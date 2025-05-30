
; flat assembler interface for Linux x64
; Copyright (c) 1999-2022, Tomasz Grysztar.
; All rights reserved.

O_ACCMODE  = 0003o
O_RDONLY   = 0000o
O_WRONLY   = 0001o
O_RDWR	   = 0002o
O_CREAT    = 0100o
O_EXCL	   = 0200o
O_NOCTTY   = 0400o
O_TRUNC    = 1000o
O_APPEND   = 2000o
O_NONBLOCK = 4000o

S_ISUID    = 4000o
S_ISGID    = 2000o
S_ISVTX    = 1000o
S_IRUSR    = 0400o
S_IWUSR    = 0200o
S_IXUSR    = 0100o
S_IRGRP    = 0040o
S_IWGRP    = 0020o
S_IXGRP    = 0010o
S_IROTH    = 0004o
S_IWOTH    = 0002o
S_IXOTH    = 0001o

init_memory:
	mov	eax,esp
	and	eax,not 0FFFh
	add	eax,1000h-10000h
	mov	[stack_limit],eax
	xor	edi,edi
	mov	eax,12
	syscall
	mov	ecx,[memory_setting]
	shl	ecx,10
	jnz	allocate_memory
	mov	ecx,1000000h
      allocate_memory:
	mov	r9d,eax
	cmp	rax,r9
	jne	high_brk
	mov	[additional_memory],eax
	lea	edi,[eax+ecx]
	mov	eax,12
	syscall
	mov	r9d,eax
	cmp	rax,r9
	jne	no_low_memory
	mov	[memory_end],eax
	sub	eax,[additional_memory]
	shr	eax,2
	add	eax,[additional_memory]
	mov	[additional_memory_end],eax
	mov	[memory_start],eax
	ret
      high_brk:
	xor	r9d,r9d
	or	r8,-1
	mov	r10d,62h		; MAP_PRIVATE + MAP_ANONYMOUS + MAP_32BIT
	mov	edx,3			; PROT_READ + PROT_WRITE
	mov	esi,ecx
	xor	edi,edi
	mov	eax,9			; sys_mmap
	syscall
	cmp	eax,-1
	je	mmap_with_hint
	mov	r9d,eax
	cmp	rax,r9
	jne	mmap_unusable
	add	r9d,esi
	jnc	mmap_ok
      mmap_unusable:
	mov	rdi,rax
	mov	eax,11			; sys_munmap
	syscall
      mmap_with_hint:
	mov	r10d,22h		; MAP_PRIVATE + MAP_ANONYMOUS
	mov	edx,3			; PROT_READ + PROT_WRITE
	mov	edi,480000h
	mov	eax,9			; sys_mmap
	syscall
	cmp	eax,-1
	je	no_low_memory
	mov	r9d,eax
	cmp	rax,r9
	jne	no_low_memory
	add	r9d,esi
	jnc	mmap_ok
      no_low_memory:
	mov	esi,lf
	call	display_string
	push	_no_low_memory
	jmp	fatal_error
      mmap_ok:
	mov	[additional_memory],eax
	lea	edi,[eax+esi]
	mov	[memory_end],edi
	shr	esi,2
	add	eax,esi
	mov	[additional_memory_end],eax
	mov	[memory_start],eax
	ret

exit_program:
	movzx	edi,al
	mov	eax,60
	syscall

get_environment_variable:
	mov	ecx,esi
	mov	rbx,[environment]
      next_variable:
	mov	rsi,[rbx]
	test	rsi,rsi
	jz	no_environment_variable
	add	rbx,8
      compare_variable_names:
	mov	edx,ecx
      compare_character:
	lodsb
	mov	ah,[edx]
	inc	edx
	cmp	al,'='
	je	end_of_variable_name
	or	ah,ah
	jz	next_variable
	sub	ah,al
	jz	compare_character
	cmp	ah,20h
	jne	next_variable
	cmp	al,41h
	jb	next_variable
	cmp	al,5Ah
	jna	compare_character
	jmp	next_variable
      no_environment_variable:
	ret
      end_of_variable_name:
	or	ah,ah
	jnz	next_variable
      copy_variable_value:
	lodsb
	cmp	edi,[memory_end]
	jae	out_of_memory
	stosb
	or	al,al
	jnz	copy_variable_value
	dec	edi
	ret

open:
	mov	r12d,esi
	mov	r13d,edi
	call	adapt_path
	mov	eax,2
	mov	edi,buffer
	mov	esi,O_RDONLY
	xor	edx,edx
	syscall
	mov	esi,r12d
	mov	edi,r13d
	test	eax,eax
	js	file_error
	mov	ebx,eax
	clc
	ret
    adapt_path:
	mov	esi,edx
	mov	edi,buffer
      copy_path:
	lods	byte [esi]
	cmp	al,'\'
	jne	path_char_ok
	mov	al,'/'
      path_char_ok:
	stos	byte [edi]
	or	al,al
	jnz	copy_path
	cmp	edi,buffer+1000h
	ja	out_of_memory
	ret
create:
	mov	r12d,esi
	mov	r13d,edi
	mov	r15d,edx
	call	adapt_path
	mov	edi,buffer
	mov	esi,O_CREAT+O_TRUNC+O_WRONLY
	mov	edx,S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH
	cmp	r15d,[output_file]
	jne	do_create
	cmp	[output_format],5
	jne	do_create
	bt	[format_flags],0
	jnc	do_create
	or	edx,S_IXUSR+S_IXGRP+S_IXOTH
      do_create:
	mov	eax,2
	syscall
	mov	esi,r12d
	mov	edi,r13d
	test	eax,eax
	js	file_error
	mov	ebx,eax
	clc
	ret
close:
	mov	r13d,edi
	mov	edi,ebx
	mov	eax,3
	syscall
	mov	edi,r13d
	ret
read:
	mov	r12d,esi
	mov	r13d,edi
	mov	eax,0
	mov	edi,ebx
	mov	esi,edx
	mov	edx,ecx
	syscall
	mov	ecx,edx
	mov	edx,esi
	mov	esi,r12d
	mov	edi,r13d
	test	eax,eax
	js	file_error
	cmp	eax,ecx
	jne	file_error
	clc
	ret
    file_error:
	stc
	ret
write:
	mov	r12d,esi
	mov	r13d,edi
	mov	eax,1
	mov	edi,ebx
	mov	esi,edx
	mov	edx,ecx
	syscall
	mov	ecx,edx
	mov	edx,esi
	mov	esi,r12d
	mov	edi,r13d
	test	eax,eax
	js	file_error
	clc
	ret
lseek:
	mov	r12d,esi
	mov	r13d,edi
	mov	edi,ebx
	mov	esi,edx
	xor	edx,edx
	mov	dl,al
	mov	eax,8
	syscall
	mov	esi,r12d
	mov	edi,r13d
	cmp	eax,-1
	je	file_error
	clc
	ret

display_string:
	mov	edi,esi
	mov	edx,esi
	or	ecx,-1
	xor	al,al
	repne	scasb
	neg	ecx
	sub	ecx,2
	mov	eax,1
	mov	edi,[con_handle]
	mov	esi,edx
	mov	edx,ecx
	syscall
	ret
display_character:
	mov	r12d,esi
	mov	r13d,edi
	mov	[character],dl
	mov	eax,1
	mov	edi,[con_handle]
	mov	esi,character
	mov	edx,1
	syscall
	mov	esi,r12d
	mov	edi,r13d
	ret
display_number:
	mov	r14d,ebx
	mov	ecx,1000000000
	xor	edx,edx
	xor	bl,bl
      display_loop:
	div	ecx
	mov	r15d,edx
	cmp	ecx,1
	je	display_digit
	or	bl,bl
	jnz	display_digit
	or	al,al
	jz	digit_ok
	not	bl
      display_digit:
	mov	dl,al
	add	dl,30h
	mov	r10d,ecx
	call	display_character
	mov	ecx,r10d
      digit_ok:
	mov	eax,ecx
	xor	edx,edx
	mov	ecx,10
	div	ecx
	mov	ecx,eax
	mov	eax,r15d
	or	ecx,ecx
	jnz	display_loop
	mov	ebx,r14d
	ret

display_user_messages:
	mov	[displayed_count],0
	call	show_display_buffer
	cmp	[displayed_count],0
	je	line_break_ok
	cmp	[last_displayed],0Ah
	je	line_break_ok
	mov	dl,0Ah
	call	display_character
      line_break_ok:
	ret
display_block:
	jecxz	block_displayed
	add	[displayed_count],ecx
	mov	al,[esi+ecx-1]
	mov	[last_displayed],al
	mov	r13d,edi
	mov	eax,1
	mov	edi,[con_handle]
	mov	edx,ecx
	syscall
	mov	edi,r13d
      block_displayed:
	ret

fatal_error:
	mov	[con_handle],2
	mov	esi,error_prefix
	call	display_string
	pop	esi
	call	display_string
	mov	esi,error_suffix
	call	display_string
	mov	al,0FFh
	jmp	exit_program
assembler_error:
	mov	[con_handle],2
	call	display_user_messages
	mov	ebx,[current_line]
	test	ebx,ebx
	jz	display_error_message
	push	dword 0
      get_error_lines:
	mov	eax,[ebx]
	cmp	byte [eax],0
	je	get_next_error_line
	push	ebx
	test	byte [ebx+7],80h
	jz	display_error_line
	mov	edx,ebx
      find_definition_origin:
	mov	edx,[edx+12]
	test	byte [edx+7],80h
	jnz	find_definition_origin
	push	edx
      get_next_error_line:
	mov	ebx,[ebx+8]
	jmp	get_error_lines
      display_error_line:
	mov	esi,[ebx]
	call	display_string
	mov	esi,line_number_start
	call	display_string
	mov	eax,[ebx+4]
	and	eax,7FFFFFFFh
	call	display_number
	mov	dl,']'
	call	display_character
	pop	esi
	cmp	ebx,esi
	je	line_number_ok
	mov	dl,20h
	call	display_character
	push	esi
	mov	esi,[esi]
	movzx	ecx,byte [esi]
	inc	esi
	call	display_block
	mov	esi,line_number_start
	call	display_string
	pop	esi
	mov	eax,[esi+4]
	and	eax,7FFFFFFFh
	call	display_number
	mov	dl,']'
	call	display_character
      line_number_ok:
	mov	esi,line_data_start
	call	display_string
	mov	esi,ebx
	mov	edx,[esi]
	call	open
	mov	al,2
	xor	edx,edx
	call	lseek
	mov	edx,[esi+8]
	sub	eax,edx
	jz	line_data_displayed
	push	eax
	xor	al,al
	call	lseek
	mov	ecx,[esp]
	mov	edx,[additional_memory]
	lea	eax,[edx+ecx]
	cmp	eax,[additional_memory_end]
	ja	out_of_memory
	call	read
	call	close
	pop	ecx
	mov	esi,[additional_memory]
      get_line_data:
	mov	al,[esi]
	cmp	al,0Ah
	je	display_line_data
	cmp	al,0Dh
	je	display_line_data
	cmp	al,1Ah
	je	display_line_data
	or	al,al
	jz	display_line_data
	inc	esi
	loop	get_line_data
      display_line_data:
	mov	ecx,esi
	mov	esi,[additional_memory]
	sub	ecx,esi
	call	display_block
      line_data_displayed:
	mov	esi,lf
	call	display_string
	pop	ebx
	or	ebx,ebx
	jnz	display_error_line
	cmp	[preprocessing_done],0
	je	display_error_message
	mov	esi,preprocessed_instruction_prefix
	call	display_string
	mov	esi,[current_line]
	add	esi,16
	mov	edi,[additional_memory]
	xor	dl,dl
      convert_instruction:
	lodsb
	cmp	al,1Ah
	je	copy_symbol
	cmp	al,22h
	je	copy_symbol
	cmp	al,3Bh
	je	instruction_converted
	stosb
	or	al,al
	jz	instruction_converted
	xor	dl,dl
	jmp	convert_instruction
      copy_symbol:
	or	dl,dl
	jz	space_ok
	mov	byte [edi],20h
	inc	edi
      space_ok:
	cmp	al,22h
	je	quoted
	lodsb
	movzx	ecx,al
	rep	movsb
	or	dl,-1
	jmp	convert_instruction
      quoted:
	mov	al,27h
	stosb
	lodsd
	mov	ecx,eax
	jecxz	quoted_copied
      copy_quoted:
	lodsb
	stosb
	cmp	al,27h
	jne	quote_ok
	stosb
      quote_ok:
	loop	copy_quoted
      quoted_copied:
	mov	al,27h
	stosb
	or	dl,-1
	jmp	convert_instruction
      instruction_converted:
	xor	al,al
	stosb
	mov	esi,[additional_memory]
	call	display_string
	mov	esi,lf
	call	display_string
      display_error_message:
	mov	esi,error_prefix
	call	display_string
	pop	esi
	call	display_string
	mov	esi,error_suffix
	call	display_string
	mov	al,2
	jmp	exit_program

make_timestamp:
	mov	r13d,edi
	mov	eax,201
	mov	edi,timestamp
	syscall
	mov	eax,dword [timestamp]
	mov	edx,dword [timestamp+4]
	mov	edi,r13d
	ret

error_prefix db 'error: ',0
error_suffix db '.'
lf db 0xA,0
line_number_start db ' [',0
line_data_start db ':',0xA,0
preprocessed_instruction_prefix db 'processed: ',0

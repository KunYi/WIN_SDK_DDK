'' FreeBASIC binding for gsl-1.16
''
'' based on the C header files:
''   block/gsl_block_ushort.h
''
''   Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
''
''   This program is free software; you can redistribute it and/or modify
''   it under the terms of the GNU General Public License as published by
''   the Free Software Foundation; either version 3 of the License, or (at
''   your option) any later version.
''
''   This program is distributed in the hope that it will be useful, but
''   WITHOUT ANY WARRANTY; without even the implied warranty of
''   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
''   General Public License for more details.
''
''   You should have received a copy of the GNU General Public License
''   along with this program; if not, write to the Free Software
''   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
''
'' translated to FreeBASIC by:
''   FreeBASIC development team

#pragma once

#include once "crt/stdlib.bi"
#include once "gsl/gsl_errno.bi"

extern "C"

#define __GSL_BLOCK_USHORT_H__

type gsl_block_ushort_struct
	size as uinteger
	data as ushort ptr
end type

type gsl_block_ushort as gsl_block_ushort_struct
declare function gsl_block_ushort_alloc(byval n as const uinteger) as gsl_block_ushort ptr
declare function gsl_block_ushort_calloc(byval n as const uinteger) as gsl_block_ushort ptr
declare sub gsl_block_ushort_free(byval b as gsl_block_ushort ptr)
declare function gsl_block_ushort_fread(byval stream as FILE ptr, byval b as gsl_block_ushort ptr) as long
declare function gsl_block_ushort_fwrite(byval stream as FILE ptr, byval b as const gsl_block_ushort ptr) as long
declare function gsl_block_ushort_fscanf(byval stream as FILE ptr, byval b as gsl_block_ushort ptr) as long
declare function gsl_block_ushort_fprintf(byval stream as FILE ptr, byval b as const gsl_block_ushort ptr, byval format as const zstring ptr) as long
declare function gsl_block_ushort_raw_fread(byval stream as FILE ptr, byval b as ushort ptr, byval n as const uinteger, byval stride as const uinteger) as long
declare function gsl_block_ushort_raw_fwrite(byval stream as FILE ptr, byval b as const ushort ptr, byval n as const uinteger, byval stride as const uinteger) as long
declare function gsl_block_ushort_raw_fscanf(byval stream as FILE ptr, byval b as ushort ptr, byval n as const uinteger, byval stride as const uinteger) as long
declare function gsl_block_ushort_raw_fprintf(byval stream as FILE ptr, byval b as const ushort ptr, byval n as const uinteger, byval stride as const uinteger, byval format as const zstring ptr) as long
declare function gsl_block_ushort_size(byval b as const gsl_block_ushort ptr) as uinteger
declare function gsl_block_ushort_data(byval b as const gsl_block_ushort ptr) as ushort ptr

end extern

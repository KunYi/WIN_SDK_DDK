Windows App
win32
Generic Windows App Built with nmake.exe
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=1,1,1,1,1,0,0,0
1=0,OT,nmake hlafile="$12" WINAPP="-w" build,
2=0,OT,nmake hlafile="$12" WINAPP="-w" buildall,
3=0,OT,nmake hlafile="$12" WINAPP="-w" syntax,
4=0,OT,nmake hlafile="$12" WINAPP="-w" compilerc,
5=0,C,nmake  hlafile="$12" WINAPP="-w" run,
6=
11=0,OT,nmake hlafile="$12" WINAPP="-w" DEBUG="-aZi -aZf" build,
12=0,OT,nmake hlafile="$12" WINAPP="-w" DEBUG="-aZi -aZf" buildall,
13=0,OT,nmake hlafile="$12" WINAPP="-w" DEBUG="-aZi -aZf" compilerc,
14=0,OT,nmake hlafile="$12" WINAPP="-w" DEBUG="-aZi -aZf" syntax,
15=0,C,nmake  hlafile="$12" WINAPP="-w" DEBUG="-aZi -aZf" run,
16=
[Resource]
[StringTable]
[VerInf]
[*ENDDEF*]
[*BEGINTXT*]
win32.hla
program GenericWin32App;
#include( "stdlib.hhf" )
#include( "w.hhf" )

?@NoDisplay := true;
?@NoStackAlign := true;


type

	// Message and dispatch table related definitions:
		  
	MsgProc_t:	procedure( hwnd:dword; wParam:dword; lParam:dword );
	
	MsgProcPtr_t:
		record
			
			MessageValue	:dword;
			MessageHndlr	:MsgProc_t;
			
		endrecord;
	



static
	hInstance			:dword;			// "Instance Handle" Windows supplies.

	wc					:w.WNDCLASSEX;	// Our "window class" data.
	msg					:w.MSG;			// Windows messages go here.
	hwnd				:dword;			// Handle to our window.
	
	
	
readonly

	ClassName	:string := "Win32Class";				// Window Class Name
	AppCaption	:string := "Generic Win32 Program";		// Caption for Window

	
	// The dispatch table:
	//
	//	This table is where you add new messages and message handlers
	//	to the program.  Each entry in the table must be a MsgProcPtr_t
	//	record containing two entries: the message value (a constant,
	//	typically one of the w.WM_***** constants found in windows.hhf)
	//	and a pointer to a "MsgProcPtr_t" procedure that will handle the
	//	message.
 
	
	Dispatch	:MsgProcPtr_t; @nostorage;

		MsgProcPtr_t	
			MsgProcPtr_t:[ w.WM_DESTROY, &QuitApplication	],
			
			// Insert new message handler records here.
			
			MsgProcPtr_t:[ 0, NULL ];	// This marks the end of the list.
			
	
			
	
	
/**************************************************************************/
/*          A P P L I C A T I O N   S P E C I F I C   C O D E	          */
/**************************************************************************/

// QuitApplication:
//
//	This procedure handles the w.WM_DESTROY message.
//	It tells the application to terminate.  This code sends
//	the appropriate message to the main program's message loop
//	that will cause the application to terminate.
	
procedure QuitApplication( hwnd: dword; wParam:dword; lParam:dword );
begin QuitApplication;

	w.PostQuitMessage( 0 );

end QuitApplication;




/**************************************************************************/
/*                   End of Application Specific Code                     */
/**************************************************************************/




// The window procedure.  
// This is actually a function that returns a return result in
// EAX.  If this function returns zero in EAX, then the event
// loop terminates program execution.

procedure WndProc( hwnd:dword; uMsg:uns32; wParam:dword; lParam:dword );
	@stdcall;

begin WndProc;

	// uMsg contains the current message Windows is passing along to
	// us.  Scan through the "Dispatch" table searching for a handler
	// for this message.  If we find one, then call the associated
	// handler procedure.  If we don't have a specific handler for this
	// message, then call the default window procedure handler function.
		
	mov( uMsg, eax );
	mov( &Dispatch, edx );
	forever
	
		mov( (type MsgProcPtr_t [edx]).MessageHndlr, ecx );
		if( ecx = 0 ) then
		
			// If an unhandled message comes along,
			// let the default window handler process the
			// message.  Whatever (non-zero) value this function
			// returns is the return result passed on to the
			// event loop.
			
			w.DefWindowProc( hwnd, uMsg, wParam, lParam );
			exit WndProc;
			
		
		elseif( eax = (type MsgProcPtr_t [edx]).MessageValue ) then
		
			// If the current message matches one of the values
			// in the message dispatch table, then call the
			// appropriate routine.  Note that the routine address
			// is still in ECX from the test above.
			
			push( hwnd );	// (type tMsgProc ecx)(hwnd, wParam, lParam)
			push( wParam );	//  This calls the associated routine after
			push( lParam );	//  pushing the necessary parameters.
			call( ecx );
			
			sub( eax, eax ); // Return value for function is zero.
			break;
		
		endif;
		add( @size( MsgProcPtr_t ), edx );
		
	endfor;
	
end WndProc;



// Here's the main program for the application.
	
begin GenericWin32App;		

	// Get this process' handle:
	
	w.GetModuleHandle( NULL );
	mov( eax, hInstance );
	

	// Set up the window class (wc) object:
	
	mov( @size( w.WNDCLASSEX ), wc.cbSize );
	mov( w.CS_HREDRAW | w.CS_VREDRAW, wc.style );
	mov( &WndProc, wc.lpfnWndProc );
	mov( NULL, wc.cbClsExtra );
	mov( NULL, wc.cbWndExtra );
	mov( w.COLOR_WINDOW+1, wc.hbrBackground );
	mov( NULL, wc.lpszMenuName );
	mov( ClassName, wc.lpszClassName );
	mov( hInstance, wc.hInstance );
	
	// Get the icons and cursor for this application:
	
	w.LoadIcon( NULL, val w.IDI_APPLICATION );
	mov( eax, wc.hIcon );
	mov( eax, wc.hIconSm );
	
	w.LoadCursor( NULL, val w.IDC_ARROW );
	mov( eax, wc.hCursor );
	
	
	// Okay, register this window with Windows so it
	// will start passing messages our way.  Once this
	// is accomplished, create the window and display it.
	
	w.RegisterClassEx( wc );

	w.CreateWindowEx
	( 
		NULL, 
		ClassName, 
		AppCaption, 
		w.WS_OVERLAPPEDWINDOW | w.WS_VSCROLL | 	w.WS_HSCROLL,
		w.CW_USEDEFAULT,
		w.CW_USEDEFAULT,
		w.CW_USEDEFAULT,
		w.CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	mov( eax, hwnd );
	
	w.ShowWindow( hwnd, w.SW_SHOWNORMAL );
	w.UpdateWindow( hwnd );
	
	// Here's the event loop that processes messages
	// sent to our window.  On return from GetMessage,
	// break if EAX contains false and then quit the
	// program.
	
	forever
	
		w.GetMessage( msg, NULL, 0, 0 );
		breakif( !eax );
		w.TranslateMessage( msg );
		w.DispatchMessage( msg );
		
	endfor;

	// The message handling inside Windows has stored
	// the program's return code in the wParam field
	// of the message.  Extract this and return it
	// as the program's return code.
	
	mov( msg.wParam, eax );
	w.ExitProcess( eax );	
				
end GenericWin32App;
[*ENDTXT*]
[*BEGINTXT*]
makefile
build: $(hlafile).exe

buildall: clean $(hlafile).exe

compilerc:
	echo No Resource Files to Process!
	
#uncomment this if you have a res file:
#
#compilerc: $(hlafile).res
#
#$(hlafile.res): $(hlafile).rc
#	rc -v $(hlafile).rc

syntax:
	hla -s $(hlafile).hla

run: $(hlafile).exe
	$(hlafile)
	pause

clean:
	delete tmp
	delete *.exe
	delete *.obj
	delete *.link
	delete *.inc
	delete *.asm
	delete *.map


# Note: you'll want to put $(hlafile).res at the end of the following
# two lines if you've got a .rc file in this project:

$(hlafile).exe: $(hlafile).hla
	hla $(DEBUG) $(WINAPP) -p:tmp $(hlafile)



[*ENDTXT*]
[*BEGINTXT*]
delete.bat
del /F /Q %1
if errorlevel 1	echo no files
[*ENDTXT*]
[*ENDPRO*]

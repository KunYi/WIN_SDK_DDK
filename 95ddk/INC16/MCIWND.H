/****************************************************************************
*                                                                           *
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY     *
* KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR     *
* PURPOSE.                                                                  *
*                                                                           *
* Copyright (C) 1993-95  Microsoft Corporation.  All Rights Reserved.       *
*                                                                           *
****************************************************************************/

// begin_vfw32
/*----------------------------------------------------------------------------*\
 *
 *  MCIWnd
 *
 *    MCIWnd window class header file.
 *
 *    the MCIWnd window class is a window class for controling MCI devices
 *    MCI devices include, wave files, midi files, AVI Video, cd audio,
 *    vcr, video disc, and others..
 *
 *    to learn more about MCI and mci command sets see the
 *    "Microsoft Multimedia Programmers's guide" in the Win31 SDK
 *
 *    the easiest use of the MCIWnd class is like so:
 *
 *          hwnd = MCIWndCreate(hwndParent, hInstance, 0, "chimes.wav");
 *          ...
 *          MCIWndPlay(hwnd);
 *          MCIWndStop(hwnd);
 *          MCIWndPause(hwnd);
 *          ....
 *          MCIWndDestroy(hwnd);
 *
 *    this will create a window with a play/pause, stop and a playbar
 *    and start the wave file playing.
 *
 *    mciwnd.h defines macros for all the most common MCI commands, but
 *    any string command can be used if needed.
 *
 *    Note: unlike the mciSendString() API, no alias or file name needs
 *    to be specifed, since the device to use is implied by the window handle.
 *
 *          MCIWndSendString(hwnd, "setaudio stream to 2");
 *
 *    (C) Copyright Microsoft Corp. 1991-1995.  All rights reserved.
 *
 * WIN32:
 *
 *    MCIWnd supports both ansi and unicode interfaces. For any message that
 *    takes or returns a text string, two versions of the message are defined,
 *    appended with A or W for Ansi or Wide Char. The message or api itself
 *    is defined to be one or other of these depending on whether you have
 *    UNICODE defined in your application.
 *    Thus for the api MCIWndCreate, there are in fact two apis,
 *    MCIWndCreateA and MCIWndCreateW. If you call MCIWndCreate, this will be
 *    re-routed to MCIWndCreateA unless UNICODE is defined when building your
 *    application. In any one application, you can mix calls to the
 *    Ansi and Unicode entrypoints.
 *
 *    If you use SendMessage instead of the macros below such as MCIWndOpen(),
 *    you will see that the messages have changed for WIN32, to support Ansi
 *    and Unicode entrypoints. In particular, MCI_OPEN has been replaced by
 *    MCWNDM_OPENA, or MCIWNDM_OPENW (MCIWNDM_OPEN is defined to be one or
 *    other of these).
 *
 *    Also, note that the WIN32 implementation of MCIWnd uses UNICODE
 *    so all apis and messages supporting ANSI strings do so by mapping them
 *    UNICODE strings and then calling the corresponding UNICODE entrypoint.
 *
 *----------------------------------------------------------------------------*/

// end_vfw32
#ifndef INC_MCIWND
#define INC_MCIWND

#if !defined(_WIN32) && !defined(LPTSTR)
    #define LPTSTR LPSTR
#endif

// begin_vfw32
#ifdef __cplusplus
// MFC Redefines SendMessage, so make sure we get the global one....
#define MCIWndSM ::SendMessage  /* SendMessage in C++*/
#else
#define MCIWndSM SendMessage    /* SendMessage in C */
#endif  /* __cplusplus */
// end_vfw32

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
// begin_vfw32
#define MCIWND_WINDOW_CLASS TEXT("MCIWndClass")
// end_vfw32
#else
#define MCIWND_WINDOW_CLASS "MCIWndClass"
#endif

#ifdef _WIN32
// begin_vfw32
HWND VFWAPIV MCIWndCreateA(HWND hwndParent, HINSTANCE hInstance,
		      DWORD dwStyle,LPCSTR szFile);
HWND VFWAPIV MCIWndCreateW(HWND hwndParent, HINSTANCE hInstance,
		      DWORD dwStyle,LPCWSTR szFile);
#ifdef UNICODE
#define MCIWndCreate    MCIWndCreateW
#else
#define MCIWndCreate    MCIWndCreateA
#endif
BOOL VFWAPIV MCIWndRegisterClass();
// end_vfw32
#else
HWND FAR _cdecl _loadds MCIWndCreate(HWND hwndParent, HINSTANCE hInstance,
                      DWORD dwStyle,LPCSTR szFile);
BOOL FAR _cdecl _loadds MCIWndRegisterClass();
#endif
// begin_vfw32

// Flags for the MCIWndOpen command
#define MCIWNDOPENF_NEW	            0x0001  // open a new file

// window styles
#define MCIWNDF_NOAUTOSIZEWINDOW    0x0001  // when movie size changes
#define MCIWNDF_NOPLAYBAR           0x0002  // no toolbar
#define MCIWNDF_NOAUTOSIZEMOVIE     0x0004  // when window size changes
#define MCIWNDF_NOMENU              0x0008  // no popup menu from RBUTTONDOWN
#define MCIWNDF_SHOWNAME            0x0010  // show name in caption
#define MCIWNDF_SHOWPOS             0x0020  // show position in caption
#define MCIWNDF_SHOWMODE            0x0040  // show mode in caption
#define MCIWNDF_SHOWALL             0x0070  // show all

#define MCIWNDF_NOTIFYMODE         0x0100  // tell parent of mode change
#define MCIWNDF_NOTIFYPOS          0x0200  // tell parent of pos change
#define MCIWNDF_NOTIFYSIZE         0x0400  // tell parent of size change
#define MCIWNDF_NOTIFYERROR        0x1000  // tell parent of an error
#define MCIWNDF_NOTIFYALL          0x1F00  // tell all

#define MCIWNDF_NOTIFYANSI	   0x0080

// end_vfw32
#ifdef _WIN32
// begin_vfw32

// The MEDIA notification includes a text string.
// To receive notifications in ANSI instead of unicode set the
// MCIWNDF_NOTIFYANSI style bit. The macro below includes this bit
// by default unless you define UNICODE in your application.

#define MCIWNDF_NOTIFYMEDIAA       0x0880  // tell parent of media change
#define MCIWNDF_NOTIFYMEDIAW       0x0800  // tell parent of media change

#ifdef UNICODE
#define MCIWNDF_NOTIFYMEDIA         MCIWNDF_NOTIFYMEDIAW
#else
#define MCIWNDF_NOTIFYMEDIA         MCIWNDF_NOTIFYMEDIAA
#endif

// end_vfw32
#else

#define MCIWNDF_NOTIFYMEDIA        0x0800  // tell parent of media change

#endif
// begin_vfw32

#define MCIWNDF_RECORD              0x2000  // Give a record button
#define MCIWNDF_NOERRORDLG          0x4000  // Show Error Dlgs for MCI cmds?
#define MCIWNDF_NOOPEN		    0x8000  // Don't allow user to open things

// can macros

#define MCIWndCanPlay(hwnd)         (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_PLAY,0,0)
#define MCIWndCanRecord(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_RECORD,0,0)
#define MCIWndCanSave(hwnd)         (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_SAVE,0,0)
#define MCIWndCanWindow(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_WINDOW,0,0)
#define MCIWndCanEject(hwnd)        (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_EJECT,0,0)
#define MCIWndCanConfig(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_CONFIG,0,0)
#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)

#define MCIWndSave(hwnd, szFile)    (LONG)MCIWndSM(hwnd, MCI_SAVE, 0, (LPARAM)(LPVOID)(szFile))
#define MCIWndSaveDialog(hwnd)      MCIWndSave(hwnd, -1)

// if you dont give a device it will use the current device....
#define MCIWndNew(hwnd, lp)         (LONG)MCIWndSM(hwnd, MCIWNDM_NEW, 0, (LPARAM)(LPVOID)(lp))

#define MCIWndRecord(hwnd)          (LONG)MCIWndSM(hwnd, MCI_RECORD, 0, 0)
// end_vfw32
#ifdef _WIN32
// begin_vfw32
#define MCIWndOpen(hwnd, sz, f)     (LONG)MCIWndSM(hwnd, MCIWNDM_OPEN, (WPARAM)(UINT)(f),(LPARAM)(LPVOID)(sz))
// end_vfw32
#else
#define MCIWndOpen(hwnd, sz, f)     (LONG)MCIWndSM(hwnd, MCI_OPEN, (WPARAM)(UINT)(f),(LPARAM)(LPVOID)(sz))
#endif
// begin_vfw32
#define MCIWndOpenDialog(hwnd)      MCIWndOpen(hwnd, -1, 0)
#define MCIWndClose(hwnd)           (LONG)MCIWndSM(hwnd, MCI_CLOSE, 0, 0)
#define MCIWndPlay(hwnd)            (LONG)MCIWndSM(hwnd, MCI_PLAY, 0, 0)
#define MCIWndStop(hwnd)            (LONG)MCIWndSM(hwnd, MCI_STOP, 0, 0)
#define MCIWndPause(hwnd)           (LONG)MCIWndSM(hwnd, MCI_PAUSE, 0, 0)
#define MCIWndResume(hwnd)          (LONG)MCIWndSM(hwnd, MCI_RESUME, 0, 0)
#define MCIWndSeek(hwnd, lPos)      (LONG)MCIWndSM(hwnd, MCI_SEEK, 0, (LPARAM)(LONG)(lPos))
#define MCIWndEject(hwnd)           (LONG)MCIWndSM(hwnd, MCIWNDM_EJECT, 0, 0)

#define MCIWndHome(hwnd)            MCIWndSeek(hwnd, MCIWND_START)
#define MCIWndEnd(hwnd)             MCIWndSeek(hwnd, MCIWND_END)

#define MCIWndGetSource(hwnd, prc)  (LONG)MCIWndSM(hwnd, MCIWNDM_GET_SOURCE, 0, (LPARAM)(LPRECT)(prc))
#define MCIWndPutSource(hwnd, prc)  (LONG)MCIWndSM(hwnd, MCIWNDM_PUT_SOURCE, 0, (LPARAM)(LPRECT)(prc))

#define MCIWndGetDest(hwnd, prc)    (LONG)MCIWndSM(hwnd, MCIWNDM_GET_DEST, 0, (LPARAM)(LPRECT)(prc))
#define MCIWndPutDest(hwnd, prc)    (LONG)MCIWndSM(hwnd, MCIWNDM_PUT_DEST, 0, (LPARAM)(LPRECT)(prc))

#define MCIWndPlayReverse(hwnd)     (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYREVERSE, 0, 0)
#define MCIWndPlayFrom(hwnd, lPos)  (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYFROM, 0, (LPARAM)(LONG)(lPos))
#define MCIWndPlayTo(hwnd, lPos)    (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYTO,   0, (LPARAM)(LONG)(lPos))
#define MCIWndPlayFromTo(hwnd, lStart, lEnd) (MCIWndSeek(hwnd, lStart), MCIWndPlayTo(hwnd, lEnd))

#define MCIWndGetDeviceID(hwnd)     (UINT)MCIWndSM(hwnd, MCIWNDM_GETDEVICEID, 0, 0)
#define MCIWndGetAlias(hwnd)        (UINT)MCIWndSM(hwnd, MCIWNDM_GETALIAS, 0, 0)
#define MCIWndGetMode(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETMODE, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))
#define MCIWndGetPosition(hwnd)     (LONG)MCIWndSM(hwnd, MCIWNDM_GETPOSITION, 0, 0)
#define MCIWndGetPositionString(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETPOSITION, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))
#define MCIWndGetStart(hwnd)        (LONG)MCIWndSM(hwnd, MCIWNDM_GETSTART, 0, 0)
#define MCIWndGetLength(hwnd)       (LONG)MCIWndSM(hwnd, MCIWNDM_GETLENGTH, 0, 0)
#define MCIWndGetEnd(hwnd)          (LONG)MCIWndSM(hwnd, MCIWNDM_GETEND, 0, 0)

#define MCIWndStep(hwnd, n)         (LONG)MCIWndSM(hwnd, MCI_STEP, 0,(LPARAM)(long)(n))

#define MCIWndDestroy(hwnd)         (VOID)MCIWndSM(hwnd, WM_CLOSE, 0, 0)
#define MCIWndSetZoom(hwnd,iZoom)   (VOID)MCIWndSM(hwnd, MCIWNDM_SETZOOM, 0, (LPARAM)(UINT)(iZoom))
#define MCIWndGetZoom(hwnd)         (UINT)MCIWndSM(hwnd, MCIWNDM_GETZOOM, 0, 0)
#define MCIWndSetVolume(hwnd,iVol)  (LONG)MCIWndSM(hwnd, MCIWNDM_SETVOLUME, 0, (LPARAM)(UINT)(iVol))
#define MCIWndGetVolume(hwnd)       (LONG)MCIWndSM(hwnd, MCIWNDM_GETVOLUME, 0, 0)
#define MCIWndSetSpeed(hwnd,iSpeed) (LONG)MCIWndSM(hwnd, MCIWNDM_SETSPEED, 0, (LPARAM)(UINT)(iSpeed))
#define MCIWndGetSpeed(hwnd)        (LONG)MCIWndSM(hwnd, MCIWNDM_GETSPEED, 0, 0)
#define MCIWndSetTimeFormat(hwnd, lp) (LONG)MCIWndSM(hwnd, MCIWNDM_SETTIMEFORMAT, 0, (LPARAM)(LPTSTR)(lp))
#define MCIWndGetTimeFormat(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETTIMEFORMAT, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))
#define MCIWndValidateMedia(hwnd)   (VOID)MCIWndSM(hwnd, MCIWNDM_VALIDATEMEDIA, 0, 0)

#define MCIWndSetRepeat(hwnd,f)     (void)MCIWndSM(hwnd, MCIWNDM_SETREPEAT, 0, (LPARAM)(BOOL)(f))
#define MCIWndGetRepeat(hwnd)       (BOOL)MCIWndSM(hwnd, MCIWNDM_GETREPEAT, 0, 0)

// end_vfw32
#ifdef _WIN32
// begin_vfw32
#define MCIWndUseFrames(hwnd)       MCIWndSetTimeFormat(hwnd, TEXT("frames"))
#define MCIWndUseTime(hwnd)         MCIWndSetTimeFormat(hwnd, TEXT("ms"))
// end_vfw32
#else
#define MCIWndUseFrames(hwnd)       MCIWndSetTimeFormat(hwnd, "frames")
#define MCIWndUseTime(hwnd)         MCIWndSetTimeFormat(hwnd, "ms")
#endif
// begin_vfw32

#define MCIWndSetActiveTimer(hwnd, active)				\
	(VOID)MCIWndSM(hwnd, MCIWNDM_SETACTIVETIMER,			\
	(WPARAM)(UINT)(active), 0L)
#define MCIWndSetInactiveTimer(hwnd, inactive)				\
	(VOID)MCIWndSM(hwnd, MCIWNDM_SETINACTIVETIMER,		\
	(WPARAM)(UINT)(inactive), 0L)
#define MCIWndSetTimers(hwnd, active, inactive)				      \
	    (VOID)MCIWndSM(hwnd, MCIWNDM_SETTIMERS,(WPARAM)(UINT)(active), \
	    (LPARAM)(UINT)(inactive))
#define MCIWndGetActiveTimer(hwnd)					\
	(UINT)MCIWndSM(hwnd, MCIWNDM_GETACTIVETIMER,	0, 0L);
#define MCIWndGetInactiveTimer(hwnd)					\
	(UINT)MCIWndSM(hwnd, MCIWNDM_GETINACTIVETIMER, 0, 0L);

#define MCIWndRealize(hwnd, fBkgnd) (LONG)MCIWndSM(hwnd, MCIWNDM_REALIZE,(WPARAM)(BOOL)(fBkgnd),0)

#define MCIWndSendString(hwnd, sz)  (LONG)MCIWndSM(hwnd, MCIWNDM_SENDSTRING, 0, (LPARAM)(LPTSTR)(sz))
#define MCIWndReturnString(hwnd, lp, len)  (LONG)MCIWndSM(hwnd, MCIWNDM_RETURNSTRING, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))
#define MCIWndGetError(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETERROR, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

//#define MCIWndActivate(hwnd, f)     (void)MCIWndSM(hwnd, WM_ACTIVATE, (WPARAM)(BOOL)(f), 0)

#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)
#define MCIWndSetPalette(hwnd, hpal) (LONG)MCIWndSM(hwnd, MCIWNDM_SETPALETTE, (WPARAM)(HPALETTE)(hpal), 0)

#define MCIWndGetFileName(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETFILENAME, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))
#define MCIWndGetDevice(hwnd, lp, len)   (LONG)MCIWndSM(hwnd, MCIWNDM_GETDEVICE, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

#define MCIWndGetStyles(hwnd) (UINT)MCIWndSM(hwnd, MCIWNDM_GETSTYLES, 0, 0L)
#define MCIWndChangeStyles(hwnd, mask, value) (LONG)MCIWndSM(hwnd, MCIWNDM_CHANGESTYLES, (WPARAM)(UINT)(mask), (LPARAM)(LONG)(value))

#define MCIWndOpenInterface(hwnd, pUnk)  (LONG)MCIWndSM(hwnd, MCIWNDM_OPENINTERFACE, 0, (LPARAM)(LPUNKNOWN)(pUnk))

#define MCIWndSetOwner(hwnd, hwndP)  (LONG)MCIWndSM(hwnd, MCIWNDM_SETOWNER, (WPARAM)(hwndP), 0)

// Messages an app will send to MCIWND

// all the text-related messages are defined out of order above (they need
// to be defined before the MCIWndOpen() macros

#define MCIWNDM_GETDEVICEID	(WM_USER + 100)
#define MCIWNDM_GETSTART	(WM_USER + 103)
#define MCIWNDM_GETLENGTH	(WM_USER + 104)
#define MCIWNDM_GETEND		(WM_USER + 105)
#define MCIWNDM_EJECT		(WM_USER + 107)
#define MCIWNDM_SETZOOM		(WM_USER + 108)
#define MCIWNDM_GETZOOM         (WM_USER + 109)
#define MCIWNDM_SETVOLUME	(WM_USER + 110)
#define MCIWNDM_GETVOLUME	(WM_USER + 111)
#define MCIWNDM_SETSPEED	(WM_USER + 112)
#define MCIWNDM_GETSPEED	(WM_USER + 113)
#define MCIWNDM_SETREPEAT	(WM_USER + 114)
#define MCIWNDM_GETREPEAT	(WM_USER + 115)
#define MCIWNDM_REALIZE         (WM_USER + 118)
#define MCIWNDM_VALIDATEMEDIA   (WM_USER + 121)
#define MCIWNDM_PLAYFROM	(WM_USER + 122)
#define MCIWNDM_PLAYTO          (WM_USER + 123)
#define MCIWNDM_GETPALETTE      (WM_USER + 126)
#define MCIWNDM_SETPALETTE      (WM_USER + 127)
#define MCIWNDM_SETTIMERS	(WM_USER + 129)
#define MCIWNDM_SETACTIVETIMER	(WM_USER + 130)
#define MCIWNDM_SETINACTIVETIMER (WM_USER + 131)
#define MCIWNDM_GETACTIVETIMER	(WM_USER + 132)
#define MCIWNDM_GETINACTIVETIMER (WM_USER + 133)
#define MCIWNDM_CHANGESTYLES	(WM_USER + 135)
#define MCIWNDM_GETSTYLES	(WM_USER + 136)
#define MCIWNDM_GETALIAS	(WM_USER + 137)
#define MCIWNDM_PLAYREVERSE	(WM_USER + 139)
#define MCIWNDM_GET_SOURCE      (WM_USER + 140)
#define MCIWNDM_PUT_SOURCE      (WM_USER + 141)
#define MCIWNDM_GET_DEST        (WM_USER + 142)
#define MCIWNDM_PUT_DEST        (WM_USER + 143)
#define MCIWNDM_CAN_PLAY        (WM_USER + 144)
#define MCIWNDM_CAN_WINDOW      (WM_USER + 145)
#define MCIWNDM_CAN_RECORD      (WM_USER + 146)
#define MCIWNDM_CAN_SAVE        (WM_USER + 147)
#define MCIWNDM_CAN_EJECT       (WM_USER + 148)
#define MCIWNDM_CAN_CONFIG      (WM_USER + 149)
#define MCIWNDM_PALETTEKICK     (WM_USER + 150)
#define MCIWNDM_OPENINTERFACE	(WM_USER + 151)
#define MCIWNDM_SETOWNER	(WM_USER + 152)

// end_vfw32
#ifdef _WIN32
// begin_vfw32

//define both A and W messages
#define MCIWNDM_SENDSTRINGA	(WM_USER + 101)
#define MCIWNDM_GETPOSITIONA	(WM_USER + 102)
#define MCIWNDM_GETMODEA	(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMATA  (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMATA  (WM_USER + 120)
#define MCIWNDM_GETFILENAMEA    (WM_USER + 124)
#define MCIWNDM_GETDEVICEA      (WM_USER + 125)
#define MCIWNDM_GETERRORA       (WM_USER + 128)
#define MCIWNDM_NEWA		(WM_USER + 134)
#define MCIWNDM_RETURNSTRINGA	(WM_USER + 138)
#define MCIWNDM_OPENA		(WM_USER + 153)

#define MCIWNDM_SENDSTRINGW	(WM_USER + 201)
#define MCIWNDM_GETPOSITIONW	(WM_USER + 202)
#define MCIWNDM_GETMODEW	(WM_USER + 206)
#define MCIWNDM_SETTIMEFORMATW  (WM_USER + 219)
#define MCIWNDM_GETTIMEFORMATW  (WM_USER + 220)
#define MCIWNDM_GETFILENAMEW    (WM_USER + 224)
#define MCIWNDM_GETDEVICEW      (WM_USER + 225)
#define MCIWNDM_GETERRORW       (WM_USER + 228)
#define MCIWNDM_NEWW		(WM_USER + 234)
#define MCIWNDM_RETURNSTRINGW	(WM_USER + 238)
#define MCIWNDM_OPENW		(WM_USER + 252)

// map defaults to A or W depending on app's UNICODE setting
#ifdef UNICODE
#define MCIWNDM_SENDSTRING      MCIWNDM_SENDSTRINGW
#define MCIWNDM_GETPOSITION     MCIWNDM_GETPOSITIONW
#define MCIWNDM_GETMODE         MCIWNDM_GETMODEW
#define MCIWNDM_SETTIMEFORMAT   MCIWNDM_SETTIMEFORMATW
#define MCIWNDM_GETTIMEFORMAT   MCIWNDM_GETTIMEFORMATW
#define MCIWNDM_GETFILENAME     MCIWNDM_GETFILENAMEW
#define MCIWNDM_GETDEVICE       MCIWNDM_GETDEVICEW
#define MCIWNDM_GETERROR        MCIWNDM_GETERRORW
#define MCIWNDM_NEW             MCIWNDM_NEWW
#define MCIWNDM_RETURNSTRING    MCIWNDM_RETURNSTRINGW
#define MCIWNDM_OPEN		MCIWNDM_OPENW
#else
#define MCIWNDM_SENDSTRING      MCIWNDM_SENDSTRINGA
#define MCIWNDM_GETPOSITION     MCIWNDM_GETPOSITIONA
#define MCIWNDM_GETMODE         MCIWNDM_GETMODEA
#define MCIWNDM_SETTIMEFORMAT   MCIWNDM_SETTIMEFORMATA
#define MCIWNDM_GETTIMEFORMAT   MCIWNDM_GETTIMEFORMATA
#define MCIWNDM_GETFILENAME     MCIWNDM_GETFILENAMEA
#define MCIWNDM_GETDEVICE       MCIWNDM_GETDEVICEA
#define MCIWNDM_GETERROR        MCIWNDM_GETERRORA
#define MCIWNDM_NEW             MCIWNDM_NEWA
#define MCIWNDM_RETURNSTRING    MCIWNDM_RETURNSTRINGA
#define MCIWNDM_OPEN		MCIWNDM_OPENA
#endif

// note that the source text for MCIWND will thus contain
// support for eg MCIWNDM_SENDSTRING (both the 16-bit entrypoint and
// in win32 mapped to MCIWNDM_SENDSTRINGW), and MCIWNDM_SENDSTRINGA (the
// win32 ansi thunk).

// end_vfw32
#else

// 16-bit Windows defines

#define MCIWNDM_SENDSTRING	(WM_USER + 101)
#define MCIWNDM_GETPOSITION	(WM_USER + 102)
#define MCIWNDM_GETMODE		(WM_USER + 106)
#define MCIWNDM_SETTIMEFORMAT   (WM_USER + 119)
#define MCIWNDM_GETTIMEFORMAT   (WM_USER + 120)
#define MCIWNDM_GETFILENAME     (WM_USER + 124)
#define MCIWNDM_GETDEVICE       (WM_USER + 125)
#define MCIWNDM_GETERROR        (WM_USER + 128)
#define MCIWNDM_NEW		(WM_USER + 134)
#define MCIWNDM_RETURNSTRING	(WM_USER + 138)

#endif
// begin_vfw32

// Messages MCIWND will send to an app
#define MCIWNDM_NOTIFYMODE      (WM_USER + 200)  // wp = hwnd, lp = mode
#define MCIWNDM_NOTIFYPOS	(WM_USER + 201)  // wp = hwnd, lp = pos
#define MCIWNDM_NOTIFYSIZE	(WM_USER + 202)  // wp = hwnd
#define MCIWNDM_NOTIFYMEDIA     (WM_USER + 203)  // wp = hwnd, lp = fn
#define MCIWNDM_NOTIFYERROR     (WM_USER + 205)  // wp = hwnd, lp = error

// special seek values for START and END
#define MCIWND_START                -1
#define MCIWND_END                  -2

#ifndef MCI_PLAY
    /* MCI command message identifiers */
#ifndef _WIN32
    // win32 apps send MCIWNDM_OPEN
    #define MCI_OPEN                        0x0803
#endif
    #define MCI_CLOSE                       0x0804
    #define MCI_PLAY                        0x0806
    #define MCI_SEEK                        0x0807
    #define MCI_STOP                        0x0808
    #define MCI_PAUSE                       0x0809
    #define MCI_STEP                        0x080E
    #define MCI_RECORD                      0x080F
    #define MCI_SAVE                        0x0813
    #define MCI_CUT                         0x0851
    #define MCI_COPY                        0x0852
    #define MCI_PASTE                       0x0853
    #define MCI_RESUME                      0x0855
    #define MCI_DELETE                      0x0856
#endif

#ifndef MCI_MODE_NOT_READY
    /* return values for 'status mode' command */
    #define MCI_MODE_NOT_READY      (524)
    #define MCI_MODE_STOP           (525)
    #define MCI_MODE_PLAY           (526)
    #define MCI_MODE_RECORD         (527)
    #define MCI_MODE_SEEK           (528)
    #define MCI_MODE_PAUSE          (529)
    #define MCI_MODE_OPEN           (530)
#endif

// end_vfw32
#ifdef __cplusplus
}
#endif

#endif

//
// err.h: Declares data, defines and struct types for error handling
//          module.
//
//

#ifndef __ERR_H__
#define __ERR_H__

// Requires comm.h to be included prior to this
//

/////////////////////////////////////////////////////  INCLUDES
/////////////////////////////////////////////////////  DEFINES

// Messagebox type flags, used by MsgBox_* macros
//
#define MSG_ERROR       1
#define MSG_INFO        2
#define MSG_QUESTION    3


#ifdef DEBUG

// Dump flags used in g_uDumpFlags
//
#define DF_DCB              0x0001
#define DF_MODEMSETTINGS    0x0002
#define DF_DEVCAPS          0x0004

// Break flags used in g_uBreakFlags
//
#define BF_ONOPEN       0x0001
#define BF_ONCLOSE      0x0002
#define BF_ONRUNONCE    0x0004
#define BF_ONVALIDATE   0x0010
#define BF_ONTHREADATT  0x0100
#define BF_ONTHREADDET  0x0200
#define BF_ONPROCESSATT 0x0400
#define BF_ONPROCESSDET 0x0800

#endif

// Trace flags used in g_uTraceFlags (defined in retail on purpose)
//
#define TF_ALWAYS       0x0000
#define TF_WARNING      0x0001
#define TF_ERROR        0x0002
#define TF_GENERAL      0x0004      // Standard trace messages
#define TF_FUNC         0x0008      // Function trace messages

/////////////////////////////////////////////////////  MACROS

// Message box macros
//

//      int MsgBox_Err(HWND hwndParent, UINT ids, UINT idsCaption);
//          Invoke error message (with ! icon)
//
#define MsgBox_Err(hwnd, ids, idsCap)       MsgBoxIds(hwnd, ids, idsCap, MSG_ERROR)

//      int MsgBox_Info(HWND hwndParent, UINT ids, UINT idsCaption);
//          Invoke info message (with i icon)
//
#define MsgBox_Info(hwnd, ids, idsCap)      MsgBoxIds(hwnd, ids, idsCap, MSG_INFO)

//      int MsgBox_Question(HWND hwndParent, UINT ids, UINT idsCaption);
//          Invoke question message (with ? icon and Yes/No buttons)
//
#define MsgBox_Question(hwnd, ids, idsCap)  MsgBoxIds(hwnd, ids, idsCap, MSG_QUESTION)

//      int MsgBox_ErrSz(HWND hwndParent, LPCSTR psz, UINT idsCaption);
//          Invoke error message (with ! icon)
//
#define MsgBox_ErrSz(hwnd, lpsz, idsCap)        MsgBoxSz(hwnd, lpsz, idsCap, MSG_ERROR, NULL)

//      int MsgBox_InfoSz(HWND hwndParent, LPCSTR psz, UINT idsCaption);
//          Invoke info message (with i icon)
//
#define MsgBox_InfoSz(hwnd, lpsz, idsCap)       MsgBoxSz(hwnd, lpsz, idsCap, MSG_INFO, NULL)

//      int MsgBox_QuestionSz(HWND hwndParent, LPCSTR psz, UINT idsCaption);
//          Invoke question message (with ? icon and Yes/No buttons)
//
#define MsgBox_QuestionSz(hwnd, lpsz, idsCap)   MsgBoxSz(hwnd, lpsz, idsCap, MSG_QUESTION, NULL)


// Debugging macros
//

#ifdef DEBUG

#define ASSERTSEG

// Use this macro to declare message text that will be placed
// in the CODE segment (useful if DS is getting full)
//
// Ex: DEBUGTEXT(szMsg, "Invalid whatever: %d");
//
#define DEBUGTEXT(sz, msg)	/* ;Internal */ \
    static const char ASSERTSEG sz[] = msg;

void PUBLIC MdmAssertFailed(LPCSTR szFile, int line);
void CPUBLIC MdmAssertMsg(BOOL f, LPCSTR pszMsg, ...);
void CPUBLIC MdmDebugMsg(UINT mask, LPCSTR pszMsg, ...);

// ASSERT(f)  -- Generate "assertion failed in line x of file.c"
//               message if f is NOT true.
//
#define ASSERT(f)                                                       \
    {                                                                   \
        DEBUGTEXT(szFile, __FILE__);                                    \
        if (!(f))                                                       \
            MdmAssertFailed(szFile, __LINE__);                          \
    }
#define ASSERT_E(f)  ASSERT(f)

// ASSERT_MSG(f, msg, args...)  -- Generate wsprintf-formatted msg w/params
//                          if f is NOT true.
//
#define ASSERT_MSG   MdmAssertMsg

// DEBUG_MSG(mask, msg, args...) - Generate wsprintf-formatted msg using
//                          specified debug mask.  System debug mask
//                          governs whether message is output.
//
#define DEBUG_MSG    MdmDebugMsg
#define TRACE_MSG    DEBUG_MSG

// VERIFYSZ(f, msg, arg)  -- Generate wsprintf-formatted msg w/ 1 param
//                          if f is NOT true 
//
#define VERIFYSZ(f, szFmt, x)   ASSERT_MSG(f, szFmt, x)

// DBG_ENTER(szFn)  -- Generates a function entry debug spew for
//                          a function 
//
#define DBG_ENTER(szFn)                  \
    TRACE_MSG(TF_FUNC, szFn "() enter")


// DBG_ENTER_SZ(szFn, sz)  -- Generates a function entry debug spew for
//                          a function that accepts a string as one of its
//                          parameters.
//
#define DBG_ENTER_SZ(szFn, sz)                  \
    TRACE_MSG(TF_FUNC, szFn "(..., %s,...) enter", Dbg_SafeStr(sz))


// DBG_ENTER_RIID(szFn, riid)  -- Generates a function entry debug spew for
//                          a function that accepts an riid as one of its
//                          parameters.
//
#define DBG_ENTER_RIID(szFn, riid)                  \
    TRACE_MSG(TF_FUNC, szFn "(..., %s,...) enter", Dbg_GetRiidName(riid))


// DBG_EXIT(szFn)  -- Generates a function exit debug spew 
//
#define DBG_EXIT(szFn)                              \
        TRACE_MSG(TF_FUNC, szFn " exit\r\n")

// DBG_EXIT_BOOL(szFn, b)  -- Generates a function exit debug spew for
//                          functions that return a BOOL.
//
#define DBG_EXIT_BOOL(szFn, b)                      \
        TRACE_MSG(TF_FUNC, szFn " exit (%s)\r\n", (b) ? (LPCSTR)"TRUE" : (LPCSTR)"FALSE")

// DBG_EXIT_US(szFn, us)  -- Generates a function exit debug spew for
//                          functions that return a USHORT.
//
#define DBG_EXIT_US(szFn, us)                       \
        TRACE_MSG(TF_FUNC, szFn " exit (%#x)\r\n", (USHORT)us)

// DBG_EXIT_UL(szFn, ul)  -- Generates a function exit debug spew for
//                          functions that return a ULONG.
//
#define DBG_EXIT_UL(szFn, ul)                   \
        TRACE_MSG(TF_FUNC, szFn " exit (%#lx)\r\n", (ULONG)ul)

// DBG_EXIT_DWORD(szFn, dw)  -- Generates a function exit debug spew for
//                          functions that return a DWORD.
//
#define DBG_EXIT_DWORD(szFn, dw)                   \
        TRACE_MSG(TF_FUNC, szFn " exit (%#lx)\r\n", (DWORD)dw)

// DBG_EXIT_PTR(szFn, pv)  -- Generates a function exit debug spew for
//                          functions that return a pointer.
//
#define DBG_EXIT_PTR(szFn, pv)                   \
        TRACE_MSG(TF_FUNC, szFn " exit (%#lx)\r\n", (LPVOID)pv)

// DBG_EXIT_RET(szFn, ret)  -- Generates a function exit debug spew for
//                          functions that return a RETERR.
//
#define DBG_EXIT_RET(szFn, ret)                   \
        TRACE_MSG(TF_FUNC, szFn " exit (%s)\r\n", Dbg_GetReterr(ret))

#else

#define ASSERT(f)
#define ASSERT_E(f)      (f)
#define ASSERT_MSG   1 ? (void)0 : (void)
#define DEBUG_MSG    1 ? (void)0 : (void)
#define TRACE_MSG    1 ? (void)0 : (void)

#define VERIFYSZ(f, szFmt, x)     (f)

#define DBG_ENTER(szFn)
#define DBG_ENTER_SZ(szFn, sz)
#define DBG_ENTER_RIID(szFn, riid)   

#define DBG_EXIT(szFn)                            
#define DBG_EXIT_BOOL(szFn, b)
#define DBG_EXIT_US(szFn, us)
#define DBG_EXIT_UL(szFn, ul)
#define DBG_EXIT_DWORD(szFn, dw)
#define DBG_EXIT_PTR(szFn, ptr)                            
#define DBG_EXIT_RET(szFn, ret)   

#endif

/////////////////////////////////////////////////////  TYPEDEFS

/////////////////////////////////////////////////////  EXPORTED DATA

/////////////////////////////////////////////////////  PUBLIC PROTOTYPES

#ifdef DEBUG

void   PUBLIC DEBUG_BREAK(UINT flag);
LPCSTR PUBLIC Dbg_GetReterr(RETERR ret);
LPCSTR PUBLIC Dbg_SafeStr(LPCSTR psz);

#endif

int PUBLIC MsgBoxIds (HWND hwndParent, UINT ids, UINT idsCaption, UINT nBoxType);
int PUBLIC MsgBoxSz (HWND hwndParent, LPCSTR lpsz, UINT idsCaption, UINT nBoxType, HANDLE hinst);

#endif // __ERR_H__


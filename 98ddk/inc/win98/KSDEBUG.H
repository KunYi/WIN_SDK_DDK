
#if !defined(_KSDEBUG_)
#define _KSDEBUG_

#if !defined(REMIND)

#define QUOTE(x) #x
#define QQUOTE(y) QUOTE(y)
#define REMIND(str) __FILE__ "(" QQUOTE(__LINE__) ") : " str

#endif // !defined(REMIND)

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

#if defined(_NTDDK_)

#define DEBUGLVL_BLAB    3
#define DEBUGLVL_VERBOSE 2
#define DEBUGLVL_TERSE   1
#define DEBUGLVL_ERROR   0

#if (DBG)
   #if !defined( DEBUG_LEVEL )
        #if defined( DEBUG_VARIABLE )
            #if defined( KSDEBUG_INIT )
                ULONG DEBUG_VARIABLE = DEBUGLVL_TERSE;
            #else
                extern ULONG DEBUG_VARIABLE;
            #endif
        #else
            #define DEBUG_VARIABLE DEBUGLVL_TERSE
        #endif
   #else 
        #if defined( DEBUG_VARIABLE )
            #if defined( KSDEBUG_INIT )
                ULONG DEBUG_VARIABLE = DEBUG_LEVEL;
            #else
                extern ULONG DEBUG_VARIABLE;
            #endif
        #else
            #define DEBUG_VARIABLE DEBUG_LEVEL
        #endif
   #endif

   #define _DbgPrintF(lvl, strings) \
{ \
    if ((lvl) <= DEBUG_VARIABLE) {\
        DbgPrint(STR_MODULENAME);\
        DbgPrint##strings;\
        DbgPrint("\n");\
        if ((lvl) == DEBUGLVL_ERROR) {\
            DbgBreakPoint();\
        } \
    } \
}
#else // !DBG
   #define _DbgPrintF(lvl, strings)
#endif // !DBG

#endif // !defined(_NTDDK_)

//
// macros
//

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

//
// constants
//

#if (DBG)

#if defined(IRPMJFUNCDESC)
static const PCHAR IrpMjFuncDesc[] =
{
   "IRP_MJ_CREATE",
   "IRP_MJ_CREATE_NAMED_PIPE",
   "IRP_MJ_CLOSE",
   "IRP_MJ_READ",
   "IRP_MJ_WRITE",
   "IRP_MJ_QUERY_INFORMATION",
   "IRP_MJ_SET_INFORMATION",
   "IRP_MJ_QUERY_EA",
   "IRP_MJ_SET_EA",
   "IRP_MJ_FLUSH_BUFFERS",
   "IRP_MJ_QUERY_VOLUME_INFORMATION",
   "IRP_MJ_SET_VOLUME_INFORMATION",
   "IRP_MJ_DIRECTORY_CONTROL",
   "IRP_MJ_FILE_SYSTEM_CONTROL",
   "IRP_MJ_DEVICE_CONTROL",
   "IRP_MJ_INTERNAL_DEVICE_CONTROL",
   "IRP_MJ_SHUTDOWN",
   "IRP_MJ_LOCK_CONTROL",
   "IRP_MJ_CLEANUP",
   "IRP_MJ_CREATE_MAILSLOT",
   "IRP_MJ_QUERY_SECURITY",
   "IRP_MJ_SET_SECURITY",
   "IRP_MJ_SET_POWER",
   "IRP_MJ_QUERY_POWER"
};
#endif // defined(IRPMJFUNCDESC)

#endif // DBG

#endif // !_KSDEBUG_

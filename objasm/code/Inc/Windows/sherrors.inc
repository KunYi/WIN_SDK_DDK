;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\sherrors.h', last modified: 19/04/2018 10:46
;Creation parameters: 

ifndef _SHERROR_
  _SHERROR_ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020) and  not Defined(__midl)
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include winerror.inc
    COPYENGINE_S_YES equ _HRESULT_TYPEDEF_(00270001h)
    COPYENGINE_S_NOT_HANDLED equ _HRESULT_TYPEDEF_(00270003h)
    COPYENGINE_S_USER_RETRY equ _HRESULT_TYPEDEF_(00270004h)
    COPYENGINE_S_USER_IGNORED equ _HRESULT_TYPEDEF_(00270005h)
    COPYENGINE_S_MERGE equ _HRESULT_TYPEDEF_(00270006h)
    COPYENGINE_S_DONT_PROCESS_CHILDREN equ _HRESULT_TYPEDEF_(00270008h)
    COPYENGINE_S_ALREADY_DONE equ _HRESULT_TYPEDEF_(0027000Ah)
    COPYENGINE_S_PENDING equ _HRESULT_TYPEDEF_(0027000Bh)
    COPYENGINE_S_KEEP_BOTH equ _HRESULT_TYPEDEF_(0027000Ch)
    COPYENGINE_S_CLOSE_PROGRAM equ _HRESULT_TYPEDEF_(0027000Dh)
    COPYENGINE_S_COLLISIONRESOLVED equ _HRESULT_TYPEDEF_(0027000Eh)
    COPYENGINE_S_PROGRESS_PAUSE equ _HRESULT_TYPEDEF_(0027000Fh)
    COPYENGINE_E_USER_CANCELLED equ _HRESULT_TYPEDEF_(80270000h)
    COPYENGINE_E_CANCELLED equ _HRESULT_TYPEDEF_(80270001h)
    COPYENGINE_E_REQUIRES_ELEVATION equ _HRESULT_TYPEDEF_(80270002h)
    COPYENGINE_E_SAME_FILE equ _HRESULT_TYPEDEF_(80270003h)
    COPYENGINE_E_DIFF_DIR equ _HRESULT_TYPEDEF_(80270004h)
    COPYENGINE_E_MANY_SRC_1_DEST equ _HRESULT_TYPEDEF_(80270005h)
    COPYENGINE_E_DEST_SUBTREE equ _HRESULT_TYPEDEF_(80270009h)
    COPYENGINE_E_DEST_SAME_TREE equ _HRESULT_TYPEDEF_(8027000Ah)
    COPYENGINE_E_FLD_IS_FILE_DEST equ _HRESULT_TYPEDEF_(8027000Bh)
    COPYENGINE_E_FILE_IS_FLD_DEST equ _HRESULT_TYPEDEF_(8027000Ch)
    COPYENGINE_E_FILE_TOO_LARGE equ _HRESULT_TYPEDEF_(8027000Dh)
    COPYENGINE_E_REMOVABLE_FULL equ _HRESULT_TYPEDEF_(8027000Eh)
    COPYENGINE_E_DEST_IS_RO_CD equ _HRESULT_TYPEDEF_(8027000Fh)
    COPYENGINE_E_DEST_IS_RW_CD equ _HRESULT_TYPEDEF_(80270010h)
    COPYENGINE_E_DEST_IS_R_CD equ _HRESULT_TYPEDEF_(80270011h)
    COPYENGINE_E_DEST_IS_RO_DVD equ _HRESULT_TYPEDEF_(80270012h)
    COPYENGINE_E_DEST_IS_RW_DVD equ _HRESULT_TYPEDEF_(80270013h)
    COPYENGINE_E_DEST_IS_R_DVD equ _HRESULT_TYPEDEF_(80270014h)
    COPYENGINE_E_SRC_IS_RO_CD equ _HRESULT_TYPEDEF_(80270015h)
    COPYENGINE_E_SRC_IS_RW_CD equ _HRESULT_TYPEDEF_(80270016h)
    COPYENGINE_E_SRC_IS_R_CD equ _HRESULT_TYPEDEF_(80270017h)
    COPYENGINE_E_SRC_IS_RO_DVD equ _HRESULT_TYPEDEF_(80270018h)
    COPYENGINE_E_SRC_IS_RW_DVD equ _HRESULT_TYPEDEF_(80270019h)
    COPYENGINE_E_SRC_IS_R_DVD equ _HRESULT_TYPEDEF_(8027001Ah)
    COPYENGINE_E_INVALID_FILES_SRC equ _HRESULT_TYPEDEF_(8027001Bh)
    COPYENGINE_E_INVALID_FILES_DEST equ _HRESULT_TYPEDEF_(8027001Ch)
    COPYENGINE_E_PATH_TOO_DEEP_SRC equ _HRESULT_TYPEDEF_(8027001Dh)
    COPYENGINE_E_PATH_TOO_DEEP_DEST equ _HRESULT_TYPEDEF_(8027001Eh)
    COPYENGINE_E_ROOT_DIR_SRC equ _HRESULT_TYPEDEF_(8027001Fh)
    COPYENGINE_E_ROOT_DIR_DEST equ _HRESULT_TYPEDEF_(80270020h)
    COPYENGINE_E_ACCESS_DENIED_SRC equ _HRESULT_TYPEDEF_(80270021h)
    COPYENGINE_E_ACCESS_DENIED_DEST equ _HRESULT_TYPEDEF_(80270022h)
    COPYENGINE_E_PATH_NOT_FOUND_SRC equ _HRESULT_TYPEDEF_(80270023h)
    COPYENGINE_E_PATH_NOT_FOUND_DEST equ _HRESULT_TYPEDEF_(80270024h)
    COPYENGINE_E_NET_DISCONNECT_SRC equ _HRESULT_TYPEDEF_(80270025h)
    COPYENGINE_E_NET_DISCONNECT_DEST equ _HRESULT_TYPEDEF_(80270026h)
    COPYENGINE_E_SHARING_VIOLATION_SRC equ _HRESULT_TYPEDEF_(80270027h)
    COPYENGINE_E_SHARING_VIOLATION_DEST equ _HRESULT_TYPEDEF_(80270028h)
    COPYENGINE_E_ALREADY_EXISTS_NORMAL equ _HRESULT_TYPEDEF_(80270029h)
    COPYENGINE_E_ALREADY_EXISTS_READONLY equ _HRESULT_TYPEDEF_(8027002Ah)
    COPYENGINE_E_ALREADY_EXISTS_SYSTEM equ _HRESULT_TYPEDEF_(8027002Bh)
    COPYENGINE_E_ALREADY_EXISTS_FOLDER equ _HRESULT_TYPEDEF_(8027002Ch)
    COPYENGINE_E_STREAM_LOSS equ _HRESULT_TYPEDEF_(8027002Dh)
    COPYENGINE_E_EA_LOSS equ _HRESULT_TYPEDEF_(8027002Eh)
    COPYENGINE_E_PROPERTY_LOSS equ _HRESULT_TYPEDEF_(8027002Fh)
    COPYENGINE_E_PROPERTIES_LOSS equ _HRESULT_TYPEDEF_(80270030h)
    COPYENGINE_E_ENCRYPTION_LOSS equ _HRESULT_TYPEDEF_(80270031h)
    COPYENGINE_E_DISK_FULL equ _HRESULT_TYPEDEF_(80270032h)
    COPYENGINE_E_DISK_FULL_CLEAN equ _HRESULT_TYPEDEF_(80270033h)
    COPYENGINE_E_EA_NOT_SUPPORTED equ _HRESULT_TYPEDEF_(80270034h)
    COPYENGINE_E_CANT_REACH_SOURCE equ _HRESULT_TYPEDEF_(80270035h)
    COPYENGINE_E_RECYCLE_UNKNOWN_ERROR equ _HRESULT_TYPEDEF_(80270035h)
    COPYENGINE_E_RECYCLE_FORCE_NUKE equ _HRESULT_TYPEDEF_(80270036h)
    COPYENGINE_E_RECYCLE_SIZE_TOO_BIG equ _HRESULT_TYPEDEF_(80270037h)
    COPYENGINE_E_RECYCLE_PATH_TOO_LONG equ _HRESULT_TYPEDEF_(80270038h)
    COPYENGINE_E_RECYCLE_BIN_NOT_FOUND equ _HRESULT_TYPEDEF_(8027003Ah)
    COPYENGINE_E_NEWFILE_NAME_TOO_LONG equ _HRESULT_TYPEDEF_(8027003Bh)
    COPYENGINE_E_NEWFOLDER_NAME_TOO_LONG equ _HRESULT_TYPEDEF_(8027003Ch)
    COPYENGINE_E_DIR_NOT_EMPTY equ _HRESULT_TYPEDEF_(8027003Dh)
    COPYENGINE_E_FAT_MAX_IN_ROOT equ _HRESULT_TYPEDEF_(8027003Eh)
    COPYENGINE_E_ACCESSDENIED_READONLY equ _HRESULT_TYPEDEF_(8027003Fh)
    COPYENGINE_E_REDIRECTED_TO_WEBPAGE equ _HRESULT_TYPEDEF_(80270040h)
    COPYENGINE_E_SERVER_BAD_FILE_TYPE equ _HRESULT_TYPEDEF_(80270041h)
    COPYENGINE_E_INTERNET_ITEM_UNAVAILABLE equ _HRESULT_TYPEDEF_(80270042h)
    COPYENGINE_E_CANNOT_MOVE_FROM_RECYCLE_BIN equ _HRESULT_TYPEDEF_(80270043h)
    COPYENGINE_E_CANNOT_MOVE_SHARED_FOLDER equ _HRESULT_TYPEDEF_(80270044h)
    COPYENGINE_E_INTERNET_ITEM_STORAGE_PROVIDER_ERROR equ _HRESULT_TYPEDEF_(80270045h)
    COPYENGINE_E_INTERNET_ITEM_STORAGE_PROVIDER_PAUSED equ _HRESULT_TYPEDEF_(80270046h)
    COPYENGINE_E_REQUIRES_EDP_CONSENT equ _HRESULT_TYPEDEF_(80270047h)
    COPYENGINE_E_BLOCKED_BY_EDP_POLICY equ _HRESULT_TYPEDEF_(80270048h)
    COPYENGINE_E_REQUIRES_EDP_CONSENT_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(80270049h)
    COPYENGINE_E_BLOCKED_BY_EDP_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Ah)
    COPYENGINE_E_RMS_REQUIRES_EDP_CONSENT_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Bh)
    COPYENGINE_E_RMS_BLOCKED_BY_EDP_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Ch)
    NETCACHE_E_NEGATIVE_CACHE equ _HRESULT_TYPEDEF_(80270100h)
    EXECUTE_E_LAUNCH_APPLICATION equ _HRESULT_TYPEDEF_(80270101h)
    SHELL_E_WRONG_BITDEPTH equ _HRESULT_TYPEDEF_(80270102h)
    LINK_E_DELETE equ _HRESULT_TYPEDEF_(80270103h)
    STORE_E_NEWER_VERSION_AVAILABLE equ _HRESULT_TYPEDEF_(80270104h)
    E_FILE_PLACEHOLDER_NOT_INITIALIZED equ _HRESULT_TYPEDEF_(80270110h)
    E_FILE_PLACEHOLDER_VERSION_MISMATCH equ _HRESULT_TYPEDEF_(80270111h)
    E_FILE_PLACEHOLDER_SERVER_TIMED_OUT equ _HRESULT_TYPEDEF_(80270112h)
    E_FILE_PLACEHOLDER_STORAGEPROVIDER_NOT_FOUND equ _HRESULT_TYPEDEF_(80270113h)
    CAMERAROLL_E_NO_DOWNSAMPLING_REQUIRED equ _HRESULT_TYPEDEF_(80270120h)
    E_ACTIVATIONDENIED_USERCLOSE equ _HRESULT_TYPEDEF_(80270130h)
    E_ACTIVATIONDENIED_SHELLERROR equ _HRESULT_TYPEDEF_(80270131h)
    E_ACTIVATIONDENIED_SHELLRESTART equ _HRESULT_TYPEDEF_(80270132h)
    E_ACTIVATIONDENIED_UNEXPECTED equ _HRESULT_TYPEDEF_(80270133h)
    LIBRARY_E_NO_SAVE_LOCATION equ _HRESULT_TYPEDEF_(80270200h)
    LIBRARY_E_NO_ACCESSIBLE_LOCATION equ _HRESULT_TYPEDEF_(80270201h)
    E_USERTILE_UNSUPPORTEDFILETYPE equ _HRESULT_TYPEDEF_(80270210h)
    E_USERTILE_CHANGEDISABLED equ _HRESULT_TYPEDEF_(80270211h)
    E_USERTILE_LARGEORDYNAMIC equ _HRESULT_TYPEDEF_(80270212h)
    E_USERTILE_VIDEOFRAMESIZE equ _HRESULT_TYPEDEF_(80270213h)
    E_USERTILE_FILESIZE equ _HRESULT_TYPEDEF_(80270214h)
    IMM_ACC_DOCKING_E_INSUFFICIENTHEIGHT equ _HRESULT_TYPEDEF_(80270230h)
    IMM_ACC_DOCKING_E_DOCKOCCUPIED equ _HRESULT_TYPEDEF_(80270231h)
    IMSC_E_SHELL_COMPONENT_STARTUP_FAILURE equ _HRESULT_TYPEDEF_(80270233h)
    SHC_E_SHELL_COMPONENT_STARTUP_FAILURE equ _HRESULT_TYPEDEF_(80270234h)
    E_TILE_NOTIFICATIONS_PLATFORM_FAILURE equ _HRESULT_TYPEDEF_(80270249h)
    E_SHELL_EXTENSION_BLOCKED equ _HRESULT_TYPEDEF_(80270301h)
    E_IMAGEFEED_CHANGEDISABLED equ _HRESULT_TYPEDEF_(80270310h)
  endif
endif


/*++ BUILD Version: 0000    // Increment this if a change has global effects

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    ndiswan.h

Abstract:

    Main header file for the TAPI wrapper


Revision History:

--*/

#ifndef _NDIS_TAPI_
#define _NDIS_TAPI_

#pragma once

//
//
//
//
// Begin definitions for TAPI
//
//
//
//

#ifndef NDIS_TAPI_CURRENT_VERSION
#define NDIS_TAPI_CURRENT_VERSION 0x00010003
#endif
//
// Symbolic constants
//


#define NDIS_STATUS_TAPI_ADDRESSBLOCKED           ((NDIS_STATUS)0xC0012000L)
#define NDIS_STATUS_TAPI_BEARERMODEUNAVAIL        ((NDIS_STATUS)0xC0012001L)
#define NDIS_STATUS_TAPI_CALLUNAVAIL              ((NDIS_STATUS)0xC0012002L)
#define NDIS_STATUS_TAPI_DIALBILLING              ((NDIS_STATUS)0xC0012003L)
#define NDIS_STATUS_TAPI_DIALDIALTONE             ((NDIS_STATUS)0xC0012004L)
#define NDIS_STATUS_TAPI_DIALPROMPT               ((NDIS_STATUS)0xC0012005L)
#define NDIS_STATUS_TAPI_DIALQUIET                ((NDIS_STATUS)0xC0012006L)
#define NDIS_STATUS_TAPI_INCOMPATIBLEEXTVERSION   ((NDIS_STATUS)0xC0012007L)
#define NDIS_STATUS_TAPI_INUSE                    ((NDIS_STATUS)0xC0012008L)
#define NDIS_STATUS_TAPI_INVALADDRESS             ((NDIS_STATUS)0xC0012009L)
#define NDIS_STATUS_TAPI_INVALADDRESSID           ((NDIS_STATUS)0xC001200AL)
#define NDIS_STATUS_TAPI_INVALADDRESSMODE         ((NDIS_STATUS)0xC001200BL)
#define NDIS_STATUS_TAPI_INVALBEARERMODE          ((NDIS_STATUS)0xC001200CL)
#define NDIS_STATUS_TAPI_INVALCALLHANDLE          ((NDIS_STATUS)0xC001200DL)
#define NDIS_STATUS_TAPI_INVALCALLPARAMS          ((NDIS_STATUS)0xC001200EL)
#define NDIS_STATUS_TAPI_INVALCALLSTATE           ((NDIS_STATUS)0xC001200FL)
#define NDIS_STATUS_TAPI_INVALDEVICECLASS         ((NDIS_STATUS)0xC0012010L)
#define NDIS_STATUS_TAPI_INVALLINEHANDLE          ((NDIS_STATUS)0xC0012011L)
#define NDIS_STATUS_TAPI_INVALLINESTATE           ((NDIS_STATUS)0xC0012012L)
#define NDIS_STATUS_TAPI_INVALMEDIAMODE           ((NDIS_STATUS)0xC0012013L)
#define NDIS_STATUS_TAPI_INVALRATE                ((NDIS_STATUS)0xC0012014L)
#define NDIS_STATUS_TAPI_NODRIVER                 ((NDIS_STATUS)0xC0012015L)
#define NDIS_STATUS_TAPI_OPERATIONUNAVAIL         ((NDIS_STATUS)0xC0012016L)
#define NDIS_STATUS_TAPI_RATEUNAVAIL              ((NDIS_STATUS)0xC0012017L)
#define NDIS_STATUS_TAPI_RESOURCEUNAVAIL          ((NDIS_STATUS)0xC0012018L)
#define NDIS_STATUS_TAPI_STRUCTURETOOSMALL        ((NDIS_STATUS)0xC0012019L)
#define NDIS_STATUS_TAPI_USERUSERINFOTOOBIG       ((NDIS_STATUS)0xC001201AL)
#define NDIS_STATUS_TAPI_ALLOCATED                ((NDIS_STATUS)0xC001201BL)
#define NDIS_STATUS_TAPI_INVALADDRESSSTATE        ((NDIS_STATUS)0xC001201CL)
#define NDIS_STATUS_TAPI_INVALPARAM               ((NDIS_STATUS)0xC001201DL)
#define NDIS_STATUS_TAPI_NODEVICE                 ((NDIS_STATUS)0xC001201EL)

//
//  The following DISCONNECTMODE status codes are used by CO_ADDRESS_FAMILY_TAPI
//  NDIS Call Managers as the NDIS status passed to:
//
//  - Ndis[M]CmMakeCallComplete
//  - Ndis[M]CmDispatchIncomingCloseCall
//
#define NDIS_STATUS_TAPI_DISCONNECTMODE_NORMAL    ((NDIS_STATUS)0xC0012020L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_UNKNOWN   ((NDIS_STATUS)0xC0012021L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_REJECT    ((NDIS_STATUS)0xC0012022L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_PICKUP    ((NDIS_STATUS)0xC0012023L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_FORWARDED ((NDIS_STATUS)0xC0012024L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_BUSY      ((NDIS_STATUS)0xC0012025L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_NOANSWER  ((NDIS_STATUS)0xC0012026L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_BADADDRESS   ((NDIS_STATUS)0xC0012027L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_UNREACHABLE  ((NDIS_STATUS)0xC0012028L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_CONGESTION   ((NDIS_STATUS)0xC0012029L)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_INCOMPATIBLE ((NDIS_STATUS)0xC001202AL)
#define NDIS_STATUS_TAPI_DISCONNECTMODE_UNAVAIL    ((NDIS_STATUS)0xC001202BL)


#define NDIS_STATUS_TAPI_RECV_DIGIT					((NDIS_STATUS)0x40010020L) // FIXME: Should this be in ndis.h?

#define LINE_ADDRESSSTATE                           0L
#define LINE_CALLINFO                               1L
#define LINE_CALLSTATE                              2L
#define LINE_CLOSE                                  3L
#define LINE_DEVSPECIFIC                            4L
#define LINE_DEVSPECIFICFEATURE                     5L  // not used
#define LINE_GATHERDIGITS                           6L  // not used
#define LINE_GENERATE                               7L  // not used
#define LINE_LINEDEVSTATE                           8L
#define LINE_MONITORDIGITS                          9L  // not used
#define LINE_MONITORMEDIA                           10L // not used
#define LINE_MONITORTONE                            11L // not used
#define LINE_REPLY                                  12L // not used
#define LINE_REQUEST                                13L // not used
#define LINE_CREATE                             	19L // TAPI v1.4

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINE_AGENTSPECIFIC                      21L             // TAPI v2.0
#define LINE_AGENTSTATUS                        22L             // TAPI v2.0
#define LINE_APPNEWCALL                         23L             // TAPI v2.0
#define LINE_PROXYREQUEST                       24L             // TAPI v2.0
#define LINE_REMOVE                             25L             // TAPI v2.0
#endif


#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020002)
#define LINE_AGENTSESSIONSTATUS                 27L             // TAPI v2.2
#define LINE_QUEUESTATUS                        28L             // TAPI v2.2
#define LINE_AGENTSTATUSEX                      29L             // TAPI v2.2
#define LINE_GROUPSTATUS                        30L             // TAPI v2.2
#define LINE_PROXYSTATUS                        31L             // TAPI v2.2
#endif


#if (TAPI_CURRENT_VERSION >= 0x00030000)
#define LINE_APPNEWCALLHUB                      32L             // TAPI v3.0
#define LINE_CALLHUBCLOSE                       33L             // TAPI v3.0
#define LINE_DEVSPECIFICEX                      34L             // TAPI v3.0
#endif


#define TSPI_MESSAGE_BASE                           500L

#define LINE_NEWCALL                                TSPI_MESSAGE_BASE
#define LINE_CALLDEVSPECIFIC                        (TSPI_MESSAGE_BASE + 1L)

#ifndef __NDISTAPI_STRINGFORMATS_DEFINED
#define __NDISTAPI_STRINGFORMATS_DEFINED

#define STRINGFORMAT_ASCII                          0x00000001
#define STRINGFORMAT_DBCS                           0x00000002
#define STRINGFORMAT_UNICODE                        0x00000003
#define STRINGFORMAT_BINARY                         0x00000004

#endif	// __NDISTAPI_STRINGFORMATS_DEFINED

#define LINEADDRCAPFLAGS_FWDNUMRINGS                0x00000001
#define LINEADDRCAPFLAGS_PICKUPGROUPID              0x00000002
#define LINEADDRCAPFLAGS_SECURE                     0x00000004
#define LINEADDRCAPFLAGS_BLOCKIDDEFAULT             0x00000008
#define LINEADDRCAPFLAGS_BLOCKIDOVERRIDE            0x00000010
#define LINEADDRCAPFLAGS_DIALED                     0x00000020
#define LINEADDRCAPFLAGS_ORIGOFFHOOK                0x00000040
#define LINEADDRCAPFLAGS_DESTOFFHOOK                0x00000080
#define LINEADDRCAPFLAGS_FWDCONSULT                 0x00000100
#define LINEADDRCAPFLAGS_SETUPCONFNULL              0x00000200
#define LINEADDRCAPFLAGS_AUTORECONNECT              0x00000400
#define LINEADDRCAPFLAGS_COMPLETIONID               0x00000800
#define LINEADDRCAPFLAGS_TRANSFERHELD               0x00001000
#define LINEADDRCAPFLAGS_TRANSFERMAKE               0x00002000
#define LINEADDRCAPFLAGS_CONFERENCEHELD             0x00004000
#define LINEADDRCAPFLAGS_CONFERENCEMAKE             0x00008000
#define LINEADDRCAPFLAGS_PARTIALDIAL                0x00010000
#define LINEADDRCAPFLAGS_FWDSTATUSVALID             0x00020000
#define LINEADDRCAPFLAGS_FWDINTEXTADDR              0x00040000
#define LINEADDRCAPFLAGS_FWDBUSYNAADDR              0x00080000
#define LINEADDRCAPFLAGS_ACCEPTTOALERT              0x00100000
#define LINEADDRCAPFLAGS_CONFDROP                   0x00200000
#define LINEADDRCAPFLAGS_PICKUPCALLWAIT             0x00400000
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEADDRCAPFLAGS_PREDICTIVEDIALER      		0x00800000      // TAPI v2.0
#define LINEADDRCAPFLAGS_QUEUE                  	0x01000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_ROUTEPOINT             	0x02000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_HOLDMAKESNEW           	0x04000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_NOINTERNALCALLS        	0x08000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_NOEXTERNALCALLS        	0x10000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_SETCALLINGID           	0x20000000      // TAPI v2.0
#endif
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
#define LINEADDRCAPFLAGS_ACDGROUP               	0x40000000      // TAPI v3.0
#define LINEADDRCAPFLAGS_NOPSTNADDRESSTRANSLATION 	0x80000000    // TAPI v3.0
#endif


#define LINEADDRESSMODE_ADDRESSID                   0x00000001
#define LINEADDRESSMODE_DIALABLEADDR                0x00000002

#define LINEADDRESSSHARING_PRIVATE                  0x00000001
#define LINEADDRESSSHARING_BRIDGEDEXCL              0x00000002
#define LINEADDRESSSHARING_BRIDGEDNEW               0x00000004
#define LINEADDRESSSHARING_BRIDGEDSHARED            0x00000008
#define LINEADDRESSSHARING_MONITORED                0x00000010

#define LINEADDRESSSTATE_OTHER                      0x00000001
#define LINEADDRESSSTATE_DEVSPECIFIC                0x00000002
#define LINEADDRESSSTATE_INUSEZERO                  0x00000004
#define LINEADDRESSSTATE_INUSEONE                   0x00000008
#define LINEADDRESSSTATE_INUSEMANY                  0x00000010
#define LINEADDRESSSTATE_NUMCALLS                   0x00000020
#define LINEADDRESSSTATE_FORWARD                    0x00000040
#define LINEADDRESSSTATE_TERMINALS                  0x00000080

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
#define LINEADDRESSTYPE_PHONENUMBER             0x00000001
#define LINEADDRESSTYPE_SDP                     0x00000002
#define LINEADDRESSTYPE_EMAILNAME               0x00000004
#define LINEADDRESSTYPE_DOMAINNAME              0x00000008
#define LINEADDRESSTYPE_IPADDRESS               0x00000010
#endif

#define LINEADDRFEATURE_FORWARD                     0x00000001
#define LINEADDRFEATURE_MAKECALL                    0x00000002
#define LINEADDRFEATURE_PICKUP                      0x00000004
#define LINEADDRFEATURE_SETMEDIACONTROL             0x00000008
#define LINEADDRFEATURE_SETTERMINAL                 0x00000010
#define LINEADDRFEATURE_SETUPCONF                   0x00000020
#define LINEADDRFEATURE_UNCOMPLETECALL              0x00000040
#define LINEADDRFEATURE_UNPARK                      0x00000080
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEADDRFEATURE_PICKUPHELD              0x00000100      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPGROUP             0x00000200      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPDIRECT            0x00000400      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPWAITING           0x00000800      // TAPI v2.0
#define LINEADDRFEATURE_FORWARDFWD              0x00001000      // TAPI v2.0
#define LINEADDRFEATURE_FORWARDDND              0x00002000      // TAPI v2.0
#endif


#define LINEANSWERMODE_NONE                         0x00000001
#define LINEANSWERMODE_DROP                         0x00000002
#define LINEANSWERMODE_HOLD                         0x00000004

#define LINEBEARERMODE_VOICE                        0x00000001
#define LINEBEARERMODE_SPEECH                       0x00000002
#define LINEBEARERMODE_MULTIUSE                     0x00000004
#define LINEBEARERMODE_DATA                         0x00000008
#define LINEBEARERMODE_ALTSPEECHDATA                0x00000010
#define LINEBEARERMODE_NONCALLSIGNALING             0x00000020
#define LINEBEARERMODE_PASSTHROUGH              0x00000040      // TAPI v1.4
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEBEARERMODE_RESTRICTEDDATA           0x00000080      // TAPI v2.0
#endif

#define LINEBUSYMODE_STATION                        0x00000001
#define LINEBUSYMODE_TRUNK                          0x00000002
#define LINEBUSYMODE_UNKNOWN                        0x00000004
#define LINEBUSYMODE_UNAVAIL                        0x00000008

#define LINECALLCOMPLCOND_BUSY                      0x00000001
#define LINECALLCOMPLCOND_NOANSWER                  0x00000002

#define LINECALLCOMPLMODE_CAMPON                    0x00000001
#define LINECALLCOMPLMODE_CALLBACK                  0x00000002
#define LINECALLCOMPLMODE_INTRUDE                   0x00000004
#define LINECALLCOMPLMODE_MESSAGE                   0x00000008

#define LINECALLFEATURE_ACCEPT                      0x00000001
#define LINECALLFEATURE_ADDTOCONF                   0x00000002
#define LINECALLFEATURE_ANSWER                      0x00000004
#define LINECALLFEATURE_BLINDTRANSFER               0x00000008
#define LINECALLFEATURE_COMPLETECALL                0x00000010
#define LINECALLFEATURE_COMPLETETRANSF              0x00000020
#define LINECALLFEATURE_DIAL                        0x00000040
#define LINECALLFEATURE_DROP                        0x00000080
#define LINECALLFEATURE_GATHERDIGITS                0x00000100
#define LINECALLFEATURE_GENERATEDIGITS              0x00000200
#define LINECALLFEATURE_GENERATETONE                0x00000400
#define LINECALLFEATURE_HOLD                        0x00000800
#define LINECALLFEATURE_MONITORDIGITS               0x00001000
#define LINECALLFEATURE_MONITORMEDIA                0x00002000
#define LINECALLFEATURE_MONITORTONES                0x00004000
#define LINECALLFEATURE_PARK                        0x00008000
#define LINECALLFEATURE_PREPAREADDCONF              0x00010000
#define LINECALLFEATURE_REDIRECT                    0x00020000
#define LINECALLFEATURE_REMOVEFROMCONF              0x00040000
#define LINECALLFEATURE_SECURECALL                  0x00080000
#define LINECALLFEATURE_SENDUSERUSER                0x00100000
#define LINECALLFEATURE_SETCALLPARAMS               0x00200000
#define LINECALLFEATURE_SETMEDIACONTROL             0x00400000
#define LINECALLFEATURE_SETTERMINAL                 0x00800000
#define LINECALLFEATURE_SETUPCONF                   0x01000000
#define LINECALLFEATURE_SETUPTRANSFER               0x02000000
#define LINECALLFEATURE_SWAPHOLD                    0x04000000
#define LINECALLFEATURE_UNHOLD                      0x08000000
#define LINECALLFEATURE_RELEASEUSERUSERINFO     0x10000000      // TAPI v1.4
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLFEATURE_SETTREATMENT            0x20000000      // TAPI v2.0
#define LINECALLFEATURE_SETQOS                  0x40000000      // TAPI v2.0
#define LINECALLFEATURE_SETCALLDATA             0x80000000      // TAPI v2.0
#endif


#define LINECALLINFOSTATE_OTHER                     0x00000001
#define LINECALLINFOSTATE_DEVSPECIFIC               0x00000002
#define LINECALLINFOSTATE_BEARERMODE                0x00000004
#define LINECALLINFOSTATE_RATE                      0x00000008
#define LINECALLINFOSTATE_MEDIAMODE                 0x00000010
#define LINECALLINFOSTATE_APPSPECIFIC               0x00000020
#define LINECALLINFOSTATE_CALLID                    0x00000040
#define LINECALLINFOSTATE_RELATEDCALLID             0x00000080
#define LINECALLINFOSTATE_ORIGIN                    0x00000100
#define LINECALLINFOSTATE_REASON                    0x00000200
#define LINECALLINFOSTATE_COMPLETIONID              0x00000400
#define LINECALLINFOSTATE_NUMOWNERINCR              0x00000800
#define LINECALLINFOSTATE_NUMOWNERDECR              0x00001000
#define LINECALLINFOSTATE_NUMMONITORS               0x00002000
#define LINECALLINFOSTATE_TRUNK                     0x00004000
#define LINECALLINFOSTATE_CALLERID                  0x00008000
#define LINECALLINFOSTATE_CALLEDID                  0x00010000
#define LINECALLINFOSTATE_CONNECTEDID               0x00020000
#define LINECALLINFOSTATE_REDIRECTIONID             0x00040000
#define LINECALLINFOSTATE_REDIRECTINGID             0x00080000
#define LINECALLINFOSTATE_DISPLAY                   0x00100000
#define LINECALLINFOSTATE_USERUSERINFO              0x00200000
#define LINECALLINFOSTATE_HIGHLEVELCOMP             0x00400000
#define LINECALLINFOSTATE_LOWLEVELCOMP              0x00800000
#define LINECALLINFOSTATE_CHARGINGINFO              0x01000000
#define LINECALLINFOSTATE_TERMINAL                  0x02000000
#define LINECALLINFOSTATE_DIALPARAMS                0x04000000
#define LINECALLINFOSTATE_MONITORMODES              0x08000000
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLINFOSTATE_TREATMENT             0x10000000      // TAPI v2.0
#define LINECALLINFOSTATE_QOS                   0x20000000      // TAPI v2.0
#define LINECALLINFOSTATE_CALLDATA              0x40000000      // TAPI v2.0
#endif


#define LINECALLORIGIN_OUTBOUND                     0x00000001
#define LINECALLORIGIN_INTERNAL                     0x00000002
#define LINECALLORIGIN_EXTERNAL                     0x00000004
#define LINECALLORIGIN_UNKNOWN                      0x00000010
#define LINECALLORIGIN_UNAVAIL                      0x00000020
#define LINECALLORIGIN_CONFERENCE                   0x00000040
#define LINECALLORIGIN_INBOUND                      0x00000080

#define LINECALLPARAMFLAGS_SECURE                   0x00000001
#define LINECALLPARAMFLAGS_IDLE                     0x00000002
#define LINECALLPARAMFLAGS_BLOCKID                  0x00000004
#define LINECALLPARAMFLAGS_ORIGOFFHOOK              0x00000008
#define LINECALLPARAMFLAGS_DESTOFFHOOK              0x00000010
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLPARAMFLAGS_NOHOLDCONFERENCE     0x00000020      // TAPI v2.0
#define LINECALLPARAMFLAGS_PREDICTIVEDIAL       0x00000040      // TAPI v2.0
#define LINECALLPARAMFLAGS_ONESTEPTRANSFER      0x00000080      // TAPI v2.0
#endif


#define LINECALLPARTYID_BLOCKED                     0x00000001
#define LINECALLPARTYID_OUTOFAREA                   0x00000002
#define LINECALLPARTYID_NAME                        0x00000004
#define LINECALLPARTYID_ADDRESS                     0x00000008
#define LINECALLPARTYID_PARTIAL                     0x00000010
#define LINECALLPARTYID_UNKNOWN                     0x00000020
#define LINECALLPARTYID_UNAVAIL                     0x00000040

#define LINECALLPRIVILEGE_NONE                      0x00000001
#define LINECALLPRIVILEGE_MONITOR                   0x00000002
#define LINECALLPRIVILEGE_OWNER                     0x00000004

#define LINECALLREASON_DIRECT                       0x00000001
#define LINECALLREASON_FWDBUSY                      0x00000002
#define LINECALLREASON_FWDNOANSWER                  0x00000004
#define LINECALLREASON_FWDUNCOND                    0x00000008
#define LINECALLREASON_PICKUP                       0x00000010
#define LINECALLREASON_UNPARK                       0x00000020
#define LINECALLREASON_REDIRECT                     0x00000040
#define LINECALLREASON_CALLCOMPLETION               0x00000080
#define LINECALLREASON_TRANSFER                     0x00000100
#define LINECALLREASON_REMINDER                     0x00000200
#define LINECALLREASON_UNKNOWN                      0x00000400
#define LINECALLREASON_UNAVAIL                      0x00000800
#define LINECALLREASON_INTRUDE                  0x00001000      // TAPI v1.4
#define LINECALLREASON_PARKED                   0x00002000      // TAPI v1.4
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLREASON_CAMPEDON                 0x00004000      // TAPI v2.0
#define LINECALLREASON_ROUTEREQUEST             0x00008000      // TAPI v2.0
#endif


#define LINECALLSELECT_LINE                         0x00000001
#define LINECALLSELECT_ADDRESS                      0x00000002
#define LINECALLSELECT_CALL                         0x00000004
#if (NDIS_TAPI_CURRENT_VERSION > 0x00020000)
#define LINECALLSELECT_DEVICEID                 0x00000008
#endif
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
#define LINECALLSELECT_CALLID                   0x00000010
#endif


#define LINECALLSTATE_IDLE                          0x00000001
#define LINECALLSTATE_OFFERING                      0x00000002
#define LINECALLSTATE_ACCEPTED                      0x00000004
#define LINECALLSTATE_DIALTONE                      0x00000008
#define LINECALLSTATE_DIALING                       0x00000010
#define LINECALLSTATE_RINGBACK                      0x00000020
#define LINECALLSTATE_BUSY                          0x00000040
#define LINECALLSTATE_SPECIALINFO                   0x00000080
#define LINECALLSTATE_CONNECTED                     0x00000100
#define LINECALLSTATE_PROCEEDING                    0x00000200
#define LINECALLSTATE_ONHOLD                        0x00000400
#define LINECALLSTATE_CONFERENCED                   0x00000800
#define LINECALLSTATE_ONHOLDPENDCONF                0x00001000
#define LINECALLSTATE_ONHOLDPENDTRANSFER            0x00002000
#define LINECALLSTATE_DISCONNECTED                  0x00004000
#define LINECALLSTATE_UNKNOWN                       0x00008000

#define LINEDEVCAPFLAGS_CROSSADDRCONF               0x00000001
#define LINEDEVCAPFLAGS_HIGHLEVCOMP                 0x00000002
#define LINEDEVCAPFLAGS_LOWLEVCOMP                  0x00000004
#define LINEDEVCAPFLAGS_MEDIACONTROL                0x00000008
#define LINEDEVCAPFLAGS_MULTIPLEADDR                0x00000010
#define LINEDEVCAPFLAGS_CLOSEDROP                   0x00000020
#define LINEDEVCAPFLAGS_DIALBILLING                 0x00000040
#define LINEDEVCAPFLAGS_DIALQUIET                   0x00000080
#define LINEDEVCAPFLAGS_DIALDIALTONE                0x00000100
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
#define LINEDEVCAPFLAGS_MSP                     0x00000200      // TAPI v3.0
#define LINEDEVCAPFLAGS_CALLHUB                 0x00000400      // TAPI v3.0
#define LINEDEVCAPFLAGS_CALLHUBTRACKING         0x00000800      // TAPI v3.0
#define LINEDEVCAPFLAGS_PRIVATEOBJECTS          0x00001000      // TAPI v3.0
#endif


#define LINEDEVSTATE_OTHER                          0x00000001
#define LINEDEVSTATE_RINGING                        0x00000002
#define LINEDEVSTATE_CONNECTED                      0x00000004
#define LINEDEVSTATE_DISCONNECTED                   0x00000008
#define LINEDEVSTATE_MSGWAITON                      0x00000010
#define LINEDEVSTATE_MSGWAITOFF                     0x00000020
#define LINEDEVSTATE_INSERVICE                      0x00000040
#define LINEDEVSTATE_OUTOFSERVICE                   0x00000080
#define LINEDEVSTATE_MAINTENANCE                    0x00000100
#define LINEDEVSTATE_OPEN                           0x00000200
#define LINEDEVSTATE_CLOSE                          0x00000400
#define LINEDEVSTATE_NUMCALLS                       0x00000800
#define LINEDEVSTATE_NUMCOMPLETIONS                 0x00001000
#define LINEDEVSTATE_TERMINALS                      0x00002000
#define LINEDEVSTATE_ROAMMODE                       0x00004000
#define LINEDEVSTATE_BATTERY                        0x00008000
#define LINEDEVSTATE_SIGNAL                         0x00010000
#define LINEDEVSTATE_DEVSPECIFIC                    0x00020000
#define LINEDEVSTATE_REINIT                         0x00040000
#define LINEDEVSTATE_LOCK                           0x00080000

#define LINEDEVSTATUSFLAGS_CONNECTED                0x00000001
#define LINEDEVSTATUSFLAGS_MSGWAIT                  0x00000002
#define LINEDEVSTATUSFLAGS_INSERVICE                0x00000004
#define LINEDEVSTATUSFLAGS_LOCKED                   0x00000008

#define LINEDIALTONEMODE_NORMAL                     0x00000001
#define LINEDIALTONEMODE_SPECIAL                    0x00000002
#define LINEDIALTONEMODE_INTERNAL                   0x00000004
#define LINEDIALTONEMODE_EXTERNAL                   0x00000008
#define LINEDIALTONEMODE_UNKNOWN                    0x00000010
#define LINEDIALTONEMODE_UNAVAIL                    0x00000020

#define LINEDIGITMODE_PULSE                         0x00000001
#define LINEDIGITMODE_DTMF                          0x00000002
#define LINEDIGITMODE_DTMFEND                       0x00000004

#define LINEDISCONNECTMODE_NORMAL                   0x00000001
#define LINEDISCONNECTMODE_UNKNOWN                  0x00000002
#define LINEDISCONNECTMODE_REJECT                   0x00000004
#define LINEDISCONNECTMODE_PICKUP                   0x00000008
#define LINEDISCONNECTMODE_FORWARDED                0x00000010
#define LINEDISCONNECTMODE_BUSY                     0x00000020
#define LINEDISCONNECTMODE_NOANSWER                 0x00000040
#define LINEDISCONNECTMODE_BADADDRESS               0x00000080
#define LINEDISCONNECTMODE_UNREACHABLE              0x00000100
#define LINEDISCONNECTMODE_CONGESTION               0x00000200
#define LINEDISCONNECTMODE_INCOMPATIBLE             0x00000400
#define LINEDISCONNECTMODE_UNAVAIL                  0x00000800
#define LINEDISCONNECTMODE_NODIALTONE           0x00001000      // TAPI v1.4
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEDISCONNECTMODE_NUMBERCHANGED        0x00002000      // TAPI v2.0
#define LINEDISCONNECTMODE_OUTOFORDER           0x00004000      // TAPI v2.0
#define LINEDISCONNECTMODE_TEMPFAILURE          0x00008000      // TAPI v2.0
#define LINEDISCONNECTMODE_QOSUNAVAIL           0x00010000      // TAPI v2.0
#define LINEDISCONNECTMODE_BLOCKED              0x00020000      // TAPI v2.0
#define LINEDISCONNECTMODE_DONOTDISTURB         0x00040000      // TAPI v2.0
#define LINEDISCONNECTMODE_CANCELLED            0x00080000      // TAPI v2.0
#endif


#define LINEFEATURE_DEVSPECIFIC                     0x00000001
#define LINEFEATURE_DEVSPECIFICFEAT                 0x00000002
#define LINEFEATURE_FORWARD                         0x00000004
#define LINEFEATURE_MAKECALL                        0x00000008
#define LINEFEATURE_SETMEDIACONTROL                 0x00000010
#define LINEFEATURE_SETTERMINAL                     0x00000020
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEFEATURE_SETDEVSTATUS                0x00000040      // TAPI v2.0
#define LINEFEATURE_FORWARDFWD                  0x00000080      // TAPI v2.0
#define LINEFEATURE_FORWARDDND                  0x00000100      // TAPI v2.0
#endif


#define LINEFORWARDMODE_UNCOND                      0x00000001
#define LINEFORWARDMODE_UNCONDINTERNAL              0x00000002
#define LINEFORWARDMODE_UNCONDEXTERNAL              0x00000004
#define LINEFORWARDMODE_UNCONDSPECIFIC              0x00000008
#define LINEFORWARDMODE_BUSY                        0x00000010
#define LINEFORWARDMODE_BUSYINTERNAL                0x00000020
#define LINEFORWARDMODE_BUSYEXTERNAL                0x00000040
#define LINEFORWARDMODE_BUSYSPECIFIC                0x00000080
#define LINEFORWARDMODE_NOANSW                      0x00000100
#define LINEFORWARDMODE_NOANSWINTERNAL              0x00000200
#define LINEFORWARDMODE_NOANSWEXTERNAL              0x00000400
#define LINEFORWARDMODE_NOANSWSPECIFIC              0x00000800
#define LINEFORWARDMODE_BUSYNA                      0x00001000
#define LINEFORWARDMODE_BUSYNAINTERNAL              0x00002000
#define LINEFORWARDMODE_BUSYNAEXTERNAL              0x00004000
#define LINEFORWARDMODE_BUSYNASPECIFIC              0x00008000

#define LINEGATHERTERM_BUFFERFULL                   0x00000001
#define LINEGATHERTERM_TERMDIGIT                    0x00000002
#define LINEGATHERTERM_FIRSTTIMEOUT                 0x00000004
#define LINEGATHERTERM_INTERTIMEOUT                 0x00000008
#define LINEGATHERTERM_CANCEL                       0x00000010

#define LINEGENERATETERM_DONE                       0x00000001
#define LINEGENERATETERM_CANCEL                     0x00000002

#define LINEMEDIACONTROL_NONE                       0x00000001
#define LINEMEDIACONTROL_START                      0x00000002
#define LINEMEDIACONTROL_RESET                      0x00000004
#define LINEMEDIACONTROL_PAUSE                      0x00000008
#define LINEMEDIACONTROL_RESUME                     0x00000010
#define LINEMEDIACONTROL_RATEUP                     0x00000020
#define LINEMEDIACONTROL_RATEDOWN                   0x00000040
#define LINEMEDIACONTROL_RATENORMAL                 0x00000080
#define LINEMEDIACONTROL_VOLUMEUP                   0x00000100
#define LINEMEDIACONTROL_VOLUMEDOWN                 0x00000200
#define LINEMEDIACONTROL_VOLUMENORMAL               0x00000400

#define LINEMEDIAMODE_UNKNOWN                       0x00000002
#define LINEMEDIAMODE_INTERACTIVEVOICE              0x00000004
#define LINEMEDIAMODE_AUTOMATEDVOICE                0x00000008
#define LINEMEDIAMODE_DATAMODEM                     0x00000010
#define LINEMEDIAMODE_G3FAX                         0x00000020
#define LINEMEDIAMODE_TDD                           0x00000040
#define LINEMEDIAMODE_G4FAX                         0x00000080
#define LINEMEDIAMODE_DIGITALDATA                   0x00000100
#define LINEMEDIAMODE_TELETEX                       0x00000200
#define LINEMEDIAMODE_VIDEOTEX                      0x00000400
#define LINEMEDIAMODE_TELEX                         0x00000800
#define LINEMEDIAMODE_MIXED                         0x00001000
#define LINEMEDIAMODE_ADSI                          0x00002000

#define LINEMEDIAMODE_VOICEVIEW                 0x00004000      // TAPI v1.4
#define LAST_LINEMEDIAMODE                          0x00004000
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020001)
#define LINEMEDIAMODE_VIDEO                     0x00008000      // TAPI v2.1
#undef LAST_LINEMEDIAMODE
#define LAST_LINEMEDIAMODE                      0x00008000		// Should override last definition.
#endif




#define LINEPARKMODE_DIRECTED                       0x00000001
#define LINEPARKMODE_NONDIRECTED                    0x00000002

#define LINEREMOVEFROMCONF_NONE                     0x00000001
#define LINEREMOVEFROMCONF_LAST                     0x00000002
#define LINEREMOVEFROMCONF_ANY                      0x00000003

#define LINEREQUESTMODE_MAKECALL                    0x00000001
#define LINEREQUESTMODE_MEDIACALL                   0x00000002
#define LINEREQUESTMODE_DROP                        0x00000004

#define LAST_LINEREQUESTMODE                        LINEREQUESTMODE_MEDIACALL

#define LINEROAMMODE_UNKNOWN                        0x00000001
#define LINEROAMMODE_UNAVAIL                        0x00000002
#define LINEROAMMODE_HOME                           0x00000004
#define LINEROAMMODE_ROAMA                          0x00000008
#define LINEROAMMODE_ROAMB                          0x00000010

#define LINESPECIALINFO_NOCIRCUIT                   0x00000001
#define LINESPECIALINFO_CUSTIRREG                   0x00000002
#define LINESPECIALINFO_REORDER                     0x00000004
#define LINESPECIALINFO_UNKNOWN                     0x00000008
#define LINESPECIALINFO_UNAVAIL                     0x00000010

#define LINETERMDEV_PHONE                           0x00000001
#define LINETERMDEV_HEADSET                         0x00000002
#define LINETERMDEV_SPEAKER                         0x00000004

#define LINETERMMODE_BUTTONS                        0x00000001
#define LINETERMMODE_LAMPS                          0x00000002
#define LINETERMMODE_DISPLAY                        0x00000004
#define LINETERMMODE_RINGER                         0x00000008
#define LINETERMMODE_HOOKSWITCH                     0x00000010
#define LINETERMMODE_MEDIATOLINE                    0x00000020
#define LINETERMMODE_MEDIAFROMLINE                  0x00000040
#define LINETERMMODE_MEDIABIDIRECT                  0x00000080

#define LINETERMSHARING_PRIVATE                     0x00000001
#define LINETERMSHARING_SHAREDEXCL                  0x00000002
#define LINETERMSHARING_SHAREDCONF                  0x00000004

#define LINETONEMODE_CUSTOM                         0x00000001
#define LINETONEMODE_RINGBACK                       0x00000002
#define LINETONEMODE_BUSY                           0x00000004
#define LINETONEMODE_BEEP                           0x00000008
#define LINETONEMODE_BILLING                        0x00000010

#define LINETRANSFERMODE_TRANSFER                   0x00000001
#define LINETRANSFERMODE_CONFERENCE                 0x00000002

#define LINETOLLLISTOPTION_ADD                      0x00000001
#define LINETOLLLISTOPTION_REMOVE                   0x00000002

#define LINETRANSLATEOPTION_CARDOVERRIDE            0x00000001

#define LINETRANSLATERESULT_CANONICAL               0x00000001
#define LINETRANSLATERESULT_INTERNATIONAL           0x00000002
#define LINETRANSLATERESULT_LONGDISTANCE            0x00000004
#define LINETRANSLATERESULT_LOCAL                   0x00000008
#define LINETRANSLATERESULT_INTOLLLIST              0x00000010
#define LINETRANSLATERESULT_NOTINTOLLLIST           0x00000020
#define LINETRANSLATERESULT_DIALBILLING             0x00000040
#define LINETRANSLATERESULT_DIALQUIET               0x00000080
#define LINETRANSLATERESULT_DIALDIALTONE            0x00000100
#define LINETRANSLATERESULT_DIALPROMPT              0x00000200
#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
#define LINETRANSLATERESULT_VOICEDETECT      		0x00000400      // TAPI v2.0
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)                                           
#define LINETRANSLATERESULT_NOTRANSLATION       	0x00000800      // TAPI v3.0       
#endif              

//
// Type definitions
//

typedef ULONG_PTR HTAPI_LINE;
typedef ULONG_PTR HDRV_LINE;
typedef ULONG_PTR HTAPI_CALL;
typedef ULONG_PTR HDRV_CALL;

typedef struct _LINE_ADDRESS_CAPS
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulLineDeviceID;

    ULONG   ulAddressSize;
    ULONG   ulAddressOffset;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

    ULONG   ulAddressSharing;
    ULONG   ulAddressStates;
    ULONG   ulCallInfoStates;
    ULONG   ulCallerIDFlags;
    ULONG   ulCalledIDFlags;
    ULONG   ulConnectedIDFlags;
    ULONG   ulRedirectionIDFlags;
    ULONG   ulRedirectingIDFlags;
    ULONG   ulCallStates;
    ULONG   ulDialToneModes;
    ULONG   ulBusyModes;
    ULONG   ulSpecialInfo;
    ULONG   ulDisconnectModes;

    ULONG   ulMaxNumActiveCalls;
    ULONG   ulMaxNumOnHoldCalls;
    ULONG   ulMaxNumOnHoldPendingCalls;
    ULONG   ulMaxNumConference;
    ULONG   ulMaxNumTransConf;

    ULONG   ulAddrCapFlags;
    ULONG   ulCallFeatures;
    ULONG   ulRemoveFromConfCaps;
    ULONG   ulRemoveFromConfState;
    ULONG   ulTransferModes;
    ULONG   ulParkModes;

    ULONG   ulForwardModes;
    ULONG   ulMaxForwardEntries;
    ULONG   ulMaxSpecificEntries;
    ULONG   ulMinFwdNumRings;
    ULONG   ulMaxFwdNumRings;

    ULONG   ulMaxCallCompletions;
    ULONG   ulCallCompletionConds;
    ULONG   ulCallCompletionModes;
    ULONG   ulNumCompletionMessages;
    ULONG   ulCompletionMsgTextEntrySize;
    ULONG   ulCompletionMsgTextSize;
    ULONG   ulCompletionMsgTextOffset;

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00010004)
    ULONG   ulAddressFeatures;                              // TAPI v1.4

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
    ULONG   ulPredictiveAutoTransferStates;                 // TAPI v2.0
    ULONG   ulNumCallTreatments;                            // TAPI v2.0
    ULONG   ulCallTreatmentListSize;                        // TAPI v2.0
    ULONG   ulCallTreatmentListOffset;                      // TAPI v2.0
    ULONG   ulDeviceClassesSize;                            // TAPI v2.0
    ULONG   ulDeviceClassesOffset;                          // TAPI v2.0
    ULONG   ulMaxCallDataSize;                              // TAPI v2.0
    ULONG   ulCallFeatures2;                                // TAPI v2.0
    ULONG   ulMaxNoAnswerTimeout;                           // TAPI v2.0
    ULONG   ulConnectedModes;                               // TAPI v2.0
    ULONG   ulOfferingModes;                                // TAPI v2.0
    ULONG   ulAvailableMediaModes;                          // TAPI v2.0
#endif
#endif

} LINE_ADDRESS_CAPS, *PLINE_ADDRESS_CAPS;


typedef struct _LINE_ADDRESS_STATUS
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulNumInUse;
    ULONG   ulNumActiveCalls;
    ULONG   ulNumOnHoldCalls;
    ULONG   ulNumOnHoldPendCalls;
    ULONG   ulAddressFeatures;

    ULONG   ulNumRingsNoAnswer;
    ULONG   ulForwardNumEntries;
    ULONG   ulForwardSize;
    ULONG   ulForwardOffset;

    ULONG   ulTerminalModesSize;
    ULONG   ulTerminalModesOffset;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

} LINE_ADDRESS_STATUS, *PLINE_ADDRESS_STATUS;


typedef struct _LINE_DIAL_PARAMS
{
    ULONG   ulDialPause;
    ULONG   ulDialSpeed;
    ULONG   ulDigitDuration;
    ULONG   ulWaitForDialtone;

} LINE_DIAL_PARAMS, *PLINE_DIAL_PARAMS;


typedef struct _LINE_CALL_INFO
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   hLine;
    ULONG   ulLineDeviceID;
    ULONG   ulAddressID;

    ULONG   ulBearerMode;
    ULONG   ulRate;
    ULONG   ulMediaMode;

    ULONG   ulAppSpecific;
    ULONG   ulCallID;
    ULONG   ulRelatedCallID;
    ULONG   ulCallParamFlags;
    ULONG   ulCallStates;

    ULONG   ulMonitorDigitModes;
    ULONG   ulMonitorMediaModes;
    LINE_DIAL_PARAMS    DialParams;

    ULONG   ulOrigin;
    ULONG   ulReason;
    ULONG   ulCompletionID;
    ULONG   ulNumOwners;
    ULONG   ulNumMonitors;

    ULONG   ulCountryCode;
    ULONG   ulTrunk;

    ULONG   ulCallerIDFlags;
    ULONG   ulCallerIDSize;
    ULONG   ulCallerIDOffset;
    ULONG   ulCallerIDNameSize;
    ULONG   ulCallerIDNameOffset;

    ULONG   ulCalledIDFlags;
    ULONG   ulCalledIDSize;
    ULONG   ulCalledIDOffset;
    ULONG   ulCalledIDNameSize;
    ULONG   ulCalledIDNameOffset;

    ULONG   ulConnectedIDFlags;
    ULONG   ulConnectedIDSize;
    ULONG   ulConnectedIDOffset;
    ULONG   ulConnectedIDNameSize;
    ULONG   ulConnectedIDNameOffset;

    ULONG   ulRedirectionIDFlags;
    ULONG   ulRedirectionIDSize;
    ULONG   ulRedirectionIDOffset;
    ULONG   ulRedirectionIDNameSize;
    ULONG   ulRedirectionIDNameOffset;

    ULONG   ulRedirectingIDFlags;
    ULONG   ulRedirectingIDSize;
    ULONG   ulRedirectingIDOffset;
    ULONG   ulRedirectingIDNameSize;
    ULONG   ulRedirectingIDNameOffset;

    ULONG   ulAppNameSize;
    ULONG   ulAppNameOffset;

    ULONG   ulDisplayableAddressSize;
    ULONG   ulDisplayableAddressOffset;

    ULONG   ulCalledPartySize;
    ULONG   ulCalledPartyOffset;

    ULONG   ulCommentSize;
    ULONG   ulCommentOffset;

    ULONG   ulDisplaySize;
    ULONG   ulDisplayOffset;

    ULONG   ulUserUserInfoSize;
    ULONG   ulUserUserInfoOffset;

    ULONG   ulHighLevelCompSize;
    ULONG   ulHighLevelCompOffset;

    ULONG   ulLowLevelCompSize;
    ULONG   ulLowLevelCompOffset;

    ULONG   ulChargingInfoSize;
    ULONG   ulChargingInfoOffset;

    ULONG   ulTerminalModesSize;
    ULONG   ulTerminalModesOffset;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
    ULONG       ulCallTreatment;                                // TAPI v2.0
    ULONG       ulCallDataSize;                                 // TAPI v2.0
    ULONG       ulCallDataOffset;                               // TAPI v2.0
    ULONG       ulSendingFlowspecSize;                          // TAPI v2.0
    ULONG       ulSendingFlowspecOffset;                        // TAPI v2.0
    ULONG       ulReceivingFlowspecSize;                        // TAPI v2.0
    ULONG       ulReceivingFlowspecOffset;                      // TAPI v2.0
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
    ULONG       ulCallerIDAddressType;                          // TAPI v3.0
    ULONG       ulCalledIDAddressType;                          // TAPI v3.0
    ULONG       ulConnectedIDAddressType;                       // TAPI v3.0
    ULONG       ulRedirectionIDAddressType;                     // TAPI v3.0
    ULONG       ulRedirectingIDAddressType;                     // TAPI v3.0
#endif

} LINE_CALL_INFO, *PLINE_CALL_INFO;


typedef struct _LINE_CALL_PARAMS        // Defaults:
{
    ULONG   ulTotalSize;                // ---------

    ULONG   ulBearerMode;               // voice
    ULONG   ulMinRate;                  // (3.1kHz)
    ULONG   ulMaxRate;                  // (3.1kHz)
    ULONG   ulMediaMode;                // interactiveVoice

    ULONG   ulCallParamFlags;           // 0
    ULONG   ulAddressMode;              // addressID
    ULONG   ulAddressID;                // (any available)

    LINE_DIAL_PARAMS DialParams;        // (0, 0, 0, 0)

    ULONG   ulOrigAddressSize;          // 0
    ULONG   ulOrigAddressOffset;
    ULONG   ulDisplayableAddressSize;
    ULONG   ulDisplayableAddressOffset;

    ULONG   ulCalledPartySize;          // 0
    ULONG   ulCalledPartyOffset;

    ULONG   ulCommentSize;              // 0
    ULONG   ulCommentOffset;

    ULONG   ulUserUserInfoSize;         // 0
    ULONG   ulUserUserInfoOffset;

    ULONG   ulHighLevelCompSize;        // 0
    ULONG   ulHighLevelCompOffset;

    ULONG   ulLowLevelCompSize;         // 0
    ULONG   ulLowLevelCompOffset;

    ULONG   ulDevSpecificSize;          // 0
    ULONG   ulDevSpecificOffset;

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
    ULONG       ulPredictiveAutoTransferStates;                 // TAPI v2.0
    ULONG       ulTargetAddressSize;                            // TAPI v2.0
    ULONG       ulTargetAddressOffset;                          // TAPI v2.0
    ULONG       ulSendingFlowspecSize;                          // TAPI v2.0
    ULONG       ulSendingFlowspecOffset;                        // TAPI v2.0
    ULONG       ulReceivingFlowspecSize;                        // TAPI v2.0
    ULONG       ulReceivingFlowspecOffset;                      // TAPI v2.0
    ULONG       ulDeviceClassSize;                              // TAPI v2.0
    ULONG       ulDeviceClassOffset;                            // TAPI v2.0
    ULONG       ulDeviceConfigSize;                             // TAPI v2.0
    ULONG       ulDeviceConfigOffset;                           // TAPI v2.0
    ULONG       ulCallDataSize;                                 // TAPI v2.0
    ULONG       ulCallDataOffset;                               // TAPI v2.0
    ULONG       ulNoAnswerTimeout;                              // TAPI v2.0
    ULONG       ulCallingPartyIDSize;                           // TAPI v2.0
    ULONG       ulCallingPartyIDOffset;                         // TAPI v2.0
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
    ULONG       ulAddressType;                                  // TAPI v3.0
#endif

} LINE_CALL_PARAMS, *PLINE_CALL_PARAMS;


typedef struct _LINE_CALL_STATUS
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulCallState;
    ULONG   ulCallStateMode;
    ULONG   ulCallPrivilege;
    ULONG   ulCallFeatures;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

} LINE_CALL_STATUS, *PLINE_CALL_STATUS;


typedef struct _LINE_EXTENSION_ID
{
    ULONG   ulExtensionID0;
    ULONG   ulExtensionID1;
    ULONG   ulExtensionID2;
    ULONG   ulExtensionID3;

} LINE_EXTENSION_ID, *PLINE_EXTENSION_ID;


typedef struct _LINE_DEV_CAPS
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulProviderInfoSize;
    ULONG   ulProviderInfoOffset;

    ULONG   ulSwitchInfoSize;
    ULONG   ulSwitchInfoOffset;

    ULONG   ulPermanentLineID;
    ULONG   ulLineNameSize;
    ULONG   ulLineNameOffset;
    ULONG   ulStringFormat;

    ULONG   ulAddressModes;
    ULONG   ulNumAddresses;
    ULONG   ulBearerModes;
    ULONG   ulMaxRate;
    ULONG   ulMediaModes;

    ULONG   ulGenerateToneModes;
    ULONG   ulGenerateToneMaxNumFreq;
    ULONG   ulGenerateDigitModes;
    ULONG   ulMonitorToneMaxNumFreq;
    ULONG   ulMonitorToneMaxNumEntries;
    ULONG   ulMonitorDigitModes;
    ULONG   ulGatherDigitsMinTimeout;
    ULONG   ulGatherDigitsMaxTimeout;

    ULONG   ulMedCtlDigitMaxListSize;
    ULONG   ulMedCtlMediaMaxListSize;
    ULONG   ulMedCtlToneMaxListSize;
    ULONG   ulMedCtlCallStateMaxListSize;

    ULONG   ulDevCapFlags;
    ULONG   ulMaxNumActiveCalls;
    ULONG   ulAnswerMode;
    ULONG   ulRingModes;
    ULONG   ulLineStates;

    ULONG   ulUUIAcceptSize;
    ULONG   ulUUIAnswerSize;
    ULONG   ulUUIMakeCallSize;
    ULONG   ulUUIDropSize;
    ULONG   ulUUISendUserUserInfoSize;
    ULONG   ulUUICallInfoSize;

    LINE_DIAL_PARAMS    MinDialParams;
    LINE_DIAL_PARAMS    MaxDialParams;
    LINE_DIAL_PARAMS    DefaultDialParams;

    ULONG   ulNumTerminals;
    ULONG   ulTerminalCapsSize;
    ULONG   ulTerminalCapsOffset;
    ULONG   ulTerminalTextEntrySize;
    ULONG   ulTerminalTextSize;
    ULONG   ulTerminalTextOffset;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00010004)
    ULONG   ulLineFeatures;                                 // TAPI v1.4
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020000)
    ULONG       ulSettableDevStatus;                            // TAPI v2.0
    ULONG       ulDeviceClassesSize;                            // TAPI v2.0
    ULONG       ulDeviceClassesOffset;                          // TAPI v2.0
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00020002)
	GUID        PermanentLineGuid;                              // TAPI v3.0
#endif

#if (NDIS_TAPI_CURRENT_VERSION >= 0x00030000)
    ULONG       ulAddressTypes;                                 // TAPI v3.0
    GUID        ProtocolGuid;                                   // TAPI v3.0
    ULONG       ulAvailableTracking;                            // TAPI v3.0    
#endif

} LINE_DEV_CAPS, *PLINE_DEV_CAPS;


typedef struct _LINE_DEV_STATUS
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulNumOpens;
    ULONG   ulOpenMediaModes;
    ULONG   ulNumActiveCalls;
    ULONG   ulNumOnHoldCalls;
    ULONG   ulNumOnHoldPendCalls;
    ULONG   ulLineFeatures;
    ULONG   ulNumCallCompletions;
    ULONG   ulRingMode;
    ULONG   ulSignalLevel;
    ULONG   ulBatteryLevel;
    ULONG   ulRoamMode;

    ULONG   ulDevStatusFlags;

    ULONG   ulTerminalModesSize;
    ULONG   ulTerminalModesOffset;

    ULONG   ulDevSpecificSize;
    ULONG   ulDevSpecificOffset;

} LINE_DEV_STATUS, *PLINE_DEV_STATUS;


#ifndef __NDISTAPI_VAR_STRING_DECLARED
#define __NDISTAPI_VAR_STRING_DECLARED

typedef struct _VAR_STRING
{
    ULONG   ulTotalSize;
    ULONG   ulNeededSize;
    ULONG   ulUsedSize;

    ULONG   ulStringFormat;
    ULONG   ulStringSize;
    ULONG   ulStringOffset;

} VAR_STRING, *PVAR_STRING;

#endif // __NDISTAPI_VAR_STRING_DECLARED

typedef struct _NDIS_TAPI_ACCEPT
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulUserUserInfoSize;
    __in  UCHAR       UserUserInfo[1];

} NDIS_TAPI_ACCEPT, *PNDIS_TAPI_ACCEPT;


typedef struct _NDIS_TAPI_ANSWER
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulUserUserInfoSize;
    __in  UCHAR       UserUserInfo[1];

} NDIS_TAPI_ANSWER, *PNDIS_TAPI_ANSWER;


typedef struct _NDIS_TAPI_CLOSE
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;

} NDIS_TAPI_CLOSE, *PNDIS_TAPI_CLOSE;


typedef struct _NDIS_TAPI_CLOSE_CALL
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;

} NDIS_TAPI_CLOSE_CALL, *PNDIS_TAPI_CLOSE_CALL;


typedef struct _NDIS_TAPI_CONDITIONAL_MEDIA_DETECTION
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __in  ULONG       ulMediaModes;
    __in  LINE_CALL_PARAMS    LineCallParams;

} NDIS_TAPI_CONDITIONAL_MEDIA_DETECTION,
*PNDIS_TAPI_CONDITIONAL_MEDIA_DETECTION;


typedef struct _NDIS_TAPI_CONFIG_DIALOG
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceID;
    __in  ULONG       ulDeviceClassSize;
    __in  ULONG       ulDeviceClassOffset;
    __in  ULONG       ulLibraryNameTotalSize;
    __out ULONG       ulLibraryNameNeededSize;
    __out CHAR        szLibraryName[1];

} NDIS_TAPI_CONFIG_DIALOG, *PNDIS_TAPI_CONFIG_DIALOG;


typedef struct _NDIS_TAPI_DEV_SPECIFIC
{
    __in    ULONG       ulRequestID;
    __in    HDRV_LINE   hdLine;
    __in    ULONG       ulAddressID;
    __in    HDRV_CALL   hdCall;
    __inout ULONG       ulParamsSize;
    __inout UCHAR       Params[1];

} NDIS_TAPI_DEV_SPECIFIC, *PNDIS_TAPI_DEV_SPECIFIC;


typedef struct _NDIS_TAPI_DIAL
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulDestAddressSize;
    __in  CHAR        szDestAddress[1];

} NDIS_TAPI_DIAL, *PNDIS_TAPI_DIAL;


typedef struct _NDIS_TAPI_DROP
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulUserUserInfoSize;
    __in  UCHAR       UserUserInfo[1];

} NDIS_TAPI_DROP, *PNDIS_TAPI_DROP;


typedef struct _NDIS_TAPI_GET_ADDRESS_CAPS
{
    __in  ULONG               ulRequestID;
    __in  ULONG               ulDeviceID;
    __in  ULONG               ulAddressID;
    __in  ULONG               ulExtVersion;
    __out LINE_ADDRESS_CAPS   LineAddressCaps;

} NDIS_TAPI_GET_ADDRESS_CAPS, *PNDIS_TAPI_GET_ADDRESS_CAPS;


typedef struct _NDIS_TAPI_GET_ADDRESS_ID
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __out ULONG       ulAddressID;
    __in  ULONG       ulAddressMode;
    __in  ULONG       ulAddressSize;
    __in  CHAR        szAddress[1];

} NDIS_TAPI_GET_ADDRESS_ID, *PNDIS_TAPI_GET_ADDRESS_ID;


typedef struct _NDIS_TAPI_GET_ADDRESS_STATUS
{
    __in  ULONG               ulRequestID;
    __in  HDRV_LINE           hdLine;
    __in  ULONG               ulAddressID;
    __out LINE_ADDRESS_STATUS LineAddressStatus;

} NDIS_TAPI_GET_ADDRESS_STATUS, *PNDIS_TAPI_GET_ADDRESS_STATUS;


typedef struct _NDIS_TAPI_GET_CALL_ADDRESS_ID
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __out ULONG       ulAddressID;

} NDIS_TAPI_GET_CALL_ADDRESS_ID, *PNDIS_TAPI_GET_CALL_ADDRESS_ID;


typedef struct _NDIS_TAPI_GET_CALL_INFO
{
    __in  ULONG           ulRequestID;
    __in  HDRV_CALL       hdCall;
    __out LINE_CALL_INFO  LineCallInfo;

} NDIS_TAPI_GET_CALL_INFO, *PNDIS_TAPI_GET_CALL_INFO;


typedef struct _NDIS_TAPI_GET_CALL_STATUS
{
    __in  ULONG               ulRequestID;
    __in  HDRV_CALL           hdCall;
    __out LINE_CALL_STATUS    LineCallStatus;

} NDIS_TAPI_GET_CALL_STATUS, *PNDIS_TAPI_GET_CALL_STATUS;


typedef struct _NDIS_TAPI_GET_DEV_CAPS
{
    __in  ULONG           ulRequestID;
    __in  ULONG           ulDeviceID;
    __in  ULONG           ulExtVersion;
    __out LINE_DEV_CAPS   LineDevCaps;

} NDIS_TAPI_GET_DEV_CAPS, *PNDIS_TAPI_GET_DEV_CAPS;


typedef struct _NDIS_TAPI_GET_DEV_CONFIG
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceID;
    __in  ULONG       ulDeviceClassSize;
    __in  ULONG       ulDeviceClassOffset;
    __out VAR_STRING  DeviceConfig;

} NDIS_TAPI_GET_DEV_CONFIG, *PNDIS_TAPI_GET_DEV_CONFIG;


typedef struct _NDIS_TAPI_GET_EXTENSION_ID
{
    __in  ULONG               ulRequestID;
    __in  ULONG               ulDeviceID;
    __out LINE_EXTENSION_ID   LineExtensionID;

} NDIS_TAPI_GET_EXTENSION_ID, *PNDIS_TAPI_GET_EXTENSION_ID;


typedef struct _NDIS_TAPI_GET_ID
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __in  ULONG       ulAddressID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulSelect;
    __in  ULONG       ulDeviceClassSize;
    __in  ULONG       ulDeviceClassOffset;
    __out VAR_STRING  DeviceID;

} NDIS_TAPI_GET_ID, *PNDIS_TAPI_GET_ID;


typedef struct _NDIS_TAPI_GET_LINE_DEV_STATUS
{
    __in  ULONG           ulRequestID;
    __in  HDRV_LINE       hdLine;
    __out LINE_DEV_STATUS LineDevStatus;

} NDIS_TAPI_GET_LINE_DEV_STATUS, *PNDIS_TAPI_GET_LINE_DEV_STATUS;


typedef struct _NDIS_TAPI_MAKE_CALL
{
    __in  ULONG               ulRequestID;
    __in  HDRV_LINE           hdLine;
    __in  HTAPI_CALL          htCall;
    __out HDRV_CALL           hdCall;
    __in  ULONG               ulDestAddressSize;
    __in  ULONG               ulDestAddressOffset;
    __in  BOOLEAN             bUseDefaultLineCallParams;
    __in  LINE_CALL_PARAMS    LineCallParams;

} NDIS_TAPI_MAKE_CALL, *PNDIS_TAPI_MAKE_CALL;


typedef struct _NDIS_TAPI_NEGOTIATE_EXT_VERSION
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceID;
    __in  ULONG       ulLowVersion;
    __in  ULONG       ulHighVersion;
    __out ULONG       ulExtVersion;

} NDIS_TAPI_NEGOTIATE_EXT_VERSION, *PNDIS_TAPI_NEGOTIATE_EXT_VERSION;


typedef struct _NDIS_TAPI_OPEN
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceID;
    __in  HTAPI_LINE  htLine;
    __out HDRV_LINE   hdLine;

} NDIS_TAPI_OPEN, *PNDIS_TAPI_OPEN;


typedef struct _NDIS_TAPI_PROVIDER_INITIALIZE
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceIDBase;
    __out ULONG       ulNumLineDevs;
    __out ULONG_PTR   ulProviderID;

} NDIS_TAPI_PROVIDER_INITIALIZE, *PNDIS_TAPI_PROVIDER_INITIALIZE;


typedef struct _NDIS_TAPI_PROVIDER_SHUTDOWN
{
    __in  ULONG       ulRequestID;

} NDIS_TAPI_PROVIDER_SHUTDOWN, *PNDIS_TAPI_PROVIDER_SHUTDOWN;


typedef struct _NDIS_TAPI_SECURE_CALL
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;

} NDIS_TAPI_SECURE_CALL, *PNDIS_TAPI_SECURE_CALL;


typedef struct _NDIS_TAPI_SELECT_EXT_VERSION
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __in  ULONG       ulExtVersion;

} NDIS_TAPI_SELECT_EXT_VERSION, *PNDIS_TAPI_SELECT_EXT_VERSION;


typedef struct _NDIS_TAPI_SEND_USER_USER_INFO
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulUserUserInfoSize;
    __in  UCHAR       UserUserInfo[1];

} NDIS_TAPI_SEND_USER_USER_INFO, *PNDIS_TAPI_SEND_USER_USER_INFO;


typedef struct _NDIS_TAPI_SET_APP_SPECIFIC
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulAppSpecific;

} NDIS_TAPI_SET_APP_SPECIFIC, *PNDIS_TAPI_SET_APP_SPECIFIC;


typedef struct _NDIS_TAPI_SET_CALL_PARAMS
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulBearerMode;
    __in  ULONG       ulMinRate;
    __in  ULONG       ulMaxRate;
    __in  BOOLEAN     bSetLineDialParams;
    __in  LINE_DIAL_PARAMS    LineDialParams;

} NDIS_TAPI_SET_CALL_PARAMS, *PNDIS_TAPI_SET_CALL_PARAMS;


typedef struct _NDIS_TAPI_SET_DEFAULT_MEDIA_DETECTION
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __in  ULONG       ulMediaModes;

} NDIS_TAPI_SET_DEFAULT_MEDIA_DETECTION,
*PNDIS_TAPI_SET_DEFAULT_MEDIA_DETECTION;


typedef struct _NDIS_TAPI_SET_DEV_CONFIG
{
    __in  ULONG       ulRequestID;
    __in  ULONG       ulDeviceID;
    __in  ULONG       ulDeviceClassSize;
    __in  ULONG       ulDeviceClassOffset;
    __in  ULONG       ulDeviceConfigSize;
    __in  UCHAR       DeviceConfig[1];

} NDIS_TAPI_SET_DEV_CONFIG, *PNDIS_TAPI_SET_DEV_CONFIG;


typedef struct _NDIS_TAPI_SET_MEDIA_MODE
{
    __in  ULONG       ulRequestID;
    __in  HDRV_CALL   hdCall;
    __in  ULONG       ulMediaMode;

} NDIS_TAPI_SET_MEDIA_MODE, *PNDIS_TAPI_SET_MEDIA_MODE;


typedef struct _NDIS_TAPI_SET_STATUS_MESSAGES
{
    __in  ULONG       ulRequestID;
    __in  HDRV_LINE   hdLine;
    __in  ULONG       ulLineStates;
    __in  ULONG       ulAddressStates;

} NDIS_TAPI_SET_STATUS_MESSAGES, *PNDIS_TAPI_SET_STATUS_MESSAGES;


typedef struct _NDIS_TAPI_EVENT
{
    __in  HTAPI_LINE  htLine;
    __in  HTAPI_CALL  htCall;
    __in  ULONG       ulMsg;
    __in  ULONG_PTR   ulParam1;
    __in  ULONG_PTR   ulParam2;
    __in  ULONG_PTR   ulParam3;

} NDIS_TAPI_EVENT, *PNDIS_TAPI_EVENT;

typedef struct _NDISTAPI_CHARACTERISTICS {
	PVOID	RequestProc;
	GUID	Guid;
	NDIS_WAN_MEDIUM_SUBTYPE	MediaType;
} NDISTAPI_CHARACTERISTICS, *PNDISTAPI_CHARACTERISTICS;


typedef struct _NDIS_TAPI_GATHER_DIGITS
{
    __in  ULONG       ulRequestID;
	IN 	HDRV_CALL   hdCall;
	IN	ULONG		ulEndToEndID;
	IN	ULONG		ulDigitModes;
	__field_ecount(ulNumDigitsNeeded) IN	LPWSTR		lpsOrigDigitsBuffer;
	IN	ULONG		ulDigitsBufferOffset;
	IN	ULONG		ulNumDigitsNeeded;
	OUT	ULONG		ulNumDigitsRead;
	OUT	ULONG		ulTickCount;
	OUT	ULONG		ulTerminationReason;
	IN 	ULONG		ulTerminationDigitsMask;
	IN 	ULONG		ulFirstDigitTimeout;
	IN	ULONG		ulInterDigitTimeout;
} NDIS_TAPI_GATHER_DIGITS, *PNDIS_TAPI_GATHER_DIGITS;

typedef struct _NDIS_TAPI_MONITOR_DIGITS
{
	IN	HDRV_CALL	hdCall;
	IN	ULONG		ulDigitModes;
} NDIS_TAPI_MONITOR_DIGITS, *PNDIS_TAPI_MONITOR_DIGITS;

#define CO_TAPI_VERSION                         NDIS_TAPI_CURRENT_VERSION

//
//  The CO_TAPI structures below are meant for TAPI support
//  over CONDIS Call Managers and Miniport Call Managers.
//

//  Structure associated with OID_CO_TAPI_CM_CAPS
//
typedef struct _CO_TAPI_CM_CAPS
{
    __out ULONG                 ulCoTapiVersion;
    __out ULONG                 ulNumLines;
    __out ULONG                 ulFlags;

} CO_TAPI_CM_CAPS, *PCO_TAPI_CM_CAPS;

//
//  Bit definitions for Flags in CO_TAPI_CM_CAPS
//
#define CO_TAPI_FLAG_PER_LINE_CAPS              0x00000001

//
//  Structure associated with OID_CO_TAPI_LINE_CAPS.
//
typedef struct _CO_TAPI_LINE_CAPS
{
    __in  ULONG                 ulLineID;
    __out ULONG                 ulFlags;
    __out LINE_DEV_CAPS         LineDevCaps;

} CO_TAPI_LINE_CAPS, *PCO_TAPI_LINE_CAPS;

//
//  Bit definitions for Flags in CO_TAPI_LINE_CAPS
//
#define CO_TAPI_FLAG_PER_ADDRESS_CAPS           0x00000001

//
//  Structure associated with OID_CO_TAPI_ADDRESS_CAPS.
//
typedef struct _CO_TAPI_ADDRESS_CAPS
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __out ULONG                 ulFlags;
    __out LINE_ADDRESS_CAPS     LineAddressCaps;

} CO_TAPI_ADDRESS_CAPS, *PCO_TAPI_ADDRESS_CAPS;


//
//  Special values for Line and Address ID fields:
//
#define CO_TAPI_LINE_ID_UNSPECIFIED             0xFFFFFFFF
#define CO_TAPI_ADDRESS_ID_UNSPECIFIED          0xFFFFFFFF

//
//  Structure associated with OID_CO_TAPI_TRANSLATE_TAPI_CALLPARAMS.
//
typedef struct _CO_TAPI_TRANSLATE_TAPI_CALLPARAMS
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __in  ULONG                 ulFlags;         // see below
    __in  NDIS_VAR_DATA_DESC    DestAddress;
    __in  NDIS_VAR_DATA_DESC    LineCallParams;  // LINE_CALL_PARAMS
    __out NDIS_VAR_DATA_DESC    NdisCallParams;  // CO_CALL_PARAMETERS

} CO_TAPI_TRANSLATE_TAPI_CALLPARAMS, *PCO_TAPI_TRANSLATE_TAPI_CALLPARAMS;

//
//  Bit definitions for Flags in CO_TAPI_TRANSLATE_TAPI_CALLPARAMS
//  and CO_TAPI_TRANSLATE_NDIS_CALLPARAMS.
//
#define CO_TAPI_FLAG_OUTGOING_CALL              0x00000001
#define CO_TAPI_FLAG_INCOMING_CALL              0x00000002
#define CO_TAPI_FLAG_USE_DEFAULT_CALLPARAMS		0x00000004


//
//  Structure associated with OID_CO_TAPI_TRANSLATE_NDIS_CALLPARAMS.
//
typedef struct _CO_TAPI_TRANSLATE_NDIS_CALLPARAMS
{
    __in  ULONG                 ulFlags;         // see above
    __in  NDIS_VAR_DATA_DESC    NdisCallParams;  // CO_CALL_PARAMETERS
    __out NDIS_VAR_DATA_DESC    LineCallInfo;    // LINE_CALL_INFO

} CO_TAPI_TRANSLATE_NDIS_CALLPARAMS, *PCO_TAPI_TRANSLATE_NDIS_CALLPARAMS;


//
//  Structure associated with OID_CO_TAPI_TRANSLATE_SAP.
//
typedef struct _CO_TAPI_TRANSLATE_SAP
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __in  ULONG                 ulMediaModes;
    __in  ULONG                 Reserved;
    __out ULONG                 NumberOfSaps;
    __out NDIS_VAR_DATA_DESC    NdisSapParams[1];   // CO_SAP

} CO_TAPI_TRANSLATE_SAP, *PCO_TAPI_TRANSLATE_SAP;


//
//  Structure associated with OID_CO_TAPI_GET_CALL_DIAGNOSTICS.
//
typedef struct _CO_TAPI_CALL_DIAGNOSTICS
{
    __out ULONG                 ulOrigin;
    __out ULONG                 ulReason;
    __out NDIS_VAR_DATA_DESC    DiagInfo;

} CO_TAPI_CALL_DIAGNOSTICS, *PCO_TAPI_CALL_DIAGNOSTICS;


//
//  Structure used in the Media-specific part of CO_CALL_PARAMETERS
//  for an outgoing call for the CO_ADDRESS_FAMILY_TAPI address family.
//  This is used in NdisClMakeCall/Ndis[M]CmActivateVc, and
//  completion routines.
//
//  This overlays:
//     CO_CALL_PARAMETERS.MediaParameters->MediaSpecific.Parameters[]
//
typedef struct _CO_AF_TAPI_MAKE_CALL_PARAMETERS
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __in  ULONG                 ulFlags;         // see CO_TAPI_TRANSLATE_TAPI_CALLPARAMS
    __in  NDIS_VAR_DATA_DESC    DestAddress;
    __in  NDIS_VAR_DATA_DESC    LineCallParams;  // LINE_CALL_PARAMS

} CO_AF_TAPI_MAKE_CALL_PARAMETERS, *PCO_AF_TAPI_MAKE_CALL_PARAMETERS;



//
//  Structure used in the Media-specific part of CO_CALL_PARAMETERS
//  for an incoming call for the CO_ADDRESS_FAMILY_TAPI address family.
//  This is used in Ndis[M]CmDispatchIncomingCall/Ndis[M]CmActivateVc
//  and completion routines.
//
//  This overlays:
//     CO_CALL_PARAMETERS.MediaParameters->MediaSpecific.Parameters[]
//
typedef struct _CO_AF_TAPI_INCOMING_CALL_PARAMETERS
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __in  ULONG                 ulFlags;         // see CO_TAPI_TRANSLATE_TAPI_CALLPARAMS
    __in  NDIS_VAR_DATA_DESC    LineCallInfo;    // LINE_CALL_INFO

} CO_AF_TAPI_INCOMING_CALL_PARAMETERS, *PCO_AF_TAPI_INCOMING_CALL_PARAMETERS;



//
//  Value of SapType in CO_SAP for a Service Access Point on the
//  CO_ADDRESS_FAMILY_TAPI address family.
//
#define AF_TAPI_SAP_TYPE      0x00008000

//
//  Structure used to convey TAPI-style SAP information in the NDIS CO_SAP
//  structure.
//
//  This overlays:
//     CO_SAP.Sap[]
//
typedef struct _CO_AF_TAPI_SAP
{
    __in  ULONG                 ulLineID;
    __in  ULONG                 ulAddressID;
    __in  ULONG                 ulMediaModes;

} CO_AF_TAPI_SAP, *PCO_AF_TAPI_SAP;



#endif // _NDIS_TAPI_


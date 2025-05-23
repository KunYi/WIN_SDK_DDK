/*
	Copyright (c) Microsoft Corporation.  All rights reserved.
*/

/*
    This file declares the driver entry points.
*/
#include <ndis.h>

extern DRIVER_INITIALIZE fun_DriverEntry;

#ifdef fun_MINIPORT_RESET
extern MINIPORT_RESET fun_MINIPORT_RESET;
#endif

#ifdef fun_MINIPORT_PAUSE
extern MINIPORT_PAUSE fun_MINIPORT_PAUSE;
#endif

#ifdef fun_MINIPORT_RESTART
extern MINIPORT_RESTART fun_MINIPORT_RESTART;
#endif

#ifdef fun_MINIPORT_INITIALIZE
extern MINIPORT_INITIALIZE fun_MINIPORT_INITIALIZE;
#endif

#ifdef fun_MINIPORT_HALT
extern MINIPORT_HALT fun_MINIPORT_HALT;
#endif

#ifdef fun_MINIPORT_OID_REQUEST
extern MINIPORT_OID_REQUEST fun_MINIPORT_OID_REQUEST;
#endif

#ifdef fun_MINIPORT_SHUTDOWN
extern MINIPORT_SHUTDOWN fun_MINIPORT_SHUTDOWN;
#endif

#ifdef fun_MINIPORT_DEVICE_PNP_EVENT_NOTIFY
extern MINIPORT_DEVICE_PNP_EVENT_NOTIFY fun_MINIPORT_DEVICE_PNP_EVENT_NOTIFY;
#endif

#ifdef fun_MINIPORT_CANCEL_SEND
extern MINIPORT_CANCEL_SEND fun_MINIPORT_CANCEL_SEND;
#endif

#ifdef fun_MINIPORT_CHECK_FOR_HANG
extern MINIPORT_CHECK_FOR_HANG fun_MINIPORT_CHECK_FOR_HANG;
#endif

#ifdef fun_MINIPORT_CANCEL_OID_REQUEST
extern MINIPORT_CANCEL_OID_REQUEST fun_MINIPORT_CANCEL_OID_REQUEST;
#endif

#ifdef fun_MINIPORT_SEND_NET_BUFFER_LISTS
extern MINIPORT_SEND_NET_BUFFER_LISTS fun_MINIPORT_SEND_NET_BUFFER_LISTS;
#endif

#ifdef fun_MINIPORT_RETURN_NET_BUFFER_LISTS
extern MINIPORT_RETURN_NET_BUFFER_LISTS fun_MINIPORT_RETURN_NET_BUFFER_LISTS;
#endif

#ifdef fun_MINIPORT_UNLOAD
extern MINIPORT_UNLOAD fun_MINIPORT_UNLOAD;
#endif

#ifdef fun_MINIPORT_SET_OPTIONS
extern MINIPORT_SET_OPTIONS fun_MINIPORT_SET_OPTIONS;
#endif

#ifdef fun_MINIPORT_PROCESS_SG_LIST
extern MINIPORT_PROCESS_SG_LIST fun_MINIPORT_PROCESS_SG_LIST;
#endif

#ifdef fun_MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE
extern MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE fun_MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE;
#endif



#ifdef fun_MINIPORT_ADD_DEVICE
extern MINIPORT_ADD_DEVICE fun_MINIPORT_ADD_DEVICE;
#endif

#ifdef fun_MINIPORT_START_DEVICE
extern MINIPORT_START_DEVICE fun_MINIPORT_START_DEVICE;
#endif

#ifdef fun_MINIPORT_REMOVE_DEVICE
extern MINIPORT_REMOVE_DEVICE fun_MINIPORT_REMOVE_DEVICE;
#endif

#ifdef fun_MINIPORT_FILTER_RESOURCE_REQUIREMENTS
extern MINIPORT_FILTER_RESOURCE_REQUIREMENTS fun_MINIPORT_FILTER_RESOURCE_REQUIREMENTS;
#endif




#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_1
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_1; /*multiple*/
#endif

#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_2
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_2; /*multiple*/
#endif

#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_3
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_3; /*multiple*/
#endif

#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_4
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_4; /*multiple*/
#endif

#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_5
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_5; /*multiple*/
#endif

#ifdef fun_NDIS_IO_WORKITEM_FUNCTION_6
extern NDIS_IO_WORKITEM_FUNCTION fun_NDIS_IO_WORKITEM_FUNCTION_6; /*multiple*/
#endif


#ifdef fun_MINIPORT_ISR_1
extern MINIPORT_ISR fun_MINIPORT_ISR_1; /*multiple*/
#endif

#ifdef fun_MINIPORT_ISR_2
extern MINIPORT_ISR fun_MINIPORT_ISR_2; /*multiple*/
#endif

#ifdef fun_MINIPORT_ISR_3
extern MINIPORT_ISR fun_MINIPORT_ISR_3; /*multiple*/
#endif

#ifdef fun_MINIPORT_ISR_4
extern MINIPORT_ISR fun_MINIPORT_ISR_4; /*multiple*/
#endif

#ifdef fun_MINIPORT_ISR_5
extern MINIPORT_ISR fun_MINIPORT_ISR_5; /*multiple*/
#endif

#ifdef fun_MINIPORT_ISR_6
extern MINIPORT_ISR fun_MINIPORT_ISR_6; /*multiple*/
#endif


#ifdef fun_MINIPORT_INTERRUPT_DPC_1
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_INTERRUPT_DPC_2
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_INTERRUPT_DPC_3
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_INTERRUPT_DPC_4
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_INTERRUPT_DPC_5
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_INTERRUPT_DPC_6
extern MINIPORT_INTERRUPT_DPC fun_MINIPORT_INTERRUPT_DPC_6;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_1
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_2
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_3
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_4
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_5
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_INTERRUPT_6
extern MINIPORT_ENABLE_INTERRUPT fun_MINIPORT_ENABLE_INTERRUPT_6;  /*multiple*/
#endif


#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_1
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_2
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_3
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_4
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_5
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_INTERRUPT_6
extern MINIPORT_SYNCHRONIZE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_INTERRUPT_6;  /*multiple*/
#endif


#ifdef fun_MINIPORT_DISABLE_INTERRUPT_1
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_INTERRUPT_2
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_INTERRUPT_3
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_INTERRUPT_4
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_INTERRUPT_5
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_INTERRUPT_6
extern MINIPORT_DISABLE_INTERRUPT fun_MINIPORT_DISABLE_INTERRUPT_6;  /*multiple*/
#endif


#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_1
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_1; /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_2
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_2; /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_3
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_3; /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_4
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_4; /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_5
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_5; /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_6
extern MINIPORT_MESSAGE_INTERRUPT fun_MINIPORT_MESSAGE_INTERRUPT_6; /*multiple*/
#endif


#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_1
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_2
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_3
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_4
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_5
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_MESSAGE_INTERRUPT_DPC_6
extern MINIPORT_MESSAGE_INTERRUPT_DPC fun_MINIPORT_MESSAGE_INTERRUPT_DPC_6;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_1
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_2
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_3
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_4
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_5
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_6
extern MINIPORT_ENABLE_MESSAGE_INTERRUPT fun_MINIPORT_ENABLE_MESSAGE_INTERRUPT_6;  /*multiple*/
#endif


#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_1
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_2
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_3
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_4
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_5
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_6
extern MINIPORT_DISABLE_MESSAGE_INTERRUPT fun_MINIPORT_DISABLE_MESSAGE_INTERRUPT_6;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_1
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_1;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_2
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_2;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_3
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_3;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_4
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_4;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_5
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_5;  /*multiple*/
#endif

#ifdef fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_6
extern MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT fun_MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT_6;  /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_1
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_1;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_2
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_2;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_3
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_3;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_4
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_4;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_5
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_5;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_6
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_6;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_7
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_7;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_8
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_8;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_9
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_9;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_10
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_10;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_11
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_11;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_12
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_12;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_13
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_13;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_14
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_14;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_15
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_15;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_16
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_16;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_17
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_17;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_18
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_18;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_19
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_19;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_20
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_20;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_21
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_21;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_22
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_22;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_23
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_23;   /*multiple*/
#endif

#ifdef fun_NDIS_TIMER_FUNCTION_24
extern NDIS_TIMER_FUNCTION fun_NDIS_TIMER_FUNCTION_24;   /*multiple*/
#endif


#ifdef fun_MINIPORT_DIRECT_OID_REQUEST
extern MINIPORT_DIRECT_OID_REQUEST fun_MINIPORT_DIRECT_OID_REQUEST;
#endif

#ifdef fun_MINIPORT_CANCEL_DIRECT_OID_REQUEST
extern MINIPORT_CANCEL_DIRECT_OID_REQUEST fun_MINIPORT_CANCEL_DIRECT_OID_REQUEST;
#endif

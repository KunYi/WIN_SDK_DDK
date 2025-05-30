//---------------------------------------------------------------------------
//
//  Module:   acnfgmgr.c
//
//  Description:
//     Config manager notification handler for AuraVision VxP500
//---------------------------------------------------------------------------
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) 1994 - 1995 Microsoft Corporation.	All Rights Reserved.
//
//---------------------------------------------------------------------------

#define  WANTVXDWRAPS

#include <basedef.h>
#include <vmm.h>
#include <vmmreg.h>
#include <vxdwraps.h>
#include <configmg.h>
#include <vmmreg.h>
#include <debug.h>

#include "acnfgmgr.h"
               
#undef CURSEG               
#define  CURSEG()                   PCODE

#define  CM_Get_Alloc_Log_Conf      PREPEND(_CONFIGMG_Get_Alloc_Log_Conf)
#define  CM_Run_Detection           PREPEND(_CONFIGMG_Run_Detection)

#ifdef  DEBUG
#define DPF(x) Out_Debug_String(x)
#else
#define DPF(x)
#endif

#pragma VxD_PAGEABLE_CODE_SEG
#pragma VxD_PAGEABLE_DATA_SEG

//--------------------------------------------------------------------------
//  
//  CONFIGRET AVVXP500_Config_Handler
//  
//  Description:
//  
//  
//  Parameters:
//      CONFIGFUNC cfFuncName
//  
//      SUBCONFIGFUNC scfSubFuncName
//  
//      DEVNODE dn
//  
//      DWORD dwRefData
//  
//      ULONG ulFlags
//  
//  Return (CONFIGRET):
//  
//  History:   Date       Author      Comment
//              2/25/94   BryanW      
//  
//--------------------------------------------------------------------------

CONFIGRET AVVXP500_Config_Handler
(
    CONFIGFUNC      cfFuncName,
    SUBCONFIGFUNC   scfSubFuncName,
    DEVNODE         dn,
    DWORD           dwRefData,
    ULONG           ulFlags
)
{
   //
   // Switch the function (aka command)
   //

   DPF( "AVVXP500: Config_Handler\r\n" ) ;

   switch (cfFuncName)
   {

      case CONFIG_FILTER:
         //
         // This command is sent to the devnode and all it's parents
         // to give them a chance to delete logical configurations
         // from the filtered configuration list.  A parent would
         // remove a configuration from the filtered list if it cannot
         // provide that configuration.
         //

         return CR_SUCCESS ;
    
      case CONFIG_START:
         switch (scfSubFuncName)
         {
            case CONFIG_START_FIRST_START:
            case CONFIG_START_DYNAMIC_START:
            {
               //
               // This command is sent to instruct the driver that
               // it can start using the resources that have been
               // allocated to it.   This is the meat of this
               // DriverConfigMan.
               //
               // We get our resource allocation by calling the
               // configuration manager (CM) using the devnode that
               // was passed to us.
               //
               // If all has gone well, we should not have been given
               // a resource allocation that we can't use.   Ideally
               // this command should always succeed.  However, every
               // now and then life throws you a curve ball, so we
               // should still verify that we are happy with the
               // resources we have been given.
               //
               // If we receive multiple _STARTs for multiple devodes,
               // then there are multiple taget devices for us to drive.
               // How we handle this is highly dependent upon the driver.
               // This particular driver can only drive one target device.
               //

               CMCONFIG    ccb ;
               CONFIGRET   cr ;
               WORD        wBaseVXP500 ;
               WORD        wIRQ ;
               DWORD       dwMemBase;

               //
               // Get our resource allocation from CM.  if
               // this fails, we have no choice but to fail
               // the CONFIG_START.  We'll return the same
               // error that the CM_Get_Alloc_Config returned.
               //
               //

               if (CR_SUCCESS != 
                     (cr = CM_Get_Alloc_Log_Conf( &ccb, dn, 0 )))
                  return cr ;

               //
               // Extract the information of interest from the config buffer
               // that we got from CM_Get_Alloc_Config.
               //

               // need index and data port

               if ((ccb.wNumIOPorts != 1) ||
                   (ccb.wIOPortLength[ 0 ] != 2)) 
               {
                  DPF( "AVVXP500: Invalid config (no I/O resource).\r\n" ) ;
                  return CR_FAILURE ;
               }
               
               wBaseVXP500 = ccb.wIOPortBase[ 0 ] ;

               if (ccb.wNumIRQs != 1)
               {
                  DPF( "AVVXP500: Invalid config (no IRQ resource).\r\n" ) ;
                  return CR_FAILURE ;
               }

               wIRQ = ccb.bIRQRegisters[ 0 ] ;

               if ((ccb.wNumMemWindows != 1) ||
                   (ccb.dMemLength[ 0 ] != 0x8000))
               {
                  DPF( "AVVXP500: Invalid config (no mem resource).\r\n" ) ;
                  return CR_FAILURE ;
               }

               dwMemBase = ccb.dMemBase[ 0 ] ;

               //
               // OK, now do whatever else is necessary to put this
               // configuration into effect.
               //

               cr = AVVXP500_Set_Config( dn, wBaseVXP500, wIRQ,
                                         dwMemBase ) ;

               return cr ;
            }

            default:
               return CR_DEFAULT ;
         }

      case CONFIG_TEST:
       
         //
         // This command is sent to query the driver whether it can
         // change configuration, stop using the resources, or
         // handle a remove.  The query is specified by the sub func.
         //

         switch (scfSubFuncName)
         {
            case CONFIG_TEST_CAN_STOP:

               //
               // This command asks: Can we stop
               // using our resources?  If we're making noise,
               // we'd rather not stop.
               //

               return (AVVXP500_IsOwned( dn ) ? CR_FAILURE : CR_SUCCESS) ;

            case CONFIG_TEST_CAN_REMOVE:

               //
               // This command asks: Is it OK for CM to remove
               // the devnode?  This implies that the associated
               // device is also going to disappear (or has
               // already disappeared).
               //
          
               return (AVVXP500_IsOwned( dn ) ? CR_FAILURE : CR_SUCCESS) ;

            default:
               return CR_DEFAULT ;
         }

      case CONFIG_STOP:
         switch (scfSubFuncName)
         {

            /// if stopped due to CONFIG_START failure, should
            /// perform cleanup here instead of CONFIG_STOP...

            case CONFIG_STOP_DYNAMIC_STOP:

               //
               // This command indicates that we should stop
               // using the resources that were allocated to us.
               //

               AVVXP500_Remove_Config( dn ) ;
               return CR_SUCCESS ;

            default:
               return CR_DEFAULT ;
         }
          
      case CONFIG_REMOVE:

         //
         // This command is sent to a devnode and all it's parents when
         // when the devnode is being removed from the hardware tree.
         // Deallocate any per devnode instance data and take whatever
         // other measures are necessary to stop using that devnode and
         // the associated hardware.   The command is essentially saying
         // that the hardware no longer exists in the system.
         //

         AVVXP500_Remove_Config( dn ) ;
         return CR_SUCCESS ;
       
      default:
         return CR_DEFAULT ;
   }

} // AVVXP500_Config_Handler()

//---------------------------------------------------------------------------
//  End of File: cnfgmgr.c
//---------------------------------------------------------------------------

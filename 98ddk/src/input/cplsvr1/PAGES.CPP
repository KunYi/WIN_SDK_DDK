//===========================================================================
//
// CPLSVR1 property pages implementation.
//
// Functions:
//  CPLSVR1_Page1_DlgProc()
//  CPLSVR1_Page2_DlgProc()
//  CPLSVR1_Page3_DlgProc()
//  CPLSVR1_Page4_DlgProc()
//  InitDInput()
//  EnumDeviceObjectsProc()
//  EnumEffectsProc()
//  DisplayAxisList()
//  DisplayButtonList()
//  DisplayPOVList()
//  DisplayEffectList()
//  DisplayJoystickState()
//
//===========================================================================

//===========================================================================
// (C) Copyright 1998 Microsoft Corp.  All rights reserved.
//
// You have a royalty-free right to use, modify, reproduce and
// distribute the Sample Files (and/or any modified version) in
// any way you find useful, provided that you agree that
// Microsoft has no warranty obligations or liability for any
// Sample Application Files which are modified.
//===========================================================================

#include "cplsvr1.h"
#include "pages.h"
#include "dicputil.h"
#include "resrc1.h"
#include <prsht.h>

LPTSTR  lptszBuf;

//===========================================================================
// CPLSVR1_Page1_DlgProc
//
// Callback proceedure CPLSVR1 property page #1 (General).
//
// Parameters:
//  HWND    hWnd    - handle to dialog window
//  UINT    uMsg    - dialog message
//  WPARAM  wParam  - message specific data
//  LPARAM  lParam  - message specific data
//
// Returns: BOOL
//
//===========================================================================
BOOL CALLBACK CPLSVR1_Page1_DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
   CDIGameCntrlPropSheet_X *pdiCpl = (CDIGameCntrlPropSheet_X*)GetWindowLong(hWnd, DWL_USER);

   switch(uMsg)
   {
	   case WM_INITDIALOG:
		   {
			// perform any required initialization... 

			// get ptr to our object
			pdiCpl = (CDIGameCntrlPropSheet_X*)((LPPROPSHEETPAGE)lParam)->lParam;
         
			// Save our pointer so we can access it later
			SetWindowLong(hWnd, DWL_USER, (LPARAM)pdiCpl);

			// initialize DirectInput
			if (FAILED(InitDInput(GetParent(hWnd), pdiCpl)))
         {
#ifdef _DEBUG
            OutputDebugString(TEXT("CPLSvr1 Page 1 - InitDInput failed!\n"));
#endif //_DEBUG
            return TRUE;
         }

		   LPDIRECTINPUTDEVICE2    pdiDevice2  = NULL;

	      // get the device object
		   pdiCpl->GetDevice(&pdiDevice2);

			// Allocate the memory for the Strings to be used below
			lptszBuf = new (TCHAR[STR_LEN_32]);
			assert (lptszBuf);

			// display the device details
			// axes
			if (FAILED(DisplayAxisList(hWnd, IDC_NUMAXES, IDC_AXISLIST, pdiDevice2)))
			{
				LoadString(ghInst, IDS_ERROR, lptszBuf, STR_LEN_32);
            SendDlgItemMessage(hWnd, IDC_AXISLIST, LB_ADDSTRING, 0, (LPARAM)lptszBuf);
			}

         // buttons
         if (FAILED(DisplayButtonList(hWnd, IDC_NUMBUTTONS, IDC_BUTTONLIST, pdiDevice2)))
         {
			   LoadString(ghInst, IDS_ERROR, lptszBuf, STR_LEN_32);
            SendDlgItemMessage(hWnd, IDC_AXISLIST, LB_ADDSTRING, 0, (LPARAM)lptszBuf);
         }

         // POVs
         if (FAILED(DisplayPOVList(hWnd, IDC_NUMPOVS, IDC_POVLIST, pdiDevice2)))
         {
			   LoadString(ghInst, IDS_ERROR, lptszBuf, STR_LEN_32);
            SendDlgItemMessage(hWnd, IDC_AXISLIST, LB_ADDSTRING, 0, (LPARAM)lptszBuf);
         }

			if (lptszBuf)
				delete[] (lptszBuf);
         }
			break;

      case WM_NOTIFY:
         // perform any WM_NOTIFY processing, but there is none...
         // return TRUE if you handled the notification (and have set
         // the result code in SetWindowLong(hWnd, DWL_MSGRESULT, lResult)
         // if you want to return a nonzero notify result)
         // or FALSE if you want default processing of the notification.
         return FALSE;
   }
    
   return FALSE;
} //*** end CPLSVR1_Page1_DlgProc()


//===========================================================================
// CPLSVR1_Page2_DlgProc
//
// Callback proceedure CPLSVR1 property page #2 (Advanced).
//
// Parameters:
//  HWND    hWnd    - handle to dialog window
//  UINT    uMsg    - dialog message
//  WPARAM  wParam  - message specific data
//  LPARAM  lParam  - message specific data
//
// Returns: BOOL
//
//===========================================================================
BOOL CALLBACK CPLSVR1_Page2_DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                                    LPARAM lParam)
{
   CDIGameCntrlPropSheet_X *pdiCpl = (CDIGameCntrlPropSheet_X*)GetWindowLong(hWnd, DWL_USER);

   switch(uMsg)
   {
      case WM_INITDIALOG:
         {
         // perform any required initialization... 

         // get ptr to our object
         pdiCpl = (CDIGameCntrlPropSheet_X*)((LPPROPSHEETPAGE)lParam)->lParam;

         // Save our pointer so we can access it later
         SetWindowLong(hWnd, DWL_USER, (LPARAM)pdiCpl);

         // initialize DirectInput
         if (FAILED(InitDInput(GetParent(hWnd), pdiCpl)))
         {
#ifdef _DEBUG
            OutputDebugString(TEXT("CPLSvr1 Page 2 - InitDInput failed!\n"));
#endif //_DEBUG
            return TRUE;
         }
         
         LPDIRECTINPUTJOYCONFIG  pdiJoyCfg;

         // get the joyconfig object
         pdiCpl->GetJoyConfig(&pdiJoyCfg);
			assert (pdiJoyCfg);

			// Allocate the memory for the Strings to be used below
			lptszBuf = new (TCHAR[MAX_PATH]);
			assert (lptszBuf);

         // display joystick display name
         DIUtilGetJoystickDisplayName(pdiCpl->GetID(), pdiJoyCfg, lptszBuf, MAX_PATH);
         SetDlgItemText(hWnd, IDC_DISPNAME, lptszBuf);

         // display joystick type name
         DIUtilGetJoystickTypeName(pdiCpl->GetID(), pdiJoyCfg, lptszBuf, MAX_PATH);
         SetDlgItemText(hWnd, IDC_TYPENAME, lptszBuf);

         // display joystick callout
         DIUtilGetJoystickCallout(pdiCpl->GetID(), pdiJoyCfg, lptszBuf, MAX_PATH);
         SetDlgItemText(hWnd, IDC_CALLOUT, lptszBuf);

         CLSID clsid;

         // display joystick config clsid
         DIUtilGetJoystickConfigCLSID(pdiCpl->GetID(), pdiJoyCfg, &clsid);
         wsprintf(lptszBuf, TEXT("{%08X-%04X-%04X-%02X%02X%02X%02X%02X%02X%02X%02X}"),
			         clsid.Data1, clsid.Data2, clsid.Data3,
			         clsid.Data4[0], clsid.Data4[1], clsid.Data4[2], clsid.Data4[3],
			         clsid.Data4[4], clsid.Data4[5], clsid.Data4[6], clsid.Data4[7]);
         SetDlgItemText(hWnd, IDC_CLSID, lptszBuf);

			if (lptszBuf)
				delete[] (lptszBuf);
         }                
         break;

      case WM_NOTIFY:
         // perform any WM_NOTIFY processing, but there is none...
         // return TRUE if you handled the notification (and have set
         // the result code in SetWindowLong(hWnd, DWL_MSGRESULT, lResult)
         // if you want to return a nonzero notify result)
         // or FALSE if you want default processing of the notification.
         return FALSE;
    }

    return FALSE;
} //*** end CPLSVR1_Page2_DlgProc()


//===========================================================================
// CPLSVR1_Page3_DlgProc
//
// Callback proceedure CPLSVR1 property page #3 (Effects).
//
// Parameters:
//  HWND    hWnd    - handle to dialog window
//  UINT    uMsg    - dialog message
//  WPARAM  wParam  - message specific data
//  LPARAM  lParam  - message specific data
//
// Returns: BOOL
//
//===========================================================================
BOOL CALLBACK CPLSVR1_Page3_DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                                    LPARAM lParam)
{
   CDIGameCntrlPropSheet_X *pdiCpl = (CDIGameCntrlPropSheet_X*)GetWindowLong(hWnd, DWL_USER);

   switch(uMsg)
   {
      case WM_INITDIALOG:
         {
         // perform any required initialization... 

         // get ptr to our object
         pdiCpl = (CDIGameCntrlPropSheet_X*)((LPPROPSHEETPAGE)lParam)->lParam;
         
         // Save our pointer so we can access it later
         SetWindowLong(hWnd, DWL_USER, (LPARAM)pdiCpl);

         // initialize DirectInput
         if (FAILED(InitDInput(GetParent(hWnd), pdiCpl)))
         {
#ifdef _DEBUG
             OutputDebugString(TEXT("CPLSvr1 Page 3 - InitDInput failed!\n"));
#endif //_DEBUG
             return TRUE;
         }

         LPDIRECTINPUTDEVICE2    pdiDevice2;

         // get the device object
         pdiCpl->GetDevice(&pdiDevice2);

			// Allocate the memory for the Strings to be used below
			lptszBuf = new (TCHAR[STR_LEN_64]);
			assert (lptszBuf);

         // display the supported effects
         if (FAILED(DisplayEffectList(hWnd, IDC_EFFECTLIST, pdiDevice2)))
         {
             LoadString(ghInst, IDS_ERROR, lptszBuf, STR_LEN_64);

             SendDlgItemMessage(hWnd, IDC_AXISLIST, LB_ADDSTRING, 0, (LPARAM)lptszBuf);
         }

         if (lptszBuf)
				delete[] (lptszBuf);
         }
         break;

      case WM_NOTIFY:
         // perform any WM_NOTIFY processing, but there is none...
         // return TRUE if you handled the notification (and have set
         // the result code in SetWindowLong(hWnd, DWL_MSGRESULT, lResult)
         // if you want to return a nonzero notify result)
         // or FALSE if you want default processing of the notification.
         return FALSE;
    }
    
    return FALSE;
} //*** end CPLSVR1_Page3_DlgProc()


//===========================================================================
// CPLSVR1_Page4_DlgProc
//
// Callback proceedure CPLSVR1 property page #4 (Test Data).
//
// Parameters:
//  HWND    hWnd    - handle to dialog window
//  UINT    uMsg    - dialog message
//  WPARAM  wParam  - message specific data
//  LPARAM  lParam  - message specific data
//
// Returns: BOOL
//
//===========================================================================
BOOL CALLBACK CPLSVR1_Page4_DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
   static CDIGameCntrlPropSheet_X *pdiCpl;
   static LPDIRECTINPUTDEVICE2    pdiDevice2;
   static LPDIJOYSTATE  pdijs;

   switch(uMsg)
   {
      case WM_INITDIALOG:
         {
         // perform any required initialization... 

         // get ptr to our object
         pdiCpl = (CDIGameCntrlPropSheet_X*)((LPPROPSHEETPAGE)lParam)->lParam;
         
         // Save our pointer so we can access it later
         SetWindowLong(hWnd, DWL_USER, (LPARAM)pdiCpl);

         // initialize DirectInput
         if (FAILED(InitDInput(GetParent(hWnd), pdiCpl)))
         {
#ifdef _DEBUG
            OutputDebugString(TEXT("CPLSvr1 Page 4 - InitDInput failed!\n"));
#endif //_DEBUG
            return TRUE;
         }

		   pdijs = new (DIJOYSTATE);
			assert (pdijs);
         }
         break;

      case WM_DESTROY:
		   if (pdijs)
				delete (pdijs);
			break;

      case WM_COMMAND:
         switch(LOWORD(wParam))
         {
            case IDC_STOP:
				   {
               // user clicked the "stop" button
               // 
               // we need to unacquire now
               //pdiCpl->GetDevice(&pdiDevice2);
               pdiDevice2->Unacquire();
               
               // we're done with our timer
               KillTimer(hWnd, ID_POLLTIMER);

               // display the acquisition status
               LoadString(ghInst, IDS_UNACQUIRED, lptszBuf, STR_LEN_64);
               SetDlgItemText(hWnd, IDC_DEVSTATUS, lptszBuf);

               // display no data
               ZeroMemory(pdijs, sizeof(DIJOYSTATE));
               DisplayJoystickState(hWnd, pdijs);
					}
               break;
         }
         break;

         case WM_NOTIFY:
         {
            // perform any WM_NOTIFY processing...

            switch(((LPNMHDR)lParam)->code)
            {
               case PSN_SETACTIVE:
		         	lptszBuf = new (TCHAR[STR_LEN_64]);
      	   	   assert (lptszBuf);

		   	      // get the device object
	   	         pdiCpl->GetDevice(&pdiDevice2);

                  // we're the active page now
                  // try to acquire the device
 				   	if (SUCCEEDED(pdiDevice2->Acquire()))
                  {                            
#ifdef _DEBUG
                     LoadString(ghInst, IDS_ACQUIRED, lptszBuf, MAX_PATH);                            
	   					OutputDebugString (lptszBuf);
#endif // _DEBUG
                     //create a timer to poll the device
                     SetTimer(hWnd, ID_POLLTIMER, 100, NULL);
                  } else KillTimer(hWnd, ID_POLLTIMER);
                  break;

               case PSN_KILLACTIVE:
                  // we're no longer the active page
                  // 
                  // we need to unacquire now
                  pdiDevice2->Unacquire();
#ifdef _DEBUG
                  LoadString(ghInst, IDS_UNACQUIRED, lptszBuf, MAX_PATH);
						OutputDebugString (lptszBuf);
#endif //_DEBUG

            		if (lptszBuf)
				         delete[] (lptszBuf);

                  // we're done with our timer
                  KillTimer(hWnd, ID_POLLTIMER);
                  break;
            }

            // display the acquisition status
            SetDlgItemText(hWnd, IDC_DEVSTATUS, lptszBuf);
         }
         return TRUE;

         case WM_TIMER:
			   // get the device object
            //pdiCpl->GetDevice(&pdiDevice2);
               
            ZeroMemory(pdijs, sizeof(DIJOYSTATE));
      
            if(SUCCEEDED(DIUtilPollJoystick(pdiDevice2, pdijs)))
               DisplayJoystickState(hWnd, pdijs);
            break;
    }
    
    return FALSE;
} //*** end CPLSVR1_Page4_DlgProc()


//===========================================================================
// InitDInput
//
// Initializes DirectInput objects
//
// Parameters:
//  HWND                    hWnd    - handle of caller's window
//  CDIGameCntrlPropSheet_X *pdiCpl - pointer to Game Controllers property
//                                      sheet object
//
// Returns: HRESULT
//
//===========================================================================
HRESULT InitDInput(HWND hWnd, CDIGameCntrlPropSheet_X *pdiCpl)
{
   // protect ourselves from multithreading problems
   EnterCriticalSection(&gcritsect);
   HRESULT       hRes;

   // validate pdiCpl
   if ((IsBadReadPtr((void*)pdiCpl, sizeof(CDIGameCntrlPropSheet_X))) ||
       (IsBadWritePtr((void*)pdiCpl, sizeof(CDIGameCntrlPropSheet_X))) )
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("InitDInput() - bogus pointer!\n"));
#endif // _DEBUG
      hRes = E_POINTER;
      goto exitinit;
   }

   LPDIRECTINPUTDEVICE2    pdiDevice2;

   // retrieve the current device object
   pdiCpl->GetDevice(&pdiDevice2);   

   LPDIRECTINPUTJOYCONFIG  pdiJoyCfg ;

   // retrieve the current joyconfig object
   pdiCpl->GetJoyConfig(&pdiJoyCfg);   

   LPDIRECTINPUT pdi;

   // have we already initialized DirectInput?
   if ((NULL == pdiDevice2) || (NULL == pdiJoyCfg))
   {
      // no, create a base DirectInput object
      hRes = DirectInputCreate(ghInst, DIRECTINPUT_VERSION, &pdi, NULL);
      if(FAILED(hRes))
      {
#ifdef _DEBUG
         OutputDebugString(TEXT("DirectInputCreate() failed!\n"));
#endif //_DEBUG
         goto exitinit;
      }
   }
   else
   {
      hRes = S_FALSE;
      goto exitinit;
   }


   // have we already created a joyconfig object?
   if (NULL == pdiJoyCfg)
   {
      // no, create a joyconfig object
      hRes = pdi->QueryInterface(IID_IDirectInputJoyConfig, (LPVOID*)&pdiJoyCfg);
      if (SUCCEEDED(hRes))
      {
         // store the joyconfig object
         pdiCpl->SetJoyConfig(pdiJoyCfg);
      }
      else
      {
#ifdef _DEBUG
         OutputDebugString(TEXT("Unable to create joyconfig!\n"));
#endif // _DEBUG
         goto exitinit;
      }
   } else hRes = S_FALSE;

   // have we already created a device object?
   if (NULL == pdiDevice2)
   {
      // no, create a device object

      if (NULL != pdiJoyCfg)
      {
         hRes = DIUtilCreateDevice2FromJoyConfig(pdiCpl->GetID(), hWnd, pdi, pdiJoyCfg, &pdiDevice2);
         if (SUCCEEDED(hRes))
         {
            // store the device object
            pdiCpl->SetDevice(pdiDevice2);
         }
         else
         {
#ifdef _DEBUG
            OutputDebugString(TEXT("DIUtilCreateDevice2FromJoyConfig() failed!\n"));
#endif //_DEBUG
            goto exitinit;
         }
      }
      else
      {
#ifdef _DEBUG
         OutputDebugString(TEXT("No joyconfig object... cannot create device!\n"));
#endif // _DEBUG
         hRes = E_FAIL;
         goto exitinit;
      }
   } else hRes = S_FALSE;

   if (NULL != pdi)
   {
      // release he base DirectInput object
      pdi->Release();
   }

exitinit:
   // we're done
   LeaveCriticalSection(&gcritsect);
   return hRes;
} //*** end InitDInput()


//===========================================================================
// EnumDeviceObjectsProc
//
// Enumerates DirectInput device objects (i.e. Axes, Buttons, etc)
//
// Parameters:
//  LPCDIDEVICEOBJECTINSTANCE   pdidoi  - ptr to device object instance data
//  LPVOID                      pv      - ptr to caller defined data
//
// Returns:
//  BOOL - DIENUM_STOP or DIENUM_CONTINUE
//
//===========================================================================
BOOL CALLBACK EnumDeviceObjectsProc(LPCDIDEVICEOBJECTINSTANCE pdidoi, LPVOID pv)
{
   // validate pointers
   if( (IsBadReadPtr((void*)pdidoi,sizeof(DIDEVICEINSTANCE))) )
   {
#ifdef _DEBUG
       OutputDebugString(TEXT("EnumDeviceObjectsProc() - invalid pdidoi!\n"));
#endif //_DEBUG
       return E_POINTER;
   }
   if( (IsBadReadPtr((void*)pv, 1)) ||
       (IsBadWritePtr((void*)pv, 1)) )
   {
#ifdef _DEBUG
       OutputDebugString(TEXT("EnumDeviceObjectsProc() - invalid pv!\n"));
#endif // _DEBUG
       return E_POINTER;
   }
    
	OBJECTINFO *poi = (OBJECTINFO*)pv;

	// store information about each object
   poi->rgGuidType[poi->nCount]    = pdidoi->guidType;
   poi->rgdwOfs[poi->nCount]       = pdidoi->dwOfs;
   poi->rgdwType[poi->nCount]      = pdidoi->dwType;
   lstrcpy(poi->rgtszName[poi->nCount], pdidoi->tszName);
    
   // increment the number of enum'd objects
   poi->nCount++;

   if (poi->nCount >= MAX_OBJECTS)
   {
      // we cannot handle any more objects...
      //
      // tell DirectInput to stop enumerating
      return DIENUM_STOP;
   }

   // let DInput enumerate until all the objects have been found
   return DIENUM_CONTINUE;
} //*** end EnumDeviceObjectsProc()


//===========================================================================
// EnumEffectsProc
//
// Enumerates DirectInput effect types
//
// Parameters:
//  LPCDIEFFECTINFO   pei   - ptr to effect information
//  LPVOID            pv    - ptr to caller defined data
//
// Returns:
//  BOOL - DIENUM_STOP or DIENUM_CONTINUE
//
//===========================================================================
BOOL CALLBACK EnumEffectsProc(LPCDIEFFECTINFO pei, LPVOID pv)
{
   // validate pointers
   if ((IsBadReadPtr((void*)pei,sizeof(DIEFFECTINFO))) )
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("EnumEffectsProc() - invalid pei!\n"));
#endif //_DEBUG
      return E_POINTER;
   }
   if ((IsBadReadPtr ((void*)pv, 1)) ||
       (IsBadWritePtr((void*)pv, 1)) )
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("EnumEffectsProc() - invalid pv!\n"));
#endif //_DEBUG
      return E_POINTER;
   }

   EFFECTLIST  *peList = (EFFECTLIST*)pv;

	// store information about each effect
   peList->rgGuid[peList->nCount]              = pei->guid;
   peList->rgdwEffType[peList->nCount]         = pei->dwEffType;
   peList->rgdwStaticParams[peList->nCount]    = pei->dwStaticParams;
   peList->rgdwDynamicParams[peList->nCount]   = pei->dwDynamicParams;
   lstrcpy(peList->rgtszName[peList->nCount], pei->tszName);
    
   // increment the number of enum'd effects
   peList->nCount++;

   if (peList->nCount >= MAX_OBJECTS)
   {
      // we cannot handle any more effects...
      //
      // tell DirectInput to stop enumerating
      return DIENUM_STOP;
   }

   // let DInput enumerate until all the objects have been found
   return DIENUM_CONTINUE;
} //*** end EnumEffectsProc()


//===========================================================================
// DisplayAxisList
//
// Displays the number and names of the device axes in the provided dialog
//  controls.
//
// Parameters:
//  HWND                    hWnd        - window handle
//  UINT                    uTextCtrlId - id of text control
//  UINT                    uListCtrlId - id of list box control
//  LPDIRECTINPUTDEVICE2    pdiDevice2  - ptr to device object
//
// Returns:
//
//===========================================================================
HRESULT DisplayAxisList(HWND hWnd, UINT uTextCtrlId, UINT uListCtrlId, LPDIRECTINPUTDEVICE2 pdiDevice2)
{
   // valdiate pointer(s)
   if( (IsBadReadPtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) ||
       (IsBadWritePtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) )
   {
#ifdef _DEBUG
       OutputDebugString(TEXT("DisplayAxisList() - invalid pdiDevice2!\n"));
#endif // _DEBUG
       return E_POINTER;
   }

   LPDIDEVCAPS   lpdidc = new (DIDEVCAPS);
   assert (lpdidc);

   lpdidc->dwSize = sizeof(DIDEVCAPS);
   HRESULT hRes = pdiDevice2->GetCapabilities(lpdidc);

   // display the number of axes reported by the device
   wsprintf(lptszBuf, TEXT("%d"), lpdidc->dwAxes);

   if (lpdidc)
      delete (lpdidc);

   SetDlgItemText(hWnd, uTextCtrlId, lptszBuf);
   
   OBJECTINFO  *poi = new (OBJECTINFO);
   assert (poi);

   // enumerate the device axes
   poi->nCount = 0;

   hRes = pdiDevice2->EnumObjects((LPDIENUMDEVICEOBJECTSCALLBACK)EnumDeviceObjectsProc, (LPVOID*)poi, DIDFT_AXIS);
   if (SUCCEEDED(hRes))
   {
      // display the name of each axis
      while (poi->nCount--)
         SendDlgItemMessage(hWnd, uListCtrlId, LB_ADDSTRING, 0, (LPARAM)poi->rgtszName[poi->nCount]);
   }
#ifdef _DEBUG
   else OutputDebugString(TEXT("DisplayAxisList() - EnumObjects() failed!\n"));
#endif // _DEBUG

   if (poi)
      delete (poi);

   // done
   return hRes;
} //*** end DisplayAxisList()


//===========================================================================
// DisplayButtonList
//
// Displays the number and names of the device buttons in the provided dialog
//  controls.
//
// Parameters:
//  HWND                    hWnd        - window handle
//  UINT                    uTextCtrlId - id of text control
//  UINT                    uListCtrlId - id of list box control
//  LPDIRECTINPUTDEVICE2    pdiDevice2  - ptr to device object
//
// Returns:
//
//===========================================================================
HRESULT DisplayButtonList(HWND hWnd, UINT uTextCtrlId, UINT uListCtrlId, LPDIRECTINPUTDEVICE2 pdiDevice2)
{
   // valdiate pointer(s)
   if ((IsBadReadPtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) ||
        (IsBadWritePtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) )
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("DisplayButtonList() - invalid pdiDevice2!\n"));
#endif // _DEBUG
      return E_POINTER;
   }

   LPDIDEVCAPS   pdidc = new (DIDEVCAPS);
	assert (pdidc);

   pdidc->dwSize = sizeof(DIDEVCAPS);
   HRESULT hRes = pdiDevice2->GetCapabilities(pdidc);

   // display the number of buttons reported by the device
   wsprintf(lptszBuf, TEXT("%d"), pdidc->dwButtons);

   if (pdidc)
	   delete (pdidc);

   SetDlgItemText(hWnd, uTextCtrlId, lptszBuf);
    
   // enumerate the device buttons
   OBJECTINFO  *poi = new (OBJECTINFO);
	assert (poi);

   poi->nCount = 0;
   hRes = pdiDevice2->EnumObjects((LPDIENUMDEVICEOBJECTSCALLBACK)EnumDeviceObjectsProc, (LPVOID*)poi, DIDFT_BUTTON);

   if (SUCCEEDED(hRes))
   {
	   // display the name of each button
	   while (poi->nCount--)
		   SendDlgItemMessage(hWnd, uListCtrlId, LB_ADDSTRING, 0, (LPARAM)poi->rgtszName[poi->nCount]);
   }
#ifdef _DEBUG
	else OutputDebugString(TEXT("DisplayButtonList() - EnumObjects() failed!\n"));
#endif //_DEBUG

	if (poi)
		delete (poi);

   // done
   return hRes;
} //*** end DisplayButtonList()


//===========================================================================
// DisplayPOVList
//
// Displays the number and names of the device POVs in the provided dialog
//  controls.
//
// Parameters:
//  HWND                    hWnd        - window handle
//  UINT                    uTextCtrlId - id of text control
//  UINT                    uListCtrlId - id of list box control
//  LPDIRECTINPUTDEVICE2    pdiDevice2  - ptr to device object
//
// Returns:
//
//===========================================================================
HRESULT DisplayPOVList(HWND hWnd, UINT uTextCtrlId, UINT uListCtrlId,
                        LPDIRECTINPUTDEVICE2 pdiDevice2)
{
   // valdiate pointer(s)
   if ((IsBadReadPtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) ||
        (IsBadWritePtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) )
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("DisplayPOVList() - invalid pdiDevice2!\n"));
#endif // _DEBUG
      return E_POINTER;
   }

   LPDIDEVCAPS   pdidc = new (DIDEVCAPS);
	assert (pdidc);

   pdidc->dwSize = sizeof(DIDEVCAPS);
   HRESULT hRes = pdiDevice2->GetCapabilities(pdidc);

   // display the number of POVs reported by the device
   wsprintf(lptszBuf, TEXT("%d"), pdidc->dwPOVs);

	if (pdidc)
	   delete (pdidc);

   SetDlgItemText(hWnd, uTextCtrlId, lptszBuf);
    
   // enumerate the device POVs
   OBJECTINFO  *poi = new (OBJECTINFO);
	assert (poi);

   poi->nCount = 0;
   hRes = pdiDevice2->EnumObjects((LPDIENUMDEVICEOBJECTSCALLBACK)EnumDeviceObjectsProc, (LPVOID*)poi, DIDFT_POV);

   if (SUCCEEDED(hRes))
   {
   	// display the name of each POV
		while (poi->nCount--)
			SendDlgItemMessage(hWnd, uListCtrlId, LB_ADDSTRING, 0, (LPARAM)poi->rgtszName[poi->nCount]);

   } 
#ifdef _DEBUG
   else OutputDebugString(TEXT("DisplayPOVList() - EnumObjects() failed!\n"));
#endif // _DEBUG

	if (poi)
		delete (poi);

   // done
   return hRes;
} //*** end DisplayPOVList()


//===========================================================================
// DisplayEffectList
//
// Displays the names of the device effects in the provided dialog
//  control.
//
// Parameters:
//  HWND                    hWnd        - window handle
//  UINT                    uListCtrlId - id of list box control
//  LPDIRECTINPUTDEVICE2    pdiDevice2  - ptr to device object
//
// Returns:
//
//===========================================================================
HRESULT DisplayEffectList(HWND hWnd, UINT uListCtrlId,
                          LPDIRECTINPUTDEVICE2 pdiDevice2)
{
   // valdiate pointer(s)
   if ((IsBadReadPtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) ||
       (IsBadWritePtr((void*)pdiDevice2, sizeof(IDirectInputDevice2))) )
   {
#ifdef _DEBUG
        OutputDebugString(TEXT("DisplayEffectList() - invalid pdiDevice2!\n"));
#endif // _DEBUG
        return E_POINTER;
   }

   DIDEVCAPS   didc;

   // check to see if our device supports force feedback
   didc.dwSize = sizeof(DIDEVCAPS);

   HRESULT hRes = pdiDevice2->GetCapabilities(&didc);
   if(FAILED(hRes))
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("DisplayEffectList() - GetCapabilities() failed!\n"));
#endif // _DEBUG
      return hRes;
   }

   if (!(didc.dwFlags & DIDC_FORCEFEEDBACK))
   {
      LoadString(ghInst, IDS_NOFORCEFEEDBACK, lptszBuf, STR_LEN_64);
      SendDlgItemMessage(hWnd, IDC_EFFECTLIST, LB_ADDSTRING, 0, (LPARAM)lptszBuf);
      return S_FALSE;
   }

   // enumerate effects
   EFFECTLIST  *pel = new (EFFECTLIST);
	assert (pel);

   pel->nCount = 0;
   hRes = pdiDevice2->EnumEffects((LPDIENUMEFFECTSCALLBACK)EnumEffectsProc, (LPVOID*)pel, DIEFT_ALL);

   if (SUCCEEDED(hRes))
   {
	   // display them to the list
	   while (pel->nCount--)
		   SendDlgItemMessage(hWnd, IDC_EFFECTLIST, LB_ADDSTRING, 0, (LPARAM)pel->rgtszName[pel->nCount]);

   }
#ifdef _DEBUG
   else OutputDebugString(TEXT("DisplayEffectList() - EnumEffects() failed!\n"));
#endif // _DEBUG

	if (pel)
		delete (pel);

   // done
   return hRes;
} //*** end DisplayEffectList()


//===========================================================================
// DisplayJoystickState
//
// Displays the current joystick state in the provided dialog.
//
// Parameters:
//  HWND        hWnd    - window handle
//  DIJOYSTATE  *pdijs  - ptr to joystick state information
//
// Returns:
//
//===========================================================================
HRESULT DisplayJoystickState(HWND hWnd, DIJOYSTATE *pdijs)
{
   TCHAR   tszBtn[5];

   // validate pointer(s)
   if( (IsBadReadPtr((void*)pdijs, sizeof(DIJOYSTATE))) )
   {
#ifdef _DEBUG
       OutputDebugString(TEXT("DisplayJoystickState() - invalid pdijs!\n"));
#endif // _DEBUG
       return E_POINTER;
   }

   // x-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lX);
   SetDlgItemText(hWnd, IDC_XDATA, lptszBuf);

   // y-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lY);
   SetDlgItemText(hWnd, IDC_YDATA, lptszBuf);

   // z-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lZ);
   SetDlgItemText(hWnd, IDC_ZDATA, lptszBuf);

   // rx-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lRx);
   SetDlgItemText(hWnd, IDC_RXDATA, lptszBuf);

   // ry-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lRy);
   SetDlgItemText(hWnd, IDC_RYDATA, lptszBuf);

   // rz-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->lRz);
   SetDlgItemText(hWnd, IDC_RZDATA, lptszBuf);

   // s0-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rglSlider[0]);
   SetDlgItemText(hWnd, IDC_S0DATA, lptszBuf);

   // s1-axis
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rglSlider[1]);
   SetDlgItemText(hWnd, IDC_S1DATA, lptszBuf);

   // pov0
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rgdwPOV[0]);
   SetDlgItemText(hWnd, IDC_POV0DATA, lptszBuf);

   // pov1
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rgdwPOV[1]);
   SetDlgItemText(hWnd, IDC_POV1DATA, lptszBuf);

   // pov2
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rgdwPOV[2]);
   SetDlgItemText(hWnd, IDC_POV2DATA, lptszBuf);

   // pov3
   wsprintf(lptszBuf, TEXT("%d"), pdijs->rgdwPOV[3]);
   SetDlgItemText(hWnd, IDC_POV3DATA, lptszBuf);

   // buttons
	lptszBuf[0] = '\0';

	#define CLEARLY_TOO_BIG		123
	static BYTE nBtnDown = CLEARLY_TOO_BIG;

	// if the button Was down, but isn't anymore...
	if (nBtnDown < CLEARLY_TOO_BIG)
	{
		if (!(pdijs->rgbButtons[nBtnDown] & 0x80))
		{
			// This sets the window back to nothing...
			SetDlgItemText(hWnd, IDC_TESTJOYBTNICON, lptszBuf);
			SetButtonState(hWnd, nBtnDown, FALSE);
		}
	}

   for (BYTE i = 0; i < 32; i++)
   {
       if (pdijs->rgbButtons[i] & 0x80)
       {
		   // this sets the string output
         wsprintf(tszBtn, TEXT(" %d"), i);
         lstrcat(lptszBuf, tszBtn);

	   	// This sets the window 
   		SetDlgItemText(hWnd, IDC_TESTJOYBTNICON, tszBtn);
		   SetButtonState(hWnd, i, TRUE );
	   	nBtnDown = i;

   		// do this if you are only checking for one button!
		   break;
      }
   }

   SetDlgItemText(hWnd, IDC_BUTTONSDOWN, lptszBuf);

   // done
   return S_OK;
} //*** end DisplayJoystickState()




















































//===========================================================================
// BUTTON.CPP
//
// Button Custom control
//
// Functions:
//    SetButtonState()
//    ButtonWndProc()
//    RegisterCustomButtonClass()
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

#include "cplsvr1.h"	   // for ghInst

#include "resrc1.h"

// Colour of text for buttons!
#define TEXT_COLOUR  RGB(202,202,202)

// Local globals!
static HICON hIconArray[2];

void SetButtonState(HWND hDlg, BYTE nButton, BOOL bState )
{
   if ((nButton < 0) || (nButton > 32))
   {
#ifdef _DEBUG
      OutputDebugString(TEXT("Button.cpp: SetState: nButton out of range!\n"));
#endif
      return;
   }

   HWND hCtrl = GetDlgItem(hDlg, IDC_TESTJOYBTNICON);
   assert (hCtrl);

   // Set the Extra Info
   SetWindowLong(hCtrl, GWL_USERDATA, (bState) ? 1 : 0);

   RedrawWindow(hCtrl, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ERASENOW);
}                                                    

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//    FUNCTION :  ButtonWndProc
//    REMARKS  :  The callback function for the CustomButton Window.
//				      
//    PARAMS   :  The usual callback funcs for message handling
//
//    RETURNS  :  LRESULT - Depends on the message
//    CALLS    :  
//    NOTES    :
//                

LRESULT CALLBACK ButtonWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(iMsg)
	{
		case WM_CREATE:
         // load the up and down states!
         hIconArray[0] = (HICON)LoadImage(ghInst, (PTSTR)IDI_BUTTONON,  IMAGE_ICON, 0, 0, NULL);
	      assert (hIconArray[0]);

         hIconArray[1] = (HICON)LoadImage(ghInst, (PTSTR)IDI_BUTTONOFF, IMAGE_ICON, 0, 0, NULL);
      	assert (hIconArray[1]);
			return FALSE;

      case WM_DESTROY:
         // Delete the buttons...
         DeleteObject(hIconArray[0]);
         DeleteObject(hIconArray[1]);
			return FALSE;

		case WM_PAINT:
			{
         PAINTSTRUCT *pps = new (PAINTSTRUCT);
			assert (pps);
         
         HDC hDC = BeginPaint(hWnd, pps);

         // Draw the appropriate icon                                                                                       
         DrawIconEx(hDC, 0, 0, hIconArray[GetWindowLong(hWnd, GWL_USERDATA)], 0, 0, 0, NULL, DI_NORMAL);
         
         static TCHAR tsz[3];

         // Get the Text
         GetWindowText(hWnd, tsz, sizeof(tsz)/sizeof(TCHAR));         
   
         // Prepare the DC for the text
         SetBkMode   (hDC, TRANSPARENT);
         SetTextColor(hDC, TEXT_COLOUR);

         // given the size of this RECT, it's faster 
         // to blit the whole the whole thing...
         pps->rcPaint.top    = 0; 
         pps->rcPaint.left   = 0;
         pps->rcPaint.bottom = 33;
         pps->rcPaint.right  = 30;

         // Draw the Number                        
         DrawText (hDC, (LPCTSTR)tsz, lstrlen(tsz), &pps->rcPaint, DT_VCENTER|DT_CENTER|DT_NOPREFIX|DT_SINGLELINE|DT_NOCLIP);
         SetBkMode(hDC, OPAQUE);
			EndPaint (hWnd, pps);

         if (pps)
            delete (pps);
			}
			return FALSE;

		default:
			return DefWindowProc(hWnd, iMsg,wParam, lParam);
	}
   return FALSE;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//    FUNCTION :  RegisterCustomButtonClass
//    REMARKS  :  Registers the Custom Button control window.
//				      
//    PARAMS   :  hInstance - Used for the call to RegisterClassEx
//
//    RETURNS  :  TRUE - if successfully registered
//                FALSE - failed to register
//    CALLS    :  RegisterClassEx
//    NOTES    :
//

extern BOOL RegisterCustomButtonClass()
{

   WNDCLASSEX     *pCustCtrlClass = new (WNDCLASSEX);
   assert (pCustCtrlClass);

   pCustCtrlClass->cbSize         = sizeof(WNDCLASSEX);
   pCustCtrlClass->style          = CS_HREDRAW | CS_VREDRAW;
   pCustCtrlClass->lpfnWndProc    = ButtonWndProc;
   pCustCtrlClass->cbClsExtra     = 0;
   pCustCtrlClass->cbWndExtra     = 0;
   pCustCtrlClass->hInstance      = ghInst;
   pCustCtrlClass->hIcon          = NULL;
   pCustCtrlClass->hCursor        = LoadCursor(NULL, IDC_ARROW);
   pCustCtrlClass->hbrBackground  = (HBRUSH) (COLOR_BTNFACE + 1);
   pCustCtrlClass->lpszMenuName   = NULL;
   pCustCtrlClass->lpszClassName  = TEXT("TESTBUTTON");
   pCustCtrlClass->hIconSm        = NULL; 

   ATOM aRet = RegisterClassEx( pCustCtrlClass );

   if (pCustCtrlClass)
      delete (pCustCtrlClass);

   return ( aRet ) ? TRUE : FALSE;
}



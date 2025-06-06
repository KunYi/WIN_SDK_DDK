/**********************************************************************/
/* Copyright (C) 1995-1996 Zhong Yi Electronics Corp.                 */
/* Auther: Wang Chao Yang                                             */
/**********************************************************************/

#include <windows.h>
#include <winerror.h>
#include <memory.h>
#include <regstr.h>
#include "imm.h"
#include "imedefs.h"


void PASCAL InitStatusUIData(
    int     cxBorder,
    int     cyBorder)
{
    // right bottom of status
    sImeG.rcStatusText.left = 2;
    sImeG.rcStatusText.top = 2;

    sImeG.rcStatusText.right = sImeG.rcStatusText.left +
		lstrlen(szImeName) * sImeG.xChiCharWi/2 + STATUS_NAME_MARGIN + STATUS_DIM_X * 4;
    sImeG.rcStatusText.bottom = sImeG.rcStatusText.top + STATUS_DIM_Y;

    sImeG.xStatusWi = STATUS_DIM_X * 4 + STATUS_NAME_MARGIN +
		lstrlen(szImeName) * sImeG.xChiCharWi/2 + 6 * cxBorder;
    sImeG.yStatusHi = STATUS_DIM_Y + 6 * cxBorder;
	
    // left bottom of imeicon bar
    sImeG.rcImeIcon.left = sImeG.rcStatusText.left;
    sImeG.rcImeIcon.top = sImeG.rcStatusText.top;
    sImeG.rcImeIcon.right = sImeG.rcImeIcon.left + STATUS_DIM_X;
    sImeG.rcImeIcon.bottom = sImeG.rcImeIcon.top + STATUS_DIM_Y;

    // left bottom of imename bar
    sImeG.rcImeName.left = sImeG.rcImeIcon.right;
    sImeG.rcImeName.top = sImeG.rcStatusText.top;
    sImeG.rcImeName.right = sImeG.rcImeName.left +
			lstrlen(szImeName) * sImeG.xChiCharWi/2 + STATUS_NAME_MARGIN;
    sImeG.rcImeName.bottom = sImeG.rcImeName.top + STATUS_DIM_Y;
	

    // middle bottom of Shape bar
    sImeG.rcShapeText.left = sImeG.rcImeName.right;
    sImeG.rcShapeText.top = sImeG.rcStatusText.top;
    sImeG.rcShapeText.right = sImeG.rcShapeText.left + STATUS_DIM_X;
    sImeG.rcShapeText.bottom = sImeG.rcShapeText.top + STATUS_DIM_Y;

    // middle bottom of Symbol bar
    sImeG.rcSymbol.left = sImeG.rcShapeText.right;
    sImeG.rcSymbol.top = sImeG.rcStatusText.top;
    sImeG.rcSymbol.right = sImeG.rcSymbol.left + STATUS_DIM_X;
    sImeG.rcSymbol.bottom = sImeG.rcSymbol.top + STATUS_DIM_Y;

    // right bottom of SK bar
    sImeG.rcSKText.left = sImeG.rcSymbol.right;  
    sImeG.rcSKText.top = sImeG.rcStatusText.top;
    sImeG.rcSKText.right = sImeG.rcSKText.left + STATUS_DIM_X;
    sImeG.rcSKText.bottom = sImeG.rcSKText.top + STATUS_DIM_Y;

    return;
}

void PASCAL InitCandUIData(
    int     cxBorder,
    int     cyBorder,
    int     UIMode)
{
    sImeG.cxCandBorder = cxBorder * 2;
    sImeG.cyCandBorder = cyBorder * 2;

    if(UIMode == LIN_UI) {
//          sImeG.rcCandIcon.left = cxBorder;
	    sImeG.rcCandIcon.left = 0;
		sImeG.rcCandIcon.top = cyBorder + 2;
	    sImeG.rcCandIcon.right = sImeG.rcCandIcon.left + UI_CANDICON;
	    sImeG.rcCandIcon.bottom = sImeG.rcCandIcon.top + UI_CANDICON;
						  
	    sImeG.rcCandText.left = sImeG.rcCandIcon.right + 3;
		sImeG.rcCandText.top =  cyBorder + 2;
	    sImeG.rcCandText.right = sImeG.rcCandText.left + UI_CANDSTR;
	    sImeG.rcCandText.bottom = sImeG.rcCandText.top + sImeG.yChiCharHi;

	    sImeG.rcCandBTH.top = cyBorder * 4;
	    sImeG.rcCandBTH.left = sImeG.rcCandText.right + 5;
	    sImeG.rcCandBTH.right = sImeG.rcCandBTH.left + UI_CANDBTW;
	    sImeG.rcCandBTH.bottom = sImeG.rcCandBTH.top + UI_CANDBTH;

	    sImeG.rcCandBTU.top = cyBorder * 4;
	    sImeG.rcCandBTU.left = sImeG.rcCandBTH.right;
	    sImeG.rcCandBTU.right = sImeG.rcCandBTU.left + UI_CANDBTW;
	    sImeG.rcCandBTU.bottom = sImeG.rcCandBTU.top + UI_CANDBTH;

	    sImeG.rcCandBTD.top = cyBorder * 4;
	    sImeG.rcCandBTD.left = sImeG.rcCandBTU.right;
	    sImeG.rcCandBTD.right = sImeG.rcCandBTD.left + UI_CANDBTW;
	    sImeG.rcCandBTD.bottom = sImeG.rcCandBTD.top + UI_CANDBTH;

	    sImeG.rcCandBTE.top = cyBorder * 4;
	    sImeG.rcCandBTE.left = sImeG.rcCandBTD.right;
	    sImeG.rcCandBTE.right = sImeG.rcCandBTE.left + UI_CANDBTW;
	    sImeG.rcCandBTE.bottom = sImeG.rcCandBTE.top + UI_CANDBTH;

	    sImeG.xCandWi = sImeG.rcCandBTE.right + sImeG.cxCandBorder * 2 + cxBorder * 4;
	    sImeG.yCandHi = sImeG.rcCandText.bottom + sImeG.cyCandBorder * 2 + cyBorder * 4;

	} else {
		sImeG.rcCandText.left = cxBorder + 2;
	    sImeG.rcCandText.top = 2 * cyBorder + 2 + UI_CANDINF;
	    if(sImeG.xChiCharWi*9 > (UI_CANDICON*6 + UI_CANDBTH*4))
			sImeG.rcCandText.right = sImeG.rcCandText.left + sImeG.xChiCharWi * 9;
		else
			sImeG.rcCandText.right = sImeG.rcCandText.left + (UI_CANDICON*6 + UI_CANDBTH*4);
	    sImeG.rcCandText.bottom = sImeG.rcCandText.top + sImeG.yChiCharHi * CANDPERPAGE;

	    sImeG.xCandWi = sImeG.rcCandText.right + sImeG.cxCandBorder * 2 + cxBorder * 4;
	    sImeG.yCandHi = sImeG.rcCandText.bottom + sImeG.cyCandBorder * 2 + cyBorder * 4;

	    sImeG.rcCandIcon.left = cxBorder;
	    sImeG.rcCandIcon.top = cyBorder + 2;
	    sImeG.rcCandIcon.right = sImeG.rcCandIcon.left + UI_CANDICON;
	    sImeG.rcCandIcon.bottom = sImeG.rcCandIcon.top + UI_CANDICON;
						  
	    sImeG.rcCandInf.left = sImeG.rcCandIcon.right;
	    sImeG.rcCandInf.top = cyBorder + 3;
	    sImeG.rcCandInf.right = sImeG.rcCandInf.left + UI_CANDICON * 5;
	    sImeG.rcCandInf.bottom = sImeG.rcCandInf.top + UI_CANDBTH;

	    sImeG.rcCandBTE.top = cyBorder * 5;
	    sImeG.rcCandBTE.right = sImeG.rcCandText.right + cxBorder;
	    sImeG.rcCandBTE.bottom = sImeG.rcCandBTE.top + UI_CANDBTH;
	    sImeG.rcCandBTE.left = sImeG.rcCandBTE.right - UI_CANDBTW;

	    sImeG.rcCandBTD.top = cyBorder * 5;
	    sImeG.rcCandBTD.right = sImeG.rcCandBTE.left;
	    sImeG.rcCandBTD.bottom = sImeG.rcCandBTD.top + UI_CANDBTH;
	    sImeG.rcCandBTD.left = sImeG.rcCandBTD.right - UI_CANDBTW;

	    sImeG.rcCandBTU.top = cyBorder * 5;
	    sImeG.rcCandBTU.right = sImeG.rcCandBTD.left;
	    sImeG.rcCandBTU.bottom = sImeG.rcCandBTU.top + UI_CANDBTH;
	    sImeG.rcCandBTU.left = sImeG.rcCandBTU.right - UI_CANDBTW;

	    sImeG.rcCandBTH.top = cyBorder * 5;
	    sImeG.rcCandBTH.right = sImeG.rcCandBTU.left;
	    sImeG.rcCandBTH.bottom = sImeG.rcCandBTH.top + UI_CANDBTH;
	    sImeG.rcCandBTH.left = sImeG.rcCandBTH.right - UI_CANDBTW;
	}

}
/**********************************************************************/
/* InitImeGlobalData()                                                */
/**********************************************************************/
void PASCAL InitImeGlobalData(
    HINSTANCE hInstance)
{
    int     cxBorder, cyBorder;
	int     UI_MODE;
    HDC     hDC;
    HGDIOBJ hOldFont;
    LOGFONT lfFont;
    BYTE    szChiChar[4];
    SIZE    lTextSize;
    HGLOBAL hResData;
    int     i;
    DWORD   dwSize;
    HKEY    hKeyIMESetting;
    LONG    lRet;

    hInst = hInstance;
    // get the UI Ime name
//    LoadString(hInst, IDS_IMENAME, szUIImeName,
//        strlen(szUIClassName));

    // get the UI class name
    LoadString(hInst, IDS_IMEUICLASS, szUIClassName,
	CLASS_LEN);

    // get the composition class name
    LoadString(hInst, IDS_IMECOMPCLASS, szCompClassName,
	CLASS_LEN);

    // get the candidate class name
    LoadString(hInst, IDS_IMECANDCLASS, szCandClassName,
	CLASS_LEN);

    // get the status class name
    LoadString(hInst, IDS_IMESTATUSCLASS, szStatusClassName,
	CLASS_LEN);

	//get the ContextMenu class name
    LoadString(hInst, IDS_IMECMENUCLASS, szCMenuClassName,
	CLASS_LEN);

	//get the softkeyboard Menu class name
    LoadString(hInst, IDS_IMESOFTKEYMENUCLASS, szSoftkeyMenuClassName,
	CLASS_LEN);

    // work area
    SystemParametersInfo(SPI_GETWORKAREA, 0, &sImeG.rcWorkAreaSt, 0);
	sImeG.rcWorkAreaCa=sImeG.rcWorkAreaCo=sImeG.rcWorkAreaKe=sImeG.rcWorkAreaSt;	

    // border
    cxBorder = GetSystemMetrics(SM_CXBORDER);
    cyBorder = GetSystemMetrics(SM_CYBORDER);

    // get the Chinese char
    LoadString(hInst, IDS_CHICHAR, szChiChar, sizeof(szChiChar));

    // get size of Chinese char
    hDC = GetDC(NULL);
    
    hOldFont = GetCurrentObject(hDC, OBJ_FONT);
    GetObject(hOldFont, sizeof(LOGFONT), &lfFont);

    if (lfFont.lfCharSet != NATIVE_CHARSET) {
	// Chicago GB Chinese
	sImeG.fDiffSysCharSet = TRUE;
	lfFont.lfCharSet = NATIVE_CHARSET;
	lfFont.lfFaceName[0] = '\0';
	SelectObject(hDC, CreateFontIndirect(&lfFont));
    } else {
	sImeG.fDiffSysCharSet = FALSE;
    }

    if(!GetTextExtentPoint(hDC, (LPSTR)szChiChar, lstrlen(szChiChar), &lTextSize))
		memset(&lTextSize, 0, sizeof(SIZE));
    if (sImeG.rcWorkAreaSt.right < 2 * UI_MARGIN) {
	sImeG.rcWorkAreaSt.left = 0;
	sImeG.rcWorkAreaSt.right = GetDeviceCaps(hDC, HORZRES);
    }
    if (sImeG.rcWorkAreaSt.bottom < 2 * UI_MARGIN) {
	sImeG.rcWorkAreaSt.top = 0;
	sImeG.rcWorkAreaSt.bottom = GetDeviceCaps(hDC, VERTRES);
    }

    if (sImeG.fDiffSysCharSet) {
	DeleteObject(SelectObject(hDC, hOldFont));
    }

    ReleaseDC(NULL, hDC);

    // get text metrics to decide the width & height of composition window
    // these IMEs always use system font to show
    sImeG.xChiCharWi = lTextSize.cx;
    sImeG.yChiCharHi = lTextSize.cy;

	if(sImeG.IC_Trace) {
		UI_MODE = BOX_UI;
	} else {
		UI_MODE = LIN_UI;
	}

	InitCandUIData(cxBorder, cyBorder, UI_MODE);

	InitStatusUIData(cxBorder, cyBorder);

    // load full ABC table
    hResData = LoadResource(hInst, FindResource(hInst,
	"FULLABC", RT_RCDATA));
    *(LPFULLABC)sImeG.wFullABC = *(LPFULLABC)LockResource(hResData);
    UnlockResource(hResData);
    FreeResource(hResData);

    // full shape space
    sImeG.wFullSpace = sImeG.wFullABC[0];

    // reverse internal code to internal code, NT don't need it
    for (i = 0; i < (sizeof(sImeG.wFullABC) / 2); i++) {
	sImeG.wFullABC[i] = (sImeG.wFullABC[i] << 8) |
	    (sImeG.wFullABC[i] >> 8);
    }

    LoadString(hInst, IDS_STATUSERR, sImeG.szStatusErr,
	sizeof(sImeG.szStatusErr));
    sImeG.cbStatusErr = lstrlen(sImeG.szStatusErr);

    sImeG.iCandStart = CAND_START;

    // get the UI offset for near caret operation
    RegCreateKey(HKEY_CURRENT_USER, szRegIMESetting, &hKeyIMESetting);

	dwSize = sizeof(DWORD);
    lRet  = RegQueryValueEx(hKeyIMESetting, szPara, NULL, NULL,
	(LPBYTE)&sImeG.iPara, &dwSize);

    if (lRet != ERROR_SUCCESS) {
	sImeG.iPara = 0;
	RegSetValueEx(hKeyIMESetting, szPara, (DWORD)NULL, REG_BINARY,
	    (LPBYTE)&sImeG.iPara, sizeof(int));
    }

	dwSize = sizeof(DWORD);
    lRet = RegQueryValueEx(hKeyIMESetting, szPerp, NULL, NULL,
	(LPBYTE)&sImeG.iPerp, &dwSize);

    if (lRet != ERROR_SUCCESS) {
	sImeG.iPerp = sImeG.yChiCharHi;
	RegSetValueEx(hKeyIMESetting, szPerp, (DWORD)NULL, REG_BINARY,
	    (LPBYTE)&sImeG.iPerp, sizeof(int));
    }

	dwSize = sizeof(DWORD);
    lRet = RegQueryValueEx(hKeyIMESetting, szParaTol, NULL, NULL,
	(LPBYTE)&sImeG.iParaTol, &dwSize);

    if (lRet != ERROR_SUCCESS) {
	sImeG.iParaTol = sImeG.xChiCharWi * 4;
	RegSetValueEx(hKeyIMESetting, szParaTol, (DWORD)NULL, REG_BINARY,
	    (LPBYTE)&sImeG.iParaTol, sizeof(int));
    }

	dwSize = sizeof(DWORD);
    lRet = RegQueryValueEx(hKeyIMESetting, szPerpTol, NULL, NULL,
	(LPBYTE)&sImeG.iPerpTol, &dwSize);

    if (lRet != ERROR_SUCCESS) {
	sImeG.iPerpTol = lTextSize.cy;
	RegSetValueEx(hKeyIMESetting, szPerpTol, (DWORD)NULL, REG_BINARY,
	    (LPBYTE)&sImeG.iPerpTol, sizeof(int));
    }

    RegCloseKey(hKeyIMESetting);

    return;
}

/**********************************************************************/
/* InitImeLocalData()                                                 */
/**********************************************************************/
BOOL PASCAL InitImeLocalData(
    HINSTANCE hInstL)
{
    int      cxBorder, cyBorder;

    lpImeL->hInst = hInstL;

    lpImeL->nMaxKey = 4;

    // border + raising edge + sunken edge
    cxBorder = GetSystemMetrics(SM_CXBORDER);
    cyBorder = GetSystemMetrics(SM_CYBORDER);
										
    // text position relative to the composition window
    lpImeL->cxCompBorder = cxBorder * 2;
    lpImeL->cyCompBorder = cyBorder * 2;

    lpImeL->rcCompText.left = cxBorder+2;
    lpImeL->rcCompText.top = cyBorder+2;

    lpImeL->rcCompText.right = lpImeL->rcCompText.left + sImeG.xChiCharWi * ((lpImeL->nMaxKey + 2) / 2);
    lpImeL->rcCompText.bottom = lpImeL->rcCompText.top + sImeG.yChiCharHi;
    // set the width & height for composition window
    lpImeL->xCompWi = lpImeL->rcCompText.right + lpImeL->cxCompBorder * 2 + cxBorder * 4;
    lpImeL->yCompHi = lpImeL->rcCompText.bottom + lpImeL->cyCompBorder * 2 + cyBorder * 4;

    // default position of composition window
    lpImeL->ptDefComp.x = sImeG.rcWorkAreaSt.right -
	lpImeL->xCompWi - cxBorder * 2;
    lpImeL->ptDefComp.y = sImeG.rcWorkAreaSt.bottom -
	lpImeL->yCompHi - cyBorder * 2;

    lpImeL->fModeConfig = MODE_CONFIG_QUICK_KEY|MODE_CONFIG_PREDICT;

    return (TRUE);
}

/**********************************************************************/
/* RegisterIme()                                                      */
/**********************************************************************/
void PASCAL RegisterIme(
    HINSTANCE hInstance)
{
	HKEY  hKeyCurrVersion;
	HKEY  hKeyGB;
	DWORD retCode;
//    CHAR  Buf[LINE_LEN];
	DWORD ValueType;
	DWORD ValueSize;

    // init ime charact
    lstrcpy(sImeG.UsedCodes, "0123456789abcdef");
	sImeG.wNumCodes = lstrlen(sImeG.UsedCodes);
    sImeG.IC_Enter = 0;
    sImeG.IC_Trace = 0;
	
	retCode = OpenReg_PathSetup(&hKeyCurrVersion);
    if (retCode) {
	    RegCreateKey(HKEY_CURRENT_USER, REGSTR_PATH_SETUP, &hKeyCurrVersion);
    }

	retCode = OpenReg_User (hKeyCurrVersion,
			  szImeRegName,
			  &hKeyGB);
    if (retCode) {
	    DWORD dwDisposition;
	DWORD Value;
	    
	    retCode = RegCreateKeyEx (hKeyCurrVersion,
			   szImeRegName,
			   0,
						   0,
						   REG_OPTION_NON_VOLATILE,
						   KEY_ALL_ACCESS,
						   NULL,
			   &hKeyGB,
			   &dwDisposition);

	    Value = 1;
	    RegSetValueEx (hKeyGB, "光标跟随",
				   (DWORD)NULL,
				   REG_DWORD,
				   (LPBYTE)&Value,
				    sizeof(DWORD));
	}

    // query 光标跟随 value
	ValueSize = sizeof(DWORD);
	if (RegQueryValueEx (hKeyGB, "光标跟随",
		    (DWORD)NULL,
					(LPDWORD)&ValueType,
		    (LPBYTE)&sImeG.IC_Trace,
		    (LPDWORD)&ValueSize) != ERROR_SUCCESS)
	{
	    DWORD Value = 1;
	    RegSetValueEx (hKeyGB, "光标跟随",
				   (DWORD)NULL,
				   REG_DWORD,
				   (LPBYTE)&Value,
				    sizeof(DWORD));
		RegQueryValueEx (hKeyGB, "光标跟随",
		    (DWORD)NULL,
					(LPDWORD)&ValueType,
		    (LPBYTE)&sImeG.IC_Trace,
		    (LPDWORD)&ValueSize);
	}
		
		

    if(RegQueryValueEx (hKeyGB, szRegRevKL,
		     NULL,
		     NULL,             //null-terminate string
		     (LPBYTE)&sImeG.hRevKL,              //&bData,
		     &ValueSize) != ERROR_SUCCESS)
		sImeG.hRevKL = NULL;
    if(RegQueryValueEx (hKeyGB, szRegRevMaxKey,
		     NULL,
		     NULL,             //null-terminate string
		     (LPBYTE)&sImeG.nRevMaxKey,              //&bData,
		     &ValueSize) != ERROR_SUCCESS)
		sImeG.hRevKL = NULL;

	RegCloseKey(hKeyGB);
	RegCloseKey(hKeyCurrVersion);

    return;
}

/**********************************************************************/
/* RegisterImeClass()                                                 */
/**********************************************************************/
void PASCAL RegisterImeClass(
    HINSTANCE hInstance,
    HINSTANCE hInstL)
{
    WNDCLASSEX wcWndCls;

    // IME UI class
	// Register IME UI class
    wcWndCls.cbSize        = sizeof(WNDCLASSEX);
    wcWndCls.cbClsExtra    = 0;
    wcWndCls.cbWndExtra    = sizeof(LONG) * 2;
    wcWndCls.hIcon         = LoadImage(hInstL, MAKEINTRESOURCE(IDI_IME),
	IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
    wcWndCls.hInstance     = hInstance;
    wcWndCls.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wcWndCls.hbrBackground = GetStockObject(NULL_BRUSH);
    wcWndCls.lpszMenuName  = (LPSTR)NULL;
    wcWndCls.hIconSm       = LoadImage(hInstL, MAKEINTRESOURCE(IDI_IME),
	IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);

    // IME UI class
    if (!GetClassInfoEx(hInstance, szUIClassName, &wcWndCls)) {
	wcWndCls.style         = CS_IME;
	wcWndCls.lpfnWndProc   = UIWndProc;
	wcWndCls.lpszClassName = (LPSTR)szUIClassName;

	RegisterClassEx(&wcWndCls);
    }

    wcWndCls.style         = CS_IME|CS_HREDRAW|CS_VREDRAW;
    wcWndCls.hbrBackground = GetStockObject(LTGRAY_BRUSH);


    // IME composition class
	// register IME composition class
    if (!GetClassInfoEx(hInstance, szCompClassName, &wcWndCls)) {
	wcWndCls.lpfnWndProc   = CompWndProc;
	wcWndCls.lpszClassName = (LPSTR)szCompClassName;

	RegisterClassEx(&wcWndCls);
    }

    // IME candidate class
	// register IME candidate class
    if (!GetClassInfoEx(hInstance, szCandClassName, &wcWndCls)) {
	wcWndCls.lpfnWndProc   = CandWndProc;
	wcWndCls.lpszClassName = (LPSTR)szCandClassName;

	RegisterClassEx(&wcWndCls);
    }

    // IME status class
	// register IME status class
    if (!GetClassInfoEx(hInstance, szStatusClassName, &wcWndCls)) {
	wcWndCls.lpfnWndProc   = StatusWndProc;
	wcWndCls.lpszClassName = (LPSTR)szStatusClassName;

	RegisterClassEx(&wcWndCls);
    }

    // IME context menu class
    if (!GetClassInfoEx(hInstance, szCMenuClassName, &wcWndCls)) {
	wcWndCls.style         = 0;
	wcWndCls.hbrBackground = GetStockObject(NULL_BRUSH);
	wcWndCls.lpfnWndProc   = ContextMenuWndProc;
	wcWndCls.lpszClassName = (LPSTR)szCMenuClassName;

	RegisterClassEx(&wcWndCls);
    }
    // IME softkeyboard menu class
    if (!GetClassInfoEx(hInstance, szSoftkeyMenuClassName, &wcWndCls)) {
	wcWndCls.style         = 0;
	wcWndCls.hbrBackground = GetStockObject(NULL_BRUSH);
	wcWndCls.lpfnWndProc   = SoftkeyMenuWndProc;
	wcWndCls.lpszClassName = (LPSTR)szSoftkeyMenuClassName;

	RegisterClassEx(&wcWndCls);
    }

    return;
}

/**********************************************************************/
/* ImeDllInit()                                                       */
/* Return Value:                                                      */
/*      TRUE - successful                                             */
/*      FALSE - failure                                               */
/**********************************************************************/
BOOL CALLBACK ImeDllInit(
    HINSTANCE hInstance,        // instance handle of this library
    DWORD     fdwReason,        // reason called
    LPVOID    lpvReserve)       // reserve pointer
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
	// init ime parameter
	RegisterIme(hInstance);

	// init globaldata & load globaldata from resource
	{
	HKEY  hKeyCurrVersion;
	HKEY  hKeyGB;
	LONG  retCode;
	DWORD ValueType;
	DWORD ValueSize;

	retCode = OpenReg_PathSetup(&hKeyCurrVersion);

    if (retCode) {
	    RegCreateKey(HKEY_CURRENT_USER, REGSTR_PATH_SETUP, &hKeyCurrVersion);
    }

 
	retCode = RegCreateKeyEx(hKeyCurrVersion, szImeRegName, 0,
    			NULL, REG_OPTION_NON_VOLATILE,	KEY_ALL_ACCESS	, NULL, &hKeyGB, NULL);

	ValueSize = sizeof(DWORD);
	retCode = RegQueryValueEx (hKeyGB, szRegImeIndex,
		             (DWORD)NULL,
					 (LPDWORD)&ValueType,
		             (LPBYTE)&sImeL.dwRegImeIndex,
		             (LPDWORD)&ValueSize);

	if ( retCode != ERROR_SUCCESS )  {
   		//set GB/QW as default


    	    sImeL.dwRegImeIndex = 0;
	        RegSetValueEx (hKeyGB, szRegImeIndex,
							(DWORD)NULL,
		        		   REG_DWORD,
				          (LPBYTE)&sImeL.dwRegImeIndex,
				          sizeof(DWORD));  
	}
    
	//readout current ImeName
	szImeName = pszImeName[sImeL.dwRegImeIndex];

	RegCloseKey(hKeyGB);
	RegCloseKey(hKeyCurrVersion);
	}

	if (!hInst) {
	    InitImeGlobalData(hInstance);
	}

	if (!lpImeL) {
	    lpImeL = &sImeL;
	    InitImeLocalData(hInstance);
	}

	RegisterImeClass(hInstance, hInstance);

	break;
    case DLL_PROCESS_DETACH:
	{
	    WNDCLASSEX wcWndCls;

		    if (GetClassInfoEx(hInstance, szCMenuClassName, &wcWndCls)) {
			UnregisterClass(szCMenuClassName, hInstance);
		}

		    if (GetClassInfoEx(hInstance, szSoftkeyMenuClassName, &wcWndCls)) {
			UnregisterClass(szSoftkeyMenuClassName, hInstance);
		}

	    if (GetClassInfoEx(hInstance, szStatusClassName, &wcWndCls)) {
		UnregisterClass(szStatusClassName, hInstance);
	    }

	    if (GetClassInfoEx(hInstance, szCandClassName, &wcWndCls)) {
		UnregisterClass(szCandClassName, hInstance);
	    }

	    if (GetClassInfoEx(hInstance, szCompClassName, &wcWndCls)) {
		UnregisterClass(szCompClassName, hInstance);
	    }

	    if (!GetClassInfoEx(hInstance, szUIClassName, &wcWndCls)) {
	    } else if (!UnregisterClass(szUIClassName, hInstance)) {
	    } else {
		DestroyIcon(wcWndCls.hIcon);
		DestroyIcon(wcWndCls.hIconSm);
	    }
	}
	break;
    default:
	break;
    }

    return (TRUE);
}

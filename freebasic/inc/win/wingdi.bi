'' FreeBASIC binding for mingw-w64-v4.0.4
''
'' based on the C header files:
''   DISCLAIMER
''   This file has no copyright assigned and is placed in the Public Domain.
''   This file is part of the mingw-w64 runtime package.
''
''   The mingw-w64 runtime package and its code is distributed in the hope that it 
''   will be useful but WITHOUT ANY WARRANTY.  ALL WARRANTIES, EXPRESSED OR 
''   IMPLIED ARE HEREBY DISCLAIMED.  This includes but is not limited to 
''   warranties of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
''
'' translated to FreeBASIC by:
''   FreeBASIC development team

#pragma once

#inclib "gdi32"
#inclib "msimg32"

#include once "winapifamily.bi"
#include once "_mingw_unicode.bi"

'' The following symbols have been renamed:
''     constant ERROR => ERROR_
''     constant ABORTDOC => ABORTDOC_
''     constant SETABORTPROC => SETABORTPROC_
''     constant STARTDOC => STARTDOC_
''     constant ENDDOC => ENDDOC_
''     constant SETMITERLIMIT => SETMITERLIMIT_
''     constant EXTTEXTOUT => EXTTEXTOUT_
''     constant STRETCHBLT => STRETCHBLT_
''     #define RGB => BGR
''     constant BITSPIXEL => BITSPIXEL_
''     constant PLANES => PLANES_

extern "Windows"

#define _WINGDI_
const R2_BLACK = 1
const R2_NOTMERGEPEN = 2
const R2_MASKNOTPEN = 3
const R2_NOTCOPYPEN = 4
const R2_MASKPENNOT = 5
const R2_NOT = 6
const R2_XORPEN = 7
const R2_NOTMASKPEN = 8
const R2_MASKPEN = 9
const R2_NOTXORPEN = 10
const R2_NOP = 11
const R2_MERGENOTPEN = 12
const R2_COPYPEN = 13
const R2_MERGEPENNOT = 14
const R2_MERGEPEN = 15
const R2_WHITE = 16
const R2_LAST = 16
const SRCCOPY = cast(DWORD, &h00CC0020)
const SRCPAINT = cast(DWORD, &h00EE0086)
const SRCAND = cast(DWORD, &h008800C6)
const SRCINVERT = cast(DWORD, &h00660046)
const SRCERASE = cast(DWORD, &h00440328)
const NOTSRCCOPY = cast(DWORD, &h00330008)
const NOTSRCERASE = cast(DWORD, &h001100A6)
const MERGECOPY = cast(DWORD, &h00C000CA)
const MERGEPAINT = cast(DWORD, &h00BB0226)
const PATCOPY = cast(DWORD, &h00F00021)
const PATPAINT = cast(DWORD, &h00FB0A09)
const PATINVERT = cast(DWORD, &h005A0049)
const DSTINVERT = cast(DWORD, &h00550009)
const BLACKNESS = cast(DWORD, &h00000042)
const WHITENESS = cast(DWORD, &h00FF0062)
const NOMIRRORBITMAP = cast(DWORD, &h80000000)
const CAPTUREBLT = cast(DWORD, &h40000000)
#define MAKEROP4(fore, back) cast(DWORD, (((back) shl 8) and &hFF000000) or (fore))
const GDI_ERROR = &hFFFFFFFF
#define HGDI_ERROR LongToHandle(&hFFFFFFFF)
const ERROR_ = 0
const NULLREGION = 1
const SIMPLEREGION = 2
const COMPLEXREGION = 3
const RGN_ERROR = ERROR_
const RGN_AND = 1
const RGN_OR = 2
const RGN_XOR = 3
const RGN_DIFF = 4
const RGN_COPY = 5
const RGN_MIN = RGN_AND
const RGN_MAX = RGN_COPY
const BLACKONWHITE = 1
const WHITEONBLACK = 2
const COLORONCOLOR = 3
const HALFTONE = 4
const MAXSTRETCHBLTMODE = 4
const STRETCH_ANDSCANS = BLACKONWHITE
const STRETCH_ORSCANS = WHITEONBLACK
const STRETCH_DELETESCANS = COLORONCOLOR
const STRETCH_HALFTONE = HALFTONE
const ALTERNATE = 1
const WINDING = 2
const POLYFILL_LAST = 2
const LAYOUT_RTL = &h00000001
const LAYOUT_BTT = &h00000002
const LAYOUT_VBH = &h00000004
const LAYOUT_ORIENTATIONMASK = (LAYOUT_RTL or LAYOUT_BTT) or LAYOUT_VBH
const LAYOUT_BITMAPORIENTATIONPRESERVED = &h00000008
const TA_NOUPDATECP = 0
const TA_UPDATECP = 1
const TA_LEFT = 0
const TA_RIGHT = 2
const TA_CENTER = 6
const TA_TOP = 0
const TA_BOTTOM = 8
const TA_BASELINE = 24
const TA_RTLREADING = 256
const TA_MASK = ((TA_BASELINE + TA_CENTER) + TA_UPDATECP) + TA_RTLREADING
const VTA_BASELINE = TA_BASELINE
const VTA_LEFT = TA_BOTTOM
const VTA_RIGHT = TA_TOP
const VTA_CENTER = TA_CENTER
const VTA_BOTTOM = TA_RIGHT
const VTA_TOP = TA_LEFT
const ETO_OPAQUE = &h0002
const ETO_CLIPPED = &h0004
const ETO_GLYPH_INDEX = &h0010
const ETO_RTLREADING = &h0080
const ETO_NUMERICSLOCAL = &h0400
const ETO_NUMERICSLATIN = &h0800
const ETO_IGNORELANGUAGE = &h1000
const ETO_PDY = &h2000

#if _WIN32_WINNT >= &h0600
	const ETO_REVERSE_INDEX_MAP = &h10000
#endif

const ASPECT_FILTERING = &h0001
const DCB_RESET = &h0001
const DCB_ACCUMULATE = &h0002
const DCB_DIRTY = DCB_ACCUMULATE
const DCB_SET = DCB_RESET or DCB_ACCUMULATE
const DCB_ENABLE = &h0004
const DCB_DISABLE = &h0008
const META_SETBKCOLOR = &h0201
const META_SETBKMODE = &h0102
const META_SETMAPMODE = &h0103
const META_SETROP2 = &h0104
const META_SETRELABS = &h0105
const META_SETPOLYFILLMODE = &h0106
const META_SETSTRETCHBLTMODE = &h0107
const META_SETTEXTCHAREXTRA = &h0108
const META_SETTEXTCOLOR = &h0209
const META_SETTEXTJUSTIFICATION = &h020A
const META_SETWINDOWORG = &h020B
const META_SETWINDOWEXT = &h020C
const META_SETVIEWPORTORG = &h020D
const META_SETVIEWPORTEXT = &h020E
const META_OFFSETWINDOWORG = &h020F
const META_SCALEWINDOWEXT = &h0410
const META_OFFSETVIEWPORTORG = &h0211
const META_SCALEVIEWPORTEXT = &h0412
const META_LINETO = &h0213
const META_MOVETO = &h0214
const META_EXCLUDECLIPRECT = &h0415
const META_INTERSECTCLIPRECT = &h0416
const META_ARC = &h0817
const META_ELLIPSE = &h0418
const META_FLOODFILL = &h0419
const META_PIE = &h081A
const META_RECTANGLE = &h041B
const META_ROUNDRECT = &h061C
const META_PATBLT = &h061D
const META_SAVEDC = &h001E
const META_SETPIXEL = &h041F
const META_OFFSETCLIPRGN = &h0220
const META_TEXTOUT = &h0521
const META_BITBLT = &h0922
const META_STRETCHBLT = &h0B23
const META_POLYGON = &h0324
const META_POLYLINE = &h0325
const META_ESCAPE = &h0626
const META_RESTOREDC = &h0127
const META_FILLREGION = &h0228
const META_FRAMEREGION = &h0429
const META_INVERTREGION = &h012A
const META_PAINTREGION = &h012B
const META_SELECTCLIPREGION = &h012C
const META_SELECTOBJECT = &h012D
const META_SETTEXTALIGN = &h012E
const META_CHORD = &h0830
const META_SETMAPPERFLAGS = &h0231
const META_EXTTEXTOUT = &h0a32
const META_SETDIBTODEV = &h0d33
const META_SELECTPALETTE = &h0234
const META_REALIZEPALETTE = &h0035
const META_ANIMATEPALETTE = &h0436
const META_SETPALENTRIES = &h0037
const META_POLYPOLYGON = &h0538
const META_RESIZEPALETTE = &h0139
const META_DIBBITBLT = &h0940
const META_DIBSTRETCHBLT = &h0b41
const META_DIBCREATEPATTERNBRUSH = &h0142
const META_STRETCHDIB = &h0f43
const META_EXTFLOODFILL = &h0548
const META_SETLAYOUT = &h0149
const META_DELETEOBJECT = &h01f0
const META_CREATEPALETTE = &h00f7
const META_CREATEPATTERNBRUSH = &h01F9
const META_CREATEPENINDIRECT = &h02FA
const META_CREATEFONTINDIRECT = &h02FB
const META_CREATEBRUSHINDIRECT = &h02FC
const META_CREATEREGION = &h06FF

type _DRAWPATRECT
	ptPosition as POINT
	ptSize as POINT
	wStyle as WORD
	wPattern as WORD
end type

type DRAWPATRECT as _DRAWPATRECT
type PDRAWPATRECT as _DRAWPATRECT ptr
const NEWFRAME = 1
const ABORTDOC_ = 2
const NEXTBAND = 3
const SETCOLORTABLE = 4
const GETCOLORTABLE = 5
const FLUSHOUTPUT = 6
const DRAFTMODE = 7
const QUERYESCSUPPORT = 8
const SETABORTPROC_ = 9
const STARTDOC_ = 10
const ENDDOC_ = 11
const GETPHYSPAGESIZE = 12
const GETPRINTINGOFFSET = 13
const GETSCALINGFACTOR = 14
const MFCOMMENT = 15
const GETPENWIDTH = 16
const SETCOPYCOUNT = 17
const SELECTPAPERSOURCE = 18
const DEVICEDATA = 19
const PASSTHROUGH = 19
const GETTECHNOLGY = 20
const GETTECHNOLOGY = 20
const SETLINECAP = 21
const SETLINEJOIN = 22
const SETMITERLIMIT_ = 23
const BANDINFO = 24
const DRAWPATTERNRECT = 25
const GETVECTORPENSIZE = 26
const GETVECTORBRUSHSIZE = 27
const ENABLEDUPLEX = 28
const GETSETPAPERBINS = 29
const GETSETPRINTORIENT = 30
const ENUMPAPERBINS = 31
const SETDIBSCALING = 32
const EPSPRINTING = 33
const ENUMPAPERMETRICS = 34
const GETSETPAPERMETRICS = 35
const POSTSCRIPT_DATA = 37
const POSTSCRIPT_IGNORE = 38
const MOUSETRAILS = 39
const GETDEVICEUNITS = 42
const GETEXTENDEDTEXTMETRICS = 256
const GETEXTENTTABLE = 257
const GETPAIRKERNTABLE = 258
const GETTRACKKERNTABLE = 259
const EXTTEXTOUT_ = 512
const GETFACENAME = 513
const DOWNLOADFACE = 514
const ENABLERELATIVEWIDTHS = 768
const ENABLEPAIRKERNING = 769
const SETKERNTRACK = 770
const SETALLJUSTVALUES = 771
const SETCHARSET = 772
const STRETCHBLT_ = 2048
const METAFILE_DRIVER = 2049
const GETSETSCREENPARAMS = 3072
const QUERYDIBSUPPORT = 3073
const BEGIN_PATH = 4096
const CLIP_TO_PATH = 4097
const END_PATH = 4098
const EXT_DEVICE_CAPS = 4099
const RESTORE_CTM = 4100
const SAVE_CTM = 4101
const SET_ARC_DIRECTION = 4102
const SET_BACKGROUND_COLOR = 4103
const SET_POLY_MODE = 4104
const SET_SCREEN_ANGLE = 4105
const SET_SPREAD = 4106
const TRANSFORM_CTM = 4107
const SET_CLIP_BOX = 4108
const SET_BOUNDS = 4109
const SET_MIRROR_MODE = 4110
const OPENCHANNEL = 4110
const DOWNLOADHEADER = 4111
const CLOSECHANNEL = 4112
const POSTSCRIPT_PASSTHROUGH = 4115
const ENCAPSULATED_POSTSCRIPT = 4116
const POSTSCRIPT_IDENTIFY = 4117
const POSTSCRIPT_INJECTION = 4118
const CHECKJPEGFORMAT = 4119
const CHECKPNGFORMAT = 4120
const GET_PS_FEATURESETTING = 4121
const GDIPLUS_TS_QUERYVER = 4122
const GDIPLUS_TS_RECORD = 4123

#if _WIN32_WINNT >= &h0600
	const MILCORE_TS_QUERYVER_RESULT_FALSE = &h0
	const MILCORE_TS_QUERYVER_RESULT_TRUE = &h7FFFFFFF
#endif

const SPCLPASSTHROUGH2 = 4568
const PSIDENT_GDICENTRIC = 0
const PSIDENT_PSCENTRIC = 1

type _PSINJECTDATA
	DataBytes as DWORD
	InjectionPoint as WORD
	PageNumber as WORD
end type

type PSINJECTDATA as _PSINJECTDATA
type PPSINJECTDATA as _PSINJECTDATA ptr
const PSINJECT_BEGINSTREAM = 1
const PSINJECT_PSADOBE = 2
const PSINJECT_PAGESATEND = 3
const PSINJECT_PAGES = 4
const PSINJECT_DOCNEEDEDRES = 5
const PSINJECT_DOCSUPPLIEDRES = 6
const PSINJECT_PAGEORDER = 7
const PSINJECT_ORIENTATION = 8
const PSINJECT_BOUNDINGBOX = 9
const PSINJECT_DOCUMENTPROCESSCOLORS = 10
const PSINJECT_COMMENTS = 11
const PSINJECT_BEGINDEFAULTS = 12
const PSINJECT_ENDDEFAULTS = 13
const PSINJECT_BEGINPROLOG = 14
const PSINJECT_ENDPROLOG = 15
const PSINJECT_BEGINSETUP = 16
const PSINJECT_ENDSETUP = 17
const PSINJECT_TRAILER = 18
const PSINJECT_EOF = 19
const PSINJECT_ENDSTREAM = 20
const PSINJECT_DOCUMENTPROCESSCOLORSATEND = 21
const PSINJECT_PAGENUMBER = 100
const PSINJECT_BEGINPAGESETUP = 101
const PSINJECT_ENDPAGESETUP = 102
const PSINJECT_PAGETRAILER = 103
const PSINJECT_PLATECOLOR = 104
const PSINJECT_SHOWPAGE = 105
const PSINJECT_PAGEBBOX = 106
const PSINJECT_ENDPAGECOMMENTS = 107
const PSINJECT_VMSAVE = 200
const PSINJECT_VMRESTORE = 201
const FEATURESETTING_NUP = 0
const FEATURESETTING_OUTPUT = 1
const FEATURESETTING_PSLEVEL = 2
const FEATURESETTING_CUSTPAPER = 3
const FEATURESETTING_MIRROR = 4
const FEATURESETTING_NEGATIVE = 5
const FEATURESETTING_PROTOCOL = 6
const FEATURESETTING_PRIVATE_BEGIN = &h1000
const FEATURESETTING_PRIVATE_END = &h1FFF

type _PSFEATURE_OUTPUT
	bPageIndependent as WINBOOL
	bSetPageDevice as WINBOOL
end type

type PSFEATURE_OUTPUT as _PSFEATURE_OUTPUT
type PPSFEATURE_OUTPUT as _PSFEATURE_OUTPUT ptr

type _PSFEATURE_CUSTPAPER
	lOrientation as LONG
	lWidth as LONG
	lHeight as LONG
	lWidthOffset as LONG
	lHeightOffset as LONG
end type

type PSFEATURE_CUSTPAPER as _PSFEATURE_CUSTPAPER
type PPSFEATURE_CUSTPAPER as _PSFEATURE_CUSTPAPER ptr
const PSPROTOCOL_ASCII = 0
const PSPROTOCOL_BCP = 1
const PSPROTOCOL_TBCP = 2
const PSPROTOCOL_BINARY = 3
const QDI_SETDIBITS = 1
const QDI_GETDIBITS = 2
const QDI_DIBTOSCREEN = 4
const QDI_STRETCHDIB = 8
const SP_NOTREPORTED = &h4000
const SP_ERROR = -1
const SP_APPABORT = -2
const SP_USERABORT = -3
const SP_OUTOFDISK = -4
const SP_OUTOFMEMORY = -5
const PR_JOBSTATUS = &h0000
const OBJ_PEN = 1
const OBJ_BRUSH = 2
const OBJ_DC = 3
const OBJ_METADC = 4
const OBJ_PAL = 5
const OBJ_FONT = 6
const OBJ_BITMAP = 7
const OBJ_REGION = 8
const OBJ_METAFILE = 9
const OBJ_MEMDC = 10
const OBJ_EXTPEN = 11
const OBJ_ENHMETADC = 12
const OBJ_ENHMETAFILE = 13
const OBJ_COLORSPACE = 14
const GDI_OBJ_LAST = OBJ_COLORSPACE
const MWT_IDENTITY = 1
const MWT_LEFTMULTIPLY = 2
const MWT_RIGHTMULTIPLY = 3
const MWT_MIN = MWT_IDENTITY
const MWT_MAX = MWT_RIGHTMULTIPLY
#define _XFORM_

type tagXFORM
	eM11 as FLOAT
	eM12 as FLOAT
	eM21 as FLOAT
	eM22 as FLOAT
	eDx as FLOAT
	eDy as FLOAT
end type

type XFORM as tagXFORM
type PXFORM as tagXFORM ptr
type LPXFORM as tagXFORM ptr

type tagBITMAP
	bmType as LONG
	bmWidth as LONG
	bmHeight as LONG
	bmWidthBytes as LONG
	bmPlanes as WORD
	bmBitsPixel as WORD
	bmBits as LPVOID
end type

type BITMAP as tagBITMAP
type PBITMAP as tagBITMAP ptr
type NPBITMAP as tagBITMAP ptr
type LPBITMAP as tagBITMAP ptr

type tagRGBTRIPLE field = 1
	rgbtBlue as UBYTE
	rgbtGreen as UBYTE
	rgbtRed as UBYTE
end type

type RGBTRIPLE as tagRGBTRIPLE

type tagRGBQUAD
	rgbBlue as UBYTE
	rgbGreen as UBYTE
	rgbRed as UBYTE
	rgbReserved as UBYTE
end type

type RGBQUAD as tagRGBQUAD
type LPRGBQUAD as RGBQUAD ptr
const CS_ENABLE = &h00000001
const CS_DISABLE = &h00000002
const CS_DELETE_TRANSFORM = &h00000003
#define LCS_SIGNATURE asc("PSOC")
#define LCS_sRGB asc("sRGB")
#define LCS_WINDOWS_COLOR_SPACE asc("Win ")
type LCSCSTYPE as LONG
const LCS_CALIBRATED_RGB = &h00000000
type LCSGAMUTMATCH as LONG
const LCS_GM_BUSINESS = &h00000001
const LCS_GM_GRAPHICS = &h00000002
const LCS_GM_IMAGES = &h00000004
const LCS_GM_ABS_COLORIMETRIC = &h00000008
const CM_OUT_OF_GAMUT = 255
const CM_IN_GAMUT = 0
const ICM_ADDPROFILE = 1
const ICM_DELETEPROFILE = 2
const ICM_QUERYPROFILE = 3
const ICM_SETDEFAULTPROFILE = 4
const ICM_REGISTERICMATCHER = 5
const ICM_UNREGISTERICMATCHER = 6
const ICM_QUERYMATCH = 7
#define GetKValue(cmyk) cast(UBYTE, (cmyk))
#define GetYValue(cmyk) cast(UBYTE, (cmyk) shr 8)
#define GetMValue(cmyk) cast(UBYTE, (cmyk) shr 16)
#define GetCValue(cmyk) cast(UBYTE, (cmyk) shr 24)
#define CMYK(c, m, y, k) cast(COLORREF, ((cast(UBYTE, (k)) or (cast(WORD, cast(UBYTE, (y))) shl 8)) or (cast(DWORD, cast(UBYTE, (m))) shl 16)) or (cast(DWORD, cast(UBYTE, (c))) shl 24))

type FXPT16DOT16 as long
type LPFXPT16DOT16 as long ptr
type FXPT2DOT30 as long
type LPFXPT2DOT30 as long ptr

type tagCIEXYZ
	ciexyzX as FXPT2DOT30
	ciexyzY as FXPT2DOT30
	ciexyzZ as FXPT2DOT30
end type

type CIEXYZ as tagCIEXYZ
type LPCIEXYZ as CIEXYZ ptr

type tagICEXYZTRIPLE
	ciexyzRed as CIEXYZ
	ciexyzGreen as CIEXYZ
	ciexyzBlue as CIEXYZ
end type

type CIEXYZTRIPLE as tagICEXYZTRIPLE
type LPCIEXYZTRIPLE as CIEXYZTRIPLE ptr

type tagLOGCOLORSPACEA
	lcsSignature as DWORD
	lcsVersion as DWORD
	lcsSize as DWORD
	lcsCSType as LCSCSTYPE
	lcsIntent as LCSGAMUTMATCH
	lcsEndpoints as CIEXYZTRIPLE
	lcsGammaRed as DWORD
	lcsGammaGreen as DWORD
	lcsGammaBlue as DWORD
	lcsFilename as zstring * 260
end type

type LOGCOLORSPACEA as tagLOGCOLORSPACEA
type LPLOGCOLORSPACEA as tagLOGCOLORSPACEA ptr

type tagLOGCOLORSPACEW
	lcsSignature as DWORD
	lcsVersion as DWORD
	lcsSize as DWORD
	lcsCSType as LCSCSTYPE
	lcsIntent as LCSGAMUTMATCH
	lcsEndpoints as CIEXYZTRIPLE
	lcsGammaRed as DWORD
	lcsGammaGreen as DWORD
	lcsGammaBlue as DWORD
	lcsFilename as wstring * 260
end type

type LOGCOLORSPACEW as tagLOGCOLORSPACEW
type LPLOGCOLORSPACEW as tagLOGCOLORSPACEW ptr

#ifdef UNICODE
	type LOGCOLORSPACE as LOGCOLORSPACEW
	type LPLOGCOLORSPACE as LPLOGCOLORSPACEW
#else
	type LOGCOLORSPACE as LOGCOLORSPACEA
	type LPLOGCOLORSPACE as LPLOGCOLORSPACEA
#endif

type tagBITMAPCOREHEADER
	bcSize as DWORD
	bcWidth as WORD
	bcHeight as WORD
	bcPlanes as WORD
	bcBitCount as WORD
end type

type BITMAPCOREHEADER as tagBITMAPCOREHEADER
type LPBITMAPCOREHEADER as tagBITMAPCOREHEADER ptr
type PBITMAPCOREHEADER as tagBITMAPCOREHEADER ptr

type tagBITMAPINFOHEADER
	biSize as DWORD
	biWidth as LONG
	biHeight as LONG
	biPlanes as WORD
	biBitCount as WORD
	biCompression as DWORD
	biSizeImage as DWORD
	biXPelsPerMeter as LONG
	biYPelsPerMeter as LONG
	biClrUsed as DWORD
	biClrImportant as DWORD
end type

type BITMAPINFOHEADER as tagBITMAPINFOHEADER
type LPBITMAPINFOHEADER as tagBITMAPINFOHEADER ptr
type PBITMAPINFOHEADER as tagBITMAPINFOHEADER ptr

type BITMAPV4HEADER
	bV4Size as DWORD
	bV4Width as LONG
	bV4Height as LONG
	bV4Planes as WORD
	bV4BitCount as WORD
	bV4V4Compression as DWORD
	bV4SizeImage as DWORD
	bV4XPelsPerMeter as LONG
	bV4YPelsPerMeter as LONG
	bV4ClrUsed as DWORD
	bV4ClrImportant as DWORD
	bV4RedMask as DWORD
	bV4GreenMask as DWORD
	bV4BlueMask as DWORD
	bV4AlphaMask as DWORD
	bV4CSType as DWORD
	bV4Endpoints as CIEXYZTRIPLE
	bV4GammaRed as DWORD
	bV4GammaGreen as DWORD
	bV4GammaBlue as DWORD
end type

type LPBITMAPV4HEADER as BITMAPV4HEADER ptr
type PBITMAPV4HEADER as BITMAPV4HEADER ptr

type BITMAPV5HEADER
	bV5Size as DWORD
	bV5Width as LONG
	bV5Height as LONG
	bV5Planes as WORD
	bV5BitCount as WORD
	bV5Compression as DWORD
	bV5SizeImage as DWORD
	bV5XPelsPerMeter as LONG
	bV5YPelsPerMeter as LONG
	bV5ClrUsed as DWORD
	bV5ClrImportant as DWORD
	bV5RedMask as DWORD
	bV5GreenMask as DWORD
	bV5BlueMask as DWORD
	bV5AlphaMask as DWORD
	bV5CSType as DWORD
	bV5Endpoints as CIEXYZTRIPLE
	bV5GammaRed as DWORD
	bV5GammaGreen as DWORD
	bV5GammaBlue as DWORD
	bV5Intent as DWORD
	bV5ProfileData as DWORD
	bV5ProfileSize as DWORD
	bV5Reserved as DWORD
end type

type LPBITMAPV5HEADER as BITMAPV5HEADER ptr
type PBITMAPV5HEADER as BITMAPV5HEADER ptr
#define PROFILE_LINKED asc("LINK")
#define PROFILE_EMBEDDED asc("MBED")
const BI_RGB = 0
const BI_RLE8 = 1
const BI_RLE4 = 2
const BI_BITFIELDS = 3
const BI_JPEG = 4
const BI_PNG = 5

type tagBITMAPINFO
	bmiHeader as BITMAPINFOHEADER
	bmiColors(0 to 0) as RGBQUAD
end type

type BITMAPINFO as tagBITMAPINFO
type LPBITMAPINFO as tagBITMAPINFO ptr
type PBITMAPINFO as tagBITMAPINFO ptr

type tagBITMAPCOREINFO
	bmciHeader as BITMAPCOREHEADER
	bmciColors(0 to 0) as RGBTRIPLE
end type

type BITMAPCOREINFO as tagBITMAPCOREINFO
type LPBITMAPCOREINFO as tagBITMAPCOREINFO ptr
type PBITMAPCOREINFO as tagBITMAPCOREINFO ptr

type tagBITMAPFILEHEADER field = 2
	bfType as WORD
	bfSize as DWORD
	bfReserved1 as WORD
	bfReserved2 as WORD
	bfOffBits as DWORD
end type

type BITMAPFILEHEADER as tagBITMAPFILEHEADER
type LPBITMAPFILEHEADER as tagBITMAPFILEHEADER ptr
type PBITMAPFILEHEADER as tagBITMAPFILEHEADER ptr
#define MAKEPOINTS(l) (*cptr(POINTS ptr, @(l)))

type tagFONTSIGNATURE
	fsUsb(0 to 3) as DWORD
	fsCsb(0 to 1) as DWORD
end type

type FONTSIGNATURE as tagFONTSIGNATURE
type PFONTSIGNATURE as tagFONTSIGNATURE ptr
type LPFONTSIGNATURE as tagFONTSIGNATURE ptr

type tagCHARSETINFO
	ciCharset as UINT
	ciACP as UINT
	fs as FONTSIGNATURE
end type

type CHARSETINFO as tagCHARSETINFO
type PCHARSETINFO as tagCHARSETINFO ptr
type NPCHARSETINFO as tagCHARSETINFO ptr
type LPCHARSETINFO as tagCHARSETINFO ptr

const TCI_SRCCHARSET = 1
const TCI_SRCCODEPAGE = 2
const TCI_SRCFONTSIG = 3
const TCI_SRCLOCALE = &h1000

type tagLOCALESIGNATURE
	lsUsb(0 to 3) as DWORD
	lsCsbDefault(0 to 1) as DWORD
	lsCsbSupported(0 to 1) as DWORD
end type

type LOCALESIGNATURE as tagLOCALESIGNATURE
type PLOCALESIGNATURE as tagLOCALESIGNATURE ptr
type LPLOCALESIGNATURE as tagLOCALESIGNATURE ptr

type tagHANDLETABLE
	objectHandle(0 to 0) as HGDIOBJ
end type

type HANDLETABLE as tagHANDLETABLE
type PHANDLETABLE as tagHANDLETABLE ptr
type LPHANDLETABLE as tagHANDLETABLE ptr

type tagMETARECORD
	rdSize as DWORD
	rdFunction as WORD
	rdParm(0 to 0) as WORD
end type

type METARECORD as tagMETARECORD
type PMETARECORD as tagMETARECORD ptr
type LPMETARECORD as tagMETARECORD ptr

type tagMETAFILEPICT
	mm as LONG
	xExt as LONG
	yExt as LONG
	hMF as HMETAFILE
end type

type METAFILEPICT as tagMETAFILEPICT
type LPMETAFILEPICT as tagMETAFILEPICT ptr

type tagMETAHEADER field = 2
	mtType as WORD
	mtHeaderSize as WORD
	mtVersion as WORD
	mtSize as DWORD
	mtNoObjects as WORD
	mtMaxRecord as DWORD
	mtNoParameters as WORD
end type

type METAHEADER as tagMETAHEADER
type PMETAHEADER as tagMETAHEADER ptr
type LPMETAHEADER as tagMETAHEADER ptr

type tagENHMETARECORD
	iType as DWORD
	nSize as DWORD
	dParm(0 to 0) as DWORD
end type

type ENHMETARECORD as tagENHMETARECORD
type PENHMETARECORD as tagENHMETARECORD ptr
type LPENHMETARECORD as tagENHMETARECORD ptr

type tagENHMETAHEADER
	iType as DWORD
	nSize as DWORD
	rclBounds as RECTL
	rclFrame as RECTL
	dSignature as DWORD
	nVersion as DWORD
	nBytes as DWORD
	nRecords as DWORD
	nHandles as WORD
	sReserved as WORD
	nDescription as DWORD
	offDescription as DWORD
	nPalEntries as DWORD
	szlDevice as SIZEL
	szlMillimeters as SIZEL
	cbPixelFormat as DWORD
	offPixelFormat as DWORD
	bOpenGL as DWORD
	szlMicrometers as SIZEL
end type

type ENHMETAHEADER as tagENHMETAHEADER
type PENHMETAHEADER as tagENHMETAHEADER ptr
type LPENHMETAHEADER as tagENHMETAHEADER ptr

const TMPF_FIXED_PITCH = &h01
const TMPF_VECTOR = &h02
const TMPF_DEVICE = &h08
const TMPF_TRUETYPE = &h04

#ifdef UNICODE
	type BCHAR as WCHAR
#else
	type BCHAR as UBYTE
#endif

#define _TEXTMETRIC_DEFINED

type tagTEXTMETRICA field = 4
	tmHeight as LONG
	tmAscent as LONG
	tmDescent as LONG
	tmInternalLeading as LONG
	tmExternalLeading as LONG
	tmAveCharWidth as LONG
	tmMaxCharWidth as LONG
	tmWeight as LONG
	tmOverhang as LONG
	tmDigitizedAspectX as LONG
	tmDigitizedAspectY as LONG
	tmFirstChar as UBYTE
	tmLastChar as UBYTE
	tmDefaultChar as UBYTE
	tmBreakChar as UBYTE
	tmItalic as UBYTE
	tmUnderlined as UBYTE
	tmStruckOut as UBYTE
	tmPitchAndFamily as UBYTE
	tmCharSet as UBYTE
end type

type TEXTMETRICA as tagTEXTMETRICA
type PTEXTMETRICA as tagTEXTMETRICA ptr
type NPTEXTMETRICA as tagTEXTMETRICA ptr
type LPTEXTMETRICA as tagTEXTMETRICA ptr

type tagTEXTMETRICW field = 4
	tmHeight as LONG
	tmAscent as LONG
	tmDescent as LONG
	tmInternalLeading as LONG
	tmExternalLeading as LONG
	tmAveCharWidth as LONG
	tmMaxCharWidth as LONG
	tmWeight as LONG
	tmOverhang as LONG
	tmDigitizedAspectX as LONG
	tmDigitizedAspectY as LONG
	tmFirstChar as WCHAR
	tmLastChar as WCHAR
	tmDefaultChar as WCHAR
	tmBreakChar as WCHAR
	tmItalic as UBYTE
	tmUnderlined as UBYTE
	tmStruckOut as UBYTE
	tmPitchAndFamily as UBYTE
	tmCharSet as UBYTE
end type

type TEXTMETRICW as tagTEXTMETRICW
type PTEXTMETRICW as tagTEXTMETRICW ptr
type NPTEXTMETRICW as tagTEXTMETRICW ptr
type LPTEXTMETRICW as tagTEXTMETRICW ptr

#ifdef UNICODE
	type TEXTMETRIC as TEXTMETRICW
	type PTEXTMETRIC as PTEXTMETRICW
	type NPTEXTMETRIC as NPTEXTMETRICW
	type LPTEXTMETRIC as LPTEXTMETRICW
#else
	type TEXTMETRIC as TEXTMETRICA
	type PTEXTMETRIC as PTEXTMETRICA
	type NPTEXTMETRIC as NPTEXTMETRICA
	type LPTEXTMETRIC as LPTEXTMETRICA
#endif

const NTM_REGULAR = &h00000040
const NTM_BOLD = &h00000020
const NTM_ITALIC = &h00000001
const NTM_NONNEGATIVE_AC = &h00010000
const NTM_PS_OPENTYPE = &h00020000
const NTM_TT_OPENTYPE = &h00040000
const NTM_MULTIPLEMASTER = &h00080000
const NTM_TYPE1 = &h00100000
const NTM_DSIG = &h00200000

type tagNEWTEXTMETRICA field = 4
	tmHeight as LONG
	tmAscent as LONG
	tmDescent as LONG
	tmInternalLeading as LONG
	tmExternalLeading as LONG
	tmAveCharWidth as LONG
	tmMaxCharWidth as LONG
	tmWeight as LONG
	tmOverhang as LONG
	tmDigitizedAspectX as LONG
	tmDigitizedAspectY as LONG
	tmFirstChar as UBYTE
	tmLastChar as UBYTE
	tmDefaultChar as UBYTE
	tmBreakChar as UBYTE
	tmItalic as UBYTE
	tmUnderlined as UBYTE
	tmStruckOut as UBYTE
	tmPitchAndFamily as UBYTE
	tmCharSet as UBYTE
	ntmFlags as DWORD
	ntmSizeEM as UINT
	ntmCellHeight as UINT
	ntmAvgWidth as UINT
end type

type NEWTEXTMETRICA as tagNEWTEXTMETRICA
type PNEWTEXTMETRICA as tagNEWTEXTMETRICA ptr
type NPNEWTEXTMETRICA as tagNEWTEXTMETRICA ptr
type LPNEWTEXTMETRICA as tagNEWTEXTMETRICA ptr

type tagNEWTEXTMETRICW field = 4
	tmHeight as LONG
	tmAscent as LONG
	tmDescent as LONG
	tmInternalLeading as LONG
	tmExternalLeading as LONG
	tmAveCharWidth as LONG
	tmMaxCharWidth as LONG
	tmWeight as LONG
	tmOverhang as LONG
	tmDigitizedAspectX as LONG
	tmDigitizedAspectY as LONG
	tmFirstChar as WCHAR
	tmLastChar as WCHAR
	tmDefaultChar as WCHAR
	tmBreakChar as WCHAR
	tmItalic as UBYTE
	tmUnderlined as UBYTE
	tmStruckOut as UBYTE
	tmPitchAndFamily as UBYTE
	tmCharSet as UBYTE
	ntmFlags as DWORD
	ntmSizeEM as UINT
	ntmCellHeight as UINT
	ntmAvgWidth as UINT
end type

type NEWTEXTMETRICW as tagNEWTEXTMETRICW
type PNEWTEXTMETRICW as tagNEWTEXTMETRICW ptr
type NPNEWTEXTMETRICW as tagNEWTEXTMETRICW ptr
type LPNEWTEXTMETRICW as tagNEWTEXTMETRICW ptr

#ifdef UNICODE
	type NEWTEXTMETRIC as NEWTEXTMETRICW
	type PNEWTEXTMETRIC as PNEWTEXTMETRICW
	type NPNEWTEXTMETRIC as NPNEWTEXTMETRICW
	type LPNEWTEXTMETRIC as LPNEWTEXTMETRICW
#else
	type NEWTEXTMETRIC as NEWTEXTMETRICA
	type PNEWTEXTMETRIC as PNEWTEXTMETRICA
	type NPNEWTEXTMETRIC as NPNEWTEXTMETRICA
	type LPNEWTEXTMETRIC as LPNEWTEXTMETRICA
#endif

type tagNEWTEXTMETRICEXA
	ntmTm as NEWTEXTMETRICA
	ntmFontSig as FONTSIGNATURE
end type

type NEWTEXTMETRICEXA as tagNEWTEXTMETRICEXA

type tagNEWTEXTMETRICEXW
	ntmTm as NEWTEXTMETRICW
	ntmFontSig as FONTSIGNATURE
end type

type NEWTEXTMETRICEXW as tagNEWTEXTMETRICEXW

#ifdef UNICODE
	type NEWTEXTMETRICEX as NEWTEXTMETRICEXW
#else
	type NEWTEXTMETRICEX as NEWTEXTMETRICEXA
#endif

type tagPELARRAY
	paXCount as LONG
	paYCount as LONG
	paXExt as LONG
	paYExt as LONG
	paRGBs as UBYTE
end type

type PELARRAY as tagPELARRAY
type PPELARRAY as tagPELARRAY ptr
type NPPELARRAY as tagPELARRAY ptr
type LPPELARRAY as tagPELARRAY ptr

type tagLOGBRUSH
	lbStyle as UINT
	lbColor as COLORREF
	lbHatch as ULONG_PTR
end type

type LOGBRUSH as tagLOGBRUSH
type PLOGBRUSH as tagLOGBRUSH ptr
type NPLOGBRUSH as tagLOGBRUSH ptr
type LPLOGBRUSH as tagLOGBRUSH ptr

type tagLOGBRUSH32
	lbStyle as UINT
	lbColor as COLORREF
	lbHatch as ULONG
end type

type LOGBRUSH32 as tagLOGBRUSH32
type PLOGBRUSH32 as tagLOGBRUSH32 ptr
type NPLOGBRUSH32 as tagLOGBRUSH32 ptr
type LPLOGBRUSH32 as tagLOGBRUSH32 ptr
type PATTERN as LOGBRUSH
type PPATTERN as PATTERN ptr
type NPPATTERN as PATTERN ptr
type LPPATTERN as PATTERN ptr

type tagLOGPEN
	lopnStyle as UINT
	lopnWidth as POINT
	lopnColor as COLORREF
end type

type LOGPEN as tagLOGPEN
type PLOGPEN as tagLOGPEN ptr
type NPLOGPEN as tagLOGPEN ptr
type LPLOGPEN as tagLOGPEN ptr

type tagEXTLOGPEN
	elpPenStyle as DWORD
	elpWidth as DWORD
	elpBrushStyle as UINT
	elpColor as COLORREF
	elpHatch as ULONG_PTR
	elpNumEntries as DWORD
	elpStyleEntry(0 to 0) as DWORD
end type

type EXTLOGPEN as tagEXTLOGPEN
type PEXTLOGPEN as tagEXTLOGPEN ptr
type NPEXTLOGPEN as tagEXTLOGPEN ptr
type LPEXTLOGPEN as tagEXTLOGPEN ptr

type tagEXTLOGPEN32
	elpPenStyle as DWORD
	elpWidth as DWORD
	elpBrushStyle as UINT
	elpColor as COLORREF
	elpHatch as ULONG
	elpNumEntries as DWORD
	elpStyleEntry(0 to 0) as DWORD
end type

type EXTLOGPEN32 as tagEXTLOGPEN32
type PEXTLOGPEN32 as tagEXTLOGPEN32 ptr
type NPEXTLOGPEN32 as tagEXTLOGPEN32 ptr
type LPEXTLOGPEN32 as tagEXTLOGPEN32 ptr
#define _PALETTEENTRY_DEFINED

type tagPALETTEENTRY
	peRed as UBYTE
	peGreen as UBYTE
	peBlue as UBYTE
	peFlags as UBYTE
end type

type PALETTEENTRY as tagPALETTEENTRY
type PPALETTEENTRY as tagPALETTEENTRY ptr
type LPPALETTEENTRY as tagPALETTEENTRY ptr
#define _LOGPALETTE_DEFINED

type tagLOGPALETTE
	palVersion as WORD
	palNumEntries as WORD
	palPalEntry(0 to 0) as PALETTEENTRY
end type

type LOGPALETTE as tagLOGPALETTE
type PLOGPALETTE as tagLOGPALETTE ptr
type NPLOGPALETTE as tagLOGPALETTE ptr
type LPLOGPALETTE as tagLOGPALETTE ptr
const LF_FACESIZE = 32

type tagLOGFONTA
	lfHeight as LONG
	lfWidth as LONG
	lfEscapement as LONG
	lfOrientation as LONG
	lfWeight as LONG
	lfItalic as UBYTE
	lfUnderline as UBYTE
	lfStrikeOut as UBYTE
	lfCharSet as UBYTE
	lfOutPrecision as UBYTE
	lfClipPrecision as UBYTE
	lfQuality as UBYTE
	lfPitchAndFamily as UBYTE
	lfFaceName as zstring * 32
end type

type LOGFONTA as tagLOGFONTA
type PLOGFONTA as tagLOGFONTA ptr
type NPLOGFONTA as tagLOGFONTA ptr
type LPLOGFONTA as tagLOGFONTA ptr

type tagLOGFONTW
	lfHeight as LONG
	lfWidth as LONG
	lfEscapement as LONG
	lfOrientation as LONG
	lfWeight as LONG
	lfItalic as UBYTE
	lfUnderline as UBYTE
	lfStrikeOut as UBYTE
	lfCharSet as UBYTE
	lfOutPrecision as UBYTE
	lfClipPrecision as UBYTE
	lfQuality as UBYTE
	lfPitchAndFamily as UBYTE
	lfFaceName as wstring * 32
end type

type LOGFONTW as tagLOGFONTW
type PLOGFONTW as tagLOGFONTW ptr
type NPLOGFONTW as tagLOGFONTW ptr
type LPLOGFONTW as tagLOGFONTW ptr

#ifdef UNICODE
	type LOGFONT as LOGFONTW
	type PLOGFONT as PLOGFONTW
	type NPLOGFONT as NPLOGFONTW
	type LPLOGFONT as LPLOGFONTW
#else
	type LOGFONT as LOGFONTA
	type PLOGFONT as PLOGFONTA
	type NPLOGFONT as NPLOGFONTA
	type LPLOGFONT as LPLOGFONTA
#endif

const LF_FULLFACESIZE = 64

type tagENUMLOGFONTA
	elfLogFont as LOGFONTA
	elfFullName as zstring * 64
	elfStyle as zstring * 32
end type

type ENUMLOGFONTA as tagENUMLOGFONTA
type LPENUMLOGFONTA as tagENUMLOGFONTA ptr

type tagENUMLOGFONTW
	elfLogFont as LOGFONTW
	elfFullName as wstring * 64
	elfStyle as wstring * 32
end type

type ENUMLOGFONTW as tagENUMLOGFONTW
type LPENUMLOGFONTW as tagENUMLOGFONTW ptr

#ifdef UNICODE
	type ENUMLOGFONT as ENUMLOGFONTW
	type LPENUMLOGFONT as LPENUMLOGFONTW
#else
	type ENUMLOGFONT as ENUMLOGFONTA
	type LPENUMLOGFONT as LPENUMLOGFONTA
#endif

type tagENUMLOGFONTEXA
	elfLogFont as LOGFONTA
	elfFullName as zstring * 64
	elfStyle as zstring * 32
	elfScript as zstring * 32
end type

type ENUMLOGFONTEXA as tagENUMLOGFONTEXA
type LPENUMLOGFONTEXA as tagENUMLOGFONTEXA ptr

type tagENUMLOGFONTEXW
	elfLogFont as LOGFONTW
	elfFullName as wstring * 64
	elfStyle as wstring * 32
	elfScript as wstring * 32
end type

type ENUMLOGFONTEXW as tagENUMLOGFONTEXW
type LPENUMLOGFONTEXW as tagENUMLOGFONTEXW ptr

#ifdef UNICODE
	type ENUMLOGFONTEX as ENUMLOGFONTEXW
	type LPENUMLOGFONTEX as LPENUMLOGFONTEXW
#else
	type ENUMLOGFONTEX as ENUMLOGFONTEXA
	type LPENUMLOGFONTEX as LPENUMLOGFONTEXA
#endif

const OUT_DEFAULT_PRECIS = 0
const OUT_STRING_PRECIS = 1
const OUT_CHARACTER_PRECIS = 2
const OUT_STROKE_PRECIS = 3
const OUT_TT_PRECIS = 4
const OUT_DEVICE_PRECIS = 5
const OUT_RASTER_PRECIS = 6
const OUT_TT_ONLY_PRECIS = 7
const OUT_OUTLINE_PRECIS = 8
const OUT_SCREEN_OUTLINE_PRECIS = 9
const OUT_PS_ONLY_PRECIS = 10
const CLIP_DEFAULT_PRECIS = 0
const CLIP_CHARACTER_PRECIS = 1
const CLIP_STROKE_PRECIS = 2
const CLIP_MASK = &hf
const CLIP_LH_ANGLES = 1 shl 4
const CLIP_TT_ALWAYS = 2 shl 4

#if _WIN32_WINNT >= &h0600
	const CLIP_DFA_DISABLE = 4 shl 4
#endif

const CLIP_EMBEDDED = 8 shl 4
const DEFAULT_QUALITY = 0
const DRAFT_QUALITY = 1
const PROOF_QUALITY = 2
const NONANTIALIASED_QUALITY = 3
const ANTIALIASED_QUALITY = 4
const CLEARTYPE_QUALITY = 5
const CLEARTYPE_NATURAL_QUALITY = 6
const DEFAULT_PITCH = 0
const FIXED_PITCH = 1
const VARIABLE_PITCH = 2
const MONO_FONT = 8
const ANSI_CHARSET = 0
const DEFAULT_CHARSET = 1
const SYMBOL_CHARSET = 2
const SHIFTJIS_CHARSET = 128
const HANGEUL_CHARSET = 129
const HANGUL_CHARSET = 129
const GB2312_CHARSET = 134
const CHINESEBIG5_CHARSET = 136
const OEM_CHARSET = 255
const JOHAB_CHARSET = 130
const HEBREW_CHARSET = 177
const ARABIC_CHARSET = 178
const GREEK_CHARSET = 161
const TURKISH_CHARSET = 162
const VIETNAMESE_CHARSET = 163
const THAI_CHARSET = 222
const EASTEUROPE_CHARSET = 238
const RUSSIAN_CHARSET = 204
const MAC_CHARSET = 77
const BALTIC_CHARSET = 186
const FS_LATIN1 = &h00000001
const FS_LATIN2 = &h00000002
const FS_CYRILLIC = &h00000004
const FS_GREEK = &h00000008
const FS_TURKISH = &h00000010
const FS_HEBREW = &h00000020
const FS_ARABIC = &h00000040
const FS_BALTIC = &h00000080
const FS_VIETNAMESE = &h00000100
const FS_THAI = &h00010000
const FS_JISJAPAN = &h00020000
const FS_CHINESESIMP = &h00040000
const FS_WANSUNG = &h00080000
const FS_CHINESETRAD = &h00100000
const FS_JOHAB = &h00200000
const FS_SYMBOL = &h80000000
const FF_DONTCARE = 0 shl 4
const FF_ROMAN = 1 shl 4
const FF_SWISS = 2 shl 4
const FF_MODERN = 3 shl 4
const FF_SCRIPT = 4 shl 4
const FF_DECORATIVE = 5 shl 4
const FW_DONTCARE = 0
const FW_THIN = 100
const FW_EXTRALIGHT = 200
const FW_LIGHT = 300
const FW_NORMAL = 400
const FW_MEDIUM = 500
const FW_SEMIBOLD = 600
const FW_BOLD = 700
const FW_EXTRABOLD = 800
const FW_HEAVY = 900
const FW_ULTRALIGHT = FW_EXTRALIGHT
const FW_REGULAR = FW_NORMAL
const FW_DEMIBOLD = FW_SEMIBOLD
const FW_ULTRABOLD = FW_EXTRABOLD
const FW_BLACK = FW_HEAVY
const PANOSE_COUNT = 10
const PAN_FAMILYTYPE_INDEX = 0
const PAN_SERIFSTYLE_INDEX = 1
const PAN_WEIGHT_INDEX = 2
const PAN_PROPORTION_INDEX = 3
const PAN_CONTRAST_INDEX = 4
const PAN_STROKEVARIATION_INDEX = 5
const PAN_ARMSTYLE_INDEX = 6
const PAN_LETTERFORM_INDEX = 7
const PAN_MIDLINE_INDEX = 8
const PAN_XHEIGHT_INDEX = 9
const PAN_CULTURE_LATIN = 0

type tagPANOSE
	bFamilyType as UBYTE
	bSerifStyle as UBYTE
	bWeight as UBYTE
	bProportion as UBYTE
	bContrast as UBYTE
	bStrokeVariation as UBYTE
	bArmStyle as UBYTE
	bLetterform as UBYTE
	bMidline as UBYTE
	bXHeight as UBYTE
end type

type PANOSE as tagPANOSE
type LPPANOSE as tagPANOSE ptr
const PAN_ANY = 0
const PAN_NO_FIT = 1
const PAN_FAMILY_TEXT_DISPLAY = 2
const PAN_FAMILY_SCRIPT = 3
const PAN_FAMILY_DECORATIVE = 4
const PAN_FAMILY_PICTORIAL = 5
const PAN_SERIF_COVE = 2
const PAN_SERIF_OBTUSE_COVE = 3
const PAN_SERIF_SQUARE_COVE = 4
const PAN_SERIF_OBTUSE_SQUARE_COVE = 5
const PAN_SERIF_SQUARE = 6
const PAN_SERIF_THIN = 7
const PAN_SERIF_BONE = 8
const PAN_SERIF_EXAGGERATED = 9
const PAN_SERIF_TRIANGLE = 10
const PAN_SERIF_NORMAL_SANS = 11
const PAN_SERIF_OBTUSE_SANS = 12
const PAN_SERIF_PERP_SANS = 13
const PAN_SERIF_FLARED = 14
const PAN_SERIF_ROUNDED = 15
const PAN_WEIGHT_VERY_LIGHT = 2
const PAN_WEIGHT_LIGHT = 3
const PAN_WEIGHT_THIN = 4
const PAN_WEIGHT_BOOK = 5
const PAN_WEIGHT_MEDIUM = 6
const PAN_WEIGHT_DEMI = 7
const PAN_WEIGHT_BOLD = 8
const PAN_WEIGHT_HEAVY = 9
const PAN_WEIGHT_BLACK = 10
const PAN_WEIGHT_NORD = 11
const PAN_PROP_OLD_STYLE = 2
const PAN_PROP_MODERN = 3
const PAN_PROP_EVEN_WIDTH = 4
const PAN_PROP_EXPANDED = 5
const PAN_PROP_CONDENSED = 6
const PAN_PROP_VERY_EXPANDED = 7
const PAN_PROP_VERY_CONDENSED = 8
const PAN_PROP_MONOSPACED = 9
const PAN_CONTRAST_NONE = 2
const PAN_CONTRAST_VERY_LOW = 3
const PAN_CONTRAST_LOW = 4
const PAN_CONTRAST_MEDIUM_LOW = 5
const PAN_CONTRAST_MEDIUM = 6
const PAN_CONTRAST_MEDIUM_HIGH = 7
const PAN_CONTRAST_HIGH = 8
const PAN_CONTRAST_VERY_HIGH = 9
const PAN_STROKE_GRADUAL_DIAG = 2
const PAN_STROKE_GRADUAL_TRAN = 3
const PAN_STROKE_GRADUAL_VERT = 4
const PAN_STROKE_GRADUAL_HORZ = 5
const PAN_STROKE_RAPID_VERT = 6
const PAN_STROKE_RAPID_HORZ = 7
const PAN_STROKE_INSTANT_VERT = 8
const PAN_STRAIGHT_ARMS_HORZ = 2
const PAN_STRAIGHT_ARMS_WEDGE = 3
const PAN_STRAIGHT_ARMS_VERT = 4
const PAN_STRAIGHT_ARMS_SINGLE_SERIF = 5
const PAN_STRAIGHT_ARMS_DOUBLE_SERIF = 6
const PAN_BENT_ARMS_HORZ = 7
const PAN_BENT_ARMS_WEDGE = 8
const PAN_BENT_ARMS_VERT = 9
const PAN_BENT_ARMS_SINGLE_SERIF = 10
const PAN_BENT_ARMS_DOUBLE_SERIF = 11
const PAN_LETT_NORMAL_CONTACT = 2
const PAN_LETT_NORMAL_WEIGHTED = 3
const PAN_LETT_NORMAL_BOXED = 4
const PAN_LETT_NORMAL_FLATTENED = 5
const PAN_LETT_NORMAL_ROUNDED = 6
const PAN_LETT_NORMAL_OFF_CENTER = 7
const PAN_LETT_NORMAL_SQUARE = 8
const PAN_LETT_OBLIQUE_CONTACT = 9
const PAN_LETT_OBLIQUE_WEIGHTED = 10
const PAN_LETT_OBLIQUE_BOXED = 11
const PAN_LETT_OBLIQUE_FLATTENED = 12
const PAN_LETT_OBLIQUE_ROUNDED = 13
const PAN_LETT_OBLIQUE_OFF_CENTER = 14
const PAN_LETT_OBLIQUE_SQUARE = 15
const PAN_MIDLINE_STANDARD_TRIMMED = 2
const PAN_MIDLINE_STANDARD_POINTED = 3
const PAN_MIDLINE_STANDARD_SERIFED = 4
const PAN_MIDLINE_HIGH_TRIMMED = 5
const PAN_MIDLINE_HIGH_POINTED = 6
const PAN_MIDLINE_HIGH_SERIFED = 7
const PAN_MIDLINE_CONSTANT_TRIMMED = 8
const PAN_MIDLINE_CONSTANT_POINTED = 9
const PAN_MIDLINE_CONSTANT_SERIFED = 10
const PAN_MIDLINE_LOW_TRIMMED = 11
const PAN_MIDLINE_LOW_POINTED = 12
const PAN_MIDLINE_LOW_SERIFED = 13
const PAN_XHEIGHT_CONSTANT_SMALL = 2
const PAN_XHEIGHT_CONSTANT_STD = 3
const PAN_XHEIGHT_CONSTANT_LARGE = 4
const PAN_XHEIGHT_DUCKING_SMALL = 5
const PAN_XHEIGHT_DUCKING_STD = 6
const PAN_XHEIGHT_DUCKING_LARGE = 7
const ELF_VENDOR_SIZE = 4

type tagEXTLOGFONTA
	elfLogFont as LOGFONTA
	elfFullName as zstring * 64
	elfStyle as zstring * 32
	elfVersion as DWORD
	elfStyleSize as DWORD
	elfMatch as DWORD
	elfReserved as DWORD
	elfVendorId(0 to 3) as UBYTE
	elfCulture as DWORD
	elfPanose as PANOSE
end type

type EXTLOGFONTA as tagEXTLOGFONTA
type PEXTLOGFONTA as tagEXTLOGFONTA ptr
type NPEXTLOGFONTA as tagEXTLOGFONTA ptr
type LPEXTLOGFONTA as tagEXTLOGFONTA ptr

type tagEXTLOGFONTW
	elfLogFont as LOGFONTW
	elfFullName as wstring * 64
	elfStyle as wstring * 32
	elfVersion as DWORD
	elfStyleSize as DWORD
	elfMatch as DWORD
	elfReserved as DWORD
	elfVendorId(0 to 3) as UBYTE
	elfCulture as DWORD
	elfPanose as PANOSE
end type

type EXTLOGFONTW as tagEXTLOGFONTW
type PEXTLOGFONTW as tagEXTLOGFONTW ptr
type NPEXTLOGFONTW as tagEXTLOGFONTW ptr
type LPEXTLOGFONTW as tagEXTLOGFONTW ptr

#ifdef UNICODE
	type EXTLOGFONT as EXTLOGFONTW
	type PEXTLOGFONT as PEXTLOGFONTW
	type NPEXTLOGFONT as NPEXTLOGFONTW
	type LPEXTLOGFONT as LPEXTLOGFONTW
#else
	type EXTLOGFONT as EXTLOGFONTA
	type PEXTLOGFONT as PEXTLOGFONTA
	type NPEXTLOGFONT as NPEXTLOGFONTA
	type LPEXTLOGFONT as LPEXTLOGFONTA
#endif

const ELF_VERSION = 0
const ELF_CULTURE_LATIN = 0
const RASTER_FONTTYPE = &h0001
const DEVICE_FONTTYPE = &h002
const TRUETYPE_FONTTYPE = &h004
#define BGR(r, g, b) cast(COLORREF, (cast(UBYTE, (r)) or (cast(WORD, cast(UBYTE, (g))) shl 8)) or (cast(DWORD, cast(UBYTE, (b))) shl 16))
#define BGRA(r, g, b, a) (culng(cubyte(r)) or (culng(cubyte(g)) shl 8) or (culng(cubyte(b)) shl 16) or (culng(cubyte(a)) shl 24))
#define PALETTERGB(r, g, b) (&h02000000 or BGR(r, g, b))
#define PALETTEINDEX(i) cast(COLORREF, &h01000000 or cast(DWORD, cast(WORD, (i))))
const PC_RESERVED = &h01
const PC_EXPLICIT = &h02
const PC_NOCOLLAPSE = &h04
#define GetRValue(rgb) LOBYTE(rgb)
#define GetGValue(rgb) LOBYTE(cast(WORD, (rgb)) shr 8)
#define GetBValue(rgb) LOBYTE((rgb) shr 16)
const TRANSPARENT = 1
const OPAQUE = 2
const BKMODE_LAST = 2
const GM_COMPATIBLE = 1
const GM_ADVANCED = 2
const GM_LAST = 2
const PT_CLOSEFIGURE = &h01
const PT_LINETO = &h02
const PT_BEZIERTO = &h04
const PT_MOVETO = &h06
const MM_TEXT = 1
const MM_LOMETRIC = 2
const MM_HIMETRIC = 3
const MM_LOENGLISH = 4
const MM_HIENGLISH = 5
const MM_TWIPS = 6
const MM_ISOTROPIC = 7
const MM_ANISOTROPIC = 8
const MM_MIN = MM_TEXT
const MM_MAX = MM_ANISOTROPIC
const MM_MAX_FIXEDSCALE = MM_TWIPS
const ABSOLUTE = 1
const RELATIVE = 2
const WHITE_BRUSH = 0
const LTGRAY_BRUSH = 1
const GRAY_BRUSH = 2
const DKGRAY_BRUSH = 3
const BLACK_BRUSH = 4
const NULL_BRUSH = 5
const HOLLOW_BRUSH = NULL_BRUSH
const WHITE_PEN = 6
const BLACK_PEN = 7
const NULL_PEN = 8
const OEM_FIXED_FONT = 10
const ANSI_FIXED_FONT = 11
const ANSI_VAR_FONT = 12
const SYSTEM_FONT = 13
const DEVICE_DEFAULT_FONT = 14
const DEFAULT_PALETTE = 15
const SYSTEM_FIXED_FONT = 16
const DEFAULT_GUI_FONT = 17
const DC_BRUSH = 18
const DC_PEN = 19
const STOCK_LAST = 19
const CLR_INVALID = &hFFFFFFFF
const BS_SOLID = 0
const BS_NULL = 1
const BS_HOLLOW = BS_NULL
const BS_HATCHED = 2
const BS_PATTERN = 3
const BS_INDEXED = 4
const BS_DIBPATTERN = 5
const BS_DIBPATTERNPT = 6
const BS_PATTERN8X8 = 7
const BS_DIBPATTERN8X8 = 8
const BS_MONOPATTERN = 9
const HS_HORIZONTAL = 0
const HS_VERTICAL = 1
const HS_FDIAGONAL = 2
const HS_BDIAGONAL = 3
const HS_CROSS = 4
const HS_DIAGCROSS = 5
const HS_API_MAX = 12
const PS_SOLID = 0
const PS_DASH = 1
const PS_DOT = 2
const PS_DASHDOT = 3
const PS_DASHDOTDOT = 4
const PS_NULL = 5
const PS_INSIDEFRAME = 6
const PS_USERSTYLE = 7
const PS_ALTERNATE = 8
const PS_STYLE_MASK = &h0000000F
const PS_ENDCAP_ROUND = &h00000000
const PS_ENDCAP_SQUARE = &h00000100
const PS_ENDCAP_FLAT = &h00000200
const PS_ENDCAP_MASK = &h00000F00
const PS_JOIN_ROUND = &h00000000
const PS_JOIN_BEVEL = &h00001000
const PS_JOIN_MITER = &h00002000
const PS_JOIN_MASK = &h0000F000
const PS_COSMETIC = &h00000000
const PS_GEOMETRIC = &h00010000
const PS_TYPE_MASK = &h000F0000
const AD_COUNTERCLOCKWISE = 1
const AD_CLOCKWISE = 2
const DRIVERVERSION = 0
const TECHNOLOGY = 2
const HORZSIZE = 4
const VERTSIZE = 6
const HORZRES = 8
const VERTRES = 10
const BITSPIXEL_ = 12
const PLANES_ = 14
const NUMBRUSHES = 16
const NUMPENS = 18
const NUMMARKERS = 20
const NUMFONTS = 22
const NUMCOLORS = 24
const PDEVICESIZE = 26
const CURVECAPS = 28
const LINECAPS = 30
const POLYGONALCAPS = 32
const TEXTCAPS = 34
const CLIPCAPS = 36
const RASTERCAPS = 38
const ASPECTX = 40
const ASPECTY = 42
const ASPECTXY = 44
const LOGPIXELSX = 88
const LOGPIXELSY = 90
const SIZEPALETTE = 104
const NUMRESERVED = 106
const COLORRES = 108
const PHYSICALWIDTH = 110
const PHYSICALHEIGHT = 111
const PHYSICALOFFSETX = 112
const PHYSICALOFFSETY = 113
const SCALINGFACTORX = 114
const SCALINGFACTORY = 115
const VREFRESH = 116
const DESKTOPVERTRES = 117
const DESKTOPHORZRES = 118
const BLTALIGNMENT = 119
const SHADEBLENDCAPS = 120
const COLORMGMTCAPS = 121
const DT_PLOTTER = 0
const DT_RASDISPLAY = 1
const DT_RASPRINTER = 2
const DT_RASCAMERA = 3
const DT_CHARSTREAM = 4
const DT_METAFILE = 5
const DT_DISPFILE = 6
const CC_NONE = 0
const CC_CIRCLES = 1
const CC_PIE = 2
const CC_CHORD = 4
const CC_ELLIPSES = 8
const CC_WIDE = 16
const CC_STYLED = 32
const CC_WIDESTYLED = 64
const CC_INTERIORS = 128
const CC_ROUNDRECT = 256
const LC_NONE = 0
const LC_POLYLINE = 2
const LC_MARKER = 4
const LC_POLYMARKER = 8
const LC_WIDE = 16
const LC_STYLED = 32
const LC_WIDESTYLED = 64
const LC_INTERIORS = 128
const PC_NONE = 0
const PC_POLYGON = 1
const PC_RECTANGLE = 2
const PC_WINDPOLYGON = 4
const PC_TRAPEZOID = 4
const PC_SCANLINE = 8
const PC_WIDE = 16
const PC_STYLED = 32
const PC_WIDESTYLED = 64
const PC_INTERIORS = 128
const PC_POLYPOLYGON = 256
const PC_PATHS = 512
const CP_NONE = 0
const CP_RECTANGLE = 1
const CP_REGION = 2
const TC_OP_CHARACTER = &h00000001
const TC_OP_STROKE = &h00000002
const TC_CP_STROKE = &h00000004
const TC_CR_90 = &h00000008
const TC_CR_ANY = &h00000010
const TC_SF_X_YINDEP = &h00000020
const TC_SA_DOUBLE = &h00000040
const TC_SA_INTEGER = &h00000080
const TC_SA_CONTIN = &h00000100
const TC_EA_DOUBLE = &h00000200
const TC_IA_ABLE = &h00000400
const TC_UA_ABLE = &h00000800
const TC_SO_ABLE = &h00001000
const TC_RA_ABLE = &h00002000
const TC_VA_ABLE = &h00004000
const TC_RESERVED = &h00008000
const TC_SCROLLBLT = &h00010000
#define RC_NONE
const RC_BITBLT = 1
const RC_BANDING = 2
const RC_SCALING = 4
const RC_BITMAP64 = 8
const RC_GDI20_OUTPUT = &h0010
const RC_GDI20_STATE = &h0020
const RC_SAVEBITMAP = &h0040
const RC_DI_BITMAP = &h0080
const RC_PALETTE = &h0100
const RC_DIBTODEV = &h0200
const RC_BIGFONT = &h0400
const RC_STRETCHBLT = &h0800
const RC_FLOODFILL = &h1000
const RC_STRETCHDIB = &h2000
const RC_OP_DX_OUTPUT = &h4000
const RC_DEVBITS = &h8000
const SB_NONE = &h00000000
const SB_CONST_ALPHA = &h00000001
const SB_PIXEL_ALPHA = &h00000002
const SB_PREMULT_ALPHA = &h00000004
const SB_GRAD_RECT = &h00000010
const SB_GRAD_TRI = &h00000020
const CM_NONE = &h00000000
const CM_DEVICE_ICM = &h00000001
const CM_GAMMA_RAMP = &h00000002
const CM_CMYK_COLOR = &h00000004
const DIB_RGB_COLORS = 0
const DIB_PAL_COLORS = 1
const SYSPAL_ERROR = 0
const SYSPAL_STATIC = 1
const SYSPAL_NOSTATIC = 2
const SYSPAL_NOSTATIC256 = 3
const CBM_INIT = &h04
const FLOODFILLBORDER = 0
const FLOODFILLSURFACE = 1
const CCHDEVICENAME = 32
const CCHFORMNAME = 32

type _devicemodeA
	dmDeviceName as zstring * 32
	dmSpecVersion as WORD
	dmDriverVersion as WORD
	dmSize as WORD
	dmDriverExtra as WORD
	dmFields as DWORD

	union
		type
			dmOrientation as short
			dmPaperSize as short
			dmPaperLength as short
			dmPaperWidth as short
			dmScale as short
			dmCopies as short
			dmDefaultSource as short
			dmPrintQuality as short
		end type

		type
			dmPosition as POINTL
			dmDisplayOrientation as DWORD
			dmDisplayFixedOutput as DWORD
		end type
	end union

	dmColor as short
	dmDuplex as short
	dmYResolution as short
	dmTTOption as short
	dmCollate as short
	dmFormName as zstring * 32
	dmLogPixels as WORD
	dmBitsPerPel as DWORD
	dmPelsWidth as DWORD
	dmPelsHeight as DWORD

	union
		dmDisplayFlags as DWORD
		dmNup as DWORD
	end union

	dmDisplayFrequency as DWORD
	dmICMMethod as DWORD
	dmICMIntent as DWORD
	dmMediaType as DWORD
	dmDitherType as DWORD
	dmReserved1 as DWORD
	dmReserved2 as DWORD
	dmPanningWidth as DWORD
	dmPanningHeight as DWORD
end type

type DEVMODEA as _devicemodeA
type PDEVMODEA as _devicemodeA ptr
type NPDEVMODEA as _devicemodeA ptr
type LPDEVMODEA as _devicemodeA ptr

type _devicemodeW
	dmDeviceName as wstring * 32
	dmSpecVersion as WORD
	dmDriverVersion as WORD
	dmSize as WORD
	dmDriverExtra as WORD
	dmFields as DWORD

	union
		type
			dmOrientation as short
			dmPaperSize as short
			dmPaperLength as short
			dmPaperWidth as short
			dmScale as short
			dmCopies as short
			dmDefaultSource as short
			dmPrintQuality as short
		end type

		type
			dmPosition as POINTL
			dmDisplayOrientation as DWORD
			dmDisplayFixedOutput as DWORD
		end type
	end union

	dmColor as short
	dmDuplex as short
	dmYResolution as short
	dmTTOption as short
	dmCollate as short
	dmFormName as wstring * 32
	dmLogPixels as WORD
	dmBitsPerPel as DWORD
	dmPelsWidth as DWORD
	dmPelsHeight as DWORD

	union
		dmDisplayFlags as DWORD
		dmNup as DWORD
	end union

	dmDisplayFrequency as DWORD
	dmICMMethod as DWORD
	dmICMIntent as DWORD
	dmMediaType as DWORD
	dmDitherType as DWORD
	dmReserved1 as DWORD
	dmReserved2 as DWORD
	dmPanningWidth as DWORD
	dmPanningHeight as DWORD
end type

type DEVMODEW as _devicemodeW
type PDEVMODEW as _devicemodeW ptr
type NPDEVMODEW as _devicemodeW ptr
type LPDEVMODEW as _devicemodeW ptr

#ifdef UNICODE
	type DEVMODE as DEVMODEW
	type PDEVMODE as PDEVMODEW
	type NPDEVMODE as NPDEVMODEW
	type LPDEVMODE as LPDEVMODEW
#else
	type DEVMODE as DEVMODEA
	type PDEVMODE as PDEVMODEA
	type NPDEVMODE as NPDEVMODEA
	type LPDEVMODE as LPDEVMODEA
#endif

const DM_SPECVERSION = &h0401
const DM_ORIENTATION = &h00000001
const DM_PAPERSIZE = &h00000002
const DM_PAPERLENGTH = &h00000004
const DM_PAPERWIDTH = &h00000008
const DM_SCALE = &h00000010
const DM_POSITION = &h00000020
const DM_NUP = &h00000040
const DM_DISPLAYORIENTATION = &h00000080
const DM_COPIES = &h00000100
const DM_DEFAULTSOURCE = &h00000200
const DM_PRINTQUALITY = &h00000400
const DM_COLOR = &h00000800
const DM_DUPLEX = &h00001000
const DM_YRESOLUTION = &h00002000
const DM_TTOPTION = &h00004000
const DM_COLLATE = &h00008000
const DM_FORMNAME = &h00010000
const DM_LOGPIXELS = &h00020000
const DM_BITSPERPEL = &h00040000
const DM_PELSWIDTH = &h00080000
const DM_PELSHEIGHT = &h00100000
const DM_DISPLAYFLAGS = &h00200000
const DM_DISPLAYFREQUENCY = &h00400000
const DM_ICMMETHOD = &h00800000
const DM_ICMINTENT = &h01000000
const DM_MEDIATYPE = &h02000000
const DM_DITHERTYPE = &h04000000
const DM_PANNINGWIDTH = &h08000000
const DM_PANNINGHEIGHT = &h10000000
const DM_DISPLAYFIXEDOUTPUT = &h20000000
const DMORIENT_PORTRAIT = 1
const DMORIENT_LANDSCAPE = 2
const DMPAPER_LETTER = 1
const DMPAPER_FIRST = DMPAPER_LETTER
const DMPAPER_LETTERSMALL = 2
const DMPAPER_TABLOID = 3
const DMPAPER_LEDGER = 4
const DMPAPER_LEGAL = 5
const DMPAPER_STATEMENT = 6
const DMPAPER_EXECUTIVE = 7
const DMPAPER_A3 = 8
const DMPAPER_A4 = 9
const DMPAPER_A4SMALL = 10
const DMPAPER_A5 = 11
const DMPAPER_B4 = 12
const DMPAPER_B5 = 13
const DMPAPER_FOLIO = 14
const DMPAPER_QUARTO = 15
const DMPAPER_10X14 = 16
const DMPAPER_11X17 = 17
const DMPAPER_NOTE = 18
const DMPAPER_ENV_9 = 19
const DMPAPER_ENV_10 = 20
const DMPAPER_ENV_11 = 21
const DMPAPER_ENV_12 = 22
const DMPAPER_ENV_14 = 23
const DMPAPER_CSHEET = 24
const DMPAPER_DSHEET = 25
const DMPAPER_ESHEET = 26
const DMPAPER_ENV_DL = 27
const DMPAPER_ENV_C5 = 28
const DMPAPER_ENV_C3 = 29
const DMPAPER_ENV_C4 = 30
const DMPAPER_ENV_C6 = 31
const DMPAPER_ENV_C65 = 32
const DMPAPER_ENV_B4 = 33
const DMPAPER_ENV_B5 = 34
const DMPAPER_ENV_B6 = 35
const DMPAPER_ENV_ITALY = 36
const DMPAPER_ENV_MONARCH = 37
const DMPAPER_ENV_PERSONAL = 38
const DMPAPER_FANFOLD_US = 39
const DMPAPER_FANFOLD_STD_GERMAN = 40
const DMPAPER_FANFOLD_LGL_GERMAN = 41
const DMPAPER_ISO_B4 = 42
const DMPAPER_JAPANESE_POSTCARD = 43
const DMPAPER_9X11 = 44
const DMPAPER_10X11 = 45
const DMPAPER_15X11 = 46
const DMPAPER_ENV_INVITE = 47
const DMPAPER_RESERVED_48 = 48
const DMPAPER_RESERVED_49 = 49
const DMPAPER_LETTER_EXTRA = 50
const DMPAPER_LEGAL_EXTRA = 51
const DMPAPER_TABLOID_EXTRA = 52
const DMPAPER_A4_EXTRA = 53
const DMPAPER_LETTER_TRANSVERSE = 54
const DMPAPER_A4_TRANSVERSE = 55
const DMPAPER_LETTER_EXTRA_TRANSVERSE = 56
const DMPAPER_A_PLUS = 57
const DMPAPER_B_PLUS = 58
const DMPAPER_LETTER_PLUS = 59
const DMPAPER_A4_PLUS = 60
const DMPAPER_A5_TRANSVERSE = 61
const DMPAPER_B5_TRANSVERSE = 62
const DMPAPER_A3_EXTRA = 63
const DMPAPER_A5_EXTRA = 64
const DMPAPER_B5_EXTRA = 65
const DMPAPER_A2 = 66
const DMPAPER_A3_TRANSVERSE = 67
const DMPAPER_A3_EXTRA_TRANSVERSE = 68
const DMPAPER_DBL_JAPANESE_POSTCARD = 69
const DMPAPER_A6 = 70
const DMPAPER_JENV_KAKU2 = 71
const DMPAPER_JENV_KAKU3 = 72
const DMPAPER_JENV_CHOU3 = 73
const DMPAPER_JENV_CHOU4 = 74
const DMPAPER_LETTER_ROTATED = 75
const DMPAPER_A3_ROTATED = 76
const DMPAPER_A4_ROTATED = 77
const DMPAPER_A5_ROTATED = 78
const DMPAPER_B4_JIS_ROTATED = 79
const DMPAPER_B5_JIS_ROTATED = 80
const DMPAPER_JAPANESE_POSTCARD_ROTATED = 81
const DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82
const DMPAPER_A6_ROTATED = 83
const DMPAPER_JENV_KAKU2_ROTATED = 84
const DMPAPER_JENV_KAKU3_ROTATED = 85
const DMPAPER_JENV_CHOU3_ROTATED = 86
const DMPAPER_JENV_CHOU4_ROTATED = 87
const DMPAPER_B6_JIS = 88
const DMPAPER_B6_JIS_ROTATED = 89
const DMPAPER_12X11 = 90
const DMPAPER_JENV_YOU4 = 91
const DMPAPER_JENV_YOU4_ROTATED = 92
const DMPAPER_P16K = 93
const DMPAPER_P32K = 94
const DMPAPER_P32KBIG = 95
const DMPAPER_PENV_1 = 96
const DMPAPER_PENV_2 = 97
const DMPAPER_PENV_3 = 98
const DMPAPER_PENV_4 = 99
const DMPAPER_PENV_5 = 100
const DMPAPER_PENV_6 = 101
const DMPAPER_PENV_7 = 102
const DMPAPER_PENV_8 = 103
const DMPAPER_PENV_9 = 104
const DMPAPER_PENV_10 = 105
const DMPAPER_P16K_ROTATED = 106
const DMPAPER_P32K_ROTATED = 107
const DMPAPER_P32KBIG_ROTATED = 108
const DMPAPER_PENV_1_ROTATED = 109
const DMPAPER_PENV_2_ROTATED = 110
const DMPAPER_PENV_3_ROTATED = 111
const DMPAPER_PENV_4_ROTATED = 112
const DMPAPER_PENV_5_ROTATED = 113
const DMPAPER_PENV_6_ROTATED = 114
const DMPAPER_PENV_7_ROTATED = 115
const DMPAPER_PENV_8_ROTATED = 116
const DMPAPER_PENV_9_ROTATED = 117
const DMPAPER_PENV_10_ROTATED = 118
const DMPAPER_LAST = DMPAPER_PENV_10_ROTATED
const DMPAPER_USER = 256
const DMBIN_UPPER = 1
const DMBIN_FIRST = DMBIN_UPPER
const DMBIN_ONLYONE = 1
const DMBIN_LOWER = 2
const DMBIN_MIDDLE = 3
const DMBIN_MANUAL = 4
const DMBIN_ENVELOPE = 5
const DMBIN_ENVMANUAL = 6
const DMBIN_AUTO = 7
const DMBIN_TRACTOR = 8
const DMBIN_SMALLFMT = 9
const DMBIN_LARGEFMT = 10
const DMBIN_LARGECAPACITY = 11
const DMBIN_CASSETTE = 14
const DMBIN_FORMSOURCE = 15
const DMBIN_LAST = DMBIN_FORMSOURCE
const DMBIN_USER = 256
const DMRES_DRAFT = -1
const DMRES_LOW = -2
const DMRES_MEDIUM = -3
const DMRES_HIGH = -4
const DMCOLOR_MONOCHROME = 1
const DMCOLOR_COLOR = 2
const DMDUP_SIMPLEX = 1
const DMDUP_VERTICAL = 2
const DMDUP_HORIZONTAL = 3
const DMTT_BITMAP = 1
const DMTT_DOWNLOAD = 2
const DMTT_SUBDEV = 3
const DMTT_DOWNLOAD_OUTLINE = 4
const DMCOLLATE_FALSE = 0
const DMCOLLATE_TRUE = 1
const DMDO_DEFAULT = 0
const DMDO_90 = 1
const DMDO_180 = 2
const DMDO_270 = 3
const DMDFO_DEFAULT = 0
const DMDFO_STRETCH = 1
const DMDFO_CENTER = 2
const DM_INTERLACED = &h00000002
const DMDISPLAYFLAGS_TEXTMODE = &h00000004
const DMNUP_SYSTEM = 1
const DMNUP_ONEUP = 2
const DMICMMETHOD_NONE = 1
const DMICMMETHOD_SYSTEM = 2
const DMICMMETHOD_DRIVER = 3
const DMICMMETHOD_DEVICE = 4
const DMICMMETHOD_USER = 256
const DMICM_SATURATE = 1
const DMICM_CONTRAST = 2
const DMICM_COLORIMETRIC = 3
const DMICM_ABS_COLORIMETRIC = 4
const DMICM_USER = 256
const DMMEDIA_STANDARD = 1
const DMMEDIA_TRANSPARENCY = 2
const DMMEDIA_GLOSSY = 3
const DMMEDIA_USER = 256
const DMDITHER_NONE = 1
const DMDITHER_COARSE = 2
const DMDITHER_FINE = 3
const DMDITHER_LINEART = 4
const DMDITHER_ERRORDIFFUSION = 5
const DMDITHER_RESERVED6 = 6
const DMDITHER_RESERVED7 = 7
const DMDITHER_RESERVED8 = 8
const DMDITHER_RESERVED9 = 9
const DMDITHER_GRAYSCALE = 10
const DMDITHER_USER = 256

type _DISPLAY_DEVICEA
	cb as DWORD
	DeviceName as zstring * 32
	DeviceString as zstring * 128
	StateFlags as DWORD
	DeviceID as zstring * 128
	DeviceKey as zstring * 128
end type

type DISPLAY_DEVICEA as _DISPLAY_DEVICEA
type PDISPLAY_DEVICEA as _DISPLAY_DEVICEA ptr
type LPDISPLAY_DEVICEA as _DISPLAY_DEVICEA ptr

type _DISPLAY_DEVICEW
	cb as DWORD
	DeviceName as wstring * 32
	DeviceString as wstring * 128
	StateFlags as DWORD
	DeviceID as wstring * 128
	DeviceKey as wstring * 128
end type

type DISPLAY_DEVICEW as _DISPLAY_DEVICEW
type PDISPLAY_DEVICEW as _DISPLAY_DEVICEW ptr
type LPDISPLAY_DEVICEW as _DISPLAY_DEVICEW ptr

#ifdef UNICODE
	type DISPLAY_DEVICE as DISPLAY_DEVICEW
	type PDISPLAY_DEVICE as PDISPLAY_DEVICEW
	type LPDISPLAY_DEVICE as LPDISPLAY_DEVICEW
#else
	type DISPLAY_DEVICE as DISPLAY_DEVICEA
	type PDISPLAY_DEVICE as PDISPLAY_DEVICEA
	type LPDISPLAY_DEVICE as LPDISPLAY_DEVICEA
#endif

const DISPLAY_DEVICE_ATTACHED_TO_DESKTOP = &h00000001
const DISPLAY_DEVICE_MULTI_DRIVER = &h00000002
const DISPLAY_DEVICE_PRIMARY_DEVICE = &h00000004
const DISPLAY_DEVICE_MIRRORING_DRIVER = &h00000008
const DISPLAY_DEVICE_VGA_COMPATIBLE = &h00000010
const DISPLAY_DEVICE_REMOVABLE = &h00000020

#if _WIN32_WINNT = &h0602
	const DISPLAY_DEVICE_ACC_DRIVER = &h00000040
#endif

const DISPLAY_DEVICE_TS_COMPATIBLE = &h00200000

#if _WIN32_WINNT >= &h0600
	const DISPLAY_DEVICE_UNSAFE_MODES_ON = &h00080000
#endif

const DISPLAY_DEVICE_MODESPRUNED = &h08000000
const DISPLAY_DEVICE_REMOTE = &h04000000
const DISPLAY_DEVICE_DISCONNECT = &h02000000
const DISPLAY_DEVICE_ACTIVE = &h00000001
const DISPLAY_DEVICE_ATTACHED = &h00000002

#if _WIN32_WINNT >= &h0601
	const DISPLAYCONFIG_MAXPATH = 1024

	type DISPLAYCONFIG_RATIONAL
		Numerator as UINT32
		Denominator as UINT32
	end type

	type DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY as long
	enum
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER = -1
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15 = 0
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO = 1
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO = 2
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO = 3
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI = 4
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI = 5
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS = 6
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN = 8
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI = 9
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL = 10
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED = 11
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL = 12
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED = 13
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE = 14
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL = &h80000000
		DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_SCANLINE_ORDERING as long
	enum
		DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED = 0
		DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE = 1
		DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED = 2
		DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = 2
		DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST = 3
		DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_2DREGION
		cx as UINT32
		cy as UINT32
	end type

	type DISPLAYCONFIG_VIDEO_SIGNAL_INFO
		pixelRate as UINT64
		hSyncFreq as DISPLAYCONFIG_RATIONAL
		vSyncFreq as DISPLAYCONFIG_RATIONAL
		activeSize as DISPLAYCONFIG_2DREGION
		totalSize as DISPLAYCONFIG_2DREGION
		videoStandard as UINT32
		scanLineOrdering as DISPLAYCONFIG_SCANLINE_ORDERING
	end type

	type DISPLAYCONFIG_SCALING as long
	enum
		DISPLAYCONFIG_SCALING_IDENTITY = 1
		DISPLAYCONFIG_SCALING_CENTERED = 2
		DISPLAYCONFIG_SCALING_STRETCHED = 3
		DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX = 4
		DISPLAYCONFIG_SCALING_CUSTOM = 5
		DISPLAYCONFIG_SCALING_PREFERRED = 128
		DISPLAYCONFIG_SCALING_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_ROTATION as long
	enum
		DISPLAYCONFIG_ROTATION_IDENTITY = 1
		DISPLAYCONFIG_ROTATION_ROTATE90 = 2
		DISPLAYCONFIG_ROTATION_ROTATE180 = 3
		DISPLAYCONFIG_ROTATION_ROTATE270 = 4
		DISPLAYCONFIG_ROTATION_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_MODE_INFO_TYPE as long
	enum
		DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE = 1
		DISPLAYCONFIG_MODE_INFO_TYPE_TARGET = 2
		DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_PIXELFORMAT as long
	enum
		DISPLAYCONFIG_PIXELFORMAT_8BPP = 1
		DISPLAYCONFIG_PIXELFORMAT_16BPP = 2
		DISPLAYCONFIG_PIXELFORMAT_24BPP = 3
		DISPLAYCONFIG_PIXELFORMAT_32BPP = 4
		DISPLAYCONFIG_PIXELFORMAT_NONGDI = 5
		DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32 = &hffffffff
	end enum

	type DISPLAYCONFIG_SOURCE_MODE
		width as UINT32
		height as UINT32
		pixelFormat as DISPLAYCONFIG_PIXELFORMAT
		position as POINTL
	end type

	type DISPLAYCONFIG_TARGET_MODE
		targetVideoSignalInfo as DISPLAYCONFIG_VIDEO_SIGNAL_INFO
	end type

	type DISPLAYCONFIG_MODE_INFO
		infoType as DISPLAYCONFIG_MODE_INFO_TYPE
		id as UINT32
		adapterId as LUID

		union
			targetMode as DISPLAYCONFIG_TARGET_MODE
			sourceMode as DISPLAYCONFIG_SOURCE_MODE
		end union
	end type

	const DISPLAYCONFIG_PATH_MODE_IDX_INVALID = &hffffffff

	type DISPLAYCONFIG_PATH_SOURCE_INFO
		adapterId as LUID
		id as UINT32
		modeInfoIdx as UINT32
		statusFlags as UINT32
	end type

	const DISPLAYCONFIG_SOURCE_IN_USE = &h1

	type DISPLAYCONFIG_PATH_TARGET_INFO
		adapterId as LUID
		id as UINT32
		modeInfoIdx as UINT32
		outputTechnology as DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY
		rotation as DISPLAYCONFIG_ROTATION
		scaling as DISPLAYCONFIG_SCALING
		refreshRate as DISPLAYCONFIG_RATIONAL
		scanLineOrdering as DISPLAYCONFIG_SCANLINE_ORDERING
		targetAvailable as WINBOOL
		statusFlags as UINT32
	end type

	const DISPLAYCONFIG_TARGET_IN_USE = &h00000001
	const DISPLAYCONFIG_TARGET_FORCIBLE = &h00000002
	const DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT = &h00000004
	const DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH = &h00000008
	const DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM = &h00000010

	type DISPLAYCONFIG_PATH_INFO
		sourceInfo as DISPLAYCONFIG_PATH_SOURCE_INFO
		targetInfo as DISPLAYCONFIG_PATH_TARGET_INFO
		flags as UINT32
	end type

	const DISPLAYCONFIG_PATH_ACTIVE = &h1

	type DISPLAYCONFIG_TOPOLOGY_ID as long
	enum
		DISPLAYCONFIG_TOPOLOGY_INTERNAL = &h1
		DISPLAYCONFIG_TOPOLOGY_CLONE = &h2
		DISPLAYCONFIG_TOPOLOGY_EXTEND = &h4
		DISPLAYCONFIG_TOPOLOGY_EXTERNAL = &h8
		DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_DEVICE_INFO_TYPE as long
	enum
		DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME = 1
		DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME = 2
		DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE = 3
		DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME = 4
		DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE = 5
		DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32 = &hFFFFFFFF
	end enum

	type DISPLAYCONFIG_DEVICE_INFO_HEADER
		as DISPLAYCONFIG_DEVICE_INFO_TYPE type
		size as UINT32
		adapterId as LUID
		id as UINT32
	end type

	type DISPLAYCONFIG_SOURCE_DEVICE_NAME
		header as DISPLAYCONFIG_DEVICE_INFO_HEADER
		viewGdiDeviceName as wstring * 32
	end type

	type DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
		union
			type
				friendlyNameFromEdid : 1 as UINT32
				friendlyNameForced : 1 as UINT32
				edidIdsValid : 1 as UINT32
				reserved : 29 as UINT32
			end type

			value as UINT32
		end union
	end type

	type DISPLAYCONFIG_TARGET_DEVICE_NAME
		header as DISPLAYCONFIG_DEVICE_INFO_HEADER
		flags as DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
		outputTechnology as DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY
		edidManufactureId as UINT16
		edidProductCodeId as UINT16
		connectorInstance as UINT32
		monitorFriendlyDeviceName as wstring * 64
		monitorDevicePath as wstring * 128
	end type

	type DISPLAYCONFIG_TARGET_PREFERRED_MODE
		header as DISPLAYCONFIG_DEVICE_INFO_HEADER
		width as UINT32
		height as UINT32
		targetMode as DISPLAYCONFIG_TARGET_MODE
	end type

	type DISPLAYCONFIG_ADAPTER_NAME
		header as DISPLAYCONFIG_DEVICE_INFO_HEADER
		adapterDevicePath as wstring * 128
	end type

	type DISPLAYCONFIG_SET_TARGET_PERSISTENCE
		header as DISPLAYCONFIG_DEVICE_INFO_HEADER

		union
			type
				bootPersistenceOn : 1 as UINT32
				reserved : 31 as UINT32
			end type

			value as UINT32
		end union
	end type

	const QDC_ALL_PATHS = &h00000001
	const QDC_ONLY_ACTIVE_PATHS = &h00000002
	const QDC_DATABASE_CURRENT = &h00000004
	const SDC_TOPOLOGY_INTERNAL = &h00000001
	const SDC_TOPOLOGY_CLONE = &h00000002
	const SDC_TOPOLOGY_EXTEND = &h00000004
	const SDC_TOPOLOGY_EXTERNAL = &h00000008
	const SDC_TOPOLOGY_SUPPLIED = &h00000010
	const SDC_USE_DATABASE_CURRENT = ((SDC_TOPOLOGY_INTERNAL or SDC_TOPOLOGY_CLONE) or SDC_TOPOLOGY_EXTEND) or SDC_TOPOLOGY_EXTERNAL
	const SDC_USE_SUPPLIED_DISPLAY_CONFIG = &h00000020
	const SDC_VALIDATE = &h00000040
	const SDC_APPLY = &h00000080
	const SDC_NO_OPTIMIZATION = &h00000100
	const SDC_SAVE_TO_DATABASE = &h00000200
	const SDC_ALLOW_CHANGES = &h00000400
	const SDC_PATH_PERSIST_IF_REQUIRED = &h00000800
	const SDC_FORCE_MODE_ENUMERATION = &h00001000
	const SDC_ALLOW_PATH_ORDER_CHANGES = &h00002000
#endif

const RDH_RECTANGLES = 1

type _RGNDATAHEADER
	dwSize as DWORD
	iType as DWORD
	nCount as DWORD
	nRgnSize as DWORD
	rcBound as RECT
end type

type RGNDATAHEADER as _RGNDATAHEADER
type PRGNDATAHEADER as _RGNDATAHEADER ptr

type _RGNDATA
	rdh as RGNDATAHEADER
	Buffer as zstring * 1
end type

type RGNDATA as _RGNDATA
type PRGNDATA as _RGNDATA ptr
type NPRGNDATA as _RGNDATA ptr
type LPRGNDATA as _RGNDATA ptr
const SYSRGN = 4

type _ABC
	abcA as long
	abcB as UINT
	abcC as long
end type

type ABC as _ABC
type PABC as _ABC ptr
type NPABC as _ABC ptr
type LPABC as _ABC ptr

type _ABCFLOAT
	abcfA as FLOAT
	abcfB as FLOAT
	abcfC as FLOAT
end type

type ABCFLOAT as _ABCFLOAT
type PABCFLOAT as _ABCFLOAT ptr
type NPABCFLOAT as _ABCFLOAT ptr
type LPABCFLOAT as _ABCFLOAT ptr

type _OUTLINETEXTMETRICA
	otmSize as UINT
	otmTextMetrics as TEXTMETRICA
	otmFiller as UBYTE
	otmPanoseNumber as PANOSE
	otmfsSelection as UINT
	otmfsType as UINT
	otmsCharSlopeRise as long
	otmsCharSlopeRun as long
	otmItalicAngle as long
	otmEMSquare as UINT
	otmAscent as long
	otmDescent as long
	otmLineGap as UINT
	otmsCapEmHeight as UINT
	otmsXHeight as UINT
	otmrcFontBox as RECT
	otmMacAscent as long
	otmMacDescent as long
	otmMacLineGap as UINT
	otmusMinimumPPEM as UINT
	otmptSubscriptSize as POINT
	otmptSubscriptOffset as POINT
	otmptSuperscriptSize as POINT
	otmptSuperscriptOffset as POINT
	otmsStrikeoutSize as UINT
	otmsStrikeoutPosition as long
	otmsUnderscoreSize as long
	otmsUnderscorePosition as long
	otmpFamilyName as PSTR
	otmpFaceName as PSTR
	otmpStyleName as PSTR
	otmpFullName as PSTR
end type

type OUTLINETEXTMETRICA as _OUTLINETEXTMETRICA
type POUTLINETEXTMETRICA as _OUTLINETEXTMETRICA ptr
type NPOUTLINETEXTMETRICA as _OUTLINETEXTMETRICA ptr
type LPOUTLINETEXTMETRICA as _OUTLINETEXTMETRICA ptr

type _OUTLINETEXTMETRICW
	otmSize as UINT
	otmTextMetrics as TEXTMETRICW
	otmFiller as UBYTE
	otmPanoseNumber as PANOSE
	otmfsSelection as UINT
	otmfsType as UINT
	otmsCharSlopeRise as long
	otmsCharSlopeRun as long
	otmItalicAngle as long
	otmEMSquare as UINT
	otmAscent as long
	otmDescent as long
	otmLineGap as UINT
	otmsCapEmHeight as UINT
	otmsXHeight as UINT
	otmrcFontBox as RECT
	otmMacAscent as long
	otmMacDescent as long
	otmMacLineGap as UINT
	otmusMinimumPPEM as UINT
	otmptSubscriptSize as POINT
	otmptSubscriptOffset as POINT
	otmptSuperscriptSize as POINT
	otmptSuperscriptOffset as POINT
	otmsStrikeoutSize as UINT
	otmsStrikeoutPosition as long
	otmsUnderscoreSize as long
	otmsUnderscorePosition as long
	otmpFamilyName as PSTR
	otmpFaceName as PSTR
	otmpStyleName as PSTR
	otmpFullName as PSTR
end type

type OUTLINETEXTMETRICW as _OUTLINETEXTMETRICW
type POUTLINETEXTMETRICW as _OUTLINETEXTMETRICW ptr
type NPOUTLINETEXTMETRICW as _OUTLINETEXTMETRICW ptr
type LPOUTLINETEXTMETRICW as _OUTLINETEXTMETRICW ptr

#ifdef UNICODE
	type OUTLINETEXTMETRIC as OUTLINETEXTMETRICW
	type POUTLINETEXTMETRIC as POUTLINETEXTMETRICW
	type NPOUTLINETEXTMETRIC as NPOUTLINETEXTMETRICW
	type LPOUTLINETEXTMETRIC as LPOUTLINETEXTMETRICW
#else
	type OUTLINETEXTMETRIC as OUTLINETEXTMETRICA
	type POUTLINETEXTMETRIC as POUTLINETEXTMETRICA
	type NPOUTLINETEXTMETRIC as NPOUTLINETEXTMETRICA
	type LPOUTLINETEXTMETRIC as LPOUTLINETEXTMETRICA
#endif

type tagPOLYTEXTA
	x as long
	y as long
	n as UINT
	lpstr as LPCSTR
	uiFlags as UINT
	rcl as RECT
	pdx as long ptr
end type

type POLYTEXTA as tagPOLYTEXTA
type PPOLYTEXTA as tagPOLYTEXTA ptr
type NPPOLYTEXTA as tagPOLYTEXTA ptr
type LPPOLYTEXTA as tagPOLYTEXTA ptr

type tagPOLYTEXTW
	x as long
	y as long
	n as UINT
	lpstr as LPCWSTR
	uiFlags as UINT
	rcl as RECT
	pdx as long ptr
end type

type POLYTEXTW as tagPOLYTEXTW
type PPOLYTEXTW as tagPOLYTEXTW ptr
type NPPOLYTEXTW as tagPOLYTEXTW ptr
type LPPOLYTEXTW as tagPOLYTEXTW ptr

#ifdef UNICODE
	type POLYTEXT as POLYTEXTW
	type PPOLYTEXT as PPOLYTEXTW
	type NPPOLYTEXT as NPPOLYTEXTW
	type LPPOLYTEXT as LPPOLYTEXTW
#else
	type POLYTEXT as POLYTEXTA
	type PPOLYTEXT as PPOLYTEXTA
	type NPPOLYTEXT as NPPOLYTEXTA
	type LPPOLYTEXT as LPPOLYTEXTA
#endif

type _FIXED
	fract as WORD
	value as short
end type

type FIXED as _FIXED

type _MAT2
	eM11 as FIXED
	eM12 as FIXED
	eM21 as FIXED
	eM22 as FIXED
end type

type MAT2 as _MAT2
type LPMAT2 as _MAT2 ptr

type _GLYPHMETRICS
	gmBlackBoxX as UINT
	gmBlackBoxY as UINT
	gmptGlyphOrigin as POINT
	gmCellIncX as short
	gmCellIncY as short
end type

type GLYPHMETRICS as _GLYPHMETRICS
type LPGLYPHMETRICS as _GLYPHMETRICS ptr
const GGO_METRICS = 0
const GGO_BITMAP = 1
const GGO_NATIVE = 2
const GGO_BEZIER = 3
const GGO_GRAY2_BITMAP = 4
const GGO_GRAY4_BITMAP = 5
const GGO_GRAY8_BITMAP = 6
const GGO_GLYPH_INDEX = &h0080
const GGO_UNHINTED = &h0100
const TT_POLYGON_TYPE = 24
const TT_PRIM_LINE = 1
const TT_PRIM_QSPLINE = 2
const TT_PRIM_CSPLINE = 3

type tagPOINTFX
	x as FIXED
	y as FIXED
end type

type POINTFX as tagPOINTFX
type LPPOINTFX as tagPOINTFX ptr

type tagTTPOLYCURVE
	wType as WORD
	cpfx as WORD
	apfx(0 to 0) as POINTFX
end type

type TTPOLYCURVE as tagTTPOLYCURVE
type LPTTPOLYCURVE as tagTTPOLYCURVE ptr

type tagTTPOLYGONHEADER
	cb as DWORD
	dwType as DWORD
	pfxStart as POINTFX
end type

type TTPOLYGONHEADER as tagTTPOLYGONHEADER
type LPTTPOLYGONHEADER as tagTTPOLYGONHEADER ptr
const GCP_DBCS = &h0001
const GCP_REORDER = &h0002
const GCP_USEKERNING = &h0008
const GCP_GLYPHSHAPE = &h0010
const GCP_LIGATE = &h0020
const GCP_DIACRITIC = &h0100
const GCP_KASHIDA = &h0400
const GCP_ERROR = &h8000
const FLI_MASK = &h103B
const GCP_JUSTIFY = &h00010000
const FLI_GLYPHS = &h00040000
const GCP_CLASSIN = &h00080000
const GCP_MAXEXTENT = &h00100000
const GCP_JUSTIFYIN = &h00200000
const GCP_DISPLAYZWG = &h00400000
const GCP_SYMSWAPOFF = &h00800000
const GCP_NUMERICOVERRIDE = &h01000000
const GCP_NEUTRALOVERRIDE = &h02000000
const GCP_NUMERICSLATIN = &h04000000
const GCP_NUMERICSLOCAL = &h08000000
const GCPCLASS_LATIN = 1
const GCPCLASS_HEBREW = 2
const GCPCLASS_ARABIC = 2
const GCPCLASS_NEUTRAL = 3
const GCPCLASS_LOCALNUMBER = 4
const GCPCLASS_LATINNUMBER = 5
const GCPCLASS_LATINNUMERICTERMINATOR = 6
const GCPCLASS_LATINNUMERICSEPARATOR = 7
const GCPCLASS_NUMERICSEPARATOR = 8
const GCPCLASS_PREBOUNDLTR = &h80
const GCPCLASS_PREBOUNDRTL = &h40
const GCPCLASS_POSTBOUNDLTR = &h20
const GCPCLASS_POSTBOUNDRTL = &h10
const GCPGLYPH_LINKBEFORE = &h8000
const GCPGLYPH_LINKAFTER = &h4000

type tagGCP_RESULTSA
	lStructSize as DWORD
	lpOutString as LPSTR
	lpOrder as UINT ptr
	lpDx as long ptr
	lpCaretPos as long ptr
	lpClass as LPSTR
	lpGlyphs as LPWSTR
	nGlyphs as UINT
	nMaxFit as long
end type

type GCP_RESULTSA as tagGCP_RESULTSA
type LPGCP_RESULTSA as tagGCP_RESULTSA ptr

type tagGCP_RESULTSW
	lStructSize as DWORD
	lpOutString as LPWSTR
	lpOrder as UINT ptr
	lpDx as long ptr
	lpCaretPos as long ptr
	lpClass as LPSTR
	lpGlyphs as LPWSTR
	nGlyphs as UINT
	nMaxFit as long
end type

type GCP_RESULTSW as tagGCP_RESULTSW
type LPGCP_RESULTSW as tagGCP_RESULTSW ptr

#ifdef UNICODE
	type GCP_RESULTS as GCP_RESULTSW
	type LPGCP_RESULTS as LPGCP_RESULTSW
#else
	type GCP_RESULTS as GCP_RESULTSA
	type LPGCP_RESULTS as LPGCP_RESULTSA
#endif

type _RASTERIZER_STATUS
	nSize as short
	wFlags as short
	nLanguageID as short
end type

type RASTERIZER_STATUS as _RASTERIZER_STATUS
type LPRASTERIZER_STATUS as _RASTERIZER_STATUS ptr
const TT_AVAILABLE = &h0001
const TT_ENABLED = &h0002

type tagPIXELFORMATDESCRIPTOR
	nSize as WORD
	nVersion as WORD
	dwFlags as DWORD
	iPixelType as UBYTE
	cColorBits as UBYTE
	cRedBits as UBYTE
	cRedShift as UBYTE
	cGreenBits as UBYTE
	cGreenShift as UBYTE
	cBlueBits as UBYTE
	cBlueShift as UBYTE
	cAlphaBits as UBYTE
	cAlphaShift as UBYTE
	cAccumBits as UBYTE
	cAccumRedBits as UBYTE
	cAccumGreenBits as UBYTE
	cAccumBlueBits as UBYTE
	cAccumAlphaBits as UBYTE
	cDepthBits as UBYTE
	cStencilBits as UBYTE
	cAuxBuffers as UBYTE
	iLayerType as UBYTE
	bReserved as UBYTE
	dwLayerMask as DWORD
	dwVisibleMask as DWORD
	dwDamageMask as DWORD
end type

type PIXELFORMATDESCRIPTOR as tagPIXELFORMATDESCRIPTOR
type PPIXELFORMATDESCRIPTOR as tagPIXELFORMATDESCRIPTOR ptr
type LPPIXELFORMATDESCRIPTOR as tagPIXELFORMATDESCRIPTOR ptr

const PFD_TYPE_RGBA = 0
const PFD_TYPE_COLORINDEX = 1
const PFD_MAIN_PLANE = 0
const PFD_OVERLAY_PLANE = 1
const PFD_UNDERLAY_PLANE = -1
const PFD_DOUBLEBUFFER = &h00000001
const PFD_STEREO = &h00000002
const PFD_DRAW_TO_WINDOW = &h00000004
const PFD_DRAW_TO_BITMAP = &h00000008
const PFD_SUPPORT_GDI = &h00000010
const PFD_SUPPORT_OPENGL = &h00000020
const PFD_GENERIC_FORMAT = &h00000040
const PFD_NEED_PALETTE = &h00000080
const PFD_NEED_SYSTEM_PALETTE = &h00000100
const PFD_SWAP_EXCHANGE = &h00000200
const PFD_SWAP_COPY = &h00000400
const PFD_SWAP_LAYER_BUFFERS = &h00000800
const PFD_GENERIC_ACCELERATED = &h00001000
const PFD_SUPPORT_DIRECTDRAW = &h00002000
const PFD_DIRECT3D_ACCELERATED = &h00004000
const PFD_SUPPORT_COMPOSITION = &h00008000
const PFD_DEPTH_DONTCARE = &h20000000
const PFD_DOUBLEBUFFER_DONTCARE = &h40000000
const PFD_STEREO_DONTCARE = &h80000000
type OLDFONTENUMPROCA as function(byval as const LOGFONTA ptr, byval as const TEXTMETRICA ptr, byval as DWORD, byval as LPARAM) as long
type OLDFONTENUMPROCW as function(byval as const LOGFONTW ptr, byval as const TEXTMETRICW ptr, byval as DWORD, byval as LPARAM) as long

#ifdef UNICODE
	type OLDFONTENUMPROC as OLDFONTENUMPROCW
#else
	type OLDFONTENUMPROC as OLDFONTENUMPROCA
#endif

type FONTENUMPROCA as OLDFONTENUMPROCA
type FONTENUMPROCW as OLDFONTENUMPROCW

#ifdef UNICODE
	type FONTENUMPROC as FONTENUMPROCW
#else
	type FONTENUMPROC as FONTENUMPROCA
#endif

type GOBJENUMPROC as function(byval as LPVOID, byval as LPARAM) as long
type LINEDDAPROC as sub(byval as long, byval as long, byval as LPARAM)
declare function AddFontResourceA(byval as LPCSTR) as long

#ifndef UNICODE
	declare function AddFontResource alias "AddFontResourceA"(byval as LPCSTR) as long
#endif

declare function AddFontResourceW(byval as LPCWSTR) as long

#ifdef UNICODE
	declare function AddFontResource alias "AddFontResourceW"(byval as LPCWSTR) as long
#endif

declare function AnimatePalette(byval hPal as HPALETTE, byval iStartIndex as UINT, byval cEntries as UINT, byval ppe as const PALETTEENTRY ptr) as WINBOOL
declare function Arc(byval hdc as HDC, byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long, byval x4 as long, byval y4 as long) as WINBOOL
declare function BitBlt(byval hdc as HDC, byval x as long, byval y as long, byval cx as long, byval cy as long, byval hdcSrc as HDC, byval x1 as long, byval y1 as long, byval rop as DWORD) as WINBOOL
declare function CancelDC(byval hdc as HDC) as WINBOOL
declare function Chord(byval hdc as HDC, byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long, byval x4 as long, byval y4 as long) as WINBOOL
declare function ChoosePixelFormat(byval hdc as HDC, byval ppfd as const PIXELFORMATDESCRIPTOR ptr) as long
declare function CloseMetaFile(byval hdc as HDC) as HMETAFILE
declare function CombineRgn(byval hrgnDst as HRGN, byval hrgnSrc1 as HRGN, byval hrgnSrc2 as HRGN, byval iMode as long) as long
declare function CopyMetaFileA(byval as HMETAFILE, byval as LPCSTR) as HMETAFILE

#ifndef UNICODE
	declare function CopyMetaFile alias "CopyMetaFileA"(byval as HMETAFILE, byval as LPCSTR) as HMETAFILE
#endif

declare function CopyMetaFileW(byval as HMETAFILE, byval as LPCWSTR) as HMETAFILE

#ifdef UNICODE
	declare function CopyMetaFile alias "CopyMetaFileW"(byval as HMETAFILE, byval as LPCWSTR) as HMETAFILE
#endif

declare function CreateBitmap(byval nWidth as long, byval nHeight as long, byval nPlanes as UINT, byval nBitCount as UINT, byval lpBits as const any ptr) as HBITMAP
declare function CreateBitmapIndirect(byval pbm as const BITMAP ptr) as HBITMAP
declare function CreateBrushIndirect(byval plbrush as const LOGBRUSH ptr) as HBRUSH
declare function CreateCompatibleBitmap(byval hdc as HDC, byval cx as long, byval cy as long) as HBITMAP
declare function CreateDiscardableBitmap(byval hdc as HDC, byval cx as long, byval cy as long) as HBITMAP
declare function CreateCompatibleDC(byval hdc as HDC) as HDC
declare function CreateDCA(byval pwszDriver as LPCSTR, byval pwszDevice as LPCSTR, byval pszPort as LPCSTR, byval pdm as const DEVMODEA ptr) as HDC

#ifndef UNICODE
	declare function CreateDC alias "CreateDCA"(byval pwszDriver as LPCSTR, byval pwszDevice as LPCSTR, byval pszPort as LPCSTR, byval pdm as const DEVMODEA ptr) as HDC
#endif

declare function CreateDCW(byval pwszDriver as LPCWSTR, byval pwszDevice as LPCWSTR, byval pszPort as LPCWSTR, byval pdm as const DEVMODEW ptr) as HDC

#ifdef UNICODE
	declare function CreateDC alias "CreateDCW"(byval pwszDriver as LPCWSTR, byval pwszDevice as LPCWSTR, byval pszPort as LPCWSTR, byval pdm as const DEVMODEW ptr) as HDC
#endif

declare function CreateDIBitmap(byval hdc as HDC, byval pbmih as const BITMAPINFOHEADER ptr, byval flInit as DWORD, byval pjBits as const any ptr, byval pbmi as const BITMAPINFO ptr, byval iUsage as UINT) as HBITMAP
declare function CreateDIBPatternBrush(byval h as HGLOBAL, byval iUsage as UINT) as HBRUSH
declare function CreateDIBPatternBrushPt(byval lpPackedDIB as const any ptr, byval iUsage as UINT) as HBRUSH
declare function CreateEllipticRgn(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long) as HRGN
declare function CreateEllipticRgnIndirect(byval lprect as const RECT ptr) as HRGN
declare function CreateFontIndirectA(byval lplf as const LOGFONTA ptr) as HFONT

#ifndef UNICODE
	declare function CreateFontIndirect alias "CreateFontIndirectA"(byval lplf as const LOGFONTA ptr) as HFONT
#endif

declare function CreateFontIndirectW(byval lplf as const LOGFONTW ptr) as HFONT

#ifdef UNICODE
	declare function CreateFontIndirect alias "CreateFontIndirectW"(byval lplf as const LOGFONTW ptr) as HFONT
#endif

declare function CreateFontA(byval cHeight as long, byval cWidth as long, byval cEscapement as long, byval cOrientation as long, byval cWeight as long, byval bItalic as DWORD, byval bUnderline as DWORD, byval bStrikeOut as DWORD, byval iCharSet as DWORD, byval iOutPrecision as DWORD, byval iClipPrecision as DWORD, byval iQuality as DWORD, byval iPitchAndFamily as DWORD, byval pszFaceName as LPCSTR) as HFONT

#ifndef UNICODE
	declare function CreateFont alias "CreateFontA"(byval cHeight as long, byval cWidth as long, byval cEscapement as long, byval cOrientation as long, byval cWeight as long, byval bItalic as DWORD, byval bUnderline as DWORD, byval bStrikeOut as DWORD, byval iCharSet as DWORD, byval iOutPrecision as DWORD, byval iClipPrecision as DWORD, byval iQuality as DWORD, byval iPitchAndFamily as DWORD, byval pszFaceName as LPCSTR) as HFONT
#endif

declare function CreateFontW(byval cHeight as long, byval cWidth as long, byval cEscapement as long, byval cOrientation as long, byval cWeight as long, byval bItalic as DWORD, byval bUnderline as DWORD, byval bStrikeOut as DWORD, byval iCharSet as DWORD, byval iOutPrecision as DWORD, byval iClipPrecision as DWORD, byval iQuality as DWORD, byval iPitchAndFamily as DWORD, byval pszFaceName as LPCWSTR) as HFONT

#ifdef UNICODE
	declare function CreateFont alias "CreateFontW"(byval cHeight as long, byval cWidth as long, byval cEscapement as long, byval cOrientation as long, byval cWeight as long, byval bItalic as DWORD, byval bUnderline as DWORD, byval bStrikeOut as DWORD, byval iCharSet as DWORD, byval iOutPrecision as DWORD, byval iClipPrecision as DWORD, byval iQuality as DWORD, byval iPitchAndFamily as DWORD, byval pszFaceName as LPCWSTR) as HFONT
#endif

declare function CreateHatchBrush(byval iHatch as long, byval color as COLORREF) as HBRUSH
declare function CreateICA(byval pszDriver as LPCSTR, byval pszDevice as LPCSTR, byval pszPort as LPCSTR, byval pdm as const DEVMODEA ptr) as HDC

#ifndef UNICODE
	declare function CreateIC alias "CreateICA"(byval pszDriver as LPCSTR, byval pszDevice as LPCSTR, byval pszPort as LPCSTR, byval pdm as const DEVMODEA ptr) as HDC
#endif

declare function CreateICW(byval pszDriver as LPCWSTR, byval pszDevice as LPCWSTR, byval pszPort as LPCWSTR, byval pdm as const DEVMODEW ptr) as HDC

#ifdef UNICODE
	declare function CreateIC alias "CreateICW"(byval pszDriver as LPCWSTR, byval pszDevice as LPCWSTR, byval pszPort as LPCWSTR, byval pdm as const DEVMODEW ptr) as HDC
#endif

declare function CreateMetaFileA(byval pszFile as LPCSTR) as HDC

#ifndef UNICODE
	declare function CreateMetaFile alias "CreateMetaFileA"(byval pszFile as LPCSTR) as HDC
#endif

declare function CreateMetaFileW(byval pszFile as LPCWSTR) as HDC

#ifdef UNICODE
	declare function CreateMetaFile alias "CreateMetaFileW"(byval pszFile as LPCWSTR) as HDC
#endif

declare function CreatePalette(byval plpal as const LOGPALETTE ptr) as HPALETTE
declare function CreatePen(byval iStyle as long, byval cWidth as long, byval color as COLORREF) as HPEN
declare function CreatePenIndirect(byval plpen as const LOGPEN ptr) as HPEN
declare function CreatePolyPolygonRgn(byval pptl as const POINT ptr, byval pc as const INT_ ptr, byval cPoly as long, byval iMode as long) as HRGN
declare function CreatePatternBrush(byval hbm as HBITMAP) as HBRUSH
declare function CreateRectRgn(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long) as HRGN
declare function CreateRectRgnIndirect(byval lprect as const RECT ptr) as HRGN
declare function CreateRoundRectRgn(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval w as long, byval h as long) as HRGN
declare function CreateScalableFontResourceA(byval fdwHidden as DWORD, byval lpszFont as LPCSTR, byval lpszFile as LPCSTR, byval lpszPath as LPCSTR) as WINBOOL

#ifndef UNICODE
	declare function CreateScalableFontResource alias "CreateScalableFontResourceA"(byval fdwHidden as DWORD, byval lpszFont as LPCSTR, byval lpszFile as LPCSTR, byval lpszPath as LPCSTR) as WINBOOL
#endif

declare function CreateScalableFontResourceW(byval fdwHidden as DWORD, byval lpszFont as LPCWSTR, byval lpszFile as LPCWSTR, byval lpszPath as LPCWSTR) as WINBOOL

#ifdef UNICODE
	declare function CreateScalableFontResource alias "CreateScalableFontResourceW"(byval fdwHidden as DWORD, byval lpszFont as LPCWSTR, byval lpszFile as LPCWSTR, byval lpszPath as LPCWSTR) as WINBOOL
#endif

declare function CreateSolidBrush(byval color as COLORREF) as HBRUSH
declare function DeleteDC(byval hdc as HDC) as WINBOOL
declare function DeleteMetaFile(byval hmf as HMETAFILE) as WINBOOL
declare function DeleteObject(byval ho as HGDIOBJ) as WINBOOL
declare function DescribePixelFormat(byval hdc as HDC, byval iPixelFormat as long, byval nBytes as UINT, byval ppfd as LPPIXELFORMATDESCRIPTOR) as long
type LPFNDEVMODE as function(byval as HWND, byval as HMODULE, byval as LPDEVMODE, byval as LPSTR, byval as LPSTR, byval as LPDEVMODE, byval as LPSTR, byval as UINT) as UINT
type LPFNDEVCAPS as function(byval as LPSTR, byval as LPSTR, byval as UINT, byval as LPSTR, byval as LPDEVMODE) as DWORD

const DM_UPDATE = 1
const DM_COPY = 2
const DM_PROMPT = 4
const DM_MODIFY = 8
#define DM_IN_BUFFER DM_MODIFY
#define DM_IN_PROMPT DM_PROMPT
#define DM_OUT_BUFFER DM_COPY
#define DM_OUT_DEFAULT DM_UPDATE
const DC_FIELDS = 1
const DC_PAPERS = 2
const DC_PAPERSIZE = 3
const DC_MINEXTENT = 4
const DC_MAXEXTENT = 5
const DC_BINS = 6
const DC_DUPLEX = 7
const DC_SIZE = 8
const DC_EXTRA = 9
const DC_VERSION = 10
const DC_DRIVER = 11
const DC_BINNAMES = 12
const DC_ENUMRESOLUTIONS = 13
const DC_FILEDEPENDENCIES = 14
const DC_TRUETYPE = 15
const DC_PAPERNAMES = 16
const DC_ORIENTATION = 17
const DC_COPIES = 18
const DC_BINADJUST = 19
const DC_EMF_COMPLIANT = 20
const DC_DATATYPE_PRODUCED = 21
const DC_COLLATE = 22
const DC_MANUFACTURER = 23
const DC_MODEL = 24
const DC_PERSONALITY = 25
const DC_PRINTRATE = 26
const DC_PRINTRATEUNIT = 27
const PRINTRATEUNIT_PPM = 1
const PRINTRATEUNIT_CPS = 2
const PRINTRATEUNIT_LPM = 3
const PRINTRATEUNIT_IPM = 4
const DC_PRINTERMEM = 28
const DC_MEDIAREADY = 29
const DC_STAPLE = 30
const DC_PRINTRATEPPM = 31
const DC_COLORDEVICE = 32
const DC_NUP = 33
const DC_MEDIATYPENAMES = 34
const DC_MEDIATYPES = 35
const DCTT_BITMAP = &h0000001
const DCTT_DOWNLOAD = &h0000002
const DCTT_SUBDEV = &h0000004
const DCTT_DOWNLOAD_OUTLINE = &h0000008
const DCBA_FACEUPNONE = &h0000
const DCBA_FACEUPCENTER = &h0001
const DCBA_FACEUPLEFT = &h0002
const DCBA_FACEUPRIGHT = &h0003
const DCBA_FACEDOWNNONE = &h0100
const DCBA_FACEDOWNCENTER = &h0101
const DCBA_FACEDOWNLEFT = &h0102
const DCBA_FACEDOWNRIGHT = &h0103
declare function DeviceCapabilitiesA(byval pDevice as LPCSTR, byval pPort as LPCSTR, byval fwCapability as WORD, byval pOutput as LPSTR, byval pDevMode as const DEVMODEA ptr) as long

#ifndef UNICODE
	declare function DeviceCapabilities alias "DeviceCapabilitiesA"(byval pDevice as LPCSTR, byval pPort as LPCSTR, byval fwCapability as WORD, byval pOutput as LPSTR, byval pDevMode as const DEVMODEA ptr) as long
#endif

declare function DeviceCapabilitiesW(byval pDevice as LPCWSTR, byval pPort as LPCWSTR, byval fwCapability as WORD, byval pOutput as LPWSTR, byval pDevMode as const DEVMODEW ptr) as long

#ifdef UNICODE
	declare function DeviceCapabilities alias "DeviceCapabilitiesW"(byval pDevice as LPCWSTR, byval pPort as LPCWSTR, byval fwCapability as WORD, byval pOutput as LPWSTR, byval pDevMode as const DEVMODEW ptr) as long
#endif

declare function DrawEscape(byval hdc as HDC, byval iEscape as long, byval cjIn as long, byval lpIn as LPCSTR) as long
declare function Ellipse(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long) as WINBOOL
declare function EnumFontFamiliesExA(byval hdc as HDC, byval lpLogfont as LPLOGFONTA, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM, byval dwFlags as DWORD) as long

#ifndef UNICODE
	declare function EnumFontFamiliesEx alias "EnumFontFamiliesExA"(byval hdc as HDC, byval lpLogfont as LPLOGFONTA, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM, byval dwFlags as DWORD) as long
#endif

declare function EnumFontFamiliesExW(byval hdc as HDC, byval lpLogfont as LPLOGFONTW, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM, byval dwFlags as DWORD) as long

#ifdef UNICODE
	declare function EnumFontFamiliesEx alias "EnumFontFamiliesExW"(byval hdc as HDC, byval lpLogfont as LPLOGFONTW, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM, byval dwFlags as DWORD) as long
#endif

declare function EnumFontFamiliesA(byval hdc as HDC, byval lpLogfont as LPCSTR, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM) as long

#ifndef UNICODE
	declare function EnumFontFamilies alias "EnumFontFamiliesA"(byval hdc as HDC, byval lpLogfont as LPCSTR, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM) as long
#endif

declare function EnumFontFamiliesW(byval hdc as HDC, byval lpLogfont as LPCWSTR, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM) as long

#ifdef UNICODE
	declare function EnumFontFamilies alias "EnumFontFamiliesW"(byval hdc as HDC, byval lpLogfont as LPCWSTR, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM) as long
#endif

declare function EnumFontsA(byval hdc as HDC, byval lpLogfont as LPCSTR, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM) as long

#ifndef UNICODE
	declare function EnumFonts alias "EnumFontsA"(byval hdc as HDC, byval lpLogfont as LPCSTR, byval lpProc as FONTENUMPROCA, byval lParam as LPARAM) as long
#endif

declare function EnumFontsW(byval hdc as HDC, byval lpLogfont as LPCWSTR, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM) as long

#ifdef UNICODE
	declare function EnumFonts alias "EnumFontsW"(byval hdc as HDC, byval lpLogfont as LPCWSTR, byval lpProc as FONTENUMPROCW, byval lParam as LPARAM) as long
#endif

declare function EnumObjects(byval hdc as HDC, byval nType as long, byval lpFunc as GOBJENUMPROC, byval lParam as LPARAM) as long
declare function EqualRgn(byval hrgn1 as HRGN, byval hrgn2 as HRGN) as WINBOOL
declare function Escape(byval hdc as HDC, byval iEscape as long, byval cjIn as long, byval pvIn as LPCSTR, byval pvOut as LPVOID) as long
declare function ExtEscape(byval hdc as HDC, byval iEscape as long, byval cjInput as long, byval lpInData as LPCSTR, byval cjOutput as long, byval lpOutData as LPSTR) as long
declare function ExcludeClipRect(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long) as long
declare function ExtCreateRegion(byval lpx as const XFORM ptr, byval nCount as DWORD, byval lpData as const RGNDATA ptr) as HRGN
declare function ExtFloodFill(byval hdc as HDC, byval x as long, byval y as long, byval color as COLORREF, byval type as UINT) as WINBOOL
declare function FillRgn(byval hdc as HDC, byval hrgn as HRGN, byval hbr as HBRUSH) as WINBOOL
declare function FloodFill(byval hdc as HDC, byval x as long, byval y as long, byval color as COLORREF) as WINBOOL
declare function FrameRgn(byval hdc as HDC, byval hrgn as HRGN, byval hbr as HBRUSH, byval w as long, byval h as long) as WINBOOL
declare function GetROP2(byval hdc as HDC) as long
declare function GetAspectRatioFilterEx(byval hdc as HDC, byval lpsize as LPSIZE) as WINBOOL
declare function GetBkColor(byval hdc as HDC) as COLORREF
declare function GetDCBrushColor(byval hdc as HDC) as COLORREF
declare function GetDCPenColor(byval hdc as HDC) as COLORREF
declare function GetBkMode(byval hdc as HDC) as long
declare function GetBitmapBits(byval hbit as HBITMAP, byval cb as LONG, byval lpvBits as LPVOID) as LONG
declare function GetBitmapDimensionEx(byval hbit as HBITMAP, byval lpsize as LPSIZE) as WINBOOL
declare function GetBoundsRect(byval hdc as HDC, byval lprect as LPRECT, byval flags as UINT) as UINT
declare function GetBrushOrgEx(byval hdc as HDC, byval lppt as LPPOINT) as WINBOOL
declare function GetCharWidthA(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL

#ifndef UNICODE
	declare function GetCharWidth alias "GetCharWidthA"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL
#endif

declare function GetCharWidthW(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL

#ifdef UNICODE
	declare function GetCharWidth alias "GetCharWidthW"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL
#endif

declare function GetCharWidth32A(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL

#ifndef UNICODE
	declare function GetCharWidth32 alias "GetCharWidth32A"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL
#endif

declare function GetCharWidth32W(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL

#ifdef UNICODE
	declare function GetCharWidth32 alias "GetCharWidth32W"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as LPINT) as WINBOOL
#endif

declare function GetCharWidthFloatA(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as PFLOAT) as WINBOOL

#ifndef UNICODE
	declare function GetCharWidthFloat alias "GetCharWidthFloatA"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as PFLOAT) as WINBOOL
#endif

declare function GetCharWidthFloatW(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as PFLOAT) as WINBOOL

#ifdef UNICODE
	declare function GetCharWidthFloat alias "GetCharWidthFloatW"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpBuffer as PFLOAT) as WINBOOL
#endif

declare function GetCharABCWidthsA(byval hdc as HDC, byval wFirst as UINT, byval wLast as UINT, byval lpABC as LPABC) as WINBOOL

#ifndef UNICODE
	declare function GetCharABCWidths alias "GetCharABCWidthsA"(byval hdc as HDC, byval wFirst as UINT, byval wLast as UINT, byval lpABC as LPABC) as WINBOOL
#endif

declare function GetCharABCWidthsW(byval hdc as HDC, byval wFirst as UINT, byval wLast as UINT, byval lpABC as LPABC) as WINBOOL

#ifdef UNICODE
	declare function GetCharABCWidths alias "GetCharABCWidthsW"(byval hdc as HDC, byval wFirst as UINT, byval wLast as UINT, byval lpABC as LPABC) as WINBOOL
#endif

declare function GetCharABCWidthsFloatA(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpABC as LPABCFLOAT) as WINBOOL

#ifndef UNICODE
	declare function GetCharABCWidthsFloat alias "GetCharABCWidthsFloatA"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpABC as LPABCFLOAT) as WINBOOL
#endif

declare function GetCharABCWidthsFloatW(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpABC as LPABCFLOAT) as WINBOOL

#ifdef UNICODE
	declare function GetCharABCWidthsFloat alias "GetCharABCWidthsFloatW"(byval hdc as HDC, byval iFirst as UINT, byval iLast as UINT, byval lpABC as LPABCFLOAT) as WINBOOL
#endif

declare function GetClipBox(byval hdc as HDC, byval lprect as LPRECT) as long
declare function GetClipRgn(byval hdc as HDC, byval hrgn as HRGN) as long
declare function GetMetaRgn(byval hdc as HDC, byval hrgn as HRGN) as long
declare function GetCurrentObject(byval hdc as HDC, byval type as UINT) as HGDIOBJ
declare function GetCurrentPositionEx(byval hdc as HDC, byval lppt as LPPOINT) as WINBOOL
declare function GetDeviceCaps(byval hdc as HDC, byval index as long) as long
declare function GetDIBits(byval hdc as HDC, byval hbm as HBITMAP, byval start as UINT, byval cLines as UINT, byval lpvBits as LPVOID, byval lpbmi as LPBITMAPINFO, byval usage as UINT) as long
declare function GetFontData(byval hdc as HDC, byval dwTable as DWORD, byval dwOffset as DWORD, byval pvBuffer as PVOID, byval cjBuffer as DWORD) as DWORD
declare function GetGlyphOutlineA(byval hdc as HDC, byval uChar as UINT, byval fuFormat as UINT, byval lpgm as LPGLYPHMETRICS, byval cjBuffer as DWORD, byval pvBuffer as LPVOID, byval lpmat2 as const MAT2 ptr) as DWORD

#ifndef UNICODE
	declare function GetGlyphOutline alias "GetGlyphOutlineA"(byval hdc as HDC, byval uChar as UINT, byval fuFormat as UINT, byval lpgm as LPGLYPHMETRICS, byval cjBuffer as DWORD, byval pvBuffer as LPVOID, byval lpmat2 as const MAT2 ptr) as DWORD
#endif

declare function GetGlyphOutlineW(byval hdc as HDC, byval uChar as UINT, byval fuFormat as UINT, byval lpgm as LPGLYPHMETRICS, byval cjBuffer as DWORD, byval pvBuffer as LPVOID, byval lpmat2 as const MAT2 ptr) as DWORD

#ifdef UNICODE
	declare function GetGlyphOutline alias "GetGlyphOutlineW"(byval hdc as HDC, byval uChar as UINT, byval fuFormat as UINT, byval lpgm as LPGLYPHMETRICS, byval cjBuffer as DWORD, byval pvBuffer as LPVOID, byval lpmat2 as const MAT2 ptr) as DWORD
#endif

declare function GetGraphicsMode(byval hdc as HDC) as long
declare function GetMapMode(byval hdc as HDC) as long
declare function GetMetaFileBitsEx(byval hMF as HMETAFILE, byval cbBuffer as UINT, byval lpData as LPVOID) as UINT
declare function GetMetaFileA(byval lpName as LPCSTR) as HMETAFILE

#ifndef UNICODE
	declare function GetMetaFile alias "GetMetaFileA"(byval lpName as LPCSTR) as HMETAFILE
#endif

declare function GetMetaFileW(byval lpName as LPCWSTR) as HMETAFILE

#ifdef UNICODE
	declare function GetMetaFile alias "GetMetaFileW"(byval lpName as LPCWSTR) as HMETAFILE
#endif

declare function GetNearestColor(byval hdc as HDC, byval color as COLORREF) as COLORREF
declare function GetNearestPaletteIndex(byval h as HPALETTE, byval color as COLORREF) as UINT
declare function GetObjectType(byval h as HGDIOBJ) as DWORD
declare function GetOutlineTextMetricsA(byval hdc as HDC, byval cjCopy as UINT, byval potm as LPOUTLINETEXTMETRICA) as UINT

#ifndef UNICODE
	declare function GetOutlineTextMetrics alias "GetOutlineTextMetricsA"(byval hdc as HDC, byval cjCopy as UINT, byval potm as LPOUTLINETEXTMETRICA) as UINT
#endif

declare function GetOutlineTextMetricsW(byval hdc as HDC, byval cjCopy as UINT, byval potm as LPOUTLINETEXTMETRICW) as UINT

#ifdef UNICODE
	declare function GetOutlineTextMetrics alias "GetOutlineTextMetricsW"(byval hdc as HDC, byval cjCopy as UINT, byval potm as LPOUTLINETEXTMETRICW) as UINT
#endif

declare function GetPaletteEntries(byval hpal as HPALETTE, byval iStart as UINT, byval cEntries as UINT, byval pPalEntries as LPPALETTEENTRY) as UINT
declare function GetPixel(byval hdc as HDC, byval x as long, byval y as long) as COLORREF
declare function GetPixelFormat(byval hdc as HDC) as long
declare function GetPolyFillMode(byval hdc as HDC) as long
declare function GetRasterizerCaps(byval lpraststat as LPRASTERIZER_STATUS, byval cjBytes as UINT) as WINBOOL
declare function GetRandomRgn(byval hdc as HDC, byval hrgn as HRGN, byval i as INT_) as long
declare function GetRegionData(byval hrgn as HRGN, byval nCount as DWORD, byval lpRgnData as LPRGNDATA) as DWORD
declare function GetRgnBox(byval hrgn as HRGN, byval lprc as LPRECT) as long
declare function GetStockObject(byval i as long) as HGDIOBJ
declare function GetStretchBltMode(byval hdc as HDC) as long
declare function GetSystemPaletteEntries(byval hdc as HDC, byval iStart as UINT, byval cEntries as UINT, byval pPalEntries as LPPALETTEENTRY) as UINT
declare function GetSystemPaletteUse(byval hdc as HDC) as UINT
declare function GetTextCharacterExtra(byval hdc as HDC) as long
declare function GetTextAlign(byval hdc as HDC) as UINT
declare function GetTextColor(byval hdc as HDC) as COLORREF
declare function GetTextExtentPointA(byval hdc as HDC, byval lpString as LPCSTR, byval c as long, byval lpsz as LPSIZE) as WINBOOL

#ifndef UNICODE
	declare function GetTextExtentPoint alias "GetTextExtentPointA"(byval hdc as HDC, byval lpString as LPCSTR, byval c as long, byval lpsz as LPSIZE) as WINBOOL
#endif

declare function GetTextExtentPointW(byval hdc as HDC, byval lpString as LPCWSTR, byval c as long, byval lpsz as LPSIZE) as WINBOOL

#ifdef UNICODE
	declare function GetTextExtentPoint alias "GetTextExtentPointW"(byval hdc as HDC, byval lpString as LPCWSTR, byval c as long, byval lpsz as LPSIZE) as WINBOOL
#endif

declare function GetTextExtentPoint32A(byval hdc as HDC, byval lpString as LPCSTR, byval c as long, byval psizl as LPSIZE) as WINBOOL

#ifndef UNICODE
	declare function GetTextExtentPoint32 alias "GetTextExtentPoint32A"(byval hdc as HDC, byval lpString as LPCSTR, byval c as long, byval psizl as LPSIZE) as WINBOOL
#endif

declare function GetTextExtentPoint32W(byval hdc as HDC, byval lpString as LPCWSTR, byval c as long, byval psizl as LPSIZE) as WINBOOL

#ifdef UNICODE
	declare function GetTextExtentPoint32 alias "GetTextExtentPoint32W"(byval hdc as HDC, byval lpString as LPCWSTR, byval c as long, byval psizl as LPSIZE) as WINBOOL
#endif

declare function GetTextExtentExPointA(byval hdc as HDC, byval lpszString as LPCSTR, byval cchString as long, byval nMaxExtent as long, byval lpnFit as LPINT, byval lpnDx as LPINT, byval lpSize as LPSIZE) as WINBOOL

#ifndef UNICODE
	declare function GetTextExtentExPoint alias "GetTextExtentExPointA"(byval hdc as HDC, byval lpszString as LPCSTR, byval cchString as long, byval nMaxExtent as long, byval lpnFit as LPINT, byval lpnDx as LPINT, byval lpSize as LPSIZE) as WINBOOL
#endif

declare function GetTextExtentExPointW(byval hdc as HDC, byval lpszString as LPCWSTR, byval cchString as long, byval nMaxExtent as long, byval lpnFit as LPINT, byval lpnDx as LPINT, byval lpSize as LPSIZE) as WINBOOL

#ifdef UNICODE
	declare function GetTextExtentExPoint alias "GetTextExtentExPointW"(byval hdc as HDC, byval lpszString as LPCWSTR, byval cchString as long, byval nMaxExtent as long, byval lpnFit as LPINT, byval lpnDx as LPINT, byval lpSize as LPSIZE) as WINBOOL
#endif

declare function GetTextCharset(byval hdc as HDC) as long
declare function GetTextCharsetInfo(byval hdc as HDC, byval lpSig as LPFONTSIGNATURE, byval dwFlags as DWORD) as long
declare function TranslateCharsetInfo(byval lpSrc as DWORD ptr, byval lpCs as LPCHARSETINFO, byval dwFlags as DWORD) as WINBOOL
declare function GetFontLanguageInfo(byval hdc as HDC) as DWORD
declare function GetCharacterPlacementA(byval hdc as HDC, byval lpString as LPCSTR, byval nCount as long, byval nMexExtent as long, byval lpResults as LPGCP_RESULTSA, byval dwFlags as DWORD) as DWORD

#ifndef UNICODE
	declare function GetCharacterPlacement alias "GetCharacterPlacementA"(byval hdc as HDC, byval lpString as LPCSTR, byval nCount as long, byval nMexExtent as long, byval lpResults as LPGCP_RESULTSA, byval dwFlags as DWORD) as DWORD
#endif

declare function GetCharacterPlacementW(byval hdc as HDC, byval lpString as LPCWSTR, byval nCount as long, byval nMexExtent as long, byval lpResults as LPGCP_RESULTSW, byval dwFlags as DWORD) as DWORD

#ifdef UNICODE
	declare function GetCharacterPlacement alias "GetCharacterPlacementW"(byval hdc as HDC, byval lpString as LPCWSTR, byval nCount as long, byval nMexExtent as long, byval lpResults as LPGCP_RESULTSW, byval dwFlags as DWORD) as DWORD
#endif

type tagWCRANGE
	wcLow as WCHAR
	cGlyphs as USHORT
end type

type WCRANGE as tagWCRANGE
type PWCRANGE as tagWCRANGE ptr
type LPWCRANGE as tagWCRANGE ptr

type tagGLYPHSET
	cbThis as DWORD
	flAccel as DWORD
	cGlyphsSupported as DWORD
	cRanges as DWORD
	ranges(0 to 0) as WCRANGE
end type

type GLYPHSET as tagGLYPHSET
type PGLYPHSET as tagGLYPHSET ptr
type LPGLYPHSET as tagGLYPHSET ptr
const GS_8BIT_INDICES = &h00000001
const GGI_MARK_NONEXISTING_GLYPHS = &h0001
declare function GetFontUnicodeRanges(byval hdc as HDC, byval lpgs as LPGLYPHSET) as DWORD
declare function GetGlyphIndicesA(byval hdc as HDC, byval lpstr as LPCSTR, byval c as long, byval pgi as LPWORD, byval fl as DWORD) as DWORD

#ifndef UNICODE
	declare function GetGlyphIndices alias "GetGlyphIndicesA"(byval hdc as HDC, byval lpstr as LPCSTR, byval c as long, byval pgi as LPWORD, byval fl as DWORD) as DWORD
#endif

declare function GetGlyphIndicesW(byval hdc as HDC, byval lpstr as LPCWSTR, byval c as long, byval pgi as LPWORD, byval fl as DWORD) as DWORD

#ifdef UNICODE
	declare function GetGlyphIndices alias "GetGlyphIndicesW"(byval hdc as HDC, byval lpstr as LPCWSTR, byval c as long, byval pgi as LPWORD, byval fl as DWORD) as DWORD
#endif

declare function GetTextExtentPointI(byval hdc as HDC, byval pgiIn as LPWORD, byval cgi as long, byval psize as LPSIZE) as WINBOOL
declare function GetTextExtentExPointI(byval hdc as HDC, byval lpwszString as LPWORD, byval cwchString as long, byval nMaxExtent as long, byval lpnFit as LPINT, byval lpnDx as LPINT, byval lpSize as LPSIZE) as WINBOOL
declare function GetCharWidthI(byval hdc as HDC, byval giFirst as UINT, byval cgi as UINT, byval pgi as LPWORD, byval piWidths as LPINT) as WINBOOL
declare function GetCharABCWidthsI(byval hdc as HDC, byval giFirst as UINT, byval cgi as UINT, byval pgi as LPWORD, byval pabc as LPABC) as WINBOOL

#define STAMP_DESIGNVECTOR ((&h8000000 + asc("d")) + (asc("v") shl 8))
#define STAMP_AXESLIST ((&h8000000 + asc("a")) + (asc("l") shl 8))
const MM_MAX_NUMAXES = 16

type tagDESIGNVECTOR
	dvReserved as DWORD
	dvNumAxes as DWORD
	dvValues(0 to 15) as LONG
end type

type DESIGNVECTOR as tagDESIGNVECTOR
type PDESIGNVECTOR as tagDESIGNVECTOR ptr
type LPDESIGNVECTOR as tagDESIGNVECTOR ptr
declare function AddFontResourceExA(byval name as LPCSTR, byval fl as DWORD, byval res as PVOID) as long

#ifndef UNICODE
	declare function AddFontResourceEx alias "AddFontResourceExA"(byval name as LPCSTR, byval fl as DWORD, byval res as PVOID) as long
#endif

declare function AddFontResourceExW(byval name as LPCWSTR, byval fl as DWORD, byval res as PVOID) as long

#ifdef UNICODE
	declare function AddFontResourceEx alias "AddFontResourceExW"(byval name as LPCWSTR, byval fl as DWORD, byval res as PVOID) as long
#endif

declare function RemoveFontResourceExA(byval name as LPCSTR, byval fl as DWORD, byval pdv as PVOID) as WINBOOL

#ifndef UNICODE
	declare function RemoveFontResourceEx alias "RemoveFontResourceExA"(byval name as LPCSTR, byval fl as DWORD, byval pdv as PVOID) as WINBOOL
#endif

declare function RemoveFontResourceExW(byval name as LPCWSTR, byval fl as DWORD, byval pdv as PVOID) as WINBOOL

#ifdef UNICODE
	declare function RemoveFontResourceEx alias "RemoveFontResourceExW"(byval name as LPCWSTR, byval fl as DWORD, byval pdv as PVOID) as WINBOOL
#endif

declare function AddFontMemResourceEx(byval pFileView as PVOID, byval cjSize as DWORD, byval pvResrved as PVOID, byval pNumFonts as DWORD ptr) as HANDLE
declare function RemoveFontMemResourceEx(byval h as HANDLE) as WINBOOL
const FR_PRIVATE = &h10
const FR_NOT_ENUM = &h20
const MM_MAX_AXES_NAMELEN = 16

type tagAXISINFOA
	axMinValue as LONG
	axMaxValue as LONG
	axAxisName as zstring * 16
end type

type AXISINFOA as tagAXISINFOA
type PAXISINFOA as tagAXISINFOA ptr
type LPAXISINFOA as tagAXISINFOA ptr

type tagAXISINFOW
	axMinValue as LONG
	axMaxValue as LONG
	axAxisName as wstring * 16
end type

type AXISINFOW as tagAXISINFOW
type PAXISINFOW as tagAXISINFOW ptr
type LPAXISINFOW as tagAXISINFOW ptr

#ifdef UNICODE
	type AXISINFO as AXISINFOW
	type PAXISINFO as PAXISINFOW
	type LPAXISINFO as LPAXISINFOW
#else
	type AXISINFO as AXISINFOA
	type PAXISINFO as PAXISINFOA
	type LPAXISINFO as LPAXISINFOA
#endif

type tagAXESLISTA
	axlReserved as DWORD
	axlNumAxes as DWORD
	axlAxisInfo(0 to 15) as AXISINFOA
end type

type AXESLISTA as tagAXESLISTA
type PAXESLISTA as tagAXESLISTA ptr
type LPAXESLISTA as tagAXESLISTA ptr

type tagAXESLISTW
	axlReserved as DWORD
	axlNumAxes as DWORD
	axlAxisInfo(0 to 15) as AXISINFOW
end type

type AXESLISTW as tagAXESLISTW
type PAXESLISTW as tagAXESLISTW ptr
type LPAXESLISTW as tagAXESLISTW ptr

#ifdef UNICODE
	type AXESLIST as AXESLISTW
	type PAXESLIST as PAXESLISTW
	type LPAXESLIST as LPAXESLISTW
#else
	type AXESLIST as AXESLISTA
	type PAXESLIST as PAXESLISTA
	type LPAXESLIST as LPAXESLISTA
#endif

type tagENUMLOGFONTEXDVA
	elfEnumLogfontEx as ENUMLOGFONTEXA
	elfDesignVector as DESIGNVECTOR
end type

type ENUMLOGFONTEXDVA as tagENUMLOGFONTEXDVA
type PENUMLOGFONTEXDVA as tagENUMLOGFONTEXDVA ptr
type LPENUMLOGFONTEXDVA as tagENUMLOGFONTEXDVA ptr

type tagENUMLOGFONTEXDVW
	elfEnumLogfontEx as ENUMLOGFONTEXW
	elfDesignVector as DESIGNVECTOR
end type

type ENUMLOGFONTEXDVW as tagENUMLOGFONTEXDVW
type PENUMLOGFONTEXDVW as tagENUMLOGFONTEXDVW ptr
type LPENUMLOGFONTEXDVW as tagENUMLOGFONTEXDVW ptr

#ifdef UNICODE
	type ENUMLOGFONTEXDV as ENUMLOGFONTEXDVW
	type PENUMLOGFONTEXDV as PENUMLOGFONTEXDVW
	type LPENUMLOGFONTEXDV as LPENUMLOGFONTEXDVW
#else
	type ENUMLOGFONTEXDV as ENUMLOGFONTEXDVA
	type PENUMLOGFONTEXDV as PENUMLOGFONTEXDVA
	type LPENUMLOGFONTEXDV as LPENUMLOGFONTEXDVA
#endif

declare function CreateFontIndirectExA(byval as const ENUMLOGFONTEXDVA ptr) as HFONT

#ifndef UNICODE
	declare function CreateFontIndirectEx alias "CreateFontIndirectExA"(byval as const ENUMLOGFONTEXDVA ptr) as HFONT
#endif

declare function CreateFontIndirectExW(byval as const ENUMLOGFONTEXDVW ptr) as HFONT

#ifdef UNICODE
	declare function CreateFontIndirectEx alias "CreateFontIndirectExW"(byval as const ENUMLOGFONTEXDVW ptr) as HFONT
#endif

type tagENUMTEXTMETRICA
	etmNewTextMetricEx as NEWTEXTMETRICEXA
	etmAxesList as AXESLISTA
end type

type ENUMTEXTMETRICA as tagENUMTEXTMETRICA
type PENUMTEXTMETRICA as tagENUMTEXTMETRICA ptr
type LPENUMTEXTMETRICA as tagENUMTEXTMETRICA ptr

type tagENUMTEXTMETRICW
	etmNewTextMetricEx as NEWTEXTMETRICEXW
	etmAxesList as AXESLISTW
end type

type ENUMTEXTMETRICW as tagENUMTEXTMETRICW
type PENUMTEXTMETRICW as tagENUMTEXTMETRICW ptr
type LPENUMTEXTMETRICW as tagENUMTEXTMETRICW ptr

#ifdef UNICODE
	type ENUMTEXTMETRIC as ENUMTEXTMETRICW
	type PENUMTEXTMETRIC as PENUMTEXTMETRICW
	type LPENUMTEXTMETRIC as LPENUMTEXTMETRICW
#else
	type ENUMTEXTMETRIC as ENUMTEXTMETRICA
	type PENUMTEXTMETRIC as PENUMTEXTMETRICA
	type LPENUMTEXTMETRIC as LPENUMTEXTMETRICA
#endif

declare function GetViewportExtEx(byval hdc as HDC, byval lpsize as LPSIZE) as WINBOOL
declare function GetViewportOrgEx(byval hdc as HDC, byval lppoint as LPPOINT) as WINBOOL
declare function GetWindowExtEx(byval hdc as HDC, byval lpsize as LPSIZE) as WINBOOL
declare function GetWindowOrgEx(byval hdc as HDC, byval lppoint as LPPOINT) as WINBOOL
declare function IntersectClipRect(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long) as long
declare function InvertRgn(byval hdc as HDC, byval hrgn as HRGN) as WINBOOL
declare function LineDDA(byval xStart as long, byval yStart as long, byval xEnd as long, byval yEnd as long, byval lpProc as LINEDDAPROC, byval data as LPARAM) as WINBOOL
declare function LineTo(byval hdc as HDC, byval x as long, byval y as long) as WINBOOL
declare function MaskBlt(byval hdcDest as HDC, byval xDest as long, byval yDest as long, byval width as long, byval height as long, byval hdcSrc as HDC, byval xSrc as long, byval ySrc as long, byval hbmMask as HBITMAP, byval xMask as long, byval yMask as long, byval rop as DWORD) as WINBOOL
declare function PlgBlt(byval hdcDest as HDC, byval lpPoint as const POINT ptr, byval hdcSrc as HDC, byval xSrc as long, byval ySrc as long, byval width as long, byval height as long, byval hbmMask as HBITMAP, byval xMask as long, byval yMask as long) as WINBOOL
declare function OffsetClipRgn(byval hdc as HDC, byval x as long, byval y as long) as long
declare function OffsetRgn(byval hrgn as HRGN, byval x as long, byval y as long) as long
declare function PatBlt(byval hdc as HDC, byval x as long, byval y as long, byval w as long, byval h as long, byval rop as DWORD) as WINBOOL
declare function Pie(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long, byval xr1 as long, byval yr1 as long, byval xr2 as long, byval yr2 as long) as WINBOOL
declare function PlayMetaFile(byval hdc as HDC, byval hmf as HMETAFILE) as WINBOOL
declare function PaintRgn(byval hdc as HDC, byval hrgn as HRGN) as WINBOOL
declare function PolyPolygon(byval hdc as HDC, byval apt as const POINT ptr, byval asz as const INT_ ptr, byval csz as long) as WINBOOL
declare function PtInRegion(byval hrgn as HRGN, byval x as long, byval y as long) as WINBOOL
declare function PtVisible(byval hdc as HDC, byval x as long, byval y as long) as WINBOOL
declare function RectInRegion(byval hrgn as HRGN, byval lprect as const RECT ptr) as WINBOOL
declare function RectVisible(byval hdc as HDC, byval lprect as const RECT ptr) as WINBOOL
declare function Rectangle(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long) as WINBOOL
declare function RestoreDC(byval hdc as HDC, byval nSavedDC as long) as WINBOOL
declare function ResetDCA(byval hdc as HDC, byval lpdm as const DEVMODEA ptr) as HDC

#ifndef UNICODE
	declare function ResetDC alias "ResetDCA"(byval hdc as HDC, byval lpdm as const DEVMODEA ptr) as HDC
#endif

declare function ResetDCW(byval hdc as HDC, byval lpdm as const DEVMODEW ptr) as HDC

#ifdef UNICODE
	declare function ResetDC alias "ResetDCW"(byval hdc as HDC, byval lpdm as const DEVMODEW ptr) as HDC
#endif

declare function RealizePalette(byval hdc as HDC) as UINT
declare function RemoveFontResourceA(byval lpFileName as LPCSTR) as WINBOOL

#ifndef UNICODE
	declare function RemoveFontResource alias "RemoveFontResourceA"(byval lpFileName as LPCSTR) as WINBOOL
#endif

declare function RemoveFontResourceW(byval lpFileName as LPCWSTR) as WINBOOL

#ifdef UNICODE
	declare function RemoveFontResource alias "RemoveFontResourceW"(byval lpFileName as LPCWSTR) as WINBOOL
#endif

declare function RoundRect(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long, byval width as long, byval height as long) as WINBOOL
declare function ResizePalette(byval hpal as HPALETTE, byval n as UINT) as WINBOOL
declare function SaveDC(byval hdc as HDC) as long
declare function SelectClipRgn(byval hdc as HDC, byval hrgn as HRGN) as long
declare function ExtSelectClipRgn(byval hdc as HDC, byval hrgn as HRGN, byval mode as long) as long
declare function SetMetaRgn(byval hdc as HDC) as long
declare function SelectObject(byval hdc as HDC, byval h as HGDIOBJ) as HGDIOBJ
declare function SelectPalette(byval hdc as HDC, byval hPal as HPALETTE, byval bForceBkgd as WINBOOL) as HPALETTE
declare function SetBkColor(byval hdc as HDC, byval color as COLORREF) as COLORREF
declare function SetDCBrushColor(byval hdc as HDC, byval color as COLORREF) as COLORREF
declare function SetDCPenColor(byval hdc as HDC, byval color as COLORREF) as COLORREF
declare function SetBkMode(byval hdc as HDC, byval mode as long) as long
declare function SetBitmapBits(byval hbm as HBITMAP, byval cb as DWORD, byval pvBits as const any ptr) as LONG
declare function SetBoundsRect(byval hdc as HDC, byval lprect as const RECT ptr, byval flags as UINT) as UINT
declare function SetDIBits(byval hdc as HDC, byval hbm as HBITMAP, byval start as UINT, byval cLines as UINT, byval lpBits as const any ptr, byval lpbmi as const BITMAPINFO ptr, byval ColorUse as UINT) as long
declare function SetDIBitsToDevice(byval hdc as HDC, byval xDest as long, byval yDest as long, byval w as DWORD, byval h as DWORD, byval xSrc as long, byval ySrc as long, byval StartScan as UINT, byval cLines as UINT, byval lpvBits as const any ptr, byval lpbmi as const BITMAPINFO ptr, byval ColorUse as UINT) as long
declare function SetMapperFlags(byval hdc as HDC, byval flags as DWORD) as DWORD
declare function SetGraphicsMode(byval hdc as HDC, byval iMode as long) as long
declare function SetMapMode(byval hdc as HDC, byval iMode as long) as long
declare function SetLayout(byval hdc as HDC, byval l as DWORD) as DWORD
declare function GetLayout(byval hdc as HDC) as DWORD
declare function SetMetaFileBitsEx(byval cbBuffer as UINT, byval lpData as const UBYTE ptr) as HMETAFILE
declare function SetPaletteEntries(byval hpal as HPALETTE, byval iStart as UINT, byval cEntries as UINT, byval pPalEntries as const PALETTEENTRY ptr) as UINT
declare function SetPixel(byval hdc as HDC, byval x as long, byval y as long, byval color as COLORREF) as COLORREF
declare function SetPixelV(byval hdc as HDC, byval x as long, byval y as long, byval color as COLORREF) as WINBOOL
declare function SetPixelFormat(byval hdc as HDC, byval format as long, byval ppfd as const PIXELFORMATDESCRIPTOR ptr) as WINBOOL
declare function SetPolyFillMode(byval hdc as HDC, byval mode as long) as long
declare function StretchBlt(byval hdcDest as HDC, byval xDest as long, byval yDest as long, byval wDest as long, byval hDest as long, byval hdcSrc as HDC, byval xSrc as long, byval ySrc as long, byval wSrc as long, byval hSrc as long, byval rop as DWORD) as WINBOOL
declare function SetRectRgn(byval hrgn as HRGN, byval left as long, byval top as long, byval right as long, byval bottom as long) as WINBOOL
declare function StretchDIBits(byval hdc as HDC, byval xDest as long, byval yDest as long, byval DestWidth as long, byval DestHeight as long, byval xSrc as long, byval ySrc as long, byval SrcWidth as long, byval SrcHeight as long, byval lpBits as const any ptr, byval lpbmi as const BITMAPINFO ptr, byval iUsage as UINT, byval rop as DWORD) as long
declare function SetROP2(byval hdc as HDC, byval rop2 as long) as long
declare function SetStretchBltMode(byval hdc as HDC, byval mode as long) as long
declare function SetSystemPaletteUse(byval hdc as HDC, byval use as UINT) as UINT
declare function SetTextCharacterExtra(byval hdc as HDC, byval extra as long) as long
declare function SetTextColor(byval hdc as HDC, byval color as COLORREF) as COLORREF
declare function SetTextAlign(byval hdc as HDC, byval align as UINT) as UINT
declare function SetTextJustification(byval hdc as HDC, byval extra as long, byval count as long) as WINBOOL
declare function UpdateColors(byval hdc as HDC) as WINBOOL
type COLOR16 as USHORT

type _TRIVERTEX
	x as LONG
	y as LONG
	Red as COLOR16
	Green as COLOR16
	Blue as COLOR16
	Alpha as COLOR16
end type

type TRIVERTEX as _TRIVERTEX
type PTRIVERTEX as _TRIVERTEX ptr
type LPTRIVERTEX as _TRIVERTEX ptr

type _GRADIENT_TRIANGLE
	Vertex1 as ULONG
	Vertex2 as ULONG
	Vertex3 as ULONG
end type

type GRADIENT_TRIANGLE as _GRADIENT_TRIANGLE
type PGRADIENT_TRIANGLE as _GRADIENT_TRIANGLE ptr
type LPGRADIENT_TRIANGLE as _GRADIENT_TRIANGLE ptr

type _GRADIENT_RECT
	UpperLeft as ULONG
	LowerRight as ULONG
end type

type GRADIENT_RECT as _GRADIENT_RECT
type PGRADIENT_RECT as _GRADIENT_RECT ptr
type LPGRADIENT_RECT as _GRADIENT_RECT ptr

type _BLENDFUNCTION
	BlendOp as UBYTE
	BlendFlags as UBYTE
	SourceConstantAlpha as UBYTE
	AlphaFormat as UBYTE
end type

type BLENDFUNCTION as _BLENDFUNCTION
type PBLENDFUNCTION as _BLENDFUNCTION ptr
const AC_SRC_OVER = &h00
const AC_SRC_ALPHA = &h01
declare function AlphaBlend(byval hdcDest as HDC, byval xoriginDest as long, byval yoriginDest as long, byval wDest as long, byval hDest as long, byval hdcSrc as HDC, byval xoriginSrc as long, byval yoriginSrc as long, byval wSrc as long, byval hSrc as long, byval ftn as BLENDFUNCTION) as WINBOOL
declare function GdiAlphaBlend(byval hdcDest as HDC, byval xoriginDest as long, byval yoriginDest as long, byval wDest as long, byval hDest as long, byval hdcSrc as HDC, byval xoriginSrc as long, byval yoriginSrc as long, byval wSrc as long, byval hSrc as long, byval ftn as BLENDFUNCTION) as WINBOOL
declare function TransparentBlt(byval hdcDest as HDC, byval xoriginDest as long, byval yoriginDest as long, byval wDest as long, byval hDest as long, byval hdcSrc as HDC, byval xoriginSrc as long, byval yoriginSrc as long, byval wSrc as long, byval hSrc as long, byval crTransparent as UINT) as WINBOOL
declare function GdiTransparentBlt(byval hdcDest as HDC, byval xoriginDest as long, byval yoriginDest as long, byval wDest as long, byval hDest as long, byval hdcSrc as HDC, byval xoriginSrc as long, byval yoriginSrc as long, byval wSrc as long, byval hSrc as long, byval crTransparent as UINT) as WINBOOL

const GRADIENT_FILL_RECT_H = &h00000000
const GRADIENT_FILL_RECT_V = &h00000001
const GRADIENT_FILL_TRIANGLE = &h00000002
const GRADIENT_FILL_OP_FLAG = &h000000ff

declare function GradientFill(byval hdc as HDC, byval pVertex as PTRIVERTEX, byval nVertex as ULONG, byval pMesh as PVOID, byval nMesh as ULONG, byval ulMode as ULONG) as WINBOOL
declare function GdiGradientFill(byval hdc as HDC, byval pVertex as PTRIVERTEX, byval nVertex as ULONG, byval pMesh as PVOID, byval nMesh as ULONG, byval ulMode as ULONG) as WINBOOL
declare function PlayMetaFileRecord(byval hdc as HDC, byval lpHandleTable as LPHANDLETABLE, byval lpMR as LPMETARECORD, byval noObjs as UINT) as WINBOOL
type MFENUMPROC as function(byval hdc as HDC, byval lpht as HANDLETABLE ptr, byval lpMR as METARECORD ptr, byval nObj as long, byval lParam as LPARAM) as long
declare function EnumMetaFile(byval hdc as HDC, byval hmf as HMETAFILE, byval lpProc as MFENUMPROC, byval lParam as LPARAM) as WINBOOL
type ENHMFENUMPROC as function(byval hdc as HDC, byval lpht as HANDLETABLE ptr, byval lpmr as const ENHMETARECORD ptr, byval hHandles as long, byval data as LPARAM) as long
declare function CloseEnhMetaFile(byval hdc as HDC) as HENHMETAFILE
declare function CopyEnhMetaFileA(byval hEnh as HENHMETAFILE, byval lpFileName as LPCSTR) as HENHMETAFILE

#ifndef UNICODE
	declare function CopyEnhMetaFile alias "CopyEnhMetaFileA"(byval hEnh as HENHMETAFILE, byval lpFileName as LPCSTR) as HENHMETAFILE
#endif

declare function CopyEnhMetaFileW(byval hEnh as HENHMETAFILE, byval lpFileName as LPCWSTR) as HENHMETAFILE

#ifdef UNICODE
	declare function CopyEnhMetaFile alias "CopyEnhMetaFileW"(byval hEnh as HENHMETAFILE, byval lpFileName as LPCWSTR) as HENHMETAFILE
#endif

declare function CreateEnhMetaFileA(byval hdc as HDC, byval lpFilename as LPCSTR, byval lprc as const RECT ptr, byval lpDesc as LPCSTR) as HDC

#ifndef UNICODE
	declare function CreateEnhMetaFile alias "CreateEnhMetaFileA"(byval hdc as HDC, byval lpFilename as LPCSTR, byval lprc as const RECT ptr, byval lpDesc as LPCSTR) as HDC
#endif

declare function CreateEnhMetaFileW(byval hdc as HDC, byval lpFilename as LPCWSTR, byval lprc as const RECT ptr, byval lpDesc as LPCWSTR) as HDC

#ifdef UNICODE
	declare function CreateEnhMetaFile alias "CreateEnhMetaFileW"(byval hdc as HDC, byval lpFilename as LPCWSTR, byval lprc as const RECT ptr, byval lpDesc as LPCWSTR) as HDC
#endif

declare function DeleteEnhMetaFile(byval hmf as HENHMETAFILE) as WINBOOL
declare function EnumEnhMetaFile(byval hdc as HDC, byval hmf as HENHMETAFILE, byval lpProc as ENHMFENUMPROC, byval lpParam as LPVOID, byval lpRect as const RECT ptr) as WINBOOL
declare function GetEnhMetaFileA(byval lpName as LPCSTR) as HENHMETAFILE

#ifndef UNICODE
	declare function GetEnhMetaFile alias "GetEnhMetaFileA"(byval lpName as LPCSTR) as HENHMETAFILE
#endif

declare function GetEnhMetaFileW(byval lpName as LPCWSTR) as HENHMETAFILE

#ifdef UNICODE
	declare function GetEnhMetaFile alias "GetEnhMetaFileW"(byval lpName as LPCWSTR) as HENHMETAFILE
#endif

declare function GetEnhMetaFileBits(byval hEMF as HENHMETAFILE, byval nSize as UINT, byval lpData as LPBYTE) as UINT
declare function GetEnhMetaFileDescriptionA(byval hemf as HENHMETAFILE, byval cchBuffer as UINT, byval lpDescription as LPSTR) as UINT

#ifndef UNICODE
	declare function GetEnhMetaFileDescription alias "GetEnhMetaFileDescriptionA"(byval hemf as HENHMETAFILE, byval cchBuffer as UINT, byval lpDescription as LPSTR) as UINT
#endif

declare function GetEnhMetaFileDescriptionW(byval hemf as HENHMETAFILE, byval cchBuffer as UINT, byval lpDescription as LPWSTR) as UINT

#ifdef UNICODE
	declare function GetEnhMetaFileDescription alias "GetEnhMetaFileDescriptionW"(byval hemf as HENHMETAFILE, byval cchBuffer as UINT, byval lpDescription as LPWSTR) as UINT
#endif

declare function GetEnhMetaFileHeader(byval hemf as HENHMETAFILE, byval nSize as UINT, byval lpEnhMetaHeader as LPENHMETAHEADER) as UINT
declare function GetEnhMetaFilePaletteEntries(byval hemf as HENHMETAFILE, byval nNumEntries as UINT, byval lpPaletteEntries as LPPALETTEENTRY) as UINT
declare function GetEnhMetaFilePixelFormat(byval hemf as HENHMETAFILE, byval cbBuffer as UINT, byval ppfd as PIXELFORMATDESCRIPTOR ptr) as UINT
declare function GetWinMetaFileBits(byval hemf as HENHMETAFILE, byval cbData16 as UINT, byval pData16 as LPBYTE, byval iMapMode as INT_, byval hdcRef as HDC) as UINT
declare function PlayEnhMetaFile(byval hdc as HDC, byval hmf as HENHMETAFILE, byval lprect as const RECT ptr) as WINBOOL
declare function PlayEnhMetaFileRecord(byval hdc as HDC, byval pht as LPHANDLETABLE, byval pmr as const ENHMETARECORD ptr, byval cht as UINT) as WINBOOL
declare function SetEnhMetaFileBits(byval nSize as UINT, byval pb as const UBYTE ptr) as HENHMETAFILE
declare function SetWinMetaFileBits(byval nSize as UINT, byval lpMeta16Data as const UBYTE ptr, byval hdcRef as HDC, byval lpMFP as const METAFILEPICT ptr) as HENHMETAFILE
declare function GdiComment(byval hdc as HDC, byval nSize as UINT, byval lpData as const UBYTE ptr) as WINBOOL
declare function GetTextMetricsA(byval hdc as HDC, byval lptm as LPTEXTMETRICA) as WINBOOL

#ifndef UNICODE
	declare function GetTextMetrics alias "GetTextMetricsA"(byval hdc as HDC, byval lptm as LPTEXTMETRICA) as WINBOOL
#endif

declare function GetTextMetricsW(byval hdc as HDC, byval lptm as LPTEXTMETRICW) as WINBOOL

#ifdef UNICODE
	declare function GetTextMetrics alias "GetTextMetricsW"(byval hdc as HDC, byval lptm as LPTEXTMETRICW) as WINBOOL
#endif

type tagDIBSECTION
	dsBm as BITMAP
	dsBmih as BITMAPINFOHEADER
	dsBitfields(0 to 2) as DWORD
	dshSection as HANDLE
	dsOffset as DWORD
end type

type DIBSECTION as tagDIBSECTION
type LPDIBSECTION as tagDIBSECTION ptr
type PDIBSECTION as tagDIBSECTION ptr

declare function AngleArc(byval hdc as HDC, byval x as long, byval y as long, byval r as DWORD, byval StartAngle as FLOAT, byval SweepAngle as FLOAT) as WINBOOL
declare function PolyPolyline(byval hdc as HDC, byval apt as const POINT ptr, byval asz as const DWORD ptr, byval csz as DWORD) as WINBOOL
declare function GetWorldTransform(byval hdc as HDC, byval lpxf as LPXFORM) as WINBOOL
declare function SetWorldTransform(byval hdc as HDC, byval lpxf as const XFORM ptr) as WINBOOL
declare function ModifyWorldTransform(byval hdc as HDC, byval lpxf as const XFORM ptr, byval mode as DWORD) as WINBOOL
declare function CombineTransform(byval lpxfOut as LPXFORM, byval lpxf1 as const XFORM ptr, byval lpxf2 as const XFORM ptr) as WINBOOL
declare function CreateDIBSection(byval hdc as HDC, byval lpbmi as const BITMAPINFO ptr, byval usage as UINT, byval ppvBits as any ptr ptr, byval hSection as HANDLE, byval offset as DWORD) as HBITMAP
declare function GetDIBColorTable(byval hdc as HDC, byval iStart as UINT, byval cEntries as UINT, byval prgbq as RGBQUAD ptr) as UINT
declare function SetDIBColorTable(byval hdc as HDC, byval iStart as UINT, byval cEntries as UINT, byval prgbq as const RGBQUAD ptr) as UINT

const CA_NEGATIVE = &h0001
const CA_LOG_FILTER = &h0002
const ILLUMINANT_DEVICE_DEFAULT = 0
const ILLUMINANT_A = 1
const ILLUMINANT_B = 2
const ILLUMINANT_C = 3
const ILLUMINANT_D50 = 4
const ILLUMINANT_D55 = 5
const ILLUMINANT_D65 = 6
const ILLUMINANT_D75 = 7
const ILLUMINANT_F2 = 8
const ILLUMINANT_MAX_INDEX = ILLUMINANT_F2
const ILLUMINANT_TUNGSTEN = ILLUMINANT_A
const ILLUMINANT_DAYLIGHT = ILLUMINANT_C
const ILLUMINANT_FLUORESCENT = ILLUMINANT_F2
const ILLUMINANT_NTSC = ILLUMINANT_C
const RGB_GAMMA_MIN = cast(WORD, &o2500)
const RGB_GAMMA_MAX = cast(WORD, 65000)
const REFERENCE_WHITE_MIN = cast(WORD, 6000)
const REFERENCE_WHITE_MAX = cast(WORD, 10000)
const REFERENCE_BLACK_MIN = cast(WORD, 0)
const REFERENCE_BLACK_MAX = cast(WORD, 4000)
#define COLOR_ADJ_MIN cast(SHORT, -100)
#define COLOR_ADJ_MAX cast(SHORT, 100)

type tagCOLORADJUSTMENT
	caSize as WORD
	caFlags as WORD
	caIlluminantIndex as WORD
	caRedGamma as WORD
	caGreenGamma as WORD
	caBlueGamma as WORD
	caReferenceBlack as WORD
	caReferenceWhite as WORD
	caContrast as SHORT
	caBrightness as SHORT
	caColorfulness as SHORT
	caRedGreenTint as SHORT
end type

type COLORADJUSTMENT as tagCOLORADJUSTMENT
type PCOLORADJUSTMENT as tagCOLORADJUSTMENT ptr
type LPCOLORADJUSTMENT as tagCOLORADJUSTMENT ptr

declare function SetColorAdjustment(byval hdc as HDC, byval lpca as const COLORADJUSTMENT ptr) as WINBOOL
declare function GetColorAdjustment(byval hdc as HDC, byval lpca as LPCOLORADJUSTMENT) as WINBOOL
declare function CreateHalftonePalette(byval hdc as HDC) as HPALETTE
type ABORTPROC as function(byval as HDC, byval as long) as WINBOOL

type _DOCINFOA
	cbSize as long
	lpszDocName as LPCSTR
	lpszOutput as LPCSTR
	lpszDatatype as LPCSTR
	fwType as DWORD
end type

type DOCINFOA as _DOCINFOA
type LPDOCINFOA as _DOCINFOA ptr

type _DOCINFOW
	cbSize as long
	lpszDocName as LPCWSTR
	lpszOutput as LPCWSTR
	lpszDatatype as LPCWSTR
	fwType as DWORD
end type

type DOCINFOW as _DOCINFOW
type LPDOCINFOW as _DOCINFOW ptr

#ifdef UNICODE
	type DOCINFO as DOCINFOW
	type LPDOCINFO as LPDOCINFOW
#else
	type DOCINFO as DOCINFOA
	type LPDOCINFO as LPDOCINFOA
#endif

const DI_APPBANDING = &h00000001
const DI_ROPS_READ_DESTINATION = &h00000002
declare function StartDocA(byval hdc as HDC, byval lpdi as const DOCINFOA ptr) as long

#ifndef UNICODE
	declare function StartDoc alias "StartDocA"(byval hdc as HDC, byval lpdi as const DOCINFOA ptr) as long
#endif

declare function StartDocW(byval hdc as HDC, byval lpdi as const DOCINFOW ptr) as long

#ifdef UNICODE
	declare function StartDoc alias "StartDocW"(byval hdc as HDC, byval lpdi as const DOCINFOW ptr) as long
#endif

declare function EndDoc(byval hdc as HDC) as long
declare function StartPage(byval hdc as HDC) as long
declare function EndPage(byval hdc as HDC) as long
declare function AbortDoc(byval hdc as HDC) as long
declare function SetAbortProc(byval hdc as HDC, byval lpProc as ABORTPROC) as long
declare function AbortPath(byval hdc as HDC) as WINBOOL
declare function ArcTo(byval hdc as HDC, byval left as long, byval top as long, byval right as long, byval bottom as long, byval xr1 as long, byval yr1 as long, byval xr2 as long, byval yr2 as long) as WINBOOL
declare function BeginPath(byval hdc as HDC) as WINBOOL
declare function CloseFigure(byval hdc as HDC) as WINBOOL
declare function EndPath(byval hdc as HDC) as WINBOOL
declare function FillPath(byval hdc as HDC) as WINBOOL
declare function FlattenPath(byval hdc as HDC) as WINBOOL
declare function GetPath(byval hdc as HDC, byval apt as LPPOINT, byval aj as LPBYTE, byval cpt as long) as long
declare function PathToRegion(byval hdc as HDC) as HRGN
declare function PolyDraw(byval hdc as HDC, byval apt as const POINT ptr, byval aj as const UBYTE ptr, byval cpt as long) as WINBOOL
declare function SelectClipPath(byval hdc as HDC, byval mode as long) as WINBOOL
declare function SetArcDirection(byval hdc as HDC, byval dir as long) as long
declare function SetMiterLimit(byval hdc as HDC, byval limit as FLOAT, byval old as PFLOAT) as WINBOOL
declare function StrokeAndFillPath(byval hdc as HDC) as WINBOOL
declare function StrokePath(byval hdc as HDC) as WINBOOL
declare function WidenPath(byval hdc as HDC) as WINBOOL
declare function ExtCreatePen(byval iPenStyle as DWORD, byval cWidth as DWORD, byval plbrush as const LOGBRUSH ptr, byval cStyle as DWORD, byval pstyle as const DWORD ptr) as HPEN
declare function GetMiterLimit(byval hdc as HDC, byval plimit as PFLOAT) as WINBOOL
declare function GetArcDirection(byval hdc as HDC) as long
declare function GetObjectA(byval h as HANDLE, byval c as long, byval pv as LPVOID) as long

#ifndef UNICODE
	declare function GetObject alias "GetObjectA"(byval h as HANDLE, byval c as long, byval pv as LPVOID) as long
#endif

declare function GetObjectW(byval h as HANDLE, byval c as long, byval pv as LPVOID) as long

#ifdef UNICODE
	declare function GetObject alias "GetObjectW"(byval h as HANDLE, byval c as long, byval pv as LPVOID) as long
#endif

declare function MoveToEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function TextOutA(byval hdc as HDC, byval x as long, byval y as long, byval lpString as LPCSTR, byval c as long) as WINBOOL

#ifndef UNICODE
	declare function TextOut alias "TextOutA"(byval hdc as HDC, byval x as long, byval y as long, byval lpString as LPCSTR, byval c as long) as WINBOOL
#endif

declare function TextOutW(byval hdc as HDC, byval x as long, byval y as long, byval lpString as LPCWSTR, byval c as long) as WINBOOL

#ifdef UNICODE
	declare function TextOut alias "TextOutW"(byval hdc as HDC, byval x as long, byval y as long, byval lpString as LPCWSTR, byval c as long) as WINBOOL
#endif

declare function ExtTextOutA(byval hdc as HDC, byval x as long, byval y as long, byval options as UINT, byval lprect as const RECT ptr, byval lpString as LPCSTR, byval c as UINT, byval lpDx as const INT_ ptr) as WINBOOL

#ifndef UNICODE
	declare function ExtTextOut alias "ExtTextOutA"(byval hdc as HDC, byval x as long, byval y as long, byval options as UINT, byval lprect as const RECT ptr, byval lpString as LPCSTR, byval c as UINT, byval lpDx as const INT_ ptr) as WINBOOL
#endif

declare function ExtTextOutW(byval hdc as HDC, byval x as long, byval y as long, byval options as UINT, byval lprect as const RECT ptr, byval lpString as LPCWSTR, byval c as UINT, byval lpDx as const INT_ ptr) as WINBOOL

#ifdef UNICODE
	declare function ExtTextOut alias "ExtTextOutW"(byval hdc as HDC, byval x as long, byval y as long, byval options as UINT, byval lprect as const RECT ptr, byval lpString as LPCWSTR, byval c as UINT, byval lpDx as const INT_ ptr) as WINBOOL
#endif

declare function PolyTextOutA(byval hdc as HDC, byval ppt as const POLYTEXTA ptr, byval nstrings as long) as WINBOOL

#ifndef UNICODE
	declare function PolyTextOut alias "PolyTextOutA"(byval hdc as HDC, byval ppt as const POLYTEXTA ptr, byval nstrings as long) as WINBOOL
#endif

declare function PolyTextOutW(byval hdc as HDC, byval ppt as const POLYTEXTW ptr, byval nstrings as long) as WINBOOL

#ifdef UNICODE
	declare function PolyTextOut alias "PolyTextOutW"(byval hdc as HDC, byval ppt as const POLYTEXTW ptr, byval nstrings as long) as WINBOOL
#endif

declare function CreatePolygonRgn(byval pptl as const POINT ptr, byval cPoint as long, byval iMode as long) as HRGN
declare function DPtoLP(byval hdc as HDC, byval lppt as LPPOINT, byval c as long) as WINBOOL
declare function LPtoDP(byval hdc as HDC, byval lppt as LPPOINT, byval c as long) as WINBOOL
declare function Polygon(byval hdc as HDC, byval apt as const POINT ptr, byval cpt as long) as WINBOOL
declare function Polyline(byval hdc as HDC, byval apt as const POINT ptr, byval cpt as long) as WINBOOL
declare function PolyBezier(byval hdc as HDC, byval apt as const POINT ptr, byval cpt as DWORD) as WINBOOL
declare function PolyBezierTo(byval hdc as HDC, byval apt as const POINT ptr, byval cpt as DWORD) as WINBOOL
declare function PolylineTo(byval hdc as HDC, byval apt as const POINT ptr, byval cpt as DWORD) as WINBOOL
declare function SetViewportExtEx(byval hdc as HDC, byval x as long, byval y as long, byval lpsz as LPSIZE) as WINBOOL
declare function SetViewportOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function SetWindowExtEx(byval hdc as HDC, byval x as long, byval y as long, byval lpsz as LPSIZE) as WINBOOL
declare function SetWindowOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function OffsetViewportOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function OffsetWindowOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function ScaleViewportExtEx(byval hdc as HDC, byval xn as long, byval dx as long, byval yn as long, byval yd as long, byval lpsz as LPSIZE) as WINBOOL
declare function ScaleWindowExtEx(byval hdc as HDC, byval xn as long, byval xd as long, byval yn as long, byval yd as long, byval lpsz as LPSIZE) as WINBOOL
declare function SetBitmapDimensionEx(byval hbm as HBITMAP, byval w as long, byval h as long, byval lpsz as LPSIZE) as WINBOOL
declare function SetBrushOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval lppt as LPPOINT) as WINBOOL
declare function GetTextFaceA(byval hdc as HDC, byval c as long, byval lpName as LPSTR) as long

#ifndef UNICODE
	declare function GetTextFace alias "GetTextFaceA"(byval hdc as HDC, byval c as long, byval lpName as LPSTR) as long
#endif

declare function GetTextFaceW(byval hdc as HDC, byval c as long, byval lpName as LPWSTR) as long

#ifdef UNICODE
	declare function GetTextFace alias "GetTextFaceW"(byval hdc as HDC, byval c as long, byval lpName as LPWSTR) as long
#endif

const FONTMAPPER_MAX = 10

type tagKERNINGPAIR
	wFirst as WORD
	wSecond as WORD
	iKernAmount as long
end type

type KERNINGPAIR as tagKERNINGPAIR
type LPKERNINGPAIR as tagKERNINGPAIR ptr
declare function GetKerningPairsA(byval hdc as HDC, byval nPairs as DWORD, byval lpKernPair as LPKERNINGPAIR) as DWORD

#ifndef UNICODE
	declare function GetKerningPairs alias "GetKerningPairsA"(byval hdc as HDC, byval nPairs as DWORD, byval lpKernPair as LPKERNINGPAIR) as DWORD
#endif

declare function GetKerningPairsW(byval hdc as HDC, byval nPairs as DWORD, byval lpKernPair as LPKERNINGPAIR) as DWORD

#ifdef UNICODE
	declare function GetKerningPairs alias "GetKerningPairsW"(byval hdc as HDC, byval nPairs as DWORD, byval lpKernPair as LPKERNINGPAIR) as DWORD
#endif

declare function GetDCOrgEx(byval hdc as HDC, byval lppt as LPPOINT) as WINBOOL
declare function FixBrushOrgEx(byval hdc as HDC, byval x as long, byval y as long, byval ptl as LPPOINT) as WINBOOL
declare function UnrealizeObject(byval h as HGDIOBJ) as WINBOOL
declare function GdiFlush() as WINBOOL
declare function GdiSetBatchLimit(byval dw as DWORD) as DWORD
declare function GdiGetBatchLimit() as DWORD

const ICM_OFF = 1
const ICM_ON = 2
const ICM_QUERY = 3
const ICM_DONE_OUTSIDEDC = 4
type ICMENUMPROCA as function(byval as LPSTR, byval as LPARAM) as long
type ICMENUMPROCW as function(byval as LPWSTR, byval as LPARAM) as long

#ifdef UNICODE
	type ICMENUMPROC as ICMENUMPROCW
#else
	type ICMENUMPROC as ICMENUMPROCA
#endif

declare function SetICMMode(byval hdc as HDC, byval mode as long) as long
declare function CheckColorsInGamut(byval hdc as HDC, byval lpRGBTriple as LPVOID, byval dlpBuffer as LPVOID, byval nCount as DWORD) as WINBOOL
declare function GetColorSpace(byval hdc as HDC) as HCOLORSPACE
declare function GetLogColorSpaceA(byval hColorSpace as HCOLORSPACE, byval lpBuffer as LPLOGCOLORSPACEA, byval nSize as DWORD) as WINBOOL

#ifndef UNICODE
	declare function GetLogColorSpace alias "GetLogColorSpaceA"(byval hColorSpace as HCOLORSPACE, byval lpBuffer as LPLOGCOLORSPACEA, byval nSize as DWORD) as WINBOOL
#endif

declare function GetLogColorSpaceW(byval hColorSpace as HCOLORSPACE, byval lpBuffer as LPLOGCOLORSPACEW, byval nSize as DWORD) as WINBOOL

#ifdef UNICODE
	declare function GetLogColorSpace alias "GetLogColorSpaceW"(byval hColorSpace as HCOLORSPACE, byval lpBuffer as LPLOGCOLORSPACEW, byval nSize as DWORD) as WINBOOL
#endif

declare function CreateColorSpaceA(byval lplcs as LPLOGCOLORSPACEA) as HCOLORSPACE

#ifndef UNICODE
	declare function CreateColorSpace alias "CreateColorSpaceA"(byval lplcs as LPLOGCOLORSPACEA) as HCOLORSPACE
#endif

declare function CreateColorSpaceW(byval lplcs as LPLOGCOLORSPACEW) as HCOLORSPACE

#ifdef UNICODE
	declare function CreateColorSpace alias "CreateColorSpaceW"(byval lplcs as LPLOGCOLORSPACEW) as HCOLORSPACE
#endif

declare function SetColorSpace(byval hdc as HDC, byval hcs as HCOLORSPACE) as HCOLORSPACE
declare function DeleteColorSpace(byval hcs as HCOLORSPACE) as WINBOOL
declare function GetICMProfileA(byval hdc as HDC, byval pBufSize as LPDWORD, byval pszFilename as LPSTR) as WINBOOL

#ifndef UNICODE
	declare function GetICMProfile alias "GetICMProfileA"(byval hdc as HDC, byval pBufSize as LPDWORD, byval pszFilename as LPSTR) as WINBOOL
#endif

declare function GetICMProfileW(byval hdc as HDC, byval pBufSize as LPDWORD, byval pszFilename as LPWSTR) as WINBOOL

#ifdef UNICODE
	declare function GetICMProfile alias "GetICMProfileW"(byval hdc as HDC, byval pBufSize as LPDWORD, byval pszFilename as LPWSTR) as WINBOOL
#endif

declare function SetICMProfileA(byval hdc as HDC, byval lpFileName as LPSTR) as WINBOOL

#ifndef UNICODE
	declare function SetICMProfile alias "SetICMProfileA"(byval hdc as HDC, byval lpFileName as LPSTR) as WINBOOL
#endif

declare function SetICMProfileW(byval hdc as HDC, byval lpFileName as LPWSTR) as WINBOOL

#ifdef UNICODE
	declare function SetICMProfile alias "SetICMProfileW"(byval hdc as HDC, byval lpFileName as LPWSTR) as WINBOOL
#endif

declare function GetDeviceGammaRamp(byval hdc as HDC, byval lpRamp as LPVOID) as WINBOOL
declare function SetDeviceGammaRamp(byval hdc as HDC, byval lpRamp as LPVOID) as WINBOOL
declare function ColorMatchToTarget(byval hdc as HDC, byval hdcTarget as HDC, byval action as DWORD) as WINBOOL
declare function EnumICMProfilesA(byval hdc as HDC, byval lpProc as ICMENUMPROCA, byval lParam as LPARAM) as long

#ifndef UNICODE
	declare function EnumICMProfiles alias "EnumICMProfilesA"(byval hdc as HDC, byval lpProc as ICMENUMPROCA, byval lParam as LPARAM) as long
#endif

declare function EnumICMProfilesW(byval hdc as HDC, byval lpProc as ICMENUMPROCW, byval lParam as LPARAM) as long

#ifdef UNICODE
	declare function EnumICMProfiles alias "EnumICMProfilesW"(byval hdc as HDC, byval lpProc as ICMENUMPROCW, byval lParam as LPARAM) as long
#endif

declare function UpdateICMRegKeyA(byval reserved as DWORD, byval lpszCMID as LPSTR, byval lpszFileName as LPSTR, byval command as UINT) as WINBOOL

#ifndef UNICODE
	declare function UpdateICMRegKey alias "UpdateICMRegKeyA"(byval reserved as DWORD, byval lpszCMID as LPSTR, byval lpszFileName as LPSTR, byval command as UINT) as WINBOOL
#endif

declare function UpdateICMRegKeyW(byval reserved as DWORD, byval lpszCMID as LPWSTR, byval lpszFileName as LPWSTR, byval command as UINT) as WINBOOL

#ifdef UNICODE
	declare function UpdateICMRegKey alias "UpdateICMRegKeyW"(byval reserved as DWORD, byval lpszCMID as LPWSTR, byval lpszFileName as LPWSTR, byval command as UINT) as WINBOOL
#endif

declare function ColorCorrectPalette(byval hdc as HDC, byval hPal as HPALETTE, byval deFirst as DWORD, byval num as DWORD) as WINBOOL
const ENHMETA_SIGNATURE = &h464D4520
const ENHMETA_STOCK_OBJECT = &h80000000
const EMR_HEADER = 1
const EMR_POLYBEZIER = 2
const EMR_POLYGON = 3
const EMR_POLYLINE = 4
const EMR_POLYBEZIERTO = 5
const EMR_POLYLINETO = 6
const EMR_POLYPOLYLINE = 7
const EMR_POLYPOLYGON = 8
const EMR_SETWINDOWEXTEX = 9
const EMR_SETWINDOWORGEX = 10
const EMR_SETVIEWPORTEXTEX = 11
const EMR_SETVIEWPORTORGEX = 12
const EMR_SETBRUSHORGEX = 13
const EMR_EOF = 14
const EMR_SETPIXELV = 15
const EMR_SETMAPPERFLAGS = 16
const EMR_SETMAPMODE = 17
const EMR_SETBKMODE = 18
const EMR_SETPOLYFILLMODE = 19
const EMR_SETROP2 = 20
const EMR_SETSTRETCHBLTMODE = 21
const EMR_SETTEXTALIGN = 22
const EMR_SETCOLORADJUSTMENT = 23
const EMR_SETTEXTCOLOR = 24
const EMR_SETBKCOLOR = 25
const EMR_OFFSETCLIPRGN = 26
const EMR_MOVETOEX = 27
const EMR_SETMETARGN = 28
const EMR_EXCLUDECLIPRECT = 29
const EMR_INTERSECTCLIPRECT = 30
const EMR_SCALEVIEWPORTEXTEX = 31
const EMR_SCALEWINDOWEXTEX = 32
const EMR_SAVEDC = 33
const EMR_RESTOREDC = 34
const EMR_SETWORLDTRANSFORM = 35
const EMR_MODIFYWORLDTRANSFORM = 36
const EMR_SELECTOBJECT = 37
const EMR_CREATEPEN = 38
const EMR_CREATEBRUSHINDIRECT = 39
const EMR_DELETEOBJECT = 40
const EMR_ANGLEARC = 41
const EMR_ELLIPSE = 42
const EMR_RECTANGLE = 43
const EMR_ROUNDRECT = 44
const EMR_ARC = 45
const EMR_CHORD = 46
const EMR_PIE = 47
const EMR_SELECTPALETTE = 48
const EMR_CREATEPALETTE = 49
const EMR_SETPALETTEENTRIES = 50
const EMR_RESIZEPALETTE = 51
const EMR_REALIZEPALETTE = 52
const EMR_EXTFLOODFILL = 53
const EMR_LINETO = 54
const EMR_ARCTO = 55
const EMR_POLYDRAW = 56
const EMR_SETARCDIRECTION = 57
const EMR_SETMITERLIMIT = 58
const EMR_BEGINPATH = 59
const EMR_ENDPATH = 60
const EMR_CLOSEFIGURE = 61
const EMR_FILLPATH = 62
const EMR_STROKEANDFILLPATH = 63
const EMR_STROKEPATH = 64
const EMR_FLATTENPATH = 65
const EMR_WIDENPATH = 66
const EMR_SELECTCLIPPATH = 67
const EMR_ABORTPATH = 68
const EMR_GDICOMMENT = 70
const EMR_FILLRGN = 71
const EMR_FRAMERGN = 72
const EMR_INVERTRGN = 73
const EMR_PAINTRGN = 74
const EMR_EXTSELECTCLIPRGN = 75
const EMR_BITBLT = 76
const EMR_STRETCHBLT = 77
const EMR_MASKBLT = 78
const EMR_PLGBLT = 79
const EMR_SETDIBITSTODEVICE = 80
const EMR_STRETCHDIBITS = 81
const EMR_EXTCREATEFONTINDIRECTW = 82
const EMR_EXTTEXTOUTA = 83
const EMR_EXTTEXTOUTW = 84
const EMR_POLYBEZIER16 = 85
const EMR_POLYGON16 = 86
const EMR_POLYLINE16 = 87
const EMR_POLYBEZIERTO16 = 88
const EMR_POLYLINETO16 = 89
const EMR_POLYPOLYLINE16 = 90
const EMR_POLYPOLYGON16 = 91
const EMR_POLYDRAW16 = 92
const EMR_CREATEMONOBRUSH = 93
const EMR_CREATEDIBPATTERNBRUSHPT = 94
const EMR_EXTCREATEPEN = 95
const EMR_POLYTEXTOUTA = 96
const EMR_POLYTEXTOUTW = 97
const EMR_SETICMMODE = 98
const EMR_CREATECOLORSPACE = 99
const EMR_SETCOLORSPACE = 100
const EMR_DELETECOLORSPACE = 101
const EMR_GLSRECORD = 102
const EMR_GLSBOUNDEDRECORD = 103
const EMR_PIXELFORMAT = 104
const EMR_RESERVED_105 = 105
const EMR_RESERVED_106 = 106
const EMR_RESERVED_107 = 107
const EMR_RESERVED_108 = 108
const EMR_RESERVED_109 = 109
const EMR_RESERVED_110 = 110
const EMR_COLORCORRECTPALETTE = 111
const EMR_SETICMPROFILEA = 112
const EMR_SETICMPROFILEW = 113
const EMR_ALPHABLEND = 114
const EMR_SETLAYOUT = 115
const EMR_TRANSPARENTBLT = 116
const EMR_RESERVED_117 = 117
const EMR_GRADIENTFILL = 118
const EMR_RESERVED_119 = 119
const EMR_RESERVED_120 = 120
const EMR_COLORMATCHTOTARGETW = 121
const EMR_CREATECOLORSPACEW = 122
const EMR_MIN = 1
const EMR_MAX = 122

type tagEMR
	iType as DWORD
	nSize as DWORD
end type

type EMR as tagEMR
type PEMR as tagEMR ptr

type tagEMRTEXT
	ptlReference as POINTL
	nChars as DWORD
	offString as DWORD
	fOptions as DWORD
	rcl as RECTL
	offDx as DWORD
end type

type EMRTEXT as tagEMRTEXT
type PEMRTEXT as tagEMRTEXT ptr

type tagABORTPATH
	emr as EMR
end type

type EMRABORTPATH as tagABORTPATH
type PEMRABORTPATH as tagABORTPATH ptr
type EMRBEGINPATH as tagABORTPATH
type PEMRBEGINPATH as tagABORTPATH ptr
type EMRENDPATH as tagABORTPATH
type PEMRENDPATH as tagABORTPATH ptr
type EMRCLOSEFIGURE as tagABORTPATH
type PEMRCLOSEFIGURE as tagABORTPATH ptr
type EMRFLATTENPATH as tagABORTPATH
type PEMRFLATTENPATH as tagABORTPATH ptr
type EMRWIDENPATH as tagABORTPATH
type PEMRWIDENPATH as tagABORTPATH ptr
type EMRSETMETARGN as tagABORTPATH
type PEMRSETMETARGN as tagABORTPATH ptr
type EMRSAVEDC as tagABORTPATH
type PEMRSAVEDC as tagABORTPATH ptr
type EMRREALIZEPALETTE as tagABORTPATH
type PEMRREALIZEPALETTE as tagABORTPATH ptr

type tagEMRSELECTCLIPPATH
	emr as EMR
	iMode as DWORD
end type

type EMRSELECTCLIPPATH as tagEMRSELECTCLIPPATH
type PEMRSELECTCLIPPATH as tagEMRSELECTCLIPPATH ptr
type EMRSETBKMODE as tagEMRSELECTCLIPPATH
type PEMRSETBKMODE as tagEMRSELECTCLIPPATH ptr
type EMRSETMAPMODE as tagEMRSELECTCLIPPATH
type PEMRSETMAPMODE as tagEMRSELECTCLIPPATH ptr
type EMRSETLAYOUT as tagEMRSELECTCLIPPATH
type PEMRSETLAYOUT as tagEMRSELECTCLIPPATH ptr
type EMRSETPOLYFILLMODE as tagEMRSELECTCLIPPATH
type PEMRSETPOLYFILLMODE as tagEMRSELECTCLIPPATH ptr
type EMRSETROP2 as tagEMRSELECTCLIPPATH
type PEMRSETROP2 as tagEMRSELECTCLIPPATH ptr
type EMRSETSTRETCHBLTMODE as tagEMRSELECTCLIPPATH
type PEMRSETSTRETCHBLTMODE as tagEMRSELECTCLIPPATH ptr
type EMRSETICMMODE as tagEMRSELECTCLIPPATH
type PEMRSETICMMODE as tagEMRSELECTCLIPPATH ptr
type EMRSETTEXTALIGN as tagEMRSELECTCLIPPATH
type PEMRSETTEXTALIGN as tagEMRSELECTCLIPPATH ptr

type tagEMRSETMITERLIMIT
	emr as EMR
	eMiterLimit as FLOAT
end type

type EMRSETMITERLIMIT as tagEMRSETMITERLIMIT
type PEMRSETMITERLIMIT as tagEMRSETMITERLIMIT ptr

type tagEMRRESTOREDC
	emr as EMR
	iRelative as LONG
end type

type EMRRESTOREDC as tagEMRRESTOREDC
type PEMRRESTOREDC as tagEMRRESTOREDC ptr

type tagEMRSETARCDIRECTION
	emr as EMR
	iArcDirection as DWORD
end type

type EMRSETARCDIRECTION as tagEMRSETARCDIRECTION
type PEMRSETARCDIRECTION as tagEMRSETARCDIRECTION ptr

type tagEMRSETMAPPERFLAGS
	emr as EMR
	dwFlags as DWORD
end type

type EMRSETMAPPERFLAGS as tagEMRSETMAPPERFLAGS
type PEMRSETMAPPERFLAGS as tagEMRSETMAPPERFLAGS ptr

type tagEMRSETTEXTCOLOR
	emr as EMR
	crColor as COLORREF
end type

type EMRSETBKCOLOR as tagEMRSETTEXTCOLOR
type PEMRSETBKCOLOR as tagEMRSETTEXTCOLOR ptr
type EMRSETTEXTCOLOR as tagEMRSETTEXTCOLOR
type PEMRSETTEXTCOLOR as tagEMRSETTEXTCOLOR ptr

type tagEMRSELECTOBJECT
	emr as EMR
	ihObject as DWORD
end type

type EMRSELECTOBJECT as tagEMRSELECTOBJECT
type PEMRSELECTOBJECT as tagEMRSELECTOBJECT ptr
type EMRDELETEOBJECT as tagEMRSELECTOBJECT
type PEMRDELETEOBJECT as tagEMRSELECTOBJECT ptr

type tagEMRSELECTPALETTE
	emr as EMR
	ihPal as DWORD
end type

type EMRSELECTPALETTE as tagEMRSELECTPALETTE
type PEMRSELECTPALETTE as tagEMRSELECTPALETTE ptr

type tagEMRRESIZEPALETTE
	emr as EMR
	ihPal as DWORD
	cEntries as DWORD
end type

type EMRRESIZEPALETTE as tagEMRRESIZEPALETTE
type PEMRRESIZEPALETTE as tagEMRRESIZEPALETTE ptr

type tagEMRSETPALETTEENTRIES
	emr as EMR
	ihPal as DWORD
	iStart as DWORD
	cEntries as DWORD
	aPalEntries(0 to 0) as PALETTEENTRY
end type

type EMRSETPALETTEENTRIES as tagEMRSETPALETTEENTRIES
type PEMRSETPALETTEENTRIES as tagEMRSETPALETTEENTRIES ptr

type tagEMRSETCOLORADJUSTMENT
	emr as EMR
	ColorAdjustment as COLORADJUSTMENT
end type

type EMRSETCOLORADJUSTMENT as tagEMRSETCOLORADJUSTMENT
type PEMRSETCOLORADJUSTMENT as tagEMRSETCOLORADJUSTMENT ptr

type tagEMRGDICOMMENT
	emr as EMR
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRGDICOMMENT as tagEMRGDICOMMENT
type PEMRGDICOMMENT as tagEMRGDICOMMENT ptr

type tagEMREOF
	emr as EMR
	nPalEntries as DWORD
	offPalEntries as DWORD
	nSizeLast as DWORD
end type

type EMREOF as tagEMREOF
type PEMREOF as tagEMREOF ptr

type tagEMRLINETO
	emr as EMR
	ptl as POINTL
end type

type EMRLINETO as tagEMRLINETO
type PEMRLINETO as tagEMRLINETO ptr
type EMRMOVETOEX as tagEMRLINETO
type PEMRMOVETOEX as tagEMRLINETO ptr

type tagEMROFFSETCLIPRGN
	emr as EMR
	ptlOffset as POINTL
end type

type EMROFFSETCLIPRGN as tagEMROFFSETCLIPRGN
type PEMROFFSETCLIPRGN as tagEMROFFSETCLIPRGN ptr

type tagEMRFILLPATH
	emr as EMR
	rclBounds as RECTL
end type

type EMRFILLPATH as tagEMRFILLPATH
type PEMRFILLPATH as tagEMRFILLPATH ptr
type EMRSTROKEANDFILLPATH as tagEMRFILLPATH
type PEMRSTROKEANDFILLPATH as tagEMRFILLPATH ptr
type EMRSTROKEPATH as tagEMRFILLPATH
type PEMRSTROKEPATH as tagEMRFILLPATH ptr

type tagEMREXCLUDECLIPRECT
	emr as EMR
	rclClip as RECTL
end type

type EMREXCLUDECLIPRECT as tagEMREXCLUDECLIPRECT
type PEMREXCLUDECLIPRECT as tagEMREXCLUDECLIPRECT ptr
type EMRINTERSECTCLIPRECT as tagEMREXCLUDECLIPRECT
type PEMRINTERSECTCLIPRECT as tagEMREXCLUDECLIPRECT ptr

type tagEMRSETVIEWPORTORGEX
	emr as EMR
	ptlOrigin as POINTL
end type

type EMRSETVIEWPORTORGEX as tagEMRSETVIEWPORTORGEX
type PEMRSETVIEWPORTORGEX as tagEMRSETVIEWPORTORGEX ptr
type EMRSETWINDOWORGEX as tagEMRSETVIEWPORTORGEX
type PEMRSETWINDOWORGEX as tagEMRSETVIEWPORTORGEX ptr
type EMRSETBRUSHORGEX as tagEMRSETVIEWPORTORGEX
type PEMRSETBRUSHORGEX as tagEMRSETVIEWPORTORGEX ptr

type tagEMRSETVIEWPORTEXTEX
	emr as EMR
	szlExtent as SIZEL
end type

type EMRSETVIEWPORTEXTEX as tagEMRSETVIEWPORTEXTEX
type PEMRSETVIEWPORTEXTEX as tagEMRSETVIEWPORTEXTEX ptr
type EMRSETWINDOWEXTEX as tagEMRSETVIEWPORTEXTEX
type PEMRSETWINDOWEXTEX as tagEMRSETVIEWPORTEXTEX ptr

type tagEMRSCALEVIEWPORTEXTEX
	emr as EMR
	xNum as LONG
	xDenom as LONG
	yNum as LONG
	yDenom as LONG
end type

type EMRSCALEVIEWPORTEXTEX as tagEMRSCALEVIEWPORTEXTEX
type PEMRSCALEVIEWPORTEXTEX as tagEMRSCALEVIEWPORTEXTEX ptr
type EMRSCALEWINDOWEXTEX as tagEMRSCALEVIEWPORTEXTEX
type PEMRSCALEWINDOWEXTEX as tagEMRSCALEVIEWPORTEXTEX ptr

type tagEMRSETWORLDTRANSFORM
	emr as EMR
	xform as XFORM
end type

type EMRSETWORLDTRANSFORM as tagEMRSETWORLDTRANSFORM
type PEMRSETWORLDTRANSFORM as tagEMRSETWORLDTRANSFORM ptr

type tagEMRMODIFYWORLDTRANSFORM
	emr as EMR
	xform as XFORM
	iMode as DWORD
end type

type EMRMODIFYWORLDTRANSFORM as tagEMRMODIFYWORLDTRANSFORM
type PEMRMODIFYWORLDTRANSFORM as tagEMRMODIFYWORLDTRANSFORM ptr

type tagEMRSETPIXELV
	emr as EMR
	ptlPixel as POINTL
	crColor as COLORREF
end type

type EMRSETPIXELV as tagEMRSETPIXELV
type PEMRSETPIXELV as tagEMRSETPIXELV ptr

type tagEMREXTFLOODFILL
	emr as EMR
	ptlStart as POINTL
	crColor as COLORREF
	iMode as DWORD
end type

type EMREXTFLOODFILL as tagEMREXTFLOODFILL
type PEMREXTFLOODFILL as tagEMREXTFLOODFILL ptr

type tagEMRELLIPSE
	emr as EMR
	rclBox as RECTL
end type

type EMRELLIPSE as tagEMRELLIPSE
type PEMRELLIPSE as tagEMRELLIPSE ptr
type EMRRECTANGLE as tagEMRELLIPSE
type PEMRRECTANGLE as tagEMRELLIPSE ptr

type tagEMRROUNDRECT
	emr as EMR
	rclBox as RECTL
	szlCorner as SIZEL
end type

type EMRROUNDRECT as tagEMRROUNDRECT
type PEMRROUNDRECT as tagEMRROUNDRECT ptr

type tagEMRARC
	emr as EMR
	rclBox as RECTL
	ptlStart as POINTL
	ptlEnd as POINTL
end type

type EMRARC as tagEMRARC
type PEMRARC as tagEMRARC ptr
type EMRARCTO as tagEMRARC
type PEMRARCTO as tagEMRARC ptr
type EMRCHORD as tagEMRARC
type PEMRCHORD as tagEMRARC ptr
type EMRPIE as tagEMRARC
type PEMRPIE as tagEMRARC ptr

type tagEMRANGLEARC
	emr as EMR
	ptlCenter as POINTL
	nRadius as DWORD
	eStartAngle as FLOAT
	eSweepAngle as FLOAT
end type

type EMRANGLEARC as tagEMRANGLEARC
type PEMRANGLEARC as tagEMRANGLEARC ptr

type tagEMRPOLYLINE
	emr as EMR
	rclBounds as RECTL
	cptl as DWORD
	aptl(0 to 0) as POINTL
end type

type EMRPOLYLINE as tagEMRPOLYLINE
type PEMRPOLYLINE as tagEMRPOLYLINE ptr
type EMRPOLYBEZIER as tagEMRPOLYLINE
type PEMRPOLYBEZIER as tagEMRPOLYLINE ptr
type EMRPOLYGON as tagEMRPOLYLINE
type PEMRPOLYGON as tagEMRPOLYLINE ptr
type EMRPOLYBEZIERTO as tagEMRPOLYLINE
type PEMRPOLYBEZIERTO as tagEMRPOLYLINE ptr
type EMRPOLYLINETO as tagEMRPOLYLINE
type PEMRPOLYLINETO as tagEMRPOLYLINE ptr

type tagEMRPOLYLINE16
	emr as EMR
	rclBounds as RECTL
	cpts as DWORD
	apts(0 to 0) as POINTS
end type

type EMRPOLYLINE16 as tagEMRPOLYLINE16
type PEMRPOLYLINE16 as tagEMRPOLYLINE16 ptr
type EMRPOLYBEZIER16 as tagEMRPOLYLINE16
type PEMRPOLYBEZIER16 as tagEMRPOLYLINE16 ptr
type EMRPOLYGON16 as tagEMRPOLYLINE16
type PEMRPOLYGON16 as tagEMRPOLYLINE16 ptr
type EMRPOLYBEZIERTO16 as tagEMRPOLYLINE16
type PEMRPOLYBEZIERTO16 as tagEMRPOLYLINE16 ptr
type EMRPOLYLINETO16 as tagEMRPOLYLINE16
type PEMRPOLYLINETO16 as tagEMRPOLYLINE16 ptr

type tagEMRPOLYDRAW
	emr as EMR
	rclBounds as RECTL
	cptl as DWORD
	aptl(0 to 0) as POINTL
	abTypes(0 to 0) as UBYTE
end type

type EMRPOLYDRAW as tagEMRPOLYDRAW
type PEMRPOLYDRAW as tagEMRPOLYDRAW ptr

type tagEMRPOLYDRAW16
	emr as EMR
	rclBounds as RECTL
	cpts as DWORD
	apts(0 to 0) as POINTS
	abTypes(0 to 0) as UBYTE
end type

type EMRPOLYDRAW16 as tagEMRPOLYDRAW16
type PEMRPOLYDRAW16 as tagEMRPOLYDRAW16 ptr

type tagEMRPOLYPOLYLINE
	emr as EMR
	rclBounds as RECTL
	nPolys as DWORD
	cptl as DWORD
	aPolyCounts(0 to 0) as DWORD
	aptl(0 to 0) as POINTL
end type

type EMRPOLYPOLYLINE as tagEMRPOLYPOLYLINE
type PEMRPOLYPOLYLINE as tagEMRPOLYPOLYLINE ptr
type EMRPOLYPOLYGON as tagEMRPOLYPOLYLINE
type PEMRPOLYPOLYGON as tagEMRPOLYPOLYLINE ptr

type tagEMRPOLYPOLYLINE16
	emr as EMR
	rclBounds as RECTL
	nPolys as DWORD
	cpts as DWORD
	aPolyCounts(0 to 0) as DWORD
	apts(0 to 0) as POINTS
end type

type EMRPOLYPOLYLINE16 as tagEMRPOLYPOLYLINE16
type PEMRPOLYPOLYLINE16 as tagEMRPOLYPOLYLINE16 ptr
type EMRPOLYPOLYGON16 as tagEMRPOLYPOLYLINE16
type PEMRPOLYPOLYGON16 as tagEMRPOLYPOLYLINE16 ptr

type tagEMRINVERTRGN
	emr as EMR
	rclBounds as RECTL
	cbRgnData as DWORD
	RgnData(0 to 0) as UBYTE
end type

type EMRINVERTRGN as tagEMRINVERTRGN
type PEMRINVERTRGN as tagEMRINVERTRGN ptr
type EMRPAINTRGN as tagEMRINVERTRGN
type PEMRPAINTRGN as tagEMRINVERTRGN ptr

type tagEMRFILLRGN
	emr as EMR
	rclBounds as RECTL
	cbRgnData as DWORD
	ihBrush as DWORD
	RgnData(0 to 0) as UBYTE
end type

type EMRFILLRGN as tagEMRFILLRGN
type PEMRFILLRGN as tagEMRFILLRGN ptr

type tagEMRFRAMERGN
	emr as EMR
	rclBounds as RECTL
	cbRgnData as DWORD
	ihBrush as DWORD
	szlStroke as SIZEL
	RgnData(0 to 0) as UBYTE
end type

type EMRFRAMERGN as tagEMRFRAMERGN
type PEMRFRAMERGN as tagEMRFRAMERGN ptr

type tagEMREXTSELECTCLIPRGN
	emr as EMR
	cbRgnData as DWORD
	iMode as DWORD
	RgnData(0 to 0) as UBYTE
end type

type EMREXTSELECTCLIPRGN as tagEMREXTSELECTCLIPRGN
type PEMREXTSELECTCLIPRGN as tagEMREXTSELECTCLIPRGN ptr

type tagEMREXTTEXTOUTA
	emr as EMR
	rclBounds as RECTL
	iGraphicsMode as DWORD
	exScale as FLOAT
	eyScale as FLOAT
	emrtext as EMRTEXT
end type

type EMREXTTEXTOUTA as tagEMREXTTEXTOUTA
type PEMREXTTEXTOUTA as tagEMREXTTEXTOUTA ptr
type EMREXTTEXTOUTW as tagEMREXTTEXTOUTA
type PEMREXTTEXTOUTW as tagEMREXTTEXTOUTA ptr

type tagEMRPOLYTEXTOUTA
	emr as EMR
	rclBounds as RECTL
	iGraphicsMode as DWORD
	exScale as FLOAT
	eyScale as FLOAT
	cStrings as LONG
	aemrtext(0 to 0) as EMRTEXT
end type

type EMRPOLYTEXTOUTA as tagEMRPOLYTEXTOUTA
type PEMRPOLYTEXTOUTA as tagEMRPOLYTEXTOUTA ptr
type EMRPOLYTEXTOUTW as tagEMRPOLYTEXTOUTA
type PEMRPOLYTEXTOUTW as tagEMRPOLYTEXTOUTA ptr

type tagEMRBITBLT
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	cxDest as LONG
	cyDest as LONG
	dwRop as DWORD
	xSrc as LONG
	ySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
end type

type EMRBITBLT as tagEMRBITBLT
type PEMRBITBLT as tagEMRBITBLT ptr

type tagEMRSTRETCHBLT
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	cxDest as LONG
	cyDest as LONG
	dwRop as DWORD
	xSrc as LONG
	ySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	cxSrc as LONG
	cySrc as LONG
end type

type EMRSTRETCHBLT as tagEMRSTRETCHBLT
type PEMRSTRETCHBLT as tagEMRSTRETCHBLT ptr

type tagEMRMASKBLT
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	cxDest as LONG
	cyDest as LONG
	dwRop as DWORD
	xSrc as LONG
	ySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	xMask as LONG
	yMask as LONG
	iUsageMask as DWORD
	offBmiMask as DWORD
	cbBmiMask as DWORD
	offBitsMask as DWORD
	cbBitsMask as DWORD
end type

type EMRMASKBLT as tagEMRMASKBLT
type PEMRMASKBLT as tagEMRMASKBLT ptr

type tagEMRPLGBLT
	emr as EMR
	rclBounds as RECTL
	aptlDest(0 to 2) as POINTL
	xSrc as LONG
	ySrc as LONG
	cxSrc as LONG
	cySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	xMask as LONG
	yMask as LONG
	iUsageMask as DWORD
	offBmiMask as DWORD
	cbBmiMask as DWORD
	offBitsMask as DWORD
	cbBitsMask as DWORD
end type

type EMRPLGBLT as tagEMRPLGBLT
type PEMRPLGBLT as tagEMRPLGBLT ptr

type tagEMRSETDIBITSTODEVICE
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	xSrc as LONG
	ySrc as LONG
	cxSrc as LONG
	cySrc as LONG
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	iUsageSrc as DWORD
	iStartScan as DWORD
	cScans as DWORD
end type

type EMRSETDIBITSTODEVICE as tagEMRSETDIBITSTODEVICE
type PEMRSETDIBITSTODEVICE as tagEMRSETDIBITSTODEVICE ptr

type tagEMRSTRETCHDIBITS
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	xSrc as LONG
	ySrc as LONG
	cxSrc as LONG
	cySrc as LONG
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	iUsageSrc as DWORD
	dwRop as DWORD
	cxDest as LONG
	cyDest as LONG
end type

type EMRSTRETCHDIBITS as tagEMRSTRETCHDIBITS
type PEMRSTRETCHDIBITS as tagEMRSTRETCHDIBITS ptr

type tagEMREXTCREATEFONTINDIRECTW
	emr as EMR
	ihFont as DWORD
	elfw as EXTLOGFONTW
end type

type EMREXTCREATEFONTINDIRECTW as tagEMREXTCREATEFONTINDIRECTW
type PEMREXTCREATEFONTINDIRECTW as tagEMREXTCREATEFONTINDIRECTW ptr

type tagEMRCREATEPALETTE
	emr as EMR
	ihPal as DWORD
	lgpl as LOGPALETTE
end type

type EMRCREATEPALETTE as tagEMRCREATEPALETTE
type PEMRCREATEPALETTE as tagEMRCREATEPALETTE ptr

type tagEMRCREATEPEN
	emr as EMR
	ihPen as DWORD
	lopn as LOGPEN
end type

type EMRCREATEPEN as tagEMRCREATEPEN
type PEMRCREATEPEN as tagEMRCREATEPEN ptr

type tagEMREXTCREATEPEN
	emr as EMR
	ihPen as DWORD
	offBmi as DWORD
	cbBmi as DWORD
	offBits as DWORD
	cbBits as DWORD
	elp as EXTLOGPEN
end type

type EMREXTCREATEPEN as tagEMREXTCREATEPEN
type PEMREXTCREATEPEN as tagEMREXTCREATEPEN ptr

type tagEMRCREATEBRUSHINDIRECT
	emr as EMR
	ihBrush as DWORD
	lb as LOGBRUSH32
end type

type EMRCREATEBRUSHINDIRECT as tagEMRCREATEBRUSHINDIRECT
type PEMRCREATEBRUSHINDIRECT as tagEMRCREATEBRUSHINDIRECT ptr

type tagEMRCREATEMONOBRUSH
	emr as EMR
	ihBrush as DWORD
	iUsage as DWORD
	offBmi as DWORD
	cbBmi as DWORD
	offBits as DWORD
	cbBits as DWORD
end type

type EMRCREATEMONOBRUSH as tagEMRCREATEMONOBRUSH
type PEMRCREATEMONOBRUSH as tagEMRCREATEMONOBRUSH ptr

type tagEMRCREATEDIBPATTERNBRUSHPT
	emr as EMR
	ihBrush as DWORD
	iUsage as DWORD
	offBmi as DWORD
	cbBmi as DWORD
	offBits as DWORD
	cbBits as DWORD
end type

type EMRCREATEDIBPATTERNBRUSHPT as tagEMRCREATEDIBPATTERNBRUSHPT
type PEMRCREATEDIBPATTERNBRUSHPT as tagEMRCREATEDIBPATTERNBRUSHPT ptr

type tagEMRFORMAT
	dSignature as DWORD
	nVersion as DWORD
	cbData as DWORD
	offData as DWORD
end type

type EMRFORMAT as tagEMRFORMAT
type PEMRFORMAT as tagEMRFORMAT ptr

type tagEMRGLSRECORD
	emr as EMR
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRGLSRECORD as tagEMRGLSRECORD
type PEMRGLSRECORD as tagEMRGLSRECORD ptr

type tagEMRGLSBOUNDEDRECORD
	emr as EMR
	rclBounds as RECTL
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRGLSBOUNDEDRECORD as tagEMRGLSBOUNDEDRECORD
type PEMRGLSBOUNDEDRECORD as tagEMRGLSBOUNDEDRECORD ptr

type tagEMRPIXELFORMAT
	emr as EMR
	pfd as PIXELFORMATDESCRIPTOR
end type

type EMRPIXELFORMAT as tagEMRPIXELFORMAT
type PEMRPIXELFORMAT as tagEMRPIXELFORMAT ptr

type tagEMRCREATECOLORSPACE
	emr as EMR
	ihCS as DWORD
	lcs as LOGCOLORSPACEA
end type

type EMRCREATECOLORSPACE as tagEMRCREATECOLORSPACE
type PEMRCREATECOLORSPACE as tagEMRCREATECOLORSPACE ptr

type tagEMRSETCOLORSPACE
	emr as EMR
	ihCS as DWORD
end type

type EMRSETCOLORSPACE as tagEMRSETCOLORSPACE
type PEMRSETCOLORSPACE as tagEMRSETCOLORSPACE ptr
type EMRSELECTCOLORSPACE as tagEMRSETCOLORSPACE
type PEMRSELECTCOLORSPACE as tagEMRSETCOLORSPACE ptr
type EMRDELETECOLORSPACE as tagEMRSETCOLORSPACE
type PEMRDELETECOLORSPACE as tagEMRSETCOLORSPACE ptr

type tagEMREXTESCAPE
	emr as EMR
	iEscape as INT_
	cbEscData as INT_
	EscData(0 to 0) as UBYTE
end type

type EMREXTESCAPE as tagEMREXTESCAPE
type PEMREXTESCAPE as tagEMREXTESCAPE ptr
type EMRDRAWESCAPE as tagEMREXTESCAPE
type PEMRDRAWESCAPE as tagEMREXTESCAPE ptr

type tagEMRNAMEDESCAPE
	emr as EMR
	iEscape as INT_
	cbDriver as INT_
	cbEscData as INT_
	EscData(0 to 0) as UBYTE
end type

type EMRNAMEDESCAPE as tagEMRNAMEDESCAPE
type PEMRNAMEDESCAPE as tagEMRNAMEDESCAPE ptr
const SETICMPROFILE_EMBEDED = &h00000001

type tagEMRSETICMPROFILE
	emr as EMR
	dwFlags as DWORD
	cbName as DWORD
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRSETICMPROFILE as tagEMRSETICMPROFILE
type PEMRSETICMPROFILE as tagEMRSETICMPROFILE ptr
type EMRSETICMPROFILEA as tagEMRSETICMPROFILE
type PEMRSETICMPROFILEA as tagEMRSETICMPROFILE ptr
type EMRSETICMPROFILEW as tagEMRSETICMPROFILE
type PEMRSETICMPROFILEW as tagEMRSETICMPROFILE ptr
const CREATECOLORSPACE_EMBEDED = &h00000001

type tagEMRCREATECOLORSPACEW
	emr as EMR
	ihCS as DWORD
	lcs as LOGCOLORSPACEW
	dwFlags as DWORD
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRCREATECOLORSPACEW as tagEMRCREATECOLORSPACEW
type PEMRCREATECOLORSPACEW as tagEMRCREATECOLORSPACEW ptr
const COLORMATCHTOTARGET_EMBEDED = &h00000001

type tagCOLORMATCHTOTARGET
	emr as EMR
	dwAction as DWORD
	dwFlags as DWORD
	cbName as DWORD
	cbData as DWORD
	Data(0 to 0) as UBYTE
end type

type EMRCOLORMATCHTOTARGET as tagCOLORMATCHTOTARGET
type PEMRCOLORMATCHTOTARGET as tagCOLORMATCHTOTARGET ptr

type tagCOLORCORRECTPALETTE
	emr as EMR
	ihPalette as DWORD
	nFirstEntry as DWORD
	nPalEntries as DWORD
	nReserved as DWORD
end type

type EMRCOLORCORRECTPALETTE as tagCOLORCORRECTPALETTE
type PEMRCOLORCORRECTPALETTE as tagCOLORCORRECTPALETTE ptr

type tagEMRALPHABLEND
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	cxDest as LONG
	cyDest as LONG
	dwRop as DWORD
	xSrc as LONG
	ySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	cxSrc as LONG
	cySrc as LONG
end type

type EMRALPHABLEND as tagEMRALPHABLEND
type PEMRALPHABLEND as tagEMRALPHABLEND ptr

type tagEMRGRADIENTFILL
	emr as EMR
	rclBounds as RECTL
	nVer as DWORD
	nTri as DWORD
	ulMode as ULONG
	Ver(0 to 0) as TRIVERTEX
end type

type EMRGRADIENTFILL as tagEMRGRADIENTFILL
type PEMRGRADIENTFILL as tagEMRGRADIENTFILL ptr

type tagEMRTRANSPARENTBLT
	emr as EMR
	rclBounds as RECTL
	xDest as LONG
	yDest as LONG
	cxDest as LONG
	cyDest as LONG
	dwRop as DWORD
	xSrc as LONG
	ySrc as LONG
	xformSrc as XFORM
	crBkColorSrc as COLORREF
	iUsageSrc as DWORD
	offBmiSrc as DWORD
	cbBmiSrc as DWORD
	offBitsSrc as DWORD
	cbBitsSrc as DWORD
	cxSrc as LONG
	cySrc as LONG
end type

type EMRTRANSPARENTBLT as tagEMRTRANSPARENTBLT
type PEMRTRANSPARENTBLT as tagEMRTRANSPARENTBLT ptr
const GDICOMMENT_IDENTIFIER = &h43494447
const GDICOMMENT_WINDOWS_METAFILE = &h80000001
const GDICOMMENT_BEGINGROUP = &h00000002
const GDICOMMENT_ENDGROUP = &h00000003
const GDICOMMENT_MULTIFORMATS = &h40000004
const EPS_SIGNATURE = &h46535045
const GDICOMMENT_UNICODE_STRING = &h00000040
const GDICOMMENT_UNICODE_END = &h00000080

declare function wglCopyContext(byval as HGLRC, byval as HGLRC, byval as UINT) as WINBOOL
declare function wglCreateContext(byval as HDC) as HGLRC
declare function wglCreateLayerContext(byval as HDC, byval as long) as HGLRC
declare function wglDeleteContext(byval as HGLRC) as WINBOOL
declare function wglGetCurrentContext() as HGLRC
declare function wglGetCurrentDC() as HDC
declare function wglGetProcAddress(byval as LPCSTR) as PROC
declare function wglMakeCurrent(byval as HDC, byval as HGLRC) as WINBOOL
declare function wglShareLists(byval as HGLRC, byval as HGLRC) as WINBOOL
declare function wglUseFontBitmapsA(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD) as WINBOOL

#ifndef UNICODE
	declare function wglUseFontBitmaps alias "wglUseFontBitmapsA"(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD) as WINBOOL
#endif

declare function wglUseFontBitmapsW(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD) as WINBOOL

#ifdef UNICODE
	declare function wglUseFontBitmaps alias "wglUseFontBitmapsW"(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD) as WINBOOL
#endif

declare function SwapBuffers(byval as HDC) as WINBOOL

type _POINTFLOAT
	x as FLOAT
	y as FLOAT
end type

type POINTFLOAT as _POINTFLOAT
type PPOINTFLOAT as _POINTFLOAT ptr

type _GLYPHMETRICSFLOAT
	gmfBlackBoxX as FLOAT
	gmfBlackBoxY as FLOAT
	gmfptGlyphOrigin as POINTFLOAT
	gmfCellIncX as FLOAT
	gmfCellIncY as FLOAT
end type

type GLYPHMETRICSFLOAT as _GLYPHMETRICSFLOAT
type PGLYPHMETRICSFLOAT as _GLYPHMETRICSFLOAT ptr
type LPGLYPHMETRICSFLOAT as _GLYPHMETRICSFLOAT ptr
const WGL_FONT_LINES = 0
const WGL_FONT_POLYGONS = 1
declare function wglUseFontOutlinesA(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD, byval as FLOAT, byval as FLOAT, byval as long, byval as LPGLYPHMETRICSFLOAT) as WINBOOL

#ifndef UNICODE
	declare function wglUseFontOutlines alias "wglUseFontOutlinesA"(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD, byval as FLOAT, byval as FLOAT, byval as long, byval as LPGLYPHMETRICSFLOAT) as WINBOOL
#endif

declare function wglUseFontOutlinesW(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD, byval as FLOAT, byval as FLOAT, byval as long, byval as LPGLYPHMETRICSFLOAT) as WINBOOL

#ifdef UNICODE
	declare function wglUseFontOutlines alias "wglUseFontOutlinesW"(byval as HDC, byval as DWORD, byval as DWORD, byval as DWORD, byval as FLOAT, byval as FLOAT, byval as long, byval as LPGLYPHMETRICSFLOAT) as WINBOOL
#endif

type tagLAYERPLANEDESCRIPTOR
	nSize as WORD
	nVersion as WORD
	dwFlags as DWORD
	iPixelType as UBYTE
	cColorBits as UBYTE
	cRedBits as UBYTE
	cRedShift as UBYTE
	cGreenBits as UBYTE
	cGreenShift as UBYTE
	cBlueBits as UBYTE
	cBlueShift as UBYTE
	cAlphaBits as UBYTE
	cAlphaShift as UBYTE
	cAccumBits as UBYTE
	cAccumRedBits as UBYTE
	cAccumGreenBits as UBYTE
	cAccumBlueBits as UBYTE
	cAccumAlphaBits as UBYTE
	cDepthBits as UBYTE
	cStencilBits as UBYTE
	cAuxBuffers as UBYTE
	iLayerPlane as UBYTE
	bReserved as UBYTE
	crTransparent as COLORREF
end type

type LAYERPLANEDESCRIPTOR as tagLAYERPLANEDESCRIPTOR
type PLAYERPLANEDESCRIPTOR as tagLAYERPLANEDESCRIPTOR ptr
type LPLAYERPLANEDESCRIPTOR as tagLAYERPLANEDESCRIPTOR ptr

const LPD_DOUBLEBUFFER = &h00000001
const LPD_STEREO = &h00000002
const LPD_SUPPORT_GDI = &h00000010
const LPD_SUPPORT_OPENGL = &h00000020
const LPD_SHARE_DEPTH = &h00000040
const LPD_SHARE_STENCIL = &h00000080
const LPD_SHARE_ACCUM = &h00000100
const LPD_SWAP_EXCHANGE = &h00000200
const LPD_SWAP_COPY = &h00000400
const LPD_TRANSPARENT = &h00001000
const LPD_TYPE_RGBA = 0
const LPD_TYPE_COLORINDEX = 1
const WGL_SWAP_MAIN_PLANE = &h00000001
const WGL_SWAP_OVERLAY1 = &h00000002
const WGL_SWAP_OVERLAY2 = &h00000004
const WGL_SWAP_OVERLAY3 = &h00000008
const WGL_SWAP_OVERLAY4 = &h00000010
const WGL_SWAP_OVERLAY5 = &h00000020
const WGL_SWAP_OVERLAY6 = &h00000040
const WGL_SWAP_OVERLAY7 = &h00000080
const WGL_SWAP_OVERLAY8 = &h00000100
const WGL_SWAP_OVERLAY9 = &h00000200
const WGL_SWAP_OVERLAY10 = &h00000400
const WGL_SWAP_OVERLAY11 = &h00000800
const WGL_SWAP_OVERLAY12 = &h00001000
const WGL_SWAP_OVERLAY13 = &h00002000
const WGL_SWAP_OVERLAY14 = &h00004000
const WGL_SWAP_OVERLAY15 = &h00008000
const WGL_SWAP_UNDERLAY1 = &h00010000
const WGL_SWAP_UNDERLAY2 = &h00020000
const WGL_SWAP_UNDERLAY3 = &h00040000
const WGL_SWAP_UNDERLAY4 = &h00080000
const WGL_SWAP_UNDERLAY5 = &h00100000
const WGL_SWAP_UNDERLAY6 = &h00200000
const WGL_SWAP_UNDERLAY7 = &h00400000
const WGL_SWAP_UNDERLAY8 = &h00800000
const WGL_SWAP_UNDERLAY9 = &h01000000
const WGL_SWAP_UNDERLAY10 = &h02000000
const WGL_SWAP_UNDERLAY11 = &h04000000
const WGL_SWAP_UNDERLAY12 = &h08000000
const WGL_SWAP_UNDERLAY13 = &h10000000
const WGL_SWAP_UNDERLAY14 = &h20000000
const WGL_SWAP_UNDERLAY15 = &h40000000

declare function wglDescribeLayerPlane(byval as HDC, byval as long, byval as long, byval as UINT, byval as LPLAYERPLANEDESCRIPTOR) as WINBOOL
declare function wglSetLayerPaletteEntries(byval as HDC, byval as long, byval as long, byval as long, byval as const COLORREF ptr) as long
declare function wglGetLayerPaletteEntries(byval as HDC, byval as long, byval as long, byval as long, byval as COLORREF ptr) as long
declare function wglRealizeLayerPalette(byval as HDC, byval as long, byval as WINBOOL) as WINBOOL
declare function wglSwapLayerBuffers(byval as HDC, byval as UINT) as WINBOOL

type _WGLSWAP
	hdc as HDC
	uiFlags as UINT
end type

type WGLSWAP as _WGLSWAP
type PWGLSWAP as _WGLSWAP ptr
type LPWGLSWAP as _WGLSWAP ptr
const WGL_SWAPMULTIPLE_MAX = 16
declare function wglSwapMultipleBuffers(byval as UINT, byval as const WGLSWAP ptr) as DWORD

end extern

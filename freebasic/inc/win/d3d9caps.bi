'' FreeBASIC binding for mingw-w64-v4.0.4
''
'' based on the C header files:
''   Copyright (C) 2002-2003 Jason Edmeades
''                           Raphael Junqueira
''
''   This library is free software; you can redistribute it and/or
''   modify it under the terms of the GNU Lesser General Public
''   License as published by the Free Software Foundation; either
''   version 2.1 of the License, or (at your option) any later version.
''
''   This library is distributed in the hope that it will be useful,
''   but WITHOUT ANY WARRANTY; without even the implied warranty of
''   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
''   Lesser General Public License for more details.
''
''   You should have received a copy of the GNU Lesser General Public
''   License along with this library; if not, write to the Free Software
''   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
''
'' translated to FreeBASIC by:
''   FreeBASIC development team

#pragma once

#define __WINE_D3D9CAPS_H
const D3DCAPS_READ_SCANLINE = &h20000
const D3DCURSORCAPS_COLOR = 1
const D3DCURSORCAPS_LOWRES = 2
const D3DDEVCAPS2_STREAMOFFSET = &h00000001
const D3DDEVCAPS2_DMAPNPATCH = &h00000002
const D3DDEVCAPS2_ADAPTIVETESSRTPATCH = &h00000004
const D3DDEVCAPS2_ADAPTIVETESSNPATCH = &h00000008
const D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES = &h00000010
const D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH = &h00000020
const D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET = &h00000040
const D3DDEVCAPS_EXECUTESYSTEMMEMORY = &h0000010
const D3DDEVCAPS_EXECUTEVIDEOMEMORY = &h0000020
const D3DDEVCAPS_TLVERTEXSYSTEMMEMORY = &h0000040
const D3DDEVCAPS_TLVERTEXVIDEOMEMORY = &h0000080
const D3DDEVCAPS_TEXTURESYSTEMMEMORY = &h0000100
const D3DDEVCAPS_TEXTUREVIDEOMEMORY = &h0000200
const D3DDEVCAPS_DRAWPRIMTLVERTEX = &h0000400
const D3DDEVCAPS_CANRENDERAFTERFLIP = &h0000800
const D3DDEVCAPS_TEXTURENONLOCALVIDMEM = &h0001000
const D3DDEVCAPS_DRAWPRIMITIVES2 = &h0002000
const D3DDEVCAPS_SEPARATETEXTUREMEMORIES = &h0004000
const D3DDEVCAPS_DRAWPRIMITIVES2EX = &h0008000
const D3DDEVCAPS_HWTRANSFORMANDLIGHT = &h0010000
const D3DDEVCAPS_CANBLTSYSTONONLOCAL = &h0020000
const D3DDEVCAPS_HWRASTERIZATION = &h0080000
const D3DDEVCAPS_PUREDEVICE = &h0100000
const D3DDEVCAPS_QUINTICRTPATCHES = &h0200000
const D3DDEVCAPS_RTPATCHES = &h0400000
const D3DDEVCAPS_RTPATCHHANDLEZERO = &h0800000
const D3DDEVCAPS_NPATCHES = &h1000000
const D3DFVFCAPS_TEXCOORDCOUNTMASK = &h00FFFF
const D3DFVFCAPS_DONOTSTRIPELEMENTS = &h080000
const D3DFVFCAPS_PSIZE = &h100000
const D3DLINECAPS_TEXTURE = &h01
const D3DLINECAPS_ZTEST = &h02
const D3DLINECAPS_BLEND = &h04
const D3DLINECAPS_ALPHACMP = &h08
const D3DLINECAPS_FOG = &h10
const D3DLINECAPS_ANTIALIAS = &h20
const D3DPBLENDCAPS_ZERO = &h00000001
const D3DPBLENDCAPS_ONE = &h00000002
const D3DPBLENDCAPS_SRCCOLOR = &h00000004
const D3DPBLENDCAPS_INVSRCCOLOR = &h00000008
const D3DPBLENDCAPS_SRCALPHA = &h00000010
const D3DPBLENDCAPS_INVSRCALPHA = &h00000020
const D3DPBLENDCAPS_DESTALPHA = &h00000040
const D3DPBLENDCAPS_INVDESTALPHA = &h00000080
const D3DPBLENDCAPS_DESTCOLOR = &h00000100
const D3DPBLENDCAPS_INVDESTCOLOR = &h00000200
const D3DPBLENDCAPS_SRCALPHASAT = &h00000400
const D3DPBLENDCAPS_BOTHSRCALPHA = &h00000800
const D3DPBLENDCAPS_BOTHINVSRCALPHA = &h00001000
const D3DPBLENDCAPS_BLENDFACTOR = &h00002000
const D3DPCMPCAPS_NEVER = &h01
const D3DPCMPCAPS_LESS = &h02
const D3DPCMPCAPS_EQUAL = &h04
const D3DPCMPCAPS_LESSEQUAL = &h08
const D3DPCMPCAPS_GREATER = &h10
const D3DPCMPCAPS_NOTEQUAL = &h20
const D3DPCMPCAPS_GREATEREQUAL = &h40
const D3DPCMPCAPS_ALWAYS = &h80
const D3DPMISCCAPS_MASKZ = &h00000002
const D3DPMISCCAPS_LINEPATTERNREP = &h00000004
const D3DPMISCCAPS_CULLNONE = &h00000010
const D3DPMISCCAPS_CULLCW = &h00000020
const D3DPMISCCAPS_CULLCCW = &h00000040
const D3DPMISCCAPS_COLORWRITEENABLE = &h00000080
const D3DPMISCCAPS_CLIPPLANESCALEDPOINTS = &h00000100
const D3DPMISCCAPS_CLIPTLVERTS = &h00000200
const D3DPMISCCAPS_TSSARGTEMP = &h00000400
const D3DPMISCCAPS_BLENDOP = &h00000800
const D3DPMISCCAPS_NULLREFERENCE = &h00001000
const D3DPMISCCAPS_INDEPENDENTWRITEMASKS = &h00004000
const D3DPMISCCAPS_PERSTAGECONSTANT = &h00008000
const D3DPMISCCAPS_FOGANDSPECULARALPHA = &h00010000
const D3DPMISCCAPS_SEPARATEALPHABLEND = &h00020000
const D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS = &h00040000
const D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING = &h00080000
const D3DPMISCCAPS_FOGVERTEXCLAMPED = &h00100000
const D3DPRASTERCAPS_DITHER = &h00000001
const D3DPRASTERCAPS_PAT = &h00000008
const D3DPRASTERCAPS_ZTEST = &h00000010
const D3DPRASTERCAPS_FOGVERTEX = &h00000080
const D3DPRASTERCAPS_FOGTABLE = &h00000100
const D3DPRASTERCAPS_ANTIALIASEDGES = &h00001000
const D3DPRASTERCAPS_MIPMAPLODBIAS = &h00002000
const D3DPRASTERCAPS_ZBIAS = &h00004000
const D3DPRASTERCAPS_ZBUFFERLESSHSR = &h00008000
const D3DPRASTERCAPS_FOGRANGE = &h00010000
const D3DPRASTERCAPS_ANISOTROPY = &h00020000
const D3DPRASTERCAPS_WBUFFER = &h00040000
const D3DPRASTERCAPS_WFOG = &h00100000
const D3DPRASTERCAPS_ZFOG = &h00200000
const D3DPRASTERCAPS_COLORPERSPECTIVE = &h00400000
const D3DPRASTERCAPS_SCISSORTEST = &h01000000
const D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS = &h02000000
const D3DPRASTERCAPS_DEPTHBIAS = &h04000000
const D3DPRASTERCAPS_MULTISAMPLE_TOGGLE = &h08000000
const D3DPRESENT_INTERVAL_DEFAULT = &h00000000
const D3DPRESENT_INTERVAL_ONE = &h00000001
const D3DPRESENT_INTERVAL_TWO = &h00000002
const D3DPRESENT_INTERVAL_THREE = &h00000004
const D3DPRESENT_INTERVAL_FOUR = &h00000008
const D3DPRESENT_INTERVAL_IMMEDIATE = &h80000000
const D3DPSHADECAPS_COLORGOURAUDRGB = &h00008
const D3DPSHADECAPS_SPECULARGOURAUDRGB = &h00200
const D3DPSHADECAPS_ALPHAGOURAUDBLEND = &h04000
const D3DPSHADECAPS_FOGGOURAUD = &h80000
const D3DPTADDRESSCAPS_WRAP = &h01
const D3DPTADDRESSCAPS_MIRROR = &h02
const D3DPTADDRESSCAPS_CLAMP = &h04
const D3DPTADDRESSCAPS_BORDER = &h08
const D3DPTADDRESSCAPS_INDEPENDENTUV = &h10
const D3DPTADDRESSCAPS_MIRRORONCE = &h20
const D3DPTEXTURECAPS_PERSPECTIVE = &h00000001
const D3DPTEXTURECAPS_POW2 = &h00000002
const D3DPTEXTURECAPS_ALPHA = &h00000004
const D3DPTEXTURECAPS_SQUAREONLY = &h00000020
const D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE = &h00000040
const D3DPTEXTURECAPS_ALPHAPALETTE = &h00000080
const D3DPTEXTURECAPS_NONPOW2CONDITIONAL = &h00000100
const D3DPTEXTURECAPS_PROJECTED = &h00000400
const D3DPTEXTURECAPS_CUBEMAP = &h00000800
const D3DPTEXTURECAPS_VOLUMEMAP = &h00002000
const D3DPTEXTURECAPS_MIPMAP = &h00004000
const D3DPTEXTURECAPS_MIPVOLUMEMAP = &h00008000
const D3DPTEXTURECAPS_MIPCUBEMAP = &h00010000
const D3DPTEXTURECAPS_CUBEMAP_POW2 = &h00020000
const D3DPTEXTURECAPS_VOLUMEMAP_POW2 = &h00040000
const D3DPTEXTURECAPS_NOPROJECTEDBUMPENV = &h00200000
const D3DPTFILTERCAPS_MINFPOINT = &h00000100
const D3DPTFILTERCAPS_MINFLINEAR = &h00000200
const D3DPTFILTERCAPS_MINFANISOTROPIC = &h00000400
const D3DPTFILTERCAPS_MINFPYRAMIDALQUAD = &h00000800
const D3DPTFILTERCAPS_MINFGAUSSIANQUAD = &h00001000
const D3DPTFILTERCAPS_MIPFPOINT = &h00010000
const D3DPTFILTERCAPS_MIPFLINEAR = &h00020000
const D3DPTFILTERCAPS_MAGFPOINT = &h01000000
const D3DPTFILTERCAPS_MAGFLINEAR = &h02000000
const D3DPTFILTERCAPS_MAGFANISOTROPIC = &h04000000
const D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD = &h08000000
const D3DPTFILTERCAPS_MAGFGAUSSIANQUAD = &h10000000
const D3DSTENCILCAPS_KEEP = &h01
const D3DSTENCILCAPS_ZERO = &h02
const D3DSTENCILCAPS_REPLACE = &h04
const D3DSTENCILCAPS_INCRSAT = &h08
const D3DSTENCILCAPS_DECRSAT = &h10
const D3DSTENCILCAPS_INVERT = &h20
const D3DSTENCILCAPS_INCR = &h40
const D3DSTENCILCAPS_DECR = &h80
const D3DSTENCILCAPS_TWOSIDED = &h100
const D3DTEXOPCAPS_DISABLE = &h0000001
const D3DTEXOPCAPS_SELECTARG1 = &h0000002
const D3DTEXOPCAPS_SELECTARG2 = &h0000004
const D3DTEXOPCAPS_MODULATE = &h0000008
const D3DTEXOPCAPS_MODULATE2X = &h0000010
const D3DTEXOPCAPS_MODULATE4X = &h0000020
const D3DTEXOPCAPS_ADD = &h0000040
const D3DTEXOPCAPS_ADDSIGNED = &h0000080
const D3DTEXOPCAPS_ADDSIGNED2X = &h0000100
const D3DTEXOPCAPS_SUBTRACT = &h0000200
const D3DTEXOPCAPS_ADDSMOOTH = &h0000400
const D3DTEXOPCAPS_BLENDDIFFUSEALPHA = &h0000800
const D3DTEXOPCAPS_BLENDTEXTUREALPHA = &h0001000
const D3DTEXOPCAPS_BLENDFACTORALPHA = &h0002000
const D3DTEXOPCAPS_BLENDTEXTUREALPHAPM = &h0004000
const D3DTEXOPCAPS_BLENDCURRENTALPHA = &h0008000
const D3DTEXOPCAPS_PREMODULATE = &h0010000
const D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR = &h0020000
const D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA = &h0040000
const D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR = &h0080000
const D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA = &h0100000
const D3DTEXOPCAPS_BUMPENVMAP = &h0200000
const D3DTEXOPCAPS_BUMPENVMAPLUMINANCE = &h0400000
const D3DTEXOPCAPS_DOTPRODUCT3 = &h0800000
const D3DTEXOPCAPS_MULTIPLYADD = &h1000000
const D3DTEXOPCAPS_LERP = &h2000000
const D3DVTXPCAPS_TEXGEN = &h00000001
const D3DVTXPCAPS_MATERIALSOURCE7 = &h00000002
const D3DVTXPCAPS_DIRECTIONALLIGHTS = &h00000008
const D3DVTXPCAPS_POSITIONALLIGHTS = &h00000010
const D3DVTXPCAPS_LOCALVIEWER = &h00000020
const D3DVTXPCAPS_TWEENING = &h00000040
const D3DVTXPCAPS_TEXGEN_SPHEREMAP = &h00000100
const D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER = &h00000200
const D3DDTCAPS_UBYTE4 = &h00000001
const D3DDTCAPS_UBYTE4N = &h00000002
const D3DDTCAPS_SHORT2N = &h00000004
const D3DDTCAPS_SHORT4N = &h00000008
const D3DDTCAPS_USHORT2N = &h00000010
const D3DDTCAPS_USHORT4N = &h00000020
const D3DDTCAPS_UDEC3 = &h00000040
const D3DDTCAPS_DEC3N = &h00000080
const D3DDTCAPS_FLOAT16_2 = &h00000100
const D3DDTCAPS_FLOAT16_4 = &h00000200
const D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD = &h00000020
const D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION = &h00000080
const D3DCAPS3_COPY_TO_VIDMEM = &h00000100
const D3DCAPS3_COPY_TO_SYSTEMMEM = &h00000200
const D3DCAPS3_RESERVED = &h8000001F
const D3DCAPS2_NO2DDURING3DSCENE = &h00000002
const D3DCAPS2_FULLSCREENGAMMA = &h00020000
const D3DCAPS2_CANRENDERWINDOWED = &h00080000
const D3DCAPS2_CANCALIBRATEGAMMA = &h00100000
const D3DCAPS2_RESERVED = &h02000000
const D3DCAPS2_CANMANAGERESOURCE = &h10000000
const D3DCAPS2_DYNAMICTEXTURES = &h20000000
const D3DCAPS2_CANAUTOGENMIPMAP = &h40000000
const D3DVS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24
const D3DVS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0
const D3DVS20_MAX_NUMTEMPS = 32
const D3DVS20_MIN_NUMTEMPS = 12
const D3DVS20_MAX_STATICFLOWCONTROLDEPTH = 4
const D3DVS20_MIN_STATICFLOWCONTROLDEPTH = 1
const D3DVS20CAPS_PREDICATION = 1 shl 0
const D3DPS20CAPS_ARBITRARYSWIZZLE = 1 shl 0
const D3DPS20CAPS_GRADIENTINSTRUCTIONS = 1 shl 1
const D3DPS20CAPS_PREDICATION = 1 shl 2
const D3DPS20CAPS_NODEPENDENTREADLIMIT = 1 shl 3
const D3DPS20CAPS_NOTEXINSTRUCTIONLIMIT = 1 shl 4
const D3DPS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24
const D3DPS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0
const D3DPS20_MAX_NUMTEMPS = 32
const D3DPS20_MIN_NUMTEMPS = 12
const D3DPS20_MAX_STATICFLOWCONTROLDEPTH = 4
const D3DPS20_MIN_STATICFLOWCONTROLDEPTH = 0
const D3DPS20_MAX_NUMINSTRUCTIONSLOTS = 512
const D3DPS20_MIN_NUMINSTRUCTIONSLOTS = 96
const D3DMIN30SHADERINSTRUCTIONS = 512
const D3DMAX30SHADERINSTRUCTIONS = 32768

#ifdef __FB_64BIT__
	type _D3DVSHADERCAPS2_0
		Caps as DWORD
		DynamicFlowControlDepth as INT_
		NumTemps as INT_
		StaticFlowControlDepth as INT_
	end type
#else
	type _D3DVSHADERCAPS2_0 field = 4
		Caps as DWORD
		DynamicFlowControlDepth as INT_
		NumTemps as INT_
		StaticFlowControlDepth as INT_
	end type
#endif

type D3DVSHADERCAPS2_0 as _D3DVSHADERCAPS2_0

#ifdef __FB_64BIT__
	type _D3DPSHADERCAPS2_0
		Caps as DWORD
		DynamicFlowControlDepth as INT_
		NumTemps as INT_
		StaticFlowControlDepth as INT_
		NumInstructionSlots as INT_
	end type
#else
	type _D3DPSHADERCAPS2_0 field = 4
		Caps as DWORD
		DynamicFlowControlDepth as INT_
		NumTemps as INT_
		StaticFlowControlDepth as INT_
		NumInstructionSlots as INT_
	end type
#endif

type D3DPSHADERCAPS2_0 as _D3DPSHADERCAPS2_0

#ifdef __FB_64BIT__
	type _D3DCAPS9
		DeviceType as D3DDEVTYPE
		AdapterOrdinal as UINT
		Caps as DWORD
		Caps2 as DWORD
		Caps3 as DWORD
		PresentationIntervals as DWORD
		CursorCaps as DWORD
		DevCaps as DWORD
		PrimitiveMiscCaps as DWORD
		RasterCaps as DWORD
		ZCmpCaps as DWORD
		SrcBlendCaps as DWORD
		DestBlendCaps as DWORD
		AlphaCmpCaps as DWORD
		ShadeCaps as DWORD
		TextureCaps as DWORD
		TextureFilterCaps as DWORD
		CubeTextureFilterCaps as DWORD
		VolumeTextureFilterCaps as DWORD
		TextureAddressCaps as DWORD
		VolumeTextureAddressCaps as DWORD
		LineCaps as DWORD
		MaxTextureWidth as DWORD
		MaxTextureHeight as DWORD
		MaxVolumeExtent as DWORD
		MaxTextureRepeat as DWORD
		MaxTextureAspectRatio as DWORD
		MaxAnisotropy as DWORD
		MaxVertexW as single
		GuardBandLeft as single
		GuardBandTop as single
		GuardBandRight as single
		GuardBandBottom as single
		ExtentsAdjust as single
		StencilCaps as DWORD
		FVFCaps as DWORD
		TextureOpCaps as DWORD
		MaxTextureBlendStages as DWORD
		MaxSimultaneousTextures as DWORD
		VertexProcessingCaps as DWORD
		MaxActiveLights as DWORD
		MaxUserClipPlanes as DWORD
		MaxVertexBlendMatrices as DWORD
		MaxVertexBlendMatrixIndex as DWORD
		MaxPointSize as single
		MaxPrimitiveCount as DWORD
		MaxVertexIndex as DWORD
		MaxStreams as DWORD
		MaxStreamStride as DWORD
		VertexShaderVersion as DWORD
		MaxVertexShaderConst as DWORD
		PixelShaderVersion as DWORD
		PixelShader1xMaxValue as single
		DevCaps2 as DWORD
		MaxNpatchTessellationLevel as single
		Reserved5 as DWORD
		MasterAdapterOrdinal as UINT
		AdapterOrdinalInGroup as UINT
		NumberOfAdaptersInGroup as UINT
		DeclTypes as DWORD
		NumSimultaneousRTs as DWORD
		StretchRectFilterCaps as DWORD
		VS20Caps as D3DVSHADERCAPS2_0
		PS20Caps as D3DPSHADERCAPS2_0
		VertexTextureFilterCaps as DWORD
		MaxVShaderInstructionsExecuted as DWORD
		MaxPShaderInstructionsExecuted as DWORD
		MaxVertexShader30InstructionSlots as DWORD
		MaxPixelShader30InstructionSlots as DWORD
	end type
#else
	type _D3DCAPS9 field = 4
		DeviceType as D3DDEVTYPE
		AdapterOrdinal as UINT
		Caps as DWORD
		Caps2 as DWORD
		Caps3 as DWORD
		PresentationIntervals as DWORD
		CursorCaps as DWORD
		DevCaps as DWORD
		PrimitiveMiscCaps as DWORD
		RasterCaps as DWORD
		ZCmpCaps as DWORD
		SrcBlendCaps as DWORD
		DestBlendCaps as DWORD
		AlphaCmpCaps as DWORD
		ShadeCaps as DWORD
		TextureCaps as DWORD
		TextureFilterCaps as DWORD
		CubeTextureFilterCaps as DWORD
		VolumeTextureFilterCaps as DWORD
		TextureAddressCaps as DWORD
		VolumeTextureAddressCaps as DWORD
		LineCaps as DWORD
		MaxTextureWidth as DWORD
		MaxTextureHeight as DWORD
		MaxVolumeExtent as DWORD
		MaxTextureRepeat as DWORD
		MaxTextureAspectRatio as DWORD
		MaxAnisotropy as DWORD
		MaxVertexW as single
		GuardBandLeft as single
		GuardBandTop as single
		GuardBandRight as single
		GuardBandBottom as single
		ExtentsAdjust as single
		StencilCaps as DWORD
		FVFCaps as DWORD
		TextureOpCaps as DWORD
		MaxTextureBlendStages as DWORD
		MaxSimultaneousTextures as DWORD
		VertexProcessingCaps as DWORD
		MaxActiveLights as DWORD
		MaxUserClipPlanes as DWORD
		MaxVertexBlendMatrices as DWORD
		MaxVertexBlendMatrixIndex as DWORD
		MaxPointSize as single
		MaxPrimitiveCount as DWORD
		MaxVertexIndex as DWORD
		MaxStreams as DWORD
		MaxStreamStride as DWORD
		VertexShaderVersion as DWORD
		MaxVertexShaderConst as DWORD
		PixelShaderVersion as DWORD
		PixelShader1xMaxValue as single
		DevCaps2 as DWORD
		MaxNpatchTessellationLevel as single
		Reserved5 as DWORD
		MasterAdapterOrdinal as UINT
		AdapterOrdinalInGroup as UINT
		NumberOfAdaptersInGroup as UINT
		DeclTypes as DWORD
		NumSimultaneousRTs as DWORD
		StretchRectFilterCaps as DWORD
		VS20Caps as D3DVSHADERCAPS2_0
		PS20Caps as D3DPSHADERCAPS2_0
		VertexTextureFilterCaps as DWORD
		MaxVShaderInstructionsExecuted as DWORD
		MaxPShaderInstructionsExecuted as DWORD
		MaxVertexShader30InstructionSlots as DWORD
		MaxPixelShader30InstructionSlots as DWORD
	end type
#endif

type D3DCAPS9 as _D3DCAPS9

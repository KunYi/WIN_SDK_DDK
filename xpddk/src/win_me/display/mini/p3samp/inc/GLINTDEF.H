/******************************Module*Header**********************************\
 *
 *                           *****************************
 *                           * Permedia 2: SAMPLE CODE   *
 *                           *****************************
 *
 * Module Name: glintdef.h
 *
 * Copyright (c) 1994-1998 3Dlabs Inc. Ltd. All rights reserved.
 * Copyright (c) 1995-2001 Microsoft Corporation.  All rights reserved.
 *
\*****************************************************************************/


/* General */

#define __GLINT_NULL                   	       0

#define __GLINT_TRUE                           1
#define __GLINT_FALSE                          0

/*-----------------------------------------------------*/
/* GLiNT Register Fields */
/* --------------------- */

// From FBReadMode
#define __GLINT_PATCH 0
#define __GLINT_SUBPATCH 1
#define __GLINT_SUBPATCHPACK 2

#define __GLINT_8BITPIXEL 0
#define __GLINT_16BITPIXEL 1
#define __GLINT_32BITPIXEL 2
#define __GLINT_4BITPIXEL 3
#define __GLINT_24BITPIXEL 4

/* Host In */
#define __GLINT_TAG_MODE_HOLD      0
#define __GLINT_TAG_MODE_INCREMENT 1
#define __GLINT_TAG_MODE_INDEXED   2
#define __GLINT_TAG_MODE_RESERVED  3

/* Host out (Filter) options. */

#define	__GLINT_FILTER_TAG		0x1	
#define	__GLINT_FILTER_DATA		0x2
#define	__GLINT_FILTER_TAG_AND_DATA	0x3

#define __GLINT_ENABLE                         1
#define __GLINT_DISABLE                        0

/* Rasterization */

#define __GLINT_MIN_ANTIALIAS                  0
#define __GLINT_MAX_ANTIALIAS                  1

#define __GLINT_LINE_PRIMITIVE       	       0
#define __GLINT_TRAPEZOID_PRIMITIVE  	       1
#define __GLINT_POINT_PRIMITIVE      	       2

#define __GLINT_FLAT_SHADE_MODE      	       0
#define __GLINT_GOURAUD_SHADE_MODE             1

#define __GLINT_FRACTION_ADJUST_NONE         0
#define __GLINT_FRACTION_ADJUST_TRUNC        1
#define __GLINT_FRACTION_ADJUST_HALF         2
#define __GLINT_FRACTION_ADJUST_ALMOST_HALF  3

#define __GLINT_START_BIAS_ZERO              0
#define __GLINT_START_BIAS_HALF              1
#define __GLINT_START_BIAS_ALMOST_HALF       2

/* Scissor */

/* Stipple */

#define __GLINT_RESET_STIPPLE_COUNTERS         0
#define __GLINT_LOAD_STIPPLE_COUNTERS          1
/* specifies pattern size as number of address bits less 1 */
#define __GLINT_AREA_STIPPLE_2_PIXEL_PATTERN   0
#define __GLINT_AREA_STIPPLE_4_PIXEL_PATTERN   1
#define __GLINT_AREA_STIPPLE_8_PIXEL_PATTERN   2
#define __GLINT_AREA_STIPPLE_16_PIXEL_PATTERN  3
#define __GLINT_AREA_STIPPLE_32_PIXEL_PATTERN  4


/* Color DDA */

/* Alpha Test */

#define __GLINT_ALPHA_COMPARE_MODE_NEVER		0
#define __GLINT_ALPHA_COMPARE_MODE_LESS	       		1
#define __GLINT_ALPHA_COMPARE_MODE_EQUAL		2
#define __GLINT_ALPHA_COMPARE_MODE_LESS_OR_EQUAL	3
#define __GLINT_ALPHA_COMPARE_MODE_GREATER		4
#define __GLINT_ALPHA_COMPARE_MODE_NOT_EQUAL		5
#define __GLINT_ALPHA_COMPARE_MODE_GREATER_OR_EQUAL	6
#define __GLINT_ALPHA_COMPARE_MODE_ALWAYS		7

/* Chroma Test Mode */
#define __GLINT_CHROMA_FBSOURCE 0
#define __GLINT_CHROMA_FBDATA 1
#define __GLINT_CHROMA_INPUT_COLOR 2
#define __GLINT_CHROMA_OUTPUT_COLOR 3
#define __GLINT_CHROMA_INCLUDE 0
#define __GLINT_CHROMA_EXCLUDE 1

/* Texture Filter Mode */
#define __GLINT_TEXTUREFILTER_ALPHAMAPSENSE_INCLUDE 0
#define __GLINT_TEXTUREFILTER_ALPHAMAPSENSE_EXCLUDE 1

/* Local buffer read */

#define __GLINT_PPCODE0  0       
#define __GLINT_PPCODE1  1      
#define __GLINT_PPCODE2  2     
#define __GLINT_PPCODE3  3     
#define __GLINT_PPCODE4  4     
#define __GLINT_PPCODE5  5     
#define __GLINT_PPCODE6  6     
#define __GLINT_PPCODE7  7     

#define __GLINT_LBDEFAULT      0
#define __GLINT_LBSTENCIL      1
#define __GLINT_LBDEPTH        2

#define __GLINT_FBDEFAULT	0
#define __GLINT_FBCOLOR         1

#define __GLINT_TOP_LEFT_WINDOW_ORIGIN       0
#define __GLINT_BOTTOM_LEFT_WINDOW_ORIGIN    1

#define __GLINT_DEPTH_WIDTH_16 0
#define __GLINT_DEPTH_WIDTH_24 1
#define __GLINT_DEPTH_WIDTH_32 2

#define __GLINT_STENCIL_WIDTH_0 0
#define __GLINT_STENCIL_WIDTH_4 1
#define __GLINT_STENCIL_WIDTH_8 2

#define __GLINT_STENCIL_POSITION_16 0
#define __GLINT_STENCIL_POSITION_20 1
#define __GLINT_STENCIL_POSITION_24 2
#define __GLINT_STENCIL_POSITION_28 3
#define __GLINT_STENCIL_POSITION_32 4

#define __GLINT_FRAMECOUNT_WIDTH_0 0
#define __GLINT_FRAMECOUNT_WIDTH_4 1
#define __GLINT_FRAMECOUNT_WIDTH_8 2

#define __GLINT_FRAMECOUNT_POSITION_16 0
#define __GLINT_FRAMECOUNT_POSITION_20 1
#define __GLINT_FRAMECOUNT_POSITION_24 2
#define __GLINT_FRAMECOUNT_POSITION_28 3
#define __GLINT_FRAMECOUNT_POSITION_32 4
#define __GLINT_FRAMECOUNT_POSITION_36 5
#define __GLINT_FRAMECOUNT_POSITION_40 6

#define __GLINT_GID_WIDTH_0 0
#define __GLINT_GID_WIDTH_4 1 
#define __GLINT_GID_POSITION_16 0
#define __GLINT_GID_POSITION_20 1
#define __GLINT_GID_POSITION_24 2
#define __GLINT_GID_POSITION_28 3
#define __GLINT_GID_POSITION_32 4
#define __GLINT_GID_POSITION_36 5
#define __GLINT_GID_POSITION_40 6
#define __GLINT_GID_POSITION_44 7
#define __GLINT_GID_POSITION_48 8

/* FBReadMode */
#define __GLINT_FBREAD_FBDEFAULT 0
#define __GLINT_FBREAD_FBCOLOR 1
#define __GLINT_FBREAD_ORIGINTOPLEFT 0
#define __GLINT_FBREAD_ORIGINBOTTOMLEFT 1
#define __GLINT_FBREAD_FBSOURCE_CONSTANT	0
#define __GLINT_FBREAD_FBSOURCE_INDEX		1
#define __GLINT_FBREAD_FBSOURCE_COORDINATE	2


/* Pixel ownership */
#define __GLINT_GID_COMPARE_ALWAYS    0
#define __GLINT_GID_COMPARE_NEVER     1
#define __GLINT_GID_COMPARE_EQUAL     2
#define __GLINT_GID_COMPARE_NOT_EQUAL 3
#define __GLINT_GID_LBUPDATE_LBDATA		0
#define __GLINT_GID_LBUPDATE_REGISTER	1

/* Stencil Test */

#define __GLINT_STENCIL_BUFFER_WIDTH_4            0
#define __GLINT_STENCIL_BUFFER_WIDTH_8            1

#define __GLINT_STENCIL_SOURCE_TEST_LOGIC	0
#define __GLINT_STENCIL_SOURCE_STENCIL_MSG	1
#define __GLINT_STENCIL_SOURCE_LBDATA_MSG	2	/* old name */
#define __GLINT_STENCIL_SOURCE_SOURCE_STENCIL	2
#define __GLINT_STENCIL_SOURCE_LBSOURCEDATA_MSG	3

#define __GLINT_STENCIL_COMPARE_MODE_NEVER		0
#define __GLINT_STENCIL_COMPARE_MODE_LESS		1
#define __GLINT_STENCIL_COMPARE_MODE_EQUAL		2
#define __GLINT_STENCIL_COMPARE_MODE_LESS_OR_EQUAL	3
#define __GLINT_STENCIL_COMPARE_MODE_GREATER		4
#define __GLINT_STENCIL_COMPARE_MODE_NOT_EQUAL		5
#define __GLINT_STENCIL_COMPARE_MODE_GREATER_OR_EQUAL	6
#define __GLINT_STENCIL_COMPARE_MODE_ALWAYS		7

#define __GLINT_STENCIL_METHOD_KEEP		0
#define __GLINT_STENCIL_METHOD_ZERO		1
#define __GLINT_STENCIL_METHOD_REPLACE		2
#define __GLINT_STENCIL_METHOD_INCR		3
#define __GLINT_STENCIL_METHOD_DECR		4
#define __GLINT_STENCIL_METHOD_INVERT		5


/* Depth Test */

#define __GLINT_NEW_DEPTH_SOURCE_DDA		0	/* old name */
#define __GLINT_DEPTH_SOURCE_DDA		0
#define __GLINT_NEW_DEPTH_SOURCE_DEPTH		1	/* old name */
#define __GLINT_DEPTH_SOURCE_SOURCE_DEPTH	1
#define __GLINT_NEW_DEPTH_SOURCE_DEPTH_MSG	2	/* old name */
#define __GLINT_DEPTH_SOURCE_DEPTH_MSG		2
#define __GLINT_NEW_DEPTH_LBSOURCE_DATA_DEPTH	3	/* old name */
#define __GLINT_DEPTH_SOURCE_LBSOURCEDATA_MSG	3

#define __GLINT_DEPTH_COMPARE_MODE_NEVER		0
#define __GLINT_DEPTH_COMPARE_MODE_LESS			1
#define __GLINT_DEPTH_COMPARE_MODE_EQUAL		2
#define __GLINT_DEPTH_COMPARE_MODE_LESS_OR_EQUAL	3
#define __GLINT_DEPTH_COMPARE_MODE_GREATER		4
#define __GLINT_DEPTH_COMPARE_MODE_NOT_EQUAL		5
#define __GLINT_DEPTH_COMPARE_MODE_GREATER_OR_EQUAL	6
#define __GLINT_DEPTH_COMPARE_MODE_ALWAYS		7

/* Local buffer write */

/* Texture / Fog  */

/* Texture AddressMode */
#define __GLINT_TEXADDRESS_WRAP_CLAMP	0
#define __GLINT_TEXADDRESS_WRAP_REPEAT	1
#define __GLINT_TEXADDRESS_WRAP_MIRROR	2
#define __GLINT_TEXADDRESS_OPERATION_2D		0
#define __GLINT_TEXADDRESS_OPERATION_3D		1
#define __GLINT_TEXADDRESS_TEXMAP_1D 0
#define __GLINT_TEXADDRESS_TEXMAP_2D 1

/* Texture ReadMode */
#define __GLINT_TEXTUREREAD_FILTER_NEAREST			0
#define __GLINT_TEXTUREREAD_FILTER_LINEAR			1
#define __GLINT_TEXTUREREAD_FILTER_NEARMIPNEAREST	2
#define __GLINT_TEXTUREREAD_FILTER_NEARMIPLINEAR	3
#define __GLINT_TEXTUREREAD_FILTER_LINEARMIPNEAREST 4
#define __GLINT_TEXTUREREAD_FILTER_LINEARMIPLINEAR	5
#define __GLINT_TEXTUREREAD_WRAP_CLAMP	0
#define __GLINT_TEXTUREREAD_WRAP_REPEAT	1
#define __GLINT_TEXTUREREAD_WRAP_MIRROR	2
#define __GLINT_TEXTUREREAD_TEXMAP_1D 0
#define __GLINT_TEXTUREREAD_TEXMAP_2D 1
#define __GLINT_TEXTUREREAD_FBSOURCE_NONE		0
#define __GLINT_TEXTUREREAD_FBSOURCE_INDEX		1
#define __GLINT_TEXTUREREAD_FBSOURCE_COORDINATE 2

/* Texture Format */
#define __GLINT_TEXTUREFORMAT_LITTLE_ENDIAN 0
#define __GLINT_TEXTUREFORMAT_BIG_ENDIAN	1
#define __GLINT_TEXTUREFORMAT_COMPONENTS_RGB	2	
#define __GLINT_TEXTUREFORMAT_COMPONENTS_RGBA	3
#define __GLINT_TEXTUREFORMAT_OUTPUT_TEXEL		0
#define __GLINT_TEXTUREFORMAT_OUTPUT_COLOR		1
#define __GLINT_TEXTUREFORMAT_OUTPUT_BITMASK	2
#define __GLINT_TEXTUREFORMAT_OUTPUT_ONECOMP_LUMA		0
#define __GLINT_TEXTUREFORMAT_OUTPUT_ONECOMP_ALPHA		1
#define __GLINT_TEXTUREFORMAT_OUTPUT_ONECOMP_INTESITY	2


/* Texture Color Mode */
#define __GLINT_TEXCOLORMODE_BASEFORMAT_ALPHA 0
#define __GLINT_TEXCOLORMODE_BASEFORMAT_LUMA 1
#define __GLINT_TEXCOLORMODE_BASEFORMAT_LUMA_ALPHA 2
#define __GLINT_TEXCOLORMODE_BASEFORMAT_INTENSITY 3
#define __GLINT_TEXCOLORMODE_BASEFORMAT_RGB 4
#define __GLINT_TEXCOLORMODE_BASEFORMAT_RGBA 5

#define __GLINT_TEXCOLORMODE_TEXTURETYPE_APPLE 1
#define __GLINT_TEXCOLORMODE_TEXTURETYPE_OPENGL 0

#define __GLINT_TEXCOLORMODE_APPLICATION_MODULATE 0
#define __GLINT_TEXCOLORMODE_APPLICATION_DECAL 1
#define __GLINT_TEXCOLORMODE_APPLICATION_BLEND 2
#define __GLINT_TEXCOLORMODE_APPLICATION_COPY 3



#define __GLINT_MODULATE_TEXTURE      0
#define __GLINT_DECAL_TEXTURE         1
#define __GLINT_BLEND_TEXTURE         2

/* Frame buffer read */

/* shares ppcode, number of reads and window origin defines
   with local buffer read */
#define __GLINT_FBDATA    0
#define __GLINT_FBCOLOR  1


/* Antialias */

#define __GLINT_COLOR_MODE_RGBA            		0
#define __GLINT_COLOR_MODE_CI            		1


/* Alpha Blend */

#define __GLINT_BLEND_FUNC_ZERO				0
#define __GLINT_BLEND_FUNC_ONE				1
#define __GLINT_BLEND_FUNC_SRC_COLOR			2
#define __GLINT_BLEND_FUNC_DST_COLOR			2
#define __GLINT_BLEND_FUNC_ONE_MINUS_SRC_COLOR		3
#define __GLINT_BLEND_FUNC_ONE_MINUS_DST_COLOR		3
#define __GLINT_BLEND_FUNC_SRC_ALPHA			4
#define __GLINT_BLEND_FUNC_ONE_MINUS_SRC_ALPHA		5
#define __GLINT_BLEND_FUNC_DST_ALPHA			6
#define __GLINT_BLEND_FUNC_ONE_MINUS_DST_ALPHA		7
#define __GLINT_BLEND_FUNC_SRC_ALPHA_SATURATE		8

#define __GLINT_BLENDOP_ONE_AND_ONE 17
#define __GLINT_BLENDOP_FORMAT 16
#define __GLINT_BLENDOP_BLEND 84
#define __GLINT_BLENDOP_PREMULT 81
#define __GLINT_BLENDOP_NONE 1

/* Dither */

#define __GLINT_COLOR_FORMAT_RGBA_8888            0
#define __GLINT_COLOR_FORMAT_RGBA_5555            1
#define __GLINT_COLOR_FORMAT_RGBA_4444            2
#define __GLINT_COLOR_FORMAT_RGBA_4444_FRONT      3
#define __GLINT_COLOR_FORMAT_RGBA_4444_BACK       4
#define __GLINT_COLOR_FORMAT_RGB_332_FRONT        5
#define __GLINT_COLOR_FORMAT_RGB_332_BACK         6
#define __GLINT_COLOR_FORMAT_RGB_121_FRONT        7
#define __GLINT_COLOR_FORMAT_RGB_121_BACK         8

#define __GLINT_COLOR_FORMAT_CI_8	          14
#define __GLINT_COLOR_FORMAT_CI_4                 15


/* Logical Ops/Write mask */

#define __GLINT_LOGICOP_CLEAR                   0
#define __GLINT_LOGICOP_AND                     1
#define __GLINT_LOGICOP_AND_REVERSE             2
#define __GLINT_LOGICOP_COPY                    3
#define __GLINT_LOGICOP_AND_INVERTED            4
#define __GLINT_LOGICOP_NOOP                    5
#define __GLINT_LOGICOP_XOR                     6
#define __GLINT_LOGICOP_OR                      7
#define __GLINT_LOGICOP_NOR                     8
#define __GLINT_LOGICOP_EQUIV                   9
#define __GLINT_LOGICOP_INVERT                 10
#define __GLINT_LOGICOP_OR_REVERSE             11
#define __GLINT_LOGICOP_COPY_INVERT            12
#define __GLINT_LOGICOP_OR_INVERT              13
#define __GLINT_LOGICOP_NAND                   14
#define __GLINT_LOGICOP_SET                    15

#define __GLINT_ALL_WRITEMASKS_SET             0xFFFFFFFF

/* FB Write */

#define __GLINT_BLOCK_WIDTH_8    0
#define __GLINT_BLOCK_WIDTH_16   1
#define __GLINT_BLOCK_WIDTH_32   2

/*-----------------------------------------------------*/
#define __GLINT_3D_CONTEXT  1
#define __GLINT_2D_CONTEXT  2

#define __GLINT_ALPHA_FUNC_SCALE			255.0

#define __GLINT_MIN_SUB_SCAN_LINES		4
#define __GLINT_MAX_SUB_SCAN_LINES		8
/* converts diameter into number of subscanlines in radius */
#define __GLINT_FASTEST_SMOOTH_POINT_RADIUS (__GLINT_MIN_SUB_SCAN_LINES >> 1)
#define __GLINT_NICEST_SMOOTH_POINT_RADIUS  (__GLINT_MAX_SUB_SCAN_LINES >> 1)

#define __GLINT_POINT_TABLE_LONGS  4

#define __GLINT_MAX_PPC_ENTRIES  3

#define __GLINT_PPCODE0_SHIFT  0       
#define __GLINT_PPCODE1_SHIFT  5      
#define __GLINT_PPCODE2_SHIFT  6     
#define __GLINT_PPCODE3_SHIFT  7     
#define __GLINT_PPCODE4_SHIFT  8     
#define __GLINT_PPCODE5_SHIFT  9     
#define __GLINT_PPCODE6_SHIFT  10     
#define __GLINT_PPCODE7_SHIFT  11     

/*-----------------------------------------------------*/
#define __GLINT_MAX_YSAMPLES 8  

#define __GLINT_SAMPLES 4

#if __GLINT_SAMPLES == 8

#define __GLINT_SUBSAMPLES  64
#define __GLINT_XSUBSAMPLES 8
#define __GLINT_YSUBSAMPLES 8
#define __GLINT_COLOR_SCALE 4

#define __GLINT_SAMPLENORM  0.015625
#define __GLINT_SPANNORM    0.125

#define __GLINT_XSUBPIXSCALE 8
#define __GLINT_XSUBPIXBITS  3
#define __GLINT_XSUBPIXSHIFT 3
#define __GLINT_XSUBPIXMASK  7
#define __GLINT_XFRACSHIFT   0

#define __GLINT_YSUBPIXSCALE __GLINT_XSUBPIXSCALE
#define __GLINT_YSUBPIXBITS  __GLINT_XSUBPIXBITS
#define __GLINT_YSUBPIXSHIFT __GLINT_XSUBPIXSHIFT
#define __GLINT_YSUBPIXMASK  __GLINT_XSUBPIXMASK

#elif __GLINT_SAMPLES == 4

#define __GLINT_SUBSAMPLES  16
#define __GLINT_XSUBSAMPLES 4
#define __GLINT_YSUBSAMPLES 4
#define __GLINT_COLOR_SCALE 16

#define __GLINT_SAMPLENORM   0.0625 
#define __GLINT_SPANNORM     0.25  

#define __GLINT_XSUBPIXSCALE 8
#define __GLINT_XSUBPIXBITS  3 
#define __GLINT_XSUBPIXSHIFT 3 
#define __GLINT_XSUBPIXMASK  7 
#define __GLINT_XFRACSHIFT   1

#define __GLINT_YSUBPIXSCALE 4
#define __GLINT_YSUBPIXBITS  2  
#define __GLINT_YSUBPIXSHIFT 2  
#define __GLINT_YSUBPIXMASK  3 

#elif __GLINT_SAMPLES == 2

"NOT SUPPORTED YET"

#else  /* __GLINT_SAMPLES == 1 Alias Case */

#define __GLINT_SUBSAMPLES  1
#define __GLINT_XSUBSAMPLES 1
#define __GLINT_YSUBSAMPLES 1
#define __GLINT_COLOR_SCALE 255

#define __GLINT_SAMPLENORM   1
#define __GLINT_SPANNORM     1

#define __GLINT_XSUBPIXSCALE 8
#define __GLINT_XSUBPIXBITS  3
#define __GLINT_XSUBPIXSHIFT 3
#define __GLINT_XSUBPIXMASK  7
 
#define __GLINT_XFRACSHIFT   3

#define __GLINT_YSUBPIXSCALE 1
#define __GLINT_YSUBPIXBITS  0
#define __GLINT_YSUBPIXSHIFT 0
#define __GLINT_YSUBPIXMASK  ~0
#endif

/*-----------------------------------------------------*/
#define __GLINT_POS_Z_FIXED_PT_SCALE  2147483647.0    /* 2**31 - 1*/
#define __GLINT_NEG_Z_FIXED_PT_SCALE  1073741824.0    /* 2**30 */

#define __GLINT_POS_Z_FIXED_PT_SCALE_RECIP  (1.0/2147483647.0)   
#define __GLINT_NEG_Z_FIXED_PT_SCALE_RECIP  (1.0/1073741824.0)

#define RGB_MODE         1
#define COLOR_MODE       1 /* 0=BGR, 1=RGB */
#define DITHER_XOFFSET   0
#define DITHER_YOFFSET   0
#define DITHER_ENABLE    __GLINT_ENABLE
#define MS_BIT_MASK             0x80000000l

// Shifts to enable units
// DepthMode
#define __GLINT_DEPTHMODE_ENABLE 0
#define __GLINT_DEPTHMODE_WRITEMASK 1
#define __GLINT_DEPTHMODE_SOURCEDEPTH 2
#define __GLINT_DEPTHMODE_COMPARISON 4


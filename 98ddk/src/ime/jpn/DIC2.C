/**********************************************************************/
/*                                                                    */
/*      DIC2.C - Windows 95 FAKEIME                                   */
/*                                                                    */
/*      Copyright (c) 1994-1995  Microsoft Corporation                */
/*                                                                    */
/**********************************************************************/
#include "windows.h"
#include "imm.h"
#include "fakeime.h"

/**********************************************************************/
/*                                                                    */
/* ConvChar()                                                         */
/*                                                                    */
/* Roman character Kana converting function                           */
/*                                                                    */
/**********************************************************************/
WORD PASCAL ConvChar( hIMC, ch1, ch2 )
HIMC hIMC;
WORD ch1, ch2;
{
    int num1, num2;
#ifdef FAKEIMEM
    static WCHAR table[15][5] = {
        { 0x30A2, 0x30A4, 0x30A6, 0x30A8, 0x30AA },     //  A
        { 0x30AB, 0x30AD, 0x30AF, 0x30B1, 0x30B3 },     //  K
        { 0x30B5, 0x30B7, 0x30B9, 0x30BB, 0x30BD },     //  S
        { 0x30BF, 0x30C1, 0x30C4, 0x30C6, 0x30C8 },     //  T
        { 0x30CA, 0x30CB, 0x30CC, 0x30CD, 0x30CE },     //  N
        { 0x30CF, 0x30D2, 0x30D5, 0x30D8, 0x30DB },     //  H
        { 0x30DE, 0x30DF, 0x30E0, 0x30E1, 0x30E2 },     //  M
        { 0x30E4, 0x0000, 0x30E6, 0x0000, 0x30E8 },     //  Y
        { 0x30E9, 0x30EA, 0x30EB, 0x30EC, 0x30ED },     //  R
        { 0x30EF, 0x0000, 0x0000, 0x0000, 0x30F2 },     //  W
        { 0x30AC, 0x30AE, 0x30B0, 0x30B2, 0x30B4 },     //  G
        { 0x30B6, 0x30B8, 0x30BA, 0x30BC, 0x30BE },     //  Z
        { 0x30C0, 0x30C2, 0x30C5, 0x30C7, 0x30C9 },     //  D
        { 0x30D0, 0x30D3, 0x30D6, 0x30D9, 0x30DC },     //  B
        { 0x30d1, 0x30d4, 0x30d7, 0x30da, 0x30dd }      //  p
    };
#else
    static unsigned char table[10][5] = {
        { 0xb1, 0xb2, 0xb3, 0xb4, 0xb5 },     //  A
        { 0xb6, 0xb7, 0xb8, 0xb9, 0xba },     //  K
        { 0xbb, 0xbc, 0xbd, 0xbe, 0xbf },     //  S
        { 0xc0, 0xc1, 0xc2, 0xc3, 0xc4 },     //  T
        { 0xc5, 0xc6, 0xc7, 0xc8, 0xc9 },     //  N
        { 0xca, 0xcb, 0xcc, 0xcd, 0xce },     //  H
        { 0xcf, 0xd0, 0xd1, 0xd2, 0xd3 },     //  M
        { 0xd4, 0x00, 0xd5, 0x00, 0xd6 },     //  Y
        { 0xd7, 0xd8, 0xd9, 0xda, 0xdb },     //  R
        { 0xdc, 0x00, 0x00, 0x00, 0xa6 }      //  W
    };
    static unsigned char table2[4][5] = {
        { 0xb6, 0xb7, 0xb8, 0xb9, 0xba },     //  G
        { 0xbb, 0xbc, 0xbd, 0xbe, 0xbf },     //  Z
        { 0xc0, 0xc1, 0xc2, 0xc3, 0xc4 },     //  D
        { 0xca, 0xcb, 0xcc, 0xcd, 0xce }      //  B
    };
    static unsigned char table3[1][5] = {
        { 0xca, 0xcb, 0xcc, 0xce, 0xcf }      //  P
    };
#endif

    num1 = IsFirst( ch1 );
    num2 = IsSecond( ch2 );
#ifdef FAKEIMEM
    return( (WORD)table[num1][num2-1] );
#else
    if( num1 <= 9 )
        return( (WORD)table[num1][num2-1] );
    else if( num1 <= 13 )
        return( ((WORD)table2[num1-10][num2-1]) << 8 | (0x00de) );
    else
        return( ((WORD)table3[num1-14][num2-1]) << 8 | (0x00df) );
#endif
}

/**********************************************************************/
/*                                                                    */
/* IsFirst()                                                          */
/*                                                                    */
/* A function which judges the vowels                                 */
/*                                                                    */
/**********************************************************************/
int PASCAL IsFirst( ch )
register WORD ch;
{
    register int i;
#ifdef FAKEIMEM
    static WCHAR table0[] = MYTEXT("KSTNHMYRWGZDBP");
    static WCHAR table1[] = MYTEXT("kstnhmyrwgzdbp");
#else
    static char table0[] = "KSTNHMYRWGZDBP";

    ch = (WORD)(DWORD)AnsiUpper( (LPSTR)(DWORD)ch );
#endif


    for( i = 0; table0[i]; i++ ){
#ifdef FAKEIMEM
        if( table0[i] == (WCHAR)ch )
            return( i+1 );

        if( table1[i] == (WCHAR)ch )
            return( i+1 );
#else
        if( table0[i] == (char)ch )
            return( i+1 );
#endif
    }
    return 0;
}

/**********************************************************************/
/*                                                                    */
/* IsSecond()                                                         */
/*                                                                    */
/* A function which judges the consonants                             */
/*                                                                    */
/**********************************************************************/
int PASCAL IsSecond( ch )
register WORD ch;
{
    register int i;
#ifdef FAKEIMEM
    static WCHAR table0[] = MYTEXT("AIUEO");
    static WCHAR table1[] = MYTEXT("aiueo");
#else
    static char table0[] = "AIUEO";

    ch = (WORD)(DWORD)AnsiUpper( (LPSTR)(DWORD)ch );
#endif


    for( i = 0; table0[i]; i++ ){
#ifdef FAKEIMEM
        if( table0[i] == (WCHAR)ch )
            return( i+1 );

        if( table1[i] == (WCHAR)ch )
            return( i+1 );
#else
        if( table0[i] == (char)ch )
            return( i+1 );
#endif
    }
    return 0;
}


static WORD table1[] = {        /* 0x20 - 0x2f */
    0x8140, 0x8149, 0x8168, 0x8194, 0x8190, 0x8193, 0x8195, 0x8166,
    0x8169, 0x816a, 0x8196, 0x817b, 0x8143, 0x817c, 0x8144, 0x8180
};
static WORD table2[] = {        /* 0x3a - 0x3f */
    0x8146, 0x8147, 0x8183, 0x8181, 0x8184, 0x8148
};
static WORD table3[] = {        /* 0x5b - 0x60 */
    0x816d, 0x818f, 0x816e, 0x814f, 0x8151, 0x8165
};
static WORD table4[] = {        /* 0x7b - 0x7f */
    0x816f, 0x8162, 0x8170, 0x8160, 0x0000
};
static WORD table5[] = {        /* 0xa1 - 0xdf hiragana */
    0x8142, 0x8175, 0x8176, 0x8141, 0x8145, 0x82f0, 0x829f,
    0x82a1, 0x82a3, 0x82a5, 0x82a7, 0x82e1, 0x82e3, 0x82e5, 0x82c1,
    0x815b, 0x82a0, 0x82a2, 0x82a4, 0x82a6, 0x82a8, 0x82a9, 0x82ab,
    0x82ad, 0x82af, 0x82b1, 0x82b3, 0x82b5, 0x82b7, 0x82b9, 0x82bb,
    0x82bd, 0x82bf, 0x82c2, 0x82c4, 0x82c6, 0x82c8, 0x82c9, 0x82ca,
    0x82cb, 0x82cc, 0x82cd, 0x82d0, 0x82d3, 0x82d6, 0x82d9, 0x82dc,
    0x82dd, 0x82de, 0x82df, 0x82e0, 0x82e2, 0x82e4, 0x82e6, 0x82e7,
    0x82e8, 0x82e9, 0x82ea, 0x82eb, 0x82ed, 0x82f1, 0x814a, 0x814b
};
static WORD table6[] = {        /* 0xa1 - 0xdf katakana */
    0x8142, 0x8175, 0x8176, 0x8141, 0x8145, 0x82f0, 0x8340,
    0x8342, 0x8344, 0x8346, 0x8348, 0x8383, 0x8385, 0x8387, 0x8362,
    0x815b, 0x8341, 0x8343, 0x8345, 0x8347, 0x8349, 0x834a, 0x834c,
    0x834e, 0x8350, 0x8352, 0x8354, 0x8356, 0x8358, 0x835a, 0x835c,
    0x835e, 0x8360, 0x8363, 0x8365, 0x8367, 0x8369, 0x836a, 0x836b,
    0x836c, 0x836d, 0x836e, 0x8371, 0x8374, 0x8377, 0x837a, 0x837d,
    0x837e, 0x8380, 0x8381, 0x8382, 0x8384, 0x8386, 0x8388, 0x8389,
    0x838a, 0x838b, 0x838c, 0x838d, 0x838f, 0x8393, 0x814a, 0x814b
};
static WORD table7[] = {        /* sonant char part 1 */
    0x82cd, 0x82d0, 0x82d3, 0x82d6, 0x82d9,
    0x836e, 0x8371, 0x8374, 0x8375, 0x837a, 0x0000
};
static WORD table8[] = {        /* sonant char part 2 */
    0x82a9, 0x82ab, 0x82ad, 0x82af, 0x82b1, 0x82b3, 0x82b5, 0x82b7,
    0x82b9, 0x82bb, 0x82bd, 0x82bf, 0x82c2, 0x82c4, 0x82c6, 0x82cd,
    0x82d0, 0x82d3, 0x82d6, 0x82d9,
    0x834a, 0x834c, 0x834e, 0x8350, 0x8352, 0x8354, 0x8356, 0x8358,
    0x835a, 0x835c, 0x835e, 0x8360, 0x8363, 0x8365, 0x8367, 0x836e,
    0x8371, 0x8374, 0x8377, 0x837a, 0x0000
};

/**********************************************************************/
/*                                                                    */
/* HanToZen( code, flag )                                             */
/*                                                                    */
/* A function which converts half size character to full size         */
/*                                                                    */
/* code                                                               */
/* Specify half size character code                                   */
/*                                                                    */
/* flag                                                               */
/* When convert to full size, specify if kana should be converted to  */
/* hiragana or katakana                                               */
/*   0   convert to katakana                                          */
/*   1   convert to hiragana                                          */
/*                                                                    */
/* return                                                             */
/* Return full size character code                                    */
/*                                                                    */
/**********************************************************************/
WORD PASCAL HanToZen( code, fdwConversion )
register WORD code;
DWORD fdwConversion;
{
    BOOL flag;

    flag = !(fdwConversion & IME_CMODE_KATAKANA);

    if( HIBYTE( code ) ){
        WORD code2, code3;
        code2 = HanToZen( HIBYTE(code), fdwConversion );
        code3 = LOBYTE( code );
        if( code3 == (0x00FF & '�') )
            code = ConvTenten( code2 );
        else if( code3 == (0x00FF & '�') )
            code = ConvMaru( code2 );
        return( code );

    } else {
        if( code >= 0x30 && 0x39 >= code )
            return( code - 0x30 + 0x824f );
        if( code >= 0x41 && 0x5a >= code )
            return( code - 0x41 + 0x8260 );
        if( code >= 0x61 && 0x7a >= code )
            return( code - 0x61 + 0x8281 );
        if( code >= 0x20 && 0x40 >= code )
            return( table1[code-0x20] );
        if( code >= 0x3a && 0x3f >= code )
            return( table2[code-0x3a] );
        if( code >= 0x5b && 0x60 >= code )
            return( table3[code-0x5b] );
        if( code >= 0x7b && 0x6f >= code )
            return( table4[code-0x7b] );
        if( code >= 0x0a1 && 0x0df >= code )
            if( flag )
                return( table5[code-0x0a1] );
            else
                return( table6[code-0x0a1] );
        return( code );
    }
}

/**********************************************************************/
/*                                                                    */
/* ZenToHan( code )                                                   */
/*                                                                    */
/* A function which converts full size character to half size         */
/*                                                                    */
/* code                                                               */
/* Specify full size character code                                   */
/*                                                                    */
/* return                                                             */
/* Return half size character code                                    */
/*                                                                    */
/**********************************************************************/
WORD PASCAL ZenToHan( code )
WORD code;
{
    int i;

    if( code >= 0x824f && code <= 0x8258 )
        return( code - 0x824f + 0x30 );
    if( code >= 0x8260 && code <= 0x8279 )
        return( code - 0x8260 + 0x41 );
    if( code >= 0x8281 && code <= 0x829a )
        return( code - 0x8281 + 0x61 );

    for( i = 0; i < 16; i++ )
        if( code == table1[i] )
            return( 0x20 + i );
    for( i = 0; i < 6; i++ )
        if( code == table2[i] )
            return( 0x3a + i );
    for( i = 0; i < 6; i++ )
        if( code == table3[i] )
            return( 0x5b + i );
    for( i = 0; i < 5; i++ )
        if( code == table4[i] )
            return( 0x7b + i );
    for( i = 0; i < 63; i++ ){
        if( code == table5[i] )
            return( 0xa1 + i );
        if( code == table6[i] )
            return( 0xa1 + i );
    }
    return 0;
}


BOOL PASCAL IsTenten( code )
WORD code;
{
    register int i;

    for( i = 0; table8[i]; i++ )
        if( table8[i] == code )
            return( TRUE );
    return( FALSE );
}


WORD PASCAL ConvTenten( code )
WORD code;
{
    if( IsTenten( code ) )
        return( code + 1 );
    return 0;
}


BOOL PASCAL IsMaru( code )
WORD code;
{
    register int i;

    for( i = 0; table7[i]; i++ )
        if( table7[i] == code )
            return( TRUE );
    return( FALSE );
}


WORD PASCAL ConvMaru( code )
WORD code;
{
    if( IsMaru( code ) )
        return( code + 2 );
    return 0;
}


WORD PASCAL HiraToKata(WORD code)
{
    register int i;

    for( i = 0; i < 63; i++ ){
        if( code == table5[i] )
            return table6[i];
    }
    for( i = 0; i < 63; i++ )
    {
        if( code-1 == table5[i] )
            if (IsTenten(table5[i]))
                return table6[i] + 1;
        if( code-2 == table5[i] )
            if (IsMaru(table5[i]))
                return table6[i] + 2;
    }
    return code;
}

WORD PASCAL KataToHira(WORD code)
{
    register int i;

    for( i = 0; i < 63; i++ ){
        if( code == table6[i] )
            return table5[i];
    }
    for( i = 0; i < 63; i++ )
    {
        if( code-1 == table6[i] )
            if (IsTenten(table6[i]))
                return table5[i] + 1;
        if( code-2 == table6[i] )
            if (IsMaru(table6[i]))
                return table5[i] + 2;
    }
    return code;
}

void PASCAL lZenToHan(LPMYSTR lpDst,LPMYSTR lpSrc)
{
    WORD code;

#ifdef FAKEIMEM
    while(*lpSrc)
    {
        if ((*lpSrc >= 0x3040) && (*lpSrc <= 0x307D))
            *lpDst = *lpSrc + 0x60;
        else
            *lpDst = *lpSrc;

        *lpDst++;
        *lpSrc++;
    }
    *lpDst = MYTEXT('\0');
#else
    while(*lpSrc)
    {
        if (IsDBCSLeadByte(*lpSrc))
        {
            code = MAKEWORD( *(lpSrc+1), *lpSrc );
            *lpDst = (char)ZenToHan(code);
            if (!*lpDst)
            {
                if (IsTenten((WORD)(code-1)))
                {
                    *lpDst++ = (char)ZenToHan((WORD)(code-1));
                    *lpDst++ = (char)0xde;
                }
                else if (IsMaru((WORD)(code-2)))
                {
                    *lpDst++ = (char)ZenToHan((WORD)(code-2));
                    *lpDst++ = (char)0xdf;
                }
            }
            else
               lpDst++;
            lpSrc += 2;
        }
        else
            *lpDst++ = *lpSrc++;
    }
    *lpDst = MYTEXT('\0');
#endif
}

void PASCAL lHanToZen(LPMYSTR lpDst,LPMYSTR lpSrc,DWORD fdwConversion)
{
    WORD code;
    WORD code0;
    WORD code1;

#ifdef FAKEIMEM
    while(*lpSrc)
    {
        if ((*lpSrc >= 0x3040) && (*lpSrc <= 0x307D))
            *lpDst = *lpSrc + 0x60;
        else
            *lpDst = *lpSrc;

        *lpDst++;
        *lpSrc++;
    }
    *lpDst = MYTEXT('\0');
#else
    while (*lpSrc)
    {
        code0 = (WORD)*lpSrc;
        code1 = (WORD)*(lpSrc+1);

        lpSrc++;
        if (( code1 == (0x00FF & '�') )
           || ( code1 == (0x00FF & '�') ))
        {
            code0 = MAKEWORD((BYTE)code0,(BYTE)code1);
            lpSrc++;
        }

        code = HanToZen (code0,fdwConversion);
        *lpDst++ = HIBYTE(code);
        *lpDst++ = LOBYTE(code);
    }
    *lpDst = MYTEXT('\0');
#endif
}

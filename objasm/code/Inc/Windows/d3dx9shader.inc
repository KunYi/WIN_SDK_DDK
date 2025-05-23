;Include file created by h2incX, Version B.01.01, 15/11/2018 21:48
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\d3dx9shader.h', last modified: 28/08/2017 14:00
;Creation parameters: 

include d3dx9.inc
ifndef __D3DX9SHADER_H__
  __D3DX9SHADER_H__ equ <>
  D3DXTX_VERSION macro _Major, _Minor
    exitm <(('T' shl 24) or ('X' shl 16) or ((_Major) shl 8) or (_Minor))>
  endm
  D3DXSHADER_DEBUG equ (1 shl 0)
  D3DXSHADER_SKIPVALIDATION equ (1 shl 1)
  D3DXSHADER_SKIPOPTIMIZATION equ (1 shl 2)
  D3DXSHADER_PACKMATRIX_ROWMAJOR equ (1 shl 3)
  D3DXSHADER_PACKMATRIX_COLUMNMAJOR equ (1 shl 4)
  D3DXSHADER_PARTIALPRECISION equ (1 shl 5)
  D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT equ (1 shl 6)
  D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT equ (1 shl 7)
  D3DXSHADER_NO_PRESHADER equ (1 shl 8)
  D3DXSHADER_AVOID_FLOW_CONTROL equ (1 shl 9)
  D3DXSHADER_PREFER_FLOW_CONTROL equ (1 shl 10)
  D3DXSHADER_ENABLE_BACKWARDS_COMPATIBILITY equ (1 shl 12)
  D3DXSHADER_IEEE_STRICTNESS equ (1 shl 13)
  D3DXSHADER_USE_LEGACY_D3DX9_31_DLL equ (1 shl 16)
  D3DXSHADER_OPTIMIZATION_LEVEL0 equ (1 shl 14)
  D3DXSHADER_OPTIMIZATION_LEVEL1 equ 0
  D3DXSHADER_OPTIMIZATION_LEVEL2 equ ((1 shl 14) or (1 shl 15))
  D3DXSHADER_OPTIMIZATION_LEVEL3 equ (1 shl 15)
  D3DXCONSTTABLE_LARGEADDRESSAWARE equ (1 shl 17)
  ifndef D3DXFX_LARGEADDRESS_HANDLE
    D3DXHANDLE typedef LPCSTR
  else
    D3DXHANDLE typedef UINT_PTR
  endif
  LPD3DXHANDLE typedef ptr D3DXHANDLE
  D3DXMACRO struct
    Name_ LPCSTR ?
    Definition LPCSTR ?
  D3DXMACRO ends
  _D3DXMACRO typedef D3DXMACRO
  LPD3DXMACRO typedef ptr D3DXMACRO
  
  D3DXSEMANTIC struct
    Usage UINT ?
    UsageIndex UINT ?
  D3DXSEMANTIC ends
  _D3DXSEMANTIC typedef D3DXSEMANTIC
  LPD3DXSEMANTIC typedef ptr D3DXSEMANTIC
  
  D3DXREGISTER_SET typedef SDWORD
  D3DXRS_BOOL equ 0
  D3DXRS_INT4 equ 1
  D3DXRS_FLOAT4 equ 2
  D3DXRS_SAMPLER equ 3
  D3DXRS_FORCE_DWORD equ 7fffffffh
  _D3DXREGISTER_SET typedef D3DXREGISTER_SET
  LPD3DXREGISTER_SET typedef ptr D3DXREGISTER_SET
  
  D3DXPARAMETER_CLASS typedef SDWORD
  D3DXPC_SCALAR equ 0
  D3DXPC_VECTOR equ 1
  D3DXPC_MATRIX_ROWS equ 2
  D3DXPC_MATRIX_COLUMNS equ 3
  D3DXPC_OBJECT equ 4
  D3DXPC_STRUCT equ 5
  D3DXPC_FORCE_DWORD equ 7fffffffh
  _D3DXPARAMETER_CLASS typedef D3DXPARAMETER_CLASS
  LPD3DXPARAMETER_CLASS typedef ptr D3DXPARAMETER_CLASS
  
  D3DXPARAMETER_TYPE typedef SDWORD
  D3DXPT_VOID equ 0
  D3DXPT_BOOL equ 1
  D3DXPT_INT equ 2
  D3DXPT_FLOAT equ 3
  D3DXPT_STRING equ 4
  D3DXPT_TEXTURE equ 5
  D3DXPT_TEXTURE1D equ 6
  D3DXPT_TEXTURE2D equ 7
  D3DXPT_TEXTURE3D equ 8
  D3DXPT_TEXTURECUBE equ 9
  D3DXPT_SAMPLER equ 10
  D3DXPT_SAMPLER1D equ 11
  D3DXPT_SAMPLER2D equ 12
  D3DXPT_SAMPLER3D equ 13
  D3DXPT_SAMPLERCUBE equ 14
  D3DXPT_PIXELSHADER equ 15
  D3DXPT_VERTEXSHADER equ 16
  D3DXPT_PIXELFRAGMENT equ 17
  D3DXPT_VERTEXFRAGMENT equ 18
  D3DXPT_UNSUPPORTED equ 19
  D3DXPT_FORCE_DWORD equ 7fffffffh
  _D3DXPARAMETER_TYPE typedef D3DXPARAMETER_TYPE
  LPD3DXPARAMETER_TYPE typedef ptr D3DXPARAMETER_TYPE
  
  D3DXCONSTANTTABLE_DESC struct
    Creator LPCSTR ?
    Version DWORD ?
    Constants UINT ?
  D3DXCONSTANTTABLE_DESC ends
  _D3DXCONSTANTTABLE_DESC typedef D3DXCONSTANTTABLE_DESC
  LPD3DXCONSTANTTABLE_DESC typedef ptr D3DXCONSTANTTABLE_DESC
  
  D3DXCONSTANT_DESC struct
    Name_ LPCSTR ?
    RegisterSet D3DXREGISTER_SET ?
    RegisterIndex UINT ?
    RegisterCount UINT ?
    Class D3DXPARAMETER_CLASS ?
    Type_ D3DXPARAMETER_TYPE ?
    Rows UINT ?
    Columns UINT ?
    Elements UINT ?
    StructMembers UINT ?
    Bytes UINT ?
    DefaultValue LPCVOID ?
  D3DXCONSTANT_DESC ends
  _D3DXCONSTANT_DESC typedef D3DXCONSTANT_DESC
  LPD3DXCONSTANT_DESC typedef ptr D3DXCONSTANT_DESC
  
  ;ID3DXConstantTable typedef ID3DXConstantTable
  
  LPD3DXCONSTANTTABLE typedef ptr ID3DXConstantTable
  
  DEFINE_GUID IID_ID3DXConstantTable, 0ab3c758fh, 93eh, 4356h, 0b7h, 62h, 4dh, 0b1h, 8fh, 1bh, 3ah, 1h
  INTERFACE equ <ID3DXConstantTable>
  DECLARE_INTERFACE_ ID3DXConstantTable, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetBufferPointer, :THIS_
    STD_METHOD GetBufferSize, :THIS_
    STD_METHOD GetDesc, :ptr THIS_
    STD_METHOD GetConstantDesc, :THIS_, :ptr D3DXCONSTANT_DESC, :ptr UINT
    STD_METHOD GetSamplerIndex, :THIS_
    STD_METHOD GetConstant, :THIS_, :UINT
    STD_METHOD GetConstantByName, :THIS_, :LPCSTR
    STD_METHOD GetConstantElement, :THIS_, :UINT
    STD_METHOD SetDefaults, :THIS_
    STD_METHOD SetValue, :THIS_, :D3DXHANDLE, :LPCVOID, :UINT
    STD_METHOD SetBool, :THIS_, :D3DXHANDLE, :BOOL
    STD_METHOD SetBoolArray, :THIS_, :D3DXHANDLE, :ptr BOOL, :UINT
    STD_METHOD SetInt, :THIS_, :D3DXHANDLE, :INT_
    STD_METHOD SetIntArray, :THIS_, :D3DXHANDLE, :ptr INT_, :UINT
    STD_METHOD SetFloat, :THIS_, :D3DXHANDLE, :FLOAT
    STD_METHOD SetFloatArray, :THIS_, :D3DXHANDLE, :ptr FLOAT, :UINT
    STD_METHOD SetVector, :THIS_, :D3DXHANDLE, :ptr D3DXVECTOR4
    STD_METHOD SetVectorArray, :THIS_, :D3DXHANDLE, :ptr D3DXVECTOR4, :UINT
    STD_METHOD SetMatrix, :THIS_, :D3DXHANDLE, :ptr D3DXMATRIX
    STD_METHOD SetMatrixArray, :THIS_, :D3DXHANDLE, :ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixPointerArray, :THIS_, :D3DXHANDLE, :ptr ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixTranspose, :THIS_, :D3DXHANDLE, :ptr D3DXMATRIX
    STD_METHOD SetMatrixTransposeArray, :THIS_, :D3DXHANDLE, :ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixTransposePointerArray, :THIS_, :D3DXHANDLE, :ptr ptr D3DXMATRIX, :UINT
  END_DECLARE_INTERFACE_
  ;ID3DXTextureShader typedef ID3DXTextureShader
  
  LPD3DXTEXTURESHADER typedef ptr ID3DXTextureShader
  
  DEFINE_GUID IID_ID3DXTextureShader, 3e3d67f8h, 0aa7ah, 405dh, 0a8h, 57h, 0bah, 1h, 0d4h, 75h, 84h, 26h
  INTERFACE equ <ID3DXTextureShader>
  DECLARE_INTERFACE_ ID3DXTextureShader, IUnknown
    STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
    STD_METHOD AddRef, :THIS_
    STD_METHOD Release, :THIS_
    STD_METHOD GetFunction, :ptr THIS_
    STD_METHOD GetConstantBuffer, :ptr THIS_
    STD_METHOD GetDesc, :ptr THIS_
    STD_METHOD GetConstantDesc, :THIS_, :ptr D3DXCONSTANT_DESC, :ptr UINT
    STD_METHOD GetConstant, :THIS_, :UINT
    STD_METHOD GetConstantByName, :THIS_, :LPCSTR
    STD_METHOD GetConstantElement, :THIS_, :UINT
    STD_METHOD SetDefaults, :THIS_
    STD_METHOD SetValue, :THIS_, :LPCVOID, :UINT
    STD_METHOD SetBool, :THIS_, :BOOL
    STD_METHOD SetBoolArray, :THIS_, :ptr BOOL, :UINT
    STD_METHOD SetInt, :THIS_, :INT_
    STD_METHOD SetIntArray, :THIS_, :ptr INT_, :UINT
    STD_METHOD SetFloat, :THIS_, :FLOAT
    STD_METHOD SetFloatArray, :THIS_, :ptr FLOAT, :UINT
    STD_METHOD SetVector, :THIS_, :ptr D3DXVECTOR4
    STD_METHOD SetVectorArray, :THIS_, :ptr D3DXVECTOR4, :UINT
    STD_METHOD SetMatrix, :THIS_, :ptr D3DXMATRIX
    STD_METHOD SetMatrixArray, :THIS_, :ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixPointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixTranspose, :THIS_, :ptr D3DXMATRIX
    STD_METHOD SetMatrixTransposeArray, :THIS_, :ptr D3DXMATRIX, :UINT
    STD_METHOD SetMatrixTransposePointerArray, :THIS_, :ptr ptr D3DXMATRIX, :UINT
  END_DECLARE_INTERFACE_
  D3DXINCLUDE_TYPE typedef SDWORD
  D3DXINC_LOCAL equ 0
  D3DXINC_SYSTEM equ 1
  D3DXINC_FORCE_DWORD equ 7fffffffh
  _D3DXINCLUDE_TYPE typedef D3DXINCLUDE_TYPE
  LPD3DXINCLUDE_TYPE typedef ptr D3DXINCLUDE_TYPE
  
  ;ID3DXInclude typedef ID3DXInclude
  
  LPD3DXINCLUDE typedef ptr ID3DXInclude
  
  INTERFACE equ <ID3DXInclude>
  DECLARE_INTERFACE ID3DXInclude
    STD_METHOD Open, :THIS_, :LPCSTR, :LPCVOID, :ptr LPCVOID, :ptr UINT
    STD_METHOD Close, :THIS_
  END_DECLARE_INTERFACE
  ifdef __cplusplus
    ;[...]
  endif
  D3DXAssembleShaderFromFileA proto WIN_STD_CALL_CONV :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  D3DXAssembleShaderFromFileW proto WIN_STD_CALL_CONV :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXAssembleShaderFromFile equ <D3DXAssembleShaderFromFileW>
  else
    D3DXAssembleShaderFromFile equ <D3DXAssembleShaderFromFileA>
  endif
  D3DXAssembleShaderFromResourceA proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  D3DXAssembleShaderFromResourceW proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXAssembleShaderFromResource equ <D3DXAssembleShaderFromResourceW>
  else
    D3DXAssembleShaderFromResource equ <D3DXAssembleShaderFromResourceA>
  endif
  D3DXAssembleShader proto WIN_STD_CALL_CONV :LPCSTR, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  D3DXCompileShaderFromFileA proto WIN_STD_CALL_CONV :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
  D3DXCompileShaderFromFileW proto WIN_STD_CALL_CONV :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
  ifdef UNICODE
    D3DXCompileShaderFromFile equ <D3DXCompileShaderFromFileW>
  else
    D3DXCompileShaderFromFile equ <D3DXCompileShaderFromFileA>
  endif
  D3DXCompileShaderFromResourceA proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
  D3DXCompileShaderFromResourceW proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
  ifdef UNICODE
    D3DXCompileShaderFromResource equ <D3DXCompileShaderFromResourceW>
  else
    D3DXCompileShaderFromResource equ <D3DXCompileShaderFromResourceA>
  endif
  D3DXCompileShader proto WIN_STD_CALL_CONV :LPCSTR, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :LPCSTR, :LPCSTR, :DWORD, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER, :ptr LPD3DXCONSTANTTABLE
  D3DXDisassembleShader proto WIN_STD_CALL_CONV :ptr DWORD, :BOOL, :LPCSTR, :ptr LPD3DXBUFFER
  D3DXGetPixelShaderProfile proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9
  D3DXGetVertexShaderProfile proto WIN_STD_CALL_CONV :LPDIRECT3DDEVICE9
  D3DXFindShaderComment proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPCVOID, :ptr UINT
  D3DXGetShaderSize proto WIN_STD_CALL_CONV :ptr DWORD
  D3DXGetShaderVersion proto WIN_STD_CALL_CONV :ptr DWORD
  D3DXGetShaderInputSemantics proto WIN_STD_CALL_CONV :ptr DWORD, :ptr D3DXSEMANTIC, :ptr UINT
  D3DXGetShaderOutputSemantics proto WIN_STD_CALL_CONV :ptr DWORD, :ptr D3DXSEMANTIC, :ptr UINT
  D3DXGetShaderSamplers proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPCSTR, :ptr UINT
  D3DXGetShaderConstantTable proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPD3DXCONSTANTTABLE
  D3DXGetShaderConstantTableEx proto WIN_STD_CALL_CONV :ptr DWORD, :DWORD, :ptr LPD3DXCONSTANTTABLE
  D3DXCreateTextureShader proto WIN_STD_CALL_CONV :ptr DWORD, :ptr LPD3DXTEXTURESHADER
  D3DXPreprocessShaderFromFileA proto WIN_STD_CALL_CONV :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  D3DXPreprocessShaderFromFileW proto WIN_STD_CALL_CONV :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXPreprocessShaderFromFile equ <D3DXPreprocessShaderFromFileW>
  else
    D3DXPreprocessShaderFromFile equ <D3DXPreprocessShaderFromFileA>
  endif
  D3DXPreprocessShaderFromResourceA proto WIN_STD_CALL_CONV :HMODULE, :LPCSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  D3DXPreprocessShaderFromResourceW proto WIN_STD_CALL_CONV :HMODULE, :LPCWSTR, :ptr D3DXMACRO, :LPD3DXINCLUDE, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  ifdef UNICODE
    D3DXPreprocessShaderFromResource equ <D3DXPreprocessShaderFromResourceW>
  else
    D3DXPreprocessShaderFromResource equ <D3DXPreprocessShaderFromResourceA>
  endif
  D3DXPreprocessShader proto WIN_STD_CALL_CONV :LPCSTR, :UINT, :ptr D3DXMACRO, :LPD3DXINCLUDE, :ptr LPD3DXBUFFER, :ptr LPD3DXBUFFER
  ifdef __cplusplus
    ;[...]
  endif
;  D3DXSHADER_CONSTANTTABLE struct
;    Size_ DWORD ?
;    Creator DWORD ?
;    Version DWORD ?
;    Constants DWORD ?
;    ConstantInfo DWORD ?
;    Flags DWORD ?
;    Target DWORD ?
;  D3DXSHADER_CONSTANTTABLE ends
;  _D3DXSHADER_CONSTANTTABLE typedef D3DXSHADER_CONSTANTTABLE
;  LPD3DXSHADER_CONSTANTTABLE typedef ptr D3DXSHADER_CONSTANTTABLE
;  
;  D3DXSHADER_CONSTANTINFO struct
;    Name_ DWORD ?
;    RegisterSet WORD ?
;    RegisterIndex WORD ?
;    RegisterCount WORD ?
;    Reserved WORD ?
;    TypeInfo DWORD ?
;    DefaultValue DWORD ?
;  D3DXSHADER_CONSTANTINFO ends
;  _D3DXSHADER_CONSTANTINFO typedef D3DXSHADER_CONSTANTINFO
;  LPD3DXSHADER_CONSTANTINFO typedef ptr D3DXSHADER_CONSTANTINFO
;  
;  D3DXSHADER_TYPEINFO struct
;    Class WORD ?
;    Type_ WORD ?
;    Rows WORD ?
;    Columns WORD ?
;    Elements WORD ?
;    StructMembers WORD ?
;    StructMemberInfo DWORD ?
;  D3DXSHADER_TYPEINFO ends
;  _D3DXSHADER_TYPEINFO typedef D3DXSHADER_TYPEINFO
;  LPD3DXSHADER_TYPEINFO typedef ptr D3DXSHADER_TYPEINFO
;  
;  D3DXSHADER_STRUCTMEMBERINFO struct
;    Name_ DWORD ?
;    TypeInfo DWORD ?
;  D3DXSHADER_STRUCTMEMBERINFO ends
;  _D3DXSHADER_STRUCTMEMBERINFO typedef D3DXSHADER_STRUCTMEMBERINFO
;  LPD3DXSHADER_STRUCTMEMBERINFO typedef ptr D3DXSHADER_STRUCTMEMBERINFO
  
endif


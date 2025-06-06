'' FreeBASIC binding for cd-5.8.2
''
'' based on the C header files:
''   Copyright (C) 1994-2014 Tecgraf, PUC-Rio.
''
''   Permission is hereby granted, free of charge, to any person obtaining
''   a copy of this software and associated documentation files (the
''   "Software"), to deal in the Software without restriction, including
''   without limitation the rights to use, copy, modify, merge, publish,
''   distribute, sublicense, and/or sell copies of the Software, and to
''   permit persons to whom the Software is furnished to do so, subject to
''   the following conditions:
''
''   The above copyright notice and this permission notice shall be
''   included in all copies or substantial portions of the Software.
''
''   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
''   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
''   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
''   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
''   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
''   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
''   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
''
'' translated to FreeBASIC by:
''   FreeBASIC development team

#pragma once

#inclib "cdlua52"

#if defined(LUA_NOOBJECT) or ((not defined(LUA_NOOBJECT)) and defined(LUA_TNONE))
	extern "C"
#endif

#define __CD_LUA_H

#ifdef LUA_NOOBJECT
	declare sub cdlua_open()
	declare sub cdlua_close()
	declare function cdlua_getcanvas() as cdCanvas ptr
	declare function cdlua_checkcanvas(byval pos as long) as cdCanvas ptr
	declare sub cdlua_pushcanvas(byval canvas as cdCanvas ptr)
#endif

#ifdef LUA_TNONE
	declare function cdlua_open(byval L as lua_State ptr) as long
	declare function cdlua_close(byval L as lua_State ptr) as long
	declare function cdlua_getcanvas(byval L as lua_State ptr) as cdCanvas ptr
	declare function cdlua_checkcanvas(byval L as lua_State ptr, byval pos as long) as cdCanvas ptr
	declare sub cdlua_pushcanvas(byval L as lua_State ptr, byval canvas as cdCanvas ptr)
#endif

#if defined(LUA_NOOBJECT) or ((not defined(LUA_NOOBJECT)) and defined(LUA_TNONE))
	end extern
#endif

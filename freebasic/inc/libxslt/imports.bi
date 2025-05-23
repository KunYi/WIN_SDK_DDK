'' FreeBASIC binding for libxslt-1.1.28
''
'' based on the C header files:
''    Copyright (C) 2001-2002 Daniel Veillard.  All Rights Reserved.
''
''   Permission is hereby granted, free of charge, to any person obtaining a copy
''   of this software and associated documentation files (the "Software"), to deal
''   in the Software without restriction, including without limitation the rights
''   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
''   copies of the Software, and to permit persons to whom the Software is fur-
''   nished to do so, subject to the following conditions:
''
''   The above copyright notice and this permission notice shall be included in
''   all copies or substantial portions of the Software.
''
''   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
''   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FIT-
''   NESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
''   DANIEL VEILLARD BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
''   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CON-
''   NECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
''
''   Except as contained in this notice, the name of Daniel Veillard shall not
''   be used in advertising or otherwise to promote the sale, use or other deal-
''   ings in this Software without prior written authorization from him.
''
'' translated to FreeBASIC by:
''   FreeBASIC development team

#pragma once

#include once "libxml/tree.bi"
#include once "xsltexports.bi"
#include once "xsltInternals.bi"

extern "C"

#define __XML_XSLT_IMPORTS_H__
#macro XSLT_GET_IMPORT_PTR(res, style, name)
	scope
		dim st as xsltStylesheetPtr = style
		res = NULL
		while st <> NULL
			if st->name <> NULL then
				res = st->name
				exit while
			end if
			st = xsltNextImport(st)
		wend
	end scope
#endmacro
#macro XSLT_GET_IMPORT_INT(res, style, name)
	scope
		dim st as xsltStylesheetPtr = style
		res = -1
		while st <> NULL
			if st->name <> (-1) then
				res = st->name
				exit while
			end if
			st = xsltNextImport(st)
		wend
	end scope
#endmacro

declare function xsltParseStylesheetImport(byval style as xsltStylesheetPtr, byval cur as xmlNodePtr) as long
declare function xsltParseStylesheetInclude(byval style as xsltStylesheetPtr, byval cur as xmlNodePtr) as long
declare function xsltNextImport(byval style as xsltStylesheetPtr) as xsltStylesheetPtr
declare function xsltNeedElemSpaceHandling(byval ctxt as xsltTransformContextPtr) as long
declare function xsltFindElemSpaceHandling(byval ctxt as xsltTransformContextPtr, byval node as xmlNodePtr) as long
declare function xsltFindTemplate(byval ctxt as xsltTransformContextPtr, byval name as const xmlChar ptr, byval nameURI as const xmlChar ptr) as xsltTemplatePtr

end extern

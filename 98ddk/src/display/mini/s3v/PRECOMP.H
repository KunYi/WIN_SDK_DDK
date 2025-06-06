/******************************Module*Header*******************************\
* Module Name: precomp.h
*
* Common headers used throughout the display driver.  This entire include
* file will typically be pre-compiled.
*
* Copyright (c) 1993-1995 Microsoft Corporation
\**************************************************************************/

#include <stddef.h>
#include <stdarg.h>
#include <limits.h>

#ifdef WINNT

#include <windef.h>
#include <winerror.h>
#include <wingdi.h>
#include <winddi.h>
#include <devioctl.h>
#include <ntddvdeo.h>
#include <ioaccess.h>

#include "lines.h"
#include "driver.h"
#include "hw.h"
#include "hw3d.h"
#include "debug.h"

#endif


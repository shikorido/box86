#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <setjmp.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x86emu.h"
#include "emu/x86emu_private.h"
#include "callback.h"
#include "librarian.h"
#include "box86context.h"
#include "emu/x86emu_private.h"
#include "myalign.h"

const char* turbojpegName =
#ifdef ANDROID
    "libturbojpeg.so";
#else
    "libturbojpeg.so.0";
#endif
#define LIBNAME turbojpeg

#define CUSTOM_INIT \
    SETALT(myturbo_);

#include "wrappedlib_init.h"

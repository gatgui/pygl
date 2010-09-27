/*

Copyright (C) 2010  Gaetan Guidet

This file is part of pygl.

luagl is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at
your option) any later version.

luagl is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
USA.

*/

#ifndef __common_h_
#define __common_h_

#ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
# pragma warning(disable: 4702 4290)
# define EXPORT extern "C" __declspec(dllexport)
#else
# define EXPORT extern "C"
# define CALLBACK
#endif

#include <GL/glew.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>

#include <Python.h>

#include "mem/manager.h"


#define INIT_TYPE(ptype, name, ctype)\
  memset(&ptype, 0, sizeof(PyTypeObject));\
  ptype.ob_refcnt = 1;\
  ptype.ob_size = 0;\
  ptype.tp_name = name;\
  ptype.tp_basicsize = sizeof(ctype)


#endif

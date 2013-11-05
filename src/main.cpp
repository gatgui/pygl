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

#include <Python.h>

extern bool PyGL_InitBuffer(PyObject *mod);
extern bool PyGL_InitGL(PyObject *mod);
extern bool PyGL_InitGLU(PyObject *mod);
extern bool PyGL_InitGLUT(PyObject *mod);

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#else
__attribute__ ((visibility ("default")))
#endif
void initpygl(void)
{
  PyObject *mod = Py_InitModule("pygl", 0);
  
  if (!PyGL_InitBuffer(mod))
  {
    Py_DECREF(mod);
    return;
  }
  
  if (!PyGL_InitGL(mod))
  {
    Py_DECREF(mod);
    return;
  }
  
  if (!PyGL_InitGLU(mod))
  {
    Py_DECREF(mod);
    return;
  }
  
  if (!PyGL_InitGLUT(mod))
  {
    Py_DECREF(mod);
    return;
  }
}

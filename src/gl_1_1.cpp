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

#include "pygl.h"

static PyObject* py_glGetError(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 0);
  Enum r(glGetError());
  return r.toPy();
}

static PyObject* py_glEnable(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glEnable);
}

static PyObject* py_glDisable(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glDisable);
}

static PyObject* py_glIsEnabled(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum e(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsEnabled(e) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glBegin(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glBegin);
}

static PyObject* py_glEnd(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glEnd);
}

static PyObject* py_glEdgeFlag(PyObject *self, PyObject *args) {
  return WrapFunc1<Boolean>::Call(self, args, glEdgeFlag);
}

static PyObject* py_glVertex2s(PyObject *self, PyObject *args) {
  return WrapFunc2<Short, Short>::Call(self, args, glVertex2s);
}
static PyObject* py_glVertex2i(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int>::Call(self, args, glVertex2i);
}
static PyObject* py_glVertex2f(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glVertex2f);
}
static PyObject* py_glVertex2d(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double>::Call(self, args, glVertex2d);
}
static PyObject* py_glVertex3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short>::Call(self, args, glVertex3s);
}
static PyObject* py_glVertex3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int>::Call(self, args, glVertex3i);
}
static PyObject* py_glVertex3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glVertex3f);
}
static PyObject* py_glVertex3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glVertex3d);
}
static PyObject* py_glVertex4s(PyObject *self, PyObject *args) {
  return WrapFunc4<Short, Short, Short, Short>::Call(self, args, glVertex4s);
}
static PyObject* py_glVertex4i(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int>::Call(self, args, glVertex4i);
}
static PyObject* py_glVertex4f(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glVertex4f);
}
static PyObject* py_glVertex4d(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glVertex4d);
}
static PyObject* py_glVertex2sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glVertex2sv);
}
static PyObject* py_glVertex2iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glVertex2iv);
}
static PyObject* py_glVertex2fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glVertex2fv);
}
static PyObject* py_glVertex2dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glVertex2dv);
}
static PyObject* py_glVertex3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glVertex3sv);
}
static PyObject* py_glVertex3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glVertex3iv);
}
static PyObject* py_glVertex3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glVertex3fv);
}
static PyObject* py_glVertex3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glVertex3dv);
}
static PyObject* py_glVertex4sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glVertex4sv);
}
static PyObject* py_glVertex4iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glVertex4iv);
}
static PyObject* py_glVertex4fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glVertex4fv);
}
static PyObject* py_glVertex4dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glVertex4dv);
}

static PyObject* py_glTexCoord1s(PyObject *self, PyObject *args) {
  return WrapFunc1<Short>::Call(self, args, glTexCoord1s);
}
static PyObject* py_glTexCoord1i(PyObject *self, PyObject *args) {
  return WrapFunc1<Int>::Call(self, args, glTexCoord1i);
}
static PyObject* py_glTexCoord1f(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glTexCoord1f);
}
static PyObject* py_glTexCoord1d(PyObject *self, PyObject *args) {
  return WrapFunc1<Double>::Call(self, args, glTexCoord1d);
}
// no v variant for glTexCoord1
static PyObject* py_glTexCoord2s(PyObject *self, PyObject *args) {
  return WrapFunc2<Short, Short>::Call(self, args, glTexCoord2s);
}
static PyObject* py_glTexCoord2i(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int>::Call(self, args, glTexCoord2i);
}
static PyObject* py_glTexCoord2f(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glTexCoord2f);
}
static PyObject* py_glTexCoord2d(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double>::Call(self, args, glTexCoord2d);
}
static PyObject* py_glTexCoord2sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glTexCoord2sv);
}
static PyObject* py_glTexCoord2iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glTexCoord2iv);
}
static PyObject* py_glTexCoord2fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glTexCoord2fv);
}
static PyObject* py_glTexCoord2dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glTexCoord2dv);
}
static PyObject* py_glTexCoord3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short>::Call(self, args, glTexCoord3s);
}
static PyObject* py_glTexCoord3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int>::Call(self, args, glTexCoord3i);
}
static PyObject* py_glTexCoord3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glTexCoord3f);
}
static PyObject* py_glTexCoord3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glTexCoord3d);
}
static PyObject* py_glTexCoord3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glTexCoord3sv);
}
static PyObject* py_glTexCoord3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glTexCoord3iv);
}
static PyObject* py_glTexCoord3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glTexCoord3fv);
}
static PyObject* py_glTexCoord3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glTexCoord3dv);
}
static PyObject* py_glTexCoord4s(PyObject *self, PyObject *args) {
  return WrapFunc4<Short, Short, Short, Short>::Call(self, args, glTexCoord4s);
}
static PyObject* py_glTexCoord4i(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int>::Call(self, args, glTexCoord4i);
}
static PyObject* py_glTexCoord4f(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glTexCoord4f);
}
static PyObject* py_glTexCoord4d(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glTexCoord4d);
}
static PyObject* py_glTexCoord4sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glTexCoord4sv);
}
static PyObject* py_glTexCoord4iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glTexCoord4iv);
}
static PyObject* py_glTexCoord4fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glTexCoord4fv);
}
static PyObject* py_glTexCoord4dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glTexCoord4dv);
}

static PyObject* py_glNormal3b(PyObject *self, PyObject *args) {
  return WrapFunc3<Byte, Byte, Byte>::Call(self, args, glNormal3b);
}
static PyObject* py_glNormal3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short>::Call(self, args, glNormal3s);
}
static PyObject* py_glNormal3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int>::Call(self, args, glNormal3i);
}
static PyObject* py_glNormal3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glNormal3f);
}
static PyObject* py_glNormal3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glNormal3d);
}
static PyObject* py_glNormal3bv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Byte> >::Call(self, args, glNormal3bv);
}
static PyObject* py_glNormal3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glNormal3sv);
}
static PyObject* py_glNormal3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glNormal3iv);
}
static PyObject* py_glNormal3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glNormal3fv);
}
static PyObject* py_glNormal3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glNormal3dv);
}

static PyObject* py_glColor3b(PyObject *self, PyObject *args) {
  return WrapFunc3<Byte, Byte, Byte>::Call(self, args, glColor3b);
}
static PyObject* py_glColor3ub(PyObject *self, PyObject *args) {
  return WrapFunc3<Ubyte, Ubyte, Ubyte>::Call(self, args, glColor3ub);
}
static PyObject* py_glColor3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short>::Call(self, args, glColor3s);
}
static PyObject* py_glColor3us(PyObject *self, PyObject *args) {
  return WrapFunc3<Ushort, Ushort, Ushort>::Call(self, args, glColor3us);
}
static PyObject* py_glColor3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int>::Call(self, args, glColor3i);
}
static PyObject* py_glColor3ui(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Uint, Uint>::Call(self, args, glColor3ui);
}
static PyObject* py_glColor3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glColor3f);
}
static PyObject* py_glColor3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glColor3d);
}
static PyObject* py_glColor3bv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Byte> >::Call(self, args, glColor3bv);
}
static PyObject* py_glColor3ubv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ubyte> >::Call(self, args, glColor3ubv);
}
static PyObject* py_glColor3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glColor3sv);
}
static PyObject* py_glColor3usv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ushort> >::Call(self, args, glColor3usv);
}
static PyObject* py_glColor3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glColor3iv);
}
static PyObject* py_glColor3uiv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Uint> >::Call(self, args, glColor3uiv);
}
static PyObject* py_glColor3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glColor3fv);
}
static PyObject* py_glColor3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glColor3dv);
}
static PyObject* py_glColor4b(PyObject *self, PyObject *args) {
  return WrapFunc4<Byte, Byte, Byte, Byte>::Call(self, args, glColor4b);
}
static PyObject* py_glColor4ub(PyObject *self, PyObject *args) {
  return WrapFunc4<Ubyte, Ubyte, Ubyte, Ubyte>::Call(self, args, glColor4ub);
}
static PyObject* py_glColor4s(PyObject *self, PyObject *args) {
  return WrapFunc4<Short, Short, Short, Short>::Call(self, args, glColor4s);
}
static PyObject* py_glColor4us(PyObject *self, PyObject *args) {
  return WrapFunc4<Ushort, Ushort, Ushort, Ushort>::Call(self, args, glColor4us);
}
static PyObject* py_glColor4i(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int>::Call(self, args, glColor4i);
}
static PyObject* py_glColor4ui(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Uint, Uint, Uint>::Call(self, args, glColor4ui);
}
static PyObject* py_glColor4f(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glColor4f);
}
static PyObject* py_glColor4d(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glColor4d);
}
static PyObject* py_glColor4bv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Byte> >::Call(self, args, glColor4bv);
}
static PyObject* py_glColor4ubv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ubyte> >::Call(self, args, glColor4ubv);
}
static PyObject* py_glColor4sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glColor4sv);
}
static PyObject* py_glColor4usv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ushort> >::Call(self, args, glColor4usv);
}
static PyObject* py_glColor4iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glColor4iv);
}
static PyObject* py_glColor4uiv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Uint> >::Call(self, args, glColor4uiv);
}
static PyObject* py_glColor4fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glColor4fv);
}
static PyObject* py_glColor4dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glColor4dv);
}

// no v variant, always 1 arg
static PyObject* py_glIndexs(PyObject *self, PyObject *args) {
  return WrapFunc1<Short>::Call(self, args, glIndexs);
}
static PyObject* py_glIndexi(PyObject *self, PyObject *args) {
  return WrapFunc1<Int>::Call(self, args, glIndexi);
}
static PyObject* py_glIndexf(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glIndexf);
}
static PyObject* py_glIndexd(PyObject *self, PyObject *args) {
  return WrapFunc1<Double>::Call(self, args, glIndexd);
}
static PyObject* py_glIndexub(PyObject *self, PyObject *args) {
  return WrapFunc1<Ubyte>::Call(self, args, glIndexub);
}

static PyObject* py_glVertexPointer(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(self, args, glVertexPointer);
}

static PyObject* py_glTexCoordPointer(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(self, args, glTexCoordPointer);
}

static PyObject* py_glNormalPointer(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(self, args, glNormalPointer);
}

static PyObject* py_glColorPointer(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, ConstPtr>::Call(self, args, glColorPointer);
}

static PyObject* py_glIndexPointer(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(self, args, glIndexPointer);
}

static PyObject* py_glEdgeFlagPointer(PyObject *self, PyObject *args) {
  return WrapFunc2<Sizei, ConstPtr>::Call(self, args, glEdgeFlagPointer);
}

static PyObject* py_glEnableClientState(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glEnableClientState);
}

static PyObject* py_glDisableClientState(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glDisableClientState);
}

static PyObject* py_glArrayElement(PyObject *self, PyObject *args) {
  return WrapFunc1<Int>::Call(self, args, glArrayElement);
}

static PyObject* py_glDrawArrays(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Sizei>::Call(self, args, glDrawArrays);
}

static PyObject* py_glDrawElements(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Sizei, Enum, ConstPtr>::Call(self, args, glDrawElements);
}

static PyObject* py_glInterleavedArrays(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstPtr>::Call(self, args, glInterleavedArrays);
}

static PyObject* py_glRects(PyObject *self, PyObject *args) {
  return WrapFunc4<Short, Short, Short, Short>::Call(self, args, glRects);
}
static PyObject* py_glRecti(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int>::Call(self, args, glRecti);
}
static PyObject* py_glRectf(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glRectf);
}
static PyObject* py_glRectd(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glRectd);
}
static PyObject* py_glRectsv(PyObject *self, PyObject *args) {
  return WrapFunc2<ConstArray<Short>, ConstArray<Short> >::Call(self, args, glRectsv);
}
static PyObject* py_glRectiv(PyObject *self, PyObject *args) {
  return WrapFunc2<ConstArray<Int>, ConstArray<Int> >::Call(self, args, glRectiv);
}
static PyObject* py_glRectfv(PyObject *self, PyObject *args) {
  return WrapFunc2<ConstArray<Float>, ConstArray<Float> >::Call(self, args, glRectfv);
}
static PyObject* py_glRectdv(PyObject *self, PyObject *args) {
  return WrapFunc2<ConstArray<Double>, ConstArray<Double> >::Call(self, args, glRectdv);
}

static PyObject* py_glDepthRange(PyObject *self, PyObject *args) {
  return WrapFunc2<Clampd, Clampd>::Call(self, args, glDepthRange);
}

static PyObject* py_glViewport(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Sizei, Sizei>::Call(self, args, glViewport);
}

static PyObject* py_glMatrixMode(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glMatrixMode);
}

static PyObject* py_glLoadMatrixf(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Float> m(PyTuple_GetItem(args, 0));
  if (m.size() != 16) {
    PyErr_SetString(PyExc_RuntimeError, "gl.LoadMatrixf: Invalid matrix data");
  }
  glLoadMatrixf(m);
  Py_RETURN_NONE;
}
static PyObject* py_glLoadMatrixd(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Double> m(PyTuple_GetItem(args, 0));
  if (m.size() != 16) {
    PyErr_SetString(PyExc_RuntimeError, "gl.LoadMatrixd: Invalid matrix data");
  }
  glLoadMatrixd(m);
  Py_RETURN_NONE;
}

static PyObject* py_glMultMatrixf(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Float> m(PyTuple_GetItem(args, 0));
  if (m.size() != 16) {
    PyErr_SetString(PyExc_RuntimeError, "gl.MultMatrixf: Invalid matrix data");
  }
  glMultMatrixf(m);
  Py_RETURN_NONE;
}
static PyObject* py_glMultMatrixd(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Double> m(PyTuple_GetItem(args, 0));
  if (m.size() != 16) {
    PyErr_SetString(PyExc_RuntimeError, "gl.MultMatrixd: Invalid matrix data");
  }
  glMultMatrixd(m);
  Py_RETURN_NONE;
}

static PyObject* py_glLoadIdentity(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glLoadIdentity);
}

static PyObject* py_glRotatef(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glRotatef);
}
static PyObject* py_glRotated(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glRotated);
}

static PyObject* py_glTranslatef(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glTranslatef);
}
static PyObject* py_glTranslated(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glTranslated);
}

static PyObject* py_glScalef(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glScalef);
}
static PyObject* py_glScaled(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glScaled);
}

static PyObject* py_glFrustum(PyObject *self, PyObject *args) {
  return WrapFunc6<Double, Double, Double, Double, Double, Double>::Call(self, args, glFrustum);
}

static PyObject* py_glOrtho(PyObject *self, PyObject *args) {
  return WrapFunc6<Double, Double, Double, Double, Double, Double>::Call(self, args, glOrtho);
}

static PyObject* py_glPushMatrix(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glPushMatrix);
}

static PyObject* py_glPopMatrix(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glPopMatrix);
}

static PyObject* py_glTexGeni(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int>::Call(self, args, glTexGeni);
}
static PyObject* py_glTexGenf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float>::Call(self, args, glTexGenf);
}
static PyObject* py_glTexGend(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Double>::Call(self, args, glTexGend);
}
static PyObject* py_glTexGeniv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glTexGeniv);
}
static PyObject* py_glTexGenfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glTexGenfv);
}
static PyObject* py_glTexGendv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Double> >::Call(self, args, glTexGendv);
}

static PyObject* py_glClipPlane(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Double> >::Call(self, args, glClipPlane);
}

static PyObject* py_glRasterPos2s(PyObject *self, PyObject *args) {
  return WrapFunc2<Short, Short>::Call(self, args, glRasterPos2s);
}
static PyObject* py_glRasterPos2i(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int>::Call(self, args, glRasterPos2i);
}
static PyObject* py_glRasterPos2f(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glRasterPos2f);
}
static PyObject* py_glRasterPos2d(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double>::Call(self, args, glRasterPos2d);
}
static PyObject* py_glRasterPos2sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glRasterPos2sv);
}
static PyObject* py_glRasterPos2iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glRasterPos2iv);
}
static PyObject* py_glRasterPos2fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glRasterPos2fv);
}
static PyObject* py_glRasterPos2dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glRasterPos2dv);
}
static PyObject* py_glRasterPos3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short>::Call(self, args, glRasterPos3s);
}
static PyObject* py_glRasterPos3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int>::Call(self, args, glRasterPos3i);
}
static PyObject* py_glRasterPos3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float>::Call(self, args, glRasterPos3f);
}
static PyObject* py_glRasterPos3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double>::Call(self, args, glRasterPos3d);
}
static PyObject* py_glRasterPos3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glRasterPos3sv);
}
static PyObject* py_glRasterPos3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glRasterPos3iv);
}
static PyObject* py_glRasterPos3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glRasterPos3fv);
}
static PyObject* py_glRasterPos3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glRasterPos3dv);
}
static PyObject* py_glRasterPos4s(PyObject *self, PyObject *args) {
  return WrapFunc4<Short, Short, Short, Short>::Call(self, args, glRasterPos4s);
}
static PyObject* py_glRasterPos4i(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int>::Call(self, args, glRasterPos4i);
}
static PyObject* py_glRasterPos4f(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glRasterPos4f);
}
static PyObject* py_glRasterPos4d(PyObject *self, PyObject *args) {
  return WrapFunc4<Double, Double, Double, Double>::Call(self, args, glRasterPos4d);
}
static PyObject* py_glRasterPos4sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glRasterPos4sv);
}
static PyObject* py_glRasterPos4iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glRasterPos4iv);
}
static PyObject* py_glRasterPos4fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glRasterPos4fv);
}
static PyObject* py_glRasterPos4dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glRasterPos4dv);
}

static PyObject* py_glFrontFace(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glFrontFace);
}

static PyObject* py_glMateriali(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int>::Call(self, args, glMateriali);
}
static PyObject* py_glMaterialf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float>::Call(self, args, glMaterialf);
}
static PyObject* py_glMaterialiv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glMaterialiv);
}
static PyObject* py_glMaterialfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glMaterialfv);
}

static PyObject* py_glLighti(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int>::Call(self, args, glLighti);
}
static PyObject* py_glLightf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float>::Call(self, args, glLightf);
}
static PyObject* py_glLightiv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glLightiv);
}
static PyObject* py_glLightfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glLightfv);
}

static PyObject* py_glLightModeli(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int>::Call(self, args, glLightModeli);
}
static PyObject* py_glLightModelf(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float>::Call(self, args, glLightModelf);
}
static PyObject* py_glLightModeliv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Int> >::Call(self, args, glLightModeliv);
}
static PyObject* py_glLightModelfv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Float> >::Call(self, args, glLightModelfv);
}

static PyObject* py_glColorMaterial(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum>::Call(self, args, glColorMaterial);
}

static PyObject* py_glShadeModel(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glShadeModel);
}

static PyObject* py_glPointSize(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glPointSize);
}

static PyObject* py_glLineWidth(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glLineWidth);
}

static PyObject* py_glLineStipple(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Ushort>::Call(self, args, glLineStipple);
}

static PyObject* py_glCullFace(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glCullFace);
}

static PyObject* py_glPolygonStipple(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstTypedPtr<Ubyte> >::Call(self, args, glPolygonStipple);
}

static PyObject* py_glPolygonMode(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum>::Call(self, args, glPolygonMode);
}

static PyObject* py_glPolygonOffset(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glPolygonOffset);
}

static PyObject* py_glPixelStorei(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int>::Call(self, args, glPixelStorei);
}
static PyObject* py_glPixelStoref(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float>::Call(self, args, glPixelStoref);
}

static PyObject* py_glPixelTransferi(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int>::Call(self, args, glPixelTransferi);
}
static PyObject* py_glPixelTransferf(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float>::Call(self, args, glPixelTransferf);
}

static PyObject* py_glPixelMapusv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Ushort> >::Call(self, args, glPixelMapusv);
}
static PyObject* py_glPixelMapuiv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Uint> >::Call(self, args, glPixelMapuiv);
}
static PyObject* py_glPixelMapfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstTypedPtr<Float> >::Call(self, args, glPixelMapfv);
}

static PyObject* py_glDrawPixels(PyObject *self, PyObject *args) {
  return WrapFunc5<Sizei, Sizei, Enum, Enum, ConstPtr>::Call(self, args, glDrawPixels);
}

static PyObject* py_glPixelZoom(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glPixelZoom);
}

static PyObject* py_glBitmap(PyObject *self, PyObject *args) {
  return WrapFunc7<Sizei, Sizei, Float, Float, Float, Float,
                   ConstTypedPtr<Ubyte> >::Call(self, args, glBitmap);
}

static PyObject* py_glTexImage1D(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Int, Int, Sizei, Int,
                   Enum, Enum, ConstPtr>::Call(self, args, glTexImage1D);
}

static PyObject* py_glTexImage2D(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Int, Sizei, Sizei, Int,
                   Enum, Enum, ConstPtr>::Call(self, args, glTexImage2D);
}

static PyObject* py_glCopyTexImage1D(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Enum, Int, Int, Sizei,
                   Int>::Call(self, args, glCopyTexImage1D);
}

static PyObject* py_glCopyTexImage2D(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Int, Enum, Int, Int, Sizei,
                   Sizei, Int>::Call(self, args, glCopyTexImage2D);
}

static PyObject* py_glTexSubImage1D(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Enum, ConstPtr>::Call(self, args, glTexSubImage1D);
}

static PyObject* py_glTexSubImage2D(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum,
                   Enum, ConstPtr>::Call(self, args, glTexSubImage2D);
}

static PyObject* py_glCopyTexSubImage1D(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Int, Int, Int, Int, Sizei>::Call(self, args, glCopyTexSubImage1D);
}

static PyObject* py_glCopyTexSubImage2D(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Int, Int, Int, Int, Int, Sizei, Sizei>::Call(self, args, glCopyTexSubImage2D);
}

static PyObject* py_glTexParameteri(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int>::Call(self, args, glTexParameteri);
}
static PyObject* py_glTexParameterf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float>::Call(self, args, glTexParameterf);
}
static PyObject* py_glTexParameteriv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glTexParameteriv);
}
static PyObject* py_glTexParameterfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glTexParameterfv);
}

static PyObject* py_glBindTexture(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint>::Call(self, args, glBindTexture);
}

static PyObject* py_glGenTextures(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> textures(n);
  glGenTextures(n, textures);
  return textures.toPy();
}

static PyObject* py_glDeleteTextures(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> textures(PyTuple_GetItem(args, 0));
  glDeleteTextures(textures.size(), textures);
  Py_RETURN_NONE;
}

static PyObject* py_glAreTexturesResident(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> textures(PyTuple_GetItem(args, 0));
  Array1D<Boolean> residences(textures.size());
  glAreTexturesResident(textures.size(), textures, residences);
  return residences.toPy();
}

static PyObject* py_glPrioritizeTextures(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Array1D<Uint> textures(PyTuple_GetItem(args, 0));
  Array1D<Clampf> priorities(PyTuple_GetItem(args, 1));
  if (priorities.size() != textures.size()) {
    PyErr_SetString(PyExc_RuntimeError, "gl.PrioritizeTextures: arrays length mismatch");
    return NULL;
  }
  glPrioritizeTextures(textures.size(), textures, priorities);
  Py_RETURN_NONE;
}

static PyObject* py_glTexEnvi(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int>::Call(self, args, glTexEnvi);
}
static PyObject* py_glTexEnvf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float>::Call(self, args, glTexEnvf);
}
static PyObject* py_glTexEnviv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glTexEnviv);
}
static PyObject* py_glTexEnvfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glTexEnvfv);
}

static PyObject* py_glFogi(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int>::Call(self, args, glFogi);
}
static PyObject* py_glFogf(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float>::Call(self, args, glFogf);
}
static PyObject* py_glFogiv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Int> >::Call(self, args, glFogiv);
}
static PyObject* py_glFogfv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Float> >::Call(self, args, glFogfv);
}

static PyObject* py_glScissor(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Sizei, Sizei>::Call(self, args, glScissor);
}

static PyObject* py_glAlphaFunc(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Clampf>::Call(self, args, glAlphaFunc);
}

static PyObject* py_glStencilFunc(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Uint>::Call(self, args, glStencilFunc);
}

static PyObject* py_glStencilOp(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Enum>::Call(self, args, glStencilOp);
}

static PyObject* py_glDepthFunc(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glDepthFunc);
}

static PyObject* py_glBlendFunc(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum>::Call(self, args, glBlendFunc);
}

static PyObject* py_glLogicOp(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glLogicOp);
}

static PyObject* py_glDrawBuffer(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glDrawBuffer);
}

static PyObject* py_glIndexMask(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glIndexMask);
}

static PyObject* py_glColorMask(PyObject *self, PyObject *args) {
  return WrapFunc4<Boolean, Boolean, Boolean, Boolean>::Call(self, args, glColorMask);
}

static PyObject* py_glDepthMask(PyObject *self, PyObject *args) {
  return WrapFunc1<Boolean>::Call(self, args, glDepthMask);
}

static PyObject* py_glStencilMask(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glStencilMask);
}

static PyObject* py_glClear(PyObject *self, PyObject *args) {
  return WrapFunc1<Bitfield>::Call(self, args, glClear);
}

static PyObject* py_glClearColor(PyObject *self, PyObject *args) {
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf>::Call(self, args, glClearColor);
}

static PyObject* py_glClearIndex(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glClearIndex);
}

static PyObject* py_glClearDepth(PyObject *self, PyObject *args) {
  return WrapFunc1<Clampd>::Call(self, args, glClearDepth);
}

static PyObject* py_glClearStencil(PyObject *self, PyObject *args) {
  return WrapFunc1<Int>::Call(self, args, glClearStencil);
}

static PyObject* py_glClearAccum(PyObject *self, PyObject *args) {
  return WrapFunc4<Float, Float, Float, Float>::Call(self, args, glClearAccum);
}

static PyObject* py_glAccum(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float>::Call(self, args, glAccum);
}

static PyObject* py_glReadPixels(PyObject *self, PyObject *args) {
  return WrapFunc7<Int, Int, Sizei, Sizei, Enum, Enum, Ptr>::Call(self, args, glReadPixels);
}

static PyObject* py_glReadBuffer(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum>::Call(self, args, glReadBuffer);
}

static PyObject* py_glCopyPixels(PyObject *self, PyObject *args) {
  return WrapFunc5<Int, Int, Sizei, Sizei, Enum>::Call(self, args, glCopyPixels);
}

static PyObject* py_glMap1f(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Float, Float, Int, Int, ConstTypedPtr<Float> >::Call(self, args, glMap1f);
}
static PyObject* py_glMap1d(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Double, Double, Int, Int, ConstTypedPtr<Double> >::Call(self, args, glMap1d);
}

static PyObject* py_glMap2f(PyObject *self, PyObject *args) {
  return WrapFunc10<Enum, Float, Float, Int, Int, Float, Float, Int, Int, ConstTypedPtr<Float> >::Call(self, args, glMap2f);
}
static PyObject* py_glMap2d(PyObject *self, PyObject *args) {
  return WrapFunc10<Enum, Double, Double, Int, Int, Double, Double, Int, Int, ConstTypedPtr<Double> >::Call(self, args, glMap2d);
}

static PyObject* py_glEvalCoord1f(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glEvalCoord1f);
}
static PyObject* py_glEvalCoord1d(PyObject *self, PyObject *args) {
  return WrapFunc1<Double>::Call(self, args, glEvalCoord1d);
}
static PyObject* py_glEvalCoord2f(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float>::Call(self, args, glEvalCoord2f);
}
static PyObject* py_glEvalCoord2d(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double>::Call(self, args, glEvalCoord2d);
}
static PyObject* py_glEvalCoord2fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glEvalCoord2fv);
}
static PyObject* py_glEvalCoord2dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glEvalCoord2dv);
}

static PyObject* py_glMapGrid1f(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Float, Float>::Call(self, args, glMapGrid1f);
}
static PyObject* py_glMapGrid1d(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Double, Double>::Call(self, args, glMapGrid1d);
}
static PyObject* py_glMapGrid2f(PyObject *self, PyObject *args) {
  return WrapFunc6<Int, Float, Float, Int, Float, Float>::Call(self, args, glMapGrid2f);
}
static PyObject* py_glMapGrid2d(PyObject *self, PyObject *args) {
  return WrapFunc6<Int, Double, Double, Int, Double, Double>::Call(self, args, glMapGrid2d);
}

static PyObject* py_glEvalMesh1(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Int>::Call(self, args, glEvalMesh1);
}
static PyObject* py_glEvalMesh2(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Int, Int, Int, Int>::Call(self, args, glEvalMesh2);
}

static PyObject* py_glEvalPoint1(PyObject *self, PyObject *args) {
  return WrapFunc1<Int>::Call(self, args, glEvalPoint1);
}
static PyObject* py_glEvalPoint2(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int>::Call(self, args, glEvalPoint2);
}

static PyObject* py_glInitNames(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glInitNames);
}

static PyObject* py_glPopName(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glPopName);
}

static PyObject* py_glPushName(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glPushName);
}

static PyObject* py_glLoadName(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glLoadName);
}

static PyObject* py_glRenderMode(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum mode(PyTuple_GetItem(args, 0));
  GLint r = glRenderMode(mode);
  return PyInt_FromLong(r);
}

static PyObject* py_glSelectBuffer(PyObject *self, PyObject *args) {
  return WrapFunc2<Sizei, TypedPtr<Uint> >::Call(self, args, glSelectBuffer);
}

static PyObject* py_glFeedbackBuffer(PyObject *self, PyObject *args) {
  return WrapFunc3<Sizei, Enum, TypedPtr<Float> >::Call(self, args, glFeedbackBuffer);
}

static PyObject* py_glPassThrough(PyObject *self, PyObject *args) {
  return WrapFunc1<Float>::Call(self, args, glPassThrough);
}

static PyObject* py_glNewList(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Enum>::Call(self, args, glNewList);
}

static PyObject* py_glEndList(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glEndList);
}

static PyObject* py_glCallList(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glCallList);
}

static PyObject* py_glCallLists(PyObject *self, PyObject *args) {
  return WrapFunc3<Sizei, Enum, ConstPtr>::Call(self, args, glCallLists);
}

static PyObject* py_glListBase(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint>::Call(self, args, glListBase);
}

static PyObject* py_glGenLists(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei s(PyTuple_GetItem(args, 0));
  return PyInt_FromLong(glGenLists(s));
}

static PyObject* py_glIsList(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint list(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsList(list) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glDeleteLists(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Sizei>::Call(self, args, glDeleteLists);
}

static PyObject* py_glFlush(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glFlush);
}

static PyObject* py_glFinish(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glFinish);
}

static PyObject* py_glHint(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum>::Call(self, args, glHint);
}

static PyObject* py_glIsTexture(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint tex(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsTexture(tex) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glGetString(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum name(PyTuple_GetItem(args, 0));
  const GLubyte *s = glGetString(name);
  return PyString_FromString((const char*)s);
}

static PyObject* py_glPushAttrib(PyObject *self, PyObject *args) {
  return WrapFunc1<Bitfield>::Call(self, args, glPushAttrib);
}

static PyObject* py_glPushClientAttrib(PyObject *self, PyObject *args) {
  return WrapFunc1<Bitfield>::Call(self, args, glPushClientAttrib);
}

static PyObject* py_glPopAttrib(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glPopAttrib);
}

static PyObject* py_glPopClientAttrib(PyObject *self, PyObject *args) {
  return WrapFunc0::Call(self, args, glPopClientAttrib);
}

static PyObject* py_glGet(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 1);
  PyObject *rv = 0;
  Enum param(PyTuple_GetItem(args, 0));
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();
  dim = gl.getParamDim(PyGL::Booleanv, param);
  if (dim <= 0)
  {
    dim = gl.getParamDim(PyGL::Integerv, param);
    if (dim <= 0)
    {
      dim = gl.getParamDim(PyGL::Floatv, param);
      if (dim <= 0)
      {
        dim = gl.getParamDim(PyGL::Doublev, param);
        if (dim > 0)
        {
          Array1D<Double> values(dim);
          glGetDoublev(param, values);
          if (dim == 1)
          {
            rv = PyFloat_FromDouble(values[0]);
          }
          else
          {
            rv = values.toPy();
          }
        }
      }
      else
      {
        Array1D<Float> values(dim);
        glGetFloatv(param, values);
        if (dim == 1)
        {
          rv = PyFloat_FromDouble(values[0]);
        }
        else
        {
          rv = values.toPy();
        }
      }
    }
    else
    {
      Array1D<Int> values(dim);
      glGetIntegerv(param, values);
      if (dim == 1)
      {
        rv = PyInt_FromLong(values[0]);
      }
      else
      {
        rv = values.toPy();
      }
    }
  }
  else
  {
    Array1D<Boolean> values(dim);
    glGetBooleanv(param, values);
    if (dim == 1)
    {
      PyObject *rv = (values[0] == GL_TRUE ? Py_True : Py_False);
      Py_INCREF(rv);
      rv = rv;
    }
    else
    {
      rv = values.toPy();
    }
  }
  if (dim <= 0)
  {
    PyErr_SetString(PyExc_RuntimeError, "gl.Get: Invalid parameter name");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetClipPlane(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum plane(PyTuple_GetItem(args, 0));
  GLdouble eq[4];
  glGetClipPlane(plane, eq);
  return Array1D<Double>(eq, 4).toPy();
}

static PyObject* py_glGetLight(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 2);
  Enum light(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::Lightiv, param);
  if (dim <= 0)
  {
    dim = gl.getParamDim(PyGL::Lightfv, param);
    if (dim > 0)
    {
      Array1D<Float> values(dim);
      glGetLightfv(light, param, values);
      if (dim == 1)
      {
        rv = PyFloat_FromDouble(values[0]);
      }
      else
      {
        rv = values.toPy();
      }
    }
  }
  else
  {
    Array1D<Int> values(dim);
    glGetLightiv(light, param, values);
    if (dim == 1)
    {
      rv = PyInt_FromLong(values[0]);
    }
    else
    {
      rv = values.toPy();
    }
  }
  if (dim <= 0)
  {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetLight: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetMaterial(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 2);
  Enum face(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::Materialiv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(PyGL::Materialfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetMaterialfv(face, param, values);
      if (dim == 1) {
        rv = PyFloat_FromDouble(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetMaterialiv(face, param, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMaterial: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetTexEnv(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::TexEnviv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(PyGL::TexEnvfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexEnvfv(target, param, values);
      if (dim == 1) {
        rv = PyFloat_FromDouble(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexEnviv(target, param, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetTexEnv: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetTexGen(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 2);
  Enum coord(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::TexGeniv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(PyGL::TexGenfv, param);
    if (dim <= 0) {
      dim = gl.getParamDim(PyGL::TexGendv, param);
      if (dim > 0) {
        Array1D<Double> values(dim);
        glGetTexGendv(coord, param, values);
        if (dim == 1) {
          rv = PyFloat_FromDouble(values[0]);
        } else {
          rv = values.toPy();
        }
      }
    } else {
      Array1D<Float> values(dim);
      glGetTexGenfv(coord, param, values);
      if (dim == 1) {
        rv = PyFloat_FromDouble(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexGeniv(coord, param, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetTexGen: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetTexParameter(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::TexParameteriv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(PyGL::TexParameterfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexParameterfv(target, param, values);
      if (dim == 1) {
        rv = PyFloat_FromDouble(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexParameteriv(target, param, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetTexParameter: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetTexLevelParameter(PyObject *, PyObject *args)
{
  CHECK_ARG_COUNT(args, 3);
  Enum target(PyTuple_GetItem(args, 0));
  Int level(PyTuple_GetItem(args, 1));
  Enum param(PyTuple_GetItem(args, 2));
  PyObject *rv = 0;
  GLint dim = 0;
  PyGL &gl = PyGL::Instance();  
  dim = gl.getParamDim(PyGL::TexLevelParameteriv, param);
  if (dim <= 0) {
    dim = gl.getParamDim(PyGL::TexLevelParameterfv, param);
    if (dim > 0) {
      Array1D<Float> values(dim);
      glGetTexLevelParameterfv(target, level, param, values);
      if (dim == 1) {
        rv = PyFloat_FromDouble(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetTexLevelParameteriv(target, level, param, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim <= 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetTexLevelParameter: invalid parameter");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetPixelMapuiv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, TypedPtr<Uint> >::Call(self, args, glGetPixelMapuiv);
}
static PyObject* py_glGetPixelMapusv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, TypedPtr<Ushort> >::Call(self, args, glGetPixelMapusv);
}
static PyObject* py_glGetPixelMapfv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, TypedPtr<Float> >::Call(self, args, glGetPixelMapfv);
}

static PyObject* py_glGetMapiv(PyObject *, PyObject *args) {
  Py_ssize_t narg = PyTuple_Size(args);
  if (narg < 2) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: requires at least two arguments");
    return NULL;
  }
  Enum target(PyTuple_GetItem(args, 0));
  Enum query(PyTuple_GetItem(args, 1));
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: invalid target");
    return NULL;
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: invalid argument count");
        return NULL;
      }
      TypedPtr<Int> values(PyTuple_GetItem(args, 2));
      glGetMapiv(target, query, values);
      Py_RETURN_NONE;
    }
    case GL_ORDER: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: invalid argument count");
        return NULL;
      }
      GLint values[4];
      glGetMapiv(target, query, values);
      return Array1D<Int>(values, dim).toPy();
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: invalid argument count");
        return NULL;
      }
      GLint values[4];
      glGetMapiv(target, query, values);
      return Array1D<Int>(values, dim*2).toPy();
    }
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetMapiv: invalid query");
      return NULL;
  }
}
static PyObject* py_glGetMapfv(PyObject *, PyObject *args) {
  Py_ssize_t narg = PyTuple_Size(args);
  if (narg < 2) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: requires at least two arguments");
    return NULL;
  }
  Enum target(PyTuple_GetItem(args, 0));
  Enum query(PyTuple_GetItem(args, 1));
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: invalid target");
    return NULL;
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: invalid argument count");
        return NULL;
      }
      TypedPtr<Float> values(PyTuple_GetItem(args, 2));
      glGetMapfv(target, query, values);
      Py_RETURN_NONE;
    }
    case GL_ORDER: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: invalid argument count");
        return NULL;
      }
      GLfloat values[4];
      glGetMapfv(target, query, values);
      return Array1D<Float>(values, dim).toPy();
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: invalid argument count");
        return NULL;
      }
      GLfloat values[4];
      glGetMapfv(target, query, values);
      return Array1D<Float>(values, dim*2).toPy();
    }
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetMapfv: invalid query");
      return NULL;
  }
}
static PyObject* py_glGetMapdv(PyObject *, PyObject *args) {
  Py_ssize_t narg = PyTuple_Size(args);
  if (narg < 2) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: requires at least two arguments");
    return NULL;
  }
  Enum target(PyTuple_GetItem(args, 0));
  Enum query(PyTuple_GetItem(args, 1));
  GLint dim = 0;
  switch (target) {
    case GL_MAP1_COLOR_4:
    case GL_MAP1_INDEX:
    case GL_MAP1_NORMAL:
    case GL_MAP1_TEXTURE_COORD_1:
    case GL_MAP1_TEXTURE_COORD_2:
    case GL_MAP1_TEXTURE_COORD_3:
    case GL_MAP1_TEXTURE_COORD_4:
    case GL_MAP1_VERTEX_3:
    case GL_MAP1_VERTEX_4:
      dim = 1;
      break;
    case GL_MAP2_COLOR_4:
    case GL_MAP2_INDEX:
    case GL_MAP2_NORMAL:
    case GL_MAP2_TEXTURE_COORD_1:
    case GL_MAP2_TEXTURE_COORD_2:
    case GL_MAP2_TEXTURE_COORD_3:
    case GL_MAP2_TEXTURE_COORD_4:
    case GL_MAP2_VERTEX_3:
    case GL_MAP2_VERTEX_4:
      dim = 2;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: invalid target");
    return NULL;
  }
  switch (query) {
    case GL_COEFF: {
      if (narg != 3) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: invalid argument count");
        return NULL;
      }
      TypedPtr<Double> values(PyTuple_GetItem(args, 2));
      glGetMapdv(target, query, values);
      Py_RETURN_NONE;
    }
    case GL_ORDER: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: invalid argument count");
        return NULL;
      }
      GLdouble values[4];
      glGetMapdv(target, query, values);
      return Array1D<Double>(values, dim).toPy();
    }
    case GL_DOMAIN: {
      if (narg != 2) {
        PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: invalid argument count");
        return NULL;
      }
      GLdouble values[4];
      glGetMapdv(target, query, values);
      return Array1D<Double>(values, dim*2).toPy();
    }
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetMapdv: invalid query");
      return NULL;
  }
}

static PyObject* py_glGetTexImage(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Int, Enum, Enum, Ptr>::Call(self, args, glGetTexImage);
}

static PyObject* py_glGetPolygonStipple(PyObject *self, PyObject *args) {
  return WrapFunc1<TypedPtr<Ubyte> >::Call(self, args, glGetPolygonStipple);
}

static PyObject* py_glGetPointer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum param(PyTuple_GetItem(args, 0));
  GLvoid *ptr;
  glGetPointerv(param, &ptr);
  return PyCObject_FromVoidPtr(ptr, NULL);
}



// ---

void Register_GL_1_1_Constants(PyGL::ConstantMap &constants)
{
  constants["NO_ERROR"] = GL_NO_ERROR;
  constants["INVALID_ENUM"] = GL_INVALID_ENUM;
  constants["INVALID_VALUE"] = GL_INVALID_VALUE;
  constants["INVALID_OPERATION"] = GL_INVALID_OPERATION;
  constants["STACK_OVERFLOW"] = GL_STACK_OVERFLOW;
  constants["STACK_UNDERFLOW"] = GL_STACK_UNDERFLOW;
  constants["OUT_OF_MEMORY"] = GL_OUT_OF_MEMORY;
  constants["POINTS"] = GL_POINTS;
  constants["LINES"] = GL_LINES;
  constants["LINE_LOOP"] = GL_LINE_LOOP;
  constants["LINE_STRIP"] = GL_LINE_STRIP;
  constants["TRIANGLES"] = GL_TRIANGLES;
  constants["TRIANGLE_STRIP"] = GL_TRIANGLE_STRIP;
  constants["TRIANGLE_FAN"] = GL_TRIANGLE_FAN;
  constants["QUADS"] = GL_QUADS;
  constants["QUAD_STRIP"] = GL_QUAD_STRIP;
  constants["POLYGON"] = GL_POLYGON;
  constants["TRUE"] = GL_TRUE;
  constants["FALSE"] = GL_FALSE;
  constants["BYTE"] = GL_BYTE;
  constants["UNSIGNED_BYTE"] = GL_UNSIGNED_BYTE;
  constants["SHORT"] = GL_SHORT;
  constants["UNSIGNED_SHORT"] = GL_UNSIGNED_SHORT;
  constants["INT"] = GL_INT;
  constants["UNSIGNED_INT"] = GL_UNSIGNED_INT;
  constants["FLOAT"] = GL_FLOAT;
  constants["DOUBLE"] = GL_DOUBLE;
  constants["VERTEX_ARRAY"] = GL_VERTEX_ARRAY;
  constants["NORMAL_ARRAY"] = GL_NORMAL_ARRAY;
  constants["COLOR_ARRAY"] = GL_COLOR_ARRAY;
  constants["INDEX_ARRAY"] = GL_INDEX_ARRAY;
  constants["TEXTURE_COORD_ARRAY"] = GL_TEXTURE_COORD_ARRAY;
  constants["EDGE_FLAG_ARRAY"] = GL_EDGE_FLAG_ARRAY;
  constants["V2F"] = GL_V2F;
  constants["V3F"] = GL_V3F;
  constants["C4UB_V2F"] = GL_C4UB_V2F;
  constants["C4UB_V3F"] = GL_C4UB_V3F;
  constants["C3F_V3F"] = GL_C3F_V3F;
  constants["N3F_V3F"] = GL_N3F_V3F;
  constants["C4F_N3F_V3F"] = GL_C4F_N3F_V3F;
  constants["T2F_V3F"] = GL_T2F_V3F;
  constants["T4F_V4F"] = GL_T4F_V4F;
  constants["T2F_C4UB_V3F"] = GL_T2F_C4UB_V3F;
  constants["T2F_C3F_V3F"] = GL_T2F_C3F_V3F;
  constants["T2F_N3F_V3F"] = GL_T2F_N3F_V3F;
  constants["T2F_C4F_N3F_V3F"] = GL_T2F_C4F_N3F_V3F;
  constants["T4F_C4F_N3F_V4F"] = GL_T4F_C4F_N3F_V4F;
  constants["MODELVIEW"] = GL_MODELVIEW;
  constants["PROJECTION"] = GL_PROJECTION;
  constants["TEXTURE"] = GL_TEXTURE;
  constants["NORMALIZE"] = GL_NORMALIZE;
  constants["TEXTURE_GEN_MODE"] = GL_TEXTURE_GEN_MODE;
  constants["OBJECT_PLANE"] = GL_OBJECT_PLANE;
  constants["EYE_PLANE"] = GL_EYE_PLANE;
  constants["EYE_LINEAR"] = GL_EYE_LINEAR;
  constants["OBJECT_LINEAR"] = GL_OBJECT_LINEAR;
  constants["SPHERE_MAP"] = GL_SPHERE_MAP;
  constants["TEXTURE_GEN_S"] = GL_TEXTURE_GEN_S;
  constants["TEXTURE_GEN_T"] = GL_TEXTURE_GEN_T;
  constants["TEXTURE_GEN_R"] = GL_TEXTURE_GEN_R;
  constants["TEXTURE_GEN_Q"] = GL_TEXTURE_GEN_Q;
  constants["CLIP_PLANE0"] = GL_CLIP_PLANE0;
  constants["CLIP_PLANE1"] = GL_CLIP_PLANE1;
  constants["CLIP_PLANE2"] = GL_CLIP_PLANE2;
  constants["CLIP_PLANE3"] = GL_CLIP_PLANE3;
  constants["CLIP_PLANE4"] = GL_CLIP_PLANE4;
  constants["CLIP_PLANE5"] = GL_CLIP_PLANE5;
  constants["LIGHTING"] = GL_LIGHTING;
  constants["LIGHT0"] = GL_LIGHT0;
  constants["LIGHT1"] = GL_LIGHT1;
  constants["LIGHT2"] = GL_LIGHT2;
  constants["LIGHT3"] = GL_LIGHT3;
  constants["LIGHT4"] = GL_LIGHT4;
  constants["LIGHT5"] = GL_LIGHT5;
  constants["LIGHT6"] = GL_LIGHT6;
  constants["LIGHT7"] = GL_LIGHT7;
  constants["FRONT"] = GL_FRONT;
  constants["BACK"] = GL_BACK;
  constants["FRONT_AND_BACK"] = GL_FRONT_AND_BACK;
  constants["COLOR_MATERIAL"] = GL_COLOR_MATERIAL;
  constants["AMBIENT"] = GL_AMBIENT;
  constants["DIFFUSE"] = GL_DIFFUSE;
  constants["AMBIENT_AND_DIFFUSE"] = GL_AMBIENT_AND_DIFFUSE;
  constants["SPECULAR"] = GL_SPECULAR;
  constants["EMISSION"] = GL_EMISSION;
  constants["SHININESS"] = GL_SHININESS;
  constants["COLOR_INDEXES"] = GL_COLOR_INDEXES;
  constants["POSITION"] = GL_POSITION;
  constants["SPOT_DIRECTION"] = GL_SPOT_DIRECTION;
  constants["SPOT_EXPONENT"] = GL_SPOT_EXPONENT;
  constants["SPOT_CUTOFF"] = GL_SPOT_CUTOFF;
  constants["CONSTANT_ATTENUATION"] = GL_CONSTANT_ATTENUATION;
  constants["LINEAR_ATTENUATION"] = GL_LINEAR_ATTENUATION;
  constants["QUADRATIC_ATTENUATION"] = GL_QUADRATIC_ATTENUATION;
  constants["LIGHT_MODEL_LOCAL_VIEWER"] = GL_LIGHT_MODEL_LOCAL_VIEWER;
  constants["LIGHT_MODEL_TWO_SIDE"] = GL_LIGHT_MODEL_TWO_SIDE;
  constants["LIGHT_MODEL_AMBIENT"] = GL_LIGHT_MODEL_AMBIENT;
  constants["FLAT"] = GL_FLAT;
  constants["SMOOTH"] = GL_SMOOTH;
  constants["CW"] = GL_CW;
  constants["CCW"] = GL_CCW;
  constants["POINT_SMOOTH"] = GL_POINT_SMOOTH;
  constants["LINE_SMOOTH"] = GL_LINE_SMOOTH;
  constants["LINE_STIPPLE"] = GL_LINE_STIPPLE;
  constants["POLYGON_SMOOTH"] = GL_POLYGON_SMOOTH;
  constants["POLYGON_STIPPLE"] = GL_POLYGON_STIPPLE;
  constants["POLYGON_OFFSET_POINT"] = GL_POLYGON_OFFSET_POINT;
  constants["POLYGON_OFFSET_LINE"] = GL_POLYGON_OFFSET_LINE;
  constants["POLYGON_OFFSET_FILL"] = GL_POLYGON_OFFSET_FILL;
  constants["POINT"] = GL_POINT;
  constants["LINE"] = GL_LINE;
  constants["FILL"] = GL_FILL;
  constants["UNPACK_SWAP_BYTES"] = GL_UNPACK_SWAP_BYTES;
  constants["UNPACK_LSB_FIRST"] = GL_UNPACK_LSB_FIRST;
  constants["UNPACK_ROW_LENGTH"] = GL_UNPACK_ROW_LENGTH;
  constants["UNPACK_SKIP_ROWS"] = GL_UNPACK_SKIP_ROWS;
  constants["UNPACK_SKIP_PIXELS"] = GL_UNPACK_SKIP_PIXELS;
  constants["UNPACK_ALIGNMENT"] = GL_UNPACK_ALIGNMENT;
  constants["MAP_COLOR"] = GL_MAP_COLOR;
  constants["MAP_STENCIL"] = GL_MAP_STENCIL;
  constants["INDEX_SHIFT"] = GL_INDEX_SHIFT;
  constants["INDEX_OFFSET"] = GL_INDEX_OFFSET;
  constants["RED_SCALE"] = GL_RED_SCALE;
  constants["RED_BIAS"] = GL_RED_BIAS;
  constants["GREEN_SCALE"] = GL_GREEN_SCALE;
  constants["GREEN_BIAS"] = GL_GREEN_BIAS;
  constants["BLUE_SCALE"] = GL_BLUE_SCALE;
  constants["BLUE_BIAS"] = GL_BLUE_BIAS;
  constants["ALPHA_SCALE"] = GL_ALPHA_SCALE;
  constants["ALPHA_BIAS"] = GL_ALPHA_BIAS;
  constants["DEPTH_SCALE"] = GL_DEPTH_SCALE;
  constants["DEPTH_BIAS"] = GL_DEPTH_BIAS;
  constants["PIXEL_MAP_I_TO_I"] = GL_PIXEL_MAP_I_TO_I;
  constants["PIXEL_MAP_S_TO_S"] = GL_PIXEL_MAP_S_TO_S;
  constants["PIXEL_MAP_I_TO_R"] = GL_PIXEL_MAP_I_TO_R;
  constants["PIXEL_MAP_I_TO_G"] = GL_PIXEL_MAP_I_TO_G;
  constants["PIXEL_MAP_I_TO_B"] = GL_PIXEL_MAP_I_TO_B;
  constants["PIXEL_MAP_I_TO_A"] = GL_PIXEL_MAP_I_TO_A;
  constants["PIXEL_MAP_R_TO_R"] = GL_PIXEL_MAP_R_TO_R;
  constants["PIXEL_MAP_G_TO_G"] = GL_PIXEL_MAP_G_TO_G;
  constants["PIXEL_MAP_B_TO_B"] = GL_PIXEL_MAP_B_TO_B;
  constants["PIXEL_MAP_A_TO_A"] = GL_PIXEL_MAP_A_TO_A;
  constants["COLOR_INDEX"] = GL_COLOR_INDEX;
  constants["STENCIL_INDEX"] = GL_STENCIL_INDEX;
  constants["DEPTH_COMPONENT"] = GL_DEPTH_COMPONENT;
  constants["RED"] = GL_RED;
  constants["GREEN"] = GL_GREEN;
  constants["BLUE"] = GL_BLUE;
  constants["ALPHA"] = GL_ALPHA;
  constants["RGB"] = GL_RGB;
  constants["RGBA"] = GL_RGBA;
  constants["LUMINANCE"] = GL_LUMINANCE;
  constants["LUMINANCE_ALPHA"] = GL_LUMINANCE_ALPHA;
  constants["BITMAP"] = GL_BITMAP;
  constants["TEXTURE_2D"] = GL_TEXTURE_2D;
  constants["PROXY_TEXTURE_2D"] = GL_PROXY_TEXTURE_2D;
  constants["ACCUM"] = GL_ACCUM;
  constants["LOAD"] = GL_LOAD;
  constants["RETURN"] = GL_RETURN;
  constants["MULT"] = GL_MULT;
  constants["ADD"] = GL_ADD;
  constants["NEVER"] = GL_NEVER;
  constants["LESS"] = GL_LESS;
  constants["EQUAL"] = GL_EQUAL;
  constants["LEQUAL"] = GL_LEQUAL;
  constants["GREATER"] = GL_GREATER;
  constants["NOTEQUAL"] = GL_NOTEQUAL;
  constants["GEQUAL"] = GL_GEQUAL;
  constants["ALWAYS"] = GL_ALWAYS;
  constants["CURRENT_BIT"] = GL_CURRENT_BIT;
  constants["POINT_BIT"] = GL_POINT_BIT;
  constants["LINE_BIT"] = GL_LINE_BIT;
  constants["POLYGON_BIT"] = GL_POLYGON_BIT;
  constants["POLYGON_STIPPLE_BIT"] = GL_POLYGON_STIPPLE_BIT;
  constants["PIXEL_MODE_BIT"] = GL_PIXEL_MODE_BIT;
  constants["LIGHTING_BIT"] = GL_LIGHTING_BIT;
  constants["FOG_BIT"] = GL_FOG_BIT;
  constants["DEPTH_BUFFER_BIT"] = GL_DEPTH_BUFFER_BIT;
  constants["ACCUM_BUFFER_BIT"] = GL_ACCUM_BUFFER_BIT;
  constants["STENCIL_BUFFER_BIT"] = GL_STENCIL_BUFFER_BIT;
  constants["VIEWPORT_BIT"] = GL_VIEWPORT_BIT;
  constants["TRANSFORM_BIT"] = GL_TRANSFORM_BIT;
  constants["ENABLE_BIT"] = GL_ENABLE_BIT;
  constants["COLOR_BUFFER_BIT"] = GL_COLOR_BUFFER_BIT;
  constants["HINT_BIT"] = GL_HINT_BIT;
  constants["EVAL_BIT"] = GL_EVAL_BIT;
  constants["LIST_BIT"] = GL_LIST_BIT;
  constants["TEXTURE_BIT"] = GL_TEXTURE_BIT;
  constants["SCISSOR_BIT"] = GL_SCISSOR_BIT;
  constants["ALL_ATTRIB_BITS"] = GL_ALL_ATTRIB_BITS;
  constants["ZERO"] = GL_ZERO;
  constants["ONE"] = GL_ONE;
  constants["SRC_COLOR"] = GL_SRC_COLOR;
  constants["ONE_MINUS_SRC_COLOR"] = GL_ONE_MINUS_SRC_COLOR;
  constants["SRC_ALPHA"] = GL_SRC_ALPHA;
  constants["ONE_MINUS_SRC_ALPHA"] = GL_ONE_MINUS_SRC_ALPHA;
  constants["DST_ALPHA"] = GL_DST_ALPHA;
  constants["ONE_MINUS_DST_ALPHA"] = GL_ONE_MINUS_DST_ALPHA;
  constants["DST_COLOR"] = GL_DST_COLOR;
  constants["ONE_MINUS_DST_COLOR"] = GL_ONE_MINUS_DST_COLOR;
  constants["SRC_ALPHA_SATURATE"] = GL_SRC_ALPHA_SATURATE;
  constants["NONE"] = GL_NONE;
  constants["FRONT_LEFT"] = GL_FRONT_LEFT;
  constants["FRONT_RIGHT"] = GL_FRONT_RIGHT;
  constants["BACK_LEFT"] = GL_BACK_LEFT;
  constants["BACK_RIGHT"] = GL_BACK_RIGHT;
  constants["LEFT"] = GL_LEFT;
  constants["RIGHT"] = GL_RIGHT;
  constants["AUX0"] = GL_AUX0;
  constants["AUX1"] = GL_AUX1;
  constants["AUX2"] = GL_AUX2;
  constants["AUX3"] = GL_AUX3;
  constants["_2D"] = GL_2D;
  constants["_3D"] = GL_3D;
  constants["_3D_COLOR"] = GL_3D_COLOR;
  constants["_3D_COLOR_TEXTURE"] = GL_3D_COLOR_TEXTURE;
  constants["_4D_COLOR_TEXTURE"] = GL_4D_COLOR_TEXTURE;
  constants["PASS_THROUGH_TOKEN"] = GL_PASS_THROUGH_TOKEN;
  constants["POINT_TOKEN"] = GL_POINT_TOKEN;
  constants["LINE_TOKEN"] = GL_LINE_TOKEN;
  constants["POLYGON_TOKEN"] = GL_POLYGON_TOKEN;
  constants["BITMAP_TOKEN"] = GL_BITMAP_TOKEN;
  constants["DRAW_PIXEL_TOKEN"] = GL_DRAW_PIXEL_TOKEN;
  constants["COPY_PIXEL_TOKEN"] = GL_COPY_PIXEL_TOKEN;
  constants["LINE_RESET_TOKEN"] = GL_LINE_RESET_TOKEN;
  constants["EXP"] = GL_EXP;
  constants["EXP2"] = GL_EXP2;
  constants["COEFF"] = GL_COEFF;
  constants["ORDER"] = GL_ORDER;
  constants["DOMAIN"] = GL_DOMAIN;
  constants["CURRENT_COLOR"] = GL_CURRENT_COLOR;
  constants["CURRENT_INDEX"] = GL_CURRENT_INDEX;
  constants["CURRENT_NORMAL"] = GL_CURRENT_NORMAL;
  constants["CURRENT_TEXTURE_COORDS"] = GL_CURRENT_TEXTURE_COORDS;
  constants["CURRENT_RASTER_COLOR"] = GL_CURRENT_RASTER_COLOR;
  constants["CURRENT_RASTER_INDEX"] = GL_CURRENT_RASTER_INDEX;
  constants["CURRENT_RASTER_TEXTURE_COORDS"] = GL_CURRENT_RASTER_TEXTURE_COORDS;
  constants["CURRENT_RASTER_POSITION"] = GL_CURRENT_RASTER_POSITION;
  constants["CURRENT_RASTER_POSITION_VALID"] = GL_CURRENT_RASTER_POSITION_VALID;
  constants["CURRENT_RASTER_DISTANCE"] = GL_CURRENT_RASTER_DISTANCE;
  constants["POINT_SIZE"] = GL_POINT_SIZE;
  constants["POINT_SIZE_RANGE"] = GL_POINT_SIZE_RANGE;
  constants["POINT_SIZE_GRANULARITY"] = GL_POINT_SIZE_GRANULARITY;
  constants["LINE_WIDTH"] = GL_LINE_WIDTH;
  constants["LINE_WIDTH_RANGE"] = GL_LINE_WIDTH_RANGE;
  constants["LINE_WIDTH_GRANULARITY"] = GL_LINE_WIDTH_GRANULARITY;
  constants["LINE_STIPPLE_PATTERN"] = GL_LINE_STIPPLE_PATTERN;
  constants["LINE_STIPPLE_REPEAT"] = GL_LINE_STIPPLE_REPEAT;
  constants["LIST_MODE"] = GL_LIST_MODE;
  constants["MAX_LIST_NESTING"] = GL_MAX_LIST_NESTING;
  constants["LIST_BASE"] = GL_LIST_BASE;
  constants["LIST_INDEX"] = GL_LIST_INDEX;
  constants["POLYGON_MODE"] = GL_POLYGON_MODE;
  constants["EDGE_FLAG"] = GL_EDGE_FLAG;
  constants["CULL_FACE"] = GL_CULL_FACE;
  constants["CULL_FACE_MODE"] = GL_CULL_FACE_MODE;
  constants["FRONT_FACE"] = GL_FRONT_FACE;
  constants["SHADE_MODEL"] = GL_SHADE_MODEL;
  constants["COLOR_MATERIAL_FACE"] = GL_COLOR_MATERIAL_FACE;
  constants["COLOR_MATERIAL_PARAMETER"] = GL_COLOR_MATERIAL_PARAMETER;
  constants["FOG"] = GL_FOG;
  constants["FOG_INDEX"] = GL_FOG_INDEX;
  constants["FOG_DENSITY"] = GL_FOG_DENSITY;
  constants["FOG_START"] = GL_FOG_START;
  constants["FOG_END"] = GL_FOG_END;
  constants["FOG_MODE"] = GL_FOG_MODE;
  constants["FOG_COLOR"] = GL_FOG_COLOR;
  constants["DEPTH_RANGE"] = GL_DEPTH_RANGE;
  constants["DEPTH_TEST"] = GL_DEPTH_TEST;
  constants["DEPTH_WRITEMASK"] = GL_DEPTH_WRITEMASK;
  constants["DEPTH_CLEAR_VALUE"] = GL_DEPTH_CLEAR_VALUE;
  constants["DEPTH_FUNC"] = GL_DEPTH_FUNC;
  constants["ACCUM_CLEAR_VALUE"] = GL_ACCUM_CLEAR_VALUE;
  constants["STENCIL_TEST"] = GL_STENCIL_TEST;
  constants["STENCIL_CLEAR_VALUE"] = GL_STENCIL_CLEAR_VALUE;
  constants["STENCIL_FUNC"] = GL_STENCIL_FUNC;
  constants["STENCIL_VALUE_MASK"] = GL_STENCIL_VALUE_MASK;
  constants["STENCIL_FAIL"] = GL_STENCIL_FAIL;
  constants["STENCIL_PASS_DEPTH_FAIL"] = GL_STENCIL_PASS_DEPTH_FAIL;
  constants["STENCIL_PASS_DEPTH_PASS"] = GL_STENCIL_PASS_DEPTH_PASS;
  constants["STENCIL_REF"] = GL_STENCIL_REF;
  constants["STENCIL_WRITEMASK"] = GL_STENCIL_WRITEMASK;
  constants["MATRIX_MODE"] = GL_MATRIX_MODE;
  constants["VIEWPORT"] = GL_VIEWPORT;
  constants["MODELVIEW_STACK_DEPTH"] = GL_MODELVIEW_STACK_DEPTH;
  constants["PROJECTION_STACK_DEPTH"] = GL_PROJECTION_STACK_DEPTH;
  constants["TEXTURE_STACK_DEPTH"] = GL_TEXTURE_STACK_DEPTH;
  constants["MODELVIEW_MATRIX"] = GL_MODELVIEW_MATRIX;
  constants["PROJECTION_MATRIX"] = GL_PROJECTION_MATRIX;
  constants["TEXTURE_MATRIX"] = GL_TEXTURE_MATRIX;
  constants["ATTRIB_STACK_DEPTH"] = GL_ATTRIB_STACK_DEPTH;
  constants["CLIENT_ATTRIB_STACK_DEPTH"] = GL_CLIENT_ATTRIB_STACK_DEPTH;
  constants["ALPHA_TEST"] = GL_ALPHA_TEST;
  constants["ALPHA_TEST_FUNC"] = GL_ALPHA_TEST_FUNC;
  constants["ALPHA_TEST_REF"] = GL_ALPHA_TEST_REF;
  constants["DITHER"] = GL_DITHER;
  constants["BLEND_DST"] = GL_BLEND_DST;
  constants["BLEND_SRC"] = GL_BLEND_SRC;
  constants["BLEND"] = GL_BLEND;
  constants["LOGIC_OP_MODE"] = GL_LOGIC_OP_MODE;
  constants["INDEX_LOGIC_OP"] = GL_INDEX_LOGIC_OP;
  constants["COLOR_LOGIC_OP"] = GL_COLOR_LOGIC_OP;
  constants["AUX_BUFFERS"] = GL_AUX_BUFFERS;
  constants["DRAW_BUFFER"] = GL_DRAW_BUFFER;
  constants["READ_BUFFER"] = GL_READ_BUFFER;
  constants["SCISSOR_BOX"] = GL_SCISSOR_BOX;
  constants["SCISSOR_TEST"] = GL_SCISSOR_TEST;
  constants["INDEX_CLEAR_VALUE"] = GL_INDEX_CLEAR_VALUE;
  constants["INDEX_WRITEMASK"] = GL_INDEX_WRITEMASK;
  constants["COLOR_CLEAR_VALUE"] = GL_COLOR_CLEAR_VALUE;
  constants["COLOR_WRITEMASK"] = GL_COLOR_WRITEMASK;
  constants["INDEX_MODE"] = GL_INDEX_MODE;
  constants["RGBA_MODE"] = GL_RGBA_MODE;
  constants["DOUBLEBUFFER"] = GL_DOUBLEBUFFER;
  constants["STEREO"] = GL_STEREO;
  constants["RENDER_MODE"] = GL_RENDER_MODE;
  constants["PERSPECTIVE_CORRECTION_HINT"] = GL_PERSPECTIVE_CORRECTION_HINT;
  constants["POINT_SMOOTH_HINT"] = GL_POINT_SMOOTH_HINT;
  constants["LINE_SMOOTH_HINT"] = GL_LINE_SMOOTH_HINT;
  constants["POLYGON_SMOOTH_HINT"] = GL_POLYGON_SMOOTH_HINT;
  constants["FOG_HINT"] = GL_FOG_HINT;
  constants["PIXEL_MAP_I_TO_I_SIZE"] = GL_PIXEL_MAP_I_TO_I_SIZE;
  constants["PIXEL_MAP_S_TO_S_SIZE"] = GL_PIXEL_MAP_S_TO_S_SIZE;
  constants["PIXEL_MAP_I_TO_R_SIZE"] = GL_PIXEL_MAP_I_TO_R_SIZE;
  constants["PIXEL_MAP_I_TO_G_SIZE"] = GL_PIXEL_MAP_I_TO_G_SIZE;
  constants["PIXEL_MAP_I_TO_B_SIZE"] = GL_PIXEL_MAP_I_TO_B_SIZE;
  constants["PIXEL_MAP_I_TO_A_SIZE"] = GL_PIXEL_MAP_I_TO_A_SIZE;
  constants["PIXEL_MAP_R_TO_R_SIZE"] = GL_PIXEL_MAP_R_TO_R_SIZE;
  constants["PIXEL_MAP_G_TO_G_SIZE"] = GL_PIXEL_MAP_G_TO_G_SIZE;
  constants["PIXEL_MAP_B_TO_B_SIZE"] = GL_PIXEL_MAP_B_TO_B_SIZE;
  constants["PIXEL_MAP_A_TO_A_SIZE"] = GL_PIXEL_MAP_A_TO_A_SIZE;
  constants["PACK_SWAP_BYTES"] = GL_PACK_SWAP_BYTES;
  constants["PACK_LSB_FIRST"] = GL_PACK_LSB_FIRST;
  constants["PACK_ROW_LENGTH"] = GL_PACK_ROW_LENGTH;
  constants["PACK_SKIP_ROWS"] = GL_PACK_SKIP_ROWS;
  constants["PACK_SKIP_PIXELS"] = GL_PACK_SKIP_PIXELS;
  constants["PACK_ALIGNMENT"] = GL_PACK_ALIGNMENT;
  constants["ZOOM_X"] = GL_ZOOM_X;
  constants["ZOOM_Y"] = GL_ZOOM_Y;
  constants["MAX_EVAL_ORDER"] = GL_MAX_EVAL_ORDER;
  constants["MAX_LIGHTS"] = GL_MAX_LIGHTS;
  constants["MAX_CLIP_PLANES"] = GL_MAX_CLIP_PLANES;
  constants["MAX_TEXTURE_SIZE"] = GL_MAX_TEXTURE_SIZE;
  constants["MAX_PIXEL_MAP_TABLE"] = GL_MAX_PIXEL_MAP_TABLE;
  constants["MAX_ATTRIB_STACK_DEPTH"] = GL_MAX_ATTRIB_STACK_DEPTH;
  constants["MAX_MODELVIEW_STACK_DEPTH"] = GL_MAX_MODELVIEW_STACK_DEPTH;
  constants["MAX_NAME_STACK_DEPTH"] = GL_MAX_NAME_STACK_DEPTH;
  constants["MAX_PROJECTION_STACK_DEPTH"] = GL_MAX_PROJECTION_STACK_DEPTH;
  constants["MAX_TEXTURE_STACK_DEPTH"] = GL_MAX_TEXTURE_STACK_DEPTH;
  constants["MAX_VIEWPORT_DIMS"] = GL_MAX_VIEWPORT_DIMS;
  constants["MAX_CLIENT_ATTRIB_STACK_DEPTH"] = GL_MAX_CLIENT_ATTRIB_STACK_DEPTH;
  constants["SUBPIXEL_BITS"] = GL_SUBPIXEL_BITS;
  constants["INDEX_BITS"] = GL_INDEX_BITS;
  constants["RED_BITS"] = GL_RED_BITS;
  constants["GREEN_BITS"] = GL_GREEN_BITS;
  constants["BLUE_BITS"] = GL_BLUE_BITS;
  constants["ALPHA_BITS"] = GL_ALPHA_BITS;
  constants["DEPTH_BITS"] = GL_DEPTH_BITS;
  constants["STENCIL_BITS"] = GL_STENCIL_BITS;
  constants["ACCUM_RED_BITS"] = GL_ACCUM_RED_BITS;
  constants["ACCUM_GREEN_BITS"] = GL_ACCUM_GREEN_BITS;
  constants["ACCUM_BLUE_BITS"] = GL_ACCUM_BLUE_BITS;
  constants["ACCUM_ALPHA_BITS"] = GL_ACCUM_ALPHA_BITS;
  constants["NAME_STACK_DEPTH"] = GL_NAME_STACK_DEPTH;
  constants["AUTO_NORMAL"] = GL_AUTO_NORMAL;
  constants["MAP1_COLOR_4"] = GL_MAP1_COLOR_4;
  constants["MAP1_INDEX"] = GL_MAP1_INDEX;
  constants["MAP1_NORMAL"] = GL_MAP1_NORMAL;
  constants["MAP1_TEXTURE_COORD_1"] = GL_MAP1_TEXTURE_COORD_1;
  constants["MAP1_TEXTURE_COORD_2"] = GL_MAP1_TEXTURE_COORD_2;
  constants["MAP1_TEXTURE_COORD_3"] = GL_MAP1_TEXTURE_COORD_3;
  constants["MAP1_TEXTURE_COORD_4"] = GL_MAP1_TEXTURE_COORD_4;
  constants["MAP1_VERTEX_3"] = GL_MAP1_VERTEX_3;
  constants["MAP1_VERTEX_4"] = GL_MAP1_VERTEX_4;
  constants["MAP2_COLOR_4"] = GL_MAP2_COLOR_4;
  constants["MAP2_INDEX"] = GL_MAP2_INDEX;
  constants["MAP2_NORMAL"] = GL_MAP2_NORMAL;
  constants["MAP2_TEXTURE_COORD_1"] = GL_MAP2_TEXTURE_COORD_1;
  constants["MAP2_TEXTURE_COORD_2"] = GL_MAP2_TEXTURE_COORD_2;
  constants["MAP2_TEXTURE_COORD_3"] = GL_MAP2_TEXTURE_COORD_3;
  constants["MAP2_TEXTURE_COORD_4"] = GL_MAP2_TEXTURE_COORD_4;
  constants["MAP2_VERTEX_3"] = GL_MAP2_VERTEX_3;
  constants["MAP2_VERTEX_4"] = GL_MAP2_VERTEX_4;
  constants["MAP1_GRID_DOMAIN"] = GL_MAP1_GRID_DOMAIN;
  constants["MAP1_GRID_SEGMENTS"] = GL_MAP1_GRID_SEGMENTS;
  constants["MAP2_GRID_DOMAIN"] = GL_MAP2_GRID_DOMAIN;
  constants["MAP2_GRID_SEGMENTS"] = GL_MAP2_GRID_SEGMENTS;
  constants["TEXTURE_1D"] = GL_TEXTURE_1D;
  constants["FEEDBACK_BUFFER_POINTER"] = GL_FEEDBACK_BUFFER_POINTER;
  constants["FEEDBACK_BUFFER_SIZE"] = GL_FEEDBACK_BUFFER_SIZE;
  constants["FEEDBACK_BUFFER_TYPE"] = GL_FEEDBACK_BUFFER_TYPE;
  constants["SELECTION_BUFFER_POINTER"] = GL_SELECTION_BUFFER_POINTER;
  constants["SELECTION_BUFFER_SIZE"] = GL_SELECTION_BUFFER_SIZE;
  constants["TEXTURE_WIDTH"] = GL_TEXTURE_WIDTH;
  constants["TEXTURE_HEIGHT"] = GL_TEXTURE_HEIGHT;
  constants["TEXTURE_INTERNAL_FORMAT"] = GL_TEXTURE_INTERNAL_FORMAT;
  constants["TEXTURE_BORDER_COLOR"] = GL_TEXTURE_BORDER_COLOR;
  constants["TEXTURE_BORDER"] = GL_TEXTURE_BORDER;
  constants["DONT_CARE"] = GL_DONT_CARE;
  constants["FASTEST"] = GL_FASTEST;
  constants["NICEST"] = GL_NICEST;
  constants["COMPILE"] = GL_COMPILE;
  constants["COMPILE_AND_EXECUTE"] = GL_COMPILE_AND_EXECUTE;
  constants["CLEAR"] = GL_CLEAR;
  constants["AND"] = GL_AND;
  constants["AND_REVERSE"] = GL_AND_REVERSE;
  constants["COPY"] = GL_COPY;
  constants["AND_INVERTED"] = GL_AND_INVERTED;
  constants["NOOP"] = GL_NOOP;
  constants["XOR"] = GL_XOR;
  constants["OR"] = GL_OR;
  constants["NOR"] = GL_NOR;
  constants["EQUIV"] = GL_EQUIV;
  constants["INVERT"] = GL_INVERT;
  constants["OR_REVERSE"] = GL_OR_REVERSE;
  constants["COPY_INVERTED"] = GL_COPY_INVERTED;
  constants["OR_INVERTED"] = GL_OR_INVERTED;
  constants["NAND"] = GL_NAND;
  constants["SET"] = GL_SET;
  constants["COLOR"] = GL_COLOR;
  constants["DEPTH"] = GL_DEPTH;
  constants["STENCIL"] = GL_STENCIL;
  constants["RENDER"] = GL_RENDER;
  constants["FEEDBACK"] = GL_FEEDBACK;
  constants["SELECT"] = GL_SELECT;
  constants["KEEP"] = GL_KEEP;
  constants["REPLACE"] = GL_REPLACE;
  constants["INCR"] = GL_INCR;
  constants["DECR"] = GL_DECR;
  constants["VENDOR"] = GL_VENDOR;
  constants["RENDERER"] = GL_RENDERER;
  constants["VERSION"] = GL_VERSION;
  constants["EXTENSIONS"] = GL_EXTENSIONS;
  constants["S"] = GL_S;
  constants["T"] = GL_T;
  constants["R"] = GL_R;
  constants["Q"] = GL_Q;
  constants["MODULATE"] = GL_MODULATE;
  constants["DECAL"] = GL_DECAL;
  constants["TEXTURE_ENV_MODE"] = GL_TEXTURE_ENV_MODE;
  constants["TEXTURE_ENV_COLOR"] = GL_TEXTURE_ENV_COLOR;
  constants["TEXTURE_ENV"] = GL_TEXTURE_ENV;
  constants["NEAREST"] = GL_NEAREST;
  constants["LINEAR"] = GL_LINEAR;
  constants["NEAREST_MIPMAP_NEAREST"] = GL_NEAREST_MIPMAP_NEAREST;
  constants["LINEAR_MIPMAP_NEAREST"] = GL_LINEAR_MIPMAP_NEAREST;
  constants["NEAREST_MIPMAP_LINEAR"] = GL_NEAREST_MIPMAP_LINEAR;
  constants["LINEAR_MIPMAP_LINEAR"] = GL_LINEAR_MIPMAP_LINEAR;
  constants["TEXTURE_MAG_FILTER"] = GL_TEXTURE_MAG_FILTER;
  constants["TEXTURE_MIN_FILTER"] = GL_TEXTURE_MIN_FILTER;
  constants["TEXTURE_WRAP_S"] = GL_TEXTURE_WRAP_S;
  constants["TEXTURE_WRAP_T"] = GL_TEXTURE_WRAP_T;
  constants["CLAMP"] = GL_CLAMP;
  constants["REPEAT"] = GL_REPEAT;
  constants["CLIENT_PIXEL_STORE_BIT"] = GL_CLIENT_PIXEL_STORE_BIT;
  constants["CLIENT_VERTEX_ARRAY_BIT"] = GL_CLIENT_VERTEX_ARRAY_BIT;
  constants["CLIENT_ALL_ATTRIB_BITS"] = GL_CLIENT_ALL_ATTRIB_BITS;
  constants["POLYGON_OFFSET_FACTOR"] = GL_POLYGON_OFFSET_FACTOR;
  constants["POLYGON_OFFSET_UNITS"] = GL_POLYGON_OFFSET_UNITS;
  constants["ALPHA4"] = GL_ALPHA4;
  constants["ALPHA8"] = GL_ALPHA8;
  constants["ALPHA12"] = GL_ALPHA12;
  constants["ALPHA16"] = GL_ALPHA16;
  constants["LUMINANCE4"] = GL_LUMINANCE4;
  constants["LUMINANCE8"] = GL_LUMINANCE8;
  constants["LUMINANCE12"] = GL_LUMINANCE12;
  constants["LUMINANCE16"] = GL_LUMINANCE16;
  constants["LUMINANCE4_ALPHA4"] = GL_LUMINANCE4_ALPHA4;
  constants["LUMINANCE6_ALPHA2"] = GL_LUMINANCE6_ALPHA2;
  constants["LUMINANCE8_ALPHA8"] = GL_LUMINANCE8_ALPHA8;
  constants["LUMINANCE12_ALPHA4"] = GL_LUMINANCE12_ALPHA4;
  constants["LUMINANCE12_ALPHA12"] = GL_LUMINANCE12_ALPHA12;
  constants["LUMINANCE16_ALPHA16"] = GL_LUMINANCE16_ALPHA16;
  constants["INTENSITY"] = GL_INTENSITY;
  constants["INTENSITY4"] = GL_INTENSITY4;
  constants["INTENSITY8"] = GL_INTENSITY8;
  constants["INTENSITY12"] = GL_INTENSITY12;
  constants["INTENSITY16"] = GL_INTENSITY16;
  constants["R3_G3_B2"] = GL_R3_G3_B2;
  constants["RGB4"] = GL_RGB4;
  constants["RGB5"] = GL_RGB5;
  constants["RGB8"] = GL_RGB8;
  constants["RGB10"] = GL_RGB10;
  constants["RGB12"] = GL_RGB12;
  constants["RGB16"] = GL_RGB16;
  constants["RGBA2"] = GL_RGBA2;
  constants["RGBA4"] = GL_RGBA4;
  constants["RGB5_A1"] = GL_RGB5_A1;
  constants["RGBA8"] = GL_RGBA8;
  constants["RGB10_A2"] = GL_RGB10_A2;
  constants["RGBA12"] = GL_RGBA12;
  constants["RGBA16"] = GL_RGBA16;
  constants["TEXTURE_RED_SIZE"] = GL_TEXTURE_RED_SIZE;
  constants["TEXTURE_GREEN_SIZE"] = GL_TEXTURE_GREEN_SIZE;
  constants["TEXTURE_BLUE_SIZE"] = GL_TEXTURE_BLUE_SIZE;
  constants["TEXTURE_ALPHA_SIZE"] = GL_TEXTURE_ALPHA_SIZE;
  constants["TEXTURE_LUMINANCE_SIZE"] = GL_TEXTURE_LUMINANCE_SIZE;
  constants["TEXTURE_INTENSITY_SIZE"] = GL_TEXTURE_INTENSITY_SIZE;
  constants["PROXY_TEXTURE_1D"] = GL_PROXY_TEXTURE_1D;
  constants["TEXTURE_PRIORITY"] = GL_TEXTURE_PRIORITY;
  constants["TEXTURE_RESIDENT"] = GL_TEXTURE_RESIDENT;
  constants["TEXTURE_BINDING_1D"] = GL_TEXTURE_BINDING_1D;
  constants["TEXTURE_BINDING_2D"] = GL_TEXTURE_BINDING_2D;
  constants["VERTEX_ARRAY_SIZE"] = GL_VERTEX_ARRAY_SIZE;
  constants["VERTEX_ARRAY_TYPE"] = GL_VERTEX_ARRAY_TYPE;
  constants["VERTEX_ARRAY_STRIDE"] = GL_VERTEX_ARRAY_STRIDE;
  constants["NORMAL_ARRAY_TYPE"] = GL_NORMAL_ARRAY_TYPE;
  constants["NORMAL_ARRAY_STRIDE"] = GL_NORMAL_ARRAY_STRIDE;
  constants["COLOR_ARRAY_SIZE"] = GL_COLOR_ARRAY_SIZE;
  constants["COLOR_ARRAY_TYPE"] = GL_COLOR_ARRAY_TYPE;
  constants["COLOR_ARRAY_STRIDE"] = GL_COLOR_ARRAY_STRIDE;
  constants["INDEX_ARRAY_TYPE"] = GL_INDEX_ARRAY_TYPE;
  constants["INDEX_ARRAY_STRIDE"] = GL_INDEX_ARRAY_STRIDE;
  constants["TEXTURE_COORD_ARRAY_SIZE"] = GL_TEXTURE_COORD_ARRAY_SIZE;
  constants["TEXTURE_COORD_ARRAY_TYPE"] = GL_TEXTURE_COORD_ARRAY_TYPE;
  constants["TEXTURE_COORD_ARRAY_STRIDE"] = GL_TEXTURE_COORD_ARRAY_STRIDE;
  constants["EDGE_FLAG_ARRAY_STRIDE"] = GL_EDGE_FLAG_ARRAY_STRIDE;
  constants["VERTEX_ARRAY_POINTER"] = GL_VERTEX_ARRAY_POINTER;
  constants["NORMAL_ARRAY_POINTER"] = GL_NORMAL_ARRAY_POINTER;
  constants["COLOR_ARRAY_POINTER"] = GL_COLOR_ARRAY_POINTER;
  constants["INDEX_ARRAY_POINTER"] = GL_INDEX_ARRAY_POINTER;
  constants["TEXTURE_COORD_ARRAY_POINTER"] = GL_TEXTURE_COORD_ARRAY_POINTER;
  constants["EDGE_FLAG_ARRAY_POINTER"] = GL_EDGE_FLAG_ARRAY_POINTER;
  constants["LOGIC_OP"] = GL_LOGIC_OP;
  constants["TEXTURE_COMPONENTS"] = GL_TEXTURE_COMPONENTS;

  //constants["COLOR_INDEX1_EXT"] = GL_COLOR_INDEX1_EXT;
  //constants["COLOR_INDEX2_EXT"] = GL_COLOR_INDEX2_EXT;
  //constants["COLOR_INDEX4_EXT"] = GL_COLOR_INDEX4_EXT;
  //constants["COLOR_INDEX8_EXT"] = GL_COLOR_INDEX8_EXT;
  //constants["COLOR_INDEX12_EXT"] = GL_COLOR_INDEX12_EXT;
  //constants["COLOR_INDEX16_EXT"] = GL_COLOR_INDEX16_EXT;
  //constants["_2_BYTES"] = GL_2_BYTES;
  //constants["_3_BYTES"] = GL_3_BYTES;
  //constants["_4_BYTES"] = GL_4_BYTES;

  PyGL &gl = PyGL::Instance();

  gl.addParamDim(PyGL::Booleanv, GL_COLOR_WRITEMASK, 4);
  gl.addParamDim(PyGL::Booleanv, GL_CURRENT_RASTER_POSITION_VALID, 1);
  gl.addParamDim(PyGL::Booleanv, GL_EDGE_FLAG, 1);
  gl.addParamDim(PyGL::Booleanv, GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
  gl.addParamDim(PyGL::Booleanv, GL_LIGHT_MODEL_TWO_SIDE, 1);
  gl.addParamDim(PyGL::Booleanv, GL_DEPTH_WRITEMASK, 1);
  gl.addParamDim(PyGL::Booleanv, GL_UNPACK_SWAP_BYTES, 1);
  gl.addParamDim(PyGL::Booleanv, GL_UNPACK_LSB_FIRST, 1);
  gl.addParamDim(PyGL::Booleanv, GL_PACK_SWAP_BYTES, 1);
  gl.addParamDim(PyGL::Booleanv, GL_PACK_LSB_FIRST, 1);
  gl.addParamDim(PyGL::Booleanv, GL_MAP_COLOR, 1);
  gl.addParamDim(PyGL::Booleanv, GL_MAP_STENCIL, 1);
  gl.addParamDim(PyGL::Booleanv, GL_RGBA_MODE, 1);
  gl.addParamDim(PyGL::Booleanv, GL_INDEX_MODE, 1);
  gl.addParamDim(PyGL::Booleanv, GL_DOUBLEBUFFER, 1);
  gl.addParamDim(PyGL::Booleanv, GL_STEREO, 1);
  gl.addParamDim(PyGL::Integerv, GL_CURRENT_COLOR, 4);
  gl.addParamDim(PyGL::Integerv, GL_CURRENT_RASTER_COLOR, 4);
  gl.addParamDim(PyGL::Integerv, GL_VIEWPORT, 4);
  gl.addParamDim(PyGL::Integerv, GL_SCISSOR_BOX, 4);
  gl.addParamDim(PyGL::Integerv, GL_MAX_VIEWPORT_DIMS, 2);
  gl.addParamDim(PyGL::Integerv, GL_CURRENT_INDEX, 1);
  gl.addParamDim(PyGL::Integerv, GL_CURRENT_RASTER_INDEX, 1);
  gl.addParamDim(PyGL::Integerv, GL_VERTEX_ARRAY_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_VERTEX_ARRAY_TYPE, 1);
  gl.addParamDim(PyGL::Integerv, GL_VERTEX_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_NORMAL_ARRAY_TYPE, 1);
  gl.addParamDim(PyGL::Integerv, GL_NORMAL_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_COLOR_ARRAY_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_COLOR_ARRAY_TYPE, 1);
  gl.addParamDim(PyGL::Integerv, GL_COLOR_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_ARRAY_TYPE, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COORD_ARRAY_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COORD_ARRAY_TYPE, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COORD_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_EDGE_FLAG_ARRAY_STRIDE, 1);
  gl.addParamDim(PyGL::Integerv, GL_MODELVIEW_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_PROJECTION_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_MATRIX_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_FOG_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_SHADE_MODEL, 1);
  gl.addParamDim(PyGL::Integerv, GL_COLOR_MATERIAL_PARAMETER, 1);
  gl.addParamDim(PyGL::Integerv, GL_COLOR_MATERIAL_FACE, 1);
  gl.addParamDim(PyGL::Integerv, GL_LINE_STIPPLE_PATTERN, 1);
  gl.addParamDim(PyGL::Integerv, GL_LINE_STIPPLE_REPEAT, 1);
  gl.addParamDim(PyGL::Integerv, GL_CULL_FACE_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_FRONT_FACE, 1);
  gl.addParamDim(PyGL::Integerv, GL_POLYGON_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_BINDING_1D, 1);
  gl.addParamDim(PyGL::Integerv, GL_TEXTURE_BINDING_2D, 1);
  gl.addParamDim(PyGL::Integerv, GL_ALPHA_TEST_FUNC, 1);
  gl.addParamDim(PyGL::Integerv, GL_ALPHA_TEST_REF, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_FUNC, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_VALUE_MASK, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_REF, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_FAIL, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_PASS_DEPTH_FAIL, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_PASS_DEPTH_PASS, 1);
  gl.addParamDim(PyGL::Integerv, GL_DEPTH_FUNC, 1);
  gl.addParamDim(PyGL::Integerv, GL_BLEND_SRC, 1);
  gl.addParamDim(PyGL::Integerv, GL_BLEND_DST, 1);
  gl.addParamDim(PyGL::Integerv, GL_LOGIC_OP_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_WRITEMASK, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_WRITEMASK, 1);
  gl.addParamDim(PyGL::Integerv, GL_DEPTH_CLEAR_VALUE, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_CLEAR_VALUE, 1);
  gl.addParamDim(PyGL::Integerv, GL_UNPACK_ROW_LENGTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_UNPACK_SKIP_ROWS, 1);
  gl.addParamDim(PyGL::Integerv, GL_UNPACK_SKIP_PIXELS, 1);
  gl.addParamDim(PyGL::Integerv, GL_UNPACK_ALIGNMENT, 1);
  gl.addParamDim(PyGL::Integerv, GL_PACK_ROW_LENGTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_PACK_SKIP_ROWS, 1);
  gl.addParamDim(PyGL::Integerv, GL_PACK_SKIP_PIXELS, 1);
  gl.addParamDim(PyGL::Integerv, GL_PACK_ALIGNMENT, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_SHIFT, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_OFFSET, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_A_TO_A_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_B_TO_B_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_G_TO_G_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_I_TO_A_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_I_TO_B_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_I_TO_G_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_I_TO_I_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_I_TO_R_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_R_TO_R_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_PIXEL_MAP_S_TO_S_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_READ_BUFFER, 1);
  gl.addParamDim(PyGL::Integerv, GL_PERSPECTIVE_CORRECTION_HINT, 1);
  gl.addParamDim(PyGL::Integerv, GL_POINT_SMOOTH_HINT, 1);
  gl.addParamDim(PyGL::Integerv, GL_LINE_SMOOTH_HINT, 1);
  gl.addParamDim(PyGL::Integerv, GL_FOG_HINT, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_LIGHTS, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_CLIP_PLANES, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_MODELVIEW_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_PROJECTION_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_SUBPIXEL_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_PIXEL_MAP_TABLE, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_NAME_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_LIST_NESTING, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_EVAL_ORDER, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_MAX_CLIENT_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_AUX_BUFFERS, 1);
  gl.addParamDim(PyGL::Integerv, GL_RED_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_GREEN_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_BLUE_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_ALPHA_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_INDEX_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_DEPTH_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_STENCIL_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_ACCUM_RED_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_ACCUM_GREEN_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_ACCUM_BLUE_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_ACCUM_ALPHA_BITS, 1);
  gl.addParamDim(PyGL::Integerv, GL_LIST_BASE, 1);
  gl.addParamDim(PyGL::Integerv, GL_LIST_INDEX, 1);
  gl.addParamDim(PyGL::Integerv, GL_LIST_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_CLIENT_ATTRIB_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_NAME_STACK_DEPTH, 1);
  gl.addParamDim(PyGL::Integerv, GL_RENDER_MODE, 1);
  gl.addParamDim(PyGL::Integerv, GL_SELECTION_BUFFER_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_FEEDBACK_BUFFER_SIZE, 1);
  gl.addParamDim(PyGL::Integerv, GL_FEEDBACK_BUFFER_TYPE, 1);
  gl.addParamDim(PyGL::Floatv, GL_MODELVIEW_MATRIX, 16);
  gl.addParamDim(PyGL::Floatv, GL_PROJECTION_MATRIX, 16);
  gl.addParamDim(PyGL::Floatv, GL_TEXTURE_MATRIX, 16);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_COLOR, 4);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_TEXTURE_COORDS, 4);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_POSITION, 4);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_COLOR, 4);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_TEXTURE_COORDS, 4);
  gl.addParamDim(PyGL::Floatv, GL_FOG_COLOR, 4);
  gl.addParamDim(PyGL::Floatv, GL_LIGHT_MODEL_AMBIENT, 4);
  gl.addParamDim(PyGL::Floatv, GL_COLOR_CLEAR_VALUE, 4);
  gl.addParamDim(PyGL::Floatv, GL_ACCUM_CLEAR_VALUE, 4);
  gl.addParamDim(PyGL::Floatv, GL_MAP2_GRID_DOMAIN, 4);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_NORMAL, 3);
  gl.addParamDim(PyGL::Floatv, GL_DEPTH_RANGE, 2);
  gl.addParamDim(PyGL::Floatv, GL_MAP1_GRID_DOMAIN, 2);
  gl.addParamDim(PyGL::Floatv, GL_MAP2_GRID_SEGMENTS, 2);
  gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_RANGE, 2);
  gl.addParamDim(PyGL::Floatv, GL_LINE_WIDTH_RANGE, 2);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_INDEX, 1);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_DISTANCE, 1);
  gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_INDEX, 1);
  gl.addParamDim(PyGL::Floatv, GL_FOG_INDEX, 1);
  gl.addParamDim(PyGL::Floatv, GL_FOG_DENSITY, 1);
  gl.addParamDim(PyGL::Floatv, GL_FOG_START, 1);
  gl.addParamDim(PyGL::Floatv, GL_FOG_END, 1);
  gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE, 1);
  gl.addParamDim(PyGL::Floatv, GL_LINE_WIDTH, 1);
  gl.addParamDim(PyGL::Floatv, GL_POLYGON_OFFSET_FACTOR, 1);
  gl.addParamDim(PyGL::Floatv, GL_POLYGON_OFFSET_UNITS, 1);
  gl.addParamDim(PyGL::Floatv, GL_INDEX_CLEAR_VALUE, 1);
  gl.addParamDim(PyGL::Floatv, GL_RED_SCALE, 1);
  gl.addParamDim(PyGL::Floatv, GL_GREEN_SCALE, 1);
  gl.addParamDim(PyGL::Floatv, GL_BLUE_SCALE, 1);
  gl.addParamDim(PyGL::Floatv, GL_ALPHA_SCALE, 1);
  gl.addParamDim(PyGL::Floatv, GL_DEPTH_SCALE, 1);
  gl.addParamDim(PyGL::Floatv, GL_RED_BIAS, 1);
  gl.addParamDim(PyGL::Floatv, GL_GREEN_BIAS, 1);
  gl.addParamDim(PyGL::Floatv, GL_BLUE_BIAS, 1);
  gl.addParamDim(PyGL::Floatv, GL_ALPHA_BIAS, 1);
  gl.addParamDim(PyGL::Floatv, GL_DEPTH_BIAS, 1);
  gl.addParamDim(PyGL::Floatv, GL_ZOOM_X, 1);
  gl.addParamDim(PyGL::Floatv, GL_ZOOM_Y, 1);
  gl.addParamDim(PyGL::Floatv, GL_MAP1_GRID_SEGMENTS, 1);
  gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_GRANULARITY, 1);
  gl.addParamDim(PyGL::Floatv, GL_LINE_WIDTH_GRANULARITY, 1);
  gl.addParamDim(PyGL::Lightfv, GL_AMBIENT, 4);
  gl.addParamDim(PyGL::Lightfv, GL_DIFFUSE, 4);
  gl.addParamDim(PyGL::Lightfv, GL_SPECULAR, 4);
  gl.addParamDim(PyGL::Lightfv, GL_POSITION, 4);
  gl.addParamDim(PyGL::Lightfv, GL_SPOT_DIRECTION, 3);
  gl.addParamDim(PyGL::Lightfv, GL_SPOT_CUTOFF, 1);
  gl.addParamDim(PyGL::Lightfv, GL_CONSTANT_ATTENUATION, 1);
  gl.addParamDim(PyGL::Lightfv, GL_LINEAR_ATTENUATION, 1);
  gl.addParamDim(PyGL::Lightfv, GL_QUADRATIC_ATTENUATION, 1);
  gl.addParamDim(PyGL::Materialfv, GL_AMBIENT, 4);
  gl.addParamDim(PyGL::Materialfv, GL_DIFFUSE, 4);
  gl.addParamDim(PyGL::Materialfv, GL_SPECULAR, 4);
  gl.addParamDim(PyGL::Materialfv, GL_EMISSION, 4);
  gl.addParamDim(PyGL::Materialfv, GL_COLOR_INDEXES, 3);
  gl.addParamDim(PyGL::Materialfv, GL_SHININESS, 1);
  gl.addParamDim(PyGL::TexEnviv, GL_TEXTURE_ENV_MODE, 1);
  gl.addParamDim(PyGL::TexEnvfv, GL_TEXTURE_ENV_COLOR, 4);
  gl.addParamDim(PyGL::TexGeniv, GL_TEXTURE_GEN_MODE, 1);
  gl.addParamDim(PyGL::TexGenfv, GL_OBJECT_PLANE, 4);
  gl.addParamDim(PyGL::TexGenfv, GL_EYE_PLANE, 4);
  gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_MIN_FILTER, 1);
  gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_MAG_FILTER, 1);
  gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_WRAP_S, 1);
  gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_WRAP_T, 1);
  gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_RESIDENT, 1);
  gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_PRIORITY, 1);
  gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_BORDER_COLOR, 4);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_WIDTH, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_HEIGHT, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_BORDER, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_INTERNAL_FORMAT, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_RED_SIZE, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_GREEN_SIZE, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_BLUE_SIZE, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_ALPHA_SIZE, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_LUMINANCE_SIZE, 1);
  gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_INTENSITY_SIZE, 1);
}

void Register_GL_1_1_Functions(PyGL::FunctionTable &functions)
{
  PyGL::Instance().setVersion(1.1);

  REGISTER_GL_FUNC(functions, GetError);
  REGISTER_GL_FUNC(functions, Begin);
  REGISTER_GL_FUNC(functions, End);
  REGISTER_GL_FUNC(functions, EdgeFlag);
  REGISTER_GL_FUNC(functions, Vertex2s);
  REGISTER_GL_FUNC(functions, Vertex2i);
  REGISTER_GL_FUNC(functions, Vertex2f);
  REGISTER_GL_FUNC(functions, Vertex2d);
  REGISTER_GL_FUNC(functions, Vertex3s);
  REGISTER_GL_FUNC(functions, Vertex3i);
  REGISTER_GL_FUNC(functions, Vertex3f);
  REGISTER_GL_FUNC(functions, Vertex3d);
  REGISTER_GL_FUNC(functions, Vertex4s);
  REGISTER_GL_FUNC(functions, Vertex4i);
  REGISTER_GL_FUNC(functions, Vertex4f);
  REGISTER_GL_FUNC(functions, Vertex4d);
  REGISTER_GL_FUNC(functions, Vertex2sv);
  REGISTER_GL_FUNC(functions, Vertex2iv);
  REGISTER_GL_FUNC(functions, Vertex2fv);
  REGISTER_GL_FUNC(functions, Vertex2dv);
  REGISTER_GL_FUNC(functions, Vertex3sv);
  REGISTER_GL_FUNC(functions, Vertex3iv);
  REGISTER_GL_FUNC(functions, Vertex3fv);
  REGISTER_GL_FUNC(functions, Vertex3dv);
  REGISTER_GL_FUNC(functions, Vertex4sv);
  REGISTER_GL_FUNC(functions, Vertex4iv);
  REGISTER_GL_FUNC(functions, Vertex4fv);
  REGISTER_GL_FUNC(functions, Vertex4dv);
  REGISTER_GL_FUNC(functions, TexCoord1s);
  REGISTER_GL_FUNC(functions, TexCoord1i);
  REGISTER_GL_FUNC(functions, TexCoord1f);
  REGISTER_GL_FUNC(functions, TexCoord1d);
  REGISTER_GL_FUNC(functions, TexCoord2s);
  REGISTER_GL_FUNC(functions, TexCoord2i);
  REGISTER_GL_FUNC(functions, TexCoord2f);
  REGISTER_GL_FUNC(functions, TexCoord2d);
  REGISTER_GL_FUNC(functions, TexCoord3s);
  REGISTER_GL_FUNC(functions, TexCoord3i);
  REGISTER_GL_FUNC(functions, TexCoord3f);
  REGISTER_GL_FUNC(functions, TexCoord3d);
  REGISTER_GL_FUNC(functions, TexCoord4s);
  REGISTER_GL_FUNC(functions, TexCoord4i);
  REGISTER_GL_FUNC(functions, TexCoord4f);
  REGISTER_GL_FUNC(functions, TexCoord4d);
  REGISTER_GL_FUNC(functions, TexCoord2sv);
  REGISTER_GL_FUNC(functions, TexCoord2iv);
  REGISTER_GL_FUNC(functions, TexCoord2fv);
  REGISTER_GL_FUNC(functions, TexCoord2dv);
  REGISTER_GL_FUNC(functions, TexCoord3sv);
  REGISTER_GL_FUNC(functions, TexCoord3iv);
  REGISTER_GL_FUNC(functions, TexCoord3fv);
  REGISTER_GL_FUNC(functions, TexCoord3dv);
  REGISTER_GL_FUNC(functions, TexCoord4sv);
  REGISTER_GL_FUNC(functions, TexCoord4iv);
  REGISTER_GL_FUNC(functions, TexCoord4fv);
  REGISTER_GL_FUNC(functions, TexCoord4dv);
  REGISTER_GL_FUNC(functions, Normal3b);
  REGISTER_GL_FUNC(functions, Normal3s);
  REGISTER_GL_FUNC(functions, Normal3i);
  REGISTER_GL_FUNC(functions, Normal3f);
  REGISTER_GL_FUNC(functions, Normal3d);
  REGISTER_GL_FUNC(functions, Normal3bv);
  REGISTER_GL_FUNC(functions, Normal3sv);
  REGISTER_GL_FUNC(functions, Normal3iv);
  REGISTER_GL_FUNC(functions, Normal3fv);
  REGISTER_GL_FUNC(functions, Normal3dv);
  REGISTER_GL_FUNC(functions, Color3b);
  REGISTER_GL_FUNC(functions, Color3ub);
  REGISTER_GL_FUNC(functions, Color3s);
  REGISTER_GL_FUNC(functions, Color3us);
  REGISTER_GL_FUNC(functions, Color3i);
  REGISTER_GL_FUNC(functions, Color3ui);
  REGISTER_GL_FUNC(functions, Color3f);
  REGISTER_GL_FUNC(functions, Color3d);
  REGISTER_GL_FUNC(functions, Color4b);
  REGISTER_GL_FUNC(functions, Color4ub);
  REGISTER_GL_FUNC(functions, Color4s);
  REGISTER_GL_FUNC(functions, Color4us);
  REGISTER_GL_FUNC(functions, Color4i);
  REGISTER_GL_FUNC(functions, Color4ui);
  REGISTER_GL_FUNC(functions, Color4f);
  REGISTER_GL_FUNC(functions, Color4d);
  REGISTER_GL_FUNC(functions, Color3bv);
  REGISTER_GL_FUNC(functions, Color3ubv);
  REGISTER_GL_FUNC(functions, Color3sv);
  REGISTER_GL_FUNC(functions, Color3usv);
  REGISTER_GL_FUNC(functions, Color3iv);
  REGISTER_GL_FUNC(functions, Color3uiv);
  REGISTER_GL_FUNC(functions, Color3fv);
  REGISTER_GL_FUNC(functions, Color3dv);
  REGISTER_GL_FUNC(functions, Color4bv);
  REGISTER_GL_FUNC(functions, Color4ubv);
  REGISTER_GL_FUNC(functions, Color4sv);
  REGISTER_GL_FUNC(functions, Color4usv);
  REGISTER_GL_FUNC(functions, Color4iv);
  REGISTER_GL_FUNC(functions, Color4uiv);
  REGISTER_GL_FUNC(functions, Color4fv);
  REGISTER_GL_FUNC(functions, Color4dv);
  REGISTER_GL_FUNC(functions, Indexub);
  REGISTER_GL_FUNC(functions, Indexs);
  REGISTER_GL_FUNC(functions, Indexi);
  REGISTER_GL_FUNC(functions, Indexf);
  REGISTER_GL_FUNC(functions, Indexd);
  REGISTER_GL_FUNC(functions, VertexPointer);
  REGISTER_GL_FUNC(functions, TexCoordPointer);
  REGISTER_GL_FUNC(functions, NormalPointer);
  REGISTER_GL_FUNC(functions, ColorPointer);
  REGISTER_GL_FUNC(functions, IndexPointer);
  REGISTER_GL_FUNC(functions, EdgeFlagPointer);
  REGISTER_GL_FUNC(functions, EnableClientState);
  REGISTER_GL_FUNC(functions, DisableClientState);
  REGISTER_GL_FUNC(functions, ArrayElement);
  REGISTER_GL_FUNC(functions, DrawArrays);
  REGISTER_GL_FUNC(functions, DrawElements);
  REGISTER_GL_FUNC(functions, InterleavedArrays);
  REGISTER_GL_FUNC(functions, DepthRange);
  REGISTER_GL_FUNC(functions, MatrixMode);
  REGISTER_GL_FUNC(functions, Ortho);
  REGISTER_GL_FUNC(functions, Frustum);
  REGISTER_GL_FUNC(functions, Viewport);
  REGISTER_GL_FUNC(functions, PushMatrix);
  REGISTER_GL_FUNC(functions, PopMatrix);
  REGISTER_GL_FUNC(functions, LoadIdentity);
  REGISTER_GL_FUNC(functions, LoadMatrixf);
  REGISTER_GL_FUNC(functions, LoadMatrixd);
  REGISTER_GL_FUNC(functions, MultMatrixf);
  REGISTER_GL_FUNC(functions, MultMatrixd);
  REGISTER_GL_FUNC(functions, Rotatef);
  REGISTER_GL_FUNC(functions, Scalef);
  REGISTER_GL_FUNC(functions, Translatef);
  REGISTER_GL_FUNC(functions, Rotated);
  REGISTER_GL_FUNC(functions, Scaled);
  REGISTER_GL_FUNC(functions, Translated);
  REGISTER_GL_FUNC(functions, Rects);
  REGISTER_GL_FUNC(functions, Recti);
  REGISTER_GL_FUNC(functions, Rectf);
  REGISTER_GL_FUNC(functions, Rectd);
  REGISTER_GL_FUNC(functions, Rectsv);
  REGISTER_GL_FUNC(functions, Rectiv);
  REGISTER_GL_FUNC(functions, Rectfv);
  REGISTER_GL_FUNC(functions, Rectdv);
  REGISTER_GL_FUNC(functions, Disable);
  REGISTER_GL_FUNC(functions, Enable);
  REGISTER_GL_FUNC(functions, IsEnabled);
  REGISTER_GL_FUNC(functions, TexGeni);
  REGISTER_GL_FUNC(functions, TexGenf);
  REGISTER_GL_FUNC(functions, TexGend);
  REGISTER_GL_FUNC(functions, TexGeniv);
  REGISTER_GL_FUNC(functions, TexGenfv);
  REGISTER_GL_FUNC(functions, TexGendv);
  REGISTER_GL_FUNC(functions, ClipPlane);
  REGISTER_GL_FUNC(functions, RasterPos2s);
  REGISTER_GL_FUNC(functions, RasterPos2i);
  REGISTER_GL_FUNC(functions, RasterPos2f);
  REGISTER_GL_FUNC(functions, RasterPos2d);
  REGISTER_GL_FUNC(functions, RasterPos3s);
  REGISTER_GL_FUNC(functions, RasterPos3i);
  REGISTER_GL_FUNC(functions, RasterPos3f);
  REGISTER_GL_FUNC(functions, RasterPos3d);
  REGISTER_GL_FUNC(functions, RasterPos4s);
  REGISTER_GL_FUNC(functions, RasterPos4i);
  REGISTER_GL_FUNC(functions, RasterPos4f);
  REGISTER_GL_FUNC(functions, RasterPos4d);
  REGISTER_GL_FUNC(functions, RasterPos2sv);
  REGISTER_GL_FUNC(functions, RasterPos2iv);
  REGISTER_GL_FUNC(functions, RasterPos2fv);
  REGISTER_GL_FUNC(functions, RasterPos2dv);
  REGISTER_GL_FUNC(functions, RasterPos3sv);
  REGISTER_GL_FUNC(functions, RasterPos3iv);
  REGISTER_GL_FUNC(functions, RasterPos3fv);
  REGISTER_GL_FUNC(functions, RasterPos3dv);
  REGISTER_GL_FUNC(functions, RasterPos4sv);
  REGISTER_GL_FUNC(functions, RasterPos4iv);
  REGISTER_GL_FUNC(functions, RasterPos4fv);
  REGISTER_GL_FUNC(functions, RasterPos4dv);
  REGISTER_GL_FUNC(functions, Materiali);
  REGISTER_GL_FUNC(functions, Materialf);
  REGISTER_GL_FUNC(functions, Materialiv);
  REGISTER_GL_FUNC(functions, Materialfv);
  REGISTER_GL_FUNC(functions, Lighti);
  REGISTER_GL_FUNC(functions, Lightf);
  REGISTER_GL_FUNC(functions, Lightiv);
  REGISTER_GL_FUNC(functions, Lightfv);
  REGISTER_GL_FUNC(functions, LightModeli);
  REGISTER_GL_FUNC(functions, LightModelf);
  REGISTER_GL_FUNC(functions, LightModeliv);
  REGISTER_GL_FUNC(functions, LightModelfv);
  REGISTER_GL_FUNC(functions, ColorMaterial);
  REGISTER_GL_FUNC(functions, ShadeModel);
  REGISTER_GL_FUNC(functions, FrontFace);
  REGISTER_GL_FUNC(functions, PointSize);
  REGISTER_GL_FUNC(functions, LineWidth);
  REGISTER_GL_FUNC(functions, LineStipple);
  REGISTER_GL_FUNC(functions, CullFace);
  REGISTER_GL_FUNC(functions, PolygonStipple);
  REGISTER_GL_FUNC(functions, PolygonMode);
  REGISTER_GL_FUNC(functions, PolygonOffset);
  REGISTER_GL_FUNC(functions, PixelStorei);
  REGISTER_GL_FUNC(functions, PixelStoref);
  REGISTER_GL_FUNC(functions, PixelTransferi);
  REGISTER_GL_FUNC(functions, PixelTransferf);
  REGISTER_GL_FUNC(functions, PixelMapusv);
  REGISTER_GL_FUNC(functions, PixelMapuiv);
  REGISTER_GL_FUNC(functions, PixelMapfv);
  REGISTER_GL_FUNC(functions, DrawPixels);
  REGISTER_GL_FUNC(functions, PixelZoom);
  REGISTER_GL_FUNC(functions, Bitmap);
  REGISTER_GL_FUNC(functions, TexImage1D);
  REGISTER_GL_FUNC(functions, TexImage2D);
  REGISTER_GL_FUNC(functions, CopyTexImage1D);
  REGISTER_GL_FUNC(functions, CopyTexImage2D);
  REGISTER_GL_FUNC(functions, TexSubImage1D);
  REGISTER_GL_FUNC(functions, TexSubImage2D);
  REGISTER_GL_FUNC(functions, CopyTexSubImage1D);
  REGISTER_GL_FUNC(functions, CopyTexSubImage2D);
  REGISTER_GL_FUNC(functions, TexParameteri);
  REGISTER_GL_FUNC(functions, TexParameterf);
  REGISTER_GL_FUNC(functions, TexParameteriv);
  REGISTER_GL_FUNC(functions, TexParameterfv);
  REGISTER_GL_FUNC(functions, BindTexture);
  REGISTER_GL_FUNC(functions, GenTextures);
  REGISTER_GL_FUNC(functions, DeleteTextures);
  REGISTER_GL_FUNC(functions, AreTexturesResident);
  REGISTER_GL_FUNC(functions, PrioritizeTextures);
  REGISTER_GL_FUNC(functions, TexEnvi);
  REGISTER_GL_FUNC(functions, TexEnvf);
  REGISTER_GL_FUNC(functions, TexEnviv);
  REGISTER_GL_FUNC(functions, TexEnvfv);
  REGISTER_GL_FUNC(functions, Fogi);
  REGISTER_GL_FUNC(functions, Fogf);
  REGISTER_GL_FUNC(functions, Fogiv);
  REGISTER_GL_FUNC(functions, Fogfv);
  REGISTER_GL_FUNC(functions, Scissor);
  REGISTER_GL_FUNC(functions, AlphaFunc);
  REGISTER_GL_FUNC(functions, StencilFunc);
  REGISTER_GL_FUNC(functions, StencilOp);
  REGISTER_GL_FUNC(functions, DepthFunc);
  REGISTER_GL_FUNC(functions, BlendFunc);
  REGISTER_GL_FUNC(functions, LogicOp);
  REGISTER_GL_FUNC(functions, DrawBuffer);
  REGISTER_GL_FUNC(functions, IndexMask);
  REGISTER_GL_FUNC(functions, ColorMask);
  REGISTER_GL_FUNC(functions, DepthMask);
  REGISTER_GL_FUNC(functions, StencilMask);
  REGISTER_GL_FUNC(functions, Clear);
  REGISTER_GL_FUNC(functions, ClearColor);
  REGISTER_GL_FUNC(functions, ClearIndex);
  REGISTER_GL_FUNC(functions, ClearDepth);
  REGISTER_GL_FUNC(functions, ClearStencil);
  REGISTER_GL_FUNC(functions, ClearAccum);
  REGISTER_GL_FUNC(functions, Accum);
  REGISTER_GL_FUNC(functions, ReadPixels);
  REGISTER_GL_FUNC(functions, ReadBuffer);
  REGISTER_GL_FUNC(functions, CopyPixels);
  REGISTER_GL_FUNC(functions, Map1f);
  REGISTER_GL_FUNC(functions, Map1d);
  REGISTER_GL_FUNC(functions, Map2f);
  REGISTER_GL_FUNC(functions, Map2d);
  REGISTER_GL_FUNC(functions, EvalCoord1f);
  REGISTER_GL_FUNC(functions, EvalCoord1d);
  REGISTER_GL_FUNC(functions, EvalCoord2f);
  REGISTER_GL_FUNC(functions, EvalCoord2d);
  REGISTER_GL_FUNC(functions, EvalCoord2fv);
  REGISTER_GL_FUNC(functions, EvalCoord2dv);
  REGISTER_GL_FUNC(functions, MapGrid1f);
  REGISTER_GL_FUNC(functions, MapGrid1d);
  REGISTER_GL_FUNC(functions, MapGrid2f);
  REGISTER_GL_FUNC(functions, MapGrid2d);
  REGISTER_GL_FUNC(functions, EvalMesh1);
  REGISTER_GL_FUNC(functions, EvalMesh2);
  REGISTER_GL_FUNC(functions, EvalPoint1);
  REGISTER_GL_FUNC(functions, EvalPoint2);
  REGISTER_GL_FUNC(functions, InitNames);
  REGISTER_GL_FUNC(functions, PopName);
  REGISTER_GL_FUNC(functions, PushName);
  REGISTER_GL_FUNC(functions, LoadName);
  REGISTER_GL_FUNC(functions, RenderMode);
  REGISTER_GL_FUNC(functions, SelectBuffer);
  REGISTER_GL_FUNC(functions, FeedbackBuffer);
  REGISTER_GL_FUNC(functions, PassThrough);
  REGISTER_GL_FUNC(functions, NewList);
  REGISTER_GL_FUNC(functions, EndList);
  REGISTER_GL_FUNC(functions, CallList);
  REGISTER_GL_FUNC(functions, CallLists);
  REGISTER_GL_FUNC(functions, ListBase);
  REGISTER_GL_FUNC(functions, GenLists);
  REGISTER_GL_FUNC(functions, IsList);
  REGISTER_GL_FUNC(functions, DeleteLists);
  REGISTER_GL_FUNC(functions, Flush);
  REGISTER_GL_FUNC(functions, Finish);
  REGISTER_GL_FUNC(functions, Hint);
  REGISTER_GL_FUNC(functions, IsTexture);
  REGISTER_GL_FUNC(functions, GetString);
  REGISTER_GL_FUNC(functions, PushAttrib);
  REGISTER_GL_FUNC(functions, PushClientAttrib);
  REGISTER_GL_FUNC(functions, PopAttrib);
  REGISTER_GL_FUNC(functions, PopClientAttrib);
  REGISTER_GL_FUNC(functions, Get);
  REGISTER_GL_FUNC(functions, GetClipPlane);
  REGISTER_GL_FUNC(functions, GetLight);
  REGISTER_GL_FUNC(functions, GetMaterial);
  REGISTER_GL_FUNC(functions, GetTexEnv);
  REGISTER_GL_FUNC(functions, GetTexGen);
  REGISTER_GL_FUNC(functions, GetTexParameter);
  REGISTER_GL_FUNC(functions, GetTexLevelParameter);
  REGISTER_GL_FUNC(functions, GetPixelMapuiv);
  REGISTER_GL_FUNC(functions, GetPixelMapusv);
  REGISTER_GL_FUNC(functions, GetPixelMapfv);
  REGISTER_GL_FUNC(functions, GetMapiv);
  REGISTER_GL_FUNC(functions, GetMapfv);
  REGISTER_GL_FUNC(functions, GetMapdv);
  REGISTER_GL_FUNC(functions, GetTexImage);
  REGISTER_GL_FUNC(functions, GetPolygonStipple);
  REGISTER_GL_FUNC(functions, GetPointer);
}


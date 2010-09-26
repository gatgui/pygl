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
#include "convert.h"
#include "wrap.h"

static PyObject* py_glUniformMatrix2x3fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix2x3fv);
}
static PyObject* py_glUniformMatrix2x4fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix2x4fv);
}
static PyObject* py_glUniformMatrix3x2fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix3x2fv);
}
static PyObject* py_glUniformMatrix3x4fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix3x4fv);
}
static PyObject* py_glUniformMatrix4x2fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix4x2fv);
}
static PyObject* py_glUniformMatrix4x3fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix4x3fv);
}

void Register_GL_2_1_Constants(PyGL::ConstantMap &constants) {
  if (GLEW_VERSION_2_1) {
    constants["CURRENT_RASTER_SECONDARY_COLOR"] = GL_CURRENT_RASTER_SECONDARY_COLOR;
    constants["PIXEL_PACK_BUFFER"] = GL_PIXEL_PACK_BUFFER;
    constants["PIXEL_UNPACK_BUFFER"] = GL_PIXEL_UNPACK_BUFFER;
    constants["PIXEL_PACK_BUFFER_BINDING"] = GL_PIXEL_PACK_BUFFER_BINDING;
    constants["PIXEL_UNPACK_BUFFER_BINDING"] = GL_PIXEL_UNPACK_BUFFER_BINDING;
    constants["FLOAT_MAT2x3"] = GL_FLOAT_MAT2x3;
    constants["FLOAT_MAT2x4"] = GL_FLOAT_MAT2x4;
    constants["FLOAT_MAT3x2"] = GL_FLOAT_MAT3x2;
    constants["FLOAT_MAT3x4"] = GL_FLOAT_MAT3x4;
    constants["FLOAT_MAT4x2"] = GL_FLOAT_MAT4x2;
    constants["FLOAT_MAT4x3"] = GL_FLOAT_MAT4x3;
    constants["SRGB"] = GL_SRGB;
    constants["SRGB8"] = GL_SRGB8;
    constants["SRGB_ALPHA"] = GL_SRGB_ALPHA;
    constants["SRGB8_ALPHA8"] = GL_SRGB8_ALPHA8;
    constants["SLUMINANCE_ALPHA"] = GL_SLUMINANCE_ALPHA;
    constants["SLUMINANCE8_ALPHA8"] = GL_SLUMINANCE8_ALPHA8;
    constants["SLUMINANCE"] = GL_SLUMINANCE;
    constants["SLUMINANCE8"] = GL_SLUMINANCE8;
    constants["COMPRESSED_SRGB"] = GL_COMPRESSED_SRGB;
    constants["COMPRESSED_SRGB_ALPHA"] = GL_COMPRESSED_SRGB_ALPHA;
    constants["COMPRESSED_SLUMINANCE"] = GL_COMPRESSED_SLUMINANCE;
    constants["COMPRESSED_SLUMINANCE_ALPHA"] = GL_COMPRESSED_SLUMINANCE_ALPHA;
    
    PyGL &gl = PyGL::Instance();
    // GL_ARB_pixel_buffer_object
    gl.addParamDim(PyGL::Integerv, GL_PIXEL_PACK_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_PIXEL_UNPACK_BUFFER_BINDING, 1);
    // GL_EXT_texture_sRGB
    // x
    // Other
    gl.addParamDim(PyGL::Floatv, GL_CURRENT_RASTER_SECONDARY_COLOR, 4);
  }
}

void Register_GL_2_1_Functions(PyGL::FunctionTable &functions) {
  if (GLEW_VERSION_2_1) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 2.1" << std::endl;
#endif
    PyGL::Instance().setVersion(2.1);
    REGISTER_GL_FUNC(functions, UniformMatrix2x3fv);
    REGISTER_GL_FUNC(functions, UniformMatrix2x4fv);
    REGISTER_GL_FUNC(functions, UniformMatrix3x2fv);
    REGISTER_GL_FUNC(functions, UniformMatrix3x4fv);
    REGISTER_GL_FUNC(functions, UniformMatrix4x2fv);
    REGISTER_GL_FUNC(functions, UniformMatrix4x3fv);
  }
}


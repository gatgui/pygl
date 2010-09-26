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

static PyObject* py_glTexImage3D(PyObject *self, PyObject *args)
{
  return WrapFunc10<Enum, Int, Int, Sizei, Sizei, Sizei, Int, Enum, Enum, ConstPtr>::Call(self, args, glTexImage3D);
}

static PyObject* py_glTexSubImage3D(PyObject *self, PyObject *args)
{
  return WrapFunc11<Enum, Int, Int, Int, Int, Sizei, Sizei, Sizei, Enum, Enum, ConstPtr>::Call(self, args, glTexSubImage3D);
}

static PyObject* py_glCopyTexSubImage3D(PyObject *self, PyObject *args)
{
  return WrapFunc9<Enum, Int, Int, Int, Int, Int, Int, Sizei, Sizei>::Call(self, args, glCopyTexSubImage3D);
}

static PyObject* py_glDrawRangeElements(PyObject *self, PyObject *args)
{
  return WrapFunc6<Enum, Uint, Uint, Sizei, Enum, ConstPtr>::Call(self, args, glDrawRangeElements);
}

void Register_GL_1_2_Constants(PyGL::ConstantMap &constants)
{
  if (GLEW_VERSION_1_2)
  {
    constants["SMOOTH_POINT_SIZE_RANGE"] = GL_SMOOTH_POINT_SIZE_RANGE;
    constants["SMOOTH_POINT_SIZE_GRANULARITY"] = GL_SMOOTH_POINT_SIZE_GRANULARITY;
    constants["SMOOTH_LINE_WIDTH_RANGE"] = GL_SMOOTH_LINE_WIDTH_RANGE;
    constants["SMOOTH_LINE_WIDTH_GRANULARITY"] = GL_SMOOTH_LINE_WIDTH_GRANULARITY;
    constants["UNSIGNED_BYTE_3_3_2"] = GL_UNSIGNED_BYTE_3_3_2;
    constants["UNSIGNED_SHORT_4_4_4_4"] = GL_UNSIGNED_SHORT_4_4_4_4;
    constants["UNSIGNED_SHORT_5_5_5_1"] = GL_UNSIGNED_SHORT_5_5_5_1;
    constants["UNSIGNED_INT_8_8_8_8"] = GL_UNSIGNED_INT_8_8_8_8;
    constants["UNSIGNED_INT_10_10_10_2"] = GL_UNSIGNED_INT_10_10_10_2;
    constants["RESCALE_NORMAL"] = GL_RESCALE_NORMAL;
    constants["TEXTURE_BINDING_3D"] = GL_TEXTURE_BINDING_3D;
    constants["PACK_SKIP_IMAGES"] = GL_PACK_SKIP_IMAGES;
    constants["PACK_IMAGE_HEIGHT"] = GL_PACK_IMAGE_HEIGHT;
    constants["UNPACK_SKIP_IMAGES"] = GL_UNPACK_SKIP_IMAGES;
    constants["UNPACK_IMAGE_HEIGHT"] = GL_UNPACK_IMAGE_HEIGHT;
    constants["TEXTURE_3D"] = GL_TEXTURE_3D;
    constants["PROXY_TEXTURE_3D"] = GL_PROXY_TEXTURE_3D;
    constants["TEXTURE_DEPTH"] = GL_TEXTURE_DEPTH;
    constants["TEXTURE_WRAP_R"] = GL_TEXTURE_WRAP_R;
    constants["MAX_3D_TEXTURE_SIZE"] = GL_MAX_3D_TEXTURE_SIZE;
    constants["BGR"] = GL_BGR;
    constants["BGRA"] = GL_BGRA;
    constants["MAX_ELEMENTS_VERTICES"] = GL_MAX_ELEMENTS_VERTICES;
    constants["MAX_ELEMENTS_INDICES"] = GL_MAX_ELEMENTS_INDICES;
    constants["CLAMP_TO_EDGE"] = GL_CLAMP_TO_EDGE;
    constants["TEXTURE_MIN_LOD"] = GL_TEXTURE_MIN_LOD;
    constants["TEXTURE_MAX_LOD"] = GL_TEXTURE_MAX_LOD;
    constants["TEXTURE_BASE_LEVEL"] = GL_TEXTURE_BASE_LEVEL;
    constants["TEXTURE_MAX_LEVEL"] = GL_TEXTURE_MAX_LEVEL;
    constants["LIGHT_MODEL_COLOR_CONTROL"] = GL_LIGHT_MODEL_COLOR_CONTROL;
    constants["SINGLE_COLOR"] = GL_SINGLE_COLOR;
    constants["SEPARATE_SPECULAR_COLOR"] = GL_SEPARATE_SPECULAR_COLOR;
    constants["UNSIGNED_BYTE_2_3_3_REV"] = GL_UNSIGNED_BYTE_2_3_3_REV;
    constants["UNSIGNED_SHORT_5_6_5"] = GL_UNSIGNED_SHORT_5_6_5;
    constants["UNSIGNED_SHORT_5_6_5_REV"] = GL_UNSIGNED_SHORT_5_6_5_REV;
    constants["UNSIGNED_SHORT_4_4_4_4_REV"] = GL_UNSIGNED_SHORT_4_4_4_4_REV;
    constants["UNSIGNED_SHORT_1_5_5_5_REV"] = GL_UNSIGNED_SHORT_1_5_5_5_REV;
    constants["UNSIGNED_INT_8_8_8_8_REV"] = GL_UNSIGNED_INT_8_8_8_8_REV;
    constants["UNSIGNED_INT_2_10_10_10_REV"] = GL_UNSIGNED_INT_2_10_10_10_REV;
    constants["ALIASED_POINT_SIZE_RANGE"] = GL_ALIASED_POINT_SIZE_RANGE;
    constants["ALIASED_LINE_WIDTH_RANGE"] = GL_ALIASED_LINE_WIDTH_RANGE;
    
    PyGL &gl = PyGL::Instance();
    gl.addParamDim(PyGL::Integerv, GL_UNPACK_SKIP_IMAGES, 1);
    gl.addParamDim(PyGL::Integerv, GL_UNPACK_IMAGE_HEIGHT, 1);
    gl.addParamDim(PyGL::Integerv, GL_PACK_SKIP_IMAGES, 1);
    gl.addParamDim(PyGL::Integerv, GL_PACK_IMAGE_HEIGHT, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_3D_TEXTURE_SIZE, 1);
    gl.addParamDim(PyGL::Integerv, GL_LIGHT_MODEL_COLOR_CONTROL, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_ELEMENTS_VERTICES, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_ELEMENTS_INDICES, 1);
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_WRAP_R, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_DEPTH, 1);
    gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_MIN_LOD, 1);
    gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_MAX_LOD, 1);
    gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_BASE_LEVEL, 1);
    gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_MAX_LEVEL, 1);
  }
}

void Register_GL_1_2_Functions(PyGL::FunctionTable &functions)
{
  if (GLEW_VERSION_1_2)
  {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.2" << std::endl;
#endif
    PyGL::Instance().setVersion(1.2);
    REGISTER_GL_FUNC(functions, TexImage3D);
    REGISTER_GL_FUNC(functions, TexSubImage3D);
    REGISTER_GL_FUNC(functions, CopyTexSubImage3D);
    REGISTER_GL_FUNC(functions, DrawRangeElements);
  }
}



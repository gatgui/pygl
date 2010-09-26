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

static PyObject* py_glBlendColor(PyObject *self, PyObject *args) {
  return WrapFunc4<Clampf, Clampf, Clampf, Clampf >::Call(self, args, glBlendColor);
}

static PyObject* py_glBlendEquation(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glBlendEquation);
}

static PyObject* py_glBlendFuncSeparate(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Enum, Enum, Enum >::Call(self, args, glBlendFuncSeparate);
}

static PyObject* py_glFogCoordPointer(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Sizei, ConstPtr >::Call(self, args, glFogCoordPointer);
}

static PyObject* py_glFogCoordd(PyObject *self, PyObject *args) {
  return WrapFunc1<Double >::Call(self, args, glFogCoordd);
}
static PyObject* py_glFogCoordf(PyObject *self, PyObject *args) {
  return WrapFunc1<Float >::Call(self, args, glFogCoordf);
}

static PyObject* py_glMultiDrawArrays(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, TypedPtr<Int>, TypedPtr<Sizei>, Sizei >::Call(self, args, glMultiDrawArrays);
}

static PyObject* py_glMultiDrawElements(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Array<Sizei>, Enum, Array<ConstPtr>, Sizei >::Call(self, args, glMultiDrawElements);
}

static PyObject* py_glPointParameterf(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float >::Call(self, args, glPointParameterf);
}
static PyObject* py_glPointParameterfv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Array<Float> >::Call(self, args, glPointParameterfv);
}
static PyObject* py_glPointParameteri(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int >::Call(self, args, glPointParameteri);
}
static PyObject* py_glPointParameteriv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Array<Int> >::Call(self, args, glPointParameteriv);
}

static PyObject* py_glSecondaryColor3b(PyObject *self, PyObject *args) {
  return WrapFunc3<Byte, Byte, Byte >::Call(self, args, glSecondaryColor3b);
}
static PyObject* py_glSecondaryColor3bv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Byte> >::Call(self, args, glSecondaryColor3bv);
}
static PyObject* py_glSecondaryColor3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double >::Call(self, args, glSecondaryColor3d);
}
static PyObject* py_glSecondaryColor3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glSecondaryColor3dv);
}
static PyObject* py_glSecondaryColor3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float >::Call(self, args, glSecondaryColor3f);
}
static PyObject* py_glSecondaryColor3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glSecondaryColor3fv);
}
static PyObject* py_glSecondaryColor3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int >::Call(self, args, glSecondaryColor3i);
}
static PyObject* py_glSecondaryColor3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glSecondaryColor3iv);
}
static PyObject* py_glSecondaryColor3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short >::Call(self, args, glSecondaryColor3s);
}
static PyObject* py_glSecondaryColor3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glSecondaryColor3sv);
}
static PyObject* py_glSecondaryColor3ub(PyObject *self, PyObject *args) {
  return WrapFunc3<Ubyte, Ubyte, Ubyte >::Call(self, args, glSecondaryColor3ub);
}
static PyObject* py_glSecondaryColor3ubv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ubyte> >::Call(self, args, glSecondaryColor3ubv);
}
static PyObject* py_glSecondaryColor3ui(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Uint, Uint >::Call(self, args, glSecondaryColor3ui);
}
static PyObject* py_glSecondaryColor3uiv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Uint> >::Call(self, args, glSecondaryColor3uiv);
}
static PyObject* py_glSecondaryColor3us(PyObject *self, PyObject *args) {
  return WrapFunc3<Ushort, Ushort, Ushort >::Call(self, args, glSecondaryColor3us);
}
static PyObject* py_glSecondaryColor3usv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Ushort> >::Call(self, args, glSecondaryColor3usv);
}

static PyObject* py_glSecondaryColorPointer(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(self, args, glSecondaryColorPointer);
}

static PyObject* py_glWindowPos2d(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double >::Call(self, args, glWindowPos2d);
}
static PyObject* py_glWindowPos2dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glWindowPos2dv);
}
static PyObject* py_glWindowPos2f(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float >::Call(self, args, glWindowPos2f);
}
static PyObject* py_glWindowPos2fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glWindowPos2fv);
}
static PyObject* py_glWindowPos2i(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int >::Call(self, args, glWindowPos2i);
}
static PyObject* py_glWindowPos2iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glWindowPos2iv);
}
static PyObject* py_glWindowPos2s(PyObject *self, PyObject *args) {
  return WrapFunc2<Short, Short >::Call(self, args, glWindowPos2s);
}
static PyObject* py_glWindowPos2sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glWindowPos2sv);
}
static PyObject* py_glWindowPos3d(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double >::Call(self, args, glWindowPos3d);
}
static PyObject* py_glWindowPos3dv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glWindowPos3dv);
}
static PyObject* py_glWindowPos3f(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float >::Call(self, args, glWindowPos3f);
}
static PyObject* py_glWindowPos3fv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glWindowPos3fv);
}
static PyObject* py_glWindowPos3i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int >::Call(self, args, glWindowPos3i);
}
static PyObject* py_glWindowPos3iv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glWindowPos3iv);
}
static PyObject* py_glWindowPos3s(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short >::Call(self, args, glWindowPos3s);
}
static PyObject* py_glWindowPos3sv(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glWindowPos3sv);
}

void Register_GL_1_4_Constants(PyGL::ConstantMap &constants) {
  if (GLEW_VERSION_1_4) {
    constants["BLEND_DST_RGB"] = GL_BLEND_DST_RGB;
    constants["BLEND_SRC_RGB"] = GL_BLEND_SRC_RGB;
    constants["BLEND_DST_ALPHA"] = GL_BLEND_DST_ALPHA;
    constants["BLEND_SRC_ALPHA"] = GL_BLEND_SRC_ALPHA;
    constants["POINT_SIZE_MIN"] = GL_POINT_SIZE_MIN;
    constants["POINT_SIZE_MAX"] = GL_POINT_SIZE_MAX;
    constants["POINT_FADE_THRESHOLD_SIZE"] = GL_POINT_FADE_THRESHOLD_SIZE;
    constants["POINT_DISTANCE_ATTENUATION"] = GL_POINT_DISTANCE_ATTENUATION;
    constants["GENERATE_MIPMAP"] = GL_GENERATE_MIPMAP;
    constants["GENERATE_MIPMAP_HINT"] = GL_GENERATE_MIPMAP_HINT;
    constants["DEPTH_COMPONENT16"] = GL_DEPTH_COMPONENT16;
    constants["DEPTH_COMPONENT24"] = GL_DEPTH_COMPONENT24;
    constants["DEPTH_COMPONENT32"] = GL_DEPTH_COMPONENT32;
    constants["MIRRORED_REPEAT"] = GL_MIRRORED_REPEAT;
    constants["FOG_COORDINATE_SOURCE"] = GL_FOG_COORDINATE_SOURCE;
    constants["FOG_COORDINATE"] = GL_FOG_COORDINATE;
    constants["FRAGMENT_DEPTH"] = GL_FRAGMENT_DEPTH;
    constants["CURRENT_FOG_COORDINATE"] = GL_CURRENT_FOG_COORDINATE;
    constants["FOG_COORDINATE_ARRAY_TYPE"] = GL_FOG_COORDINATE_ARRAY_TYPE;
    constants["FOG_COORDINATE_ARRAY_STRIDE"] = GL_FOG_COORDINATE_ARRAY_STRIDE;
    constants["FOG_COORDINATE_ARRAY_POINTER"] = GL_FOG_COORDINATE_ARRAY_POINTER;
    constants["FOG_COORDINATE_ARRAY"] = GL_FOG_COORDINATE_ARRAY;
    constants["COLOR_SUM"] = GL_COLOR_SUM;
    constants["CURRENT_SECONDARY_COLOR"] = GL_CURRENT_SECONDARY_COLOR;
    constants["SECONDARY_COLOR_ARRAY_SIZE"] = GL_SECONDARY_COLOR_ARRAY_SIZE;
    constants["SECONDARY_COLOR_ARRAY_TYPE"] = GL_SECONDARY_COLOR_ARRAY_TYPE;
    constants["SECONDARY_COLOR_ARRAY_STRIDE"] = GL_SECONDARY_COLOR_ARRAY_STRIDE;
    constants["SECONDARY_COLOR_ARRAY_POINTER"] = GL_SECONDARY_COLOR_ARRAY_POINTER;
    constants["SECONDARY_COLOR_ARRAY"] = GL_SECONDARY_COLOR_ARRAY;
    constants["MAX_TEXTURE_LOD_BIAS"] = GL_MAX_TEXTURE_LOD_BIAS;
    constants["TEXTURE_FILTER_CONTROL"] = GL_TEXTURE_FILTER_CONTROL;
    constants["TEXTURE_LOD_BIAS"] = GL_TEXTURE_LOD_BIAS;
    constants["INCR_WRAP"] = GL_INCR_WRAP;
    constants["DECR_WRAP"] = GL_DECR_WRAP;
    constants["TEXTURE_DEPTH_SIZE"] = GL_TEXTURE_DEPTH_SIZE;
    constants["DEPTH_TEXTURE_MODE"] = GL_DEPTH_TEXTURE_MODE;
    constants["TEXTURE_COMPARE_MODE"] = GL_TEXTURE_COMPARE_MODE;
    constants["TEXTURE_COMPARE_FUNC"] = GL_TEXTURE_COMPARE_FUNC;
    constants["COMPARE_R_TO_TEXTURE"] = GL_COMPARE_R_TO_TEXTURE;
    
    PyGL &gl = PyGL::Instance();
    // GL_SGIS_generate_mipmap
    gl.addParamDim(PyGL::TexParameteriv, GL_GENERATE_MIPMAP, 1);
    gl.addParamDim(PyGL::Integerv, GL_GENERATE_MIPMAP_HINT, 1);
    // GL_NV_blend_square
    gl.addParamDim(PyGL::Integerv, GL_BLEND_SRC, 1);
    gl.addParamDim(PyGL::Integerv, GL_BLEND_DST, 1);
    // GL_ARB_depth_texture
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_SIZE, 1);
    gl.addParamDim(PyGL::TexParameteriv, GL_DEPTH_TEXTURE_MODE, 1);
    // GL_ARB_shadow
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_COMPARE_MODE, 1);
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC, 1);
    // GL_EXT_fog_coord
    gl.addParamDim(PyGL::Floatv, GL_CURRENT_FOG_COORDINATE, 1);
    gl.addParamDim(PyGL::Integerv, GL_FOG_COORDINATE_ARRAY_TYPE, 1);
    gl.addParamDim(PyGL::Integerv, GL_FOG_COORDINATE_ARRAY_STRIDE, 1);
    gl.addParamDim(PyGL::Integerv, GL_FOG_COORDINATE_SOURCE, 1);
    // GL_EXT_multi_draw_arrays
    // x
    // GL_ARB_point_parameters
    gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_MIN, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_MAX, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_FADE_THRESHOLD_SIZE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_DISTANCE_ATTENUATION, 3);
    // GL_EXT_secondary_color
    gl.addParamDim(PyGL::Floatv, GL_CURRENT_SECONDARY_COLOR, 4);
    gl.addParamDim(PyGL::Integerv, GL_SECONDARY_COLOR_ARRAY_SIZE, 1);
    gl.addParamDim(PyGL::Integerv, GL_SECONDARY_COLOR_ARRAY_TYPE, 1);
    gl.addParamDim(PyGL::Integerv, GL_SECONDARY_COLOR_ARRAY_STRIDE, 1);
    // GL_EXT_blend_func_separate
    gl.addParamDim(PyGL::Integerv, GL_BLEND_SRC_RGB, 1);
    gl.addParamDim(PyGL::Integerv, GL_BLEND_DST_RGB, 1);
    gl.addParamDim(PyGL::Integerv, GL_BLEND_SRC_ALPHA, 1);
    gl.addParamDim(PyGL::Integerv, GL_BLEND_DST_ALPHA, 1);
    // GL_EXT_stencil_wrap
    // x
    // GL_ARB_texture_env_crossbar
    // x
    // GL_EXT_texture_lod_bias
    gl.addParamDim(PyGL::TexEnvfv, GL_TEXTURE_LOD_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_MAX_TEXTURE_LOD_BIAS, 1);
    // GL_ARB_texture_mirrored_repeat
    // x
    // GL_ARB_window_pos
    // x
  }
}

void Register_GL_1_4_Functions(PyGL::FunctionTable &functions) {
  if (GLEW_VERSION_1_4) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.4" << std::endl;
#endif
    PyGL::Instance().setVersion(1.4);
    REGISTER_GL_FUNC(functions, BlendColor);
    REGISTER_GL_FUNC(functions, BlendEquation);
    REGISTER_GL_FUNC(functions, BlendFuncSeparate);
    REGISTER_GL_FUNC(functions, FogCoordPointer);
    REGISTER_GL_FUNC(functions, FogCoordd);
    REGISTER_GL_FUNC(functions, FogCoordf);
    REGISTER_GL_FUNC(functions, MultiDrawArrays);
    REGISTER_GL_FUNC(functions, MultiDrawElements);
    REGISTER_GL_FUNC(functions, PointParameterf);
    REGISTER_GL_FUNC(functions, PointParameterfv);
    REGISTER_GL_FUNC(functions, PointParameteri);
    REGISTER_GL_FUNC(functions, PointParameteriv);
    REGISTER_GL_FUNC(functions, SecondaryColor3d);
    REGISTER_GL_FUNC(functions, SecondaryColor3f);
    REGISTER_GL_FUNC(functions, SecondaryColor3b);
    REGISTER_GL_FUNC(functions, SecondaryColor3s);
    REGISTER_GL_FUNC(functions, SecondaryColor3i);
    REGISTER_GL_FUNC(functions, SecondaryColor3ub);
    REGISTER_GL_FUNC(functions, SecondaryColor3us);
    REGISTER_GL_FUNC(functions, SecondaryColor3ui);
    REGISTER_GL_FUNC(functions, SecondaryColor3dv);
    REGISTER_GL_FUNC(functions, SecondaryColor3fv);
    REGISTER_GL_FUNC(functions, SecondaryColor3bv);
    REGISTER_GL_FUNC(functions, SecondaryColor3sv);
    REGISTER_GL_FUNC(functions, SecondaryColor3iv);
    REGISTER_GL_FUNC(functions, SecondaryColor3ubv);
    REGISTER_GL_FUNC(functions, SecondaryColor3usv);
    REGISTER_GL_FUNC(functions, SecondaryColor3uiv);
    REGISTER_GL_FUNC(functions, SecondaryColorPointer);
    REGISTER_GL_FUNC(functions, WindowPos2d);
    REGISTER_GL_FUNC(functions, WindowPos2f);
    REGISTER_GL_FUNC(functions, WindowPos2i);
    REGISTER_GL_FUNC(functions, WindowPos2s);
    REGISTER_GL_FUNC(functions, WindowPos2dv);
    REGISTER_GL_FUNC(functions, WindowPos2fv);
    REGISTER_GL_FUNC(functions, WindowPos2iv);
    REGISTER_GL_FUNC(functions, WindowPos2sv);
    REGISTER_GL_FUNC(functions, WindowPos3d);
    REGISTER_GL_FUNC(functions, WindowPos3f);
    REGISTER_GL_FUNC(functions, WindowPos3i);
    REGISTER_GL_FUNC(functions, WindowPos3s);
    REGISTER_GL_FUNC(functions, WindowPos3dv);
    REGISTER_GL_FUNC(functions, WindowPos3fv);
    REGISTER_GL_FUNC(functions, WindowPos3iv);
    REGISTER_GL_FUNC(functions, WindowPos3sv);
  }
  
}



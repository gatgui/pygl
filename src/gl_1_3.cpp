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

static PyObject* py_glActiveTexture(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glActiveTexture);
}

static PyObject* py_glClientActiveTexture(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glClientActiveTexture);
}

static PyObject* py_glCompressedTexImage1D(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Enum, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage1D);
}

static PyObject* py_glCompressedTexImage2D(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Int, Enum, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage2D);
}

static PyObject* py_glCompressedTexImage3D(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Enum, Sizei, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage3D);
}

static PyObject* py_glCompressedTexSubImage1D(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage1D);
}

static PyObject* py_glCompressedTexSubImage2D(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage2D);
}

static PyObject* py_glCompressedTexSubImage3D(PyObject *self, PyObject *args) {
  return WrapFunc11<Enum, Int, Int, Int, Int, Sizei, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage3D);
}

static PyObject* py_glGetCompressedTexImage(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Ptr >::Call(self, args, glGetCompressedTexImage);
}

static PyObject* py_glLoadTransposeMatrixf(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArrayN<Float, 16> >::Call(self, args, glLoadTransposeMatrixf);
}
static PyObject* py_glLoadTransposeMatrixd(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArrayN<Double, 16> >::Call(self, args, glLoadTransposeMatrixd);
}

static PyObject* py_glMultTransposeMatrixf(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArrayN<Float, 16> >::Call(self, args, glMultTransposeMatrixf);
}
static PyObject* py_glMultTransposeMatrixd(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArrayN<Double, 16> >::Call(self, args, glMultTransposeMatrixd);
}

static PyObject* py_glMultiTexCoord1s(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Short >::Call(self, args, glMultiTexCoord1s);
}
static PyObject* py_glMultiTexCoord1i(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int >::Call(self, args, glMultiTexCoord1i);
}
static PyObject* py_glMultiTexCoord1f(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float >::Call(self, args, glMultiTexCoord1f);
}
static PyObject* py_glMultiTexCoord1d(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Double >::Call(self, args, glMultiTexCoord1d);
}

static PyObject* py_glMultiTexCoord2s(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Short, Short >::Call(self, args, glMultiTexCoord2s);
}
static PyObject* py_glMultiTexCoord2i(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Int >::Call(self, args, glMultiTexCoord2i);
}
static PyObject* py_glMultiTexCoord2f(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Float, Float >::Call(self, args, glMultiTexCoord2f);
}
static PyObject* py_glMultiTexCoord2d(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Double, Double >::Call(self, args, glMultiTexCoord2d);
}
static PyObject* py_glMultiTexCoord2sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Short, 2> >::Call(self, args, glMultiTexCoord2sv);
}
static PyObject* py_glMultiTexCoord2iv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Int, 2> >::Call(self, args, glMultiTexCoord2iv);
}
static PyObject* py_glMultiTexCoord2fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Float, 2> >::Call(self, args, glMultiTexCoord2fv);
}
static PyObject* py_glMultiTexCoord2dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Double, 2> >::Call(self, args, glMultiTexCoord2dv);
}

static PyObject* py_glMultiTexCoord3s(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Short, Short, Short >::Call(self, args, glMultiTexCoord3s);
}
static PyObject* py_glMultiTexCoord3i(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Int, Int, Int >::Call(self, args, glMultiTexCoord3i);
}
static PyObject* py_glMultiTexCoord3f(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Float, Float, Float >::Call(self, args, glMultiTexCoord3f);
}
static PyObject* py_glMultiTexCoord3d(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Double, Double, Double >::Call(self, args, glMultiTexCoord3d);
}
static PyObject* py_glMultiTexCoord3sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Short, 3> >::Call(self, args, glMultiTexCoord3sv);
}
static PyObject* py_glMultiTexCoord3iv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Int, 3> >::Call(self, args, glMultiTexCoord3iv);
}
static PyObject* py_glMultiTexCoord3fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Float, 3> >::Call(self, args, glMultiTexCoord3fv);
}
static PyObject* py_glMultiTexCoord3dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Double, 3> >::Call(self, args, glMultiTexCoord3dv);
}

static PyObject* py_glMultiTexCoord4s(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Short, Short, Short, Short >::Call(self, args, glMultiTexCoord4s);
}
static PyObject* py_glMultiTexCoord4i(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Int, Int, Int, Int >::Call(self, args, glMultiTexCoord4i);
}
static PyObject* py_glMultiTexCoord4f(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Float, Float, Float, Float >::Call(self, args, glMultiTexCoord4f);
}
static PyObject* py_glMultiTexCoord4d(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Double, Double, Double, Double >::Call(self, args, glMultiTexCoord4d);
}
static PyObject* py_glMultiTexCoord4sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Short, 4> >::Call(self, args, glMultiTexCoord4sv);
}
static PyObject* py_glMultiTexCoord4iv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Int, 4> >::Call(self, args, glMultiTexCoord4iv);
}
static PyObject* py_glMultiTexCoord4fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Float, 4> >::Call(self, args, glMultiTexCoord4fv);
}
static PyObject* py_glMultiTexCoord4dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArrayN<Double, 4> >::Call(self, args, glMultiTexCoord4dv);
}

static PyObject* py_glSampleCoverage(PyObject *self, PyObject *args) {
  return WrapFunc2<Clampf, Boolean >::Call(self, args, glSampleCoverage);
}

void Register_GL_1_3_Constants(PyGL::ConstantMap &constants) {
  if (GLEW_VERSION_1_3) {
    constants["MULTISAMPLE"] = GL_MULTISAMPLE;
    constants["SAMPLE_ALPHA_TO_COVERAGE"] = GL_SAMPLE_ALPHA_TO_COVERAGE;
    constants["SAMPLE_ALPHA_TO_ONE"] = GL_SAMPLE_ALPHA_TO_ONE;
    constants["SAMPLE_COVERAGE"] = GL_SAMPLE_COVERAGE;
    constants["SAMPLE_BUFFERS"] = GL_SAMPLE_BUFFERS;
    constants["SAMPLES"] = GL_SAMPLES;
    constants["SAMPLE_COVERAGE_VALUE"] = GL_SAMPLE_COVERAGE_VALUE;
    constants["SAMPLE_COVERAGE_INVERT"] = GL_SAMPLE_COVERAGE_INVERT;
    constants["CLAMP_TO_BORDER"] = GL_CLAMP_TO_BORDER;
    constants["TEXTURE0"] = GL_TEXTURE0;
    constants["TEXTURE1"] = GL_TEXTURE1;
    constants["TEXTURE2"] = GL_TEXTURE2;
    constants["TEXTURE3"] = GL_TEXTURE3;
    constants["TEXTURE4"] = GL_TEXTURE4;
    constants["TEXTURE5"] = GL_TEXTURE5;
    constants["TEXTURE6"] = GL_TEXTURE6;
    constants["TEXTURE7"] = GL_TEXTURE7;
    constants["TEXTURE8"] = GL_TEXTURE8;
    constants["TEXTURE9"] = GL_TEXTURE9;
    constants["TEXTURE10"] = GL_TEXTURE10;
    constants["TEXTURE11"] = GL_TEXTURE11;
    constants["TEXTURE12"] = GL_TEXTURE12;
    constants["TEXTURE13"] = GL_TEXTURE13;
    constants["TEXTURE14"] = GL_TEXTURE14;
    constants["TEXTURE15"] = GL_TEXTURE15;
    constants["TEXTURE16"] = GL_TEXTURE16;
    constants["TEXTURE17"] = GL_TEXTURE17;
    constants["TEXTURE18"] = GL_TEXTURE18;
    constants["TEXTURE19"] = GL_TEXTURE19;
    constants["TEXTURE20"] = GL_TEXTURE20;
    constants["TEXTURE21"] = GL_TEXTURE21;
    constants["TEXTURE22"] = GL_TEXTURE22;
    constants["TEXTURE23"] = GL_TEXTURE23;
    constants["TEXTURE24"] = GL_TEXTURE24;
    constants["TEXTURE25"] = GL_TEXTURE25;
    constants["TEXTURE26"] = GL_TEXTURE26;
    constants["TEXTURE27"] = GL_TEXTURE27;
    constants["TEXTURE28"] = GL_TEXTURE28;
    constants["TEXTURE29"] = GL_TEXTURE29;
    constants["TEXTURE30"] = GL_TEXTURE30;
    constants["TEXTURE31"] = GL_TEXTURE31;
    constants["ACTIVE_TEXTURE"] = GL_ACTIVE_TEXTURE;
    constants["CLIENT_ACTIVE_TEXTURE"] = GL_CLIENT_ACTIVE_TEXTURE;
    constants["MAX_TEXTURE_UNITS"] = GL_MAX_TEXTURE_UNITS;
    constants["TRANSPOSE_MODELVIEW_MATRIX"] = GL_TRANSPOSE_MODELVIEW_MATRIX;
    constants["TRANSPOSE_PROJECTION_MATRIX"] = GL_TRANSPOSE_PROJECTION_MATRIX;
    constants["TRANSPOSE_TEXTURE_MATRIX"] = GL_TRANSPOSE_TEXTURE_MATRIX;
    constants["TRANSPOSE_COLOR_MATRIX"] = GL_TRANSPOSE_COLOR_MATRIX;
    constants["SUBTRACT"] = GL_SUBTRACT;
    constants["COMPRESSED_ALPHA"] = GL_COMPRESSED_ALPHA;
    constants["COMPRESSED_LUMINANCE"] = GL_COMPRESSED_LUMINANCE;
    constants["COMPRESSED_LUMINANCE_ALPHA"] = GL_COMPRESSED_LUMINANCE_ALPHA;
    constants["COMPRESSED_INTENSITY"] = GL_COMPRESSED_INTENSITY;
    constants["COMPRESSED_RGB"] = GL_COMPRESSED_RGB;
    constants["COMPRESSED_RGBA"] = GL_COMPRESSED_RGBA;
    constants["TEXTURE_COMPRESSION_HINT"] = GL_TEXTURE_COMPRESSION_HINT;
    constants["NORMAL_MAP"] = GL_NORMAL_MAP;
    constants["REFLECTION_MAP"] = GL_REFLECTION_MAP;
    constants["TEXTURE_CUBE_MAP"] = GL_TEXTURE_CUBE_MAP;
    constants["TEXTURE_BINDING_CUBE_MAP"] = GL_TEXTURE_BINDING_CUBE_MAP;
    constants["TEXTURE_CUBE_MAP_POSITIVE_X"] = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Y"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Z"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_X"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Y"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Z"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;
    constants["PROXY_TEXTURE_CUBE_MAP"] = GL_PROXY_TEXTURE_CUBE_MAP;
    constants["MAX_CUBE_MAP_TEXTURE_SIZE"] = GL_MAX_CUBE_MAP_TEXTURE_SIZE;
    constants["COMBINE"] = GL_COMBINE;
    constants["COMBINE_RGB"] = GL_COMBINE_RGB;
    constants["COMBINE_ALPHA"] = GL_COMBINE_ALPHA;
    constants["RGB_SCALE"] = GL_RGB_SCALE;
    constants["ADD_SIGNED"] = GL_ADD_SIGNED;
    constants["INTERPOLATE"] = GL_INTERPOLATE;
    constants["CONSTANT"] = GL_CONSTANT;
    constants["PRIMARY_COLOR"] = GL_PRIMARY_COLOR;
    constants["PREVIOUS"] = GL_PREVIOUS;
    constants["SOURCE0_RGB"] = GL_SOURCE0_RGB;
    constants["SORUCE1_RGB"] = GL_SOURCE1_RGB;
    constants["SOURCE2_RGB"] = GL_SOURCE2_RGB;
    constants["SOURCE0_ALPHA"] = GL_SOURCE0_ALPHA;
    constants["SOURCE1_ALPHA"] = GL_SOURCE1_ALPHA;
    constants["SOURCE2_ALPHA"] = GL_SOURCE2_ALPHA;
    constants["OPERAND0_RGB"] = GL_OPERAND0_RGB;
    constants["OPERAND1_RGB"] = GL_OPERAND1_RGB;
    constants["OPERAND2_RGB"] = GL_OPERAND2_RGB;
    constants["OPERAND0_ALPHA"] = GL_OPERAND0_ALPHA;
    constants["OPERAND1_ALPHA"] = GL_OPERAND1_ALPHA;
    constants["OPERAND2_ALPHA"] = GL_OPERAND2_ALPHA;
    constants["TEXTURE_COMPRESSED_IMAGE_SIZE"] = GL_TEXTURE_COMPRESSED_IMAGE_SIZE;
    constants["TEXTURE_COMPRESSED"] = GL_TEXTURE_COMPRESSED;
    constants["NUM_COMPRESSED_TEXTURE_FORMATS"] = GL_NUM_COMPRESSED_TEXTURE_FORMATS;
    constants["COMPRESSED_TEXTURE_FORMATS"] = GL_COMPRESSED_TEXTURE_FORMATS;
    constants["DOT3_RGB"] = GL_DOT3_RGB;
    constants["DOT3_RGBA"] = GL_DOT3_RGBA;
    constants["MULTISAMPLE_BIT"] = GL_MULTISAMPLE_BIT;

    PyGL &gl = PyGL::Instance();
    // GL_ARB_texture_compression
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED_IMAGE_SIZE, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED, 1);
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COMPRESSION_HINT, 1);
    gl.addParamDim(PyGL::Integerv, GL_NUM_COMPRESSED_TEXTURE_FORMATS, 1);
    gl.addDependentParamDim(PyGL::Integerv, GL_COMPRESSED_TEXTURE_FORMATS, GL_NUM_COMPRESSED_TEXTURE_FORMATS);
    // GL_ARB_texture_cube_map
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_BINDING_CUBE_MAP, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_CUBE_MAP_TEXTURE_SIZE, 1);
    // GL_ARB_multisample
    gl.addParamDim(PyGL::Floatv, GL_SAMPLE_COVERAGE_VALUE, 1);
    gl.addParamDim(PyGL::Booleanv, GL_SAMPLE_COVERAGE_INVERT, 1);
    gl.addParamDim(PyGL::Integerv, GL_SAMPLE_BUFFERS, 1);
    gl.addParamDim(PyGL::Integerv, GL_SAMPLES, 1);
    // GL_ARB_multitexture
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_UNITS, 1);
    gl.addParamDim(PyGL::Integerv, GL_ACTIVE_TEXTURE, 1);
    gl.addParamDim(PyGL::Integerv, GL_CLIENT_ACTIVE_TEXTURE, 1);
    // GL_ARB_texture_env_add
    // x
    // GL_ARB_texture_env_combine
    gl.addParamDim(PyGL::TexEnviv, GL_COMBINE_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_COMBINE_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE0_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE1_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE2_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE0_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE1_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE2_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND0_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND1_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND2_RGB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND0_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND1_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND2_ALPHA, 1);
    gl.addParamDim(PyGL::TexEnvfv, GL_RGB_SCALE, 1);
    gl.addParamDim(PyGL::TexEnvfv, GL_ALPHA_SCALE, 1);
    // GL_ARB_texture_env_dot3
    // x
    // GL_ARB_texture_border_clamp
    // x
  }
}

void Register_GL_1_3_Functions(PyGL::FunctionTable &functions)
{
  if (GLEW_VERSION_1_3)
  {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.3" << std::endl;
#endif
    PyGL::Instance().setVersion(1.3);
    REGISTER_GL_FUNC(functions, ActiveTexture);
    REGISTER_GL_FUNC(functions, ClientActiveTexture);
    REGISTER_GL_FUNC(functions, CompressedTexImage1D);
    REGISTER_GL_FUNC(functions, CompressedTexImage2D);
    REGISTER_GL_FUNC(functions, CompressedTexImage3D);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage1D);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage2D);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage3D);
    REGISTER_GL_FUNC(functions, GetCompressedTexImage);
    REGISTER_GL_FUNC(functions, LoadTransposeMatrixf);
    REGISTER_GL_FUNC(functions, LoadTransposeMatrixd);
    REGISTER_GL_FUNC(functions, MultTransposeMatrixf);
    REGISTER_GL_FUNC(functions, MultTransposeMatrixd);
    REGISTER_GL_FUNC(functions, MultiTexCoord1s);
    REGISTER_GL_FUNC(functions, MultiTexCoord1i);
    REGISTER_GL_FUNC(functions, MultiTexCoord1f);
    REGISTER_GL_FUNC(functions, MultiTexCoord1d);
    REGISTER_GL_FUNC(functions, MultiTexCoord2s);
    REGISTER_GL_FUNC(functions, MultiTexCoord2i);
    REGISTER_GL_FUNC(functions, MultiTexCoord2f);
    REGISTER_GL_FUNC(functions, MultiTexCoord2d);
    REGISTER_GL_FUNC(functions, MultiTexCoord2sv);
    REGISTER_GL_FUNC(functions, MultiTexCoord2iv);
    REGISTER_GL_FUNC(functions, MultiTexCoord2fv);
    REGISTER_GL_FUNC(functions, MultiTexCoord2dv);
    REGISTER_GL_FUNC(functions, MultiTexCoord3s);
    REGISTER_GL_FUNC(functions, MultiTexCoord3i);
    REGISTER_GL_FUNC(functions, MultiTexCoord3f);
    REGISTER_GL_FUNC(functions, MultiTexCoord3d);
    REGISTER_GL_FUNC(functions, MultiTexCoord3sv);
    REGISTER_GL_FUNC(functions, MultiTexCoord3iv);
    REGISTER_GL_FUNC(functions, MultiTexCoord3fv);
    REGISTER_GL_FUNC(functions, MultiTexCoord3dv);
    REGISTER_GL_FUNC(functions, MultiTexCoord4s);
    REGISTER_GL_FUNC(functions, MultiTexCoord4i);
    REGISTER_GL_FUNC(functions, MultiTexCoord4f);
    REGISTER_GL_FUNC(functions, MultiTexCoord4d);
    REGISTER_GL_FUNC(functions, MultiTexCoord4sv);
    REGISTER_GL_FUNC(functions, MultiTexCoord4iv);
    REGISTER_GL_FUNC(functions, MultiTexCoord4fv);
    REGISTER_GL_FUNC(functions, MultiTexCoord4dv);
    REGISTER_GL_FUNC(functions, SampleCoverage);
  }
}

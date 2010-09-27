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

static PyObject* py_glAttachShader(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Uint >::Call(self, args, glAttachShader);
}

static PyObject* py_glBindAttribLocation(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Uint, String >::Call(self, args, glBindAttribLocation);
}

static PyObject* py_glBlendEquationSeparate(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum >::Call(self, args, glBlendEquationSeparate);
}

static PyObject* py_glCompileShader(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glCompileShader);
}

static PyObject* py_glCreateProgram(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 0);
  return PyInt_FromLong(glCreateProgram());
}

static PyObject* py_glCreateShader(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum type(PyTuple_GetItem(args, 0));
  return PyInt_FromLong(glCreateShader(type));
}

static PyObject* py_glDeleteProgram(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glDeleteProgram);
}

static PyObject* py_glDeleteShader(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glDeleteShader);
}

static PyObject* py_glDetachShader(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Uint >::Call(self, args, glDetachShader);
}

static PyObject* py_glDisableVertexAttribArray(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glDisableVertexAttribArray);
}

static PyObject* py_glDrawBuffers(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Enum> buffers(PyTuple_GetItem(args, 0));
  glDrawBuffers(buffers.size(), buffers);
  Py_RETURN_NONE;
}

static PyObject* py_glEnableVertexAttribArray(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glEnableVertexAttribArray);
}

static PyObject* py_glGetActiveAttrib(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint prg(PyTuple_GetItem(args, 0));
  Uint idx(PyTuple_GetItem(args, 1));
  GLint len = 0;
  glGetProgramiv(prg, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &len);
  //GLchar *name = new GLchar[len+1];
  Array1D<Char> name(len+1);
  GLint size;
  GLenum type;
  glGetActiveAttrib(prg, idx, len, NULL, &size, &type, name);
  //lua_pushinteger(L, size);
  //lua_pushinteger(L, type);
  //lua_pushstring(L, name);
  PyObject *rv = PyTuple_New(3);
  PyTuple_SetItem(rv, 0, PyInt_FromLong(size));
  PyTuple_SetItem(rv, 1, PyInt_FromLong(type));
  PyTuple_SetItem(rv, 2, PyString_FromString(name));
  //delete[] name;
  return rv;
}

static PyObject* py_glGetActiveUniform(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint prg(PyTuple_GetItem(args, 0));
  Uint idx(PyTuple_GetItem(args, 1));
  GLint len = 0;
  glGetProgramiv(prg, GL_ACTIVE_UNIFORM_MAX_LENGTH, &len);
  //GLchar *name = new GLchar[len+1];
  Array1D<Char> name(len+1);
  GLint size;
  GLenum type;
  glGetActiveUniform(prg, idx, len, NULL, &size, &type, name);
  PyObject *rv = PyTuple_New(3);
  PyTuple_SetItem(rv, 0, PyInt_FromLong(size));
  PyTuple_SetItem(rv, 1, PyInt_FromLong(type));
  PyTuple_SetItem(rv, 2, PyString_FromString(name));
  //delete[] name;
  return rv;
}

static PyObject* py_glGetAttachedShaders(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint prg(PyTuple_GetItem(args, 0));
  GLint count=0;
  glGetProgramiv(prg, GL_ATTACHED_SHADERS, &count);
  if (count == 0) {
    return PyList_New(0);
  } else {
    Array1D<Uint> shaders(count);
    glGetAttachedShaders(prg, count, NULL, shaders);
    return shaders.toPy();
  }
}

static PyObject* py_glGetAttribLocation(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint prg(PyTuple_GetItem(args, 0));
  String name(PyTuple_GetItem(args, 1));
  return PyInt_FromLong(glGetAttribLocation(prg, name));
}

static PyObject* py_glGetProgramInfoLog(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint prg(PyTuple_GetItem(args, 0));
  GLint len=0;
  glGetProgramiv(prg, GL_INFO_LOG_LENGTH, &len);
  //GLchar *log = new GLchar[len+1];
  Array1D<Char> log(len+1);
  glGetProgramInfoLog(prg, len, NULL, log);
  return PyString_FromString(log);
  //delete[] log;
}

static PyObject* py_glGetProgram(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  PyObject *rv = 0;
  Uint prg(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLint dim = PyGL::Instance().getParamDim(PyGL::Programiv, pname);
  if (dim > 0) {
    Array1D<Int> param(dim);
    glGetProgramiv(prg, pname, param);
    if (dim == 1) {
      rv = PyInt_FromLong(param[0]);
    } else {
      rv = param.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetProgram: invalid parameter name");
  }
  return rv;
}

static PyObject* py_glGetShaderInfoLog(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint shader(PyTuple_GetItem(args, 0));
  GLint len=0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
  //GLchar *log = new GLchar[len+1];
  Array1D<Char> log(len+1);
  glGetShaderInfoLog(shader, len, NULL, log);
  return PyString_FromString(log);
  //delete[] log;
}

static PyObject* py_glGetShaderSource(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint shader(PyTuple_GetItem(args, 0));
  GLint len=0;
  glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &len);
  //GLchar *src = new GLchar[len+1];
  Array1D<Char> src(len+1);
  glGetShaderSource(shader, len, NULL, src);
  return PyString_FromString(src);
  //delete[] src;
}

static PyObject* py_glGetShader(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  PyObject *rv = 0;
  Uint prg(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLint dim = PyGL::Instance().getParamDim(PyGL::Shaderiv, pname);
  if (dim > 0) {
    Array1D<Int> param(dim);
    glGetShaderiv(prg, pname, param);
    if (dim == 1) {
      rv = PyInt_FromLong(param[0]);
    } else {
      rv = param.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetShader: invalid parameter name");
  }
  return rv;
}

static PyObject* py_glGetUniformLocation(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Int prg(PyTuple_GetItem(args, 0));
  String name(PyTuple_GetItem(args, 1));
  return PyInt_FromLong(glGetUniformLocation(prg, name));
}

static PyObject* py_glIsProgram(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint prg(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsProgram(prg) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glIsShader(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint shader(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsShader(shader) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glLinkProgram(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glLinkProgram);
}

static PyObject* py_glGetUniform(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  PyObject *rv = 0;
  Uint prg(PyTuple_GetItem(args, 0));
  Int loc(PyTuple_GetItem(args, 1));
  GLint size;
  GLenum type;
  GLchar dummy;
  glGetActiveUniform(prg, loc, 0, 0, &size, &type, &dummy);
  bool integer = false;
  int dim = 0;
  switch (type) {
    case GL_FLOAT:
      dim = 1;
      break;
    case GL_FLOAT_VEC2:
      dim = 2;
      break;
    case GL_FLOAT_VEC3:
      dim = 3;
      break;
    case GL_FLOAT_VEC4:
    case GL_FLOAT_MAT2:
      dim = 4;
      break;
    case GL_FLOAT_MAT3:
      dim = 9;
      break;
    case GL_FLOAT_MAT4:
      dim = 16;
      break;
    // Those are in fact OpenGL 2.1 additions
    case GL_FLOAT_MAT2x3:
    case GL_FLOAT_MAT3x2:
      dim = 6;
      break;
    case GL_FLOAT_MAT2x4:
    case GL_FLOAT_MAT4x2:
      dim = 8;
      break;
    case GL_FLOAT_MAT3x4:
    case GL_FLOAT_MAT4x3:
      dim = 12;
      break;
    case GL_INT:
    case GL_BOOL:
    case GL_SAMPLER_1D:
    case GL_SAMPLER_2D:
    case GL_SAMPLER_3D:
    case GL_SAMPLER_CUBE:
    case GL_SAMPLER_1D_SHADOW:
    case GL_SAMPLER_2D_SHADOW:
      integer = true;
      dim = 1;
      break;
    case GL_INT_VEC2:
    case GL_BOOL_VEC2:
      integer = true;
      dim = 2;
      break;
    case GL_INT_VEC3:
    case GL_BOOL_VEC3:
      integer = true;
      dim = 3;
      break;
    case GL_INT_VEC4:
    case GL_BOOL_VEC4:
      integer = true;
      dim = 4;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetUniform: invalid type");
    return NULL;
  }
  if (integer) {
    GLint values[4];
    glGetUniformiv(prg, loc, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = Array1D<Int>(values, dim).toPy();
    }
  } else {
    GLfloat values[16];
    glGetUniformfv(prg, loc, values);
    if (dim == 1) {
      rv = PyFloat_FromDouble(values[0]);
    } else {
      rv = Array1D<Float>(values, dim).toPy();
    }
  }
  return rv;
}

static PyObject* py_glGetVertexAttribPointer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint prg(PyTuple_GetItem(args, 0));
  Enum param(PyTuple_GetItem(args, 1));
  GLvoid *ptr = 0;
  glGetVertexAttribPointerv(prg, param, &ptr);
  return PyCObject_FromVoidPtr(ptr, NULL);
}

static PyObject* py_glGetVertexAttrib(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  PyObject *rv = 0;
  Uint attrib(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  switch (pname) {
    case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING:
    case GL_VERTEX_ATTRIB_ARRAY_ENABLED:
    case GL_VERTEX_ATTRIB_ARRAY_SIZE:
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE:
    case GL_VERTEX_ATTRIB_ARRAY_TYPE:
    case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED: {
      GLint value;
      glGetVertexAttribiv(attrib, pname, &value);
      rv = PyInt_FromLong(value);
      break;
    }
    case GL_CURRENT_VERTEX_ATTRIB: {
      Array1D<Float> values(4);
      glGetVertexAttribfv(attrib, pname, values);
      rv = values.toPy();
      break;
    }
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetVertexAttrib: invalid parameter name");
  }
  return rv;
}

static PyObject* py_glShaderSource(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint shader(PyTuple_GetItem(args, 0));
  Array1D<String> strings(PyTuple_GetItem(args, 1));
  glShaderSource(shader, strings.size(), strings, 0);
  Py_RETURN_NONE;
}

static PyObject* py_glStencilFuncSeparate(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Enum, Int, Uint >::Call(self, args, glStencilFuncSeparate);
}

static PyObject* py_glStencilMaskSeparate(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glStencilMaskSeparate);
}

static PyObject* py_glStencilOpSeparate(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Enum, Enum, Enum >::Call(self, args, glStencilOpSeparate);
}

static PyObject* py_glUniform1f(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Float >::Call(self, args, glUniform1f);
}
static PyObject* py_glUniform2f(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Float, Float >::Call(self, args, glUniform2f);
}
static PyObject* py_glUniform3f(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Float, Float, Float >::Call(self, args, glUniform3f);
}
static PyObject* py_glUniform4f(PyObject *self, PyObject *args) {
  return WrapFunc5<Int, Float, Float, Float, Float >::Call(self, args, glUniform4f);
}
static PyObject* py_glUniform1i(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int >::Call(self, args, glUniform1i);
}
static PyObject* py_glUniform2i(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int >::Call(self, args, glUniform2i);
}
static PyObject* py_glUniform3i(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int >::Call(self, args, glUniform3i);
}
static PyObject* py_glUniform4i(PyObject *self, PyObject *args) {
  return WrapFunc5<Int, Int, Int, Int, Int >::Call(self, args, glUniform4i);
}
static PyObject* py_glUniform1iv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform1iv);
}
static PyObject* py_glUniform2iv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform2iv);
}
static PyObject* py_glUniform3iv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform3iv);
}
static PyObject* py_glUniform4iv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform4iv);
}
static PyObject* py_glUniform1fv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform1fv);
}
static PyObject* py_glUniform2fv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform2fv);
}
static PyObject* py_glUniform3fv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform3fv);
}
static PyObject* py_glUniform4fv(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform4fv);
}

static PyObject* py_glUniformMatrix2fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix2fv);
}
static PyObject* py_glUniformMatrix3fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix3fv);
}
static PyObject* py_glUniformMatrix4fv(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix4fv);
}

static PyObject* py_glUseProgram(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glUseProgram);
}

static PyObject* py_glValidateProgram(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glValidateProgram);
}

static PyObject* py_glVertexAttrib1d(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Double >::Call(self, args, glVertexAttrib1d);
}
static PyObject* py_glVertexAttrib1f(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Float >::Call(self, args, glVertexAttrib1f);
}
static PyObject* py_glVertexAttrib1s(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Short >::Call(self, args, glVertexAttrib1s);
}

static PyObject* py_glVertexAttrib2d(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Double, Double >::Call(self, args, glVertexAttrib2d);
}
static PyObject* py_glVertexAttrib2f(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Float, Float >::Call(self, args, glVertexAttrib2f);
}
static PyObject* py_glVertexAttrib2s(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Short, Short >::Call(self, args, glVertexAttrib2s);
}
static PyObject* py_glVertexAttrib2dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib2dv);
}
static PyObject* py_glVertexAttrib2fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib2fv);
}
static PyObject* py_glVertexAttrib2sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib2sv);
}

static PyObject* py_glVertexAttrib3d(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Double, Double, Double >::Call(self, args, glVertexAttrib3d);
}
static PyObject* py_glVertexAttrib3f(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Float, Float, Float >::Call(self, args, glVertexAttrib3f);
}
static PyObject* py_glVertexAttrib3s(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Short, Short, Short >::Call(self, args, glVertexAttrib3s);
}
static PyObject* py_glVertexAttrib3dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib3dv);
}
static PyObject* py_glVertexAttrib3fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib3fv);
}
static PyObject* py_glVertexAttrib3sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib3sv);
}

static PyObject* py_glVertexAttrib4d(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Double, Double, Double, Double >::Call(self, args, glVertexAttrib4d);
}
static PyObject* py_glVertexAttrib4f(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Float, Float, Float, Float >::Call(self, args, glVertexAttrib4f);
}
static PyObject* py_glVertexAttrib4s(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Short, Short, Short, Short >::Call(self, args, glVertexAttrib4s);
}
static PyObject* py_glVertexAttrib4Nub(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte >::Call(self, args, glVertexAttrib4Nub);
}
static PyObject* py_glVertexAttrib4Nbv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(self, args, glVertexAttrib4Nbv);
}
static PyObject* py_glVertexAttrib4Niv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Int> >::Call(self, args, glVertexAttrib4Niv);
}
static PyObject* py_glVertexAttrib4Nsv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib4Nsv);
}
static PyObject* py_glVertexAttrib4Nubv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(self, args, glVertexAttrib4Nubv);
}
static PyObject* py_glVertexAttrib4Nuiv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(self, args, glVertexAttrib4Nuiv);
}
static PyObject* py_glVertexAttrib4Nusv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(self, args, glVertexAttrib4Nusv);
}
static PyObject* py_glVertexAttrib4bv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(self, args, glVertexAttrib4bv);
}
static PyObject* py_glVertexAttrib4ubv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(self, args, glVertexAttrib4ubv);
}
static PyObject* py_glVertexAttrib4sv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib4sv);
}
static PyObject* py_glVertexAttrib4usv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(self, args, glVertexAttrib4usv);
}
static PyObject* py_glVertexAttrib4iv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Int> >::Call(self, args, glVertexAttrib4iv);
}
static PyObject* py_glVertexAttrib4uiv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(self, args, glVertexAttrib4uiv);
}
static PyObject* py_glVertexAttrib4fv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib4fv);
}
static PyObject* py_glVertexAttrib4dv(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib4dv);
}

static PyObject* py_glVertexAttribPointer(PyObject *self, PyObject *args) {
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr >::Call(self, args, glVertexAttribPointer);
}


void Register_GL_2_0_Constants(PyGL::ConstantMap &constants) {
  if (GLEW_VERSION_2_0) {
    constants["BLEND_EQUATION_RGB"] = GL_BLEND_EQUATION_RGB;
    constants["VERTEX_ATTRIB_ARRAY_ENABLED"] = GL_VERTEX_ATTRIB_ARRAY_ENABLED;
    constants["VERTEX_ATTRIB_ARRAY_SIZE"] = GL_VERTEX_ATTRIB_ARRAY_SIZE;
    constants["VERTEX_ATTRIB_ARRAY_STRIDE"] = GL_VERTEX_ATTRIB_ARRAY_STRIDE;
    constants["VERTEX_ATTRIB_ARRAY_TYPE"] = GL_VERTEX_ATTRIB_ARRAY_TYPE;
    constants["CURRENT_VERTEX_ATTRIB"] = GL_CURRENT_VERTEX_ATTRIB;
    constants["VERTEX_PROGRAM_POINT_SIZE"] = GL_VERTEX_PROGRAM_POINT_SIZE;
    constants["VERTEX_PROGRAM_TWO_SIDE"] = GL_VERTEX_PROGRAM_TWO_SIDE;
    constants["VERTEX_ATTRIB_ARRAY_POINTER"] = GL_VERTEX_ATTRIB_ARRAY_POINTER;
    constants["STENCIL_BACK_FUNC"] = GL_STENCIL_BACK_FUNC;
    constants["STENCIL_BACK_FAIL"] = GL_STENCIL_BACK_FAIL;
    constants["STENCIL_BACK_PASS_DEPTH_FAIL"] = GL_STENCIL_BACK_PASS_DEPTH_FAIL;
    constants["STENCIL_BACK_PASS_DEPTH_PASS"] = GL_STENCIL_BACK_PASS_DEPTH_PASS;
    constants["MAX_DRAW_BUFFERS"] = GL_MAX_DRAW_BUFFERS;
    constants["DRAW_BUFFER0"] = GL_DRAW_BUFFER0;
    constants["DRAW_BUFFER1"] = GL_DRAW_BUFFER1;
    constants["DRAW_BUFFER2"] = GL_DRAW_BUFFER2;
    constants["DRAW_BUFFER3"] = GL_DRAW_BUFFER3;
    constants["DRAW_BUFFER4"] = GL_DRAW_BUFFER4;
    constants["DRAW_BUFFER5"] = GL_DRAW_BUFFER5;
    constants["DRAW_BUFFER6"] = GL_DRAW_BUFFER6;
    constants["DRAW_BUFFER7"] = GL_DRAW_BUFFER7;
    constants["DRAW_BUFFER8"] = GL_DRAW_BUFFER8;
    constants["DRAW_BUFFER9"] = GL_DRAW_BUFFER9;
    constants["DRAW_BUFFER10"] = GL_DRAW_BUFFER10;
    constants["DRAW_BUFFER11"] = GL_DRAW_BUFFER11;
    constants["DRAW_BUFFER12"] = GL_DRAW_BUFFER12;
    constants["DRAW_BUFFER13"] = GL_DRAW_BUFFER13;
    constants["DRAW_BUFFER14"] = GL_DRAW_BUFFER14;
    constants["DRAW_BUFFER15"] = GL_DRAW_BUFFER15;
    constants["BLEND_EQUATION_ALPHA"] = GL_BLEND_EQUATION_ALPHA;
    constants["POINT_SPRITE"] = GL_POINT_SPRITE;
    constants["COORD_REPLACE"] = GL_COORD_REPLACE;
    constants["MAX_VERTEX_ATTRIBS"] = GL_MAX_VERTEX_ATTRIBS;
    constants["VERTEX_ATTRIB_ARRAY_NORMALIZED"] = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED;
    constants["MAX_TEXTURE_COORDS"] = GL_MAX_TEXTURE_COORDS;
    constants["MAX_TEXTURE_IMAGE_UNITS"] = GL_MAX_TEXTURE_IMAGE_UNITS;
    constants["FRAGMENT_SHADER"] = GL_FRAGMENT_SHADER;
    constants["VERTEX_SHADER"] = GL_VERTEX_SHADER;
    constants["MAX_FRAGMENT_UNIFORM_COMPONENTS"] = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS;
    constants["MAX_VERTEX_UNIFORM_COMPONENTS"] = GL_MAX_VERTEX_UNIFORM_COMPONENTS;
    constants["MAX_VARYING_FLOATS"] = GL_MAX_VARYING_FLOATS;
    constants["MAX_VERTEX_TEXTURE_IMAGE_UNITS"] = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS;
    constants["MAX_COMBINED_TEXTURE_IMAGE_UNITS"] = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS;
    constants["SHADER_TYPE"] = GL_SHADER_TYPE;
    constants["FLOAT_VEC2"] = GL_FLOAT_VEC2;
    constants["FLOAT_VEC3"] = GL_FLOAT_VEC3;
    constants["FLOAT_VEC4"] = GL_FLOAT_VEC4;
    constants["INT_VEC2"] = GL_INT_VEC2;
    constants["INT_VEC3"] = GL_INT_VEC3;
    constants["INT_VEC4"] = GL_INT_VEC4;
    constants["BOOL"] = GL_BOOL;
    constants["BOOL_VEC2"] = GL_BOOL_VEC2;
    constants["BOOL_VEC3"] = GL_BOOL_VEC3;
    constants["BOOL_VEC4"] = GL_BOOL_VEC4;
    constants["FLOAT_MAT2"] = GL_FLOAT_MAT2;
    constants["FLOAT_MAT3"] = GL_FLOAT_MAT3;
    constants["FLOAT_MAT4"] = GL_FLOAT_MAT4;
    constants["SAMPLER_1D"] = GL_SAMPLER_1D;
    constants["SAMPLER_2D"] = GL_SAMPLER_2D;
    constants["SAMPLER_3D"] = GL_SAMPLER_3D;
    constants["SAMPLER_CUBE"] = GL_SAMPLER_CUBE;
    constants["SAMPLER_1D_SHADOW"] = GL_SAMPLER_1D_SHADOW;
    constants["SAMPLER_2D_SHADOW"] = GL_SAMPLER_2D_SHADOW;
    constants["DELETE_STATUS"] = GL_DELETE_STATUS;
    constants["COMPILE_STATUS"] = GL_COMPILE_STATUS;
    constants["LINK_STATUS"] = GL_LINK_STATUS;
    constants["VALIDATE_STATUS"] = GL_VALIDATE_STATUS;
    constants["INFO_LOG_LENGTH"] = GL_INFO_LOG_LENGTH;
    constants["ATTACHED_SHADERS"] = GL_ATTACHED_SHADERS;
    constants["ACTIVE_UNIFORMS"] = GL_ACTIVE_UNIFORMS;
    constants["ACTIVE_UNIFORM_MAX_LENGTH"] = GL_ACTIVE_UNIFORM_MAX_LENGTH;
    constants["SHADER_SOURCE_LENGTH"] = GL_SHADER_SOURCE_LENGTH;
    constants["ACTIVE_ATTRIBUTES"] = GL_ACTIVE_ATTRIBUTES;
    constants["ACTIVE_ATTRIBUTE_MAX_LENGTH"] = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH;
    constants["FRAGMENT_SHADER_DERIVATIVE_HINT"] = GL_FRAGMENT_SHADER_DERIVATIVE_HINT;
    constants["SHADING_LANGUAGE_VERSION"] = GL_SHADING_LANGUAGE_VERSION;
    constants["CURRENT_PROGRAM"] = GL_CURRENT_PROGRAM;
    constants["POINT_SPRITE_COORD_ORIGIN"] = GL_POINT_SPRITE_COORD_ORIGIN;
    constants["LOWER_LEFT"] = GL_LOWER_LEFT;
    constants["UPPER_LEFT"] = GL_UPPER_LEFT;
    constants["STENCIL_BACK_REF"] = GL_STENCIL_BACK_REF;
    constants["STENCIL_BACK_VALUE_MASK"] = GL_STENCIL_BACK_VALUE_MASK;
    constants["STENCIL_BACK_WRITEMASK"] = GL_STENCIL_BACK_WRITEMASK;
    
    PyGL &gl = PyGL::Instance();
    // GL_ARB_shader_objects
    // x
    // GL_ARB_vertex_shader
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_ATTRIBS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_UNIFORM_COMPONENTS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VARYING_FLOATS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_COORDS, 1);
    // GL_ARB_fragment_shader
    gl.addParamDim(PyGL::Integerv, GL_FRAGMENT_SHADER_DERIVATIVE_HINT, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_COORDS, 1);
    // GL_ARB_shading_language_100
    // x
    // GL_ARB_draw_buffers
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER0, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER1, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER2, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER3, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER4, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER5, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER6, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER7, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER8, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER9, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER10, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER11, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER12, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER15, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_DRAW_BUFFERS, 1);
    // GL_ARB_texture_non_power_of_two
    // x
    // GL_ARB_point_sprite [depends on GL_ARB_point_parameter]
    gl.addParamDim(PyGL::TexEnviv, GL_COORD_REPLACE, 1);
    gl.addParamDim(PyGL::Integerv, GL_POINT_SPRITE_COORD_ORIGIN, 1);
    // GL_EXT_blend_equation_separate
    gl.addParamDim(PyGL::Integerv, GL_BLEND_EQUATION_RGB, 1);
    gl.addParamDim(PyGL::Integerv, GL_BLEND_EQUATION_ALPHA, 1);
    // GL_ATI_separate_stencil, GL_EXT_stencil_two_side
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_FUNC, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_FAIL, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_PASS_DEPTH_FAIL, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_PASS_DEPTH_PASS, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_VALUE_MASK, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_REF, 1);
    gl.addParamDim(PyGL::Integerv, GL_STENCIL_BACK_WRITEMASK, 1);
    // Other
    gl.addParamDim(PyGL::Integerv, GL_CURRENT_PROGRAM, 1);
    gl.addParamDim(PyGL::Shaderiv, GL_SHADER_TYPE, 1);
    gl.addParamDim(PyGL::Shaderiv, GL_DELETE_STATUS, 1);
    gl.addParamDim(PyGL::Shaderiv, GL_COMPILE_STATUS, 1);
    gl.addParamDim(PyGL::Shaderiv, GL_INFO_LOG_LENGTH, 1);
    gl.addParamDim(PyGL::Shaderiv, GL_SHADER_SOURCE_LENGTH, 1);
    gl.addParamDim(PyGL::Programiv, GL_DELETE_STATUS, 1);
    gl.addParamDim(PyGL::Programiv, GL_LINK_STATUS, 1);
    gl.addParamDim(PyGL::Programiv, GL_VALIDATE_STATUS, 1);
    gl.addParamDim(PyGL::Programiv, GL_ATTACHED_SHADERS, 1);
    gl.addParamDim(PyGL::Programiv, GL_INFO_LOG_LENGTH, 1);
    gl.addParamDim(PyGL::Programiv, GL_ACTIVE_UNIFORMS, 1);
    gl.addParamDim(PyGL::Programiv, GL_ACTIVE_UNIFORM_MAX_LENGTH, 1);
    gl.addParamDim(PyGL::Programiv, GL_ACTIVE_ATTRIBUTES, 1);
    gl.addParamDim(PyGL::Programiv, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, 1);
  }
}

void Register_GL_2_0_Functions(PyGL::FunctionTable &functions) {
  if (GLEW_VERSION_2_0) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 2.0" << std::endl;
#endif
    PyGL::Instance().setVersion(2.0);
    REGISTER_GL_FUNC(functions, AttachShader);
    REGISTER_GL_FUNC(functions, CreateShader);
    REGISTER_GL_FUNC(functions, CreateProgram);
    REGISTER_GL_FUNC(functions, DetachShader);
    REGISTER_GL_FUNC(functions, DeleteShader);
    REGISTER_GL_FUNC(functions, DeleteProgram);
    REGISTER_GL_FUNC(functions, BindAttribLocation);
    REGISTER_GL_FUNC(functions, BlendEquationSeparate);
    REGISTER_GL_FUNC(functions, CompileShader);
    REGISTER_GL_FUNC(functions, DisableVertexAttribArray);
    REGISTER_GL_FUNC(functions, DrawBuffers);
    REGISTER_GL_FUNC(functions, EnableVertexAttribArray);
    REGISTER_GL_FUNC(functions, GetActiveAttrib);
    REGISTER_GL_FUNC(functions, GetActiveUniform);
    REGISTER_GL_FUNC(functions, GetAttachedShaders);
    REGISTER_GL_FUNC(functions, GetAttribLocation);
    REGISTER_GL_FUNC(functions, GetProgramInfoLog);
    REGISTER_GL_FUNC(functions, GetProgram);
    REGISTER_GL_FUNC(functions, GetShaderInfoLog);
    REGISTER_GL_FUNC(functions, GetShaderSource);
    REGISTER_GL_FUNC(functions, GetShader);
    REGISTER_GL_FUNC(functions, GetUniformLocation);
    REGISTER_GL_FUNC(functions, IsProgram);
    REGISTER_GL_FUNC(functions, IsShader);
    REGISTER_GL_FUNC(functions, LinkProgram);
    REGISTER_GL_FUNC(functions, GetUniform);
    REGISTER_GL_FUNC(functions, GetVertexAttribPointer);
    REGISTER_GL_FUNC(functions, GetVertexAttrib);
    REGISTER_GL_FUNC(functions, ShaderSource);
    REGISTER_GL_FUNC(functions, StencilFuncSeparate);
    REGISTER_GL_FUNC(functions, StencilMaskSeparate);
    REGISTER_GL_FUNC(functions, StencilOpSeparate);
    REGISTER_GL_FUNC(functions, Uniform1f);
    REGISTER_GL_FUNC(functions, Uniform2f);
    REGISTER_GL_FUNC(functions, Uniform3f);
    REGISTER_GL_FUNC(functions, Uniform4f);
    REGISTER_GL_FUNC(functions, Uniform1i);
    REGISTER_GL_FUNC(functions, Uniform2i);
    REGISTER_GL_FUNC(functions, Uniform3i);
    REGISTER_GL_FUNC(functions, Uniform4i);
    REGISTER_GL_FUNC(functions, Uniform1iv);
    REGISTER_GL_FUNC(functions, Uniform2iv);
    REGISTER_GL_FUNC(functions, Uniform3iv);
    REGISTER_GL_FUNC(functions, Uniform4iv);
    REGISTER_GL_FUNC(functions, Uniform1fv);
    REGISTER_GL_FUNC(functions, Uniform2fv);
    REGISTER_GL_FUNC(functions, Uniform3fv);
    REGISTER_GL_FUNC(functions, Uniform4fv);
    REGISTER_GL_FUNC(functions, UniformMatrix2fv);
    REGISTER_GL_FUNC(functions, UniformMatrix3fv);
    REGISTER_GL_FUNC(functions, UniformMatrix4fv);
    REGISTER_GL_FUNC(functions, UseProgram);
    REGISTER_GL_FUNC(functions, ValidateProgram);
    REGISTER_GL_FUNC(functions, VertexAttrib1f);
    REGISTER_GL_FUNC(functions, VertexAttrib1d);
    REGISTER_GL_FUNC(functions, VertexAttrib1s);
    REGISTER_GL_FUNC(functions, VertexAttrib2f);
    REGISTER_GL_FUNC(functions, VertexAttrib2d);
    REGISTER_GL_FUNC(functions, VertexAttrib2s);
    REGISTER_GL_FUNC(functions, VertexAttrib3f);
    REGISTER_GL_FUNC(functions, VertexAttrib3d);
    REGISTER_GL_FUNC(functions, VertexAttrib3s);
    REGISTER_GL_FUNC(functions, VertexAttrib2fv);
    REGISTER_GL_FUNC(functions, VertexAttrib2dv);
    REGISTER_GL_FUNC(functions, VertexAttrib2sv);
    REGISTER_GL_FUNC(functions, VertexAttrib3fv);
    REGISTER_GL_FUNC(functions, VertexAttrib3dv);
    REGISTER_GL_FUNC(functions, VertexAttrib3sv);
    REGISTER_GL_FUNC(functions, VertexAttrib4f);
    REGISTER_GL_FUNC(functions, VertexAttrib4d);
    REGISTER_GL_FUNC(functions, VertexAttrib4s);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nub);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nbv);
    REGISTER_GL_FUNC(functions, VertexAttrib4Niv);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nsv);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nubv);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nuiv);
    REGISTER_GL_FUNC(functions, VertexAttrib4Nusv);
    REGISTER_GL_FUNC(functions, VertexAttrib4bv);
    REGISTER_GL_FUNC(functions, VertexAttrib4ubv);
    REGISTER_GL_FUNC(functions, VertexAttrib4sv);
    REGISTER_GL_FUNC(functions, VertexAttrib4usv);
    REGISTER_GL_FUNC(functions, VertexAttrib4iv);
    REGISTER_GL_FUNC(functions, VertexAttrib4uiv);
    REGISTER_GL_FUNC(functions, VertexAttrib4fv);
    REGISTER_GL_FUNC(functions, VertexAttrib4dv);
    REGISTER_GL_FUNC(functions, VertexAttribPointer);
  }
}


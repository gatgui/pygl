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

// GL_ARB_color_buffer_float

static PyObject* py_glClampColorARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Enum >::Call(self, args, glClampColorARB);
}

// GL_ARB_draw_buffers

static PyObject* py_glDrawBuffersARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Enum> buffers(PyTuple_GetItem(args, 0));
  glDrawBuffersARB(buffers.size(), buffers);
  Py_RETURN_NONE;
}

// GL_ARB_matrix_palette

static PyObject* py_glCurrentPaletteMatrixARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Int >::Call(self, args, glCurrentPaletteMatrixARB);
}
static PyObject* py_glMatrixIndexPointerARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(self, args, glMatrixIndexPointerARB);
}
static PyObject* py_glMatrixIndexubvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Array<Ubyte> >::Call(self, args, glMatrixIndexubvARB);
}
static PyObject* py_glMatrixIndexusvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Array<Ushort> >::Call(self, args, glMatrixIndexusvARB);
}
static PyObject* py_glMatrixIndexuivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Array<Uint> >::Call(self, args, glMatrixIndexuivARB);
}

// GL_ARB_multisample

static PyObject* py_glSampleCoverageARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Clampf, Boolean >::Call(self, args, glSampleCoverageARB);
}

// GL_ARB_multitexture

static PyObject* py_glActiveTextureARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glActiveTextureARB);
}

static PyObject* py_glClientActiveTextureARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glClientActiveTextureARB);
}

static PyObject* py_glMultiTexCoord1dARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Double >::Call(self, args, glMultiTexCoord1dARB);
}
static PyObject* py_glMultiTexCoord1fARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float >::Call(self, args, glMultiTexCoord1fARB);
}
static PyObject* py_glMultiTexCoord1sARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Short >::Call(self, args, glMultiTexCoord1sARB);
}
static PyObject* py_glMultiTexCoord1iARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Int >::Call(self, args, glMultiTexCoord1iARB);
}

static PyObject* py_glMultiTexCoord2dARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Double, Double >::Call(self, args, glMultiTexCoord2dARB);
}
static PyObject* py_glMultiTexCoord2fARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Float, Float >::Call(self, args, glMultiTexCoord2fARB);
}
static PyObject* py_glMultiTexCoord2sARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Short, Short >::Call(self, args, glMultiTexCoord2sARB);
}
static PyObject* py_glMultiTexCoord2iARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Int >::Call(self, args, glMultiTexCoord2iARB);
}
static PyObject* py_glMultiTexCoord2dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Double> >::Call(self, args, glMultiTexCoord2dvARB);
}
static PyObject* py_glMultiTexCoord2fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Float> >::Call(self, args, glMultiTexCoord2fvARB);
}
static PyObject* py_glMultiTexCoord2svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Short> >::Call(self, args, glMultiTexCoord2svARB);
}
static PyObject* py_glMultiTexCoord2ivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Int> >::Call(self, args, glMultiTexCoord2ivARB);
}

static PyObject* py_glMultiTexCoord3dARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Double, Double, Double >::Call(self, args, glMultiTexCoord3dARB);
}
static PyObject* py_glMultiTexCoord3fARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Float, Float, Float >::Call(self, args, glMultiTexCoord3fARB);
}
static PyObject* py_glMultiTexCoord3sARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Short, Short, Short >::Call(self, args, glMultiTexCoord3sARB);
}
static PyObject* py_glMultiTexCoord3iARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Int, Int, Int >::Call(self, args, glMultiTexCoord3iARB);
}
static PyObject* py_glMultiTexCoord3dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Double> >::Call(self, args, glMultiTexCoord3dvARB);
}
static PyObject* py_glMultiTexCoord3fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Float> >::Call(self, args, glMultiTexCoord3fvARB);
}
static PyObject* py_glMultiTexCoord3svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Short> >::Call(self, args, glMultiTexCoord3svARB);
}
static PyObject* py_glMultiTexCoord3ivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Int> >::Call(self, args, glMultiTexCoord3ivARB);
}

static PyObject* py_glMultiTexCoord4dARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Double, Double, Double, Double >::Call(self, args, glMultiTexCoord4dARB);
}
static PyObject* py_glMultiTexCoord4fARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Float, Float, Float, Float >::Call(self, args, glMultiTexCoord4fARB);
}
static PyObject* py_glMultiTexCoord4sARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Short, Short, Short, Short >::Call(self, args, glMultiTexCoord4sARB);
}
static PyObject* py_glMultiTexCoord4iARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Int, Int, Int, Int >::Call(self, args, glMultiTexCoord4iARB);
}
static PyObject* py_glMultiTexCoord4dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Double> >::Call(self, args, glMultiTexCoord4dvARB);
}
static PyObject* py_glMultiTexCoord4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Float> >::Call(self, args, glMultiTexCoord4fvARB);
}
static PyObject* py_glMultiTexCoord4svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Short> >::Call(self, args, glMultiTexCoord4svARB);
}
static PyObject* py_glMultiTexCoord4ivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, ConstArray<Int> >::Call(self, args, glMultiTexCoord4ivARB);
}

// GL_ARB_occlusion_query

static PyObject* py_glBeginQueryARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glBeginQueryARB);
}
static PyObject* py_glDeleteQueriesARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> ids(PyTuple_GetItem(args, 0));
  glDeleteQueriesARB(ids.size(), ids);
  Py_RETURN_NONE;
}
static PyObject* py_glEndQueryARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glEndQueryARB);
}
static PyObject* py_glGenQueriesARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> ids(n);
  glGenQueriesARB(n, ids);
  return ids.toPy();
}
static PyObject* py_glGetQueryObjectARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint id(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  switch (pname) {
    case GL_QUERY_RESULT_ARB: {
      GLuint value;
      glGetQueryObjectuivARB(id, pname, &value);
      return PyInt_FromLong(value);
    }
    case GL_QUERY_RESULT_AVAILABLE_ARB: {
      GLint value;
      glGetQueryObjectivARB(id, pname, &value);
      return PyInt_FromLong(value);
    }
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetQueryObjectARB: invalid parameter name");
      return NULL;
  }
}
static PyObject* py_glGetQueryARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLint value;
  switch (pname) {
    case GL_CURRENT_QUERY_ARB:
    case GL_QUERY_COUNTER_BITS_ARB:
      glGetQueryivARB(target, pname, &value);
      return PyInt_FromLong(value);
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetQueryARB: invalid parameter name");
      return NULL;
  }
}
static PyObject* py_glIsQueryARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint id(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsQueryARB(id) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

// GL_ARB_point_parameters

static PyObject* py_glPointParameterfARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Float >::Call(self, args, glPointParameterfARB);
}
static PyObject* py_glPointParameterfvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Array<Float> >::Call(self, args, glPointParameterfvARB);
}

// GL_ARB_shader_objects

static PyObject* py_glAttachObjectARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Handle, Handle >::Call(self, args, glAttachObjectARB);
}
static PyObject* py_glCompileShaderARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Handle >::Call(self, args, glCompileShaderARB);
}
static PyObject* py_glCreateProgramObjectARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 0);
  GLhandleARB handle = glCreateProgramObjectARB();
  return PyInt_FromLong(handle);
}
static PyObject* py_glCreateShaderObjectARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum type(PyTuple_GetItem(args, 0));
  GLhandleARB handle = glCreateShaderObjectARB(type);
  return PyInt_FromLong(handle);
}
static PyObject* py_glDeleteObjectARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Handle >::Call(self, args, glDeleteObjectARB);
}
static PyObject* py_glDetachObjectARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Handle, Handle >::Call(self, args, glDetachObjectARB);
}
static PyObject* py_glUseProgramObjectARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Handle >::Call(self, args, glUseProgramObjectARB);
}
static PyObject* py_glValidateProgramARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Handle >::Call(self, args, glValidateProgramARB);
}
static PyObject* py_glLinkProgramARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Handle >::Call(self, args, glLinkProgramARB);
}
static PyObject* py_glUniform1fARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Float >::Call(self, args, glUniform1fARB);
}
static PyObject* py_glUniform1iARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int >::Call(self, args, glUniform1iARB);
}
static PyObject* py_glUniform2fARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Float, Float >::Call(self, args, glUniform2fARB);
}
static PyObject* py_glUniform2iARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int >::Call(self, args, glUniform2iARB);
}
static PyObject* py_glUniform3fARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Float, Float, Float >::Call(self, args, glUniform3fARB);
}
static PyObject* py_glUniform3iARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Int, Int, Int >::Call(self, args, glUniform3iARB);
}
static PyObject* py_glUniform4fARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Int, Float, Float, Float, Float >::Call(self, args, glUniform4fARB);
}
static PyObject* py_glUniform4iARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Int, Int, Int, Int, Int >::Call(self, args, glUniform4iARB);
}
static PyObject* py_glUniform1fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform1fvARB);
}
static PyObject* py_glUniform1ivARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform1ivARB);
}
static PyObject* py_glUniform2fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform2fvARB);
}
static PyObject* py_glUniform2ivARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform2ivARB);
}
static PyObject* py_glUniform3fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform3fvARB);
}
static PyObject* py_glUniform3ivARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform3ivARB);
}
static PyObject* py_glUniform4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Float> >::Call(self, args, glUniform4fvARB);
}
static PyObject* py_glUniform4ivARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Sizei, ConstArray<Int> >::Call(self, args, glUniform4ivARB);
}
static PyObject* py_glUniformMatrix2fvARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix2fvARB);
}
static PyObject* py_glUniformMatrix3fvARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix3fvARB);
}
static PyObject* py_glUniformMatrix4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Sizei, Boolean, ConstArray<Float> >::Call(self, args, glUniformMatrix4fvARB);
}
static PyObject* py_glGetHandleARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum pname(PyTuple_GetItem(args, 0));
  GLhandleARB handle = glGetHandleARB(pname);
  return PyInt_FromLong(handle);
}
static PyObject* py_glGetUniformLocationARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle prog(PyTuple_GetItem(args, 0));
  String name(PyTuple_GetItem(args, 1));
  GLint loc = glGetUniformLocationARB(prog, name);
  return PyInt_FromLong(loc);
}
static PyObject* py_glShaderSourceARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle obj(PyTuple_GetItem(args, 0));
  Array1D<String> string(PyTuple_GetItem(args, 2));
  glShaderSourceARB(obj, string.size(), string, 0);
  Py_RETURN_NONE;
}
static PyObject* py_glGetUniformARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle prog(PyTuple_GetItem(args, 0));
  Int loc(PyTuple_GetItem(args, 1));
  GLchar dummy;
  GLint count;
  GLenum type;
  glGetActiveUniformARB(prog, loc, 0, 0, &count, &type, &dummy);
  bool integer = false;
  int dim = 0;
  switch (type) {
    case GL_INT:
    case GL_BOOL_ARB:
    case GL_SAMPLER_1D_ARB:
    case GL_SAMPLER_2D_ARB:
    case GL_SAMPLER_3D_ARB:
    case GL_SAMPLER_CUBE_ARB:
    case GL_SAMPLER_1D_SHADOW_ARB:
    case GL_SAMPLER_2D_SHADOW_ARB:
    case GL_SAMPLER_2D_RECT_ARB:
    case GL_SAMPLER_2D_RECT_SHADOW_ARB:
      integer = true;
      dim = 1;
      break;
    case GL_INT_VEC2_ARB:
    case GL_BOOL_VEC2_ARB:
      integer = true;
      dim = 2;
      break;
    case GL_INT_VEC3_ARB:
    case GL_BOOL_VEC3_ARB:
      integer = true;
      dim = 3;
      break;
    case GL_INT_VEC4_ARB:
    case GL_BOOL_VEC4_ARB:
      integer = true;
      dim = 4;
      break;
    case GL_FLOAT:
      dim = 1;
      break;
    case GL_FLOAT_VEC2_ARB:
      dim = 2;
      break;
    case GL_FLOAT_VEC3_ARB:
      dim = 3;
      break;
    case GL_FLOAT_VEC4_ARB:
    case GL_FLOAT_MAT2_ARB:
      dim = 4;
      break;
    case GL_FLOAT_MAT3_ARB:
      dim = 9;
      break;
    case GL_FLOAT_MAT4_ARB:
      dim = 16;
      break;
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetUniformARB: unsupported uniform type");
      return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetUniformivARB(prog, loc, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetUniformfvARB(prog, loc, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  };
}
static PyObject* py_glGetActiveUniformARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle obj(PyTuple_GetItem(args, 0));
  Uint idx(PyTuple_GetItem(args, 1));
  GLint len;
  GLint size;
  GLenum type;  
  glGetObjectParameterivARB(obj, GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB, &len);
  Array1D<Char> name(len+1);
  glGetActiveUniformARB(obj, idx, len, 0, &size, &type, name);
  PyObject *rv = PyTuple_New(3);
  PyTuple_SetItem(rv, 0, PyInt_FromLong(size));
  PyTuple_SetItem(rv, 1, PyInt_FromLong(type));
  PyTuple_SetItem(rv, 2, PyString_FromString(name));
  return rv;
}
static PyObject* py_glGetAttachedObjectsARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Handle obj(PyTuple_GetItem(args, 0));
  GLint len = 0;
  glGetObjectParameterivARB(obj, GL_OBJECT_ATTACHED_OBJECTS_ARB, &len);
  if (len == 0) {
    return PyList_New(0);
  } else {
    Array1D<Handle> handles(len);
    glGetAttachedObjectsARB(obj, len, 0, handles);
    return handles.toPy();
  }
}
static PyObject* py_glGetObjectParameterARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle obj(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  int dim = 0;
  bool integer = false;
  switch (pname) {
    case GL_OBJECT_TYPE_ARB:
    case GL_OBJECT_SUBTYPE_ARB:
    case GL_OBJECT_DELETE_STATUS_ARB:
    case GL_OBJECT_COMPILE_STATUS_ARB:
    case GL_OBJECT_LINK_STATUS_ARB:
    case GL_OBJECT_VALIDATE_STATUS_ARB:
    case GL_OBJECT_INFO_LOG_LENGTH_ARB:
    case GL_OBJECT_SHADER_SOURCE_LENGTH_ARB:
    case GL_OBJECT_ATTACHED_OBJECTS_ARB:
    case GL_OBJECT_ACTIVE_UNIFORMS_ARB:
    case GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB:
    case GL_OBJECT_ACTIVE_ATTRIBUTES_ARB: // ARB_vertex_shader
    case GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB: // ARB_vertex_shader
      integer = true;
      dim = 1;
      break;
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetObjectParameterARB: invalid parameter name");
      return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetObjectParameterivARB(obj, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetObjectParameterfvARB(obj, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}
static PyObject* py_glGetInfoLogARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Handle obj(PyTuple_GetItem(args, 0));
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_INFO_LOG_LENGTH_ARB, &len);
  Array1D<Char> log(len+1);
  glGetInfoLogARB(obj, len, 0, log);
  return PyString_FromString(log);
}
static PyObject* py_glGetShaderSourceARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Handle obj(PyTuple_GetItem(args, 0));
  GLint len=0;
  glGetObjectParameterivARB(obj, GL_OBJECT_SHADER_SOURCE_LENGTH_ARB, &len);
  Array1D<Char> src(len+1);
  glGetShaderSourceARB(obj, len, 0, src);
  return PyString_FromString(src);
}

// GL_ARB_texture_compression

static PyObject* py_glCompressedTexImage1DARB(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Enum, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage1D);
}
static PyObject* py_glCompressedTexImage2DARB(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Int, Enum, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage2D);
}
static PyObject* py_glCompressedTexImage3DARB(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Enum, Sizei, Sizei, Sizei, Int, Sizei, ConstPtr >::Call(self, args, glCompressedTexImage3D);
}
static PyObject* py_glCompressedTexSubImage1DARB(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Int, Int, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage1D);
}
static PyObject* py_glCompressedTexSubImage2DARB(PyObject *self, PyObject *args) {
  return WrapFunc9<Enum, Int, Int, Int, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage2D);
}
static PyObject* py_glCompressedTexSubImage3DARB(PyObject *self, PyObject *args) {
  return WrapFunc11<Enum, Int, Int, Int, Int, Sizei, Sizei, Sizei, Enum, Sizei, ConstPtr >::Call(self, args, glCompressedTexSubImage3D);
}
static PyObject* py_glGetCompressedTexImageARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Int, Ptr >::Call(self, args, glGetCompressedTexImageARB);
}

// GL_ARB_transpose_matrix

static PyObject* py_glLoadTransposeMatrixdARB(PyObject *self, PyObject *args) {
  // WrapFunc1<CheckSize<Array<Double>, 16>, glLoadTransposeMatrixdARB>::Call(self, args);
  return WrapFunc1<Array<Double> >::Call(self, args, glLoadTransposeMatrixdARB);
}
static PyObject* py_glLoadTransposeMatrixfARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Array<Float> >::Call(self, args, glLoadTransposeMatrixfARB);
}
static PyObject* py_glMultTransposeMatrixdARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Array<Double> >::Call(self, args, glMultTransposeMatrixdARB);
}
static PyObject* py_glMultTransposeMatrixfARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Array<Float> >::Call(self, args, glMultTransposeMatrixfARB);
}

// GL_ARB_vertex_weight

static PyObject* py_glVertexBlendARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Int >::Call(self, args, glVertexBlendARB);
}
static PyObject* py_glWeightPointerARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Int, Enum, Sizei, Ptr >::Call(self, args, glWeightPointerARB);
}
static PyObject* py_glWeightbvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Byte> weights(PyTuple_GetItem(args, 0));
  glWeightbvARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightdvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Double> weights(PyTuple_GetItem(args, 0));
  glWeightdvARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightfvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Float> weights(PyTuple_GetItem(args, 0));
  glWeightfvARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightivARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Int> weights(PyTuple_GetItem(args, 0));
  glWeightivARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightsvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Short> weights(PyTuple_GetItem(args, 0));
  glWeightsvARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightubvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Ubyte> weights(PyTuple_GetItem(args, 0));
  glWeightubvARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightuivARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> weights(PyTuple_GetItem(args, 0));
  glWeightuivARB(weights.size(), weights);
  Py_RETURN_NONE;
}
static PyObject* py_glWeightusvARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Ushort> weights(PyTuple_GetItem(args, 0));
  glWeightusvARB(weights.size(), weights);
  Py_RETURN_NONE;
}

// GL_ARB_vertex_buffer_object

static PyObject* py_glBindBufferARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glBindBufferARB);
}
static PyObject* py_glBufferDataARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Sizeiptr, ConstPtr, Enum >::Call(self, args, glBufferDataARB);
}
static PyObject* py_glBufferSubDataARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, ConstPtr >::Call(self, args, glBufferSubDataARB);
}
static PyObject* py_glDeleteBuffersARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> buffers(PyTuple_GetItem(args, 0));
  glDeleteBuffersARB(buffers.size(), buffers);
  Py_RETURN_NONE;
}
static PyObject* py_glGenBuffersARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> buffers(n);
  glGenBuffersARB(n, buffers);
  return buffers.toPy();
}
static PyObject* py_glIsBufferARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint buffer(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsBufferARB(buffer) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}
static PyObject* py_glMapBufferARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum access(PyTuple_GetItem(args, 1));
  return PyCObject_FromVoidPtr(glMapBufferARB(target, access), NULL);
}
static PyObject* py_glUnmapBufferARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum target(PyTuple_GetItem(args, 0));
  PyObject *rv = (glUnmapBufferARB(target) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}
static PyObject* py_glGetBufferPointerARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLvoid *ptr;
  glGetBufferPointervARB(target, pname, &ptr);
  return PyCObject_FromVoidPtr(ptr, NULL);
}
static PyObject* py_glGetBufferSubDataARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, Ptr >::Call(self, args, glGetBufferSubDataARB);
}
static PyObject* py_glGetBufferParameterARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  int dim = 0;
  switch (pname) {
    case GL_BUFFER_SIZE_ARB:
    case GL_BUFFER_USAGE_ARB:
    case GL_BUFFER_ACCESS_ARB:
    case GL_BUFFER_MAPPED_ARB:
      dim = 1;
      break;
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetBufferParameter: invalid parameter name");
      return NULL;
  }
  Array1D<Int> values(dim);
  glGetBufferParameterivARB(target, pname, values);
  if (dim == 1) {
    return PyInt_FromLong(values[0]);
  } else {
    return values.toPy();
  }
}

// GL_ARB_vertex_program

static PyObject* py_glBindProgramARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glBindProgramARB);
}
static PyObject* py_glDeleteProgramsARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> progs(PyTuple_GetItem(args, 0));
  glDeleteProgramsARB(progs.size(), progs);
  Py_RETURN_NONE;
}
static PyObject* py_glDisableVertexAttribArrayARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glDisableVertexAttribArrayARB);
}
static PyObject* py_glEnableVertexAttribArrayARB(PyObject *self, PyObject *args) {
  return WrapFunc1<Uint >::Call(self, args, glEnableVertexAttribArrayARB);
}
static PyObject* py_glGenProgramsARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> progs(n);
  glGenProgramsARB(n, progs);
  return progs.toPy();
}
static PyObject* py_glGetProgramEnvParameterARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Uint index(PyTuple_GetItem(args, 1));
  Array1D<Double> values(4);
  glGetProgramEnvParameterdvARB(target, index, values);
  return values.toPy();
}
static PyObject* py_glGetProgramLocalParameterARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Uint index(PyTuple_GetItem(args, 1));
  Array1D<Double> values(4);
  glGetProgramLocalParameterdvARB(target, index, values);
  return values.toPy();
}
static PyObject* py_glGetProgramARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  int dim = 0;
  switch (pname) {
    case GL_PROGRAM_BINDING_ARB:
    case GL_PROGRAM_LENGTH_ARB:
    case GL_PROGRAM_FORMAT_ARB:
    case GL_PROGRAM_INSTRUCTIONS_ARB:
    case GL_PROGRAM_TEMPORARIES_ARB:
    case GL_PROGRAM_PARAMETERS_ARB:
    case GL_PROGRAM_ATTRIBS_ARB:
    case GL_PROGRAM_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB:
    case GL_PROGRAM_NATIVE_TEMPORARIES_ARB:
    case GL_PROGRAM_NATIVE_PARAMETERS_ARB:
    case GL_PROGRAM_NATIVE_ATTRIBS_ARB:
    case GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB:
    case GL_MAX_PROGRAM_ENV_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_INSTRUCTIONS_ARB:
    case GL_MAX_PROGRAM_TEMPORARIES_ARB:
    case GL_MAX_PROGRAM_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_ATTRIBS_ARB:
    case GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB:
    case GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB:
    case GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB:
    case GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB:
    case GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB:
    case GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB:
    case GL_PROGRAM_ALU_INSTRUCTIONS_ARB: // ARB_fragment_program
    case GL_PROGRAM_TEX_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_TEX_INDIRECTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB: // "
    case GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB: // "
    case GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB: // "
    case GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB: // "
      dim = 1;
      break;
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetProgramARB: invalid parameter name");
      return NULL;
  }
  Array1D<Int> values(dim);
  glGetProgramivARB(target, pname, values);
  if (dim == 1) {
    return PyInt_FromLong(values[0]);
  } else {
    return values.toPy();
  }
}
static PyObject* py_glGetProgramStringARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLint len;
  glGetProgramiv(target, GL_PROGRAM_LENGTH_ARB, &len);
  Array1D<Char> str(len+1);
  glGetProgramStringARB(target, pname, str);
  return PyString_FromString(str);
}
static PyObject* py_glIsProgramARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint program(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsProgramARB(program) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}
static PyObject* py_glProgramEnvParameter4dARB(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double >::Call(self, args, glProgramEnvParameter4dARB);
}
static PyObject* py_glProgramEnvParameter4dvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Uint, ConstArray<Double> >::Call(self, args, glProgramEnvParameter4dvARB);
}
static PyObject* py_glProgramEnvParameter4fARB(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float >::Call(self, args, glProgramEnvParameter4fARB);
}
static PyObject* py_glProgramEnvParameter4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Uint, ConstArray<Float> >::Call(self, args, glProgramEnvParameter4fvARB);
}
static PyObject* py_glProgramLocalParameter4dARB(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Uint, Double, Double, Double, Double >::Call(self, args, glProgramLocalParameter4dARB);
}
static PyObject* py_glProgramLocalParameter4dvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Uint, ConstArray<Double> >::Call(self, args, glProgramLocalParameter4dvARB);
}
static PyObject* py_glProgramLocalParameter4fARB(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Uint, Float, Float, Float, Float >::Call(self, args, glProgramLocalParameter4fARB);
}
static PyObject* py_glProgramLocalParameter4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Uint, ConstArray<Float> >::Call(self, args, glProgramLocalParameter4fvARB);
}
static PyObject* py_glProgramStringARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 3);
  Enum target(PyTuple_GetItem(args, 0));
  Enum format(PyTuple_GetItem(args, 1));
  String string(PyTuple_GetItem(args, 2));
  GLsizei len = (GLsizei) strlen(string);
  glProgramStringARB(target, format, len, string);
  Py_RETURN_NONE;
}
static PyObject* py_glVertexAttrib1dARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Double >::Call(self, args, glVertexAttrib1dARB);
}
static PyObject* py_glVertexAttrib2dARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Double, Double >::Call(self, args, glVertexAttrib2dARB);
}
static PyObject* py_glVertexAttrib2dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib2dvARB);
}
static PyObject* py_glVertexAttrib3dARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Double, Double, Double >::Call(self, args, glVertexAttrib3dARB);
}
static PyObject* py_glVertexAttrib3dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib3dvARB);
}
static PyObject* py_glVertexAttrib4dARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Double, Double, Double, Double >::Call(self, args, glVertexAttrib4dARB);
}
static PyObject* py_glVertexAttrib4dvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Double> >::Call(self, args, glVertexAttrib4dvARB);
}
static PyObject* py_glVertexAttrib1fARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Float >::Call(self, args, glVertexAttrib1fARB);
}
static PyObject* py_glVertexAttrib2fARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Float, Float >::Call(self, args, glVertexAttrib2fARB);
}
static PyObject* py_glVertexAttrib2fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib2fvARB);
}
static PyObject* py_glVertexAttrib3fARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Float, Float, Float >::Call(self, args, glVertexAttrib3fARB);
}
static PyObject* py_glVertexAttrib3fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib3fvARB);
}
static PyObject* py_glVertexAttrib4fARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Float, Float, Float, Float >::Call(self, args, glVertexAttrib4fARB);
}
static PyObject* py_glVertexAttrib4fvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Float> >::Call(self, args, glVertexAttrib4fvARB);
}
static PyObject* py_glVertexAttrib1sARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, Short >::Call(self, args, glVertexAttrib1sARB);
}
static PyObject* py_glVertexAttrib2sARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Uint, Short, Short >::Call(self, args, glVertexAttrib2sARB);
}
static PyObject* py_glVertexAttrib2svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib2svARB);
}
static PyObject* py_glVertexAttrib3sARB(PyObject *self, PyObject *args) {
  return WrapFunc4<Uint, Short, Short, Short >::Call(self, args, glVertexAttrib3sARB);
}
static PyObject* py_glVertexAttrib3svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib3svARB);
}
static PyObject* py_glVertexAttrib4sARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Short, Short, Short, Short >::Call(self, args, glVertexAttrib4sARB);
}
static PyObject* py_glVertexAttrib4svARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib4svARB);
}
static PyObject* py_glVertexAttrib4NbvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(self, args, glVertexAttrib4NbvARB);
}
static PyObject* py_glVertexAttrib4NivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Int> >::Call(self, args, glVertexAttrib4NivARB);
}
static PyObject* py_glVertexAttrib4NsvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Short> >::Call(self, args, glVertexAttrib4NsvARB);
}
static PyObject* py_glVertexAttrib4NubvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(self, args, glVertexAttrib4NubvARB);
}
static PyObject* py_glVertexAttrib4NuivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(self, args, glVertexAttrib4NuivARB);
}
static PyObject* py_glVertexAttrib4NusvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(self, args, glVertexAttrib4NusvARB);
}
static PyObject* py_glVertexAttrib4bvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Byte> >::Call(self, args, glVertexAttrib4bvARB);
}
static PyObject* py_glVertexAttrib4ivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Int> >::Call(self, args, glVertexAttrib4ivARB);
}
static PyObject* py_glVertexAttrib4ubvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ubyte> >::Call(self, args, glVertexAttrib4ubvARB);
}
static PyObject* py_glVertexAttrib4uivARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Uint> >::Call(self, args, glVertexAttrib4uivARB);
}
static PyObject* py_glVertexAttrib4usvARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Uint, ConstArray<Ushort> >::Call(self, args, glVertexAttrib4usvARB);
}
static PyObject* py_glVertexAttrib4NubARB(PyObject *self, PyObject *args) {
  return WrapFunc5<Uint, Ubyte, Ubyte, Ubyte, Ubyte >::Call(self, args, glVertexAttrib4NubARB);
}
static PyObject* py_glVertexAttribPointerARB(PyObject *self, PyObject *args) {
  return WrapFunc6<Uint, Int, Enum, Boolean, Sizei, ConstPtr >::Call(self, args, glVertexAttribPointerARB);
}
static PyObject* py_glGetVertexAttribPointerARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint index(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLvoid *ptr;
  glGetVertexAttribPointervARB(index, pname, &ptr);
  return PyCObject_FromVoidPtr(ptr, NULL);
}
static PyObject* py_glGetVertexAttribARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Uint index(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  int dim = 0;
  bool integer = false;
  switch (pname) {
    case GL_CURRENT_VERTEX_ATTRIB_ARB:
      dim = 4;
      break;
    case GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB:
    case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB: // requires: ARB_vertex_buffer_object
      integer = true;
      dim = 1;
      break;
    default:
      PyErr_SetString(PyExc_RuntimeError, "gl.GetVertexAttribARB: invalid parameter name");
      return NULL;
  }
  if (integer) {
    Array1D<Int> values;
    glGetVertexAttribivARB(index, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Double> values;
    glGetVertexAttribdvARB(index, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}

// GL_ARB_vertex_shader

static PyObject* py_glBindAttribLocationARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Handle, Uint, String >::Call(self, args, glBindAttribLocationARB);
}
static PyObject* py_glGetActiveAttribARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle obj(PyTuple_GetItem(args, 0));
  Uint index(PyTuple_GetItem(args, 1));
  GLint len = 0;
  glGetObjectParameterivARB(obj, GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB, &len);
  GLint size;
  GLenum type;
  Array1D<Char> name(len+1);
  glGetActiveAttribARB(obj, index, len, 0, &size, &type, name);
  PyObject *rv = PyTuple_New(3);
  PyTuple_SetItem(rv, 0, PyInt_FromLong(size));
  PyTuple_SetItem(rv, 1, PyInt_FromLong(type));
  PyTuple_SetItem(rv, 2, PyString_FromString(name));
  return rv;
}
static PyObject* py_glGetAttribLocationARB(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Handle obj(PyTuple_GetItem(args, 0));
  String name(PyTuple_GetItem(args, 1));
  return PyInt_FromLong(glGetAttribLocationARB(obj, name));
}

// GL_ARB_window_pos

static PyObject* py_glWindowPos2dARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Double, Double >::Call(self, args, glWindowPos2dARB);
}
static PyObject* py_glWindowPos2dvARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glWindowPos2dvARB);
}
static PyObject* py_glWindowPos3dARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Double, Double, Double >::Call(self, args, glWindowPos3dARB);
}
static PyObject* py_glWindowPos3dvARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Double> >::Call(self, args, glWindowPos3dvARB);
}
static PyObject* py_glWindowPos2fARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Float, Float >::Call(self, args, glWindowPos2fARB);
}
static PyObject* py_glWindowPos2fvARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glWindowPos2fvARB);
}
static PyObject* py_glWindowPos3fARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Float, Float, Float >::Call(self, args, glWindowPos3fARB);
}
static PyObject* py_glWindowPos3fvARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Float> >::Call(self, args, glWindowPos3fvARB);
}
static PyObject* py_glWindowPos2iARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Int, Int >::Call(self, args, glWindowPos2iARB);
}
static PyObject* py_glWindowPos2ivARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glWindowPos2ivARB);
}
static PyObject* py_glWindowPos3iARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Int, Int, Int >::Call(self, args, glWindowPos3iARB);
}
static PyObject* py_glWindowPos3ivARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Int> >::Call(self, args, glWindowPos3ivARB);
}
static PyObject* py_glWindowPos2sARB(PyObject *self, PyObject *args) {
  return WrapFunc2<Short, Short >::Call(self, args, glWindowPos2sARB);
}
static PyObject* py_glWindowPos2svARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glWindowPos2svARB);
}
static PyObject* py_glWindowPos3sARB(PyObject *self, PyObject *args) {
  return WrapFunc3<Short, Short, Short >::Call(self, args, glWindowPos3sARB);
}
static PyObject* py_glWindowPos3svARB(PyObject *self, PyObject *args) {
  return WrapFunc1<ConstArray<Short> >::Call(self, args, glWindowPos3svARB);
}

// GL_ARB_imaging

static PyObject* py_glColorSubTable(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Sizei, Sizei, Enum, Enum, ConstPtr >::Call(self, args, glColorSubTable);
}
static PyObject* py_glColorTable(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr >::Call(self, args, glColorTable);
}
static PyObject* py_glColorTableParameterfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glColorTableParameterfv);
}
static PyObject* py_glColorTableParameteriv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glColorTableParameteriv);
}
static PyObject* py_glConvolutionFilter1D(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Enum, Sizei, Enum, Enum, ConstPtr >::Call(self, args, glConvolutionFilter1D);
}
static PyObject* py_glConvolutionFilter2D(PyObject *self, PyObject *args) {
  return WrapFunc7<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr >::Call(self, args, glConvolutionFilter2D);
}
static PyObject* py_glConvolutionParameterf(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Float >::Call(self, args, glConvolutionParameterf);
}
static PyObject* py_glConvolutionParameterfv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Float> >::Call(self, args, glConvolutionParameterfv);
}
static PyObject* py_glConvolutionParameteri(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Int >::Call(self, args, glConvolutionParameteri);
}
static PyObject* py_glConvolutionParameteriv(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, ConstArray<Int> >::Call(self, args, glConvolutionParameteriv);
}
static PyObject* py_glCopyColorSubTable(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Sizei, Int, Int, Sizei >::Call(self, args, glCopyColorSubTable);
}
static PyObject* py_glCopyColorTable(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Enum, Int, Int, Sizei >::Call(self, args, glCopyColorTable);
}
static PyObject* py_glCopyConvolutionFilter1D(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Enum, Int, Int, Sizei >::Call(self, args, glCopyConvolutionFilter1D);
}
static PyObject* py_glCopyConvolutionFilter2D(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Enum, Int, Int, Sizei, Sizei >::Call(self, args, glCopyConvolutionFilter2D);
}
static PyObject* py_glGetColorTable(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Enum, Enum, Ptr >::Call(self, args, glGetColorTable);
}
static PyObject* py_glGetColorTableParameter(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_COLOR_TABLE_FORMAT:
    case GL_COLOR_TABLE_WIDTH:
    case GL_COLOR_TABLE_RED_SIZE:
    case GL_COLOR_TABLE_GREEN_SIZE:
    case GL_COLOR_TABLE_BLUE_SIZE:
    case GL_COLOR_TABLE_ALPHA_SIZE:
    case GL_COLOR_TABLE_LUMINANCE_SIZE:
    case GL_COLOR_TABLE_INTENSITY_SIZE:
      integer = true;
      dim = 1;
      break;
    case GL_COLOR_TABLE_SCALE:
    case GL_COLOR_TABLE_BIAS:
      dim = 4;
      break;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetColorTableParameter: invalid parameter name");
    return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetColorTableParameteriv(target, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetColorTableParameterfv(target, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}
static PyObject* py_glGetConvolutionFilter(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Enum, Enum, Ptr >::Call(self, args, glGetConvolutionFilter);
}
static PyObject* py_glGetConvolutionParameter(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_CONVOLUTION_BORDER_MODE:
    case GL_CONVOLUTION_FORMAT:
    case GL_CONVOLUTION_WIDTH:
    case GL_CONVOLUTION_HEIGHT:
    case GL_MAX_CONVOLUTION_WIDTH:
    case GL_MAX_CONVOLUTION_HEIGHT:
      integer = true;
      dim = 1;
      break;
    case GL_CONVOLUTION_BORDER_COLOR:
    case GL_CONVOLUTION_FILTER_SCALE:
    case GL_CONVOLUTION_FILTER_BIAS:
      dim = 4;
      break;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetConvolutionParameter: invalid parameter name");
    return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetConvolutionParameteriv(target, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetConvolutionParameterfv(target, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}
static PyObject* py_glGetHistogram(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr >::Call(self, args, glGetHistogram);
}
static PyObject* py_glGetHistogramParameter(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_HISTOGRAM_WIDTH:
    case GL_HISTOGRAM_FORMAT:
    case GL_HISTOGRAM_RED_SIZE:
    case GL_HISTOGRAM_GREEN_SIZE:
    case GL_HISTOGRAM_BLUE_SIZE:
    case GL_HISTOGRAM_ALPHA_SIZE:
    case GL_HISTOGRAM_LUMINANCE_SIZE:
    case GL_HISTOGRAM_SINK:
      integer = true;
      dim = 1;
      break;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetHistogramParameter: invalid parameter name");
    return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetHistogramParameteriv(target, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetHistogramParameterfv(target, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}
static PyObject* py_glGetMinmax(PyObject *self, PyObject *args) {
  return WrapFunc5<Enum, Boolean, Enum, Enum, Ptr >::Call(self, args, glGetMinmax);
}
static PyObject* py_glGetMinmaxParameter(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  bool integer = false;
  int dim = 0;
  switch (pname) {
    case GL_MINMAX_FORMAT:
    case GL_MINMAX_SINK:
      integer = true;
      dim = 1;
      break;
    default:
      break;
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetMinmaxParameter: invalid parameter name");
    return NULL;
  }
  if (integer) {
    Array1D<Int> values(dim);
    glGetMinmaxParameteriv(target, pname, values);
    if (dim == 1) {
      return PyInt_FromLong(values[0]);
    } else {
      return values.toPy();
    }
  } else {
    Array1D<Float> values(dim);
    glGetMinmaxParameterfv(target, pname, values);
    if (dim == 1) {
      return PyFloat_FromDouble(values[0]);
    } else {
      return values.toPy();
    }
  }
}
static PyObject* py_glGetSeparableFilter(PyObject *self, PyObject *args) {
  return WrapFunc6<Enum, Enum, Enum, Ptr, Ptr, Ptr >::Call(self, args, glGetSeparableFilter);
}
static PyObject* py_glHistogram(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Sizei, Enum, Boolean >::Call(self, args, glHistogram);
}
static PyObject* py_glMinmax(PyObject *self, PyObject *args) {
  return WrapFunc3<Enum, Enum, Boolean >::Call(self, args, glMinmax);
}
static PyObject* py_glResetHistogram(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glResetHistogram);
}
static PyObject* py_glResetMinmax(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glResetMinmax);
}
static PyObject* py_glSeparableFilter2D(PyObject *self, PyObject *args) {
  return WrapFunc8<Enum, Enum, Sizei, Sizei, Enum, Enum, ConstPtr, ConstPtr >::Call(self, args, glSeparableFilter2D);
}

// Register constants and functions to LUA

void Register_GL_ARB_Constants(PyGL::ConstantMap &constants) {
  PyGL &gl = PyGL::Instance();

  if (GLEW_ARB_color_buffer_float) {
#ifdef _DEBUG
    std::cout << "Supports ARB color buffer float" << std::endl;
#endif
    constants["ARB_color_buffer_float"] = 1;
    constants["RGBA_FLOAT_MODE_ARB"] = GL_RGBA_FLOAT_MODE_ARB;
    constants["CLAMP_VERTEX_COLOR_ARB"] = GL_CLAMP_VERTEX_COLOR_ARB;
    constants["CLAMP_FRAGMENT_COLOR_ARB"] = GL_CLAMP_FRAGMENT_COLOR_ARB;
    constants["CLAMP_READ_COLOR_ARB"] = GL_CLAMP_READ_COLOR_ARB;
    constants["FIXED_ONLY_ARB"] = GL_FIXED_ONLY_ARB;
    gl.addParamDim(PyGL::Integerv, GL_CLAMP_VERTEX_COLOR_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_CLAMP_FRAGMENT_COLOR_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_CLAMP_READ_COLOR_ARB, 1);
    gl.addParamDim(PyGL::Booleanv, GL_RGBA_FLOAT_MODE_ARB, 1);
  } else {
    constants["ARB_color_buffer_float"] = 0;
  }

  if (GLEW_ARB_depth_texture) {
#ifdef _DEBUG
    std::cout << "Supports ARB depth texture" << std::endl;
#endif
    constants["ARB_depth_texture"] = 1;
    constants["DEPTH_COMPONENT16_ARB"] = GL_DEPTH_COMPONENT16_ARB;
    constants["DEPTH_COMPONENT24_ARB"] = GL_DEPTH_COMPONENT24_ARB;
    constants["DEPTH_COMPONENT32_ARB"] = GL_DEPTH_COMPONENT32_ARB;
    constants["TEXTURE_DEPTH_SIZE_ARB"] = GL_TEXTURE_DEPTH_SIZE_ARB;
    constants["DEPTH_TEXTURE_MODE_ARB"] = GL_DEPTH_TEXTURE_MODE_ARB;
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_SIZE_ARB, 1);
    gl.addParamDim(PyGL::TexParameteriv, GL_DEPTH_TEXTURE_MODE_ARB, 1);
  } else {
    constants["ARB_depth_texture"] = 0;
  }

  if (GLEW_ARB_draw_buffers) {
#ifdef _DEBUG
    std::cout << "Supports ARB draw buffers" << std::endl;
#endif
    constants["ARB_draw_buffers"] = 1;
    constants["MAX_DRAW_BUFFERS_ARB"] = GL_MAX_DRAW_BUFFERS_ARB;
    constants["DRAW_BUFFER0_ARB"] = GL_DRAW_BUFFER0_ARB;
    constants["DRAW_BUFFER1_ARB"] = GL_DRAW_BUFFER1_ARB;
    constants["DRAW_BUFFER2_ARB"] = GL_DRAW_BUFFER2_ARB;
    constants["DRAW_BUFFER3_ARB"] = GL_DRAW_BUFFER3_ARB;
    constants["DRAW_BUFFER4_ARB"] = GL_DRAW_BUFFER4_ARB;
    constants["DRAW_BUFFER5_ARB"] = GL_DRAW_BUFFER5_ARB;
    constants["DRAW_BUFFER6_ARB"] = GL_DRAW_BUFFER6_ARB;
    constants["DRAW_BUFFER7_ARB"] = GL_DRAW_BUFFER7_ARB;
    constants["DRAW_BUFFER8_ARB"] = GL_DRAW_BUFFER8_ARB;
    constants["DRAW_BUFFER9_ARB"] = GL_DRAW_BUFFER9_ARB;
    constants["DRAW_BUFFER10_ARB"] = GL_DRAW_BUFFER10_ARB;
    constants["DRAW_BUFFER11_ARB"] = GL_DRAW_BUFFER11_ARB;
    constants["DRAW_BUFFER12_ARB"] = GL_DRAW_BUFFER12_ARB;
    constants["DRAW_BUFFER13_ARB"] = GL_DRAW_BUFFER13_ARB;
    constants["DRAW_BUFFER14_ARB"] = GL_DRAW_BUFFER14_ARB;
    constants["DRAW_BUFFER15_ARB"] = GL_DRAW_BUFFER15_ARB;
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER0_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER1_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER2_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER3_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER4_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER5_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER6_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER7_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER8_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER9_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER10_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER11_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER12_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER13_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER14_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_DRAW_BUFFER15_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_DRAW_BUFFERS_ARB, 1);
  } else {
    constants["ARB_draw_buffers"] = 0;
  }

  if (GLEW_ARB_fragment_program) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment program" << std::endl;
#endif
    constants["ARB_fragment_program"] = 1;
    constants["FRAGMENT_PROGRAM_ARB"] = GL_FRAGMENT_PROGRAM_ARB;
    constants["PROGRAM_ALU_INSTRUCTIONS_ARB"] = GL_PROGRAM_ALU_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEX_INSTRUCTIONS_ARB"] = GL_PROGRAM_TEX_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEX_INDIRECTIONS_ARB"] = GL_PROGRAM_TEX_INDIRECTIONS_ARB;
    constants["PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB"] = GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB;
    constants["MAX_PROGRAM_ALU_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_TEX_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_TEX_INDIRECTIONS_ARB"] = GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB;
    constants["MAX_TEXTURE_COORDS_ARB"] = GL_MAX_TEXTURE_COORDS_ARB;
    constants["MAX_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_TEXTURE_IMAGE_UNITS_ARB;
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_COORDS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_IMAGE_UNITS_ARB, 1);
  } else {
    constants["ARB_fragment_program"] = 0;
  }

  if (GLEW_ARB_fragment_program_shadow) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment program shadow" << std::endl;
#endif
    constants["ARB_fragment_program_shadow"] = 1;
  } else {
    constants["ARB_fragment_program_shadow"] = 0;
  }

  if (GLEW_ARB_fragment_shader) {
#ifdef _DEBUG
    std::cout << "Supports ARB fragment shader" << std::endl;
#endif
    constants["ARB_fragment_shader"] = 1;
    constants["FRAGMENT_SHADER_ARB"] = GL_FRAGMENT_SHADER_ARB;
    constants["MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB"] = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB;
    constants["FRAGMENT_SHADER_DERIVATIVE_HINT_ARB"] = GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB;
    gl.addParamDim(PyGL::Integerv, GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB, 1);
  } else {
    constants["ARB_fragment_shader"] = 0;
  }

  if (GLEW_ARB_half_float_pixel) {
#ifdef _DEBUG
    std::cout << "Supports ARB half float pixel" << std::endl;
#endif
    constants["ARB_half_float_pixel"] = 1;
    constants["HALF_FLOAT_ARB"] = GL_HALF_FLOAT_ARB;
  } else {
    constants["ARB_half_float_pixel"] = 0;
  }

  if (GLEW_ARB_matrix_palette) {
#ifdef _DEBUG
    std::cout << "Supports ARB matrix palette" << std::endl;
#endif
    constants["ARB_matrix_palette"] = 1;
    constants["MATRIX_PALETTE_ARB"] = GL_MATRIX_PALETTE_ARB;
    constants["MAX_MATRIX_PALETTE_STACK_DEPTH_ARB"] = GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB;
    constants["MAX_PALETTE_MATRICES_ARB"] = GL_MAX_PALETTE_MATRICES_ARB;
    constants["CURRENT_PALETTE_MATRIX_ARB"] = GL_CURRENT_PALETTE_MATRIX_ARB;
    constants["MATRIX_INDEX_ARRAY_ARB"] = GL_MATRIX_INDEX_ARRAY_ARB;
    constants["CURRENT_MATRIX_INDEX_ARB"] = GL_CURRENT_MATRIX_INDEX_ARB;
    constants["MATRIX_INDEX_ARRAY_SIZE_ARB"] = GL_MATRIX_INDEX_ARRAY_SIZE_ARB;
    constants["MATRIX_INDEX_ARRAY_TYPE_ARB"] = GL_MATRIX_INDEX_ARRAY_TYPE_ARB;
    constants["MATRIX_INDEX_ARRAY_STRIDE_ARB"] = GL_MATRIX_INDEX_ARRAY_STRIDE_ARB;
    constants["MATRIX_INDEX_ARRAY_POINTER_ARB"] = GL_MATRIX_INDEX_ARRAY_POINTER_ARB;
    gl.addParamDim(PyGL::Integerv, GL_CURRENT_MATRIX_INDEX_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MATRIX_INDEX_ARRAY_SIZE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MATRIX_INDEX_ARRAY_TYPE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MATRIX_INDEX_ARRAY_STRIDE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_CURRENT_PALETTE_MATRIX_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_PALETTE_MATRICES_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_MATRIX_PALETTE_ARB, 16);
  } else {
    constants["ARB_matrix_palette"] = 0;
  }

  if (GLEW_ARB_multisample) {
#ifdef _DEBUG
    std::cout << "Supports ARB multisample" << std::endl;
#endif
    constants["ARB_multisample"] = 1;
    constants["MULTISAMPLE_ARB"] = GL_MULTISAMPLE_ARB;
    constants["SAMPLE_ALPHA_TO_COVERAGE_ARB"] = GL_SAMPLE_ALPHA_TO_COVERAGE_ARB;
    constants["SAMPLE_ALPHA_TO_ONE_ARB"] = GL_SAMPLE_ALPHA_TO_ONE_ARB;
    constants["SAMPLE_COVERAGE_ARB"] = GL_SAMPLE_COVERAGE_ARB;
    constants["SAMPLE_BUFFERS_ARB"] = GL_SAMPLE_BUFFERS_ARB;
    constants["SAMPLES_ARB"] = GL_SAMPLES_ARB;
    constants["SAMPLE_COVERAGE_VALUE_ARB"] = GL_SAMPLE_COVERAGE_VALUE_ARB;
    constants["SAMPLE_COVERAGE_INVERT_ARB"] = GL_SAMPLE_COVERAGE_INVERT_ARB;
    constants["MULTISAMPLE_BIT_ARB"] = GL_MULTISAMPLE_BIT_ARB;
    gl.addParamDim(PyGL::Floatv, GL_SAMPLE_COVERAGE_VALUE_ARB, 1);
    gl.addParamDim(PyGL::Booleanv, GL_SAMPLE_COVERAGE_INVERT_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_SAMPLE_BUFFERS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_SAMPLES_ARB, 1);
  } else {
    constants["ARB_multisample"] = 0;
  }

  if (GLEW_ARB_multitexture) {
#ifdef _DEBUG
    std::cout << "Supports ARB multitexture" << std::endl;
#endif
    constants["ARB_multitexture"] = 1;
    constants["TEXTURE0_ARB"] = GL_TEXTURE0_ARB;
    constants["TEXTURE1_ARB"] = GL_TEXTURE1_ARB;
    constants["TEXTURE2_ARB"] = GL_TEXTURE2_ARB;
    constants["TEXTURE3_ARB"] = GL_TEXTURE3_ARB;
    constants["TEXTURE4_ARB"] = GL_TEXTURE4_ARB;
    constants["TEXTURE5_ARB"] = GL_TEXTURE5_ARB;
    constants["TEXTURE6_ARB"] = GL_TEXTURE6_ARB;
    constants["TEXTURE7_ARB"] = GL_TEXTURE7_ARB;
    constants["TEXTURE8_ARB"] = GL_TEXTURE8_ARB;
    constants["TEXTURE9_ARB"] = GL_TEXTURE9_ARB;
    constants["TEXTURE10_ARB"] = GL_TEXTURE10_ARB;
    constants["TEXTURE11_ARB"] = GL_TEXTURE11_ARB;
    constants["TEXTURE12_ARB"] = GL_TEXTURE12_ARB;
    constants["TEXTURE13_ARB"] = GL_TEXTURE13_ARB;
    constants["TEXTURE14_ARB"] = GL_TEXTURE14_ARB;
    constants["TEXTURE15_ARB"] = GL_TEXTURE15_ARB;
    constants["TEXTURE16_ARB"] = GL_TEXTURE16_ARB;
    constants["TEXTURE17_ARB"] = GL_TEXTURE17_ARB;
    constants["TEXTURE18_ARB"] = GL_TEXTURE18_ARB;
    constants["TEXTURE19_ARB"] = GL_TEXTURE19_ARB;
    constants["TEXTURE20_ARB"] = GL_TEXTURE20_ARB;
    constants["TEXTURE21_ARB"] = GL_TEXTURE21_ARB;
    constants["TEXTURE22_ARB"] = GL_TEXTURE22_ARB;
    constants["TEXTURE23_ARB"] = GL_TEXTURE23_ARB;
    constants["TEXTURE24_ARB"] = GL_TEXTURE24_ARB;
    constants["TEXTURE25_ARB"] = GL_TEXTURE25_ARB;
    constants["TEXTURE26_ARB"] = GL_TEXTURE26_ARB;
    constants["TEXTURE27_ARB"] = GL_TEXTURE27_ARB;
    constants["TEXTURE28_ARB"] = GL_TEXTURE28_ARB;
    constants["TEXTURE29_ARB"] = GL_TEXTURE29_ARB;
    constants["TEXTURE30_ARB"] = GL_TEXTURE30_ARB;
    constants["TEXTURE31_ARB"] = GL_TEXTURE31_ARB;
    constants["ACTIVE_TEXTURE_ARB"] = GL_ACTIVE_TEXTURE_ARB;
    constants["CLIENT_ACTIVE_TEXTURE_ARB"] = GL_CLIENT_ACTIVE_TEXTURE_ARB;
    constants["MAX_TEXTURE_UNITS_ARB"] = GL_MAX_TEXTURE_UNITS_ARB;
    gl.addParamDim(PyGL::Integerv, GL_MAX_TEXTURE_UNITS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_ACTIVE_TEXTURE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_CLIENT_ACTIVE_TEXTURE_ARB, 1);
  } else {
    constants["ARB_multitexture"] = 0;
  }

  if (GLEW_ARB_occlusion_query) {
#ifdef _DEBUG
    std::cout << "Supports ARB occlusion query" << std::endl;
#endif
    constants["ARB_occlusion_query"] = 1;
    constants["QUERY_COUNTER_BITS_ARB"] = GL_QUERY_COUNTER_BITS_ARB;
    constants["CURRENT_QUERY_ARB"] = GL_CURRENT_QUERY_ARB;
    constants["QUERY_RESULT_ARB"] = GL_QUERY_RESULT_ARB;
    constants["QUERY_RESULT_AVAILABLE_ARB"] = GL_QUERY_RESULT_AVAILABLE_ARB;
    constants["SAMPLES_PASSED_ARB"] = GL_SAMPLES_PASSED_ARB;
  } else {
    constants["ARB_occlusion_query"] = 0;
  }

  if (GLEW_ARB_pixel_buffer_object) {
#ifdef _DEBUG
    std::cout << "Supports ARB pixel buffer object" << std::endl;
#endif
    constants["ARB_pixel_buffer_object"] = 1;
    constants["PIXEL_PACK_BUFFER_ARB"] = GL_PIXEL_PACK_BUFFER_ARB;
    constants["PIXEL_UNPACK_BUFFER_ARB"] = GL_PIXEL_UNPACK_BUFFER_ARB;
    constants["PIXEL_PACK_BUFFER_BINDING_ARB"] = GL_PIXEL_PACK_BUFFER_BINDING_ARB;
    constants["PIXEL_UNPACK_BUFFER_BINDING_ARB"] = GL_PIXEL_UNPACK_BUFFER_BINDING_ARB;
    gl.addParamDim(PyGL::Integerv, GL_PIXEL_PACK_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_PIXEL_UNPACK_BUFFER_BINDING_ARB, 1);
  } else {
    constants["ARB_pixel_buffer_object"] = 0;
  }

  if (GLEW_ARB_point_parameters) {
#ifdef _DEBUG
    std::cout << "Supports ARB point parameters" << std::endl;
#endif
    constants["ARB_point_parameters"] = 1;
    constants["POINT_SIZE_MIN_ARB"] = GL_POINT_SIZE_MIN_ARB;
    constants["POINT_SIZE_MAX_ARB"] = GL_POINT_SIZE_MAX_ARB;
    constants["POINT_FADE_THRESHOLD_SIZE_ARB"] = GL_POINT_FADE_THRESHOLD_SIZE_ARB;
    constants["POINT_DISTANCE_ATTENUATION_ARB"] = GL_POINT_DISTANCE_ATTENUATION_ARB;
    gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_MIN_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_SIZE_MAX_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_FADE_THRESHOLD_SIZE_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_POINT_DISTANCE_ATTENUATION_ARB, 3);
  } else {
    constants["ARB_point_parameters"] = 0;
  }

  if (GLEW_ARB_point_sprite) {
#ifdef _DEBUG
    std::cout << "Supports ARB point sprite" << std::endl;
#endif
    constants["ARB_point_sprite"] = 1;
    constants["POINT_SPRITE_ARB"] = GL_POINT_SPRITE_ARB;
    constants["COORD_REPLACE_ARB"] = GL_COORD_REPLACE_ARB;
    gl.addParamDim(PyGL::TexEnviv, GL_COORD_REPLACE_ARB, 1);
  } else {
    constants["ARB_point_sprite"] = 0;
  }

  if (GLEW_ARB_shader_objects) {
#ifdef _DEBUG
    std::cout << "Supports ARB shader objects" << std::endl;
#endif
    constants["ARB_shader_objects"] = 1;
    constants["PROGRAM_OBJECT_ARB"] = GL_PROGRAM_OBJECT_ARB;
    constants["SHADER_OBJECT_ARB"] = GL_SHADER_OBJECT_ARB;
    constants["OBJECT_TYPE_ARB"] = GL_OBJECT_TYPE_ARB;
    constants["OBJECT_SUBTYPE_ARB"] = GL_OBJECT_SUBTYPE_ARB;
    constants["FLOAT_VEC2_ARB"] = GL_FLOAT_VEC2_ARB;
    constants["FLOAT_VEC3_ARB"] = GL_FLOAT_VEC3_ARB;
    constants["FLOAT_VEC4_ARB"] = GL_FLOAT_VEC4_ARB;
    constants["INT_VEC2_ARB"] = GL_INT_VEC2_ARB;
    constants["INT_VEC3_ARB"] = GL_INT_VEC3_ARB;
    constants["INT_VEC4_ARB"] = GL_INT_VEC4_ARB;
    constants["BOOL_ARB"] = GL_BOOL_ARB;
    constants["BOOL_VEC2_ARB"] = GL_BOOL_VEC2_ARB;
    constants["BOOL_VEC3_ARB"] = GL_BOOL_VEC3_ARB;
    constants["BOOL_VEC4_ARB"] = GL_BOOL_VEC4_ARB;
    constants["FLOAT_MAT2_ARB"] = GL_FLOAT_MAT2_ARB;
    constants["FLOAT_MAT3_ARB"] = GL_FLOAT_MAT3_ARB;
    constants["FLOAT_MAT4_ARB"] = GL_FLOAT_MAT4_ARB;
    constants["SAMPLER_1D_ARB"] = GL_SAMPLER_1D_ARB;
    constants["SAMPLER_2D_ARB"] = GL_SAMPLER_2D_ARB;
    constants["SAMPLER_3D_ARB"] = GL_SAMPLER_3D_ARB;
    constants["SAMPLER_CUBE_ARB"] = GL_SAMPLER_CUBE_ARB;
    constants["SAMPLER_1D_SHADOW_ARB"] = GL_SAMPLER_1D_SHADOW_ARB;
    constants["SAMPLER_2D_SHADOW_ARB"] = GL_SAMPLER_2D_SHADOW_ARB;
    constants["SAMPLER_2D_RECT_ARB"] = GL_SAMPLER_2D_RECT_ARB;
    constants["SAMPLER_2D_RECT_SHADOW_ARB"] = GL_SAMPLER_2D_RECT_SHADOW_ARB;
    constants["OBJECT_DELETE_STATUS_ARB"] = GL_OBJECT_DELETE_STATUS_ARB;
    constants["OBJECT_COMPILE_STATUS_ARB"] = GL_OBJECT_COMPILE_STATUS_ARB;
    constants["OBJECT_LINK_STATUS_ARB"] = GL_OBJECT_LINK_STATUS_ARB;
    constants["OBJECT_VALIDATE_STATUS_ARB"] = GL_OBJECT_VALIDATE_STATUS_ARB;
    constants["OBJECT_INFO_LOG_LENGTH_ARB"] = GL_OBJECT_INFO_LOG_LENGTH_ARB;
    constants["OBJECT_ATTACHED_OBJECTS_ARB"] = GL_OBJECT_ATTACHED_OBJECTS_ARB;
    constants["OBJECT_ACTIVE_UNIFORMS_ARB"] = GL_OBJECT_ACTIVE_UNIFORMS_ARB;
    constants["OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB"] = GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB;
    constants["OBJECT_SHADER_SOURCE_LENGTH_ARB"] = GL_OBJECT_SHADER_SOURCE_LENGTH_ARB;
  } else {
    constants["ARB_shader_objects"] = 0;
  }

  if (GLEW_ARB_shading_language_100) {
#ifdef _DEBUG
    std::cout << "Supports ARB shading language 100" << std::endl;
#endif
    constants["ARB_shading_language_100"] = 1;
    constants["SHADING_LANGUAGE_VERSION_ARB"] = GL_SHADING_LANGUAGE_VERSION_ARB;
  } else {
    constants["ARB_shading_language_100"] = 1;
  }

  if (GLEW_ARB_shadow) {
#ifdef _DEBUG
    std::cout << "Supports ARB shadow" << std::endl;
#endif
    constants["ARB_shadow"] = 0;
    constants["TEXTURE_COMPARE_MODE_ARB"] = GL_TEXTURE_COMPARE_MODE_ARB;
    constants["TEXTURE_COMPARE_FUNC_ARB"] = GL_TEXTURE_COMPARE_FUNC_ARB;
    constants["COMPARE_R_TO_TEXTURE_ARB"] = GL_COMPARE_R_TO_TEXTURE_ARB;
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_COMPARE_MODE_ARB, 1);
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC_ARB, 1);
  } else {
    constants["ARB_shadow"] = 0;
  }

  if (GLEW_ARB_shadow_ambient) {
#ifdef _DEBUG
    std::cout << "Supports ARB shadow ambient" << std::endl;
#endif
    constants["ARB_shadow_ambient"] = 1;
    constants["TEXTURE_COMPARE_FAIL_VALUE_ARB"] = GL_TEXTURE_COMPARE_FAIL_VALUE_ARB;
    gl.addParamDim(PyGL::TexParameterfv, GL_TEXTURE_COMPARE_FAIL_VALUE_ARB, 1);
  } else {
    constants["ARB_shadow_ambient"] = 0;
  }

  if (GLEW_ARB_texture_border_clamp) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture border clamp" << std::endl;
#endif
    constants["ARB_texture_border_clamp"] = 1;
    constants["CLAMP_TO_BORDER_ARB"] = GL_CLAMP_TO_BORDER_ARB;
  } else {
    constants["ARB_texture_border_clamp"] = 0;
  }

  if (GLEW_ARB_texture_compression) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture compression" << std::endl;
#endif
    constants["ARB_texture_compression"] = 1;
    constants["COMPRESSED_ALPHA_ARB"] = GL_COMPRESSED_ALPHA_ARB;
    constants["COMPRESSED_LUMINANCE_ARB"] = GL_COMPRESSED_LUMINANCE_ARB;
    constants["COMPRESSED_LUMINANCE_ALPHA_ARB"] = GL_COMPRESSED_LUMINANCE_ALPHA_ARB;
    constants["COMPRESSED_INTENSITY_ARB"] = GL_COMPRESSED_INTENSITY_ARB;
    constants["COMPRESSED_RGB_ARB"] = GL_COMPRESSED_RGB_ARB;
    constants["COMPRESSED_RGBA_ARB"] = GL_COMPRESSED_RGBA_ARB;
    constants["TEXTURE_COMPRESSION_HINT_ARB"] = GL_TEXTURE_COMPRESSION_HINT_ARB;
    constants["TEXTURE_COMPRESSED_IMAGE_SIZE_ARB"] = GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB;
    constants["TEXTURE_COMPRESSED_ARB"] = GL_TEXTURE_COMPRESSED_ARB;
    constants["NUM_COMPRESSED_TEXTURE_FORMATS_ARB"] = GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB;
    constants["COMPRESSED_TEXTURE_FORMATS_ARB"] = GL_COMPRESSED_TEXTURE_FORMATS_ARB;
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_COMPRESSED_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COMPRESSION_HINT_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB, 1);
    gl.addDependentParamDim(PyGL::Integerv, GL_COMPRESSED_TEXTURE_FORMATS_ARB, GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB);
  } else {
    constants["ARB_texture_compression"] = 0;
  }

  if (GLEW_ARB_texture_cube_map) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture cube map" << std::endl;
#endif
    constants["ARB_texture_cube_map"] = 1;
    constants["NORMAL_MAP_ARB"] = GL_NORMAL_MAP_ARB;
    constants["REFLECTION_MAP_ARB"] = GL_REFLECTION_MAP_ARB;
    constants["TEXTURE_CUBE_MAP_ARB"] = GL_TEXTURE_CUBE_MAP_ARB;
    constants["TEXTURE_BINDING_CUBE_MAP_ARB"] = GL_TEXTURE_BINDING_CUBE_MAP_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_X_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_X_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Y_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB;
    constants["TEXTURE_CUBE_MAP_POSITIVE_Z_ARB"] = GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB;
    constants["TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB"] = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB;
    constants["PROXY_TEXTURE_CUBE_MAP_ARB"] = GL_PROXY_TEXTURE_CUBE_MAP_ARB;
    constants["MAX_CUBE_MAP_TEXTURE_SIZE_ARB"] = GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB;
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_BINDING_CUBE_MAP_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB, 1);
  } else {
    constants["ARB_texture_cube_map"] = 0;
  }

  if (GLEW_ARB_texture_env_add) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env add" << std::endl;
#endif
    constants["ARB_texture_env_add"] = 1;
  } else {
    constants["ARB_texture_env_add"] = 0;
  }

  if (GLEW_ARB_texture_env_combine) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env combine" << std::endl;
#endif
    constants["ARB_texture_env_combine"] = 1;
    constants["SUBTRACT_ARB"] = GL_SUBTRACT_ARB;
    constants["COMBINE_ARB"] = GL_COMBINE_ARB;
    constants["COMBINE_RGB_ARB"] = GL_COMBINE_RGB_ARB;
    constants["COMBINE_ALPHA_ARB"] = GL_COMBINE_ALPHA_ARB;
    constants["RGB_SCALE_ARB"] = GL_RGB_SCALE_ARB;
    constants["ADD_SIGNED_ARB"] = GL_ADD_SIGNED_ARB;
    constants["INTERPOLATE_ARB"] = GL_INTERPOLATE_ARB;
    constants["CONSTANT_ARB"] = GL_CONSTANT_ARB;
    constants["PRIMARY_COLOR_ARB"] = GL_PRIMARY_COLOR_ARB;
    constants["PREVIOUS_ARB"] = GL_PREVIOUS_ARB;
    constants["SOURCE0_RGB_ARB"] = GL_SOURCE0_RGB_ARB;
    constants["SOURCE1_RGB_ARB"] = GL_SOURCE1_RGB_ARB;
    constants["SOURCE2_RGB_ARB"] = GL_SOURCE2_RGB_ARB;
    constants["SOURCE0_ALPHA_ARB"] = GL_SOURCE0_ALPHA_ARB;
    constants["SOURCE1_ALPHA_ARB"] = GL_SOURCE1_ALPHA_ARB;
    constants["SOURCE2_ALPHA_ARB"] = GL_SOURCE2_ALPHA_ARB;
    constants["OPERAND0_RGB_ARB"] = GL_OPERAND0_RGB_ARB;
    constants["OPERAND1_RGB_ARB"] = GL_OPERAND1_RGB_ARB;
    constants["OPERAND2_RGB_ARB"] = GL_OPERAND2_RGB_ARB;
    constants["OPERAND0_ALPHA_ARB"] = GL_OPERAND0_ALPHA_ARB;
    constants["OPERAND1_ALPHA_ARB"] = GL_OPERAND1_ALPHA_ARB;
    constants["OPERAND2_ALPHA_ARB"] = GL_OPERAND2_ALPHA_ARB;
    gl.addParamDim(PyGL::TexEnviv, GL_COMBINE_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_COMBINE_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE0_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE1_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE2_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE0_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE1_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_SOURCE2_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND0_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND1_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND2_RGB_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND0_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND1_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnviv, GL_OPERAND2_ALPHA_ARB, 1);
    gl.addParamDim(PyGL::TexEnvfv, GL_RGB_SCALE_ARB, 1);
    gl.addParamDim(PyGL::TexEnvfv, GL_ALPHA_SCALE, 1);
  } else {
    constants["ARB_texture_env_combine"] = 0;
  }

  if (GLEW_ARB_texture_env_crossbar) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env crossbar" << std::endl;
#endif
    constants["ARB_texture_env_crossbar"] = 1;
  } else {
    constants["ARB_texture_env_crossbar"] = 0;
  }

  if (GLEW_ARB_texture_env_dot3) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture env dot3" << std::endl;
#endif
    constants["ARB_texture_env_dot3"] = 1;
    constants["DOT3_RGB_ARB"] = GL_DOT3_RGB_ARB;
    constants["DOT3_RGBA_ARB"] = GL_DOT3_RGBA_ARB;
  } else {
    constants["ARB_texture_env_dot3"] = 0;
  }

  if (GLEW_ARB_texture_float) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture float" << std::endl;
#endif
    constants["ARB_texture_float"] = 1;
    constants["RGBA32F_ARB"] = GL_RGBA32F_ARB;
    constants["RGB32F_ARB"] = GL_RGB32F_ARB;
    constants["ALPHA32F_ARB"] = GL_ALPHA32F_ARB;
    constants["INTENSITY32F_ARB"] = GL_INTENSITY32F_ARB;
    constants["LUMINANCE32F_ARB"] = GL_LUMINANCE32F_ARB;
    constants["LUMINANCE_ALPHA32F_ARB"] = GL_LUMINANCE_ALPHA32F_ARB;
    constants["RGBA16F_ARB"] = GL_RGBA16F_ARB;
    constants["RGB16F_ARB"] = GL_RGB16F_ARB;
    constants["ALPHA16F_ARB"] = GL_ALPHA16F_ARB;
    constants["INTENSITY16F_ARB"] = GL_INTENSITY16F_ARB;
    constants["LUMINANCE16F_ARB"] = GL_LUMINANCE16F_ARB;
    constants["LUMINANCE_ALPHA16F_ARB"] = GL_LUMINANCE_ALPHA16F_ARB;
    constants["TEXTURE_RED_TYPE_ARB"] = GL_TEXTURE_RED_TYPE_ARB;
    constants["TEXTURE_GREEN_TYPE_ARB"] = GL_TEXTURE_GREEN_TYPE_ARB;
    constants["TEXTURE_BLUE_TYPE_ARB"] = GL_TEXTURE_BLUE_TYPE_ARB;
    constants["TEXTURE_ALPHA_TYPE_ARB"] = GL_TEXTURE_ALPHA_TYPE_ARB;
    constants["TEXTURE_LUMINANCE_TYPE_ARB"] = GL_TEXTURE_LUMINANCE_TYPE_ARB;
    constants["TEXTURE_INTENSITY_TYPE_ARB"] = GL_TEXTURE_INTENSITY_TYPE_ARB;
    constants["TEXTURE_DEPTH_TYPE_ARB"] = GL_TEXTURE_DEPTH_TYPE_ARB;
    constants["UNSIGNED_NORMALIZED_ARB"] = GL_UNSIGNED_NORMALIZED_ARB;
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_RED_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_GREEN_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_BLUE_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_ALPHA_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_LUMINANCE_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_INTENSITY_TYPE_ARB, 1);
    gl.addParamDim(PyGL::TexLevelParameteriv, GL_TEXTURE_DEPTH_TYPE_ARB, 1);
  } else {
    constants["ARB_texture_float"] = 0;
  }

  if (GLEW_ARB_texture_mirrored_repeat) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture mirrored repeat" << std::endl;
#endif
    constants["ARB_texture_mirrored_repeat"] = 1;
    constants["MIRRORED_REPEAT_ARB"] = GL_MIRRORED_REPEAT_ARB;
  } else {
    constants["ARB_texture_mirrored_repeat"] = 0;
  }

  if (GLEW_ARB_texture_non_power_of_two) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture npot" << std::endl;
#endif
    constants["ARB_texture_non_power_of_two"] = 1;
  } else {
    constants["ARB_texture_non_power_of_two"] = 0;
  }

  if (GLEW_ARB_texture_rectangle) {
#ifdef _DEBUG
    std::cout << "Supports ARB texture rectangle" << std::endl;
#endif
    constants["ARB_texture_rectangle"] = 1;
    constants["TEXTURE_RECTANGLE_ARB"] = GL_TEXTURE_RECTANGLE_ARB;
    constants["TEXTURE_BINDING_RECTANGLE_ARB"] = GL_TEXTURE_BINDING_RECTANGLE_ARB;
    constants["PROXY_TEXTURE_RECTANGLE_ARB"] = GL_PROXY_TEXTURE_RECTANGLE_ARB;
    constants["MAX_RECTANGLE_TEXTURE_SIZE_ARB"] = GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB;
    constants["SAMPLER_2D_RECT_ARB"] = GL_SAMPLER_2D_RECT_ARB;
    constants["SAMPLER_2D_RECT_SHADOW_ARB"] = GL_SAMPLER_2D_RECT_SHADOW_ARB;
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_BINDING_RECTANGLE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB, 1);
  } else {
    constants["ARB_texture_rectangle"] = 0;
  }

  if (GLEW_ARB_transpose_matrix) {
#ifdef _DEBUG
    std::cout << "Supports ARB transpose matrix" << std::endl;
#endif
    constants["ARB_transpose_matrix"] = 1;
    constants["TRANSPOSE_MODELVIEW_MATRIX_ARB"] = GL_TRANSPOSE_MODELVIEW_MATRIX_ARB;
    constants["TRANSPOSE_PROJECTION_MATRIX_ARB"] = GL_TRANSPOSE_PROJECTION_MATRIX_ARB;
    constants["TRANSPOSE_TEXTURE_MATRIX_ARB"] = GL_TRANSPOSE_TEXTURE_MATRIX_ARB;
    constants["TRANSPOSE_COLOR_MATRIX_ARB"] = GL_TRANSPOSE_COLOR_MATRIX_ARB;
  } else {
    constants["ARB_transpose_matrix"] = 0;
  }

  if (GLEW_ARB_vertex_blend) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex blend" << std::endl;
#endif
    constants["ARB_vertex_blend"] = 1;
    constants["MAX_VERTEX_UNITS_ARB"] = GL_MAX_VERTEX_UNITS_ARB;
    constants["ACTIVE_VERTEX_UNITS_ARB"] = GL_ACTIVE_VERTEX_UNITS_ARB;
    constants["WEIGHT_SUM_UNITY_ARB"] = GL_WEIGHT_SUM_UNITY_ARB;
    constants["VERTEX_BLEND_ARB"] = GL_VERTEX_BLEND_ARB;
    constants["CURRENT_WEIGHT_ARB"] = GL_CURRENT_WEIGHT_ARB;
    constants["WEIGHT_ARRAY_TYPE_ARB"] = GL_WEIGHT_ARRAY_TYPE_ARB;
    constants["WEIGHT_ARRAY_STRIDE_ARB"] = GL_WEIGHT_ARRAY_STRIDE_ARB;
    constants["WEIGHT_ARRAY_SIZE_ARB"] = GL_WEIGHT_ARRAY_SIZE_ARB;
    constants["WEIGHT_ARRAY_POINTER_ARB"] = GL_WEIGHT_ARRAY_POINTER_ARB;
    constants["WEIGHT_ARRAY_ARB"] = GL_WEIGHT_ARRAY_ARB;
    constants["MODELVIEW0_ARB"] = GL_MODELVIEW0_ARB;
    constants["MODELVIEW1_ARB"] = GL_MODELVIEW1_ARB;
    constants["MODELVIEW2_ARB"] = GL_MODELVIEW2_ARB;
    constants["MODELVIEW3_ARB"] = GL_MODELVIEW3_ARB;
    constants["MODELVIEW4_ARB"] = GL_MODELVIEW4_ARB;
    constants["MODELVIEW5_ARB"] = GL_MODELVIEW5_ARB;
    constants["MODELVIEW6_ARB"] = GL_MODELVIEW6_ARB;
    constants["MODELVIEW7_ARB"] = GL_MODELVIEW7_ARB;
    constants["MODELVIEW8_ARB"] = GL_MODELVIEW8_ARB;
    constants["MODELVIEW9_ARB"] = GL_MODELVIEW9_ARB;
    constants["MODELVIEW10_ARB"] = GL_MODELVIEW10_ARB;
    constants["MODELVIEW11_ARB"] = GL_MODELVIEW11_ARB;
    constants["MODELVIEW12_ARB"] = GL_MODELVIEW12_ARB;
    constants["MODELVIEW13_ARB"] = GL_MODELVIEW13_ARB;
    constants["MODELVIEW14_ARB"] = GL_MODELVIEW14_ARB;
    constants["MODELVIEW15_ARB"] = GL_MODELVIEW15_ARB;
    constants["MODELVIEW16_ARB"] = GL_MODELVIEW16_ARB;
    constants["MODELVIEW17_ARB"] = GL_MODELVIEW17_ARB;
    constants["MODELVIEW18_ARB"] = GL_MODELVIEW18_ARB;
    constants["MODELVIEW19_ARB"] = GL_MODELVIEW19_ARB;
    constants["MODELVIEW20_ARB"] = GL_MODELVIEW20_ARB;
    constants["MODELVIEW21_ARB"] = GL_MODELVIEW21_ARB;
    constants["MODELVIEW22_ARB"] = GL_MODELVIEW22_ARB;
    constants["MODELVIEW23_ARB"] = GL_MODELVIEW23_ARB;
    constants["MODELVIEW24_ARB"] = GL_MODELVIEW24_ARB;
    constants["MODELVIEW25_ARB"] = GL_MODELVIEW25_ARB;
    constants["MODELVIEW26_ARB"] = GL_MODELVIEW26_ARB;
    constants["MODELVIEW27_ARB"] = GL_MODELVIEW27_ARB;
    constants["MODELVIEW28_ARB"] = GL_MODELVIEW28_ARB;
    constants["MODELVIEW29_ARB"] = GL_MODELVIEW29_ARB;
    constants["MODELVIEW30_ARB"] = GL_MODELVIEW30_ARB;
    constants["MODELVIEW31_ARB"] = GL_MODELVIEW31_ARB;
    gl.addParamDim(PyGL::Integerv, GL_WEIGHT_ARRAY_TYPE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_WEIGHT_ARRAY_SIZE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_WEIGHT_ARRAY_STRIDE_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_ACTIVE_VERTEX_UNITS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_UNITS_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW0_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW1_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW2_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW3_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW4_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW5_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW6_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW7_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW8_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW9_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW10_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW11_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW12_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW13_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW14_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW15_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW16_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW17_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW18_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW19_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW20_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW21_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW22_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW23_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW24_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW25_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW26_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW27_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW28_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW29_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW30_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_MODELVIEW31_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_CURRENT_WEIGHT_ARB, 1);
  } else {
    constants["ARB_vertex_blend"] = 0;
  }

  if (GLEW_ARB_vertex_buffer_object) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex buffer object" << std::endl;
#endif
    constants["ARB_vertex_buffer_object"] = 1;
    constants["BUFFER_SIZE_ARB"] = GL_BUFFER_SIZE_ARB;
    constants["BUFFER_USAGE_ARB"] = GL_BUFFER_USAGE_ARB;
    constants["ARRAY_BUFFER_ARB"] = GL_ARRAY_BUFFER_ARB;
    constants["ELEMENT_ARRAY_BUFFER_ARB"] = GL_ELEMENT_ARRAY_BUFFER_ARB;
    constants["ARRAY_BUFFER_BINDING_ARB"] = GL_ARRAY_BUFFER_BINDING_ARB;
    constants["ELEMENT_ARRAY_BUFFER_BINDING_ARB"] = GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB;
    constants["VERTEX_ARRAY_BUFFER_BINDING_ARB"] = GL_VERTEX_ARRAY_BUFFER_BINDING_ARB;
    constants["NORMAL_ARRAY_BUFFER_BINDING_ARB"] = GL_NORMAL_ARRAY_BUFFER_BINDING_ARB;
    constants["COLOR_ARRAY_BUFFER_BINDING_ARB"] = GL_COLOR_ARRAY_BUFFER_BINDING_ARB;
    constants["INDEX_ARRAY_BUFFER_BINDING_ARB"] = GL_INDEX_ARRAY_BUFFER_BINDING_ARB;
    constants["TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB"] = GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB;
    constants["EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB"] = GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB;
    constants["SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB"] = GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB;
    constants["FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB"] = GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB;
    constants["WEIGHT_ARRAY_BUFFER_BINDING_ARB"] = GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB;
    constants["VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB"] = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB;
    constants["READ_ONLY_ARB"] = GL_READ_ONLY_ARB;
    constants["WRITE_ONLY_ARB"] = GL_WRITE_ONLY_ARB;
    constants["READ_WRITE_ARB"] = GL_READ_WRITE_ARB;
    constants["BUFFER_ACCESS_ARB"] = GL_BUFFER_ACCESS_ARB;
    constants["BUFFER_MAPPED_ARB"] = GL_BUFFER_MAPPED_ARB;
    constants["BUFFER_MAP_POINTER_ARB"] = GL_BUFFER_MAP_POINTER_ARB;
    constants["STREAM_DRAW_ARB"] = GL_STREAM_DRAW_ARB;
    constants["STREAM_READ_ARB"] = GL_STREAM_READ_ARB;
    constants["STREAM_COPY_ARB"] = GL_STREAM_COPY_ARB;
    constants["STATIC_DRAW_ARB"] = GL_STATIC_DRAW_ARB;
    constants["STATIC_READ_ARB"] = GL_STATIC_READ_ARB;
    constants["STATIC_COPY_ARB"] = GL_STATIC_COPY_ARB;
    constants["DYNAMIC_DRAW_ARB"] = GL_DYNAMIC_DRAW_ARB;
    constants["DYNAMIC_READ_ARB"] = GL_DYNAMIC_READ_ARB;
    constants["DYNAMIC_COPY_ARB"] = GL_DYNAMIC_COPY_ARB;
    gl.addParamDim(PyGL::Integerv, GL_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_VERTEX_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_NORMAL_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_COLOR_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_INDEX_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB, 1);
    // VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB    16+ x Z+  GetVertexAttribivARB     0
  } else {
    constants["ARB_vertex_buffer_object"] = 0;
  }

  if (GLEW_ARB_vertex_program) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex program" << std::endl;
#endif
    constants["ARB_vertex_program"] = 1;
    constants["COLOR_SUM_ARB"] = GL_COLOR_SUM_ARB;
    constants["VERTEX_PROGRAM_ARB"] = GL_VERTEX_PROGRAM_ARB;
    constants["VERTEX_ATTRIB_ARRAY_ENABLED_ARB"] = GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB;
    constants["VERTEX_ATTRIB_ARRAY_SIZE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_STRIDE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_TYPE_ARB"] = GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB;
    constants["CURRENT_VERTEX_ATTRIB_ARB"] = GL_CURRENT_VERTEX_ATTRIB_ARB;
    constants["PROGRAM_LENGTH_ARB"] = GL_PROGRAM_LENGTH_ARB;
    constants["PROGRAM_STRING_ARB"] = GL_PROGRAM_STRING_ARB;
    constants["MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB"] = GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB;
    constants["MAX_PROGRAM_MATRICES_ARB"] = GL_MAX_PROGRAM_MATRICES_ARB;
    constants["CURRENT_MATRIX_STACK_DEPTH_ARB"] = GL_CURRENT_MATRIX_STACK_DEPTH_ARB;
    constants["CURRENT_MATRIX_ARB"] = GL_CURRENT_MATRIX_ARB;
    constants["VERTEX_PROGRAM_POINT_SIZE_ARB"] = GL_VERTEX_PROGRAM_POINT_SIZE_ARB;
    constants["VERTEX_PROGRAM_TWO_SIDE_ARB"] = GL_VERTEX_PROGRAM_TWO_SIDE_ARB;
    constants["VERTEX_ATTRIB_ARRAY_POINTER_ARB"] = GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB;
    constants["PROGRAM_ERROR_POSITION_ARB"] = GL_PROGRAM_ERROR_POSITION_ARB;
    constants["PROGRAM_BINDING_ARB"] = GL_PROGRAM_BINDING_ARB;
    constants["MAX_VERTEX_ATTRIBS_ARB"] = GL_MAX_VERTEX_ATTRIBS_ARB;
    constants["VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB"] = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB;
    constants["PROGRAM_ERROR_STRING_ARB"] = GL_PROGRAM_ERROR_STRING_ARB;
    constants["PROGRAM_FORMAT_ASCII_ARB"] = GL_PROGRAM_FORMAT_ASCII_ARB;
    constants["PROGRAM_FORMAT_ARB"] = GL_PROGRAM_FORMAT_ARB;
    constants["PROGRAM_INSTRUCTIONS_ARB"] = GL_PROGRAM_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_INSTRUCTIONS_ARB;
    constants["PROGRAM_NATIVE_INSTRUCTIONS_ARB"] = GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB;
    constants["MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB"] = GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB;
    constants["PROGRAM_TEMPORARIES_ARB"] = GL_PROGRAM_TEMPORARIES_ARB;
    constants["MAX_PROGRAM_TEMPORARIES_ARB"] = GL_MAX_PROGRAM_TEMPORARIES_ARB;
    constants["PROGRAM_NATIVE_TEMPORARIES_ARB"] = GL_PROGRAM_NATIVE_TEMPORARIES_ARB;
    constants["MAX_PROGRAM_NATIVE_TEMPORARIES_ARB"] = GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB;
    constants["PROGRAM_PARAMETERS_ARB"] = GL_PROGRAM_PARAMETERS_ARB;
    constants["MAX_PROGRAM_PARAMETERS_ARB"] = GL_MAX_PROGRAM_PARAMETERS_ARB;
    constants["PROGRAM_NATIVE_PARAMETERS_ARB"] = GL_PROGRAM_NATIVE_PARAMETERS_ARB;
    constants["MAX_PROGRAM_NATIVE_PARAMETERS_ARB"] = GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB;
    constants["PROGRAM_ATTRIBS_ARB"] = GL_PROGRAM_ATTRIBS_ARB;
    constants["MAX_PROGRAM_ATTRIBS_ARB"] = GL_MAX_PROGRAM_ATTRIBS_ARB;
    constants["PROGRAM_NATIVE_ATTRIBS_ARB"] = GL_PROGRAM_NATIVE_ATTRIBS_ARB;
    constants["MAX_PROGRAM_NATIVE_ATTRIBS_ARB"] = GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB;
    constants["PROGRAM_ADDRESS_REGISTERS_ARB"] = GL_PROGRAM_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_ADDRESS_REGISTERS_ARB"] = GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB;
    constants["PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB"] = GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB"] = GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB;
    constants["MAX_PROGRAM_LOCAL_PARAMETERS_ARB"] = GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB;
    constants["MAX_PROGRAM_ENV_PARAMETERS_ARB"] = GL_MAX_PROGRAM_ENV_PARAMETERS_ARB;
    constants["PROGRAM_UNDER_NATIVE_LIMITS_ARB"] = GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB;
    constants["TRANSPOSE_CURRENT_MATRIX_ARB"] = GL_TRANSPOSE_CURRENT_MATRIX_ARB;
    constants["MATRIX0_ARB"] = GL_MATRIX0_ARB;
    constants["MATRIX1_ARB"] = GL_MATRIX1_ARB;
    constants["MATRIX2_ARB"] = GL_MATRIX2_ARB;
    constants["MATRIX3_ARB"] = GL_MATRIX3_ARB;
    constants["MATRIX4_ARB"] = GL_MATRIX4_ARB;
    constants["MATRIX5_ARB"] = GL_MATRIX5_ARB;
    constants["MATRIX6_ARB"] = GL_MATRIX6_ARB;
    constants["MATRIX7_ARB"] = GL_MATRIX7_ARB;
    constants["MATRIX8_ARB"] = GL_MATRIX8_ARB;
    constants["MATRIX9_ARB"] = GL_MATRIX9_ARB;
    constants["MATRIX10_ARB"] = GL_MATRIX10_ARB;
    constants["MATRIX11_ARB"] = GL_MATRIX11_ARB;
    constants["MATRIX12_ARB"] = GL_MATRIX12_ARB;
    constants["MATRIX13_ARB"] = GL_MATRIX13_ARB;
    constants["MATRIX14_ARB"] = GL_MATRIX14_ARB;
    constants["MATRIX15_ARB"] = GL_MATRIX15_ARB;
    constants["MATRIX16_ARB"] = GL_MATRIX16_ARB;
    constants["MATRIX17_ARB"] = GL_MATRIX17_ARB;
    constants["MATRIX18_ARB"] = GL_MATRIX18_ARB;
    constants["MATRIX19_ARB"] = GL_MATRIX19_ARB;
    constants["MATRIX20_ARB"] = GL_MATRIX20_ARB;
    constants["MATRIX21_ARB"] = GL_MATRIX21_ARB;
    constants["MATRIX22_ARB"] = GL_MATRIX22_ARB;
    constants["MATRIX23_ARB"] = GL_MATRIX23_ARB;
    constants["MATRIX24_ARB"] = GL_MATRIX24_ARB;
    constants["MATRIX25_ARB"] = GL_MATRIX25_ARB;
    constants["MATRIX26_ARB"] = GL_MATRIX26_ARB;
    constants["MATRIX27_ARB"] = GL_MATRIX27_ARB;
    constants["MATRIX28_ARB"] = GL_MATRIX28_ARB;
    constants["MATRIX29_ARB"] = GL_MATRIX29_ARB;
    constants["MATRIX30_ARB"] = GL_MATRIX30_ARB;
    constants["MATRIX31_ARB"] = GL_MATRIX31_ARB;
    gl.addParamDim(PyGL::Integerv, GL_PROGRAM_ERROR_POSITION_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_PROGRAM_MATRICES_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_CURRENT_MATRIX_STACK_DEPTH_ARB, 1);
    gl.addParamDim(PyGL::Floatv, GL_CURRENT_MATRIX_ARB, 16);
    gl.addParamDim(PyGL::Floatv, GL_TRANSPOSE_CURRENT_MATRIX_ARB, 16);
  } else {
    constants["ARB_vertex_program"] = 0;
  }

  if (GLEW_ARB_vertex_shader) {
#ifdef _DEBUG
    std::cout << "Supports ARB vertex shader" << std::endl;
#endif
    constants["ARB_vertex_shader"] = 1;
    constants["VERTEX_SHADER_ARB"] = GL_VERTEX_SHADER_ARB;
    constants["MAX_VERTEX_UNIFORM_COMPONENTS_ARB"] = GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB;
    constants["MAX_VARYING_FLOATS_ARB"] = GL_MAX_VARYING_FLOATS_ARB;
    constants["MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB;
    constants["MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB"] = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB;
    constants["OBJECT_ACTIVE_ATTRIBUTES_ARB"] = GL_OBJECT_ACTIVE_ATTRIBUTES_ARB;
    constants["OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB"] = GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB;
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VARYING_FLOATS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB, 1);
  } else {
    constants["ARB_vertex_shader"] = 0;
  }

  if (GLEW_ARB_window_pos) {
#ifdef _DEBUG
    std::cout << "Supports ARB window pos" << std::endl;
#endif
    constants["ARB_window_pos"] = 1;
  } else {
    constants["ARB_window_pos"] = 0;
  }

  if (GLEW_ARB_imaging) {
#ifdef _DEBUG
    std::cout << "Supports ARB imaging" << std::endl;
#endif
    constants["ARB_imaging"] = 1;
    constants["CONSTANT_COLOR"] = GL_CONSTANT_COLOR;
    constants["ONE_MINUS_CONSTANT_COLOR"] = GL_ONE_MINUS_CONSTANT_COLOR;
    constants["CONSTANT_ALPHA"] = GL_CONSTANT_ALPHA;
    constants["ONE_MINUS_CONSTANT_ALPHA"] = GL_ONE_MINUS_CONSTANT_ALPHA;
    constants["BLEND_COLOR"] = GL_BLEND_COLOR;
    constants["FUNC_ADD"] = GL_FUNC_ADD;
    constants["MIN"] = GL_MIN;
    constants["MAX"] = GL_MAX;
    constants["BLEND_EQUATION"] = GL_BLEND_EQUATION;
    constants["FUNC_SUBTRACT"] = GL_FUNC_SUBTRACT;
    constants["FUNC_REVERSE_SUBTRACT"] = GL_FUNC_REVERSE_SUBTRACT;
    constants["CONVOLUTION_1D"] = GL_CONVOLUTION_1D;
    constants["CONVOLUTION_2D"] = GL_CONVOLUTION_2D;
    constants["SEPARABLE_2D"] = GL_SEPARABLE_2D;
    constants["CONVOLUTION_BORDER_MODE"] = GL_CONVOLUTION_BORDER_MODE;
    constants["CONVOLUTION_FILTER_SCALE"] = GL_CONVOLUTION_FILTER_SCALE;
    constants["CONVOLUTION_FILTER_BIAS"] = GL_CONVOLUTION_FILTER_BIAS;
    constants["REDUCE"] = GL_REDUCE;
    constants["CONVOLUTION_FORMAT"] = GL_CONVOLUTION_FORMAT;
    constants["CONVOLUTION_WIDTH"] = GL_CONVOLUTION_WIDTH;
    constants["CONVOLUTION_HEIGHT"] = GL_CONVOLUTION_HEIGHT;
    constants["MAX_CONVOLUTION_WIDTH"] = GL_MAX_CONVOLUTION_WIDTH;
    constants["MAX_CONVOLUTION_HEIGHT"] = GL_MAX_CONVOLUTION_HEIGHT;
    constants["POST_CONVOLUTION_RED_SCALE"] = GL_POST_CONVOLUTION_RED_SCALE;
    constants["POST_CONVOLUTION_GREEN_SCALE"] = GL_POST_CONVOLUTION_GREEN_SCALE;
    constants["POST_CONVOLUTION_BLUE_SCALE"] = GL_POST_CONVOLUTION_BLUE_SCALE;
    constants["POST_CONVOLUTION_ALPHA_SCALE"] = GL_POST_CONVOLUTION_ALPHA_SCALE;
    constants["POST_CONVOLUTION_RED_BIAS"] = GL_POST_CONVOLUTION_RED_BIAS;
    constants["POST_CONVOLUTION_GREEN_BIAS"] = GL_POST_CONVOLUTION_GREEN_BIAS;
    constants["POST_CONVOLUTION_BLUE_BIAS"] = GL_POST_CONVOLUTION_BLUE_BIAS;
    constants["POST_CONVOLUTION_ALPHA_BIAS"] = GL_POST_CONVOLUTION_ALPHA_BIAS;
    constants["HISTOGRAM"] = GL_HISTOGRAM;
    constants["PROXY_HISTOGRAM"] = GL_PROXY_HISTOGRAM;
    constants["HISTOGRAM_WIDTH"] = GL_HISTOGRAM_WIDTH;
    constants["HISTOGRAM_FORMAT"] = GL_HISTOGRAM_FORMAT;
    constants["HISTOGRAM_RED_SIZE"] = GL_HISTOGRAM_RED_SIZE;
    constants["HISTOGRAM_GREEN_SIZE"] = GL_HISTOGRAM_GREEN_SIZE;
    constants["HISTOGRAM_BLUE_SIZE"] = GL_HISTOGRAM_BLUE_SIZE;
    constants["HISTOGRAM_ALPHA_SIZE"] = GL_HISTOGRAM_ALPHA_SIZE;
    constants["HISTOGRAM_LUMINANCE_SIZE"] = GL_HISTOGRAM_LUMINANCE_SIZE;
    constants["HISTOGRAM_SINK"] = GL_HISTOGRAM_SINK;
    constants["MINMAX"] = GL_MINMAX;
    constants["MINMAX_FORMAT"] = GL_MINMAX_FORMAT;
    constants["MINMAX_SINK"] = GL_MINMAX_SINK;
    constants["TABLE_TOO_LARGE"] = GL_TABLE_TOO_LARGE;
    constants["COLOR_MATRIX"] = GL_COLOR_MATRIX;
    constants["COLOR_MATRIX_STACK_DEPTH"] = GL_COLOR_MATRIX_STACK_DEPTH;
    constants["MAX_COLOR_MATRIX_STACK_DEPTH"] = GL_MAX_COLOR_MATRIX_STACK_DEPTH;
    constants["POST_COLOR_MATRIX_RED_SCALE"] = GL_POST_COLOR_MATRIX_RED_SCALE;
    constants["POST_COLOR_MATRIX_GREEN_SCALE"] = GL_POST_COLOR_MATRIX_GREEN_SCALE;
    constants["POST_COLOR_MATRIX_BLUE_SCALE"] = GL_POST_COLOR_MATRIX_BLUE_SCALE;
    constants["POST_COLOR_MATRIX_ALPHA_SCALE"] = GL_POST_COLOR_MATRIX_ALPHA_SCALE;
    constants["POST_COLOR_MATRIX_RED_BIAS"] = GL_POST_COLOR_MATRIX_RED_BIAS;
    constants["POST_COLOR_MATRIX_GREEN_BIAS"] = GL_POST_COLOR_MATRIX_GREEN_BIAS;
    constants["POST_COLOR_MATRIX_BLUE_BIAS"] = GL_POST_COLOR_MATRIX_BLUE_BIAS;
    constants["POST_COLOR_MATRIX_ALPHA_BIAS"] = GL_POST_COLOR_MATRIX_ALPHA_BIAS;
    constants["COLOR_TABLE"] = GL_COLOR_TABLE;
    constants["POST_CONVOLUTION_COLOR_TABLE"] = GL_POST_CONVOLUTION_COLOR_TABLE;
    constants["POST_COLOR_MATRIX_COLOR_TABLE"] = GL_POST_COLOR_MATRIX_COLOR_TABLE;
    constants["PROXY_COLOR_TABLE"] = GL_PROXY_COLOR_TABLE;
    constants["PROXY_POST_CONVOLUTION_COLOR_TABLE"] = GL_PROXY_POST_CONVOLUTION_COLOR_TABLE;
    constants["PROXY_POST_COLOR_MATRIX_COLOR_TABLE"] = GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE;
    constants["COLOR_TABLE_SCALE"] = GL_COLOR_TABLE_SCALE;
    constants["COLOR_TABLE_BIAS"] = GL_COLOR_TABLE_BIAS;
    constants["COLOR_TABLE_FORMAT"] = GL_COLOR_TABLE_FORMAT;
    constants["COLOR_TABLE_WIDTH"] = GL_COLOR_TABLE_WIDTH;
    constants["COLOR_TABLE_RED_SIZE"] = GL_COLOR_TABLE_RED_SIZE;
    constants["COLOR_TABLE_GREEN_SIZE"] = GL_COLOR_TABLE_GREEN_SIZE;
    constants["COLOR_TABLE_BLUE_SIZE"] = GL_COLOR_TABLE_BLUE_SIZE;
    constants["COLOR_TABLE_ALPHA_SIZE"] = GL_COLOR_TABLE_ALPHA_SIZE;
    constants["COLOR_TABLE_LUMINANCE_SIZE"] = GL_COLOR_TABLE_LUMINANCE_SIZE;
    constants["COLOR_TABLE_INTENSITY_SIZE"] = GL_COLOR_TABLE_INTENSITY_SIZE;
    constants["IGNORE_BORDER"] = GL_IGNORE_BORDER;
    constants["CONSTANT_BORDER"] = GL_CONSTANT_BORDER;
    constants["WRAP_BORDER"] = GL_WRAP_BORDER;
    constants["REPLICATE_BORDER"] = GL_REPLICATE_BORDER;
    constants["CONVOLUTION_BORDER_COLOR"] = GL_CONVOLUTION_BORDER_COLOR;
    gl.addParamDim(PyGL::Integerv, GL_COLOR_MATRIX_STACK_DEPTH, 1);
    gl.addParamDim(PyGL::Integerv, GL_MAX_COLOR_MATRIX_STACK_DEPTH, 1);
    gl.addParamDim(PyGL::Floatv, GL_COLOR_MATRIX, 16);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_RED_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_GREEN_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_BLUE_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_ALPHA_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_RED_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_GREEN_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_BLUE_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_CONVOLUTION_ALPHA_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_RED_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_GREEN_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_BLUE_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_ALPHA_SCALE, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_RED_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_GREEN_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_BLUE_BIAS, 1);
    gl.addParamDim(PyGL::Floatv, GL_POST_COLOR_MATRIX_ALPHA_BIAS, 1);
  } else {
    constants["ARB_imaging"] = 0;
  }
}

void Register_GL_ARB_Functions(PyGL::FunctionTable &functions) {
  //REGISTER_GL_FUNC(functions, 
  if (GLEW_ARB_color_buffer_float) {
    REGISTER_GL_FUNC(functions, ClampColorARB);
  }
  if (GLEW_ARB_draw_buffers) {
    REGISTER_GL_FUNC(functions, DrawBuffersARB);
  }
  if (GLEW_ARB_matrix_palette) {
    REGISTER_GL_FUNC(functions, CurrentPaletteMatrixARB);
    REGISTER_GL_FUNC(functions, MatrixIndexPointerARB);
    REGISTER_GL_FUNC(functions, MatrixIndexubvARB);
    REGISTER_GL_FUNC(functions, MatrixIndexusvARB);
    REGISTER_GL_FUNC(functions, MatrixIndexuivARB);
  }
  if (GLEW_ARB_multisample) {
    REGISTER_GL_FUNC(functions, SampleCoverageARB);
  }
  if (GLEW_ARB_multitexture) {
    REGISTER_GL_FUNC(functions, ActiveTextureARB);
    REGISTER_GL_FUNC(functions, ClientActiveTextureARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord1dARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord1fARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord1sARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord1iARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2dARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2fARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2sARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2iARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3dARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3fARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3sARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3iARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4dARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4fARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4sARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4iARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2dvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2fvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2svARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord2ivARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3dvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3fvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3svARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord3ivARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4dvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4fvARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4svARB);
    REGISTER_GL_FUNC(functions, MultiTexCoord4ivARB);
  }
  if (GLEW_ARB_occlusion_query) {
    REGISTER_GL_FUNC(functions, BeginQueryARB);
    REGISTER_GL_FUNC(functions, GenQueriesARB);
    REGISTER_GL_FUNC(functions, EndQueryARB);
    REGISTER_GL_FUNC(functions, DeleteQueriesARB);
    REGISTER_GL_FUNC(functions, GetQueryObjectARB);
    REGISTER_GL_FUNC(functions, GetQueryARB);
    REGISTER_GL_FUNC(functions, IsQueryARB);
  }
  if (GLEW_ARB_point_parameters) {
    REGISTER_GL_FUNC(functions, PointParameterfARB);
    REGISTER_GL_FUNC(functions, PointParameterfvARB); 
  }
  if (GLEW_ARB_shader_objects) {
    REGISTER_GL_FUNC(functions, AttachObjectARB);
    REGISTER_GL_FUNC(functions, CompileShaderARB);
    REGISTER_GL_FUNC(functions, CreateProgramObjectARB);
    REGISTER_GL_FUNC(functions, CreateShaderObjectARB);
    REGISTER_GL_FUNC(functions, DeleteObjectARB);
    REGISTER_GL_FUNC(functions, DetachObjectARB);
    REGISTER_GL_FUNC(functions, UseProgramObjectARB);
    REGISTER_GL_FUNC(functions, ValidateProgramARB);
    REGISTER_GL_FUNC(functions, LinkProgramARB);
    REGISTER_GL_FUNC(functions, Uniform1fARB);
    REGISTER_GL_FUNC(functions, Uniform2fARB);
    REGISTER_GL_FUNC(functions, Uniform3fARB);
    REGISTER_GL_FUNC(functions, Uniform4fARB);
    REGISTER_GL_FUNC(functions, Uniform1fvARB);
    REGISTER_GL_FUNC(functions, Uniform2fvARB);
    REGISTER_GL_FUNC(functions, Uniform3fvARB);
    REGISTER_GL_FUNC(functions, Uniform4fvARB);
    REGISTER_GL_FUNC(functions, Uniform1iARB);
    REGISTER_GL_FUNC(functions, Uniform2iARB);
    REGISTER_GL_FUNC(functions, Uniform3iARB);
    REGISTER_GL_FUNC(functions, Uniform4iARB);
    REGISTER_GL_FUNC(functions, Uniform1ivARB);
    REGISTER_GL_FUNC(functions, Uniform2ivARB);
    REGISTER_GL_FUNC(functions, Uniform3ivARB);
    REGISTER_GL_FUNC(functions, Uniform4ivARB);
    REGISTER_GL_FUNC(functions, GetActiveUniformARB);
    REGISTER_GL_FUNC(functions, GetShaderSourceARB);
    REGISTER_GL_FUNC(functions, GetHandleARB);
    REGISTER_GL_FUNC(functions, GetUniformLocationARB);
    REGISTER_GL_FUNC(functions, ShaderSourceARB);
    REGISTER_GL_FUNC(functions, GetAttachedObjectsARB);
    REGISTER_GL_FUNC(functions, GetObjectParameterARB);
    REGISTER_GL_FUNC(functions, GetInfoLogARB);
    REGISTER_GL_FUNC(functions, UniformMatrix2fvARB);
    REGISTER_GL_FUNC(functions, UniformMatrix3fvARB);
    REGISTER_GL_FUNC(functions, UniformMatrix4fvARB);
    REGISTER_GL_FUNC(functions, GetUniformARB);
  }
  if (GLEW_ARB_texture_compression) {
    REGISTER_GL_FUNC(functions, CompressedTexImage1DARB);
    REGISTER_GL_FUNC(functions, CompressedTexImage2DARB);
    REGISTER_GL_FUNC(functions, CompressedTexImage3DARB);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage1DARB);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage2DARB);
    REGISTER_GL_FUNC(functions, CompressedTexSubImage3DARB);
    REGISTER_GL_FUNC(functions, GetCompressedTexImageARB);
  }
  if (GLEW_ARB_transpose_matrix) {
    REGISTER_GL_FUNC(functions, LoadTransposeMatrixdARB);
    REGISTER_GL_FUNC(functions, LoadTransposeMatrixfARB);
    REGISTER_GL_FUNC(functions, MultTransposeMatrixdARB);
    REGISTER_GL_FUNC(functions, MultTransposeMatrixfARB);
  }
  if (GLEW_ARB_vertex_blend) {
    REGISTER_GL_FUNC(functions, VertexBlendARB);
    REGISTER_GL_FUNC(functions, WeightPointerARB);
    REGISTER_GL_FUNC(functions, WeightdvARB);
    REGISTER_GL_FUNC(functions, WeightfvARB);
    REGISTER_GL_FUNC(functions, WeightivARB);
    REGISTER_GL_FUNC(functions, WeightsvARB);
    REGISTER_GL_FUNC(functions, WeightbvARB);
    REGISTER_GL_FUNC(functions, WeightuivARB);
    REGISTER_GL_FUNC(functions, WeightusvARB);
    REGISTER_GL_FUNC(functions, WeightubvARB);
  }
  if (GLEW_ARB_vertex_buffer_object) {
    REGISTER_GL_FUNC(functions, BindBufferARB);
    REGISTER_GL_FUNC(functions, BufferDataARB);
    REGISTER_GL_FUNC(functions, BufferSubDataARB);
    REGISTER_GL_FUNC(functions, DeleteBuffersARB);
    REGISTER_GL_FUNC(functions, GenBuffersARB);
    REGISTER_GL_FUNC(functions, IsBufferARB);
    REGISTER_GL_FUNC(functions, MapBufferARB);
    REGISTER_GL_FUNC(functions, UnmapBufferARB);
    REGISTER_GL_FUNC(functions, GetBufferPointerARB);
    REGISTER_GL_FUNC(functions, GetBufferSubDataARB);
    REGISTER_GL_FUNC(functions, GetBufferParameterARB);
  }
  if (GLEW_ARB_vertex_program) {
    REGISTER_GL_FUNC(functions, GetVertexAttribARB);
    REGISTER_GL_FUNC(functions, GetVertexAttribPointerARB);
    REGISTER_GL_FUNC(functions, VertexAttribPointerARB);
    REGISTER_GL_FUNC(functions, VertexAttrib1dARB);
    REGISTER_GL_FUNC(functions, VertexAttrib1fARB);
    REGISTER_GL_FUNC(functions, VertexAttrib1sARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2dARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2fARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2sARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3dARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3fARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3sARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4dARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4fARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4sARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2dvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2fvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib2svARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3dvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3fvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib3svARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4dvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4fvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4svARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NbvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NsvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NivARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NubvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NusvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NuivARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4bvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4ivARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4ubvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4usvARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4uivARB);
    REGISTER_GL_FUNC(functions, BindProgramARB);
    REGISTER_GL_FUNC(functions, DeleteProgramsARB);
    REGISTER_GL_FUNC(functions, DisableVertexAttribArrayARB);
    REGISTER_GL_FUNC(functions, EnableVertexAttribArrayARB);
    REGISTER_GL_FUNC(functions, GenProgramsARB);
    REGISTER_GL_FUNC(functions, GetProgramEnvParameterARB);
    REGISTER_GL_FUNC(functions, GetProgramLocalParameterARB);
    REGISTER_GL_FUNC(functions, GetProgramARB);
    REGISTER_GL_FUNC(functions, GetProgramStringARB);
    REGISTER_GL_FUNC(functions, IsProgramARB);
    REGISTER_GL_FUNC(functions, ProgramEnvParameter4fvARB);
    REGISTER_GL_FUNC(functions, ProgramEnvParameter4fARB);
    REGISTER_GL_FUNC(functions, ProgramEnvParameter4dvARB);
    REGISTER_GL_FUNC(functions, ProgramEnvParameter4dARB);
    REGISTER_GL_FUNC(functions, ProgramLocalParameter4fvARB);
    REGISTER_GL_FUNC(functions, ProgramLocalParameter4fARB);
    REGISTER_GL_FUNC(functions, ProgramLocalParameter4dvARB);
    REGISTER_GL_FUNC(functions, ProgramLocalParameter4dARB);
    REGISTER_GL_FUNC(functions, ProgramStringARB);
    REGISTER_GL_FUNC(functions, VertexAttrib4NubARB);
  }
  if (GLEW_ARB_vertex_shader) {
    REGISTER_GL_FUNC(functions, BindAttribLocationARB);
    REGISTER_GL_FUNC(functions, GetActiveAttribARB);
    REGISTER_GL_FUNC(functions, GetAttribLocationARB);
  }
  if (GLEW_ARB_window_pos) {
    REGISTER_GL_FUNC(functions, WindowPos2dARB);
    REGISTER_GL_FUNC(functions, WindowPos2fARB);
    REGISTER_GL_FUNC(functions, WindowPos2iARB);
    REGISTER_GL_FUNC(functions, WindowPos2sARB);
    REGISTER_GL_FUNC(functions, WindowPos3dARB);
    REGISTER_GL_FUNC(functions, WindowPos3fARB);
    REGISTER_GL_FUNC(functions, WindowPos3iARB);
    REGISTER_GL_FUNC(functions, WindowPos3sARB);
    REGISTER_GL_FUNC(functions, WindowPos2dvARB);
    REGISTER_GL_FUNC(functions, WindowPos2fvARB);
    REGISTER_GL_FUNC(functions, WindowPos2ivARB);
    REGISTER_GL_FUNC(functions, WindowPos2svARB);
    REGISTER_GL_FUNC(functions, WindowPos3dvARB);
    REGISTER_GL_FUNC(functions, WindowPos3fvARB);
    REGISTER_GL_FUNC(functions, WindowPos3ivARB);
    REGISTER_GL_FUNC(functions, WindowPos3svARB);
  }
  if (GLEW_ARB_imaging) {
    REGISTER_GL_FUNC(functions, ColorSubTable);
    REGISTER_GL_FUNC(functions, ColorTable);
    REGISTER_GL_FUNC(functions, ColorTableParameterfv);
    REGISTER_GL_FUNC(functions, ColorTableParameteriv);
    REGISTER_GL_FUNC(functions, ConvolutionFilter1D);
    REGISTER_GL_FUNC(functions, ConvolutionFilter2D);
    REGISTER_GL_FUNC(functions, ConvolutionParameterf);
    REGISTER_GL_FUNC(functions, ConvolutionParameterfv);
    REGISTER_GL_FUNC(functions, ConvolutionParameteri);
    REGISTER_GL_FUNC(functions, ConvolutionParameteriv);
    REGISTER_GL_FUNC(functions, CopyColorSubTable);
    REGISTER_GL_FUNC(functions, CopyColorTable);
    REGISTER_GL_FUNC(functions, CopyConvolutionFilter1D);
    REGISTER_GL_FUNC(functions, CopyConvolutionFilter2D);
    REGISTER_GL_FUNC(functions, GetColorTable);
    REGISTER_GL_FUNC(functions, GetColorTableParameter);
    REGISTER_GL_FUNC(functions, GetConvolutionFilter);
    REGISTER_GL_FUNC(functions, GetConvolutionParameter);
    REGISTER_GL_FUNC(functions, GetHistogram);
    REGISTER_GL_FUNC(functions, GetHistogramParameter);
    REGISTER_GL_FUNC(functions, GetMinmax);
    REGISTER_GL_FUNC(functions, GetMinmaxParameter);
    REGISTER_GL_FUNC(functions, GetSeparableFilter);
    REGISTER_GL_FUNC(functions, Histogram);
    REGISTER_GL_FUNC(functions, Minmax);
    REGISTER_GL_FUNC(functions, ResetHistogram);
    REGISTER_GL_FUNC(functions, ResetMinmax);
    REGISTER_GL_FUNC(functions, SeparableFilter2D);
  }
}

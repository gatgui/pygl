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

static PyObject* py_glBeginQuery(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glBeginQuery);
}

static PyObject* py_glBindBuffer(PyObject *self, PyObject *args) {
  return WrapFunc2<Enum, Uint >::Call(self, args, glBindBuffer);
}

static PyObject* py_glBufferData(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Sizeiptr, ConstPtr, Enum >::Call(self, args, glBufferData);
}

static PyObject* py_glBufferSubData(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, ConstPtr >::Call(self, args, glBufferSubData);
}

static PyObject* py_glDeleteBuffers(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> buffers;
  if (buffers.fromPy(PyTuple_GetItem(args, 0))) {
    glDeleteBuffers(buffers.size(), buffers);
  }
  Py_RETURN_NONE;
}

static PyObject* py_glDeleteQueries(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Array1D<Uint> queries;
  if (queries.fromPy(PyTuple_GetItem(args, 0))) {
    glDeleteQueries(queries.size(), queries);
  }
  Py_RETURN_NONE;
}

static PyObject* py_glEndQuery(PyObject *self, PyObject *args) {
  return WrapFunc1<Enum >::Call(self, args, glEndQuery);
}

static PyObject* py_glGenBuffers(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> buffers(n);
  glGenBuffers(n, buffers);
  return buffers.toPy();
}

static PyObject* py_glGenQueries(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Sizei n(PyTuple_GetItem(args, 0));
  Array1D<Uint> queries(n);
  glGenQueries(n, queries);
  return queries.toPy();
}

static PyObject* py_glGetBufferParameter(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = PyGL::Instance().getParamDim(PyGL::BufferParameteriv, pname);
  if (dim > 0) {
    Array1D<Int> values(dim);
    glGetBufferParameteriv(target, pname, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetBufferParameter: invalid parameter name");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetBufferPointer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  GLvoid *ptr=0;
  glGetBufferPointerv(target, pname, &ptr);
  return PyCObject_FromVoidPtr(ptr, NULL);
}

static PyObject* py_glGetBufferSubData(PyObject *self, PyObject *args) {
  return WrapFunc4<Enum, Intptr, Sizeiptr, Ptr >::Call(self, args, glGetBufferSubData);
}

static PyObject* py_glIsBuffer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint id(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsBuffer(id) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glIsQuery(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Uint id(PyTuple_GetItem(args, 0));
  PyObject *rv = (glIsQuery(id) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glMapBuffer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum access(PyTuple_GetItem(args, 1));
  GLvoid *ptr = glMapBuffer(target, access);
  return PyCObject_FromVoidPtr(ptr, NULL);
}

static PyObject* py_glUnmapBuffer(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 1);
  Enum target(PyTuple_GetItem(args, 0));
  PyObject *rv = (glUnmapBuffer(target) == GL_TRUE ? Py_True : Py_False);
  Py_INCREF(rv);
  return rv;
}

static PyObject* py_glGetQueryObject(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = PyGL::Instance().getParamDim(PyGL::QueryObjectiv, pname);
  if (dim <= 0) {
    dim = PyGL::Instance().getParamDim(PyGL::QueryObjectuiv, pname);
    if (dim > 0) {
      Array1D<Uint> values(dim);
      glGetQueryObjectuiv(target, pname, values);
      if (dim == 1) {
        rv = PyInt_FromLong(values[0]);
      } else {
        rv = values.toPy();
      }
    }
  } else {
    Array1D<Int> values(dim);
    glGetQueryObjectiv(target, pname, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetQueryObject: invalid parameter name");
    return NULL;
  }
  return rv;
}

static PyObject* py_glGetQuery(PyObject *, PyObject *args) {
  CHECK_ARG_COUNT(args, 2);
  Enum target(PyTuple_GetItem(args, 0));
  Enum pname(PyTuple_GetItem(args, 1));
  PyObject *rv = 0;
  GLint dim = PyGL::Instance().getParamDim(PyGL::Queryiv, pname);
  if (dim > 0) {
    Array1D<Int> values(dim);
    glGetQueryiv(target, pname, values);
    if (dim == 1) {
      rv = PyInt_FromLong(values[0]);
    } else {
      rv = values.toPy();
    }
  }
  if (dim == 0) {
    PyErr_SetString(PyExc_RuntimeError, "gl.GetQuery: invalid parameter name");
    return NULL;
  }
  return rv;
}

void Register_GL_1_5_Constants(PyGL::ConstantMap &constants) {
  if (GLEW_VERSION_1_5) {
    constants["FOG_COORD_SRC"] = GL_FOG_COORD_SRC;
    constants["FOG_COORD"] = GL_FOG_COORD;
    constants["FOG_COORD_ARRAY"] = GL_FOG_COORD_ARRAY;
    constants["SRC0_RGB"] = GL_SRC0_RGB;
    constants["FOG_COORD_ARRAY_POINTER"] = GL_FOG_COORD_ARRAY_POINTER;
    constants["FOG_COORD_ARRAY_TYPE"] = GL_FOG_COORD_ARRAY_TYPE;
    constants["SRC1_ALPHA"] = GL_SRC1_ALPHA;
    constants["CURRENT_FOG_COORD"] = GL_CURRENT_FOG_COORD;
    constants["FOG_COORD_ARRAY_STRIDE"] = GL_FOG_COORD_ARRAY_STRIDE;
    constants["SRC0_ALPHA"] = GL_SRC0_ALPHA;
    constants["SRC1_RGB"] = GL_SRC1_RGB;
    constants["FOG_COORD_ARRAY_BUFFER_BINDING"] = GL_FOG_COORD_ARRAY_BUFFER_BINDING;
    constants["SRC2_ALPHA"] = GL_SRC2_ALPHA;
    constants["SRC2_RGB"] = GL_SRC2_RGB;
    constants["BUFFER_SIZE"] = GL_BUFFER_SIZE;
    constants["BUFFER_USAGE"] = GL_BUFFER_USAGE;
    constants["QUERY_COUNTER_BITS"] = GL_QUERY_COUNTER_BITS;
    constants["CURRENT_QUERY"] = GL_CURRENT_QUERY;
    constants["QUERY_RESULT"] = GL_QUERY_RESULT;
    constants["QUERY_RESULT_AVAILABLE"] = GL_QUERY_RESULT_AVAILABLE;
    constants["ARRAY_BUFFER"] = GL_ARRAY_BUFFER;
    constants["ELEMENT_ARRAY_BUFFER"] = GL_ELEMENT_ARRAY_BUFFER;
    constants["ARRAY_BUFFER_BINDING"] = GL_ARRAY_BUFFER_BINDING;
    constants["ELEMENT_ARRAY_BUFFER_BINDING"] = GL_ELEMENT_ARRAY_BUFFER_BINDING;
    constants["VERTEX_ARRAY_BUFFER_BINDING"] = GL_VERTEX_ARRAY_BUFFER_BINDING;
    constants["NORMAL_ARRAY_BUFFER_BINDING"] = GL_NORMAL_ARRAY_BUFFER_BINDING;
    constants["COLOR_ARRAY_BUFFER_BINDING"] = GL_COLOR_ARRAY_BUFFER_BINDING;
    constants["INDEX_ARRAY_BUFFER_BINDING"] = GL_INDEX_ARRAY_BUFFER_BINDING;
    constants["TEXTURE_COORD_ARRAY_BUFFER_BINDING"] = GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING;
    constants["EDGE_FLAG_ARRAY_BUFFER_BINDING"] = GL_EDGE_FLAG_ARRAY_BUFFER_BINDING;
    constants["SECONDARY_COLOR_ARRAY_BUFFER_BINDING"] = GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING;
    constants["FOG_COORDINATE_ARRAY_BUFFER_BINDING"] = GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING;
    constants["WEIGHT_ARRAY_BUFFER_BINDING"] = GL_WEIGHT_ARRAY_BUFFER_BINDING;
    constants["VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"] = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;
    constants["READ_ONLY"] = GL_READ_ONLY;
    constants["WRITE_ONLY"] = GL_WRITE_ONLY;
    constants["READ_WRITE"] = GL_READ_WRITE;
    constants["BUFFER_ACCESS"] = GL_BUFFER_ACCESS;
    constants["BUFFER_MAPPED"] = GL_BUFFER_MAPPED;
    constants["BUFFER_MAP_POINTER"] = GL_BUFFER_MAP_POINTER;
    constants["STREAM_DRAW"] = GL_STREAM_DRAW;
    constants["STREAM_READ"] = GL_STREAM_READ;
    constants["STREAM_COPY"] = GL_STREAM_COPY;
    constants["STATIC_DRAW"] = GL_STATIC_DRAW;
    constants["STATIC_READ"] = GL_STATIC_READ;
    constants["STATIC_COPY"] = GL_STATIC_COPY;
    constants["DYNAMIC_DRAW"] = GL_DYNAMIC_DRAW;
    constants["DYNAMIC_READ"] = GL_DYNAMIC_READ;
    constants["DYNAMIC_COPY"] = GL_DYNAMIC_COPY;
    constants["SAMPLES_PASSED"] = GL_SAMPLES_PASSED;
    
    PyGL &gl = PyGL::Instance();
    // GL_ARB_vertex_buffer_object
    gl.addParamDim(PyGL::Integerv, GL_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_VERTEX_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_NORMAL_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_COLOR_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_INDEX_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_EDGE_FLAG_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_WEIGHT_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::Integerv, GL_ELEMENT_ARRAY_BUFFER_BINDING, 1);
    gl.addParamDim(PyGL::BufferParameteriv, GL_BUFFER_SIZE, 1);
    gl.addParamDim(PyGL::BufferParameteriv, GL_BUFFER_USAGE, 1);
    gl.addParamDim(PyGL::BufferParameteriv, GL_BUFFER_ACCESS, 1);
    gl.addParamDim(PyGL::BufferParameteriv, GL_BUFFER_MAPPED, 1);
    // GL_ARB_occlusion_query
    gl.addParamDim(PyGL::Queryiv, GL_CURRENT_QUERY, 1);
    gl.addParamDim(PyGL::Queryiv, GL_QUERY_COUNTER_BITS, 1);
    gl.addParamDim(PyGL::QueryObjectuiv, GL_QUERY_RESULT, 1);
    gl.addParamDim(PyGL::QueryObjectiv, GL_QUERY_RESULT_AVAILABLE, 1);
    // GL_EXT_shadow_funcs
    gl.addParamDim(PyGL::TexParameteriv, GL_TEXTURE_COMPARE_FUNC, 1);
  }
}

void Register_GL_1_5_Functions(PyGL::FunctionTable &functions) {
  if (GLEW_VERSION_1_5) {
#ifdef _DEBUG
    std::cout << "Supports OpenGL 1.5" << std::endl;
#endif
    PyGL::Instance().setVersion(1.5);
    REGISTER_GL_FUNC(functions, BeginQuery);
    REGISTER_GL_FUNC(functions, BindBuffer);
    REGISTER_GL_FUNC(functions, BufferData);
    REGISTER_GL_FUNC(functions, BufferSubData);
    REGISTER_GL_FUNC(functions, DeleteBuffers);
    REGISTER_GL_FUNC(functions, DeleteQueries);
    REGISTER_GL_FUNC(functions, EndQuery);
    REGISTER_GL_FUNC(functions, GenBuffers);
    REGISTER_GL_FUNC(functions, GenQueries);
    REGISTER_GL_FUNC(functions, GetBufferParameter);
    REGISTER_GL_FUNC(functions, GetBufferPointer);
    REGISTER_GL_FUNC(functions, GetBufferSubData);
    REGISTER_GL_FUNC(functions, IsBuffer);
    REGISTER_GL_FUNC(functions, IsQuery);
    REGISTER_GL_FUNC(functions, MapBuffer);
    REGISTER_GL_FUNC(functions, UnmapBuffer);
    REGISTER_GL_FUNC(functions, GetQueryObject);
    REGISTER_GL_FUNC(functions, GetQuery);
  }
}


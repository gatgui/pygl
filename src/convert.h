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

#ifndef __pygl_convert_h_
#define __pygl_convert_h_

#include "common.h"
#include "array.h"

template <typename CType, typename PyType,
          PyType (*from)(PyObject *),
          PyObject* (*to)(PyType)>
struct TypeWrapper
{
  typedef CType T;
  
  inline TypeWrapper()
  {
  }
  
  inline TypeWrapper(T v)
    : value(v)
  {
  }
  
  inline TypeWrapper(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~TypeWrapper()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value = T(from(obj));
  }
  
  inline PyObject* toPy()
  {
    return to(PyType(value));
  }
  
  inline operator T () const
  {
    return value;
  }
  
  T value;
};

typedef TypeWrapper<GLbitfield, long, PyInt_AsLong, PyInt_FromLong> Bitfield;
typedef TypeWrapper<GLenum, long, PyInt_AsLong, PyInt_FromLong> Enum;
typedef TypeWrapper<GLsizei, long, PyInt_AsLong, PyInt_FromLong> Sizei;
typedef TypeWrapper<GLbyte, long, PyInt_AsLong, PyInt_FromLong> Byte;
typedef TypeWrapper<GLubyte, long, PyInt_AsLong, PyInt_FromLong> Ubyte;
typedef TypeWrapper<GLshort, long, PyInt_AsLong, PyInt_FromLong> Short;
typedef TypeWrapper<GLushort, long, PyInt_AsLong, PyInt_FromLong> Ushort;
typedef TypeWrapper<GLint, long, PyInt_AsLong, PyInt_FromLong> Int;
typedef TypeWrapper<GLuint, long, PyInt_AsLong, PyInt_FromLong> Uint;
typedef TypeWrapper<GLfloat, double, PyFloat_AsDouble, PyFloat_FromDouble> Float;
typedef TypeWrapper<GLclampf, double, PyFloat_AsDouble, PyFloat_FromDouble> Clampf;
typedef TypeWrapper<GLdouble, double, PyFloat_AsDouble, PyFloat_FromDouble> Double;
typedef TypeWrapper<GLclampd, double, PyFloat_AsDouble, PyFloat_FromDouble> Clampd;
typedef TypeWrapper<GLsizeiptr, long, PyInt_AsLong, PyInt_FromLong> Sizeiptr;
typedef TypeWrapper<GLintptr, long, PyInt_AsLong, PyInt_FromLong> Intptr;
typedef TypeWrapper<GLchar, long, PyInt_AsLong, PyInt_FromLong> Char;
typedef TypeWrapper<GLhandleARB, long, PyInt_AsLong, PyInt_FromLong> Handle;
typedef TypeWrapper<int, long, PyInt_AsLong, PyInt_FromLong> CInt;
typedef TypeWrapper<long, long, PyInt_AsLong, PyInt_FromLong> CLong;
typedef TypeWrapper<unsigned int, long, PyInt_AsLong, PyInt_FromLong> CUint;
typedef TypeWrapper<unsigned long, long, PyInt_AsLong, PyInt_FromLong> CUlong;

struct Boolean
{
  typedef GLboolean T;
  
  inline Boolean()
  {
  }
  
  inline Boolean(T v)
    : value(v)
  {
  }
  
  inline Boolean(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~Boolean()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value = (obj == Py_True ? GL_TRUE : GL_FALSE);
  }
  
  inline PyObject* toPy()
  {
    PyObject *rv = (value == GL_TRUE ? Py_True : Py_False);
    Py_INCREF(rv);
    return rv;
  }
  
  inline operator T () const
  {
    return value;
  }
  
  GLboolean value;
};

struct String
{
  typedef const char* T;
  
  inline String()
  {
  }
  
  inline String(T v)
    : value(v)
  {
  }
  
  inline String(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~String()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value = PyString_AsString(obj);
  }
  
  inline PyObject* toPy()
  {
    return PyString_FromString(value);
  }
  
  inline operator T () const
  {
    return value;
  }
  
  const char* value;
};

struct Ptr
{
  typedef void* T;
  
  inline Ptr()
    : value(0)
  {
  }
  
  inline Ptr(T v)
    : value(v)
  {
  }
  
  inline Ptr(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~Ptr()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    if (PyCObject_Check(obj))
    {
      value = PyCObject_AsVoidPtr(obj);
    }
    else
    {
      value = 0;
    }
  }
  
  inline PyObject* toPy()
  {
    return PyCObject_FromVoidPtr(value, NULL);
  }
  
  inline operator T () const
  {
    return value;
  }
  
  T value;
};

struct ConstPtr
{
  typedef const void* T;
  
  inline ConstPtr()
    : value(0)
  {
  }
  
  inline ConstPtr(T v)
    : value(v)
  {
  }
  
  inline ConstPtr(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~ConstPtr()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    if (PyCObject_Check(obj))
    {
      value = PyCObject_AsVoidPtr(obj);
    }
    else
    {
      value = 0;
    }
  }
  
  inline PyObject* toPy()
  {
    return PyCObject_FromVoidPtr((void*)value, NULL);
  }
  
  inline operator T () const
  {
    return value;
  }
  
  T value;
};

template <typename U>
struct TypedPtr
{
  typedef typename U::T* T;
  
  inline TypedPtr()
    : value(0)
  {
  }
  
  inline TypedPtr(T v)
    : value(v)
  {
  }
  
  inline TypedPtr(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~TypedPtr()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    if (PyCObject_Check(obj))
    {
      value = (T) PyCObject_AsVoidPtr(obj);
    }
    else
    {
      value = 0;
    }
  }
  
  inline PyObject* toPy()
  {
    return PyCObject_FromVoidPtr((void*)value, NULL);
  }
  
  inline operator T () const
  {
    return value;
  }
  
  T value;
};

template <typename U>
struct ConstTypedPtr
{
  typedef const typename U::T* T;
  
  inline ConstTypedPtr()
    : value(0)
  {
  }
  
  inline ConstTypedPtr(T v)
    : value(v)
  {
  }
  
  inline ConstTypedPtr(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~ConstTypedPtr()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    if (PyCObject_Check(obj))
    {
      value = (T) PyCObject_AsVoidPtr(obj);
    }
    else
    {
      value = 0;
    }
  }
  
  inline PyObject* toPy()
  {
    return PyCObject_FromVoidPtr((void*)value, NULL);
  }
  
  inline operator T () const
  {
    return value;
  }
  
  T value;
};

template <typename U>
struct Array {
  typedef typename U::T* T;
  
  inline Array()
  {
  }
  
  inline Array(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~Array()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value.fromPy(obj);
  }
  
  inline PyObject* toPy()
  {
    return value.toPy();
  }
  
  inline operator T ()
  {
    return value;
  }
  
  Array1D<U> value;
};

template <typename U, int dim>
struct ArrayN {
  typedef typename U::T* T;
  
  inline ArrayN()
  {
    value = Array1D<U>(_cary, dim);
  }
  
  inline ArrayN(PyObject *obj)
  {
    value = Array1D<U>(_cary, dim);
    fromPy(obj);
  }
  
  inline ~ArrayN()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value.fromPy(obj);
  }
  
  inline PyObject* toPy()
  {
    return value.toPy();
  }
  
  inline operator T ()
  {
    return value;
  }
  
  Array1D<U> value;
  typename U::T _cary[dim];
};

template <typename U>
struct ConstArray
{
  typedef const typename U::T* T;
  
  inline ConstArray()
  {
  }
  
  inline ConstArray(PyObject *obj)
  {
    fromPy(obj);
  }
  
  inline ~ConstArray()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value.fromPy(obj);
  }
  
  inline PyObject* toPy()
  {
    return value.toPy();
  }
  
  inline operator T () const
  {
    return value;
  }
  
  Array1D<U> value;
};

template <typename U, int dim>
struct ConstArrayN
{
  typedef const typename U::T* T;
  
  inline ConstArrayN()
  {
    value = Array1D<U>(_cary, dim);
  }
  
  inline ConstArrayN(PyObject *obj)
  {
    value = Array1D<U>(_cary, dim);
    fromPy(obj);
  }
  
  inline ~ConstArrayN()
  {
  }
  
  inline void fromPy(PyObject *obj)
  {
    value.fromPy(obj);
  }
  
  inline PyObject* toPy()
  {
    return value.toPy();
  }
  
  inline operator T () const
  {
    return value;
  }
  
  Array1D<U> value;
  typename U::T _cary[dim];
};


#endif

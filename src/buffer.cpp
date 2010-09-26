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

#include "buffer.h"
#include <iostream>
#include <map>

Structure::Structure()
  : mName("-"), mOffset(0), mCount(0), mFinalized(false) {
}

Structure::Structure(const std::string &n)
  : mName(n), mOffset(0), mCount(0), mFinalized(false) {
}

Structure::Structure(const Structure &rhs)
  : mName(rhs.mName), mOffset(rhs.mOffset),
    mCount(rhs.mCount), mSubs(rhs.mSubs),
    mFinalized(rhs.mFinalized) {
}

Structure::~Structure() {
}

Structure& Structure::operator=(const Structure &rhs) {
  if (this != &rhs) {
    mName = rhs.mName;
    mOffset = rhs.mOffset;
    mCount = rhs.mCount;
    mSubs = rhs.mSubs;
    mFinalized = rhs.mFinalized;
  }
  return *this;
}

bool Structure::operator==(const Structure &rhs) const {
  if (this != &rhs) {
    if (mName != rhs.mName) {
      return false;
    }
    if (mOffset != rhs.mOffset) {
      return false;
    }
    if (mCount != rhs.mCount) {
      return false;
    }
    if (mSubs.size() != rhs.mSubs.size()) {
      return false;
    }
    for (size_t i=0; i<mSubs.size(); ++i) {
      if (mSubs[i] != rhs.mSubs[i]) {
        return false;
      }
    }
  }
  return true;
}

Structure&
Structure::addField(const std::string &name) throw (std::runtime_error) {
  if (mFinalized) {
    throw std::runtime_error("Structure::addField: description is finalized");
  }
  Structure sub(name);
  mSubs.push_back(sub);
  return mSubs.back();
}

size_t Structure::getFieldIndex(const std::string &name) const {
  for (size_t i=0; i<mSubs.size(); ++i) {
    if (mSubs[i].getName() == name) {
      return i;
    }
  }
  return InvalidIndex;
}

const Structure&
Structure::getField(size_t idx) const throw(std::runtime_error) {
  if (idx >= mSubs.size()) {
    throw std::runtime_error("Structure::getField: Invalid index");
  }
  return mSubs[idx];
}

const Structure&
Structure::getField(const std::string &name) const throw(std::runtime_error) {
  size_t idx = getFieldIndex(name);
  if (idx == InvalidIndex) {
    throw std::runtime_error("Structure::getField: Invalid name");
  }
  return mSubs[idx];
}

Structure&
Structure::getField(size_t idx) throw(std::runtime_error) {
  if (idx >= mSubs.size()) {
    throw std::runtime_error("Structure::getField: Invalid index");
  }
  return mSubs[idx];
}

Structure&
Structure::getField(const std::string &name) throw(std::runtime_error) {
  size_t idx = getFieldIndex(name);
  if (idx == InvalidIndex) {
    throw std::runtime_error("Structure::getField: Invalid name");
  }
  return mSubs[idx];
}

void Structure::resolve(size_t &off) {
  mOffset = off;
  mCount = 0;
  for (size_t i=0; i<mSubs.size(); ++i) {
    mSubs[i].resolve(off);
    mSubs[i].mFinalized = true;
    mCount += mSubs[i].getFieldCount();
  }
  if (mCount == 0) {
    mCount = 1;
    ++off;
  }
}

std::string Structure::toString() const {
  std::ostringstream oss;
  if (isTerminal()) {
    oss << mName;
  } else {
    oss << "{ " << mName << ": ";
    for (size_t i=0; i<mSubs.size(); ++i) {
      oss << mSubs[i].toString() << " ";
    }
    oss << "}";
  }
  return oss.str();
}

// ---

typedef struct
{
  PyObject_HEAD
  Structure *ps;
  bool own;
} PyGL_Buffer_Structure;

PyTypeObject PyGL_Buffer_StructureType;

PyObject* PyGL_Buffer_Structure_New(PyTypeObject *t, PyObject *, PyObject *)
{
  PyObject *self = t->tp_alloc(t, 0);
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  pstruct->ps = new Structure();
  pstruct->own = false;
  return self;
}

int PyGL_Buffer_Structure_Init(PyObject *self, PyObject *args, PyObject *)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (PyTuple_Size(args) == 1)
  {
    char *str = 0;
    if (!PyArg_ParseTuple(args, "s", &str))
    {
      return -1;
    }
    *(pstruct->ps) = Structure(str);
  }
  else if (PyTuple_Size(args) != 0)
  {
    PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.Structure.__init__ takes at most 1 argument");
  }
  return 0;
}

void PyGL_Buffer_Structure_Delete(PyObject *self)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (pstruct->own && pstruct->ps != 0)
  {
    delete pstruct->ps;
  }
  self->ob_type->tp_free(self);
}

PyObject* PyGL_Buffer_Structure_GetOffset(PyObject *self, void*)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  return PyInt_FromLong(long(pstruct->ps->getOffset()));
}

PyObject* PyGL_Buffer_Structure_GetFieldCount(PyObject *self, void*)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  return PyInt_FromLong(long(pstruct->ps->getFieldCount()));
}

PyObject* PyGL_Buffer_Structure_GetIsTerminal(PyObject *self, void*)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  if (pstruct->ps->isTerminal())
  {
    Py_RETURN_TRUE;
  }
  else
  {
    Py_RETURN_FALSE;
  }
}

PyObject* PyGL_Buffer_Structure_GetIsFinalized(PyObject *self, void*)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  if (pstruct->ps->isFinalized())
  {
    Py_RETURN_TRUE;
  }
  else
  {
    Py_RETURN_FALSE;
  }
}

PyObject* PyGL_Buffer_Structure_GetName(PyObject *self, void*)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  return PyString_FromString(pstruct->ps->getName().c_str());
}

PyGetSetDef PyGL_Buffer_Structure_GetSeters[] =
{
  {(char*)"offset", PyGL_Buffer_Structure_GetOffset, NULL, NULL, NULL},
  {(char*)"fieldCount", PyGL_Buffer_Structure_GetFieldCount, NULL, NULL, NULL},
  {(char*)"terminal", PyGL_Buffer_Structure_GetIsTerminal, NULL, NULL, NULL},
  {(char*)"finalized", PyGL_Buffer_Structure_GetIsFinalized, NULL, NULL, NULL},
  {(char*)"name", PyGL_Buffer_Structure_GetName, NULL, NULL, NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

PyObject* PyGL_Buffer_Structure_FieldIndex(PyObject *self, PyObject *args)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  char *n = 0;
  
  if (!PyArg_ParseTuple(args, "s", &n))
  {
    return NULL;
  }
  
  size_t rv = pstruct->ps->getFieldIndex(n);
  
  if (rv == Structure::InvalidIndex)
  {
    return PyInt_FromLong(-1);
  }
  else
  {
    return PyInt_FromLong(long(rv));
  }
}

PyObject* PyGL_Buffer_Structure_AddField(PyObject *self, PyObject *args)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  char *n = 0;
  
  if (!PyArg_ParseTuple(args, "s", &n))
  {
    return NULL;
  }
  
  try
  {
    Structure &s = pstruct->ps->addField(n);
    
    PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructureType, NULL);
    ((PyGL_Buffer_Structure*)rv)->ps = &s;
    ((PyGL_Buffer_Structure*)rv)->own = false;
    
    return rv;
  }
  catch (std::runtime_error &e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  }
}

PyObject* PyGL_Buffer_Structure_HasField(PyObject *self, PyObject *args)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  char *n = 0;
  
  if (!PyArg_ParseTuple(args, "s", &n))
  {
    return NULL;
  }
  
  if (pstruct->ps->hasField(n))
  {
    Py_RETURN_TRUE;
  }
  else
  {
    Py_RETURN_FALSE;
  }
}

PyObject* PyGL_Buffer_Structure_Finalize(PyObject *self, PyObject *)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  pstruct->ps->finalize();
  Py_RETURN_NONE;
}

PyObject* PyGL_Buffer_Structure_Field(PyObject *self, PyObject *args)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  // string or int
  if (PyTuple_Size(args) != 1)
  {
    PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.Structure.getField takes exactly one argument");
    return NULL;
  }
  
  PyObject *arg = PyTuple_GetItem(args, 0);
  
  try
  {
    if (PyInt_Check(arg))
    {
      size_t idx = (size_t)PyInt_AsLong(arg);
      
      Structure &s = pstruct->ps->getField(idx);
      
      PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructureType, NULL);
      ((PyGL_Buffer_Structure*)rv)->ps = &s;
      ((PyGL_Buffer_Structure*)rv)->own = false;
      
      return rv;
    }
    else if (PyString_Check(arg))
    {
      const char *name = PyString_AsString(arg);
      
      Structure &s = pstruct->ps->getField(name);
      
      PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructureType, NULL);
      ((PyGL_Buffer_Structure*)rv)->ps = &s;
      ((PyGL_Buffer_Structure*)rv)->own = false;
      
      return rv;
    }
    else
    {
      PyErr_SetString(PyExc_ValueError, "pygl.buffer.Structure.getField expects a string or an integer");
      return NULL;
    }
  }
  catch (std::runtime_error &e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  }
}

PyMethodDef PyGL_Buffer_Structure_Methods[] =
{
  {"fieldIndex", PyGL_Buffer_Structure_FieldIndex, METH_VARARGS, NULL},
  {"addField", PyGL_Buffer_Structure_AddField, METH_VARARGS, NULL},
  {"hasField", PyGL_Buffer_Structure_HasField, METH_VARARGS, NULL},
  {"finalize", PyGL_Buffer_Structure_Finalize, METH_VARARGS, NULL},
  {"field", PyGL_Buffer_Structure_Field, METH_VARARGS, NULL},
  {NULL, NULL, NULL, NULL}
};


PyObject* PyGL_Buffer_Structure_ToString(PyObject *self)
{
  PyGL_Buffer_Structure *pstruct = (PyGL_Buffer_Structure*) self;
  
  if (!pstruct->ps)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyString_FromString(pstruct->ps->toString().c_str());
}

// ---

PyTypeObject PyGL_Buffer_RawPtrType;

PyObject* PyGL_Buffer_RawPtr_New(PyTypeObject *t, PyObject *, PyObject *)
{
  PyObject *self = t->tp_alloc(t, 0);
  ((PyGL_Buffer_RawPtr*)self)->ptr = 0;
  return self;
}

int PyGL_Buffer_RawPtr_Init(PyObject *, PyObject *, PyObject *)
{
  return 0;
}

void PyGL_Buffer_RawPtr_Delete(PyObject *self)
{
  self->ob_type->tp_free(self);
}

PyObject* PyGL_Buffer_RawPtr_IsNull(PyObject *self, void*)
{
  if (((PyGL_Buffer_RawPtr*)self)->ptr != 0)
  {
    Py_RETURN_FALSE;
  }
  else
  {
    Py_RETURN_TRUE;
  }
}

PyObject* PyGL_Buffer_RawPtr_ToStr(PyObject *self)
{
  std::ostringstream oss;
  oss << std::hex << ((PyGL_Buffer_RawPtr*)self)->ptr << std::dec;
  return PyString_FromString(oss.str().c_str());
}

PyGetSetDef PyGL_Buffer_RawPtr_GetSeters[] =
{
  {(char*)"null", PyGL_Buffer_RawPtr_IsNull, NULL, NULL, NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

// ---

template <DataType DT>
struct PyGL_Buffer_Buffer
{
  PyObject_HEAD
  Buffer<DT> *pb;
  bool own;
};

template <DataType DT>
struct PyGL_Buffer_BufferTypeDesc
{
  static PyTypeObject Type;
  static PyGetSetDef GetSeters[];
  static PyMethodDef Methods[];
  static PySequenceMethods SeqMethods;
};

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_New(PyTypeObject *t, PyObject *, PyObject *)
{
  PyObject *self = t->tp_alloc(t, 0);
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*)self;
  pbuf->pb = new Buffer<DT>();
  pbuf->own = true;
  return self;
}

template <DataType DT>
int PyGL_Buffer_Buffer_Init(PyObject *self, PyObject *args, PyObject *)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*)self;
  if (PyTuple_Size(args) == 1)
  {
    int n = 0;
    if (!PyArg_ParseTuple(args, "i", &n))
    {
      return -1;
    }
    *(pbuf->pb) = Buffer<DT>(n);
  }
  else if (PyTuple_Size(args) != 0)
  {
    PyErr_SetString(PyExc_RuntimeError, "At most one argument");
    return -1;
  }
  return 0;
}

template <DataType DT>
void PyGL_Buffer_Buffer_Delete(PyObject *self)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  if (pbuf->own && pbuf->pb != 0)
  {
    delete pbuf->pb;
  }
  self->ob_type->tp_free(self);
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_GetElementCount(PyObject *self, void*)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getElementCount()));
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_GetElementSize(PyObject *self, void*)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getElementSize()));
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_GetType(PyObject *self, void*)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getType()));
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_GetRawPtr(PyObject *self, void*)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  typename Buffer<DT>::T *ptr = (typename Buffer<DT>::T *) *(pbuf->pb);
  
  PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_RawPtrType, NULL);
  ((PyGL_Buffer_RawPtr*)rv)->ptr = (void*)ptr;
  return rv;
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_Offset(PyObject *self, PyObject *args)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  int i = 0;
  
  if (!PyArg_ParseTuple(args, "i", &i))
  {
    return NULL;
  }
  
  PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT>::Type, NULL);
  *(((PyGL_Buffer_Buffer<DT>*)rv)->pb) = pbuf->pb->offset(i);
  return rv;
}

template <DataType DT>
Py_ssize_t PyGL_Buffer_Buffer_Size(PyObject *self)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return (Py_ssize_t) pbuf->pb->getElementCount();
}

template <DataType DT>
PyObject* PyGL_Buffer_Buffer_GetItem(PyObject *self, Py_ssize_t idx)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  if (idx < 0 || idx >= (Py_ssize_t) pbuf->pb->getElementCount())
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return NULL;
  }
  
  return TypeConvert<DT>::ToPy((*(pbuf->pb))[idx]);
}

template <DataType DT>
int PyGL_Buffer_Buffer_SetItem(PyObject *self, Py_ssize_t idx, PyObject *val)
{
  PyGL_Buffer_Buffer<DT> *pbuf = (PyGL_Buffer_Buffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return -1;
  }
  
  if (idx < 0 || idx >= (Py_ssize_t) pbuf->pb->getElementCount())
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return -1;
  }
  
  (*(pbuf->pb))[idx] = TypeConvert<DT>::FromPy(val);
  
  return 0;
}

template <DataType DT>
PyTypeObject PyGL_Buffer_BufferTypeDesc<DT>::Type;

template <DataType DT>
PyGetSetDef PyGL_Buffer_BufferTypeDesc<DT>::GetSeters[] =
{
  {(char*)"elementCount", PyGL_Buffer_Buffer_GetElementCount<DT>, NULL, NULL, NULL},
  {(char*)"elementSize", PyGL_Buffer_Buffer_GetElementSize<DT>, NULL, NULL, NULL},
  {(char*)"type", PyGL_Buffer_Buffer_GetType<DT>, NULL, NULL, NULL},
  {(char*)"rawPtr", PyGL_Buffer_Buffer_GetRawPtr<DT>, NULL, NULL, NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

template <DataType DT>
PyMethodDef PyGL_Buffer_BufferTypeDesc<DT>::Methods[] =
{
  {"offset", PyGL_Buffer_Buffer_Offset<DT>, METH_VARARGS, NULL},
  {NULL, NULL, NULL, NULL}
};

template <DataType DT>
PySequenceMethods PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods;

template <DataType DT>
PyObject* InitBufferClass(const char *className)
{
  INIT_TYPE(PyGL_Buffer_BufferTypeDesc<DT>::Type, className, PyGL_Buffer_Buffer<DT>);
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_flags = Py_TPFLAGS_DEFAULT;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_new = PyGL_Buffer_Buffer_New<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_init = PyGL_Buffer_Buffer_Init<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_dealloc = PyGL_Buffer_Buffer_Delete<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_getset = PyGL_Buffer_BufferTypeDesc<DT>::GetSeters;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_methods = PyGL_Buffer_BufferTypeDesc<DT>::Methods;
  
  memset(&(PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods), 0, sizeof(PySequenceMethods));
  PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods.sq_length = PyGL_Buffer_Buffer_Size<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods.sq_item = PyGL_Buffer_Buffer_GetItem<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods.sq_ass_item = PyGL_Buffer_Buffer_SetItem<DT>;
  PyGL_Buffer_BufferTypeDesc<DT>::Type.tp_as_sequence = &(PyGL_Buffer_BufferTypeDesc<DT>::SeqMethods);
  
  if (PyType_Ready(&PyGL_Buffer_BufferTypeDesc<DT>::Type) < 0)
  {
    return NULL;
  }
  
  return (PyObject*) &(PyGL_Buffer_BufferTypeDesc<DT>::Type);
}

// ---

template <DataType DT>
struct PyGL_Buffer_StructuredBuffer
{
  PyObject_HEAD
  StructuredBuffer<DT> *pb;
  bool own;
  bool isiter;
  size_t cur;
  PyObject *fields;
};

template <DataType DT>
struct PyGL_Buffer_StructuredBufferTypeDesc
{
  static PyTypeObject Type;
  static PyGetSetDef GetSeters[];
  static PyMethodDef Methods[];
  static PySequenceMethods SeqMethods;
};

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_New(PyTypeObject *t, PyObject *, PyObject *)
{
  PyObject *self = t->tp_alloc(t, 0);
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*)self;
  pbuf->pb = NULL;
  pbuf->own = true;
  pbuf->isiter = false;
  pbuf->cur = 0;
  pbuf->fields = PyDict_New();
  return self;
}

template <DataType DT>
int PyGL_Buffer_StructuredBuffer_Init(PyObject *self, PyObject *args, PyObject *)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*)self;

  if (PyTuple_Size(args) == 2)
  {
    PyObject *s = 0;
    int n = 0;

    if (!PyArg_ParseTuple(args, "O!i", &PyGL_Buffer_StructureType, &s, &n))
    {
      return -1;
    }

    pbuf->pb = new StructuredBuffer<DT>(*(((PyGL_Buffer_Structure*)s)->ps), n);
  }
  else if (PyTuple_Size(args) != 0)
  {
    PyErr_SetString(PyExc_RuntimeError, "No or two arguments");
    return -1;
  }
  else
  {
    pbuf->pb = new StructuredBuffer<DT>();
  }
  return 0;
}

template <DataType DT>
void PyGL_Buffer_StructuredBuffer_Delete(PyObject *self)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  Py_DECREF(pbuf->fields);
  if (pbuf->own && pbuf->pb != 0)
  {
    delete pbuf->pb;
  }
  self->ob_type->tp_free(self);
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_ToStr(PyObject *self)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  return PyString_FromString(pbuf->pb->toString().c_str());
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetType(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getType()));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetStructure(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  const Structure &s = pbuf->pb->getStructure();
  
  PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructureType, 0);
  ((PyGL_Buffer_Structure*)rv)->ps = (Structure*)&s;
  return rv;
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetFieldCount(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getFieldCount()));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetElementStride(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getElementStride()));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetElementCount(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getElementCount()));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetElementSize(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  return PyInt_FromLong(long(pbuf->pb->getElementSize()));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetRawPtr(PyObject *self, void*)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  typename StructuredBuffer<DT>::T *ptr = (typename StructuredBuffer<DT>::T *) *(pbuf->pb);
  
  PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_RawPtrType, NULL);
  ((PyGL_Buffer_RawPtr*)rv)->ptr = (void*) ptr;
  return rv;
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_FieldOffset(PyObject *self, PyObject *args)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  char *n = 0;
  
  if (!PyArg_ParseTuple(args, "s", &n))
  {
    return NULL;
  }
  
  try
  {
    return PyInt_FromLong(long(pbuf->pb->getFieldOffset(n)));
  }
  catch (std::runtime_error &e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  }
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_ElementOffset(PyObject *self, PyObject *args)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  int idx = 0;
  
  if (!PyArg_ParseTuple(args, "i", &idx))
  {
    return NULL;
  }
  
  if (idx < 0 || idx >= (int)pbuf->pb->getElementCount())
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return NULL;
  }
  
  return PyInt_FromLong((long) pbuf->pb->getElementOffset(idx));
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_Element(PyObject *self, PyObject *args)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  int idx = 0;
  
  if (!PyArg_ParseTuple(args, "i", &idx))
  {
    return NULL;
  }
  
  if (idx < 0 || idx >= (int)pbuf->pb->getElementCount())
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return NULL;
  }
  
  try
  {
    PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type, NULL);
    PyGL_Buffer_StructuredBuffer<DT> *b = (PyGL_Buffer_StructuredBuffer<DT>*)rv;
    b->isiter = pbuf->isiter;
    b->cur = pbuf->cur;
    *(b->pb) = pbuf->pb->getElement(idx);
    return rv;
  }
  catch (std::runtime_error &e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  }
  
  return NULL;
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_FieldBuffer(PyObject *self, PyObject *args)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  char *n = 0;
  
  if (!PyArg_ParseTuple(args, "s", &n))
  {
    return NULL;
  }
  
  try
  {
    PyObject *rv = PyDict_GetItemString(pbuf->fields, n);
    
    if (rv == 0)
    {
      PyErr_Clear();
      rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type, NULL);
      PyGL_Buffer_StructuredBuffer<DT> *b = (PyGL_Buffer_StructuredBuffer<DT>*)rv;
      b->isiter = pbuf->isiter;
      b->cur = pbuf->cur;
      PyDict_SetItemString(pbuf->fields, n, rv);
    }
    else
    {
      Py_INCREF(rv);
    }
    
    *(((PyGL_Buffer_StructuredBuffer<DT>*)rv)->pb) = pbuf->pb->getFieldBuffer(n);
    
    return rv;
  }
  catch (std::runtime_error &e)
  {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return NULL;
  }
}

template <DataType DT>
Py_ssize_t PyGL_Buffer_StructuredBuffer_Size(PyObject *self)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  if (pbuf->isiter)
  {
    return (Py_ssize_t) pbuf->pb->getFieldCount();
  }
  else
  {
    return (Py_ssize_t) (pbuf->pb->getElementCount() * pbuf->pb->getElementStride());
  }
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetItem(PyObject *self, Py_ssize_t idx)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  size_t numcomps;

  if (pbuf->isiter)
  {
    numcomps = pbuf->pb->getFieldCount();
  }
  else
  {
    numcomps = pbuf->pb->getElementCount() * pbuf->pb->getElementStride();
  }
  
  if (idx < 0 || idx >= (Py_ssize_t)numcomps)
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return NULL;
  }
  
  return TypeConvert<DT>::ToPy((*(pbuf->pb))[idx]);
}

template <DataType DT>
int PyGL_Buffer_StructuredBuffer_SetItem(PyObject *self, Py_ssize_t idx, PyObject *val)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return -1;
  }
  
  size_t numcomps;
  
  if (pbuf->isiter)
  {
    numcomps = pbuf->pb->getFieldCount();
  }
  else
  {
    numcomps = pbuf->pb->getElementCount() * pbuf->pb->getElementStride();
  }
  
  if (idx < 0 || idx >= (Py_ssize_t)numcomps)
  {
    PyErr_SetString(PyExc_IndexError, "Invalid index");
    return -1;
  }
  
  (*(pbuf->pb))[idx] = TypeConvert<DT>::FromPy(val);
  
  return 0;
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_GetAttr(PyObject *self, PyObject *pname)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  PyObject *rv = PyObject_GenericGetAttr(self, pname);
  if (rv != NULL)
  {
    return rv;
  }

  PyErr_Clear();
  
  const char *name = PyString_AsString(pname);
  
  const Structure &s = pbuf->pb->getStructure();
  
  if (s.hasField(name))
  {
    const Structure &fs = s.getField(name);
    if (fs.isTerminal())
    {
      return TypeConvert<DT>::ToPy((*(pbuf->pb))[fs.getOffset()]);
    }
    else
    {
      rv = PyDict_GetItemString(pbuf->fields, name);
      
      if (rv == 0)
      {
        PyErr_Clear();
        rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type, NULL);
        PyGL_Buffer_StructuredBuffer<DT> *b = (PyGL_Buffer_StructuredBuffer<DT>*)rv;
        b->isiter = pbuf->isiter;
        b->cur = pbuf->cur;
        PyDict_SetItemString(pbuf->fields, name, rv);
      }
      else
      {
        Py_INCREF(rv);
      }
      
      *(((PyGL_Buffer_StructuredBuffer<DT>*)rv)->pb) = pbuf->pb->getFieldBuffer(name);
      
      return rv;
    }
  }
  else
  {
    PyErr_Format(PyExc_AttributeError, "Unknown attribute \"%s\"", name);
    return NULL;
  }
}

template <DataType DT>
int PyGL_Buffer_StructuredBuffer_SetAttr(PyObject *self, PyObject *pname, PyObject *val)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  const char *name = PyString_AsString(pname);
  
  const Structure &s = pbuf->pb->getStructure();
  
  if (s.hasField(name))
  {
    const Structure &fs = s.getField(name);
    if (fs.isTerminal())
    {
      (*(pbuf->pb))[fs.getOffset()] = TypeConvert<DT>::FromPy(val);
      return 0;
    }
    else
    {
      PyErr_Format(PyExc_RuntimeError, "Attribute \"%s\" cannot be assigned", name);
      return -1;
    }
  }
  else
  {
    return PyObject_GenericSetAttr(self, pname, val);
  }
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_Iter(PyObject *self)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  if (!pbuf->isiter)
  {
    PyObject *rv = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type, NULL);
    
    PyGL_Buffer_StructuredBuffer<DT> *b = (PyGL_Buffer_StructuredBuffer<DT> *)rv;
    
    typename StructuredBuffer<DT>::T *ptr = *(pbuf->pb);
    size_t n = pbuf->pb->getElementCount();
    size_t es = pbuf->pb->getElementStride();
    ptr -= es;
    *(b->pb) = StructuredBuffer<DT>(pbuf->pb->getStructure(), ptr, n, es);
    b->isiter = true;
    
    return rv;
  }
  else
  {
    Py_INCREF(self);
    return self;
  }
}

template <DataType DT>
PyObject* PyGL_Buffer_StructuredBuffer_IterNext(PyObject *self)
{
  PyGL_Buffer_StructuredBuffer<DT> *pbuf = (PyGL_Buffer_StructuredBuffer<DT>*) self;
  
  if (!pbuf->pb)
  {
    PyErr_SetString(PyExc_RuntimeError, "Unbound object");
    return NULL;
  }
  
  if (!pbuf->isiter)
  {
    PyErr_SetString(PyExc_RuntimeError, "Not an iterator");
    return NULL;
  }
  
  if (pbuf->cur >= pbuf->pb->getElementCount())
  {
    PyErr_SetString(PyExc_StopIteration, "No more element to iterate");
    return NULL;
  }
  
  pbuf->pb->next();
  pbuf->cur++;
  
  Py_INCREF(self);
  return self;
}



template <DataType DT>
PyTypeObject PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type;

template <DataType DT>
PyGetSetDef PyGL_Buffer_StructuredBufferTypeDesc<DT>::GetSeters[] =
{
  {(char*)"type", PyGL_Buffer_StructuredBuffer_GetType<DT>, NULL, NULL, NULL},
  {(char*)"structure", PyGL_Buffer_StructuredBuffer_GetStructure<DT>, NULL, NULL, NULL},
  {(char*)"fieldCount", PyGL_Buffer_StructuredBuffer_GetFieldCount<DT>, NULL, NULL, NULL},
  {(char*)"elementStride", PyGL_Buffer_StructuredBuffer_GetElementStride<DT>, NULL, NULL, NULL},
  {(char*)"elementSize", PyGL_Buffer_StructuredBuffer_GetElementSize<DT>, NULL, NULL, NULL},
  {(char*)"elementCount", PyGL_Buffer_StructuredBuffer_GetElementCount<DT>, NULL, NULL, NULL},
  {(char*)"rawPtr", PyGL_Buffer_StructuredBuffer_GetRawPtr<DT>, NULL, NULL, NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

template <DataType DT>
PyMethodDef PyGL_Buffer_StructuredBufferTypeDesc<DT>::Methods[] =
{
  {"fieldOffset", PyGL_Buffer_StructuredBuffer_FieldOffset<DT>, METH_VARARGS, NULL},
  {"elementOffset", PyGL_Buffer_StructuredBuffer_ElementOffset<DT>, METH_VARARGS, NULL},
  {"element", PyGL_Buffer_StructuredBuffer_Element<DT>, METH_VARARGS, NULL},
  {"field", PyGL_Buffer_StructuredBuffer_FieldBuffer<DT>, METH_VARARGS, NULL},
  {NULL, NULL, NULL, NULL}
};

template <DataType DT>
PySequenceMethods PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods;

template <DataType DT>
PyObject* InitStructuredBufferClass(const char *className)
{
  INIT_TYPE(PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type, className, PyGL_Buffer_StructuredBuffer<DT>);
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_flags = Py_TPFLAGS_DEFAULT;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_new = PyGL_Buffer_StructuredBuffer_New<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_init = PyGL_Buffer_StructuredBuffer_Init<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_dealloc = PyGL_Buffer_StructuredBuffer_Delete<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_getset = PyGL_Buffer_StructuredBufferTypeDesc<DT>::GetSeters;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_methods = PyGL_Buffer_StructuredBufferTypeDesc<DT>::Methods;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_str = PyGL_Buffer_StructuredBuffer_ToStr<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_getattro = PyGL_Buffer_StructuredBuffer_GetAttr<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_setattro = PyGL_Buffer_StructuredBuffer_SetAttr<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_iter = PyGL_Buffer_StructuredBuffer_Iter<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_iternext = PyGL_Buffer_StructuredBuffer_IterNext<DT>;
  
  memset(&(PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods), 0, sizeof(PySequenceMethods));
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods.sq_length = PyGL_Buffer_StructuredBuffer_Size<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods.sq_item = PyGL_Buffer_StructuredBuffer_GetItem<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods.sq_ass_item = PyGL_Buffer_StructuredBuffer_SetItem<DT>;
  PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type.tp_as_sequence = &(PyGL_Buffer_StructuredBufferTypeDesc<DT>::SeqMethods);
  
  if (PyType_Ready(&PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type) < 0)
  {
    return NULL;
  }
  
  return (PyObject*) &(PyGL_Buffer_StructuredBufferTypeDesc<DT>::Type);
}

bool PyGL_Buffer_AddFields(Structure *s, PyObject *o)
{
  if (PyList_Check(o))
  {
    Py_ssize_t len = PyList_Size(o);
    
    if (len > 0)
    {
      // first entry MUST be a string
      PyObject *item = PyList_GetItem(o, 0);
      
      if (!PyString_Check(item))
      {
        PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.MakeStructure: invalid structure specification");
        return false;
      }
      
      Structure &ss = s->addField(PyString_AsString(item));
      
      // sub structure ?
      if (len == 2)
      {
        item = PyList_GetItem(o, 1);
        
        if (PyList_Check(item))
        {
          if (!PyGL_Buffer_AddFields(&ss, item))
          {
            return false;
          }
        }
        else if (PyString_Check(item))
        {
          s->addField(PyString_AsString(item));
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.MakeStructure: invalid structure specification");
          return false;
        }
      }
      else
      {
        for (Py_ssize_t i=1; i<len; ++i)
        {
          item = PyList_GetItem(o, i);
          if (!PyString_Check(item))
          {
            PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.MakeStructure: invalid structure specification");
            return false;
          }
          s->addField(PyString_AsString(item));
        }
      }
    }
    return true;
  }
  else if (PyString_Check(o))
  {
    s->addField(PyString_AsString(o));
    return true;
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "pygl.buffer.MakeStructure: invalid structure specification");
    return false;
  }
}

PyObject* PyGL_Buffer_MakeStructure(PyObject *, PyObject *args)
{  
  PyObject *pstruct = PyObject_CallObject((PyObject*)&PyGL_Buffer_StructureType, NULL);
  
  Structure *s = ((PyGL_Buffer_Structure*)pstruct)->ps;
  
  for (Py_ssize_t i=0; i<PyTuple_Size(args); ++i)
  {
    if (!PyGL_Buffer_AddFields(s, PyTuple_GetItem(args, i)))
    {
      Py_DECREF(pstruct);
      return NULL;
    }
  }
  
  s->finalize();
  
  return pstruct;
}

PyObject* PyGL_Buffer_New(PyObject *, PyObject *args)
{
  if (PyTuple_Size(args) == 2)
  {
    int t, n;
    
    if (!PyArg_ParseTuple(args, "ii", &t, &n))
    {
      return NULL;
    }
    
    PyObject *a = Py_BuildValue("(i)", n);
    PyObject *rv = 0;
    
    switch (t) {
    case DT_UBYTE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_UBYTE>::Type, a, NULL);
      break;
    case DT_USHORT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_USHORT>::Type, a, NULL);
      break;
    case DT_UINT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_UINT>::Type, a, NULL);
      break;
    case DT_ULONG:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_ULONG>::Type, a, NULL);
      break;
    case DT_BYTE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_BYTE>::Type, a, NULL);
      break;
    case DT_SHORT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_SHORT>::Type, a, NULL);
      break;
    case DT_INT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_INT>::Type, a, NULL);
      break;
    case DT_LONG:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_LONG>::Type, a, NULL);
      break;
    case DT_FLOAT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_FLOAT>::Type, a, NULL);
      break;
    case DT_DOUBLE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_BufferTypeDesc<DT_DOUBLE>::Type, a, NULL);
      break;
    default:
      Py_DECREF(a);
      PyErr_SetString(PyExc_ValueError, "Invalid type");
      return NULL;
    }
    
    Py_DECREF(a);
    return rv;
  }
  else if (PyTuple_Size(args) == 3)
  {
    int t, n;
    PyObject *s = 0;
    
    if (!PyArg_ParseTuple(args, "iOi", &t, &s, &n))
    {
      return NULL;
    }
    
    PyObject *a = Py_BuildValue("(Oi)", s, n);
    PyObject *rv = 0;
    
    switch (t) {
    case DT_UBYTE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_UBYTE>::Type, a, NULL);
      break;
    case DT_USHORT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_USHORT>::Type, a, NULL);
      break;
    case DT_UINT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_UINT>::Type, a, NULL);
      break;
    case DT_ULONG:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_ULONG>::Type, a, NULL);
      break;
    case DT_BYTE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_BYTE>::Type, a, NULL);
      break;
    case DT_SHORT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_SHORT>::Type, a, NULL);
      break;
    case DT_INT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_INT>::Type, a, NULL);
      break;
    case DT_LONG:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_LONG>::Type, a, NULL);
      break;
    case DT_FLOAT:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_FLOAT>::Type, a, NULL);
      break;
    case DT_DOUBLE:
      rv = PyObject_Call((PyObject*)&PyGL_Buffer_StructuredBufferTypeDesc<DT_DOUBLE>::Type, a, NULL);
      break;
    default:
      Py_DECREF(a);
      PyErr_SetString(PyExc_ValueError, "Invalid type");
      return NULL;
    }
    
    Py_DECREF(a);
    
    return rv;
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "2 or 3 arguments");
    return NULL;
  }
}

PyMethodDef PyGL_Buffer_Methods[] =
{
  {"MakeStructure", PyGL_Buffer_MakeStructure, METH_VARARGS, NULL},
  {"New", PyGL_Buffer_New, METH_VARARGS, NULL},
  {NULL, NULL, NULL, NULL}
};

bool PyGL_InitBuffer(PyObject *mod)
{
  PyObject *smod = Py_InitModule("buffer", PyGL_Buffer_Methods);
  
  INIT_TYPE(PyGL_Buffer_StructureType, "pygl.buffer.Structure", PyGL_Buffer_Structure);
  PyGL_Buffer_StructureType.tp_flags = Py_TPFLAGS_DEFAULT;
  PyGL_Buffer_StructureType.tp_new = PyGL_Buffer_Structure_New;
  PyGL_Buffer_StructureType.tp_init = PyGL_Buffer_Structure_Init;
  PyGL_Buffer_StructureType.tp_dealloc = PyGL_Buffer_Structure_Delete;
  PyGL_Buffer_StructureType.tp_getset = PyGL_Buffer_Structure_GetSeters;
  PyGL_Buffer_StructureType.tp_methods = PyGL_Buffer_Structure_Methods;
  PyGL_Buffer_StructureType.tp_str = PyGL_Buffer_Structure_ToString;
  
  if (PyType_Ready(&PyGL_Buffer_StructureType) < 0)
  {
    Py_DECREF(smod);
    return false;
  }
  
  INIT_TYPE(PyGL_Buffer_RawPtrType, "pygl.buffer.RawPtr", PyGL_Buffer_RawPtr);
  PyGL_Buffer_RawPtrType.tp_flags = Py_TPFLAGS_DEFAULT;
  PyGL_Buffer_RawPtrType.tp_new = PyGL_Buffer_RawPtr_New;
  PyGL_Buffer_RawPtrType.tp_init = PyGL_Buffer_RawPtr_Init;
  PyGL_Buffer_RawPtrType.tp_dealloc = PyGL_Buffer_RawPtr_Delete;
  PyGL_Buffer_RawPtrType.tp_getset = PyGL_Buffer_RawPtr_GetSeters;
  PyGL_Buffer_RawPtrType.tp_str = PyGL_Buffer_RawPtr_ToStr;
  
  if (PyType_Ready(&PyGL_Buffer_RawPtrType) < 0)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferb = InitBufferClass<DT_BYTE>("pygl.buffer.ByteBuffer");
  if (!bufferb)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *buffers = InitBufferClass<DT_SHORT>("pygl.buffer.ShortBuffer");
  if (!buffers)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferi = InitBufferClass<DT_INT>("pygl.buffer.IntBuffer");
  if (!bufferi)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferl = InitBufferClass<DT_LONG>("pygl.buffer.LongBuffer");
  if (!bufferl)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferub = InitBufferClass<DT_UBYTE>("pygl.buffer.UbyteBuffer");
  if (!bufferub)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferus = InitBufferClass<DT_USHORT>("pygl.buffer.UshortBuffer");
  if (!bufferus)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferui = InitBufferClass<DT_UINT>("pygl.buffer.UintBuffer");
  if (!bufferui)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferul = InitBufferClass<DT_ULONG>("pygl.buffer.UlongBuffer");
  if (!bufferul)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferf = InitBufferClass<DT_FLOAT>("pygl.buffer.FloatBuffer");
  if (!bufferf)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *bufferd = InitBufferClass<DT_DOUBLE>("pygl.buffer.DoubleBuffer");
  if (!bufferd)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferb = InitStructuredBufferClass<DT_BYTE>("pygl.buffer.StructuredByteBuffer");
  if (!sbufferb)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbuffers = InitStructuredBufferClass<DT_SHORT>("pygl.buffer.StructuredShortBuffer");
  if (!sbuffers)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferi = InitStructuredBufferClass<DT_INT>("pygl.buffer.StructuredIntBuffer");
  if (!sbufferi)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferl = InitStructuredBufferClass<DT_LONG>("pygl.buffer.StructuredLongBuffer");
  if (!sbufferl)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferub = InitStructuredBufferClass<DT_UBYTE>("pygl.buffer.StructuredUbyteBuffer");
  if (!sbufferub)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferus = InitStructuredBufferClass<DT_USHORT>("pygl.buffer.StructuredUshortBuffer");
  if (!sbufferus)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferui = InitStructuredBufferClass<DT_UINT>("pygl.buffer.StructuredUintBuffer");
  if (!sbufferui)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferul = InitStructuredBufferClass<DT_ULONG>("pygl.buffer.StructuredUlongBuffer");
  if (!sbufferul)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferf = InitStructuredBufferClass<DT_FLOAT>("pygl.buffer.StructuredFloatBuffer");
  if (!sbufferf)
  {
    Py_DECREF(smod);
    return false;
  }
  
  PyObject *sbufferd = InitStructuredBufferClass<DT_DOUBLE>("pygl.buffer.StructuredDoubleBuffer");
  if (!sbufferd)
  {
    Py_DECREF(smod);
    return false;
  }
  
  Py_INCREF(&PyGL_Buffer_StructureType);
  PyModule_AddObject(smod, "Structure", (PyObject*)&PyGL_Buffer_StructureType);
  
  Py_INCREF(&PyGL_Buffer_RawPtrType);
  PyModule_AddObject(smod, "RawPtr", (PyObject*)&PyGL_Buffer_RawPtrType);
  
  Py_INCREF(bufferb);
  PyModule_AddObject(smod, "ByteBuffer", bufferb);
  
  Py_INCREF(buffers);
  PyModule_AddObject(smod, "ShortBuffer", buffers);
  
  Py_INCREF(bufferi);
  PyModule_AddObject(smod, "IntBuffer", bufferi);
  
  Py_INCREF(bufferl);
  PyModule_AddObject(smod, "LongBuffer", bufferl);
  
  Py_INCREF(bufferub);
  PyModule_AddObject(smod, "UbyteBuffer", bufferub);
  
  Py_INCREF(bufferus);
  PyModule_AddObject(smod, "UshortBuffer", bufferus);
  
  Py_INCREF(bufferui);
  PyModule_AddObject(smod, "UintBuffer", bufferui);
  
  Py_INCREF(bufferul);
  PyModule_AddObject(smod, "UlongBuffer", bufferul);
  
  Py_INCREF(bufferf);
  PyModule_AddObject(smod, "FloatBuffer", bufferf);
  
  Py_INCREF(bufferd);
  PyModule_AddObject(smod, "DoubleBuffer", bufferd);
  
  Py_INCREF(bufferb);
  PyModule_AddObject(smod, "StructuredByteBuffer", sbufferb);
  
  Py_INCREF(buffers);
  PyModule_AddObject(smod, "StructuredShortBuffer", sbuffers);
  
  Py_INCREF(bufferi);
  PyModule_AddObject(smod, "StructuredIntBuffer", sbufferi);
  
  Py_INCREF(bufferl);
  PyModule_AddObject(smod, "StructuredLongBuffer", sbufferl);
  
  Py_INCREF(bufferub);
  PyModule_AddObject(smod, "StructuredUbyteBuffer", sbufferub);
  
  Py_INCREF(bufferus);
  PyModule_AddObject(smod, "StructuredUshortBuffer", sbufferus);
  
  Py_INCREF(bufferui);
  PyModule_AddObject(smod, "StructuredUintBuffer", sbufferui);
  
  Py_INCREF(bufferul);
  PyModule_AddObject(smod, "StructuredUlongBuffer", sbufferul);
  
  Py_INCREF(bufferf);
  PyModule_AddObject(smod, "StructuredFloatBuffer", sbufferf);
  
  Py_INCREF(bufferd);
  PyModule_AddObject(smod, "StructuredDoubleBuffer", sbufferd);
  
  PyModule_AddIntConstant(smod, "Byte", DT_BYTE);
  PyModule_AddIntConstant(smod, "Short", DT_SHORT);
  PyModule_AddIntConstant(smod, "Int", DT_INT);
  PyModule_AddIntConstant(smod, "Long", DT_LONG);
  PyModule_AddIntConstant(smod, "Ubyte", DT_UBYTE);
  PyModule_AddIntConstant(smod, "Ushort", DT_USHORT);
  PyModule_AddIntConstant(smod, "Uint", DT_UINT);
  PyModule_AddIntConstant(smod, "Ulong", DT_ULONG);
  PyModule_AddIntConstant(smod, "Float", DT_FLOAT);
  PyModule_AddIntConstant(smod, "Double", DT_DOUBLE);
  
  PyModule_AddObject(mod, "buffer", smod);
  
  return true;
}



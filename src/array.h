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

#ifndef __pygl_array_h_
#define __pygl_array_h_

#include "common.h"

extern int CheckArraySize(PyObject *arg);

template <typename U>
class Array1D
{
  public:
    
    typedef typename U::T T;
    
    Array1D()
      : mData(0), mSize(0), mOwns(true)
    {
    }
    
    Array1D(T *data, int sz)
      : mData(data), mSize(sz), mOwns(false)
    {
    }
    
    Array1D(int sz)
      : mSize(sz), mOwns(true)
    {
      mData = new T[sz];
    }
    
    Array1D(const Array1D<U> &rhs)
      : mData(rhs.mData), mSize(rhs.mSize), mOwns(rhs.mOwns)
    {
      rhs.mOwns = false;
    }
    
    ~Array1D()
    {
      if (mData && mOwns)
      {
        delete[] mData;
      }
    }
    
    Array1D<U>& operator=(const Array1D<U> &rhs)
    {
      if (this != &rhs)
      {
        if (mData && mOwns)
        {
          delete[] mData;
        }
        mData = rhs.mData;
        mSize = rhs.mSize;
        mOwns = rhs.mOwns;
        rhs.mOwns = false;
      }
      return *this;
    }
    
    inline operator T* ()
    {
      return mData;
    }
    
    inline operator const T* () const
    {
      return mData;
    }
    
    inline operator void* ()
    {
      return (void*)mData;
    }
    
    inline operator const void*() const
    {
      return (const void*)mData;
    }
    
    inline int size() const
    {
      return mSize;
    }
    
    PyObject* toPy()
    {
      if (!mData)
      {
        Py_RETURN_NONE;
      }
      PyObject *l = PyList_New(mSize);
      for (int i=0; i<mSize; ++i)
      {
        U v(mData[i]);
        PyList_SetItem(l, i, v.toPy());
      }
      return l;
    }
 
    bool fromPy(PyObject *o)
    {
      int sz = CheckArraySize(o);
      
      if (mData)
      {
        if (mSize != sz)
        {
          PyErr_SetString(PyExc_RuntimeError, "Array size mismatch");
          return false;
        }
      }
      else
      {
        mSize = sz;
        mOwns = true;
        mData = new T[sz];
      }
      
      if (mSize > 0)
      {
        for (int i=0; i<mSize; ++i)
        {
          PyObject *item = PySequence_GetItem(o, i);
          U v(item);
          mData[i] = T(v);
          Py_DECREF(item);
        }
      }
      
      return true;
    }
  
  protected:
    
    T *mData;
    int mSize;
    mutable bool mOwns;
};

#endif

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
#include "mem/managedobject.h"

enum
{
  COLUMN_MAJOR = 0,
  ROW_MAJOR,
};

extern int CheckArraySize(PyObject *arg);

template <typename U>
class Array1D : public MemoryManagedObject
{
  public:
    
    typedef typename U::T T;
    
    Array1D()
      : mData(0), mSize(0), mOwns(true)
    {
    }
    
    Array1D(PyObject *obj)
      : mData(0), mSize(0), mOwns(true)
    {
      fromPy(obj);
    }
    
    Array1D(T *data, int sz)
      : mData(data), mSize(sz), mOwns(false)
    {
    }
    
    Array1D(int sz)
      : mSize(sz), mOwns(true)
    {
      //mData = new T[sz];
      mData = (T*) MemoryManager::Instance().allocate(sz * sizeof(T));
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
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mSize * sizeof(T));
      }
    }
    
    Array1D<U>& operator=(const Array1D<U> &rhs)
    {
      if (this != &rhs)
      {
        if (mData && mOwns)
        {
          //delete[] mData;
          MemoryManager::Instance().deallocate(mData, mSize*sizeof(T));
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
 
    const T* fromPy(PyObject *o)
    {
      if (mData && mOwns)
      {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mSize*sizeof(T));
      }
      
      mData = 0;
      mSize = 0;
      mOwns = true;
      
      mSize = CheckArraySize(o);
      
      if (mSize > 0)
      {
        mData = (T*) MemoryManager::Instance().allocate(mSize*sizeof(T));
        for (int i=0; i<mSize; ++i)
        {
          PyObject *item = PySequence_GetItem(o, i);
          U v(item);
          mData[i] = T(v);
          Py_DECREF(item);
        }
      }
      
      return mData;
    }
  
  protected:
    
    T *mData;
    int mSize;
    mutable bool mOwns;
};


template <typename U>
class FlatArray2D : public MemoryManagedObject
{
  public:
    
    typedef typename U::T T;
    
    FlatArray2D()
      : mData(0), mRowSize(0), mColSize(0), mOwns(true)
    {
    }
    
    FlatArray2D(int nr, int nc)
      : mRowSize(nr), mColSize(nc), mOwns(true)
    {
      //mData = new T[nr * nc];
      mData = (T*) MemoryManager::Instance().allocate(nr * nc * sizeof(T));
    }
    
    FlatArray2D(T *data, int nr, int nc)
      : mData(data), mRowSize(nr), mColSize(nc), mOwns(false)
    {
    }
    
    FlatArray2D(PyObject *obj, int pyformat, int dstformat)
      : mData(0), mRowSize(0), mColSize(0), mOwns(true)
    {
      fromPy(obj, pyformat, dstformat);
    }
    
    FlatArray2D(const FlatArray2D<U> &rhs)
      : mData(rhs.mData), mRowSize(rhs.mRowSize), mColSize(rhs.mColSize),
        mOwns(rhs.mOwns)
    {
      rhs.mOwns = false;
    }
    
    ~FlatArray2D()
    {
      if (mData && mOwns)
      {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
      }
    }
    
    FlatArray2D<U>& operator=(const FlatArray2D<U> &rhs)
    {
      if (this != &rhs)
      {
        if (mData && mOwns)
        {
          //delete[] mData;
          MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
        }
        mData = rhs.mData;
        mRowSize = rhs.mRowSize;
        mColSize = rhs.mColSize;
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
    
    inline int numRows() const
    {
      return mRowSize;
    }
    
    inline int numColumns() const
    {
      return mColSize;
    }

    inline int size() const
    {
      return (mRowSize * mColSize);
    }
    
    PyObject* toPy(int srcformat, int pyformat)
    {
      
      if (!mData)
      {
        Py_RETURN_NONE;
      }
      
      int mRowStride, mColStride;
        
      if (srcformat == COLUMN_MAJOR)
      {
        mRowStride = 1;
        mColStride = mColSize;
      }
      else
      {
        mColStride = 1;
        mRowStride = mRowSize;
      }
      
      if (pyformat == ROW_MAJOR)
      {
        PyObject *rows = PyList_New(mRowSize);
        for (int r=0; r<mRowSize; ++r)
        {
          int idx = r * mRowStride;
          PyObject *row = PyList_New(mColSize);
          for (int c=0; c<mColSize; ++c, idx+=mColStride)
          {
            U v(mData[idx]);
            PyList_SetItem(row, c, v.toPy());
          }
          PyList_SetItem(rows, r, row);
        }
        return rows; 
      }
      else
      {
        PyObject *cols = PyList_New(mColSize);
        for (int c=0; c<mColSize; ++c)
        {
          int idx = c * mColStride;
          PyObject *col = PyList_New(mRowSize);
          for (int r=0; r<mRowSize; ++r, idx+=mRowStride)
          {
            U v(mData[idx]);
            PyList_SetItem(col, r, v.toPy());
          }
          PyList_SetItem(cols, c, col);
        }
        return cols;
      }
    }
    
    const T* fromPy(PyObject *obj, int pyformat, int dstformat)
    {
      if (mData && mOwns)
      {
        //delete[] mData;
        MemoryManager::Instance().deallocate(mData, mRowSize*mColSize*sizeof(T));
      }
      
      mRowSize = 0;
      mColSize = 0;
      mOwns = true;
      
      if (pyformat == ROW_MAJOR)
      {
        mRowSize = CheckArraySize(obj);
        int cs = -1;
        for (int i=0; i<mRowSize; ++i)
        {
          PyObject *col = PySequence_GetItem(obj, i);
          if (cs == -1)
          {
            cs = CheckArraySize(col);
          }
          else if (cs != CheckArraySize(col))
          {
            Py_DECREF(col);
            PyErr_SetString(PyExc_RuntimeError, "All columns must have the same dimension");
            return 0;
          }
          Py_DECREF(col);
        }
        mColSize = cs;
        
      }
      else
      {
        mColSize = CheckArraySize(obj);
        int rs = -1;
        for (int i=0; i<mColSize; ++i)
        {
          PyObject *row = PySequence_GetItem(obj, i);
          if (rs == -1)
          {
            rs = CheckArraySize(row);
          }
          else if (rs != CheckArraySize(row))
          {
            Py_DECREF(row);
            PyErr_SetString(PyExc_RuntimeError, "All rows must have the same dimension");
            return 0;
          }
          Py_DECREF(row);
        }
        mRowSize = rs;
      }
      
      if (mRowSize > 0 && mColSize > 0)
      {
        
        int mRowStride, mColStride;
        
        if (dstformat == COLUMN_MAJOR)
        {
          mRowStride = 1;
          mColStride = mColSize;
        }
        else
        {
          mColStride = 1;
          mRowStride = mRowSize;
        }
        
        //mData = new T[mRowSize * mColSize];
        mData = (T*) MemoryManager::Instance().allocate(mRowSize * mColSize * sizeof(T));        
        
        if (pyformat == COLUMN_MAJOR)
        {
          for (int c=0; c<mColSize; ++c)
          {
            int idx = c * mColStride;
            PyObject *col = PySequence_GetItem(obj, c);
            for (int r=0; r<mRowSize; ++r, idx+=mRowStride)
            {
              PyObject *pv = PySequence_GetItem(col, r);
              U v(pv);
              mData[idx] = T(v);
              Py_DECREF(pv);
            }
            Py_DECREF(col);
          }
          
        }
        else
        {
          for (int r=0; r<mRowSize; ++r)
          {
            int idx = r * mRowStride;
            PyObject *row = PySequence_GetItem(obj, r);
            for (int c=0; c<mColSize; ++c, idx+=mColStride)
            {
              PyObject *pv = PySequence_GetItem(row, c);
              U v(pv);
              mData[idx] = T(v);
              Py_DECREF(pv);
            }
            Py_DECREF(row);
          }
        }
      }
      
      return mData;
    }
    
  protected:
    
    T *mData;
    int mRowSize;
    int mColSize;
    mutable bool mOwns;
    
};


#endif

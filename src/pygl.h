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

#ifndef __pygl_h_
#define __pygl_h_

#include "common.h"
#include "convert.h"
#include "wrap.h"

#define REGISTER_GL_FUNC(table, name) \
  {\
    PyMethodDef tmp = {#name, py_gl##name, METH_VARARGS, NULL};\
    table.push_back(tmp);\
  }

class PyGL
{
  public:
    
    static GLenum ENUM_ERROR;
    
    static PyGL& Instance();
    
  public:
    
    typedef std::map<std::string, GLenum> ConstantMap;
    
    typedef std::vector<PyMethodDef> FunctionTable;
    
    enum Getter
    {
      Booleanv = 0,
      Integerv,
      Floatv,
      Doublev,
      Lightiv,
      Lightfv,
      Materialiv,
      Materialfv,
      TexEnviv,
      TexEnvfv,
      TexGeniv,
      TexGenfv,
      TexGendv,
      TexParameteriv,
      TexParameterfv,
      TexLevelParameteriv,
      TexLevelParameterfv,
      // GL 1.5
      BufferParameteriv,
      Queryiv,
      QueryObjectuiv,
      QueryObjectiv,
      // GL 2.0
      Programiv,
      Shaderiv
    };
    
    typedef std::map<Getter, std::map<GLenum, GLint> > GetParamDimMap;
    typedef std::map<GLenum, GLenum> DependentParamDimMap;
    
  public:
    
    PyGL();
    ~PyGL();
    
    inline void setVersion(double v)
    {
      if (v > mVersion)
      {
        mVersion = v;
      }
    }
    
    inline double getVersion() const
    {
      return mVersion;
    }
    
    void setPyModule(PyObject *m)
    {
      mModule = m;
    }

    PyObject* getPyModule()
    {
      return mModule;
    }
    
    GLenum getConstant(const std::string &name);
    
    void initConstants();
    
    void initFunctions();
    
    void registerPyFunctions(PyObject *m);
    
    void registerPyConstants(PyObject *m);
    
    inline void addParamDim(Getter g, GLenum p, GLint d)
    {
#ifdef _DEBUG
      if (mParamDim.find(g) != mParamDim.end())
      {
        if (mParamDim[g].find(p) != mParamDim[g].end())
        {
          if (mParamDim[g][p] != d)
          {
            std::cout << "Parameter dim overriden with different size" << std::endl;
          }
        }
      }
#endif
      mParamDim[g][p] = d;
    }
    
    inline void addDependentParamDim(Getter g, GLenum p, GLenum d)
    {
#ifdef _DEBUG
      if (mParamDim.find(g) != mParamDim.end())
      {
        if (mParamDim[g].find(p) != mParamDim[g].end())
        {
          if (mParamDim[g][p] != -1)
          {
            std::cout << "Parameter dim overriden with different size" << std::endl;
          }
        }
      }
      if (mDependentDim.find(p) != mDependentDim.end())
      {
        if (mDependentDim[p] != d)
        {
          std::cout << "Dependent parameter dim overridden with different param" << std::endl;
        }
      }
#endif
      mParamDim[g][p] = -1;
      mDependentDim[p] = d;
    }
    
    inline int getParamDim(Getter g, GLenum p) const
    {
      GetParamDimMap::const_iterator git = mParamDim.find(g);
      if (git == mParamDim.end())
      {
        return 0;
      }
      std::map<GLenum, GLint>::const_iterator dit = git->second.find(p);
      if (dit == git->second.end())
      {
        return 0;
      }
      if (dit->second <= 0)
      {
#ifdef _DEBUG
        std::cout << "Get dependent size..." << std::endl;
#endif
        DependentParamDimMap::const_iterator fit = mDependentDim.find(p);
        if (fit != mDependentDim.end())
        {
          // will that always be glGetIntegerv ?
          GLint n = 0;
          glGetIntegerv(fit->second, &n);
#ifdef _DEBUG
          std::cout << "-> " << n << std::endl;
#endif
          return n;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return dit->second;
      }
    }
    
  protected:
    
    ConstantMap mConstants;
    FunctionTable mFunctions;
    std::map<std::string, bool> mExts;
    GetParamDimMap mParamDim;
    DependentParamDimMap mDependentDim;
    double mVersion;
    PyObject *mModule;
    
    static PyGL * msInstance;
};

#endif

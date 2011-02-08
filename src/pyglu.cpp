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

#include "common.h"
#include "convert.h"
#include "wrap.h"

#define REGISTER_GLU_FUNC(Name) \
  {\
    PyMethodDef tmp = {#Name, &PyGLU::py_glu##Name, METH_VARARGS, NULL};\
    mFunctions.push_back(tmp);\
  }


class PyGLU
{
  public:
    
    static GLenum ENUM_ERROR;
    
  public:
    
    PyGLU()
      : mQuadric(0), mTess(0), mNURBS(0)
    {
      assert(msInstance == 0);
      msInstance = this;
      mContourVertices = PyList_New(0);
    }
    
    ~PyGLU()
    {
      msInstance = 0;
      
      Py_DECREF(mContourVertices);
      
      TessCallbacksMap::iterator tit = mTessCallbacks.begin();
      while (tit != mTessCallbacks.end())
      {
        Py_XDECREF(tit->second.Begin);
        Py_XDECREF(tit->second.End);
        Py_XDECREF(tit->second.EdgeFlag);
        Py_XDECREF(tit->second.Vertex);
        Py_XDECREF(tit->second.Combine);
        Py_XDECREF(tit->second.Error);
        Py_XDECREF(tit->second.pdata);
        ++tit;
      }
      
      NurbsCallbacksMap::iterator nit = mNurbsCallbacks.begin();
      while (nit != mNurbsCallbacks.end())
      {
        Py_XDECREF(nit->second.Begin);
        Py_XDECREF(nit->second.Vertex);
        Py_XDECREF(nit->second.Normal);
        Py_XDECREF(nit->second.Color);
        Py_XDECREF(nit->second.TexCoord);
        Py_XDECREF(nit->second.End);
        Py_XDECREF(nit->second.Error);
        Py_XDECREF(nit->second.data);
        ++nit;
      }
    }
    
    inline GLenum getConstant(const std::string &str)
    {
      std::map<std::string, GLenum>::iterator it = mConstants.find(str);
      if (it != mConstants.end())
      {
        return it->second;
      }
      else
      {
        return ENUM_ERROR;
      }
    }

  public:
    
    inline static PyGLU& Instance()
    {
      if (msInstance == 0)
      {
        new PyGLU();
      }
      return *msInstance;
    }

  public: // GLU callbacks
    
    // Quadrics
    static void CALLBACK py_gluQuadricErrorProc(GLenum e)
    {
      PyObject *func = Instance().getCurrentQuadricCallback();
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", e);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    // Nurbs
#ifdef GLU_VERSION_1_3
    
    static void CALLBACK py_gluNurbsBeginProc(GLenum e, void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsBeginCallback();
      if (func != Py_None)
      {
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(iO)", e, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluNurbsVertexProc(GLfloat *v, void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsVertexCallback();
      if (func != Py_None)
      {
        PyObject *pv = Array1D<Float>(v, 3).toPy();
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(OO)", pv, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
        Py_DECREF(pv);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluNurbsNormalProc(GLfloat *n, void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsNormalCallback();
      if (func != Py_None)
      {
        PyObject *pn = Array1D<Float>(n, 3).toPy();
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(OO)", pn, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
        Py_DECREF(pn);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluNurbsColorProc(GLfloat *c, void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsColorCallback();
      if (func != Py_None)
      {
        PyObject *pc = Array1D<Float>(c, 4).toPy();
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(OO)", pc, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
        Py_DECREF(pc);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluNurbsTexCoordProc(GLfloat *t, void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsTexCoordCallback();
      if (func != Py_None)
      {
        int n = Instance().getNurbsTexCoordDim(ud);
        PyObject *pt = Array1D<Float>(t, n).toPy();
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(OO)", pt, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
        Py_DECREF(pt);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluNurbsEndProc(void *ud)
    {
      PyObject *func = Instance().getCurrentNurbsEndCallback();
      if (func != Py_None)
      {
        PyObject *pud = Instance().getNurbsData(ud);
        PyObject *args = Py_BuildValue("(O)", pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
#endif
    
    static void CALLBACK py_gluNurbsErrorProc(GLenum e)
    {
      PyObject *func = Instance().getCurrentNurbsErrorCallback();
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", e);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    // Tess
    static void CALLBACK py_gluTessBeginProc(GLenum e, void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorBeginCallback();
      if (func != Py_None)
      {
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        PyObject *args = Py_BuildValue("(iO)", e, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluTessEndProc(void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorEndCallback();
      if (func != Py_None)
      {
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        PyObject *args = Py_BuildValue("(O)", pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluTessEdgeFlagProc(GLboolean b, void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorEdgeFlagCallback();
      if (func != Py_None)
      {
        PyObject *pb = (b == GL_TRUE ? Py_True : Py_False);
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        PyObject *args = Py_BuildValue("(OO)", pb, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluTessVertexProc(void *vd, void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorVertexCallback();
      if (func != Py_None)
      {
        PyObject *pvd = Instance().getTessContourVertex(vd);
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        PyObject *args = Py_BuildValue("(OO)", pvd, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
        Py_DECREF(pvd);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluTessCombineProc(GLdouble coords[3], void *verts[4], GLfloat weights[4], void **out, void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorCombineCallback();
      if (func != Py_None)
      {
        int i;
        
        // coords
        PyObject *pcoords = Array1D<Double>(coords, 3).toPy();
        
        // verts
        PyObject *pverts = PyList_New(4);
        for (i=0; i<4; ++i)
        {
          PyObject *pv = Instance().getTessContourVertex(verts[i]);
          PyList_SetItem(pverts, i, pv);
        }
        // weights
        PyObject *pweights = Array1D<Float>(weights, 4).toPy();
        
        // ud
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        
        // call
        PyObject *args = Py_BuildValue("(OOOO)", pcoords, pverts, pweights, pud);
        PyObject *rv = PyObject_CallObject(func, args);
        Py_DECREF(args);
        
        // store result in out contour vertex table)
        size_t id = Instance().addTessContourVertex(rv);
        *out = (void*)id;
        
        Py_XDECREF(rv);
        Py_DECREF(pud);
        Py_DECREF(pweights);
        Py_DECREF(pverts);
        Py_DECREF(pcoords);
      }
      Py_DECREF(func);
    }
    
    static void CALLBACK py_gluTessErrorProc(GLenum e, void *ud)
    {
      PyObject *func = Instance().getCurrentTesselatorErrorCallback();
      if (func != Py_None)
      {
        PyObject *pud = Instance().getTesselatorPolygonData(ud);
        PyObject *args = Py_BuildValue("(i0)", e, pud);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
        Py_DECREF(pud);
      }
      Py_DECREF(func);
    }
    
  protected: // Callback data
  
    // Quadric
    
    typedef std::map<void*, PyObject*> QuadricCallbackMap;
    
    QuadricCallbackMap mQuadricCallbacks;
    void *mQuadric;
    
    struct QuadricT
    {
      typedef GLUquadric T;
    };
    typedef TypedPtr<QuadricT> Quadric;
    
    // Tess
    
    struct TessCallbacks
    {
      PyObject* Begin;
      PyObject* End;
      PyObject* EdgeFlag;
      PyObject* Vertex;
      PyObject* Combine;
      PyObject* Error;
      PyObject* pdata; // for user data passed to gluTessBeginPolygon
    };
    
    typedef std::map<void*, TessCallbacks> TessCallbacksMap;
    
    TessCallbacksMap mTessCallbacks;
    void *mTess;
    PyObject *mContourVertices;
    
    struct TessT
    {
      typedef GLUtesselator T;
    };
    typedef TypedPtr<TessT> Tess;
    
    // Nurbs
    
    struct NurbsCallbacks
    {
      PyObject* Begin;
      PyObject* Vertex;
      PyObject* Normal;
      PyObject* Color;
      PyObject* TexCoord;
      PyObject* End;
      PyObject* Error;
      PyObject* data; // for user data passed to gluNurbsCallbackData
      int tdim; // texture coord dimension (check for GL_MAP[1|2]_TEXTURE_COORD_[1|2|3|4])
    };
    
    typedef std::map<void*, NurbsCallbacks> NurbsCallbacksMap;
    
    NurbsCallbacksMap mNurbsCallbacks;
    void *mNURBS;
    
    struct NurbsT
    {
      typedef GLUnurbs T;
    };
    typedef TypedPtr<NurbsT> Nurbs;
    
  public: // Callbacks management
    
#ifdef PYGL_GLU_VARIADIC_CALLBACK
    typedef GLvoid (CALLBACK *GLUcallback)(...);
#else
    typedef void (CALLBACK *GLUcallback)();
#endif

    // Quadrics
  
    void addQuadricCallback(GLUquadric *q, PyObject *func)
    {
      void *key = (void*)q;
      
      Py_INCREF(func);
      
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(key);
      
      if (it != mQuadricCallbacks.end())
      {
        Py_DECREF(it->second);
      }
      
      mQuadricCallbacks[key] = func;
      
      gluQuadricCallback(q, GLU_ERROR, (GLUcallback)py_gluQuadricErrorProc);
    }
    
    void delQuadricCallback(GLUquadric *q)
    {
      void *key = (void*)q;
      
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(key);
      
      if (it != mQuadricCallbacks.end())
      {
        Py_DECREF(it->second);
        mQuadricCallbacks.erase(it);
      }
      
      gluQuadricCallback(q, GLU_ERROR, (GLUcallback)0);
    }
    
    PyObject* getCurrentQuadricCallback()
    {
      QuadricCallbackMap::iterator it = mQuadricCallbacks.find(mQuadric);
      if (it != mQuadricCallbacks.end())
      {
        Py_INCREF(it->second);
        return it->second;
      }
      Py_RETURN_NONE;
    }
    
    inline void setCurrentQuadric(GLUquadric *q)
    {
      mQuadric = (void*) q;
    }
    
    // Tess

#define ADD_TESS_CALLBACK(which, cbe)\
    void addTesselator##which##Callback(GLUtesselator *t, PyObject *func)\
    {\
      void *key = (void*)t;\
      Py_INCREF(func);\
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);\
      if (it == mTessCallbacks.end())\
      {\
        mTessCallbacks[key].Begin = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].End = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].EdgeFlag = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].Vertex = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].Combine = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].Error = Py_None; Py_INCREF(Py_None);\
        mTessCallbacks[key].pdata = Py_None; Py_INCREF(Py_None);\
      }\
      else\
      {\
        Py_DECREF(it->second.which);\
      }\
      mTessCallbacks[key].which = func;\
      gluTessCallback(t, cbe, (GLUcallback)py_gluTess##which##Proc);\
    }

#define DEL_TESS_CALLBACK(which, cbe)\
    void delTesselator##which##Callback(GLUtesselator *t)\
    {\
      void *key = (void*)t;\
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);\
      if (it != mTessCallbacks.end())\
      {\
        Py_DECREF(it->second.which);\
        it->second.which = Py_None;\
        Py_INCREF(Py_None);\
      }\
      gluTessCallback(t, cbe, (GLUcallback)0);\
    }

#define GET_TESS_CALLBACK(which)\
    PyObject* getCurrentTesselator##which##Callback()\
    {\
      TessCallbacksMap::iterator it = mTessCallbacks.find(mTess);\
      if (it != mTessCallbacks.end())\
      {\
        Py_INCREF(it->second.which);\
        return it->second.which;\
      }\
      Py_RETURN_NONE;\
    }
    
    ADD_TESS_CALLBACK(Begin, GLU_TESS_BEGIN_DATA);
    ADD_TESS_CALLBACK(EdgeFlag, GLU_TESS_EDGE_FLAG_DATA);
    ADD_TESS_CALLBACK(Vertex, GLU_TESS_VERTEX_DATA);
    ADD_TESS_CALLBACK(Combine, GLU_TESS_COMBINE_DATA);
    ADD_TESS_CALLBACK(End, GLU_TESS_END_DATA);
    ADD_TESS_CALLBACK(Error, GLU_TESS_ERROR_DATA);
    
    DEL_TESS_CALLBACK(Begin, GLU_TESS_BEGIN_DATA);
    DEL_TESS_CALLBACK(EdgeFlag, GLU_TESS_EDGE_FLAG_DATA);
    DEL_TESS_CALLBACK(Vertex, GLU_TESS_VERTEX_DATA);
    DEL_TESS_CALLBACK(Combine, GLU_TESS_COMBINE_DATA);
    DEL_TESS_CALLBACK(End, GLU_TESS_END_DATA);
    DEL_TESS_CALLBACK(Error, GLU_TESS_ERROR_DATA);
    
    GET_TESS_CALLBACK(Begin);
    GET_TESS_CALLBACK(EdgeFlag);
    GET_TESS_CALLBACK(Vertex);
    GET_TESS_CALLBACK(Combine);
    GET_TESS_CALLBACK(End);
    GET_TESS_CALLBACK(Error);
    
    void setTesselatorPolygonData(GLUtesselator *t, PyObject *pdata)
    {
      void *key = (void*)t;
      
      Py_INCREF(pdata);
      
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);
      
      if (it != mTessCallbacks.end())
      {
        Py_DECREF(it->second.pdata);
      }
      
      mTessCallbacks[key].pdata = pdata;
    }
    
    PyObject* getTesselatorPolygonData(void *ud)
    {
      TessCallbacksMap::iterator it = mTessCallbacks.find(ud);
      if (it != mTessCallbacks.end())
      {
        Py_INCREF(it->second.pdata);
        return it->second.pdata;
      }
      Py_RETURN_NONE;
    }
    
    void delAllTesselatorCallbacks(GLUtesselator *t)
    {
      delTesselatorBeginCallback(t);
      delTesselatorEndCallback(t);
      delTesselatorVertexCallback(t);
      delTesselatorCombineCallback(t);
      delTesselatorEdgeFlagCallback(t);
      delTesselatorErrorCallback(t);
      void *key = (void*)t;
      TessCallbacksMap::iterator it = mTessCallbacks.find(key);
      if (it != mTessCallbacks.end())
      {
        mTessCallbacks.erase(it);
      }
    }
    
    inline void setCurrentTesselator(GLUtesselator *t)
    {
      mTess = (void*)t;
    }
    
    size_t addTessContourVertex(PyObject *cv)
    {
      size_t id = PyList_Size(mContourVertices);
      PyList_Append(mContourVertices, cv);
      return id;
    }
    
    void clearTessContourVertices()
    {
      Py_DECREF(mContourVertices);
      mContourVertices = PyList_New(0);
    }
    
    PyObject* getTessContourVertex(void *ud)
    {
      Py_ssize_t idx = (Py_ssize_t)ud;
      if (idx < 0 || idx >= PyList_Size(mContourVertices))
      {
        Py_RETURN_NONE;
      }
      else
      {
        PyObject *rv = PyList_GetItem(mContourVertices, idx);
        Py_INCREF(rv);
        return rv;
      }
    }
    
#undef ADD_TESS_CALLBACK
#undef DEL_TESS_CALLBACK
#undef GET_TESS_CALLBACK
    
    // Nurbs
    
#define ADD_NURBS_CALLBACK(which, cbe)\
    void addNurbs##which##Callback(GLUnurbs *n, PyObject *func)\
    {\
      void *key = (void*)n;\
      Py_INCREF(func);\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);\
      if (it == mNurbsCallbacks.end())\
      {\
        mNurbsCallbacks[key].Begin = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].Vertex = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].Normal = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].Color = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].TexCoord = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].End = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].Error = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].data = Py_None; Py_INCREF(Py_None);\
        mNurbsCallbacks[key].tdim = 0;\
      }\
      else\
      {\
        Py_DECREF(it->second.which);\
      }\
      mNurbsCallbacks[key].which = func;\
      gluNurbsCallback(n, cbe, (GLUcallback)py_gluNurbs##which##Proc);\
    }

#define DEL_NURBS_CALLBACK(which, cbe)\
    void delNurbs##which##Callback(GLUnurbs *n)\
    {\
      void *key = (void*)n;\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);\
      if (it != mNurbsCallbacks.end())\
      {\
        Py_DECREF(it->second.which);\
        Py_INCREF(Py_None);\
        it->second.which = Py_None;\
      }\
      gluNurbsCallback(n, cbe, (GLUcallback)0);\
    }

#define GET_NURBS_CALLBACK(which)\
    PyObject* getCurrentNurbs##which##Callback()\
    {\
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(mNURBS);\
      if (it != mNurbsCallbacks.end())\
      {\
        Py_INCREF(it->second.which);\
        return it->second.which;\
      }\
      Py_RETURN_NONE;\
    }
    
#ifdef GLU_VERSION_1_3
    
    ADD_NURBS_CALLBACK(Begin, GLU_NURBS_BEGIN_DATA);
    ADD_NURBS_CALLBACK(Vertex, GLU_NURBS_VERTEX_DATA);
    ADD_NURBS_CALLBACK(Normal, GLU_NURBS_NORMAL_DATA);
    ADD_NURBS_CALLBACK(TexCoord, GLU_NURBS_TEXTURE_COORD_DATA);
    ADD_NURBS_CALLBACK(Color, GLU_NURBS_COLOR_DATA);
    ADD_NURBS_CALLBACK(End, GLU_NURBS_END_DATA);
    ADD_NURBS_CALLBACK(Error, GLU_NURBS_ERROR);
    
    DEL_NURBS_CALLBACK(Begin, GLU_NURBS_BEGIN_DATA);
    DEL_NURBS_CALLBACK(Vertex, GLU_NURBS_VERTEX_DATA);
    DEL_NURBS_CALLBACK(Normal, GLU_NURBS_NORMAL_DATA);
    DEL_NURBS_CALLBACK(TexCoord, GLU_NURBS_TEXTURE_COORD_DATA);
    DEL_NURBS_CALLBACK(Color, GLU_NURBS_COLOR_DATA);
    DEL_NURBS_CALLBACK(End, GLU_NURBS_END_DATA);
    DEL_NURBS_CALLBACK(Error, GLU_NURBS_ERROR);
    
    GET_NURBS_CALLBACK(Begin);
    GET_NURBS_CALLBACK(Vertex);
    GET_NURBS_CALLBACK(Normal);
    GET_NURBS_CALLBACK(TexCoord);
    GET_NURBS_CALLBACK(Color);
    GET_NURBS_CALLBACK(End);
    GET_NURBS_CALLBACK(Error);
    
#else
    
    ADD_NURBS_CALLBACK(Error, GLU_ERROR);
    
    DEL_NURBS_CALLBACK(Error, GLU_ERROR);
    
    GET_NURBS_CALLBACK(Error);
    
#endif
    
    inline void setCurrentNurbs(GLUnurbs *n)
    {
      mNURBS = (void*)n;
    }
    
    void delAllNurbsCallbacks(GLUnurbs *n)
    {
#ifdef GLU_VERSION_1_3
      delNurbsBeginCallback(n);
      delNurbsEndCallback(n);
      delNurbsVertexCallback(n);
      delNurbsNormalCallback(n);
      delNurbsColorCallback(n);
      delNurbsTexCoordCallback(n);
#endif
      delNurbsErrorCallback(n);
      
      void *key = (void*)n;
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it != mNurbsCallbacks.end())
      {
        Py_DECREF(it->second.data);
        mNurbsCallbacks.erase(it);
      }
    }
    
    void setNurbsData(GLUnurbs *n, PyObject *data)
    {
      void *key = (void*)n;
      
      Py_INCREF(data);
      
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it != mNurbsCallbacks.end())
      {
        Py_DECREF(it->second.data);
        
      }
      
      mNurbsCallbacks[key].data = data;
    }
    
    PyObject* getNurbsData(void *ud)
    {
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(ud);
      if (it != mNurbsCallbacks.end())
      {
        Py_INCREF(it->second.data);
        return it->second.data;
      }
      Py_RETURN_NONE;
    }
    
    void setNurbsTexCoordDim(GLUnurbs *n, int dim)
    {
      void *key = (void*)n;
      mNurbsCallbacks[key].tdim = dim;
    }
    
    int getNurbsTexCoordDim(void *key)
    {
      NurbsCallbacksMap::iterator it = mNurbsCallbacks.find(key);
      if (it != mNurbsCallbacks.end())
      {
        return it->second.tdim;
      }
      else
      {
        return 0;
      }
    }
    
#undef ADD_NURBS_CALLBACK
#undef DEL_NURBS_CALLBACK
#undef GET_NURBS_CALLBACK
    
  public: // lua functions
    
    static PyObject* py_gluErrorString(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum code(PyTuple_GetItem(args, 0));
      const GLubyte *str = gluErrorString(code);
      return PyString_FromString((const char*)str);
    }
    
    static PyObject* py_gluGetString(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum name(PyTuple_GetItem(args, 0));
      const GLubyte *str = gluGetString(name);
      return PyString_FromString((const char*)str);
    }
    
    static PyObject* py_gluOrtho2D(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Double, Double >::Call(self, args, gluOrtho2D);
    }
    
    static PyObject* py_gluPerspective(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Double, Double >::Call(self, args, gluPerspective);
    }
    
    static PyObject* py_gluPickMatrix(PyObject *, PyObject *args) {
      CHECK_ARG_COUNT(args, 5);
      Double x(PyTuple_GetItem(args, 0));
      Double y(PyTuple_GetItem(args, 1));
      Double w(PyTuple_GetItem(args, 2));
      Double h(PyTuple_GetItem(args, 3));
      Array1D<Int> viewport(PyTuple_GetItem(args, 4));
      if (viewport.size() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.PickMatrix: invalid viewport");
        return NULL;
      }
      gluPickMatrix(x, y, w, h, viewport);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluLookAt(PyObject *self, PyObject *args)
    {
      return WrapFunc9<Double, Double, Double, Double, Double, Double, Double, Double, Double >::Call(self, args, gluLookAt);
    }
    
    static PyObject* py_gluProject(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 6);
      Double ox(PyTuple_GetItem(args, 0));
      Double oy(PyTuple_GetItem(args, 1));
      Double oz(PyTuple_GetItem(args, 2));
      FlatArray2D<Double> model(PyTuple_GetItem(args, 3), ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.Project: invalid model matrix");
        return NULL;
      }
      FlatArray2D<Double> proj(PyTuple_GetItem(args, 4), ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.Project: invalid proj matrix");
        return NULL;
      }
      Array1D<Int> viewport(PyTuple_GetItem(args, 5));
      if (viewport.size() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.Project: invalid viewport");
      }
      GLdouble w[3];
      int r = gluProject(ox, oy, oz, model, proj, viewport, &w[0], &w[1], &w[2]);
      if (r != GL_TRUE)
      {
        Py_RETURN_NONE;
      }
      else
      {
        return Array1D<Double>(w, 3).toPy();
      }
    }
    
    static PyObject* py_gluUnProject(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 6);
      Double wx(PyTuple_GetItem(args, 0));
      Double wy(PyTuple_GetItem(args, 1));
      Double wz(PyTuple_GetItem(args, 2));
      FlatArray2D<Double> model(PyTuple_GetItem(args, 3), ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.UnProject: invalid model matrix");
        return NULL;
      }
      FlatArray2D<Double> proj(PyTuple_GetItem(args, 4), ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.UnProject: invalid proj matrix");
        return NULL;
      }
      Array1D<Int> viewport(PyTuple_GetItem(args, 6));
      if (viewport.size() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.UnProject: invalid viewport");
        return NULL;
      }
      GLdouble o[3];
      int r = gluUnProject(wx, wy, wz, model, proj, viewport, &o[0], &o[1], &o[2]);
      if (r != GL_TRUE)
      {
        Py_RETURN_NONE;
      }
      else
      {
        return Array1D<Double>(o, 3).toPy();
      }
    }
    
    static PyObject* py_gluScaleImage(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 9);
      Enum fmt(PyTuple_GetItem(args, 0));
      Int wi(PyTuple_GetItem(args, 1));
      Int hi(PyTuple_GetItem(args, 2));
      Enum ti(PyTuple_GetItem(args, 3));
      ConstPtr dati(PyTuple_GetItem(args, 4));
      Int wo(PyTuple_GetItem(args, 5));
      Int ho(PyTuple_GetItem(args, 6));
      Enum to(PyTuple_GetItem(args, 7));
      Ptr dato(PyTuple_GetItem(args, 8));
      return PyInt_FromLong(gluScaleImage(fmt, wi, hi, ti, dati, wo, ho, to, dato));
    }
    
    static PyObject* py_gluBuild1DMipmaps(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 6);
      Enum tgt(PyTuple_GetItem(args, 0));
      Int comp(PyTuple_GetItem(args, 1));
      Int w(PyTuple_GetItem(args, 2));
      Enum fmt(PyTuple_GetItem(args, 3));
      Enum typ(PyTuple_GetItem(args, 4));
      ConstPtr data(PyTuple_GetItem(args, 5));
      return PyInt_FromLong(gluBuild1DMipmaps(tgt, comp, w, fmt, typ, data));
    }
    
    static PyObject* py_gluBuild2DMipmaps(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 7);
      Enum tgt(PyTuple_GetItem(args, 0));
      Int comp(PyTuple_GetItem(args, 1));
      Int w(PyTuple_GetItem(args, 2));
      Int h(PyTuple_GetItem(args, 3));
      Enum fmt(PyTuple_GetItem(args, 4));
      Enum typ(PyTuple_GetItem(args, 5));
      ConstPtr data(PyTuple_GetItem(args, 6));
      return PyInt_FromLong(gluBuild2DMipmaps(tgt, comp, w, h, fmt, typ, data));
    }
    
    // Quadrics
    
    static PyObject* py_gluNewQuadric(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      GLUquadric *q = gluNewQuadric();
      return PyCObject_FromVoidPtr((void*)q, NULL);
    }
    
    static PyObject* py_gluDeleteQuadric(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().delQuadricCallback(q);
      return WrapFunc1<Quadric >::Call(self, args, gluDeleteQuadric);
    }
    
    static PyObject* py_gluQuadricNormals(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc2<Quadric, Enum >::Call(self, args, gluQuadricNormals);
    }
    
    static PyObject* py_gluQuadricTexture(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc2<Quadric, Boolean >::Call(self, args, gluQuadricTexture);
    }
    
    static PyObject* py_gluQuadricOrientation(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc2<Quadric, Enum >::Call(self, args, gluQuadricOrientation);
    }
    
    static PyObject* py_gluQuadricDrawStyle(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc2<Quadric, Enum >::Call(self, args, gluQuadricDrawStyle);
    }
    
    static PyObject* py_gluCylinder(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc6<Quadric, Double, Double, Double, Int, Int >::Call(self, args, gluCylinder);
    }
    
    static PyObject* py_gluDisk(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc5<Quadric, Double, Double, Int, Int >::Call(self, args, gluDisk);
    }
    
    static PyObject* py_gluPartialDisk(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc7<Quadric, Double, Double, Int, Int, Double, Double >::Call(self, args, gluPartialDisk);
    }
    
    static PyObject* py_gluSphere(PyObject *self, PyObject *args)
    {
      Quadric q(PyTuple_GetItem(args, 0));
      Instance().setCurrentQuadric(q);
      return WrapFunc4<Quadric, Double, Int, Int >::Call(self, args, gluSphere);
    }
    
    // Tesselator
    
    static PyObject* py_gluNewTess(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      GLUtesselator *t = gluNewTess();
      return PyCObject_FromVoidPtr((void*)t, NULL);
    }
    
    static PyObject* py_gluDeleteTess(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setTesselatorPolygonData(t, Py_None);
      Instance().delAllTesselatorCallbacks(t);
      return WrapFunc1<Tess >::Call(self, args, gluDeleteTess);
    }
    
    static PyObject* py_gluTessBeginPolygon(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      Instance().setTesselatorPolygonData(t, PyTuple_GetItem(args, 1));
      gluTessBeginPolygon(t, (void*)t);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluTessEndPolygon(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      return WrapFunc1<Tess >::Call(self, args, gluTessEndPolygon);
    }
  
    static PyObject* py_gluTessBeginContour(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      Instance().clearTessContourVertices();
      return WrapFunc1<Tess >::Call(self, args, gluTessBeginContour);
    }
    
    static PyObject* py_gluTessEndContour(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      return WrapFunc1<Tess >::Call(self, args, gluTessEndContour);
    }
    
    static PyObject* py_gluTessVertex(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 3);
      Tess t(PyTuple_GetItem(args, 0));
      Array1D<Double> coords(PyTuple_GetItem(args, 1));
      if (coords.size() != 3)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.TessVertex: invalid coords");
        return NULL;
      }
      size_t id = Instance().addTessContourVertex(PyTuple_GetItem(args, 2));
      Instance().setCurrentTesselator(t);
      gluTessVertex(t, coords, (void*)id);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluTessNormal(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      return WrapFunc4<Tess, Double, Double, Double >::Call(self, args, gluTessNormal);
    }
    
    static PyObject* py_gluTessProperty(PyObject *self, PyObject *args)
    {
      Tess t(PyTuple_GetItem(args, 0));
      Instance().setCurrentTesselator(t);
      return WrapFunc3<Tess, Enum, Double >::Call(self, args, gluTessProperty);
    }
    
    static PyObject* py_gluGetTessProperty(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      Tess t(PyTuple_GetItem(args, 0));
      Enum which(PyTuple_GetItem(args, 1));
      GLdouble val;
      Instance().setCurrentTesselator(t);
      gluGetTessProperty(t, which, &val);
      return PyFloat_FromDouble(val);
    }
    
    // Nurbs
    
    static PyObject* py_gluNewNurbsRenderer(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      GLUnurbs *n = gluNewNurbsRenderer();
      return PyCObject_FromVoidPtr((void*)n, NULL);
    }
    
    static PyObject* py_gluDeleteNurbsRenderer(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setNurbsData(n, Py_None);
      Instance().delAllNurbsCallbacks(n);
      gluDeleteNurbsRenderer(n);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluBeginSurface(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluBeginSurface);
    }
    
    static PyObject* py_gluEndSurface(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluEndSurface);
    }
    
    static PyObject* py_gluBeginCurve(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluBeginCurve);
    }
    
    static PyObject* py_gluEndCurve(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluEndCurve);
    }
    
    static PyObject* py_gluBeginTrim(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluBeginTrim);
    }
    
    static PyObject* py_gluEndTrim(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc1<Nurbs >::Call(self, args, gluEndTrim);
    }
    
    static PyObject* py_gluPwlCurve(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc5<Nurbs, Int, TypedPtr<Float>, Int, Enum >::Call(self, args, gluPwlCurve);
    }
    
    static PyObject* py_gluNurbsCurve(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc7<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Enum >::Call(self, args, gluNurbsCurve);
    }
    
    static PyObject* py_gluNurbsSurface(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc11<Nurbs, Int, TypedPtr<Float>, Int, TypedPtr<Float>, Int, Int, TypedPtr<Float>, Int, Int, Enum >::Call(self, args, gluNurbsSurface);
    }
    
    static PyObject* py_gluNurbsProperty(PyObject *self, PyObject *args)
    {
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      return WrapFunc3<Nurbs, Enum, Float >::Call(self, args, gluNurbsProperty);
    }
    
    static PyObject* py_gluGetNurbsProperty(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      Nurbs n(PyTuple_GetItem(args, 0));
      Enum p(PyTuple_GetItem(args, 1));
      Instance().setCurrentNurbs(n);
      GLfloat v;
      gluGetNurbsProperty(n, p, &v);
      return PyFloat_FromDouble(v);
    }
    
    static PyObject* py_gluLoadSamplingMatrices(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 4);
      Nurbs n(PyTuple_GetItem(args, 0));
      FlatArray2D<Float> model(PyTuple_GetItem(args, 1), ROW_MAJOR, COLUMN_MAJOR);
      if (model.numRows() != 4 || model.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.LoadSamplingMatrices: invalid modelview matrix");
        return NULL;
      }
      FlatArray2D<Float> proj(PyTuple_GetItem(args, 2), ROW_MAJOR, COLUMN_MAJOR);
      if (proj.numRows() != 4 || proj.numColumns() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.LoadSamplingMatrices: invalid projection matrix");
        return NULL;
      }
      Array1D<Int> viewport(PyTuple_GetItem(args, 3));
      if (viewport.size() != 4)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.LoadSamplingMatrices: invalid viewport");
        return NULL;
      }
      gluLoadSamplingMatrices(n, model, proj, viewport);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluQuadricCallback(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 3);
      
      Quadric q(PyTuple_GetItem(args, 0));
      Enum which(PyTuple_GetItem(args, 1));
      PyObject *func = PyTuple_GetItem(args, 2);
      
      if (which != GLU_ERROR)
      {
        PyErr_SetString(PyExc_RuntimeError, "glu.GLU_ERROR is the only valid option");
        return NULL;
      }
      
      if (func == Py_None)
      {
        Instance().delQuadricCallback(q);
        
      }
      else if (PyFunction_Check(func))
      {
        Instance().addQuadricCallback(q, func);
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Expected function as third argument");
        return NULL;
      }
      
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluTessCallback(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 3);
      
      Tess t(PyTuple_GetItem(args, 0));
      Enum which(PyTuple_GetItem(args, 1));
      PyObject *func = PyTuple_GetItem(args, 2);
      
      bool isnil = (func == Py_None);
      
      if (!isnil && !PyFunction_Check(func))
      {
        PyErr_SetString(PyExc_RuntimeError, "Expected function as third argument");
        return NULL;
      }
      
      switch (which)
      {
      case GLU_TESS_BEGIN:
      case GLU_TESS_BEGIN_DATA:
        if (isnil)
        {
          Instance().delTesselatorBeginCallback(t);
        }
        else
        {
          Instance().addTesselatorBeginCallback(t, func);
        }
        break;
      case GLU_TESS_EDGE_FLAG:
      case GLU_TESS_EDGE_FLAG_DATA:
        if (isnil)
        {
          Instance().delTesselatorEdgeFlagCallback(t);
        }
        else
        {
          Instance().addTesselatorEdgeFlagCallback(t, func);
        }
        break;
      case GLU_TESS_VERTEX:
      case GLU_TESS_VERTEX_DATA:
        if (isnil)
        {
          Instance().delTesselatorVertexCallback(t);
        }
        else
        {
          Instance().addTesselatorVertexCallback(t, func);
        }
        break;
      case GLU_TESS_COMBINE:
      case GLU_TESS_COMBINE_DATA:
        if (isnil)
        {
          Instance().delTesselatorCombineCallback(t);
        }
        else
        {
          Instance().addTesselatorCombineCallback(t, func);
        }
        break;
      case GLU_TESS_END:
      case GLU_TESS_END_DATA:
        if (isnil)
        {
          Instance().delTesselatorEndCallback(t);
        }
        else
        {
          Instance().addTesselatorEndCallback(t, func);
        }
        break;
      case GLU_TESS_ERROR:
      case GLU_TESS_ERROR_DATA:
        if (isnil)
        {
          Instance().delTesselatorErrorCallback(t);
        }
        else
        {
          Instance().addTesselatorErrorCallback(t, func);
        }
        break;
      default:
        PyErr_SetString(PyExc_RuntimeError, "Invalid callback name");
        return NULL;
      }
      
      Py_RETURN_NONE;
    }
    
    static PyObject* py_gluNurbsCallback(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 3);
      
      Nurbs n(PyTuple_GetItem(args, 0));
      Enum which(PyTuple_GetItem(args, 1));
      PyObject *func = PyTuple_GetItem(args, 2);
      
      bool isnil = (func == Py_None);
      if (!isnil && !PyFunction_Check(func))
      {
        PyErr_SetString(PyExc_RuntimeError, "Expected function as third argument");
        return NULL;
      }
      
#ifdef GLU_VERSION_1_3
      switch (which)
      {
      case GLU_NURBS_BEGIN:
      case GLU_NURBS_BEGIN_DATA:
        if (isnil)
        {
          Instance().delNurbsBeginCallback(n);
        }
        else
        {
          Instance().addNurbsBeginCallback(n, func);
        }
        break;
      case GLU_NURBS_VERTEX:
      case GLU_NURBS_VERTEX_DATA:
        if (isnil)
        {
          Instance().delNurbsVertexCallback(n);
        }
        else
        {
          Instance().addNurbsVertexCallback(n, func);
        }
        break;
      case GLU_NURBS_NORMAL:
      case GLU_NURBS_NORMAL_DATA:
        if (isnil)
        {
          Instance().delNurbsNormalCallback(n);
        }
        else
        {
          Instance().addNurbsNormalCallback(n, func);
        }
        break;
      case GLU_NURBS_COLOR:
      case GLU_NURBS_COLOR_DATA:
        if (isnil)
        {
          Instance().delNurbsColorCallback(n);
        }
        else
        {
          Instance().addNurbsColorCallback(n, func);
        }
        break;
      case GLU_NURBS_TEXTURE_COORD:
      case GLU_NURBS_TEXTURE_COORD_DATA:
        if (isnil)
        {
          Instance().delNurbsTexCoordCallback(n);
        }
        else
        {
          Instance().addNurbsTexCoordCallback(n, func);
        }
        break;
      case GLU_NURBS_END:
      case GLU_NURBS_END_DATA:
        if (isnil)
        {
          Instance().delNurbsEndCallback(n);
        }
        else
        {
          Instance().addNurbsEndCallback(n, func);
        }
        break;
      case GLU_NURBS_ERROR:
        if (isnil)
        {
          Instance().delNurbsErrorCallback(n);
        }
        else
        {
          Instance().addNurbsErrorCallback(n, func);
        }
        break;
      default:
        PyErr_SetString(PyExc_RuntimeError, "Invalid callback name");
        return NULL;
      }
#else
      if (which != GLU_ERROR)
      {
        PyErr_SetString(PyExc_RuntimeError, "Invalid callback name");
        return NULL;
      }
      if (isnil)
      {
        Instance().delNurbsErrorCallback(n);
      }
      else
      {
        Instance().addNurbsErrorCallback(n, func);
      }
#endif
      Py_RETURN_NONE;
    }
    
#ifdef GLU_VERSION_1_3
    
    static PyObject* py_gluNurbsCallbackData(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      Nurbs n(PyTuple_GetItem(args, 0));
      Instance().setCurrentNurbs(n);
      Instance().setNurbsData(n, PyTuple_GetItem(args, 1));
      gluNurbsCallbackData(n, (void*)(GLUnurbs*)n);
      Py_RETURN_NONE;
    }

#endif
  
    /*
    Backward comp:
      
    void APIENTRY gluBeginPolygon(GLUtesselator *tess);
    void APIENTRY gluNextContour(GLUtesselator *tess, GLenum type);
    void APIENTRY gluEndPolygon(GLUtesselator *tess);
      
    1.3:
      
    GLAPI GLint GLAPIENTRY gluBuild1DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
    GLAPI GLint GLAPIENTRY gluBuild2DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
    GLAPI GLint GLAPIENTRY gluBuild3DMipmaps (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
    GLAPI GLint GLAPIENTRY gluBuild3DMipmapLevels (GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data);
    GLAPI GLboolean GLAPIENTRY gluCheckExtension (const GLubyte *extName, const GLubyte *extString);
    */
  
  public:
  
    void initFunctions()
    {
      REGISTER_GLU_FUNC(ErrorString);
      REGISTER_GLU_FUNC(GetString);
      REGISTER_GLU_FUNC(Ortho2D);
      REGISTER_GLU_FUNC(Perspective);
      REGISTER_GLU_FUNC(PickMatrix);
      REGISTER_GLU_FUNC(LookAt);
      REGISTER_GLU_FUNC(Project);
      REGISTER_GLU_FUNC(UnProject);
      REGISTER_GLU_FUNC(ScaleImage);
      REGISTER_GLU_FUNC(Build1DMipmaps);
      REGISTER_GLU_FUNC(Build2DMipmaps);
      REGISTER_GLU_FUNC(NewQuadric);
      REGISTER_GLU_FUNC(DeleteQuadric);
      REGISTER_GLU_FUNC(QuadricNormals);
      REGISTER_GLU_FUNC(QuadricTexture);
      REGISTER_GLU_FUNC(QuadricOrientation);
      REGISTER_GLU_FUNC(QuadricDrawStyle);
      REGISTER_GLU_FUNC(Cylinder);
      REGISTER_GLU_FUNC(Disk);
      REGISTER_GLU_FUNC(PartialDisk);
      REGISTER_GLU_FUNC(Sphere);
      REGISTER_GLU_FUNC(NewTess);
      REGISTER_GLU_FUNC(DeleteTess);
      REGISTER_GLU_FUNC(TessBeginPolygon);
      REGISTER_GLU_FUNC(TessEndPolygon);
      REGISTER_GLU_FUNC(TessBeginContour);
      REGISTER_GLU_FUNC(TessEndContour);
      REGISTER_GLU_FUNC(TessVertex);
      REGISTER_GLU_FUNC(TessNormal);
      REGISTER_GLU_FUNC(TessProperty);
      REGISTER_GLU_FUNC(GetTessProperty);
      REGISTER_GLU_FUNC(NewNurbsRenderer);
      REGISTER_GLU_FUNC(DeleteNurbsRenderer);
      REGISTER_GLU_FUNC(BeginSurface);
      REGISTER_GLU_FUNC(EndSurface);
      REGISTER_GLU_FUNC(BeginCurve);
      REGISTER_GLU_FUNC(EndCurve);
      REGISTER_GLU_FUNC(BeginTrim);
      REGISTER_GLU_FUNC(EndTrim);
      REGISTER_GLU_FUNC(PwlCurve);
      REGISTER_GLU_FUNC(NurbsCurve);
      REGISTER_GLU_FUNC(NurbsSurface);
      REGISTER_GLU_FUNC(NurbsProperty);
      REGISTER_GLU_FUNC(GetNurbsProperty);
      REGISTER_GLU_FUNC(LoadSamplingMatrices);
      REGISTER_GLU_FUNC(QuadricCallback);
      REGISTER_GLU_FUNC(TessCallback);
      REGISTER_GLU_FUNC(NurbsCallback);
#ifdef GLU_VERSION_1_3
      REGISTER_GLU_FUNC(NurbsCallbackData);
#endif
    }
    
    void initConstants()
    {
      mConstants["VERSION_1_1"] = GLU_VERSION_1_1;
      mConstants["VERSION_1_2"] = GLU_VERSION_1_2;
      mConstants["INVALID_ENUM"] = GLU_INVALID_ENUM;
      mConstants["INVALID_VALUE"] = GLU_INVALID_VALUE;
      mConstants["OUT_OF_MEMORY"] = GLU_OUT_OF_MEMORY;
      mConstants["INCOMPATIBLE_GL_VERSION"] = GLU_INCOMPATIBLE_GL_VERSION;
      mConstants["VERSION"] = GLU_VERSION;
      mConstants["EXTENSIONS"] = GLU_EXTENSIONS;
      mConstants["TRUE"] = GLU_TRUE;
      mConstants["FALSE"] = GLU_FALSE;
      mConstants["SMOOTH"] = GLU_SMOOTH;
      mConstants["FLAT"] = GLU_FLAT;
      mConstants["NONE"] = GLU_NONE;
      mConstants["POINT"] = GLU_POINT;
      mConstants["LINE"] = GLU_LINE;
      mConstants["FILL"] = GLU_FILL;
      mConstants["SILHOUETTE"] = GLU_SILHOUETTE;
      mConstants["OUTSIDE"] = GLU_OUTSIDE;
      mConstants["INSIDE"] = GLU_INSIDE;
      mConstants["TESS_WINDING_RULE"] = GLU_TESS_WINDING_RULE;
      mConstants["TESS_BOUNDARY_ONLY"] = GLU_TESS_BOUNDARY_ONLY;
      mConstants["TESS_TOLERANCE"] = GLU_TESS_TOLERANCE;
      mConstants["TESS_WINDING_ODD"] = GLU_TESS_WINDING_ODD;
      mConstants["TESS_WINDING_NONZERO"] = GLU_TESS_WINDING_NONZERO;
      mConstants["TESS_WINDING_POSITIVE"] = GLU_TESS_WINDING_POSITIVE;
      mConstants["TESS_WINDING_NEGATIVE"] = GLU_TESS_WINDING_NEGATIVE;
      mConstants["TESS_WINDING_ABS_GEQ_TWO"] = GLU_TESS_WINDING_ABS_GEQ_TWO;
      mConstants["TESS_BEGIN"] = GLU_TESS_BEGIN;
      mConstants["TESS_VERTEX"] = GLU_TESS_VERTEX;
      mConstants["TESS_END"] = GLU_TESS_END;
      mConstants["TESS_ERROR"] = GLU_TESS_ERROR;
      mConstants["TESS_EDGE_FLAG"] = GLU_TESS_EDGE_FLAG;
      mConstants["TESS_COMBINE"] = GLU_TESS_COMBINE;
      mConstants["TESS_BEGIN_DATA"] = GLU_TESS_BEGIN_DATA;
      mConstants["TESS_VERTEX_DATA"] = GLU_TESS_VERTEX_DATA;
      mConstants["TESS_END_DATA"] = GLU_TESS_END_DATA;
      mConstants["TESS_ERROR_DATA"] = GLU_TESS_ERROR_DATA;
      mConstants["TESS_EDGE_FLAG_DATA"] = GLU_TESS_EDGE_FLAG_DATA;
      mConstants["TESS_COMBINE_DATA"] = GLU_TESS_COMBINE_DATA;
      mConstants["TESS_ERROR1"] = GLU_TESS_ERROR1;
      mConstants["TESS_ERROR2"] = GLU_TESS_ERROR2;
      mConstants["TESS_ERROR3"] = GLU_TESS_ERROR3;
      mConstants["TESS_ERROR4"] = GLU_TESS_ERROR4;
      mConstants["TESS_ERROR5"] = GLU_TESS_ERROR5;
      mConstants["TESS_ERROR6"] = GLU_TESS_ERROR6;
      mConstants["TESS_ERROR7"] = GLU_TESS_ERROR7;
      mConstants["TESS_ERROR8"] = GLU_TESS_ERROR8;
      mConstants["TESS_MISSING_BEGIN_POLYGON"] = GLU_TESS_MISSING_BEGIN_POLYGON;
      mConstants["TESS_MISSING_BEGIN_CONTOUR"] = GLU_TESS_MISSING_BEGIN_CONTOUR;
      mConstants["TESS_MISSING_END_POLYGON"] = GLU_TESS_MISSING_END_POLYGON;
      mConstants["TESS_MISSING_END_CONTOUR"] = GLU_TESS_MISSING_END_CONTOUR;
      mConstants["TESS_COORD_TOO_LARGE"] = GLU_TESS_COORD_TOO_LARGE;
      mConstants["TESS_NEED_COMBINE_CALLBACK"] = GLU_TESS_NEED_COMBINE_CALLBACK;
      mConstants["AUTO_LOAD_MATRIX"] = GLU_AUTO_LOAD_MATRIX;
      mConstants["CULLING"] = GLU_CULLING;
      mConstants["SAMPLING_TOLERANCE"] = GLU_SAMPLING_TOLERANCE;
      mConstants["DISPLAY_MODE"] = GLU_DISPLAY_MODE;
      mConstants["PARAMETRIC_TOLERANCE"] = GLU_PARAMETRIC_TOLERANCE;
      mConstants["SAMPLING_METHOD"] = GLU_SAMPLING_METHOD;
      mConstants["U_STEP"] = GLU_U_STEP;
      mConstants["V_STEP"] = GLU_V_STEP;
      mConstants["PATH_LENGTH"] = GLU_PATH_LENGTH;
      mConstants["PARAMETRIC_ERROR"] = GLU_PARAMETRIC_ERROR;
      mConstants["DOMAIN_DISTANCE"] = GLU_DOMAIN_DISTANCE;
      mConstants["MAP1_TRIM_2"] = GLU_MAP1_TRIM_2;
      mConstants["MAP1_TRIM_3"] = GLU_MAP1_TRIM_3;
      mConstants["OUTLINE_POLYGON"] = GLU_OUTLINE_POLYGON;
      mConstants["OUTLINE_PATCH"] = GLU_OUTLINE_PATCH;
      mConstants["NURBS_ERROR1"] = GLU_NURBS_ERROR1;
      mConstants["NURBS_ERROR2"] = GLU_NURBS_ERROR2;
      mConstants["NURBS_ERROR3"] = GLU_NURBS_ERROR3;
      mConstants["NURBS_ERROR4"] = GLU_NURBS_ERROR4;
      mConstants["NURBS_ERROR5"] = GLU_NURBS_ERROR5;
      mConstants["NURBS_ERROR6"] = GLU_NURBS_ERROR6;
      mConstants["NURBS_ERROR7"] = GLU_NURBS_ERROR7;
      mConstants["NURBS_ERROR8"] = GLU_NURBS_ERROR8;
      mConstants["NURBS_ERROR9"] = GLU_NURBS_ERROR9;
      mConstants["NURBS_ERROR10"] = GLU_NURBS_ERROR10;
      mConstants["NURBS_ERROR11"] = GLU_NURBS_ERROR11;
      mConstants["NURBS_ERROR12"] = GLU_NURBS_ERROR12;
      mConstants["NURBS_ERROR13"] = GLU_NURBS_ERROR13;
      mConstants["NURBS_ERROR14"] = GLU_NURBS_ERROR14;
      mConstants["NURBS_ERROR15"] = GLU_NURBS_ERROR15;
      mConstants["NURBS_ERROR16"] = GLU_NURBS_ERROR16;
      mConstants["NURBS_ERROR17"] = GLU_NURBS_ERROR17;
      mConstants["NURBS_ERROR18"] = GLU_NURBS_ERROR18;
      mConstants["NURBS_ERROR19"] = GLU_NURBS_ERROR19;
      mConstants["NURBS_ERROR20"] = GLU_NURBS_ERROR20;
      mConstants["NURBS_ERROR21"] = GLU_NURBS_ERROR21;
      mConstants["NURBS_ERROR22"] = GLU_NURBS_ERROR22;
      mConstants["NURBS_ERROR23"] = GLU_NURBS_ERROR23;
      mConstants["NURBS_ERROR24"] = GLU_NURBS_ERROR24;
      mConstants["NURBS_ERROR25"] = GLU_NURBS_ERROR25;
      mConstants["NURBS_ERROR26"] = GLU_NURBS_ERROR26;
      mConstants["NURBS_ERROR27"] = GLU_NURBS_ERROR27;
      mConstants["NURBS_ERROR28"] = GLU_NURBS_ERROR28;
      mConstants["NURBS_ERROR29"] = GLU_NURBS_ERROR29;
      mConstants["NURBS_ERROR30"] = GLU_NURBS_ERROR30;
      mConstants["NURBS_ERROR31"] = GLU_NURBS_ERROR31;
      mConstants["NURBS_ERROR32"] = GLU_NURBS_ERROR32;
      mConstants["NURBS_ERROR33"] = GLU_NURBS_ERROR33;
      mConstants["NURBS_ERROR34"] = GLU_NURBS_ERROR34;
      mConstants["NURBS_ERROR35"] = GLU_NURBS_ERROR35;
      mConstants["NURBS_ERROR36"] = GLU_NURBS_ERROR36;
      mConstants["NURBS_ERROR37"] = GLU_NURBS_ERROR37;
      mConstants["CW"] = GLU_CW;
      mConstants["CCW"] = GLU_CCW;
      mConstants["INTERIOR"] = GLU_INTERIOR;
      mConstants["EXTERIOR"] = GLU_EXTERIOR;
      mConstants["UNKNOWN"] = GLU_UNKNOWN;
      mConstants["BEGIN"] = GLU_BEGIN;
      mConstants["VERTEX"] = GLU_VERTEX;
      mConstants["END"] = GLU_END;
      mConstants["ERROR"] = GLU_ERROR;
      mConstants["EDGE_FLAG"] = GLU_EDGE_FLAG;
#ifdef GLU_VERSION_1_3
      mConstants["VERSION_1_3"] = GLU_VERSION_1_3;
      mConstants["NURBS_ERROR"] = GLU_NURBS_ERROR;
      mConstants["NURBS_BEGIN"] = GLU_NURBS_BEGIN;
      mConstants["NURBS_VERTEX"] = GLU_NURBS_VERTEX;
      mConstants["NURBS_NORMAL"] = GLU_NURBS_NORMAL;
      mConstants["NURBS_COLOR"] = GLU_NURBS_COLOR;
      mConstants["NURBS_TEXTURE_COORD"] = GLU_NURBS_TEXTURE_COORD;
      mConstants["NURBS_END"] = GLU_NURBS_END;
      mConstants["NURBS_BEGIN_DATA"] = GLU_NURBS_BEGIN_DATA;
      mConstants["NURBS_VERTEX_DATA"] = GLU_NURBS_VERTEX_DATA;
      mConstants["NURBS_NORMAL_DATA"] = GLU_NURBS_NORMAL_DATA;
      mConstants["NURBS_COLOR_DATA"] = GLU_NURBS_COLOR_DATA;
      mConstants["NURBS_TEXTURE_COORD_DATA"] = GLU_NURBS_TEXTURE_COORD_DATA;
      mConstants["NURBS_END_DATA"] = GLU_NURBS_END_DATA;
      mConstants["NURBS_MODE"] = GLU_NURBS_MODE;
      mConstants["NURBS_TESSELLATOR"] = GLU_NURBS_TESSELLATOR;
      mConstants["NURBS_RENDERER"] = GLU_NURBS_RENDERER;
      mConstants["OBJECT_PARAMETRIC_ERROR"] = GLU_OBJECT_PARAMETRIC_ERROR;
      mConstants["OBJECT_PATH_LENGTH"] = GLU_OBJECT_PATH_LENGTH;
#else
      mConstants["VERSION_1_3"] = 0;
#endif
    }
    
    void registerPyConstants(PyObject *mod)
    {
      if (mConstants.size() > 0)
      {
        return;
      }
      
      initConstants();
      
      std::map<std::string, GLenum>::iterator it = mConstants.begin();
      
      while (it != mConstants.end())
      {
        PyModule_AddIntConstant(mod, it->first.c_str(), it->second);
        ++it;
      }
      
      PyModule_AddObject(mod, "TESS_MAX_COORD", PyFloat_FromDouble(GLU_TESS_MAX_COORD));
    }
    
    PyMethodDef* getPyFunctions()
    {
      extern bool operator!=(const PyMethodDef &, const PyMethodDef &);
      
      if (mFunctions.size() > 0)
      {
        return &(mFunctions[0]);
      }
      
      initFunctions();
      
      PyMethodDef null = {NULL, NULL, NULL, NULL};
      
      if (mFunctions.size() == 0 || mFunctions.back() != null)
      {
        mFunctions.push_back(null);
      }
      
      return &(mFunctions[0]);
    }
    
    
  protected:
    
    static PyGLU *msInstance;
    
  protected:
    
    std::map<std::string, GLenum> mConstants;
    std::vector<PyMethodDef> mFunctions;
};


GLenum PyGLU::ENUM_ERROR = (GLenum)-2;
PyGLU* PyGLU::msInstance = 0;

void PyGL_CleanupGLU(void *obj)
{
#ifdef _DEBUG
  std::cout << "PyGL_CleanupGLU" << std::endl;
#endif
  delete ((PyGLU*)obj);
}

bool PyGL_InitGLU(PyObject *mod)
{
  PyGLU &glu = PyGLU::Instance();
  
  PyObject *smod = Py_InitModule("glu", glu.getPyFunctions());
  
  glu.registerPyConstants(smod);
  
  PyObject *cleanup = PyCObject_FromVoidPtr((void*)&glu, PyGL_CleanupGLU);
  PyModule_AddObject(smod, "__cleanupObj", cleanup);
  
  if (mod != NULL)
  {
    PyModule_AddObject(mod, "glu", smod);
  }
  
  return true;
}

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

bool operator==(const PyMethodDef &md0, const PyMethodDef &md1)
{
  return ((md0.ml_meth == md1.ml_meth) && (md0.ml_flags == md1.ml_flags));
}

bool operator!=(const PyMethodDef &md0, const PyMethodDef &md1)
{
  return !operator==(md0, md1);
}

// ---

extern void Register_GL_1_1_Constants(PyGL::ConstantMap&);
extern void Register_GL_1_2_Constants(PyGL::ConstantMap&);
extern void Register_GL_1_3_Constants(PyGL::ConstantMap&);
extern void Register_GL_1_4_Constants(PyGL::ConstantMap&);
extern void Register_GL_1_5_Constants(PyGL::ConstantMap&);
extern void Register_GL_2_0_Constants(PyGL::ConstantMap&);
extern void Register_GL_2_1_Constants(PyGL::ConstantMap&);
extern void Register_GL_ARB_Constants(PyGL::ConstantMap&);

extern void Register_GL_1_1_Functions(PyGL::FunctionTable&);
extern void Register_GL_1_2_Functions(PyGL::FunctionTable&);
extern void Register_GL_1_3_Functions(PyGL::FunctionTable&);
extern void Register_GL_1_4_Functions(PyGL::FunctionTable&);
extern void Register_GL_1_5_Functions(PyGL::FunctionTable&);
extern void Register_GL_2_0_Functions(PyGL::FunctionTable&);
extern void Register_GL_2_1_Functions(PyGL::FunctionTable&);
extern void Register_GL_ARB_Functions(PyGL::FunctionTable&);

// ---

GLenum PyGL::ENUM_ERROR = (GLenum)-2;

PyGL* PyGL::msInstance = 0;

PyGL& PyGL::Instance()
{
  if (msInstance == 0)
  {
    new PyGL();
  }
  return *msInstance;
}

PyGL::PyGL()
  : mVersion(1.1)
{
  assert(msInstance == 0);
  msInstance = this;
  mModule = NULL;
}

PyGL::~PyGL()
{
  msInstance = 0;
}

GLenum PyGL::getConstant(const std::string &name)
{
  std::map<std::string, GLenum>::iterator it = mConstants.find(name);
  if (it == mConstants.end())
  {
    return ENUM_ERROR;
  }
  else
  {
    return it->second;
  }
}

void PyGL::initConstants()
{
  Register_GL_1_1_Constants(mConstants);
  Register_GL_1_2_Constants(mConstants);
  Register_GL_1_3_Constants(mConstants);
  Register_GL_1_4_Constants(mConstants);
  Register_GL_1_5_Constants(mConstants);
  Register_GL_2_0_Constants(mConstants);
  Register_GL_2_1_Constants(mConstants);
  Register_GL_ARB_Constants(mConstants);
}

void PyGL::initFunctions()
{
  Register_GL_1_1_Functions(mFunctions);
  Register_GL_1_2_Functions(mFunctions);
  Register_GL_1_3_Functions(mFunctions);
  Register_GL_1_4_Functions(mFunctions);
  Register_GL_1_5_Functions(mFunctions);
  Register_GL_2_0_Functions(mFunctions);
  Register_GL_2_1_Functions(mFunctions);
  Register_GL_ARB_Functions(mFunctions);
}

void PyGL::registerPyFunctions(PyObject *m)
{
  if (mFunctions.size() > 0)
  {
    return;
  }
  
  glewInit();
  
  initFunctions();
  
  for (size_t i=0; i<mFunctions.size(); ++i)
  {
    PyMethodDef *def = &(mFunctions[i]);
    if (def->ml_name == NULL || def->ml_meth == NULL)
    {
      continue;
    }
    PyObject *func = PyCFunction_New(def, m);
    PyModule_AddObject(m, def->ml_name, func);
  }
}

void PyGL::registerPyConstants(PyObject *m)
{
  if (mConstants.size() > 0)
  {
    return;
  }
  
  initConstants();
  
  char buffer[64];
  sprintf(buffer, "%.1f", getVersion());
  PyModule_AddStringConstant(m, "version", buffer); // no float constant...
  
  std::map<std::string, GLenum>::iterator it = mConstants.begin();
  while (it != mConstants.end())
  {
    PyModule_AddIntConstant(m, it->first.c_str(), it->second);
    ++it;
  }
}

// ---

static PyObject* Init(PyObject *, PyObject *)
{
  PyGL &gl = PyGL::Instance();
  
  PyObject *mod = gl.getPyModule();
  if (mod != NULL)
  {
    gl.registerPyFunctions(mod);
    gl.registerPyConstants(mod);
  }
  
  Py_RETURN_NONE;
}

static PyMethodDef PyGL_Methods[] =
{
  {"Init", Init, METH_VARARGS, NULL},
  {NULL, NULL, NULL, NULL}
};

void PyGL_CleanupGL(void *obj)
{
#ifdef _DEBUG
  std::cout << "PyGL_CleanupGL" << std::endl;
#endif
  delete ((PyGL*)obj);
}

bool PyGL_InitGL(PyObject *mod)
{
  PyGL &gl = PyGL::Instance();
  
  PyObject *smod = Py_InitModule("gl", PyGL_Methods);
  
  gl.setPyModule(smod);
  
  PyObject *cleanup = PyCObject_FromVoidPtr((void*)&gl, PyGL_CleanupGL);
  PyModule_AddObject(smod, "__cleanupObj", cleanup);
  
  if (mod != NULL)
  {
    Py_INCREF(smod);
    PyModule_AddObject(mod, "gl", smod);
  }
  
  return true;
}

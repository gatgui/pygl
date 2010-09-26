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

#ifdef __APPLE__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif


#define MENU_MAX_ENTRY 100


#define REGISTER_GLUT_FUNCTION(name) \
  {\
    PyMethodDef tmp = {#name, &PyGLUT::py_glut##name, METH_VARARGS, NULL};\
    mFunctions.push_back(tmp);\
  }

static void dummyFree(void*)
{
}



class PyGLUT
{
  protected:
    
    struct WindowCallbacks
    {
      PyObject *Display;
      PyObject *Reshape;
      PyObject *Keyboard;
      PyObject *Mouse;
      PyObject *Motion;
      PyObject *PassiveMotion;
      PyObject *Entry;
      PyObject *Visibility;
      PyObject *Special;
      PyObject *SpaceballMotion;
      PyObject *SpaceballRotate;
      PyObject *SpaceballButton;
      PyObject *ButtonBox;
      PyObject *Dials;
      PyObject *TabletMotion;
      PyObject *TabletButton;
      PyObject *OverlayDisplay;
      PyObject *Status;
      PyObject *KeyboardUp;
      PyObject *SpecialUp;
      PyObject *Joystick;
    };
  
  public:

    static int REG_KEY;
    static unsigned int INTEGER_ERROR;
    static GLenum ENUM_ERROR;
    static void* PTR_ERROR;
    static PyGLUT * msInstance;

  public:

    PyGLUT()
    {
      assert(msInstance == 0);
      msInstance = this;
      mMenuStatusCallback = Py_None;
      mIdleCallback = Py_None;
      Py_INCREF(Py_None);
      Py_INCREF(Py_None);
    }
    
    ~PyGLUT()
    {
      msInstance = 0;
      
      Py_DECREF(mMenuStatusCallback);
      Py_DECREF(mIdleCallback);
      
      std::map<int, PyObject*>::iterator sit;
      
      sit = mMenuCallbacks.begin();
      while (sit != mMenuCallbacks.end())
      {
        Py_XDECREF(sit->second);
        ++sit;
      }
      
      sit = mTimerCallbacks.begin();
      while (sit != mTimerCallbacks.end())
      {
        Py_XDECREF(sit->second);
        ++sit;
      }
      
      std::map<int, WindowCallbacks>::iterator wit = mWinCallbacks.begin();
      while (wit != mWinCallbacks.end())
      {
        Py_XDECREF(wit->second.Display);
        Py_XDECREF(wit->second.Reshape);
        Py_XDECREF(wit->second.Keyboard);
        Py_XDECREF(wit->second.Mouse);
        Py_XDECREF(wit->second.Motion);
        Py_XDECREF(wit->second.PassiveMotion);
        Py_XDECREF(wit->second.Entry);
        Py_XDECREF(wit->second.Visibility);
        Py_XDECREF(wit->second.Special);
        Py_XDECREF(wit->second.SpaceballMotion);
        Py_XDECREF(wit->second.SpaceballRotate);
        Py_XDECREF(wit->second.SpaceballButton);
        Py_XDECREF(wit->second.ButtonBox);
        Py_XDECREF(wit->second.Dials);
        Py_XDECREF(wit->second.TabletMotion);
        Py_XDECREF(wit->second.TabletButton);
        Py_XDECREF(wit->second.OverlayDisplay);
        Py_XDECREF(wit->second.Status);
        Py_XDECREF(wit->second.KeyboardUp);
        Py_XDECREF(wit->second.SpecialUp);
        Py_XDECREF(wit->second.Joystick);
        ++wit;
      }
    }
    
    unsigned int getInteger(const std::string &name)
    {
      std::map<std::string, unsigned int>::iterator it = mIConstants.find(name);
      if (it == mIConstants.end())
      {
        return INTEGER_ERROR;
      }
      else
      {
        return it->second;
      }
    }
    
    GLenum getEnum(const std::string &name)
    {
      std::map<std::string, GLenum>::iterator it = mEConstants.find(name);
      if (it == mEConstants.end())
      {
        return ENUM_ERROR;
      }
      else
      {
        return it->second;
      }
    }
    
    void* getPtr(const std::string &name)
    {
      std::map<std::string, void*>::iterator it = mPConstants.find(name);
      if (it == mPConstants.end())
      {
        return PTR_ERROR;
      }
      else
      {
        return it->second;
      }
    }
    
    void setMenuStatusCallback(PyObject *func)
    {
      Py_INCREF(func);
      Py_DECREF(mMenuStatusCallback);
      mMenuStatusCallback = func;
    }
    
    PyObject* getMenuStatusCallback()
    {
      Py_INCREF(mMenuStatusCallback);
      return mMenuStatusCallback;
    }
    
    void setIdleCallback(PyObject *func)
    {
      Py_INCREF(func);
      Py_DECREF(mIdleCallback);
      mIdleCallback = func;
    }
    
    PyObject* getIdleCallback()
    {
      Py_INCREF(mIdleCallback);
      return mIdleCallback;
    }
    
    void addTimerCallback(int tid, PyObject *func)
    {
      Py_INCREF(func);
      std::map<int, PyObject*>::iterator it = mTimerCallbacks.find(tid);
      if (it != mTimerCallbacks.end())
      {
        Py_DECREF(it->second);
      }
      mTimerCallbacks[tid] = func;
    }
    
    PyObject* findTimerCallback(int tid)
    {
      std::map<int, PyObject*>::iterator it = mTimerCallbacks.find(tid);
      if (it != mTimerCallbacks.end())
      {
        Py_INCREF(it->second);
        return it->second;
      }
      else
      {
        Py_RETURN_NONE;
      }
    }
    
    void addMenuCallback(int mid, PyObject *func)
    {
      Py_INCREF(func);
      std::map<int, PyObject*>::iterator it = mMenuCallbacks.find(mid);
      if (it != mMenuCallbacks.end())
      {
        Py_DECREF(it->second);
      }
      mMenuCallbacks[mid] = func;
    }
    
    void removeMenuCallback(int mid)
    {
      std::map<int, PyObject*>::iterator it = mMenuCallbacks.find(mid);
      if (it != mMenuCallbacks.end())
      {
        Py_DECREF(it->second);
        mMenuCallbacks.erase(it);
      }
    }
    
    PyObject* findMenuCallback(int mid)
    {
      std::map<int, PyObject*>::iterator it = mMenuCallbacks.find(mid);
      if (it != mMenuCallbacks.end())
      {
        Py_INCREF(it->second);
        return it->second;
      }
      else
      {
        Py_RETURN_NONE;
      }
    }
    
    WindowCallbacks& getWindowCallbacks(int wid)
    {
      std::map<int, WindowCallbacks>::iterator it = mWinCallbacks.find(wid);
      if (it == mWinCallbacks.end())
      {
        mWinCallbacks[wid] = WindowCallbacks();
        mWinCallbacks[wid].Display = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Reshape = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Keyboard = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Mouse = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Motion = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].PassiveMotion = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Entry = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Visibility = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Special = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].SpaceballMotion = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].SpaceballRotate = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].SpaceballButton = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].ButtonBox = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Dials = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].TabletMotion = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].TabletButton = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].OverlayDisplay = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Status = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].KeyboardUp = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].SpecialUp = Py_None; Py_INCREF(Py_None);
        mWinCallbacks[wid].Joystick = Py_None; Py_INCREF(Py_None);
      }
      return mWinCallbacks[wid];
    }
    
    WindowCallbacks* findWindowCallbacks(int wid)
    {
      std::map<int, WindowCallbacks>::iterator it = mWinCallbacks.find(wid);
      if (it != mWinCallbacks.end())
      {
        return &(it->second);
      }
      else
      {
        return 0;
      }
    }
    
#define FIND_WINDOW_CALLBACK(name)\
    PyObject* findWindow##name##Callback(int wid)\
    {\
      WindowCallbacks *wc = findWindowCallbacks(wid);\
      if (wc != 0)\
      {\
        Py_INCREF(wc->name);\
        return wc->name;\
      }\
      Py_RETURN_NONE;\
    }
    
    FIND_WINDOW_CALLBACK(Display);
    FIND_WINDOW_CALLBACK(Reshape);
    FIND_WINDOW_CALLBACK(Keyboard);
    FIND_WINDOW_CALLBACK(Mouse);
    FIND_WINDOW_CALLBACK(Motion);
    FIND_WINDOW_CALLBACK(PassiveMotion);
    FIND_WINDOW_CALLBACK(Entry);
    FIND_WINDOW_CALLBACK(Visibility);
    FIND_WINDOW_CALLBACK(Special);
    FIND_WINDOW_CALLBACK(SpaceballMotion);
    FIND_WINDOW_CALLBACK(SpaceballRotate);
    FIND_WINDOW_CALLBACK(SpaceballButton);
    FIND_WINDOW_CALLBACK(ButtonBox);
    FIND_WINDOW_CALLBACK(Dials);
    FIND_WINDOW_CALLBACK(TabletMotion);
    FIND_WINDOW_CALLBACK(TabletButton);
    FIND_WINDOW_CALLBACK(OverlayDisplay);
    FIND_WINDOW_CALLBACK(Status);
    FIND_WINDOW_CALLBACK(KeyboardUp);
    FIND_WINDOW_CALLBACK(SpecialUp);
    FIND_WINDOW_CALLBACK(Joystick);
    
#undef FIND_WINDOW_CALLBACK
    
    
  public:
    
    // Proxy callbacks
    
    inline static PyGLUT& Instance()
    {
      if (msInstance == 0)
      {
        new PyGLUT();
      }
      return *msInstance;
    }
    
    static void py_glutMenuCallback(int idx)
    {
      int id = glutGetMenu();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findMenuCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", idx);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutDisplayCallback(void)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowDisplayCallback(id);
      if (func != Py_None)
      {
        PyObject_CallObject(func, NULL);
      }
      Py_DECREF(func);
    }
    
    static void py_glutReshapeCallback(int w, int h)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowReshapeCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", w, h);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutKeyboardCallback(unsigned char c, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowKeyboardCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", c, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutMouseCallback(int b, int s, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowMouseCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iiii)", b, s, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutMotionCallback(int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowMotionCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutPassiveMotionCallback(int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowPassiveMotionCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutEntryCallback(int s)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowEntryCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", s);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutVisibilityCallback(int s)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowVisibilityCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", s);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutSpecialCallback(int key, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowSpecialCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", key, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutSpaceballMotionCallback(int x, int y, int z)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowSpaceballMotionCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", x, y, z);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutSpaceballRotateCallback(int x, int y, int z)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowSpaceballRotateCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", x, y, z);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutSpaceballButtonCallback(int b, int s)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowSpaceballButtonCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", b, s);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutButtonBoxCallback(int b, int s)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowButtonBoxCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", b, s);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutDialsCallback(int dial, int value)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowDialsCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", dial, value);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutTabletMotionCallback(int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowTabletMotionCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(ii)", x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutTabletButtonCallback(int button, int state, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowTabletButtonCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iiii)", button, state, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutOverlayDisplayCallback(void)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowOverlayDisplayCallback(id);
      if (func != Py_None)
      {
        PyObject_CallObject(func, NULL);
      }
      Py_DECREF(func);
    }
    
    static void py_glutWindowStatusCallback(int status)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowStatusCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(i)", status);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutKeyboardUpCallback(unsigned char key, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowKeyboardUpCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", key, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutSpecialUpCallback(int key, int x, int y)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowSpecialUpCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", key, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutJoystickCallback(unsigned int mask, int x, int y, int z)
    {
      int id = glutGetWindow();
      PyGLUT &pg = Instance();
      PyObject *func = pg.findWindowJoystickCallback(id);
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iiii)", mask, x, y, z);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutIdleCallback(void)
    {
      PyGLUT &pg = Instance();
      PyObject *func = pg.getIdleCallback();
      if (func != Py_None)
      {
        PyObject_CallObject(func, NULL);
      }
      Py_DECREF(func);
    }
    
    static void py_glutMenuStatusCallback(int status, int x, int y)
    {
      PyGLUT &pg = Instance();
      PyObject *func = pg.getMenuStatusCallback();
      if (func != Py_None)
      {
        PyObject *args = Py_BuildValue("(iii)", status, x, y);
        PyObject_CallObject(func, args);
        Py_DECREF(args);
      }
      Py_DECREF(func);
    }
    
    static void py_glutTimerCallback(int value)
    {
      PyGLUT &pg = Instance();
      PyObject *func = pg.findTimerCallback(value);
      if (func != Py_None)
      {
        PyObject_CallObject(func, NULL);
      }
      Py_DECREF(func);
    }
    
  public:
    
    static PyObject* py_glutInit(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      static char *argv[] = {(char*)"PyGLUT", 0};
      static int argc = 1;
      glutInit(&argc, argv);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutInitDisplayMode(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CUint >::Call(self, args, glutInitDisplayMode);
    }
    
    static PyObject* py_glutInitDisplayString(PyObject *self, PyObject *args)
    {
      return WrapFunc1<String >::Call(self, args, glutInitDisplayString);
    }
    
    static PyObject* py_glutInitWindowPosition(PyObject *self, PyObject *args)
    {
      return WrapFunc2<CInt, CInt >::Call(self, args, glutInitWindowPosition);
    }
    
    static PyObject* py_glutInitWindowSize(PyObject *self, PyObject *args)
    {
      return WrapFunc2<CInt, CInt >::Call(self, args, glutInitWindowSize);
    }
    
    static PyObject* py_glutMainLoop(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutMainLoop);
    }
    
    static PyObject* py_glutCreateWindow(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      String title(PyTuple_GetItem(args, 0));
      int w = glutCreateWindow(title);
      return PyInt_FromLong(w);
    }
    
    static PyObject* py_glutCreateSubWindow(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 5);
      CInt id(PyTuple_GetItem(args, 0));
      CInt x(PyTuple_GetItem(args, 1));
      CInt y(PyTuple_GetItem(args, 2));
      CInt w(PyTuple_GetItem(args, 3));
      CInt h(PyTuple_GetItem(args, 4));
      int sid = glutCreateSubWindow(id, x, y, w, h);
      return PyInt_FromLong(sid);
    }
    
    static PyObject* py_glutDestroyWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutDestroyWindow);
    }
    
    static PyObject* py_glutPostRedisplay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutPostRedisplay);
    }
    
    static PyObject* py_glutPostWindowRedisplay(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutPostWindowRedisplay);
    }
    
    static PyObject* py_glutSwapBuffers(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSwapBuffers);
    }
    
    static PyObject* py_glutGetWindow(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      int id = glutGetWindow();
      return PyInt_FromLong(id);
    }
    
    static PyObject* py_glutSetWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutSetWindow);
    }
    
    static PyObject* py_glutSetWindowTitle(PyObject *self, PyObject *args)
    {
      return WrapFunc1<String >::Call(self, args, glutSetWindowTitle);
    }
    
    static PyObject* py_glutSetIconTitle(PyObject *self, PyObject *args)
    {
      return WrapFunc1<String >::Call(self, args, glutSetIconTitle);
    }
    
    static PyObject* py_glutPositionWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc2<CInt, CInt >::Call(self, args, glutPositionWindow);
    }
    
    static PyObject* py_glutReshapeWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc2<CInt, CInt >::Call(self, args, glutReshapeWindow);
    }
    
    static PyObject* py_glutPopWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutPopWindow);
    }
    
    static PyObject* py_glutPushWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutPushWindow);
    }
    
    static PyObject* py_glutIconifyWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutIconifyWindow);
    }
    
    static PyObject* py_glutShowWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutShowWindow);
    }
    
    static PyObject* py_glutHideWindow(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutHideWindow);
    }
    
    static PyObject* py_glutFullScreen(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutFullScreen);
    }
    
    static PyObject* py_glutSetCursor(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutSetCursor);
    }
    
    static PyObject* py_glutWarpPointer(PyObject *self, PyObject *args)
    {
      return WrapFunc2<CInt, CInt >::Call(self, args, glutWarpPointer);
    }
    
    static PyObject* py_glutEstablishOverlay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutEstablishOverlay);
    }
    
    static PyObject* py_glutRemoveOverlay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutRemoveOverlay);
    }
    
    static PyObject* py_glutUseLayer(PyObject *self, PyObject *args)
    {
      return WrapFunc1<Enum >::Call(self, args, glutUseLayer);
    }
    
    static PyObject* py_glutPostOverlayRedisplay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutPostOverlayRedisplay);
    }
    
    static PyObject* py_glutPostWindowOverlayRedisplay(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutPostWindowOverlayRedisplay);
    }
    
    static PyObject* py_glutShowOverlay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutShowOverlay);
    }
    
    static PyObject* py_glutHideOverlay(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutHideOverlay);
    }
    
    static PyObject* py_glutCreateMenu(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      if (func != Py_None && !PyFunction_Check(func))
      {
        PyErr_SetString(PyExc_RuntimeError, "Expected a function");
        return NULL;
      }
      int m = glutCreateMenu(&PyGLUT::py_glutMenuCallback);
      Instance().addMenuCallback(m, func);
      return PyInt_FromLong(m);
    }
    
    static PyObject* py_glutDestroyMenu(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      CInt m(PyTuple_GetItem(args, 0));
      Instance().removeMenuCallback(m);
      glutDestroyMenu(m);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutGetMenu(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      int m = glutGetMenu();
      return PyInt_FromLong(m);
    }
    
    static PyObject* py_glutSetMenu(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutSetMenu);
    }
    
    static PyObject* py_glutAddMenuEntry(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      String label(PyTuple_GetItem(args, 0));
      CInt val(PyTuple_GetItem(args, 1));
      glutAddMenuEntry(label, val);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutAddSubMenu(PyObject *self, PyObject *args)
    {
      return WrapFunc2<String, CInt >::Call(self, args, glutAddSubMenu);
    }
    
    static PyObject* py_glutChangeToMenuEntry(PyObject *self, PyObject *args)
    {
      return WrapFunc3<CInt, String, CInt >::Call(self, args, glutChangeToMenuEntry);
    }
    
    static PyObject* py_glutChangeToSubMenu(PyObject *self, PyObject *args)
    {
      return WrapFunc3<CInt, String, CInt >::Call(self, args, glutChangeToSubMenu);
    }
    
    static PyObject* py_glutRemoveMenuItem(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutRemoveMenuItem);
    }
    
    static PyObject* py_glutAttachMenu(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutAttachMenu);
    }
    
    static PyObject* py_glutDetachMenu(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutDetachMenu);
    }
    
    static PyObject* py_glutDisplayFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        PyErr_SetString(PyExc_RuntimeError, "GLUT windows MUST have a display callback");
        return NULL;
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutDisplayFunc(py_glutDisplayCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Display);
      wc.Display = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutReshapeFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutReshapeFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutReshapeFunc(py_glutReshapeCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Reshape);
      wc.Reshape = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutKeyboardFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutKeyboardFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutKeyboardFunc(py_glutKeyboardCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Keyboard);
      wc.Keyboard = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutKeyboardUpFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutKeyboardUpFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutKeyboardUpFunc(py_glutKeyboardUpCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.KeyboardUp);
      wc.KeyboardUp = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutMouseFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutMouseFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutMouseFunc(py_glutMouseCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Mouse);
      wc.Mouse = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutMotionFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutMotionFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutMotionFunc(py_glutMotionCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Motion);
      wc.Motion = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutPassiveMotionFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutPassiveMotionFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutPassiveMotionFunc(py_glutPassiveMotionCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.PassiveMotion);
      wc.PassiveMotion = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutEntryFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutEntryFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutEntryFunc(py_glutEntryCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Entry);
      wc.Entry = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSpecialFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutSpecialFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutSpecialFunc(py_glutSpecialCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Special);
      wc.Special = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSpecialUpFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutSpecialUpFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutSpecialUpFunc(py_glutSpecialUpCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.SpecialUp);
      wc.SpecialUp = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutVisibilityFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutVisibilityFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutVisibilityFunc(py_glutVisibilityCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Visibility);
      wc.Visibility = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSpaceballMotionFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutSpaceballMotionFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutSpaceballMotionFunc(py_glutSpaceballMotionCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.SpaceballMotion);
      wc.SpaceballMotion = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSpaceballRotateFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutSpaceballRotateFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutSpaceballRotateFunc(py_glutSpaceballRotateCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.SpaceballRotate);
      wc.SpaceballRotate = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSpaceballButtonFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutSpaceballButtonFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutSpaceballButtonFunc(py_glutSpaceballButtonCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.SpaceballMotion);
      wc.SpaceballMotion = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutButtonBoxFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutButtonBoxFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutButtonBoxFunc(py_glutButtonBoxCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.ButtonBox);
      wc.ButtonBox = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutDialsFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutDialsFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutDialsFunc(py_glutDialsCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Dials);
      wc.Dials = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutTabletMotionFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutTabletMotionFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutTabletMotionFunc(py_glutTabletMotionCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.TabletMotion);
      wc.TabletMotion = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutTabletButtonFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutTabletButtonFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutTabletButtonFunc(py_glutTabletButtonCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.TabletButton);
      wc.TabletButton = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutOverlayDisplayFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutOverlayDisplayFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutOverlayDisplayFunc(py_glutOverlayDisplayCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.OverlayDisplay);
      wc.OverlayDisplay = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutWindowStatusFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutWindowStatusFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutWindowStatusFunc(py_glutWindowStatusCallback);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Status);
      wc.Status = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutJoystickFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      PyObject *func = PyTuple_GetItem(args, 0);
      CInt interval(PyTuple_GetItem(args, 1));
      int wid = glutGetWindow();
      WindowCallbacks &wc = Instance().getWindowCallbacks(wid);
      if (func == Py_None)
      {
        glutJoystickFunc(0, 0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutJoystickFunc(py_glutJoystickCallback, interval);
      }
      Py_INCREF(func);
      Py_DECREF(wc.Joystick);
      wc.Joystick = func;
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutIdleFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      if (func == Py_None)
      {
        glutIdleFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutIdleFunc(py_glutIdleCallback);
      }
      Instance().setIdleCallback(func);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutTimerFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 3);
      CUint msec(PyTuple_GetItem(args, 0));
      PyObject *func = PyTuple_GetItem(args, 1);
      CInt value(PyTuple_GetItem(args, 2));
      
      if (func == Py_None)
      {
        PyErr_SetString(PyExc_RuntimeError, "None value passed to glut.TimerFunc");
        return NULL;
      }
      
      if (!PyFunction_Check(func))
      {
        PyErr_SetString(PyExc_RuntimeError, "Expected a function");
        return NULL;
      }
      
      Instance().addTimerCallback(value, func);
      
      glutTimerFunc(msec, py_glutTimerCallback, value);
      
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutMenuStatusFunc(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      PyObject *func = PyTuple_GetItem(args, 0);
      if (func == Py_None)
      {
        glutMenuStatusFunc(0);
      }
      else
      {
        if (!PyFunction_Check(func))
        {
          PyErr_SetString(PyExc_RuntimeError, "Expected a function");
          return NULL;
        }
        glutMenuStatusFunc(py_glutMenuStatusCallback);
      }
      Instance().setMenuStatusCallback(func);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutSetColor(PyObject *self, PyObject *args)
    {
      return WrapFunc4<CInt, Float, Float, Float >::Call(self, args, glutSetColor);
    }
    
    static PyObject* py_glutGetColor(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      CInt ndx(PyTuple_GetItem(args, 0));
      CInt comp(PyTuple_GetItem(args, 1));
      GLfloat r = glutGetColor(ndx, comp);
      return PyFloat_FromDouble(r);
    }
    
    static PyObject* py_glutCopyColormap(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutCopyColormap);
    }
    
    static PyObject* py_glutGet(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum e(PyTuple_GetItem(args, 0));
      int r = glutGet(e);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutDeviceGet(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum e(PyTuple_GetItem(args, 0));
      int r = glutDeviceGet(e);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutExtensionSupported(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      String s(PyTuple_GetItem(args, 0));
      int r = glutExtensionSupported(s);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutGetModifiers(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      int r = glutGetModifiers();
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutLayerGet(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum e(PyTuple_GetItem(args, 0));
      int r = glutLayerGet(e);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutBitmapCharacter(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      CInt character(PyTuple_GetItem(args, 1));
      glutBitmapCharacter(font, character);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutBitmapWidth(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      CInt character(PyTuple_GetItem(args, 1));
      int r = glutBitmapWidth(font, character);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutStrokeCharacter(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      CInt character(PyTuple_GetItem(args, 1));
      glutStrokeCharacter(font, character);
      Py_RETURN_NONE;
    }
    
    static PyObject* py_glutStrokeWidth(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      CInt character(PyTuple_GetItem(args, 1));
      int r = glutStrokeWidth(font, character);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutBitmapLength(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      String str(PyTuple_GetItem(args, 1));
      int r = glutBitmapLength(font, (const unsigned char*)(const char*)str);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutStrokeLength(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 2);
      void *font = PyCObject_AsVoidPtr(PyTuple_GetItem(args, 0));
      String str(PyTuple_GetItem(args, 1));
      int r = glutStrokeLength(font, (const unsigned char*)(const char*)str);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutWireSphere(PyObject *self, PyObject *args)
    {
      return WrapFunc3<Double, Int, Int >::Call(self, args, glutWireSphere);
    }
    
    static PyObject* py_glutSolidSphere(PyObject *self, PyObject *args)
    {
      return WrapFunc3<Double, Int, Int >::Call(self, args, glutSolidSphere);
    }
    
    static PyObject* py_glutWireCone(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Int, Int >::Call(self, args, glutWireCone);
    }
    
    static PyObject* py_glutSolidCone(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Int, Int >::Call(self, args, glutSolidCone);
    }
    
    static PyObject* py_glutWireCube(PyObject *self, PyObject *args)
    {
      return WrapFunc1<Double >::Call(self, args, glutWireCube);
    }
    
    static PyObject* py_glutSolidCube(PyObject *self, PyObject *args)
    {
      return WrapFunc1<Double >::Call(self, args, glutSolidCube);
    }
    
    static PyObject* py_glutWireTorus(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Int, Int >::Call(self, args, glutWireTorus);
    }
    
    static PyObject* py_glutSolidTorus(PyObject *self, PyObject *args)
    {
      return WrapFunc4<Double, Double, Int, Int >::Call(self, args, glutSolidTorus);
    }
    
    static PyObject* py_glutWireDodecahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutWireDodecahedron);
    }
    
    static PyObject* py_glutSolidDodecahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSolidDodecahedron);
    }
    
    static PyObject* py_glutWireTeapot(PyObject *self, PyObject *args)
    {
      return WrapFunc1<Double >::Call(self, args, glutWireTeapot);
    }
    
    static PyObject* py_glutSolidTeapot(PyObject *self, PyObject *args)
    {
      return WrapFunc1<Double >::Call(self, args, glutSolidTeapot);
    }
    
    static PyObject* py_glutWireOctahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutWireOctahedron);
    }
    
    static PyObject* py_glutSolidOctahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSolidOctahedron);
    }
    
    static PyObject* py_glutWireTetrahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutWireTetrahedron);
    }
    
    static PyObject* py_glutSolidTetrahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSolidTetrahedron);
    }
    
    static PyObject* py_glutWireIcosahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutWireIcosahedron);
    }
    
    static PyObject* py_glutSolidIcosahedron(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSolidIcosahedron);
    }
    
    static PyObject* py_glutVideoResizeGet(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 1);
      Enum param(PyTuple_GetItem(args, 0));
      int r = glutVideoResizeGet(param);
      return PyInt_FromLong(r);
    }
    
    static PyObject* py_glutSetupVideoResizing(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutSetupVideoResizing);
    }
    
    static PyObject* py_glutStopVideoResizing(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutStopVideoResizing);
    }
    
    static PyObject* py_glutVideoResize(PyObject *self, PyObject *args)
    {
      return WrapFunc4<CInt, CInt, CInt, CInt >::Call(self, args, glutVideoResize);
    }
    
    static PyObject* py_glutVideoPan(PyObject *self, PyObject *args)
    {
      return WrapFunc4<CInt, CInt, CInt, CInt >::Call(self, args, glutVideoPan);
    }
    
    static PyObject* py_glutReportErrors(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutReportErrors);
    }
    
    static PyObject* py_glutIgnoreKeyRepeat(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutIgnoreKeyRepeat);
    }
    
    static PyObject* py_glutSetKeyRepeat(PyObject *self, PyObject *args)
    {
      return WrapFunc1<CInt >::Call(self, args, glutSetKeyRepeat);
    }
    
    static PyObject* py_glutForceJoystickFunc(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutForceJoystickFunc);
    }
    
    static PyObject* py_glutGameModeString(PyObject *self, PyObject *args)
    {
      return WrapFunc1<String >::Call(self, args, glutGameModeString);
    }
    
    static PyObject* py_glutEnterGameMode(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      int i = glutEnterGameMode();
      return PyInt_FromLong(i);
    }
    
    static PyObject* py_glutLeaveGameMode(PyObject *self, PyObject *args)
    {
      return WrapFunc0::Call(self, args, glutLeaveGameMode);
    }
    
    static PyObject* py_glutGameModeGet(PyObject *, PyObject *args)
    {
      CHECK_ARG_COUNT(args, 0);
      Enum e(PyTuple_GetItem(args, 0));
      int i = glutGameModeGet(e);
      return PyInt_FromLong(i);
    }
    
    static PyObject* py_glutExit(PyObject *, PyObject *args)
    {
      int code = 0;
      if (PyTuple_Size(args) == 1)
      {
        code = PyInt_AsLong(PyTuple_GetItem(args, 0));
      }
      Py_Finalize();
      // cleanup python
      exit(code);
    }
    
  public:
    
    void initFunctions()
    {  
      REGISTER_GLUT_FUNCTION(Init);
      REGISTER_GLUT_FUNCTION(InitDisplayMode);
      REGISTER_GLUT_FUNCTION(InitDisplayString);
      REGISTER_GLUT_FUNCTION(InitWindowPosition);
      REGISTER_GLUT_FUNCTION(InitWindowSize);
      REGISTER_GLUT_FUNCTION(MainLoop);
      REGISTER_GLUT_FUNCTION(CreateWindow);
      REGISTER_GLUT_FUNCTION(CreateSubWindow);
      REGISTER_GLUT_FUNCTION(DestroyWindow);
      REGISTER_GLUT_FUNCTION(PostRedisplay);
      REGISTER_GLUT_FUNCTION(PostWindowRedisplay);
      REGISTER_GLUT_FUNCTION(SwapBuffers);
      REGISTER_GLUT_FUNCTION(GetWindow);
      REGISTER_GLUT_FUNCTION(SetWindow);
      REGISTER_GLUT_FUNCTION(SetWindowTitle);
      REGISTER_GLUT_FUNCTION(SetIconTitle);
      REGISTER_GLUT_FUNCTION(PositionWindow);
      REGISTER_GLUT_FUNCTION(ReshapeWindow);
      REGISTER_GLUT_FUNCTION(PopWindow);
      REGISTER_GLUT_FUNCTION(PushWindow);
      REGISTER_GLUT_FUNCTION(IconifyWindow);
      REGISTER_GLUT_FUNCTION(ShowWindow);
      REGISTER_GLUT_FUNCTION(HideWindow);
      REGISTER_GLUT_FUNCTION(FullScreen);
      REGISTER_GLUT_FUNCTION(SetCursor);
      REGISTER_GLUT_FUNCTION(WarpPointer);
      REGISTER_GLUT_FUNCTION(EstablishOverlay);
      REGISTER_GLUT_FUNCTION(RemoveOverlay);
      REGISTER_GLUT_FUNCTION(UseLayer);
      REGISTER_GLUT_FUNCTION(PostOverlayRedisplay);
      REGISTER_GLUT_FUNCTION(PostWindowOverlayRedisplay);
      REGISTER_GLUT_FUNCTION(ShowOverlay);
      REGISTER_GLUT_FUNCTION(HideOverlay);
      REGISTER_GLUT_FUNCTION(CreateMenu);
      REGISTER_GLUT_FUNCTION(DestroyMenu);
      REGISTER_GLUT_FUNCTION(GetMenu);
      REGISTER_GLUT_FUNCTION(SetMenu);
      REGISTER_GLUT_FUNCTION(AddMenuEntry);
      REGISTER_GLUT_FUNCTION(AddSubMenu);
      REGISTER_GLUT_FUNCTION(ChangeToMenuEntry);
      REGISTER_GLUT_FUNCTION(ChangeToSubMenu);
      REGISTER_GLUT_FUNCTION(RemoveMenuItem);
      REGISTER_GLUT_FUNCTION(AttachMenu);
      REGISTER_GLUT_FUNCTION(DetachMenu);
      REGISTER_GLUT_FUNCTION(DisplayFunc);
      REGISTER_GLUT_FUNCTION(ReshapeFunc);
      REGISTER_GLUT_FUNCTION(KeyboardFunc);
      REGISTER_GLUT_FUNCTION(MouseFunc);
      REGISTER_GLUT_FUNCTION(MotionFunc);
      REGISTER_GLUT_FUNCTION(PassiveMotionFunc);
      REGISTER_GLUT_FUNCTION(EntryFunc);
      REGISTER_GLUT_FUNCTION(VisibilityFunc);
      REGISTER_GLUT_FUNCTION(SpecialFunc);
      REGISTER_GLUT_FUNCTION(SpaceballMotionFunc);
      REGISTER_GLUT_FUNCTION(SpaceballRotateFunc);
      REGISTER_GLUT_FUNCTION(SpaceballButtonFunc);
      REGISTER_GLUT_FUNCTION(ButtonBoxFunc);
      REGISTER_GLUT_FUNCTION(DialsFunc);
      REGISTER_GLUT_FUNCTION(TabletMotionFunc);
      REGISTER_GLUT_FUNCTION(TabletButtonFunc);
      REGISTER_GLUT_FUNCTION(OverlayDisplayFunc);
      REGISTER_GLUT_FUNCTION(WindowStatusFunc);
      REGISTER_GLUT_FUNCTION(KeyboardUpFunc);
      REGISTER_GLUT_FUNCTION(SpecialUpFunc);
      REGISTER_GLUT_FUNCTION(JoystickFunc);
      REGISTER_GLUT_FUNCTION(IdleFunc);
      REGISTER_GLUT_FUNCTION(TimerFunc);
      REGISTER_GLUT_FUNCTION(MenuStatusFunc);
      REGISTER_GLUT_FUNCTION(SetColor);
      REGISTER_GLUT_FUNCTION(GetColor);
      REGISTER_GLUT_FUNCTION(CopyColormap);
      REGISTER_GLUT_FUNCTION(Get);
      REGISTER_GLUT_FUNCTION(DeviceGet);
      REGISTER_GLUT_FUNCTION(ExtensionSupported);
      REGISTER_GLUT_FUNCTION(GetModifiers);
      REGISTER_GLUT_FUNCTION(LayerGet);
      REGISTER_GLUT_FUNCTION(BitmapCharacter);
      REGISTER_GLUT_FUNCTION(BitmapWidth);
      REGISTER_GLUT_FUNCTION(BitmapLength);
      REGISTER_GLUT_FUNCTION(StrokeCharacter);
      REGISTER_GLUT_FUNCTION(StrokeWidth);
      REGISTER_GLUT_FUNCTION(StrokeLength);
      REGISTER_GLUT_FUNCTION(WireSphere);
      REGISTER_GLUT_FUNCTION(SolidSphere);
      REGISTER_GLUT_FUNCTION(WireCone);
      REGISTER_GLUT_FUNCTION(SolidCone);
      REGISTER_GLUT_FUNCTION(WireCube);
      REGISTER_GLUT_FUNCTION(SolidCube);
      REGISTER_GLUT_FUNCTION(WireTorus);
      REGISTER_GLUT_FUNCTION(SolidTorus);
      REGISTER_GLUT_FUNCTION(WireDodecahedron);
      REGISTER_GLUT_FUNCTION(SolidDodecahedron);
      REGISTER_GLUT_FUNCTION(WireTeapot);
      REGISTER_GLUT_FUNCTION(SolidTeapot);
      REGISTER_GLUT_FUNCTION(WireOctahedron);
      REGISTER_GLUT_FUNCTION(SolidOctahedron);
      REGISTER_GLUT_FUNCTION(WireTetrahedron);
      REGISTER_GLUT_FUNCTION(SolidTetrahedron);
      REGISTER_GLUT_FUNCTION(WireIcosahedron);
      REGISTER_GLUT_FUNCTION(SolidIcosahedron);
      REGISTER_GLUT_FUNCTION(VideoResizeGet);
      REGISTER_GLUT_FUNCTION(SetupVideoResizing);
      REGISTER_GLUT_FUNCTION(StopVideoResizing);
      REGISTER_GLUT_FUNCTION(VideoResize);
      REGISTER_GLUT_FUNCTION(VideoPan);
      REGISTER_GLUT_FUNCTION(ReportErrors);
      REGISTER_GLUT_FUNCTION(GameModeString);
      REGISTER_GLUT_FUNCTION(EnterGameMode);
      REGISTER_GLUT_FUNCTION(LeaveGameMode);
      REGISTER_GLUT_FUNCTION(GameModeGet);
      // not a glut function really
      REGISTER_GLUT_FUNCTION(Exit);
    }
    
    void initConstants()
    {
      // use GLUT_API_VERSION 3
      
      mIConstants["RGB"] = GLUT_RGB;
      mIConstants["RGBA"] = GLUT_RGBA;
      mIConstants["INDEX"] = GLUT_INDEX;
      mIConstants["SINGLE"] = GLUT_SINGLE;
      mIConstants["DOUBLE"] = GLUT_DOUBLE;
      mIConstants["ACCUM"] = GLUT_ACCUM;
      mIConstants["ALPHA"] = GLUT_ALPHA;
      mIConstants["DEPTH"] = GLUT_DEPTH;
      mIConstants["STENCIL"] = GLUT_STENCIL;
      mIConstants["MULTISAMPLE"] = GLUT_MULTISAMPLE;
      mIConstants["STEREO"] = GLUT_STEREO;
      mIConstants["LUMINANCE"] = GLUT_LUMINANCE;
      mIConstants["LEFT_BUTTON"] = GLUT_LEFT_BUTTON;
      mIConstants["MIDDLE_BUTTON"] = GLUT_MIDDLE_BUTTON;
      mIConstants["RIGHT_BUTTON"] = GLUT_RIGHT_BUTTON;
      mIConstants["DOWN"] = GLUT_DOWN;
      mIConstants["UP"] = GLUT_UP;
      mIConstants["KEY_F1"] = GLUT_KEY_F1;
      mIConstants["KEY_F2"] = GLUT_KEY_F2;
      mIConstants["KEY_F3"] = GLUT_KEY_F3;
      mIConstants["KEY_F4"] = GLUT_KEY_F4;
      mIConstants["KEY_F5"] = GLUT_KEY_F5;
      mIConstants["KEY_F6"] = GLUT_KEY_F6;
      mIConstants["KEY_F7"] = GLUT_KEY_F7;
      mIConstants["KEY_F8"] = GLUT_KEY_F8;
      mIConstants["KEY_F9"] = GLUT_KEY_F9;
      mIConstants["KEY_F10"] = GLUT_KEY_F10;
      mIConstants["KEY_F11"] = GLUT_KEY_F11;
      mIConstants["KEY_F12"] = GLUT_KEY_F12;
      mIConstants["KEY_LEFT"] = GLUT_KEY_LEFT;
      mIConstants["KEY_UP"] = GLUT_KEY_UP;
      mIConstants["KEY_RIGHT"] = GLUT_KEY_RIGHT;
      mIConstants["KEY_DOWN"] = GLUT_KEY_DOWN;
      mIConstants["KEY_PAGE_UP"] = GLUT_KEY_PAGE_UP;
      mIConstants["KEY_PAGE_DOWN"] = GLUT_KEY_PAGE_DOWN;
      mIConstants["KEY_HOME"] = GLUT_KEY_HOME;
      mIConstants["KEY_END"] = GLUT_KEY_END;
      mIConstants["KEY_INSERT"] = GLUT_KEY_INSERT;
      mIConstants["LEFT"] = GLUT_LEFT;
      mIConstants["ENTERED"] = GLUT_ENTERED;
      mIConstants["MENU_NOT_IN_USE"] = GLUT_MENU_NOT_IN_USE;
      mIConstants["MENU_IN_USE"] = GLUT_MENU_IN_USE;
      mIConstants["NOT_VISIBLE"] = GLUT_NOT_VISIBLE;
      mIConstants["VISIBLE"] = GLUT_VISIBLE;
      mIConstants["HIDDEN"] = GLUT_HIDDEN;
      mIConstants["FULLY_RETAINED"] = GLUT_FULLY_RETAINED;
      mIConstants["PARTIALLY_RETAINED"] = GLUT_PARTIALLY_RETAINED;
      mIConstants["FULLY_COVERED"] = GLUT_FULLY_COVERED;
      mIConstants["RED"] = GLUT_RED;
      mIConstants["GREEN"] = GLUT_GREEN;
      mIConstants["BLUE"] = GLUT_BLUE;
      mIConstants["ACTIVE_SHIFT"] = GLUT_ACTIVE_SHIFT;
      mIConstants["ACTIVE_CTRL"] = GLUT_ACTIVE_CTRL;
      mIConstants["ACTIVE_ALT"] = GLUT_ACTIVE_ALT;
      mIConstants["CURSOR_RIGHT_ARROW"] = GLUT_CURSOR_RIGHT_ARROW;
      mIConstants["CURSOR_LEFT_ARROW"] = GLUT_CURSOR_LEFT_ARROW;
      mIConstants["CURSOR_INFO"] = GLUT_CURSOR_INFO;
      mIConstants["CURSOR_DESTROY"] = GLUT_CURSOR_DESTROY;
      mIConstants["CURSOR_HELP"] = GLUT_CURSOR_HELP;
      mIConstants["CURSOR_CYCLE"] = GLUT_CURSOR_CYCLE;
      mIConstants["CURSOR_SPRAY"] = GLUT_CURSOR_SPRAY;
      mIConstants["CURSOR_WAIT"] = GLUT_CURSOR_WAIT;
      mIConstants["CURSOR_TEXT"] = GLUT_CURSOR_TEXT;
      mIConstants["CURSOR_CROSSHAIR"] = GLUT_CURSOR_CROSSHAIR;
      mIConstants["CURSOR_UP_DOWN"] = GLUT_CURSOR_UP_DOWN;
      mIConstants["CURSOR_LEFT_RIGHT"] = GLUT_CURSOR_LEFT_RIGHT;
      mIConstants["CURSOR_TOP_SIDE"] = GLUT_CURSOR_TOP_SIDE;
      mIConstants["CURSOR_BOTTOM_SIDE"] = GLUT_CURSOR_BOTTOM_SIDE;
      mIConstants["CURSOR_LEFT_SIDE"] = GLUT_CURSOR_LEFT_SIDE;
      mIConstants["CURSOR_RIGHT_SIDE"] = GLUT_CURSOR_RIGHT_SIDE;
      mIConstants["CURSOR_TOP_LEFT_CORNER"] = GLUT_CURSOR_TOP_LEFT_CORNER;
      mIConstants["CURSOR_TOP_RIGHT_CORNER"] = GLUT_CURSOR_TOP_RIGHT_CORNER;
      mIConstants["CURSOR_BOTTOM_RIGHT_CORNER"] = GLUT_CURSOR_BOTTOM_RIGHT_CORNER;
      mIConstants["CURSOR_BOTTOM_LEFT_CORNER"] = GLUT_CURSOR_BOTTOM_LEFT_CORNER;
      mIConstants["CURSOR_INHERIT"] = GLUT_CURSOR_INHERIT;
      mIConstants["CURSOR_NONE"] = GLUT_CURSOR_NONE;
      mIConstants["CURSOR_FULL_CROSSHAIR"] = GLUT_CURSOR_FULL_CROSSHAIR;
      mIConstants["KEY_REPEAT_OFF"] = GLUT_KEY_REPEAT_OFF;
      mIConstants["KEY_REPEAT_ON"] = GLUT_KEY_REPEAT_ON;
      mIConstants["KEY_REPEAT_DEFAULT"] = GLUT_KEY_REPEAT_DEFAULT;
      mIConstants["JOYSTICK_BUTTON_A"] = GLUT_JOYSTICK_BUTTON_A;
      mIConstants["JOYSTICK_BUTTON_B"] = GLUT_JOYSTICK_BUTTON_B;
      mIConstants["JOYSTICK_BUTTON_C"] = GLUT_JOYSTICK_BUTTON_C;
      mIConstants["JOYSTICK_BUTTON_D"] = GLUT_JOYSTICK_BUTTON_D;
      mEConstants["GAME_MODE_ACTIVE"] = GLUT_GAME_MODE_ACTIVE;
      mEConstants["GAME_MODE_POSSIBLE"] = GLUT_GAME_MODE_POSSIBLE;
      mEConstants["GAME_MODE_WIDTH"] = GLUT_GAME_MODE_WIDTH;
      mEConstants["GAME_MODE_HEIGHT"] = GLUT_GAME_MODE_HEIGHT;
      mEConstants["GAME_MODE_PIXEL_DEPTH"] = GLUT_GAME_MODE_PIXEL_DEPTH;
      mEConstants["GAME_MODE_REFRESH_RATE"] = GLUT_GAME_MODE_REFRESH_RATE;
      mEConstants["GAME_MODE_DISPLAY_CHANGED"] = GLUT_GAME_MODE_DISPLAY_CHANGED;
      
      mPConstants["STROKE_ROMAN"] = GLUT_STROKE_ROMAN;
      mPConstants["STROKE_MONO_ROMAN"] = GLUT_STROKE_MONO_ROMAN;
      mPConstants["BITMAP_9_BY_15"] = GLUT_BITMAP_9_BY_15;
      mPConstants["BITMAP_8_BY_13"] = GLUT_BITMAP_8_BY_13;
      mPConstants["BITMAP_TIMES_ROMAN_10"] = GLUT_BITMAP_TIMES_ROMAN_10;
      mPConstants["BITMAP_TIMES_ROMAN_24"] = GLUT_BITMAP_TIMES_ROMAN_24;
      mPConstants["BITMAP_HELVETICA_10"] = GLUT_BITMAP_HELVETICA_10;
      mPConstants["BITMAP_HELVETICA_12"] = GLUT_BITMAP_HELVETICA_12;
      mPConstants["BITMAP_HELVETICA_18"] = GLUT_BITMAP_HELVETICA_18;
      
      mEConstants["WINDOW_X"] = GLUT_WINDOW_X;
      mEConstants["WINDOW_Y"] = GLUT_WINDOW_Y;
      mEConstants["WINDOW_WIDTH"] = GLUT_WINDOW_WIDTH;
      mEConstants["WINDOW_HEIGHT"] = GLUT_WINDOW_HEIGHT;
      mEConstants["WINDOW_BUFFER_SIZE"] = GLUT_WINDOW_BUFFER_SIZE;
      mEConstants["WINDOW_STENCIL_SIZE"] = GLUT_WINDOW_STENCIL_SIZE;
      mEConstants["WINDOW_DEPTH_SIZE"] = GLUT_WINDOW_DEPTH_SIZE;
      mEConstants["WINDOW_RED_SIZE"] = GLUT_WINDOW_RED_SIZE;
      mEConstants["WINDOW_GREEN_SIZE"] = GLUT_WINDOW_GREEN_SIZE;
      mEConstants["WINDOW_BLUE_SIZE"] = GLUT_WINDOW_BLUE_SIZE;
      mEConstants["WINDOW_ALPHA_SIZE"] = GLUT_WINDOW_ALPHA_SIZE;
      mEConstants["WINDOW_ACCUM_RED_SIZE"] = GLUT_WINDOW_ACCUM_RED_SIZE;
      mEConstants["WINDOW_ACCUM_GREEN_SIZE"] = GLUT_WINDOW_ACCUM_GREEN_SIZE;
      mEConstants["WINDOW_ACCUM_BLUE_SIZE"] = GLUT_WINDOW_ACCUM_BLUE_SIZE;
      mEConstants["WINDOW_ACCUM_ALPHA_SIZE"] = GLUT_WINDOW_ACCUM_ALPHA_SIZE;
      mEConstants["WINDOW_DOUBLEBUFFER"] = GLUT_WINDOW_DOUBLEBUFFER;
      mEConstants["WINDOW_RGBA"] = GLUT_WINDOW_RGBA;
      mEConstants["WINDOW_PARENT"] = GLUT_WINDOW_PARENT;
      mEConstants["WINDOW_NUM_CHILDREN"] = GLUT_WINDOW_NUM_CHILDREN;
      mEConstants["WINDOW_COLORMAP_SIZE"] = GLUT_WINDOW_COLORMAP_SIZE;      
      mEConstants["WINDOW_NUM_SAMPLES"] = GLUT_WINDOW_NUM_SAMPLES;
      mEConstants["WINDOW_STEREO"] = GLUT_WINDOW_STEREO;
      mEConstants["WINDOW_CURSOR"] = GLUT_WINDOW_CURSOR;
      mEConstants["SCREEN_WIDTH"] = GLUT_SCREEN_WIDTH;
      mEConstants["SCREEN_HEIGHT"] = GLUT_SCREEN_HEIGHT;
      mEConstants["SCREEN_WIDTH_MM"] = GLUT_SCREEN_WIDTH_MM;
      mEConstants["SCREEN_HEIGHT_MM"] = GLUT_SCREEN_HEIGHT_MM;
      mEConstants["MENU_NUM_ITEMS"] = GLUT_MENU_NUM_ITEMS;
      mEConstants["DISPLAY_MODE_POSSIBLE"] = GLUT_DISPLAY_MODE_POSSIBLE;
      mEConstants["INIT_WINDOW_X"] = GLUT_INIT_WINDOW_X;
      mEConstants["INIT_WINDOW_Y"] = GLUT_INIT_WINDOW_Y;
      mEConstants["INIT_WINDOW_WIDTH"] = GLUT_INIT_WINDOW_WIDTH;
      mEConstants["INIT_WINDOW_HEIGHT"] = GLUT_INIT_WINDOW_HEIGHT;
      mEConstants["INIT_DISPLAY_MODE"] = GLUT_INIT_DISPLAY_MODE;
      mEConstants["ELAPSED_TIME"] = GLUT_ELAPSED_TIME;
      mEConstants["WINDOW_FORMAT_ID"] = GLUT_WINDOW_FORMAT_ID;
      mEConstants["HAS_KEYBOARD"] = GLUT_HAS_KEYBOARD;
      mEConstants["HAS_MOUSE"] = GLUT_HAS_MOUSE;
      mEConstants["HAS_SPACEBALL"] = GLUT_HAS_SPACEBALL;
      mEConstants["HAS_DIAL_AND_BUTTON_BOX"] = GLUT_HAS_DIAL_AND_BUTTON_BOX;
      mEConstants["HAS_TABLET"] = GLUT_HAS_TABLET;
      mEConstants["NUM_MOUSE_BUTTONS"] = GLUT_NUM_MOUSE_BUTTONS;
      mEConstants["NUM_SPACEBALL_BUTTONS"] = GLUT_NUM_SPACEBALL_BUTTONS;
      mEConstants["NUM_BUTTON_BOX_BUTTONS"] = GLUT_NUM_BUTTON_BOX_BUTTONS;
      mEConstants["NUM_DIALS"] = GLUT_NUM_DIALS;
      mEConstants["NUM_TABLET_BUTTONS"] = GLUT_NUM_TABLET_BUTTONS;
      mEConstants["DEVICE_IGNORE_KEY_REPEAT"] = GLUT_DEVICE_IGNORE_KEY_REPEAT;
      mEConstants["DEVICE_KEY_REPEAT"] = GLUT_DEVICE_KEY_REPEAT;
      mEConstants["HAS_JOYSTICK"] = GLUT_HAS_JOYSTICK;
      mEConstants["OWNS_JOYSTICK"] = GLUT_OWNS_JOYSTICK;
      mEConstants["JOYSTICK_BUTTONS"] = GLUT_JOYSTICK_BUTTONS;
      mEConstants["JOYSTICK_AXES"] = GLUT_JOYSTICK_AXES;
      mEConstants["JOYSTICK_POLL_RATE"] = GLUT_JOYSTICK_POLL_RATE;
      mEConstants["OVERLAY_POSSIBLE"] = GLUT_OVERLAY_POSSIBLE;
      mEConstants["LAYER_IN_USE"] = GLUT_LAYER_IN_USE;
      mEConstants["HAS_OVERLAY"] = GLUT_HAS_OVERLAY;
      mEConstants["TRANSPARENT_INDEX"] = GLUT_TRANSPARENT_INDEX;
      mEConstants["NORMAL_DAMAGED"] = GLUT_NORMAL_DAMAGED;
      mEConstants["OVERLAY_DAMAGED"] = GLUT_OVERLAY_DAMAGED;
      mEConstants["VIDEO_RESIZE_POSSIBLE"] = GLUT_VIDEO_RESIZE_POSSIBLE;
      mEConstants["VIDEO_RESIZE_IN_USE"] = GLUT_VIDEO_RESIZE_IN_USE;
      mEConstants["VIDEO_RESIZE_X_DELTA"] = GLUT_VIDEO_RESIZE_X_DELTA;
      mEConstants["VIDEO_RESIZE_Y_DELTA"] = GLUT_VIDEO_RESIZE_Y_DELTA;
      mEConstants["VIDEO_RESIZE_WIDTH_DELTA"] = GLUT_VIDEO_RESIZE_WIDTH_DELTA;
      mEConstants["VIDEO_RESIZE_HEIGHT_DELTA"] = GLUT_VIDEO_RESIZE_HEIGHT_DELTA;
      mEConstants["VIDEO_RESIZE_X"] = GLUT_VIDEO_RESIZE_X;
      mEConstants["VIDEO_RESIZE_Y"] = GLUT_VIDEO_RESIZE_Y;
      mEConstants["VIDEO_RESIZE_WIDTH"] = GLUT_VIDEO_RESIZE_WIDTH;
      mEConstants["VIDEO_RESIZE_HEIGHT"] = GLUT_VIDEO_RESIZE_HEIGHT;
      mEConstants["NORMAL"] = GLUT_NORMAL;
      mEConstants["OVERLAY"] = GLUT_OVERLAY;
    }
    
    void registerPyConstants(PyObject *m)
    {
      if (mIConstants.size() + mEConstants.size() + mPConstants.size() == 0)
      {
        initConstants();
        
        std::map<std::string, unsigned int>::iterator iit = mIConstants.begin();
        while (iit != mIConstants.end())
        {
          PyModule_AddIntConstant(m, iit->first.c_str(), iit->second);
          ++iit;
        }
        
        std::map<std::string, void*>::iterator pit = mPConstants.begin();
        while (pit != mPConstants.end())
        {
          PyModule_AddObject(m, pit->first.c_str(), PyCObject_FromVoidPtr(pit->second, dummyFree));
          ++pit;
        }
        
        std::map<std::string, GLenum>::iterator eit = mEConstants.begin();
        while (eit != mEConstants.end())
        {
          PyModule_AddIntConstant(m, eit->first.c_str(), eit->second);
          ++eit;
        }
      }
    }
    
    PyMethodDef* getPyFunctions()
    {
      extern bool operator!=(const PyMethodDef&, const PyMethodDef&);
      
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
    
    std::map<int, PyObject*> mMenuCallbacks;
    std::map<int, PyObject*> mTimerCallbacks;
    std::map<int, WindowCallbacks> mWinCallbacks;
    PyObject *mMenuStatusCallback;
    PyObject *mIdleCallback;
    
    std::map<std::string, unsigned int> mIConstants;
    std::map<std::string, void*> mPConstants;
    std::map<std::string, GLenum> mEConstants;
    
    std::vector<PyMethodDef> mFunctions;
};


unsigned int PyGLUT::INTEGER_ERROR = (unsigned int)-1;
GLenum PyGLUT::ENUM_ERROR = (GLenum)-2;
void* PyGLUT::PTR_ERROR = (void*)-1;
PyGLUT* PyGLUT::msInstance = 0;

// ---

void PyGL_CleanupGLUT(void *obj)
{
#ifdef _DEBUG
  std::cout << "PyGL_CleanupGLUT" << std::endl;
#endif
  delete ((PyGLUT*)obj);
}

// ---

bool PyGL_InitGLUT(PyObject *mod)
{
  PyGLUT &glut = PyGLUT::Instance();
  
  PyObject *smod = Py_InitModule("glut", glut.getPyFunctions());
  
  glut.registerPyConstants(smod);
  
  PyObject *cleanup = PyCObject_FromVoidPtr((void*)&glut, PyGL_CleanupGLUT);
  PyModule_AddObject(smod, "__cleanupObj", cleanup);
  
  if (mod != NULL)
  {
    PyModule_AddObject(mod, "glut", smod);
  }
  
  return true;
}

PyMODINIT_FUNC initglut(void)
{
  PyGL_InitGLUT(NULL);
}


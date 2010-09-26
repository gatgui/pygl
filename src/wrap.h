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

#ifndef __pygl_wrap_h_
#define __pygl_wrap_h_

#include "convert.h"

#define CHECK_ARG_COUNT(args, n) \
  if (PyTuple_Size(args) != n) {\
    PyErr_Format(PyExc_RuntimeError, "Expected %d arguments count", n);\
    return 0;\
  }

struct WrapFunc0 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)()) {
    CHECK_ARG_COUNT(args, 0);
    func();
    Py_RETURN_NONE;
  }
};
template <typename A>
struct WrapFunc1 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T)) {
    CHECK_ARG_COUNT(args, 1);
    A arg0(PyTuple_GetItem(args, 0));
    func(arg0);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B>
struct WrapFunc2 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T)) {
    CHECK_ARG_COUNT(args, 2);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    func(arg0, arg1);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C>
struct WrapFunc3 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T)) {
    CHECK_ARG_COUNT(args, 3);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    func(arg0, arg1, arg2);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D>
struct WrapFunc4 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T)) {
    CHECK_ARG_COUNT(args, 4);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    func(arg0, arg1, arg2, arg3);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E>
struct WrapFunc5 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T)) {
    CHECK_ARG_COUNT(args, 5);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    func(arg0, arg1, arg2, arg3, arg4);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F>
struct WrapFunc6 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T)) {
    CHECK_ARG_COUNT(args, 6);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    func(arg0, arg1, arg2, arg3, arg4, arg5);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G>
struct WrapFunc7 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T)) {
    CHECK_ARG_COUNT(args, 7);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    G arg6(PyTuple_GetItem(args, 6));
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H>
struct WrapFunc8 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T)) {
    CHECK_ARG_COUNT(args, 8);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    G arg6(PyTuple_GetItem(args, 6));
    H arg7(PyTuple_GetItem(args, 7));
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I>
struct WrapFunc9 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T)) {
    CHECK_ARG_COUNT(args, 9);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    G arg6(PyTuple_GetItem(args, 6));
    H arg7(PyTuple_GetItem(args, 7));
    I arg8(PyTuple_GetItem(args, 8));
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I, typename J>
struct WrapFunc10 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T,
                                                             typename J::T)) {
    CHECK_ARG_COUNT(args, 10);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    G arg6(PyTuple_GetItem(args, 6));
    H arg7(PyTuple_GetItem(args, 7));
    I arg8(PyTuple_GetItem(args, 8));
    J arg9(PyTuple_GetItem(args, 9));
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    Py_RETURN_NONE;
  }
};
template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G, typename H, typename I, typename J,
          typename K>
struct WrapFunc11 {
  static inline PyObject* Call(PyObject *, PyObject *args, void (CALLBACK *func)(typename A::T, typename B::T, typename C::T,
                                                             typename D::T, typename E::T, typename F::T,
                                                             typename G::T, typename H::T, typename I::T,
                                                             typename J::T, typename K::T)) {
    CHECK_ARG_COUNT(args, 11);
    A arg0(PyTuple_GetItem(args, 0));
    B arg1(PyTuple_GetItem(args, 1));
    C arg2(PyTuple_GetItem(args, 2));
    D arg3(PyTuple_GetItem(args, 3));
    E arg4(PyTuple_GetItem(args, 4));
    F arg5(PyTuple_GetItem(args, 5));
    G arg6(PyTuple_GetItem(args, 6));
    H arg7(PyTuple_GetItem(args, 7));
    I arg8(PyTuple_GetItem(args, 8));
    J arg9(PyTuple_GetItem(args, 9));
    K arg10(PyTuple_GetItem(args, 10));
    func(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    Py_RETURN_NONE;
  }
};

#endif

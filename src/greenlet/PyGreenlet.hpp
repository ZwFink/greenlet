#ifndef PYGREENLET_HPP
#define PYGREENLET_HPP


#include "greenlet.h"
#include "greenlet_compiler_compat.hpp"
#include "greenlet_refs.hpp"


using greenlet::refs::OwnedGreenlet;
using greenlet::refs::BorrowedGreenlet;
using greenlet::refs::BorrowedObject;;
using greenlet::refs::OwnedObject;
using greenlet::refs::PyErrPieces;


// XXX: These doesn't really belong here, it's not a Python slot.
OwnedObject internal_green_throw(BorrowedGreenlet self, PyErrPieces& err_pieces);

PyGreenlet* green_new(PyTypeObject* type, PyObject* UNUSED(args), PyObject* UNUSED(kwds));
int green_clear(PyGreenlet* self);
int green_init(PyGreenlet* self, PyObject* args, PyObject* kwargs);
int green_setparent(PyGreenlet* self, PyObject* nparent, void* UNUSED(context));
int green_setrun(PyGreenlet* self, PyObject* nrun, void* UNUSED(context));
int green_traverse(PyGreenlet* self, visitproc visit, void* arg);
void green_dealloc(PyGreenlet* self);
PyObject* green_getparent(PyGreenlet* self, void* UNUSED(context));

int green_is_gc(PyObject* self);
PyObject* green_getdead(PyGreenlet* self, void* UNUSED(context));
PyObject* green_getrun(PyGreenlet* self, void* UNUSED(context));
int green_setcontext(PyGreenlet* self, PyObject* nctx, void* UNUSED(context));
PyObject* green_getframe(PyGreenlet* self, void* UNUSED(context));
PyObject* green_repr(PyGreenlet* self);
#endif

/*
 * Context.c.  Python interfaces for perf script.
 *
 * Copyright (C) 2010 Tom Zanussi <tzanussi@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <Python.h>
#include "../../../perf.h"
#include "../../../util/trace-event.h"

#if PY_MAJOR_VERSION < 3
#define _PyCapsule_GetPointer(arg1, arg2) \
  PyCObject_AsVoidPtr(arg1)

PyMODINIT_FUNC initperf_trace_context(void);
#else
#define _PyCapsule_GetPointer(arg1, arg2) \
  PyCapsule_GetPointer((arg1), (arg2))

PyMODINIT_FUNC PyInit_perf_trace_context(void);
#endif

static PyObject *perf_trace_context_common_pc(PyObject *obj, PyObject *args)
{
	static struct scripting_context *scripting_context;
	PyObject *context;
	int retval;

	if (!PyArg_ParseTuple(args, "O", &context))
		return NULL;

	scripting_context = _PyCapsule_GetPointer(context, NULL);
	retval = common_pc(scripting_context);

	return Py_BuildValue("i", retval);
}

static PyObject *perf_trace_context_common_flags(PyObject *obj,
						 PyObject *args)
{
	static struct scripting_context *scripting_context;
	PyObject *context;
	int retval;

	if (!PyArg_ParseTuple(args, "O", &context))
		return NULL;

	scripting_context = _PyCapsule_GetPointer(context, NULL);
	retval = common_flags(scripting_context);

	return Py_BuildValue("i", retval);
}

static PyObject *perf_trace_context_common_lock_depth(PyObject *obj,
						      PyObject *args)
{
	static struct scripting_context *scripting_context;
	PyObject *context;
	int retval;

	if (!PyArg_ParseTuple(args, "O", &context))
		return NULL;

	scripting_context = _PyCapsule_GetPointer(context, NULL);
	retval = common_lock_depth(scripting_context);

	return Py_BuildValue("i", retval);
}

static PyMethodDef ContextMethods[] = {
	{ "common_pc", perf_trace_context_common_pc, METH_VARARGS,
	  "Get the common preempt count event field value."},
	{ "common_flags", perf_trace_context_common_flags, METH_VARARGS,
	  "Get the common flags event field value."},
	{ "common_lock_depth", perf_trace_context_common_lock_depth,
	  METH_VARARGS,	"Get the common lock depth event field value."},
	{ NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initperf_trace_context(void)
{
	(void) Py_InitModule("perf_trace_context", ContextMethods);
}
#else
PyMODINIT_FUNC PyInit_perf_trace_context(void)
{
	static struct PyModuleDef moduledef = {
		PyModuleDef_HEAD_INIT,
		"perf_trace_context",	/* m_name */
		"",			/* m_doc */
		-1,			/* m_size */
		ContextMethods,		/* m_methods */
		NULL,			/* m_reload */
		NULL,			/* m_traverse */
		NULL,			/* m_clear */
		NULL,			/* m_free */
	};
	return PyModule_Create(&moduledef);
}
#endif

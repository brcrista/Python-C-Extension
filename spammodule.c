#define PY_SSIZE_T_CLEAN
#include <Python.h>

//! Call the C `system` function with the arguments in `args`.
static PyObject* spam_system(PyObject* self, PyObject* args)
{
    const char* command;
    if (!PyArg_ParseTuple(args, "s", &command))
    {
        // In this case, PyArg_ParseTuple has already set the exception.
        // NULL is a sentinel value for "error".
        // To return the Python None value, use
        //   PyINCREF(Py_None);
        //   return Py_None;
        return NULL;
    }

    int sts = system(command);
    if (sts < 0)
    {
        PyErr_SetString(SpamError, "Call to `system()` failed");
        return NULL;
    }

    // Return the value as a Python object (an integer).
    return PyLong_FromLong(sts);
}

// The module's method table
static PyMethodDef SpamMethods[] =
{
    { "system", spam_system, METH_VARARGS, "Execute a command on the underlying shell." },
    { NULL, NULL, 0, NULL } // Sentinel
};

static spam_doc = NULL;

// The module's definition
static struct PyModuleDef spammodule =
{
    PyModuleDef_HEAD_INIT,
    "spam", // name of the module
    spam_doc, // module documentation
    -1, // the module keeps state in global variables
    SpamMethods
};

// A custom exception type for this module.
static PyObject* SpamError;

//! The initialization function for the `spam` module.
PyMODINIT_FUNC PyInit_spam(void)
{
    PyObject* module = PyModule_Create(&spammodule);
    if (module == NULL)
    {
        return NULL;
    }

    // The Python name for the exception type is `spam.error`
    // with a base class of `Exception`.
    SpamError = PyErr_NewException("spam.error", NULL, NULL);

    // Make sure the `spam.error` type object does not get garbage collected
    // if some Python code deletes it from the module.
    Py_INCREF(SpamError);

    PyModule_AddObject(module, "error", SpamError);
    return module;
}

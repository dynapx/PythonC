#define PY_SSIZE_T_CLEAN
#include <Python.h>
static PyObject *SpamError;

static PyObject * spam_system(PyObject *self, PyObject *args)
{
//    const char *command;
//    int sts;
//
//    if (!PyArg_ParseTuple(args, "s", &command))
//        return NULL;
//    sts = system(command);
//    if(sts<0){
//
//    PyErr_SetString(SpamError, "System command failed");
//     return NULL;
//     }

//    PyObject *test1=_PyObject_New(PyLong_FromLong(1));
PyObject *test1=_PyObject_New(PyLong_FromLong(1000));
    printf("test1=%d\n",Py_REFCNT(test1));
    PyObject* test2=test1;
    printf("test2=%d\n",Py_REFCNT(test2));

    return test1;
}




static PyMethodDef SpamMethods[] = {

    {"system",  spam_system,METH_VARARGS,
     "Execute a shell command."},
      {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    if (PyModule_AddObjectRef(m, "error", SpamError) < 0) {
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}





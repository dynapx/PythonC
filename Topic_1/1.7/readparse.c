#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject * readparse_test(PyObject *self, PyObject *args)
{
int ok;
int i, j;
//long k, l;
const char *s;
Py_ssize_t size;

//ok = PyArg_ParseTuple(args, "s",&s); /* No arguments */
//    /* Python call: f() */
//
//    ok = PyArg_ParseTuple(args, "lls", &k, &l, &s); /* Two longs and a string */
//    /* Possible Python call: f(1, 2, 'three') */
//

    ok = PyArg_ParseTuple(args, "(ii)s#", &i, &j, &s, &size);
    /* A pair of ints and a string, whose size is also returned */
    /* Possible Python call: f((1, 2), 'three') */
//    return Py_BuildValue("i", 123);
return Py_BuildValue("{s:i,s:i}",
              "abc", 123, "def", 456);

}


static PyMethodDef readparseMethods[] = {

    {"test", readparse_test, METH_VARARGS,
     "jsut a test."},
      {NULL, NULL, 0, NULL}        /* Sentinel */
};
static struct PyModuleDef readparse = {
    PyModuleDef_HEAD_INIT,
    "readparse",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    readparseMethods
};

PyMODINIT_FUNC PyInit_readparse(void)
{
    PyObject *m;

    m = PyModule_Create(&readparse);
    if (m == NULL)
        return NULL;

    return m;
}
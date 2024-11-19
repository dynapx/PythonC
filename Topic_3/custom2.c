#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h> /* for offsetof() */



typedef struct {
    PyObject_HEAD
    PyObject *first; /* first name */
    PyObject *last;  /* last name */
    int number;
} CustomObject;

//static PyObject *
//custom_repr(CustomObject *obj)
//{
//    return PyUnicode_FromFormat("print the new type {{name:%S %S}}",
//                                obj->first,obj->last);
//}

static PyObject *
custom_str(CustomObject *obj)
{
    return PyUnicode_FromFormat("print the new type {{name:%S %S}}",
                                obj->first,obj->last);
}
static int Custom_traverse(CustomObject*self,visitproc visit, void *arg)
{
    Py_VISIT(self->first);
    printf("freed first\n");
    Py_VISIT(self->last);
    printf("freed last\n");
    return 0;
}
static int Custom_clear(CustomObject *self)
{
    Py_CLEAR(self->first);
    Py_CLEAR(self->last);
    return 0;
}

static void Custom_dealloc(CustomObject *self)
{
//    Py_XDECREF(self->first);
//    Py_XDECREF(self->last);
//    Py_TYPE(self)->tp_free((PyObject *) self);
  PyObject_GC_UnTrack(self);
    Custom_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
   // printf("delte over\n");
}

static PyObject *
Custom_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    CustomObject *self;
    self = (CustomObject *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->first = PyUnicode_FromString("");
        if (self->first == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->last = PyUnicode_FromString("");
        if (self->last == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->number = 0;
    }
    return (PyObject *) self;
}

static int
Custom_init(CustomObject *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"first", "last", "number", NULL};
    PyObject *first = NULL, *last = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOi", kwlist,
                                     &first, &last,
                                     &self->number))
        return -1;

    if (first) {
        Py_XSETREF(self->first, Py_NewRef(first));
    }
    if (last) {
        Py_XSETREF(self->last, Py_NewRef(last));
    }
    return 0;
}

static PyMemberDef Custom_members[] = {
    {"first", Py_T_OBJECT_EX, offsetof(CustomObject, first), 0,
     "first name"},
    {"last", Py_T_OBJECT_EX, offsetof(CustomObject, last), 0,
     "last name"},
    {"number", Py_T_INT, offsetof(CustomObject, number), 0,
     "custom number"},
    {NULL}  /* Sentinel */
};

static PyObject *
Custom_name(CustomObject *self, PyObject *Py_UNUSED(ignored))
{
    if (self->first == NULL) {
        PyErr_SetString(PyExc_AttributeError, "first");
        return NULL;
    }
    if (self->last == NULL) {
        PyErr_SetString(PyExc_AttributeError, "last");
        return NULL;
    }
    return PyUnicode_FromFormat("%S %S", self->first, self->last);
}

static PyMethodDef Custom_methods[] = {
    {"name", (PyCFunction) Custom_name, METH_NOARGS,
     "Return the name, combining the first and last name"
    },
    {NULL}  /* Sentinel */
};
static PyObject *
CustomObject_richcmp(CustomObject *obj1, CustomObject *obj2, int op)
{
    PyObject *result;
    int c, size1, size2;

    /* code to make sure that both arguments are of type
       newdatatype omitted */

    size1 = obj1->number;
    size2 = obj2->number;

    switch (op) {
    case Py_LT: c = size1 <  size2; break;
    case Py_LE: c = size1 <= size2; break;
    case Py_EQ: c = size1 == size2; break;
    case Py_NE: c = size1 != size2; break;
    case Py_GT: c = size1 >  size2; break;
    case Py_GE: c = size1 >= size2; break;
    }
    result = c ? Py_True : Py_False;
    Py_INCREF(result);
    return result;
 }


static PyTypeObject CustomType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "custom2.Custom",
    .tp_doc = PyDoc_STR("Custom objects"),
    .tp_basicsize = sizeof(CustomObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE| Py_TPFLAGS_HAVE_GC,
    .tp_new = Custom_new,
    .tp_init = (initproc) Custom_init,
    .tp_dealloc = (destructor) Custom_dealloc,
    .tp_traverse=(traverseproc) Custom_traverse,
    .tp_clear=(inquiry) Custom_clear,
    .tp_members = Custom_members,
    .tp_methods = Custom_methods,
    //.tp_repr=custom_repr,
    .tp_str=custom_str,
    .tp_richcompare=CustomObject_richcmp
};
static PyObject *my_function(PyObject *self, PyObject *args) {
    PyObject *some_object;

    // 解析参数
    if (!PyArg_ParseTuple(args, "O", &some_object)) {
        return NULL;
    }

    // 检查类型
    if (!PyObject_TypeCheck(some_object, &CustomType)) {
        //PyErr_SetString(PyExc_TypeError, "arg #1 not a MyType object");
           printf(" not pass the check\n");
         Py_RETURN_NONE;
    }
    printf(" pass the check\n");

    // 类型匹配，继续处理
    Py_RETURN_NONE;
}
static PyMethodDef Mymethod[]=
{
   { "my_function",my_function,METH_VARARGS , "CHECK IF ARGUMENT IS MYTYPE"},
   {NULL,NULL,0,NULL}
};

static PyModuleDef custommodule = {
    PyModuleDef_HEAD_INIT,
    "custom2",
     "Example module that creates an extension type.",
    -1,
    Mymethod
};

PyMODINIT_FUNC
PyInit_custom2(void)
{
    PyObject *m;
    if (PyType_Ready(&CustomType) < 0)
        return NULL;

    m = PyModule_Create(&custommodule);
    if (m == NULL)
        return NULL;

    if (PyModule_AddObjectRef(m, "Custom", (PyObject *) &CustomType) < 0) {
        Py_DECREF(m);
        return NULL;
    }

    return m;
}

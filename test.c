#include <Python.h>
void check_refcount(PyObject *obj) {
    // 获取对象的引用计数并打印
    printf("Reference count for the object: %ld\n", Py_REFCNT(obj));
}
//void print_total_refcount() {
//    // 打印 _Py_RefTotal 的值
//    printf("Total refcount operations: %ld\n", _Py_RefTotal);
//}
int main() {
    // 初始化 Python 解释器
    Py_Initialize();
    // 获取全局对象 None

    //print_total_refcount();
    PyObject *obj1 = PyLong_FromLong(4);
    //print_total_refcount();
    PyObject *obj2 = Py_None;
    //print_total_refcount();
    PyObject *obj3 = PyLong_FromLong(400);
    //print_total_refcount();
    // 检查 None 对象的引用计数
//    check_refcount(obj1);
//    check_refcount(obj2);
//     check_refcount(obj3);
//
//      // 尝试使用 Py_SET_REFCNT() 修改引用计数
//    Py_SET_REFCNT(obj1, 20);  // 对永生对象无效，引用计数不会改变
//    Py_SET_REFCNT(obj3, 20);//对正常对象有效
//    printf("set 为20 后：\n");
//     check_refcount(obj1);
//      check_refcount(obj3);
//       // 使用 _Py_NewReference()（模拟）来重新初始化引用计数
//    _Py_NewReference(obj3);  // 对于普通对象，初始化引用计数
//    _Py_NewReference(obj1);
//      printf("new 后：\n");
//     check_refcount(obj1);
//      check_refcount(obj3);




      Py_INCREF(obj1);
      Py_INCREF(obj2);
      Py_INCREF(obj3);
      printf("加1：\n");
      check_refcount(obj1);
      check_refcount(obj2);
     check_refcount(obj3);

     for(int i=1;i<=42949672000;i++)
     {
     Py_DECREF(obj1);
     }
     Py_DECREF(obj2);
     Py_DECREF(obj3);
     printf("减1：\n");
      check_refcount(obj1);
      check_refcount(obj2);
     check_refcount(obj3);
    // 关闭 Python 解释器
    Py_Finalize();
    return 0;
}
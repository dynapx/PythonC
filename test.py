# import sys
# # a = None
# # b=1
# # print(sys.getrefcount(a))  # 输出可能是一个非常大的值，因为 None 是永生对象（全局单例对象）
# # print(sys.getrefcount(b))#小整数缓存,永生对象
#
#
# print("Total refcount before operations:", sys.gettotalrefcount())
#
# # 对永生对象进行引用计数操作
# a = None
# sys.getrefcount(a)  # 调用会临时增加引用计数
#
# print("Total refcount after operations:", sys.gettotalrefcount())




import gc
import sys

# 查看当前垃圾回收器是否启用
print("Is garbage collection enabled?", gc.isenabled())

# 检查永生对象（如 None）的引用计数
print("Reference count for None before GC:", sys.getrefcount(None))

# 强制运行垃圾回收
gc.collect()

# 检查 None 的引用计数是否改变
print("Reference count for None after GC:", sys.getrefcount(None))
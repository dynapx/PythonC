from setuptools import setup, Extension

# 定义扩展模块
spam_module = Extension(
    'spam',  # 扩展模块名，与 Python 中导入的名字一致
    sources=['spammodule.c'],  # 包含的源文件
    include_dirs=[],  # 指定头文件路径
    library_dirs=[],  # 指定库文件路径
    libraries=[]  # 需要链接的库
)

# keywdarg_module = Extension(
#     'keywdarg',  # 扩展模块名，与 Python 中导入的名字一致
#     sources=['Topic_1\\1.8\keywdarg.c'],  # 包含的源文件
#     include_dirs=[],  # 指定头文件路径
#     library_dirs=[],  # 指定库文件路径
#     libraries=[]  # 需要链接的库
# )


# setup 函数配置扩展模块
setup(
    name='mymodule',  # 模块名
    version='1.0',
    description='A simple Python C extension module',
    ext_modules=[spam_module]  # 使用定义好的扩展模块
)

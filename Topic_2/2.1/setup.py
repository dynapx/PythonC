from setuptools import setup ,Extension

custom_module=Extension(
    'custom',
    sources=['custom.c'],
    include_dirs=[],
    library_dirs=[],
    libraries=[]
)

setup(name="mymodule",version='1.0',description='A simple Python C extension module',ext_modules=[custom_module])
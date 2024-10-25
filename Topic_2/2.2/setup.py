from setuptools import setup ,Extension

custom2_module=Extension(
    'custom2',
    sources=['custom2.c'],
    include_dirs=[],
    library_dirs=[],
    libraries=[]
)

setup(name="mymodule",version='1.0',description='A simple Python C extension module',ext_modules=[custom2_module])
from setuptools import Extension, setup
setup(ext_modules=[Extension("custom2", ["custom2.c"])])
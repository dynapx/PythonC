from setuptools import Extension, setup
setup(ext_modules=[Extension("custom3", ["custom3.c"])])
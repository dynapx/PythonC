from setuptools import Extension, setup
setup(ext_modules=[Extension("sublist", ["sublist.c"])])
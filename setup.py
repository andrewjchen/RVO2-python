#!/usr/bin/env python
 
from distutils.core import setup
from distutils.extension import Extension
from glob import glob

files=glob('src/*.cpp')

setup(name="pyrvo2",
    ext_modules=[
        Extension("pyrvo2", 
        	files,
        libraries = ["boost_python"]),
    ])


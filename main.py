# export LD_LIBRARY_PATH=.

from ctypes import cdll

cpp_lib = cdll.LoadLibrary("CPPlib.so")
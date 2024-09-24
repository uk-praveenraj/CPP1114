import ctypes
import os

cwd = os.getcwd()
print(cwd)
#path="C://learn/CPP1114/cpp_world/python-bindings//ctypes//cpp//cfunc.so"
cfunc = ctypes.CDLL(cwd+"//cfunc.so")

cfunc.func()
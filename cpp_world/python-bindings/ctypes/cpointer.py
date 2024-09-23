import ctypes

cpointer = ctypes.CDLL("C:/learn/CPP1114/cpp_world/python-bindings/ctypes/cpointer.so")

alloc_func = cpointer.alloc_mem
alloc_func.restype = ctypes.POINTER(ctypes.c_char_p)

free_func = cpointer.free_mem
free_func.argtypes = [ctypes.POINTER(ctypes.c_char_p)]

str_pointer = alloc_func()
#print(str_pointer.value) # won't work

str = ctypes.c_char_p.from_buffer(str_pointer)
print(str.value) # will work

free_func(str_pointer)


######################
num = ctypes.c_int(100)
ptr = ctypes.pointer(num)
print(ptr)
print(ptr.contents)

ptr1 = ctypes.POINTER(ctypes.c_int)
ptr1.contents=num
print(ptr1.contents)

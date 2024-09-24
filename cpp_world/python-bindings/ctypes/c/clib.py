import ctypes

clib = ctypes.CDLL("C:\learn\CPP1114\cpp_world\python-bindings\ctypes\c\clib.so")
clib.display(b"Name", 18)

func=clib.display
func.argtypes = [ctypes.c_char_p, ctypes.c_int]
func.restype = ctypes.c_char_p

str = ctypes.c_char_p(b"New name")
func(str, 19)

print(str)

str.value = b"another name"
print(str)

#to get the same address
str = ctypes.create_string_buffer(100) 
str.value = b"another name again"
print(str)
str.value = b"another name over again"
print(str)

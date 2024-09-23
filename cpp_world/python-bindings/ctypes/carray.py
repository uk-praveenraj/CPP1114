import ctypes

carray = ctypes.CDLL("C:/learn/CPP1114/cpp_world/python-bindings/ctypes/carray.so")

values = (ctypes.c_int * 10)()

for i in range(len(values)):
    values[i] = i

sum = carray.sumArray(values, len(values))
print(sum)

carray.incArray.restype = ctypes.POINTER(ctypes.c_int)
result = carray.incArray(values, len(values))
print(result)
print(result.contents)

for i in range(10):
    print(result[i])

carray.getArray.restype = ctypes.POINTER(ctypes.c_int)
result = carray.getArray()
for i in range(10):
    print(result[i])

carray.freeMem(result)
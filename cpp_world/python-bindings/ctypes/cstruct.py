import ctypes

cstruct = ctypes.CDLL("C:/learn/CPP1114/cpp_world/python-bindings/ctypes/cstruct.so")

class Point(ctypes.Structure):
    _fields_ = [("x", ctypes.c_int),
                ("y", ctypes.c_int)]

p = Point(5,10)
print(p)
print(p.x)
print(p.y)

cstruct.printPoint()

cstruct.getPoint.restype = ctypes.POINTER(Point)
p1 = cstruct.getPoint()
#print(p1)
print(p1.contents.x, p1.contents.y)

class Student(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p)]

s = Student(b"England") # or look below
cstruct.printStu(s)

name = "New England"
s = Student(bytes(name, 'utf-8'))
cstruct.printStu(s)

cstruct.getStu.restype = ctypes.POINTER(Student)
s=cstruct.getStu()
print(s)
print(s.contents)
print(s.contents.name)
print(s.contents.name.decode('utf-8'))

cstruct.freeMem(s)

#Arrays

class PointArray(ctypes.Structure):
    _fields_ = [("points", Point * 3)]

#points = (Point(1,1), Point(2,3),Point(5,6))
pa = PointArray( (Point(1,1), Point(2,3),Point(5,6)) )
cstruct.printPA(pa)
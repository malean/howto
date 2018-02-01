import ctypes

mylib = ctypes.CDLL("../build/src/libmylib.so")

# int sum
print(mylib.int_sum(4, 5))

# float sum
mylib.float_sum.argtypes = [ctypes.c_float, ctypes.c_float]
mylib.float_sum.restype = ctypes.c_float
print(mylib.float_sum(4, 5))


class Foo(ctypes.Structure):
  _fields_ = [('num', ctypes.c_int), 
              ('val', ctypes.c_float)]

myfoo = Foo()
myfoo.num = 3
myfoo.val = 3.14

print(myfoo)

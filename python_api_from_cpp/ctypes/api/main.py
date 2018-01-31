import ctypes

mylib = ctypes.CDLL("/home/cdoucet/Depots/forexample/ctypes/build/src/libmylib.so")

# int sum
print(mylib.int_sum(4, 5))

# float sum
mylib.float_sum.argtypes = [ctypes.c_float, ctypes.c_float]
mylib.float_sum.restype = ctypes.c_float
print(mylib.float_sum(4, 5))

cdef extern from "hello.c":
    void f()
    
cpdef myf():
    f()

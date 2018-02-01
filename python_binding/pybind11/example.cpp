#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

struct Foo
{
  int num;
  double val;
};

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    pybind11::class_<Foo>(m, "Foo")
      .def_readwrite("num", &Foo::num)
      .def_readwrite("val", &Foo::val)
      .def(pybind11::init<>());
}


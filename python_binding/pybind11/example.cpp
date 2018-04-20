#include <pybind11/pybind11.h>

#include <iostream>
#include <map>



int add(int i, int j) {
    return i + j;
}

struct Foo
{
  int num;
  double val;
};


class Base
{};

class Derived : public Base
{};


class Bar
{
  public:
    std::map<std::string, std::unique_ptr<Base>> get()
    { 
      std::map<std::string, std::unique_ptr<Base>> map;
      return map; 
    }

    void set(std::map<std::string, std::unique_ptr<Base>> const & map)
    { std::cout << "it works!" << std::endl; }

};

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    pybind11::class_<Foo>(m, "Foo")
      .def_readwrite("num", &Foo::num)
      .def_readwrite("val", &Foo::val)
      .def(pybind11::init<>());


  pybind11::class_<Base>(m, "Base")
    .def(pybind11::init<>());

  pybind11::class_<Bar>(m, "Bar")
    .def(pybind11::init<>())
    .def("get", &Bar::get)
    .def("set", &Bar::set);

}

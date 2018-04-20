

#include "abstract.hpp"


#include <pybind11/pybind11.h>

BaseList get_list()
{
  BaseList list;
  list.push_back(new Derived("toto"));
  list.push_back(new Derived("titi"));
  return list;
}

void print_list(BaseList const & list)
{ std::cout << list.to_string() << std::endl; }


class PyBase : public Base 
{
  public:
    using Base::Base;
    
    /* Trampoline (need one for each virtual function) */
    virtual std::string const & name() const
    { PYBIND11_OVERLOAD_PURE(std::string const &, Base, name); }
    
    virtual void print() const
    { PYBIND11_OVERLOAD_PURE(void, Base, print); }
};

class PyDerived : public Derived 
{
  public:
    using Derived::Derived;
    
    virtual std::string const & name() const
    { PYBIND11_OVERLOAD_PURE(std::string const &, Derived, name); }
    
    /* Trampoline (need one for each virtual function) */
    virtual void print() const
    { PYBIND11_OVERLOAD_PURE(void, Derived, print); }
};



PYBIND11_MODULE(abstract, m) 
{
  pybind11::class_<Base, PyBase>(m, "Base")
    .def(pybind11::init<>())
    .def("print", &Base::print)
    ;

  pybind11::class_<Derived, PyDerived>(m, "Derived")
    .def(pybind11::init<std::string const &>())
    .def("print", &Derived::print)
    ;

  pybind11::class_<BaseList>(m, "BaseList")
    .def(pybind11::init<>())
    .def("__repr__", [](BaseList const & list) { return list.to_string(); });
    ;
  
  m.def("get_list", &get_list);
  m.def("print_list", &print_list);
}

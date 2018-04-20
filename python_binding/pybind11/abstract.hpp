

#ifndef ABSTRACT_HPP
#define ABSTRACT_HPP

#include <iostream>
#include <vector>

class Base
{
  public:
    
    virtual std::string const & name() const = 0;
    virtual void print() const = 0;

    virtual ~Base()
    {}
};


class Derived : public Base
{

  public:

    Derived(std::string const & name)
    : name_(name)
    {}

    virtual std::string const & name() const
    { return name_; }

    virtual void print() const
    { std::cout << name_ << std::endl; }

  private:

    std::string name_;


};


class BaseList
{

  public:

    void push_back(Base * base)
    { elements_.push_back(base); }

    std::string to_string() const
    {
      std::string str = "( ";

      std::vector<Base*>::const_iterator it;
      for (it = elements_.begin(); it != elements_.end(); ++it)
      {
        str += (*it)->name() + " ";
      }
      str += ")";

      return str;
    }


  private:

    std::vector<Base*> elements_;



};


BaseList get_list();
void print_list(BaseList const &);

#endif

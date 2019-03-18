#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include <iostream>
#include <vector>
#include <forward_list>
#include <functional>

namespace detail
{
  template<typename C>
  struct bracketsImplementation
  {
    typedef std::size_t indexType;
    static typename C::value_type & getElement(C & container, size_t index)
    {
      return container[index];
    }

    static size_t getBegin(const C & /*container*/)
    {
      return 0;
    }

    static size_t getEnd(const C & container)
    {
      return container.size();
    }

    static size_t getNextIndex (size_t index)
    {
      return ++index;
    }  
  };

  template<typename C>
  struct atImplementation
  {
    typedef std::size_t indexType;
    static typename C::value_type & getElement(C & container, size_t index)
    {
      return container.at(index);
    }

    static size_t getBegin(const C & /*container*/)
    {
      return 0;
    }

    static size_t getEnd(const C & container)
    {
      return container.size();
    }

    static size_t getNextIndex(size_t index)
    {
      return ++index;
    }  
  };

  template<typename C>
  struct iteratorImplementation
  {
    typedef typename C::iterator indexType;
    static typename C::value_type & getElement(C & /*container*/, typename C::iterator & iter)
    {
      return *iter;
    }

    static typename C::iterator getBegin(C & container)
    {
      return container.begin();
    }

    static typename C::iterator getEnd(C & container)
    {
      return container.end();
    }

    static typename C::iterator getNextIndex(typename C::iterator & iter)
    {
      return std::next(iter);
    }    
  };

  template<template<class C> class Traits, typename C>
  void sort(C & container, std::string order)
  {
    std::function<bool(typename C::value_type, typename C::value_type)> comp;

    if (order == "ascending")
    {
      comp = std::greater<typename C::value_type>();
    }
    else
    {
      comp = std::less<typename C::value_type>();
    }

    using indexType = typename Traits<C>::indexType;
    const indexType containerEnd = Traits<C>::getEnd(container);
    for (indexType i = Traits<C>::getBegin(container); i != containerEnd; i++)
    {
      for (indexType j = Traits<C>::getNextIndex(i); j != containerEnd; j++)
      {
        typename C::value_type & a = Traits<C>::getElement(container, i);
        typename C::value_type & b = Traits<C>::getElement(container, j);
        if(comp(a, b))
        {
          std::swap(a, b);
        }
      }
    }
  }

  template<typename T>
  void printContainerValues(const T & val)
  {
    for (typename T::const_iterator iter = val.cbegin(); iter != val.cend(); iter++)
    {
      std::cout << *iter << " ";
    }
    std::cout << std::endl;
  }
}

std::string getSortOrder(const std::string & param);

void runTask1(int args, char *argv[]);
void runTask2(int args, char *argv[]);
void runTask3(int args, char *argv[]);
void runTask4(int args, char *argv[]);

#endif

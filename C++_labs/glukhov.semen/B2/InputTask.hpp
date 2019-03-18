#ifndef INPUTTASK_HPP
#define INPUTTASK_HPP

#include <iostream>
#include <list>
#include "element.hpp"

class InputParser
{
public:
  InputParser(std::istream & in);
  void parseInput();
  std::list <element_t>::iterator begin();
  std::list <element_t>::iterator end();
  
private:
  std::list<element_t> text_;
  std::istream & in_;
  void readWord();
  void readNumber();
  void readDash();
  void readElement();
};

#endif

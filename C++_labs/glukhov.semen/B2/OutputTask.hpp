#ifndef OUTPUTTASK_HPP
#define OUTPUTTASK_HPP

#include <iostream>
#include <list>
#include "element.hpp"

void printLine (std::ostream & out, const std::list<element_t> & line);
int reorganizeLine (std::ostream & out, std::list<element_t> & line);
void formatText(std::ostream & out, unsigned int width, const std::list<element_t> & vector);
bool trueOrder (const std::list<element_t> & vector);

#endif

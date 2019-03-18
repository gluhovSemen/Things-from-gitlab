#include <iostream>
#include <vector>
#include <forward_list>
#include <string>
#include <stdexcept>
#include "declarations.hpp"

void runTask1(int args, char *argv[])
{
  if (args != 3)
  {
    throw std::invalid_argument("Incorrect amount of parameters for task №1!");
  }

  std::string order = argv[2];

  if ((order != "ascending") && (order != "descending"))
  {
    throw std::invalid_argument("Incorrect parameter of sorting!");
  }

  std::forward_list<int> list1;
  int nextValue = 0;
  while (std::cin >> nextValue)
  {
    list1.push_front(nextValue);
  }
  if ((std::cin.fail()) && (!std::cin.eof()))
  {
    throw std::invalid_argument("Incorrect input!");
  }
  std::vector<int> vector1(list1.begin(), list1.end());
  std::vector<int> vector2(list1.begin(), list1.end());

  detail::sort<detail::iteratorImplementation>(list1, order);
  detail::printContainerValues(list1);

  detail::sort<detail::bracketsImplementation>(vector1, order);
  detail::printContainerValues(vector1);

  detail::sort<detail::atImplementation>(vector2, order);
  detail::printContainerValues(vector2);
}

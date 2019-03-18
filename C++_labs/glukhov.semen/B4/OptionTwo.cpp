#include "Options.hpp"
#include "factorials.hpp"
#include <iostream>

int optionTwo()
{
  FactContainer cont;
  std::copy(cont.begin(), cont.end(), std::ostream_iterator<size_t>(std::cout, " "));
  std::cout << std::endl;
  std::reverse_iterator<FactContainer::Iterator>rbeg(cont.end()--);
  std::reverse_iterator<FactContainer::Iterator>rend(cont.begin());
  std::copy(rbeg, rend, std::ostream_iterator<size_t>(std::cout, " "));
  std::cout << std::endl;

  return 0;

}

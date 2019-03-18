#include <iostream>
#include "Options.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "wrong input ";
    return 1;
  }
  else if(std::string(argv[1]) == "1")
  {
    return optionOne();
  }
  else if (std::string(argv[1]) == "2")
  {
    return optionTwo();
  }
  else
  {
    std::cerr << "wrong input ";
    return 1;
  }
  return 0;
}

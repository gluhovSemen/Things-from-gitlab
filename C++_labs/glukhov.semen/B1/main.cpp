#include <iostream>
#include <stdexcept>
#include <string>
#include "declarations.hpp"

int main(int args, char *argv[])
{
  if (args < 2)
  {
    std::cerr << "The number of the task required!" << std::endl;
    return 1;
  }

  try
  {
    int variant = std::stoi(argv[1]);
    switch (variant)
    {
    case 1:
      runTask1(args, argv);
      break;
    case 2:
      runTask2(args, argv);
      break;
    case 3:
      runTask3(args, argv);
      break;
    case 4:
      runTask4(args, argv);
      break;
    default:
      std::cerr << "Wrong number of the task!" << std::endl;
      return 1;
    }
  }
  
  catch (const std::exception & error)
  {
    std::cerr << error.what() << std::endl;
    return 1;
  }
  
  return 0;
}

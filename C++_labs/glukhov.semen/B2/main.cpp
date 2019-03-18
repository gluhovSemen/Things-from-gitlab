#include <iostream>
#include "InputTask.hpp"
#include "OutputTask.hpp"

int main(int args, char * argv[])
{
  int width = 40;
  
  if (args > 1)
  {
    if (args != 3)
    {
      std::cerr << "Incorrect amount of parameters!";
      return 1;
    }
    else if (std::string(argv[1]) != "--line-width")
    {
      std::cerr << "Incorrect arguments!";
      return 1;
    }
    else
    {
      width = std::stoi(argv[2]);
      if (width < 24)
      {
        std::cerr << "Incorrect line width!";
        return 1;
      }
    }
  }
  
  try 
  {
    InputParser parser(std::cin);
    parser.parseInput();
    
    std::list<element_t> vector(parser.begin(), parser.end());

    if (!trueOrder(vector))
    {
      throw std::invalid_argument("Incorrect input!");
    }
    
    formatText(std::cout, width, vector);
  }
  
  catch (const std::invalid_argument & error)
  {
    std::cerr << error.what();
    return 1;
  }
  
  return 0;
}

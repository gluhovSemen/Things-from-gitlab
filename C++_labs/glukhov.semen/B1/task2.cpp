#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>
#include "declarations.hpp"

void runTask2(int args, char *argv[])
{
  
  if(args != 3)
  {
    throw std::invalid_argument("Incorrect amount of parameters for task №2!");
  }

  std::ifstream input(argv[2], std::ios_base::in);
  if(!input.good())
  {
    throw std::invalid_argument("Incorrect filename for task №2!");
  }

  input.seekg(0, std::ios_base::end);
  std::streamsize size = input.tellg();
  input.seekg(0, std::ios_base::beg);

  std::unique_ptr<char[]> contents(new char[size]);
  input.read(contents.get(), size);

  if(!input)
  {
    throw std::ios_base::failure("Error while reading the file!");
  }

  std::vector<char> vector(contents.get(), contents.get() + size);

  for (auto i = vector.begin(); i != vector.end(); i++)
  {
    std::cout << *i;
  }
}

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stdexcept>
#include "declarations.hpp"

void fillRandom(double * array, int size)
{
  std::random_device rnd;
  std::mt19937 randomize(rnd());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);
  for (int i = 0; i < size; i++)
  {
    array[i] = dist(randomize);
  }
}

void runTask4(int args, char *argv[])
{
  if (args != 4)
  {
    throw std::invalid_argument("Incorrect amount of parameters for task №4!");
  }

  std::string order = argv[2];

  if ((order != "ascending") && (order != "descending"))
  {
    throw std::invalid_argument("Incorrect parameter of sorting!");
  }
  
  std::vector<double> vector(std::stoi(argv[3]));

  if(!vector.empty())
  {
    fillRandom(&vector[0], vector.size());
    detail::printContainerValues(vector);
    detail::sort<detail::atImplementation>(vector, order);
    detail::printContainerValues(vector);
  }
}

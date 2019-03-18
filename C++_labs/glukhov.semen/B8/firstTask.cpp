#define _USE_MATH_DEFINES
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <functional>

#include "figures.hpp"
#include "tasks.hpp"


void firstTask()
{
  std::vector<double> vector{ std::istream_iterator<double>(std::cin), std::istream_iterator<double>() };
  if (!std::cin.eof())
  {
    throw std::invalid_argument("Invalid input!");
  }
  if (vector.empty())
  {
    return;
  }

  std::transform(vector.begin(), vector.end(), vector.begin(),
    std::bind2nd(std::multiplies<double>(), M_PI));
  std::copy(vector.begin(), vector.end(), std::ostream_iterator<double>(std::cout, "\n"));
}

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "declarations.hpp"

void runTask3(int args, char*[])
{
  if(args != 2)
  {
    throw std::invalid_argument("Incorrect amount of parameters for task №3!");
  }

  std::vector<int> vector;
  int temp;
  while (std::cin >> temp)
  {
    vector.push_back(temp);
  }

  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input!");
  }

  if(!vector.empty())
  {
    if(vector.back() != 0)
    {
      throw std::invalid_argument("Zero at the end of the input required!");
    }
    else
    {
      vector.pop_back();
    }
  }

  if (!vector.empty())
  {
    int lastValue = vector.back();
    if(lastValue == 1)
    {
      int numberOfEvenValues = 0;
      for (auto i = vector.begin(); i != vector.end(); i++)
      {
        if (*i % 2 == 0)
        {
          std::swap(*i, *std::prev(i, numberOfEvenValues));
          numberOfEvenValues++;
        }
        else if(numberOfEvenValues > 0)
        {
          std::swap(*i, *std::prev(i, numberOfEvenValues));
        }
      }
      vector.erase(std::prev(vector.end(), numberOfEvenValues), vector.end());
    }
    else if(lastValue == 2)
    {
      int oneNumbers = 0;
      for(auto i = vector.begin(); i != vector.end(); i++)
      {
        if(*i % 3 == 0)
        {
          oneNumbers = oneNumbers + 3;
        }
      }
      if (oneNumbers > 0)
      {
        vector.resize(vector.size() + oneNumbers, 1);
        
        for (auto i = std::next(vector.rbegin(), oneNumbers); i != vector.rend(); i++)
        {
          if(*i % 3 == 0)
          {
            oneNumbers -= 3;
          }
          std::swap(*i, *std::prev(i, oneNumbers));
        }
      }
    }
    detail::printContainerValues(vector);
  }
}

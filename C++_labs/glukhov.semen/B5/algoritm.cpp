#include "algoritm.h"

size_t parseNum(const std::string & str, int& dest)
{
  size_t delim = str.find_first_of(',');
  if (delim == std::string::npos)
  {
    throw std::logic_error("There must be two ',' in line");
  }
  size_t pos = 0;
  dest = std::stoi(str.substr(0, delim), &pos);
  if (pos != delim)
  {
    throw std::logic_error("Wrong number");
  }
  if (dest < -5 || dest>5)
  {
    throw std::logic_error("Both keys must be in[-5;5]");
  }
  return delim;
}

void fillVector(std::vector<DataStruct>& arr, std::istream & stream)
{
  std::string line;
  DataStruct temp;
  while (std::getline(stream, line))
  {
    line = line.substr(parseNum(line, temp.key1) + 1);
    temp.str = line.substr(parseNum(line, temp.key2) + 1);
    while (isspace(temp.str.front()))
    {
      temp.str.erase(0, 1);
    }
    arr.push_back(temp);
  }
}

bool cmp(const DataStruct &rhs, const DataStruct &lhs)
{
  if (rhs.key1 < lhs.key1)
  {
    return true;
  }
  if (rhs.key1 == lhs.key1)
  {
    if (rhs.key2 == lhs.key2)
    {
      if (rhs.str.size() == lhs.str.size())
      {
        return (rhs.str < lhs.str);
      }
      return (rhs.str.size() < lhs.str.size());
    }
    return (rhs.key2 < lhs.key2);
  }
  return false;
}

void sortVector(std::vector<DataStruct>& arr)
{
  std::sort(arr.begin(), arr.end(), cmp);
}

void printVector(const std::vector<DataStruct>& arr, std::ostream & stream)
{
  for (auto i:arr)
  {
    stream << i.key1 << "," << i.key2 << "," << i.str << std::endl;
  }
}

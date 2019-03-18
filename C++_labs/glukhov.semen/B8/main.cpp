#include <cstring>
#include "tasks.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2)
  {
    std::cerr << "invalid input!";
    return 1;
  }
  else
  {
    try
    {
      if (std::strcmp(argv[1], "1") == 0)
      {
        firstTask();
        return 0;
      }
      else if (std::strcmp(argv[1], "2") == 0)
      {
        secondTask();
        return 0;
      }
      else
      {
        std::cerr << "invalid input!";
        return 1;
      }
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
  }

  return 0; // useless
}

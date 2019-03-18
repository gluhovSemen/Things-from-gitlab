#include "Tasks.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Invalid input";
    return 1;
  }
  switch (std::stoull(argv[1])) {
    case 1: {
      Tasks::task1();
      break;
    }
    case 2: {
      try {
        Tasks::task2();
      } catch (const std::exception &ex) {
        std::cerr << ex.what();
        return 1;
      }
      break;
    }
    default: {
      std::cerr << "Invalid input";
      return 1;
    }
  }
  return 0;
}


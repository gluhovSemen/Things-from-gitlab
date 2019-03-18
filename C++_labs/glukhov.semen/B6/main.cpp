#include <iostream>
#include <stdexcept>
#include <string>

#include "Parts.hpp"

int main (int argc, char *argv[])
{
  try {
    if (argc != 2) {
      std::cerr << "Invalid args";
      return 1;
    }

    switch (std::stoi(argv[1])) {
      case 1:
      {
        doFirstPart (std::cin, std::cout);
        break;
      }
      case 2:
      {
        doSecondPart (std::cin, std::cout);
        break;
      }
      default:
      {
        std::cerr << "Invalid args";
        return 2;
      }
    }
  }
  catch (const std::ios_base::failure & err) {
    std::cerr << err.what ();
    return 2;
  }
  catch (const std::exception & err) {
    std::cerr << err.what ();
    return 1;
  }
  return 0;
}

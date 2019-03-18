#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "Functor.hpp"

int main()
{
  try {
    std::for_each (std::istream_iterator<int> (std::cin), std::istream_iterator<int> (), Functor (std::cout));
    if (!std::cin.eof ()) {
      std::cerr << "Invalid data";
      return 1;
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


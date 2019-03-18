#include "Parts.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <iterator>

void doFirstPart (std::istream & istream, std::ostream & ostream)
{
  if (istream && ostream) {
    std::set<std::string> set ((std::istream_iterator<std::string> (istream)), std::istream_iterator<std::string> ());
    std::copy (set.begin (), set.end (), std::ostream_iterator<std::string> (ostream, "\n"));
  } else {
    throw std::ios_base::failure ("Stream Crash");
  }
}

#include "Options.hpp"
#include <iostream>
#include <sstream>
#include "PBInterface.hpp"



int optionOne()
{
  PhoneBook book;
  PBinterface bookInterface(book);

  std::string buf;
  std::stringstream command;

  while (std::getline(std::cin, buf))
  {
    command.clear();
    command.str(buf);
    if (!std::cin.good())
    {
      return 2;
    }
    else if (std::cin.eof())
    {
      break;
    }
    else
    {
      bookInterface.chooseAction(command);
    }
  }

  return 0;
}

#include "PBInterface.hpp"

PBinterface::PBinterface(PhoneBook& book):
  m_book(book)
{

}

void PBinterface::chooseAction(std::istream& command)
{
  std::string str;
  command >> str;
  if (str == "add")
  {
    addNote(command);
  }
  else if (str == "store")
  {
    storeMark(command);
  }
  else if (str == "insert")
  {
    insertNote(command);
  }
  else if (str == "delete")
  {
    delNote(command);
  }
  else if (str == "show")
  {
    showNote(command);
  }
  else if (str == "move")
  {
    moveNote(command);
  }
  else
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
  }
}

void PBinterface::addNote(std::istream& command)
{
  std::string number;
  std::string name;
  command >> number;
  command.ignore();
  std::getline(command, name);
  if ((name.empty()) || (number.empty()))
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
    return;
  }
  if (!checkName(name))
  {
    return;
  }
  formatName(name);
  m_book.pushBack(name, number);
}

void PBinterface::storeMark(std::istream& command)
{
  std::string Markname;
  std::string Newmarkname;

  command >> Markname >> Newmarkname;

  if ((Markname.empty()) || (Newmarkname.empty()))
  {
    std::cout  << "<INVALID COMMAND>" << std::endl;
  }
  else
  {
    if (!m_book.makeCurrent(Markname))
    {
      std::cout << "<INVALID BOOKMARK>" << std::endl;
    }
    else
    {
      m_book.addMark(Newmarkname);
    }
  }

}

void PBinterface::insertNote(std::istream& command)
{
  std::string pos;
  std::string markName;
  std::string name;
  std::string number;
  command >> pos >> markName >> number;
  command.ignore();
  std::getline(command, name);

  for (size_t i = 0;i < number.size();i++)
  {
    if (!isdigit(number[i]))
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
      return;
    }
  }

  if (!checkName(name))
  {
    return;
  }

  formatName(name);


  if (!m_book.makeCurrent(markName))
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
    return;
  }

  if (pos == "before")
  {
    m_book.insertBeforeCur(name, number);
  }
  else if (pos == "after")
  {
    m_book.insertAfterCur(name, number);
  }
  else
  {
    std::cout << "<INVALID COMMAND>";
  }

}

void PBinterface::showNote(std::istream& command)
{
  std::string Markname;
  command >> Markname;

  if (Markname.empty())
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
    return;
  }
  if (!m_book.makeCurrent(Markname))
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
  else
  {
      if (m_book.getSize() == 0)
      {
        std::cout << "<EMPTY>" << std::endl;
        return;
      }
    std::cout << m_book.getNote().second << ' ' << m_book.getNote().first << std::endl;
  }
}

void PBinterface::moveNote(std::istream& command)
{
  std::string markname, steps;
  command >> markname >> steps;
  if (!command.eof() || markname.empty() || steps.empty())
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
    return;
  }

  if (!m_book.makeCurrent(markname))
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
    return;
  }

  if (steps == "last")
  {
    m_book.goAheadTo(m_book.getSize());
  }
  else if (steps == "first")
  {
    m_book.goBackTo(m_book.getSize());
  }
  else
  {
    for (size_t i = 0;i < steps.size();i++)
    {
      if (i == 0 && (steps[i] == '-' || steps[i] == '+'))
      {
        continue;
      }
      if (!isdigit(steps[i]))
      {
        std::cout << "<INVALID STEP>" << std::endl;
        return;
      }
    }
    int numsteps = std::stoi(steps);
    if (numsteps > 0)
    {
      m_book.goAheadTo(numsteps);
    }
    else if (numsteps < 0)
    {
      m_book.goBackTo(-numsteps);
    }
  }


}

void PBinterface::delNote(std::istream& command)
{
  std::string Markname;
  command >> Markname;
  if (!m_book.makeCurrent(Markname))
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
    return;
  }

  m_book.deleteCur();
}

void PBinterface::formatName(std::string& name)
{
  std::string::iterator itr = name.begin();
  while (itr != name.end())
  {
    if ((*itr == '\\') && ((*(itr + 1) == '\\') || (*(itr + 1) == '"')))
    {
      itr = name.erase(itr) + 1;
    }
    else if (*itr == '"')
    {
      itr = name.erase(itr);
    }
    else
    {
      ++itr;
    }
  }

}

bool PBinterface::checkName(const std::string& name) const
{
  if (name[0] != '"' || name[name.size() - 1] != '"')
  {
    std::cout << "<INVALID COMMAND>" << std::endl;
    return false;
  }
  return true;
}

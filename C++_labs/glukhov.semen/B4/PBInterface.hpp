#ifndef PBInterface_
#define PBInterface_
#include <list>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

class PBinterface 
{
public:
  PBinterface(PhoneBook & book);
  void chooseAction(std::istream& command);
private:
  PhoneBook& m_book;
  PBinterface() = delete;
  
  void addNote(std::istream& command);
  void storeMark(std::istream& command);
  void insertNote(std::istream& command);
  void showNote(std::istream& command);
  void moveNote(std::istream& command);
  void delNote(std::istream& command);
  void formatName(std::string& name);
  bool checkName(const std::string& name) const;
};

#endif // QueueWithPriority_

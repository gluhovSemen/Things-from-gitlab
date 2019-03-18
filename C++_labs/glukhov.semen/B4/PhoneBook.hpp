#ifndef PhoneBook_
#define PhoneBook_
#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <utility>

class PhoneBook 
{
public:
  typedef std::pair < std::string, std::string > note_t;
  typedef std::list<note_t>::iterator iterator_t;
  typedef std::pair<iterator_t, std::string> bookmark_t;

  PhoneBook();
  
  note_t& getNote() const;
  int goPrev();
  int goNext();
  int replaceCurNote(const std::string& name, const std::string& number);
  int insertAfterCur(const std::string& name, const std::string& number);
  int insertBeforeCur(const std::string& name, const std::string& number);
  int pushBack(const std::string& name, const std::string& number);
  bool makeCurrent(const std::string& name);
  void addMark(const std::string& name);
  int goAheadTo(size_t n);
  int goBackTo(size_t n);
  int deleteCur();
  size_t getSize() const;
private:
  std::list<note_t> m_book;
  std::list<bookmark_t> m_bookmarks;
  std::list<bookmark_t>::iterator m_curmarkIt;
};

#endif // QueueWithPriority_

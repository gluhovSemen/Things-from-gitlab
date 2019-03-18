#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
  m_bookmarks.push_back(std::make_pair(m_book.begin(), "current"));
  m_curmarkIt = m_bookmarks.begin();
}

PhoneBook::note_t& PhoneBook::getNote() const
{
  return *(m_curmarkIt->first);
}

int PhoneBook::goAheadTo(size_t n)
{
  if (m_book.empty())
  {
    return 1;
  }
  std::list<note_t>::iterator itr = m_curmarkIt->first;
  for (size_t i = 0; i < n;i++)
  {
    itr++;
    if (itr == m_book.end())
    {
      itr--;
      m_curmarkIt->first = itr;
      return 0;
    }
  }
  m_curmarkIt->first = itr;
  return 0;
}

int PhoneBook::goBackTo(size_t n)
{
  if (m_book.empty())
  {
    return 1;
  }
  std::list<note_t>::iterator itr = m_curmarkIt->first;
  for (size_t i = 0; i < n;i++)
  {
    if (itr == m_book.begin())
    {
      m_curmarkIt->first = itr;
      return 0;
    }
    itr--;
  }
  m_curmarkIt->first = itr;
  return 0;
}

int PhoneBook::goNext()
{
  if (m_book.empty())
  {
    return 1;
  }
  if (std::next(m_curmarkIt->first) != m_book.end())
  {
    m_curmarkIt->first = std::next(m_curmarkIt->first);
  }
  return 0;
}

int PhoneBook::goPrev()
{
  if (m_book.empty())
  {
    return 1;
  }
  if (m_curmarkIt->first != m_book.begin())
  {
    m_curmarkIt->first = std::prev(m_curmarkIt->first);
  }
  return 0;
}

int PhoneBook::insertAfterCur(const std::string& name, const std::string& number)
{
  if (m_curmarkIt->first == m_book.end())
  {
    m_book.push_back(std::make_pair(name, number));
    m_curmarkIt->first--;
    return 0;
  }
  try {
    m_book.insert(std::next(m_curmarkIt->first), std::make_pair(name, number));
  }
  catch (std::bad_alloc)
  {
    return 1;
  }

  if (m_curmarkIt->first == m_book.end())
  {
    m_curmarkIt->first--;
  }
  return 0;
}

int PhoneBook::insertBeforeCur(const std::string& name, const std::string& number)
{
  try {
    m_book.insert(m_curmarkIt->first, std::make_pair(name, number));
  }
  catch (std::bad_alloc)
  {
    return 1;
  }
  if (m_curmarkIt->first == m_book.end())
  {
    m_curmarkIt->first--;
  }
  return 0;
}

int PhoneBook::replaceCurNote(const std::string& name, const std::string& number)
{
  if (m_book.empty())
  {
    return 1;
  }
  if (m_curmarkIt->first == m_book.end())
  {
    return 1;
  }
  try {
    *(m_curmarkIt->first) = std::make_pair(name, number);
  }
  catch (std::bad_alloc)
  {
    return 1;
  }
  return 0;
}

int PhoneBook::pushBack(const std::string& name, const std::string& number)
{
  try {
    m_book.push_back(std::make_pair(name, number));
  }
  catch (std::bad_alloc)
  {
    return 1;
  }
  if (m_book.size() == 1)
  {
    m_curmarkIt->first = m_book.begin();
  }
  return 0;
}

bool PhoneBook::makeCurrent(const std::string& name)
{
  for (std::list<bookmark_t>::iterator it = m_bookmarks.begin(); it != m_bookmarks.end(); it++)
  {
    if (it->second == name)
    {
      m_curmarkIt = it;
      return true;
    }
  }
  return false;
}

int PhoneBook::deleteCur()
{
  if (m_book.empty() || m_curmarkIt->first == m_book.end())
  {
    return 1;
  }
  iterator_t deleted = m_curmarkIt->first;
  iterator_t LastElem = --m_book.end();

  for (std::list<bookmark_t>::iterator it = m_bookmarks.begin(); it != m_bookmarks.end();++it)
  {
    if (it->first == deleted)
    {
      if ((it->first == LastElem) && (m_book.size() > 1))
      {
        --(it->first);
      }
      else
      {
        ++(it->first);
      }
    }
  }

  m_book.erase(deleted);
  return 0;
}

size_t PhoneBook::getSize() const
{
  return m_book.size();
}

void PhoneBook::addMark(const std::string& name)
{
  if (m_book.empty())
  {
    return;
  }
  m_bookmarks.push_back(std::make_pair(m_curmarkIt->first, name));
}

#ifndef Factorials_
#define Factorials_
#include <iterator>

class FactContainer
{
public:
  class Iterator;
  Iterator begin();
  Iterator end();
};

class FactContainer::Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
{
public:
  Iterator();
  Iterator(size_t n);

  size_t& operator*();
  size_t* operator->();
  Iterator& operator++();
  const Iterator operator++(int);
  Iterator& operator--();
  const Iterator operator--(int);

  bool operator==(const Iterator& itr) const;
  bool operator!=(const Iterator& itr) const;

private:
  size_t m_number;
  static size_t m_common;
  size_t m_fact;
  size_t fact(size_t number);
};
#endif

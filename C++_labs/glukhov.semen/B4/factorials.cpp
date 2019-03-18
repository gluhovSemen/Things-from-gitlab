#include "factorials.hpp"

size_t FactContainer::Iterator::m_common;

FactContainer::Iterator FactContainer::begin()
{
  return FactContainer::Iterator(1);
}

FactContainer::Iterator FactContainer::end()
{
  return FactContainer::Iterator(11);
}

FactContainer::Iterator::Iterator():
  Iterator(1)
{
}

FactContainer::Iterator::Iterator(size_t num) :
  m_number(num),
  m_fact(fact(num))
{
}

size_t FactContainer::Iterator::fact(size_t number)
{
  if (number == 0)
  {
    return 1;
  }
  size_t result = 1;
  for (size_t i = 2; i != number + 1;i++)
  {
    result *=i;
  }
  return result;
}

size_t& FactContainer::Iterator::operator*()
{
  m_common = m_fact;
  return m_common;
}

size_t* FactContainer::Iterator::operator->()
{
  m_common = m_fact;
  return &m_common;
}

FactContainer::Iterator& FactContainer::Iterator::operator++()
{
  m_number++;
  m_fact *= m_number;

  return *this;
}

const FactContainer::Iterator FactContainer::Iterator::operator++(int)
{
  FactContainer::Iterator itr = *this;
    m_number++;
    m_fact *= m_number;


  return itr;
}

FactContainer::Iterator& FactContainer::Iterator::operator--()
{
  m_fact /= m_number;
  m_number--;
  return *this;
}

const FactContainer::Iterator FactContainer::Iterator::operator--(int)
{
  FactContainer::Iterator itr = *this;

  m_fact /= m_number;
  m_number--;

  return itr;
}


bool FactContainer::Iterator::operator==(const Iterator& itr) const
{
  return ((m_number == itr.m_number)&& (m_fact == itr.m_fact));
}

bool FactContainer::Iterator::operator!=(const Iterator& itr) const
{
  return !(*this == itr);
}

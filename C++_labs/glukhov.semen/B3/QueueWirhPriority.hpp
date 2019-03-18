#ifndef B3_QUEUE_WITH_PRIORITY_HPP
#define B3_QUEUE_WITH_PRIORITY_HPP

#include <memory>
#include <list>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>

enum class ElementPriority {
  high,
  normal,
  low
};


template<typename T>
class QueueWithPriority {
public:
  void add(const T &element, const ElementPriority &elementPriority);

  void accelerate();

  T get();

  bool isEmpty();

private:
  std::list<T> high_, normal_, low_;
};

template<typename T>
bool QueueWithPriority<T>::isEmpty()
{
  return high_.empty() && normal_.empty() && low_.empty();
}

template<typename T>
void QueueWithPriority<T>::add(const T &element, const ElementPriority &elementPriority)
{
  switch (elementPriority) {
    case ElementPriority::high:
      high_.push_back(element);
      break;
    case ElementPriority::normal:
      normal_.push_back(element);
      break;
    case ElementPriority::low:
      low_.push_back(element);
      break;
  }
}

template<typename T>
T QueueWithPriority<T>::get()
{
  if (!high_.empty()) {
    const auto element = high_.front();
    high_.pop_front();
    return element;
  }

  if (!normal_.empty()) {
    const auto element = normal_.front();
    normal_.pop_front();
    return element;
  }

  if (!low_.empty()) {
    const auto element = low_.front();
    low_.pop_front();
    return element;
  }

  throw std::out_of_range("<EMPTY>");
}

template<typename T>
void QueueWithPriority<T>::accelerate()
{
  high_.insert(std::cend(high_), std::cbegin(low_), std::cend(low_));
  low_.clear();
}
#endif //B3_QUEUE_WITH_PRIORITY_HPP


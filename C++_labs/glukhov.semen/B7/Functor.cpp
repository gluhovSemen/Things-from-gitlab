#include "Functor.hpp"

#include <limits>
#include <iostream>
#include <iomanip>

Functor::Functor (std::ostream & ostream) :
  max_ (std::numeric_limits<int>::min ()),
  min_ (std::numeric_limits<int>::max ()),
  positive_ (0),
  negative_ (0),
  elements_ (0),
  first_ (0),
  sum_ (0),
  oddS_ (0),
  evenS_ (0),
  wasFirst_ (false),
  isFirstEqualLast_ (false),
  ostream_ (&ostream),
  isCopy_ (false)
{
}

Functor::Functor (const Functor & func) :
  max_ (func.max_),
  min_ (func.min_),
  positive_ (func.positive_),
  negative_ (func.negative_),
  elements_ (func.elements_),
  first_ (func.first_),
  sum_ (func.sum_),
  oddS_ (func.oddS_),
  evenS_ (func.evenS_),
  wasFirst_ (func.wasFirst_),
  isFirstEqualLast_ (func.isFirstEqualLast_),
  ostream_ (func.ostream_),
  isCopy_ (true)
{
}

Functor & Functor::operator=(const Functor & func)
{
  *this = Functor (func);
  return *this;
}

Functor::~Functor ()
{
  if (!isCopy_) {
    if (elements_ != 0) {
      *ostream_ << *this;
    } else {
      *ostream_ << "No Data\n";
    }
  }
}

void Functor::operator()(int x)
{
  if (x > max_) {
    max_ = x;
  }
  if (x < min_) {
    min_ = x;
  }
  if (x > 0) {
    positive_++;
  }
  if (x < 0) {
    negative_++;
  }

  sum_ += x;
  elements_++;

  if (x % 2 != 0) {
    oddS_ += x;
  } else {
    evenS_ += x;
  }

  if (wasFirst_) {
    if (x == first_) {
      isFirstEqualLast_ = true;
    } else {
      isFirstEqualLast_ = false;
    }
  } else {
    first_ = x;
    wasFirst_ = true;
  }
}



std::ostream & operator<<(std::ostream & ostream, Functor & func)
{
  if (!ostream) {
    throw std::ios_base::failure ("Stream Crash");
  }

  ostream << "Max: " << func.max_ << "\nMin: " << func.min_;

  double mean = static_cast<double>(func.sum_) / static_cast<double>(func.elements_);
  ostream << "\nMean: " << std::fixed << std::setprecision (1) << mean;
  ostream << "\nPositive: " << func.positive_ << "\nNegative: " << func.negative_;
  ostream << "\nOdd Sum: " << func.oddS_ << "\nEven Sum: " << func.evenS_;
  ostream << "\nFirst/Last Equal: ";
  if ((func.isFirstEqualLast_) || (func.elements_ == 1)) {
    ostream << "yes\n";
  } else {
    ostream << "no\n";
  }

  return ostream;
}


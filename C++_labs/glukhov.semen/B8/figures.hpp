#ifndef FIGURES_HPP
#define FIGURES_HPP

#include <ostream>

#include "newShape.hpp"

class newCircle : public newShape
{
public:
  newCircle(int x, int y) :
    newShape(x, y)
  {}

  void draw(std::ostream &ostream) const override
  {
    ostream << "CIRCLE " << '(' << x_ << "; " << y_ << ")\n";
  }
};


class Square : public newShape
{
public:
  Square(int x, int y) :
    newShape(x, y)
  {}

  void draw(std::ostream &ostream) const override
  {
    ostream << "SQUARE " << '(' << x_ << "; " << y_ << ")\n";
  }
};


class Triangle : public newShape
{
public:
  Triangle(int x, int y) :
    newShape(x, y)
  {}

  void draw(std::ostream &ostream) const override
  {
    ostream << "TRIANGLE " << '(' << x_ << "; " << y_ << ")\n";
  }
};


#endif // !FIGURES_HPP

#include "newShape.hpp"

newShape::newShape(int x, int y) :
  x_(x),
  y_(y)
{}

bool newShape::isMoreLeft(const newShape &shape) const
{
  return (x_ < shape.x_);
}

bool newShape::isUpper(const newShape &shape) const
{
  return (y_ > shape.y_);
}

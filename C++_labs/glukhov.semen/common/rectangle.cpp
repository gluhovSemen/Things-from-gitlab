#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h>

using namespace isaev;

Rectangle::Rectangle(const point_t &centre, double width, double height):
pos_(centre),
width_(width),
height_(height),
angle_(0.0)
{
  if (width < 0.0 || height < 0.0)
  {
    throw std::invalid_argument("Sides of rectangle can't be negative");
  }//line and point are rectangles too
}
point_t Rectangle::getPos() const
{
  return pos_;
}


double Rectangle::getArea() const
{
  return (width_ * height_);
}
rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}
void Rectangle::move(const point_t &point)
{
  pos_ = point;
}
void Rectangle::move(const double dx,const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Rectangle::scale(const double ratio)
{
  if(ratio < 0.0)
  {
    throw std::invalid_argument("Ratio can't be negative");
  }
  width_ *= ratio;
  height_ *= ratio;
}
void Rectangle::rotate(const double angle)
{
  angle_ += angle;
  if (angle_ >= 360)
  {
    angle_ = fmod(angle_, 360.0);
  }
}


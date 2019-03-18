#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdexcept>

Circle::Circle(const point_t &centre, double r):
pos_(centre),
rad_(r)
{
  if(r < 0.0)
  {
    throw std::invalid_argument("Radius can't be negative");
  } //point is circle too
}
double Circle::getArea() const
{
  return (rad_ * rad_ * M_PI);
}
rectangle_t Circle::getFrameRect() const
{
  return { rad_ * 2 , rad_ * 2, pos_ };
}
void Circle::move(const point_t &point)
{  
  pos_ = point;
}
void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Circle::printShapeInfo() const
{
  std::cout << "Circle info:\n";
  std::cout << "Centre: {" << pos_.x << "," << pos_.y << "}\n";
  std::cout << "Radius = " << rad_ << "\n";
}


#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iostream>

struct Point
{
  int x, y;
};

using Shape = std::vector<Point>;

std::istream & operator>>(std::istream &, Point & point);
std::ostream & operator<<(std::ostream &, const Point & point);
std::istream & operator>>(std::istream &, Shape & shape);
std::ostream & operator<<(std::ostream &, const Shape & shape);

double getDistance (const Point & pointA, const Point & pointB);
bool isSquare (const Shape & shape);

#endif //SHAPE_HPP


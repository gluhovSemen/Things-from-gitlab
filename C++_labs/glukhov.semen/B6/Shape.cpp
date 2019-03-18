#include "Shape.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <algorithm>
#include <iterator>

std::istream & operator>>(std::istream & istream, Point & point)
{
  std::string str = "";
  char symbol = 0;

  std::getline (istream, str, ')');
  if (str.empty ()) {
    return istream;
  }

  std::stringstream stream (str);
  
  stream >> symbol;
  if (symbol == 0) {
    return istream;
  }
  if (symbol != '(') {
    throw std::invalid_argument ("Invalid Data");
  }
  stream >> point.x >> symbol >> point.y;
  if (symbol != ';') {
    throw std::invalid_argument ("Invalid Data");
  }

  return istream;
}

std::ostream & operator<<(std::ostream & ostream, const Point & point)
{
  ostream << " (" << point.x << "; " << point.y << ")";
  return ostream;
}

std::istream & operator>>(std::istream & istream, Shape & shape)
{
  char symbol = 0;
  size_t size = 0;
  istream >> size >> std::noskipws >> symbol;

  if (symbol == '\n') {
    throw std::invalid_argument ("Invalid Data");
  }

  istream >> std::skipws;
  std::string str = "";
  std::getline (istream, str, '\n');

  if (str.empty ()) {
    return istream;
  }
  std::istringstream stream (str);

  std::vector<Point> tmp ((std::istream_iterator<Point> (stream)), std::istream_iterator<Point> ());
  shape.swap (tmp);
  shape.pop_back ();

  if ((size != shape.size ()) || (shape.size () < 3)) {
    throw std::invalid_argument ("Invalid Shape");
  }

  return istream;
}

std::ostream & operator<<(std::ostream & ostream, const Shape & shape)
{
  ostream << shape.size () << " ";
  std::copy (shape.begin (), shape.end (), std::ostream_iterator<Point> (ostream, " "));
  ostream << "\n";
  return ostream;
}

double getDistance (const Point & pointA, const Point & pointB)
{
  return ((pointA.x - pointB.x)*(pointA.x - pointB.x) + (pointA.y - pointB.y)*(pointA.y - pointB.y));
}

bool isSquare (const Shape & shape)
{
  if (getDistance (shape[0], shape[2]) == getDistance (shape[1], shape[3])) {
    if (getDistance (shape[0], shape[1]) != getDistance (shape[1], shape[2])) {
      return false;
    }
    if (getDistance (shape[1], shape[2]) != getDistance (shape[2], shape[3])) {
      return false;
    }
    if (getDistance (shape[2], shape[3]) != getDistance (shape[3], shape[0])) {
      return false;
    }
    if (getDistance (shape[0], shape[3]) != getDistance (shape[0], shape[1])) {
      return false;
    }
    return true;
  }
  return false;
}

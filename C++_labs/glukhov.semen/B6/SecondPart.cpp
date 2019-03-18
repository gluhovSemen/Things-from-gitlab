#include "Parts.hpp"

#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#include "Shape.hpp"

void doSecondPart (std::istream & istream, std::ostream & ostream)
{
  if (!istream) {
    throw std::ios_base::failure ("Stream Crash");
  }

  std::vector<Shape> shapes ((std::istream_iterator<Shape> (istream)), std::istream_iterator<Shape> ());

  int quantity_of_vertices = 0;
  int quantity_of_triangels = 0;
  int quantity_of_rectangels = 0;
  int quantity_of_squares = 0;

  shapes.erase (
    std::remove_if (shapes.begin (), shapes.end (), [&quantity_of_vertices](const Shape & shape) {
    quantity_of_vertices += shape.size ();
    return ((shape.size () == 5) || (shape.size () == 0));
  }), shapes.end ());
  
  std::vector<Point> points;

  std::for_each (shapes.begin (), shapes.end (), [&points, &quantity_of_triangels, &quantity_of_rectangels, &quantity_of_squares](const Shape & shape) {
    points.push_back (shape.front ());
    if (shape.size () == 3) {
      quantity_of_triangels++;
    }
    if (shape.size () == 4) {
      quantity_of_rectangels++;
      if (isSquare (shape)) {
        quantity_of_squares++;
      }
    }
  });

  std::sort (shapes.begin (), shapes.end (), [](const Shape & shape1, const Shape & shape2) {
    if (shape1.size () < shape2.size ()) {
      return true;
    } else {
      if ((shape1.size () == shape2.size ()) && (shape1.size () == 4)) {
        if (isSquare (shape1)) {
          if (isSquare (shape2)) {
            return shape1[0].x < shape2[0].x;
          } else {
            return true;
          }
        }
      }
      return false;
    }
  });

  ostream << "Vertices: " << quantity_of_vertices;
  ostream << "\nTriangles: " << quantity_of_triangels;
  ostream << "\nSquares: " << quantity_of_squares;
  ostream << "\nRectangles: " << quantity_of_rectangels;
  ostream << "\nPoints:";

  std::copy (points.begin (), points.end (), std::ostream_iterator<Point> (ostream));

  ostream << "\nShapes:\n";
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<Shape> (ostream));
}

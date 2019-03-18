#include <iostream>
#include "../common/circle.hpp"
#include "../common/rectangle.hpp"
#include "../common/base-types.hpp"

using namespace isaev;
using namespace std;
void printShapeInfo(const Shape & shape)
{
  cout << "Area = " << shape.getArea() << endl;
  rectangle_t rect = shape.getFrameRect();
  cout << "Frame rect: x = " << rect.pos.x << ", y = " << rect.pos.y
      << ", width = " << rect.width << ", height = " << rect.height << endl;
}
int main()
{
  point_t p = {0, 0};
  Rectangle rect(p, 5, 10);
  Shape *ptr = &rect;
  printShapeInfo(rect);
  std::cout << "Area is = " << ptr->getArea() << "\n";
  ptr->scale(3);
  std::cout << "After scaling to 3: " << "\n";
  printShapeInfo(rect);

  Circle cir(p ,3);
  ptr = &cir;
  printShapeInfo(cir);
  std::cout << "Area is = " << ptr->getArea() << "\n";
  ptr->scale(5);
  std::cout << "After scaling to 5 " << "\n";
  printShapeInfo(cir);

  return 0;
}

#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
   Rectangle rect({ 0,0 }, 5, 10);
   Shape *ptr = &rect;
   ptr->printShapeInfo();
   std::cout << "Area is = " << ptr->getArea() << "\n";
   ptr->move({ 3,3 });
   std::cout << "After moving to {3,3}: " << "\n";
   ptr->printShapeInfo();
   ptr->move(10, 10);
   std::cout << "After moving on dx=10, dy=10" << "\n";
   ptr->printShapeInfo();
   std::cout << "\n";

   Circle cir({ 0,0 }, 3);
   ptr = &cir;
   ptr->printShapeInfo();
   std::cout << "Area is = " << ptr->getArea() << "\n";
   ptr->move({ 15, 15 });
   std::cout << "After moving to {15,15}: " << "\n";
   ptr->printShapeInfo();
   ptr->move(22, 30);
   std::cout << "After moving on dx=22, dy=30" << "\n";
   ptr->printShapeInfo();
   std::cout << "\n";
    
  return 0;
}


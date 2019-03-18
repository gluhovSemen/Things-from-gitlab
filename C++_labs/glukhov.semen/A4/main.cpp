#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
using namespace isaev;
using namespace std;
int main()
{
  point_t p1 = { 4.0, 4.0 };
  point_t p2 = { 2.0, 2.0 };
  Rectangle rect(p1 , 1.0 , 1.0);
  Circle circle(p2, 1.0);

  CompositeShape comp_shape;
  CompositeShape::ptr_type rectPtr = make_shared<Rectangle>(rect);
  CompositeShape::ptr_type circPtr = make_shared<Circle>(circle);

  cout << "add rectangle" << endl;
  comp_shape.addShape(rectPtr);
  cout << "shape0 =" << comp_shape.size() << endl;
  cout << comp_shape.getFrameRect().pos.x << ' ' << comp_shape.getFrameRect().pos.y;

  cout << "add circle" << endl;
  comp_shape.addShape(circPtr);
  cout << "shape0 =" << comp_shape.size() << endl;

  cout << "Area of CompositeShape is = " << comp_shape.getArea() << endl;
  cout << "FrameRect of CompositeShape is:" << endl;
  cout << "X = " << comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y = " << comp_shape.getFrameRect().pos.y << endl;

  cout << "Width of CompositeShape = " << comp_shape.getFrameRect().width << endl;
  cout << "Height of CompositeShape = " << comp_shape.getFrameRect().height << endl;


  cout << "Scaling. Coef = 2" << endl;
  comp_shape.scale(2.0);
  cout << "New parameters of CompositeShape" << endl;
  cout << "New area of CompositeShape is = " << comp_shape.getArea() << endl;
  cout << "New width of CompositeShape = " << comp_shape.getFrameRect().width << endl;
  cout << "New height of CompositeShape = " << comp_shape.getFrameRect().height << endl;


  cout << "Moving to point (-3.0 ; -3.0)" << endl;

  cout << "X1 = " << comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y1 = " << comp_shape.getFrameRect().pos.y << endl;
  comp_shape.move({ -3.0, -3.0 });
  cout << "X1 = " << comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y1 = " << comp_shape.getFrameRect().pos.y << endl;


  cout << "Moving by dx = 3, dy = 3" << endl;
  comp_shape.move(3.0, 3.0);
  cout << circle.getFrameRect().pos.x << ' ' << circle.getFrameRect().pos.y << endl;
  cout << "X2 = " << comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y2 = " << comp_shape.getFrameRect().pos.y << endl;



  cout << "remove 1-st shape" << endl;
  comp_shape.removeShape(1);
  cout << "shape0 =" << comp_shape.size() << endl;

  cout << "" << endl;

  rectPtr->rotate(180);

  Rectangle rect2({ 5.0,6.0 } ,3.0, 4.0);
  CompositeShape::ptr_type rectPtr2 = make_shared<Rectangle>(rect2);
  Circle circle2({-2.0, -3.0}, 1.0);
  CompositeShape::ptr_type circPtr2 = make_shared<Circle>(circle2);

  Matrix matr;
  matr.addShape(rectPtr2);
  matr.addShape(circPtr2);
  cout<<matr.getNumber()<<endl;
  cout << matr.getSize() << endl;
  matr[0][0]->rotate(180.0);

  cout << matr[0][0]->getFrameRect().width<<" "<< matr[0][0]->getFrameRect().height << " "
            << matr[0][0]->getFrameRect().pos.x << " " << matr[0][0]->getFrameRect().pos.y << endl;

  Rectangle rect3({ 5.0,0.0 } , 5.0, 6.0 );
  CompositeShape::ptr_type rectPtr3 = make_shared<Rectangle>(rect3);
  Circle circle3({ -5.0, -2.0 }, 4.0);
  CompositeShape::ptr_type circPtr3 = make_shared<Circle>(circle3);

  CompositeShape comp1;
  comp1.addShape(rectPtr3);
  comp1.addShape(circPtr3);
  comp1.move({0.0,0.0});
  cout << rectPtr3->getFrameRect().width << " " << rectPtr3->getFrameRect().height << " "
            << rectPtr3->getFrameRect().pos.x << " " << rectPtr3->getFrameRect().pos.y << endl;
  cout << comp1.getFrameRect().width << " " << comp1.getFrameRect().height << " "
            << comp1.getFrameRect().pos.x << " " << comp1.getFrameRect().pos.y << endl;
  comp1.rotate(180);
  cout << rectPtr3->getFrameRect().width << " " << rectPtr3->getFrameRect().height << " "
            << rectPtr3->getFrameRect().pos.x << " " << rectPtr3->getFrameRect().pos.y << endl;
  cout << comp1.getFrameRect().width << " " << comp1.getFrameRect().height << " "
            << comp1.getFrameRect().pos.x << " " << comp1.getFrameRect().pos.y << endl;

  return 0;
}


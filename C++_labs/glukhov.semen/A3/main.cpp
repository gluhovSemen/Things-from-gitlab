#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using namespace isaev;
using namespace std;
int main()
{
  point_t p1 = {5.0, 5.0};
  point_t p2 = {10.0, 10.0};
  Rectangle rect(p1 , 3.0 , 4.0);
  Circle circle(p2, 1.0);

  isaev::CompositeShape comp_shape;
  CompositeShape::ptr_type rectPtr = make_shared<Rectangle>(rect);
  CompositeShape::ptr_type circPtr = make_shared<Circle>(circle);

  cout << "add rectangle" <<endl;
  comp_shape.addShape(rectPtr);
  cout <<"first shape ="<< comp_shape.size() << endl;
  cout << comp_shape.getFrameRect().pos.x << ' '<< comp_shape.getFrameRect().pos.y;

  cout << "add circle" <<endl;
  comp_shape.addShape(circPtr);
  cout <<"first shape ="<< comp_shape.size() << endl;


  cout << "Area of CompositeShape is = " << comp_shape.getArea() <<endl;
  cout << "FrameRect of CompositeShape is:" << endl;
  cout << "X = " <<comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y = " <<comp_shape.getFrameRect().pos.y <<endl;

  cout << "Width of CompositeShape = " <<comp_shape.getFrameRect().width<<endl;
  cout << "Height of CompositeShape = " <<comp_shape.getFrameRect().height<<endl;


  cout << "Scaling. K = 2" <<endl;
  comp_shape.scale(2.0);
  cout << "New parameters of CompositeShape" << endl;
  cout << "New area of CompositeShape is = " << comp_shape.getArea() << endl;
  cout << "New width of CompositeShape = " <<comp_shape.getFrameRect().width << endl;
  cout << "New height of CompositeShape = " <<comp_shape.getFrameRect().height << endl;


  cout << "Moving to point (-3.0 ; -3.0)" << endl;

  cout << "X1 = " <<comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y1 = " <<comp_shape.getFrameRect().pos.y << endl;
  comp_shape.move({-3.0, -3.0});
  cout << "X1 = " <<comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y1 = " <<comp_shape.getFrameRect().pos.y << endl;


  cout << "Moving by dx = 3, dy = 3" <<endl;
  comp_shape.move(3.0, 3.0);
  cout<<circle.getFrameRect().pos.x<< ' '<< circle.getFrameRect().pos.y<< endl;
  cout << "X2 = " <<comp_shape.getFrameRect().pos.x << ' ';
  cout << "Y2 = " <<comp_shape.getFrameRect().pos.y <<endl;



  cout << "remove 1-st shape" <<endl;
  comp_shape.removeShape(1);
  cout <<"shape0 ="<< comp_shape.size() << endl;

  cout << "" <<endl;

  return 0;
}

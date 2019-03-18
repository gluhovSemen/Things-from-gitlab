#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <math.h>
#include "shape.hpp"

namespace isaev
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &centre, double r);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t &point) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double ratio) override;
    point_t getCenter() const;
    double getRadius() const;
    void rotate(const double angle) override;
    point_t getPos() const override;
  private:
    point_t pos_;
    double rad_;
    double angle_;
  };
}
#endif


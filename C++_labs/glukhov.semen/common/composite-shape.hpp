#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace isaev
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape & rhs);//rhs - RightHand side
    CompositeShape(CompositeShape && rhs);
    using ptr_type = std::shared_ptr < Shape >;

    CompositeShape & operator =(const CompositeShape & rhs);
    CompositeShape & operator =(CompositeShape && rhs);// '&&' described higher
    
    size_t size() const;
    ptr_type operator[](size_t index) const;

    void addShape(const ptr_type & shape);
    void removeShape(const size_t index);
    

    virtual double getArea() const noexcept override;
    virtual rectangle_t getFrameRect() const noexcept override;
    virtual void move(const point_t & resPoint) noexcept override;
    virtual void move(const double dx, const double dy) noexcept override;
    virtual void scale(const double value) override;
    void rotate(const double angle) override;
    point_t getPos() const override ;
  private:
    size_t size_;
    std::unique_ptr<ptr_type []> shapes_;
    double angle_;
  };
}

#endif

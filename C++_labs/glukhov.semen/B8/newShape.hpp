#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class newShape // Shape declarated in /Common/
{
public:
  newShape(int, int);

  virtual ~newShape() = default;

  bool isMoreLeft(const newShape&) const;
  bool isUpper(const newShape&) const;

  virtual void draw(std::ostream&) const = 0;

protected:
  int x_, y_;
};

#endif // !SHAPE_HPP

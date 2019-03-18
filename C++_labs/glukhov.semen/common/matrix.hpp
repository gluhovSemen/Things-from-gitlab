#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>

#include "shape.hpp"

namespace isaev
{
  class Matrix
  {
    public:
      Matrix();
      Matrix(const Matrix & matrix);
      Matrix(Matrix && matrix);

      Matrix & operator=(const Matrix & matrix);
      Matrix & operator=(Matrix && matrix);
      bool operator==(const Matrix & rhs) const;
      bool operator!=(const Matrix & rhs) const;
      std::unique_ptr<std::shared_ptr<Shape>[]> operator[](const int index) const;

      void addShape(const std::shared_ptr<Shape> shape) noexcept;
      int getNumber();
      int getSize();

    private:
      std::unique_ptr<std::shared_ptr<Shape>[]> elements_;
      int layersNumber_;
      int layerSize_;

      bool checkOverlapping(const int index, std::shared_ptr<Shape> shape) const noexcept;
  };
}
#endif


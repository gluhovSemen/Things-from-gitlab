#include "matrix.hpp"

#include <memory>
#include <stdexcept>

using namespace isaev;

Matrix::Matrix():
  elements_(nullptr),
  layersNumber_(0),
  layerSize_(0)
{}

Matrix::Matrix(const Matrix & matrix):
  elements_(new std::shared_ptr<Shape>[matrix.layersNumber_ * matrix.layerSize_]),
  layersNumber_(matrix.layersNumber_),
  layerSize_(matrix.layerSize_)
{
  for (int i = 0; i < layersNumber_ * layerSize_; ++i)
  {
    elements_[i] = matrix.elements_[i];
  }
}

Matrix::Matrix(Matrix && matrix):
  elements_(nullptr),
  layersNumber_(matrix.layersNumber_),
  layerSize_(matrix.layerSize_)
{
  elements_.swap(matrix.elements_);
  matrix.layerSize_ = 0;
  matrix.layersNumber_ = 0;
}

Matrix & Matrix::operator=(const Matrix & matrix)
{
  if (this != & matrix)
  {
    std::unique_ptr<std::shared_ptr<Shape>[]> newElements(
      new std::shared_ptr<Shape>[matrix.layersNumber_ * matrix.layerSize_]);
    layersNumber_ = matrix.layersNumber_;
    layerSize_ = matrix.layerSize_;
    for (int i = 0; i < layersNumber_ * layerSize_; ++i)
    {
      newElements[i] = matrix.elements_[i];
    }
    elements_.swap(newElements);
  }
  return *this;
}

Matrix & Matrix::operator=(Matrix && matrix)
{
  if (this != & matrix)
  {
    layersNumber_ = matrix.layersNumber_;
    layerSize_ = matrix.layerSize_;
    elements_.reset();
    elements_.swap(matrix.elements_);
    matrix.layersNumber_ = 0;
    matrix.layerSize_ = 0;
  }
  return *this;
}

bool Matrix::operator==(const Matrix & rhs) const
{
  if ((layersNumber_ == rhs.layersNumber_) && (layerSize_ == rhs.layerSize_))
  {
    bool equality = true;
    for (int i = 0; i < layersNumber_ * layerSize_; ++i)
    {
      if (!(elements_[i] == rhs.elements_[i]))
      {
        equality = false;
      }
    }
    if (equality)
    {
      return true;
    }
  }
  return false;
}

bool Matrix::operator!=(const Matrix & rhs) const
{
  if ((layersNumber_ != rhs.layersNumber_) || (layerSize_ != rhs.layerSize_))
  {
    return true;
  }
  else
  {
    bool nonequality = false;
    for (int i = 0; i < layersNumber_ * layerSize_; ++i)
    {
      if (elements_[i] != rhs.elements_[i])
      {
        nonequality = true;
        break;
      }
    }
    if (nonequality)
    {
      return true;
    }
  }
  return false;
}


std::unique_ptr<std::shared_ptr<Shape>[]> Matrix::operator[](const int index) const
{
  if ((index < 0) || (index >= layersNumber_))
  {
    throw std::out_of_range("Invalid index");
  }
  std::unique_ptr<std::shared_ptr<Shape>[]> layer(new std::shared_ptr<Shape>[layerSize_]);
  for (int i = 0; i < layerSize_; ++i)
  {
    layer[i] = elements_[index * layerSize_ + i];
  }
  return layer;
}

void Matrix::addShape(const std::shared_ptr<Shape> shape) noexcept
{
  if (layersNumber_ == 0)
  {
    std::unique_ptr<std::shared_ptr<Shape>[]> newElements(new std::shared_ptr<Shape>[(layersNumber_ + 1) * (layerSize_ + 1)]);
    layerSize_++;
    layersNumber_++;
    elements_.swap(newElements);
    elements_[0] = shape;
  }
  else
  {
    bool addedShape = false;
    for (int i = 0; !addedShape ; ++i)
    {
      for (int j = 0; j < layerSize_; ++j)
      {
        if (!elements_[i * layerSize_ + j])
        {
          elements_[i * layerSize_ + j] = shape;
          addedShape = true;
          break;
        }
        else
        {
          if (checkOverlapping(i * layerSize_ + j, shape))
          {
            break;
          }
        }

        if (j == (layerSize_ - 1))
        {
          std::unique_ptr<std::shared_ptr<Shape>[]> newElements(
            new std::shared_ptr<Shape>[layersNumber_ * (layerSize_ + 1)]);
          layerSize_++;
          for (int n = 0; n < layersNumber_; ++n)
          {
            for (int m = 0; m < layerSize_ - 1; ++m)
            {
              newElements[n * layerSize_ + m] = elements_[n * (layerSize_ - 1) + m];
            }
            newElements[(n + 1) * layerSize_ - 1] = nullptr;
          }
          newElements[(i + 1) * layerSize_ - 1] = shape;
          elements_.swap(newElements);
          addedShape = true;
          break;
        }
      }
      if ((i == (layersNumber_ - 1)) && !addedShape)
      {
        std::unique_ptr<std::shared_ptr<Shape>[]> newElements(
          new std::shared_ptr<Shape>[(layersNumber_ + 1) * layerSize_]);
        layersNumber_++;
        for (int n = 0; n < ((layersNumber_ - 1) * layerSize_); ++n)
        {
          newElements[n] = elements_[n];
        }
        for (int n = ((layersNumber_ - 1) * layerSize_) ; n < (layersNumber_ * layerSize_); ++n)
        {
          newElements[n] = nullptr;
        }
        newElements[(layersNumber_ - 1) * layerSize_ ] = shape;
        elements_.swap(newElements);
        addedShape = true;
      }
    }
  }
}

bool Matrix::checkOverlapping(const int index, std::shared_ptr<Shape> shape) const noexcept
{
  rectangle_t nShapeFrameRect = shape->getFrameRect();
  rectangle_t mShapeFrameRect = elements_[index]->getFrameRect();
  point_t newPoints[4] = {
    {nShapeFrameRect.pos.x - nShapeFrameRect.width / 2.0, nShapeFrameRect.pos.y + nShapeFrameRect.height / 2.0},
    {nShapeFrameRect.pos.x + nShapeFrameRect.width / 2.0, nShapeFrameRect.pos.y + nShapeFrameRect.height / 2.0},
    {nShapeFrameRect.pos.x + nShapeFrameRect.width / 2.0, nShapeFrameRect.pos.y - nShapeFrameRect.height / 2.0},
    {nShapeFrameRect.pos.x - nShapeFrameRect.width / 2.0, nShapeFrameRect.pos.y - nShapeFrameRect.height / 2.0}
  };

  point_t matrixPoints[4] = {
    {mShapeFrameRect.pos.x - mShapeFrameRect.width / 2.0, mShapeFrameRect.pos.y + mShapeFrameRect.height / 2.0},
    {mShapeFrameRect.pos.x + mShapeFrameRect.width / 2.0, mShapeFrameRect.pos.y + mShapeFrameRect.height / 2.0},
    {mShapeFrameRect.pos.x + mShapeFrameRect.width / 2.0, mShapeFrameRect.pos.y - mShapeFrameRect.height / 2.0},
    {mShapeFrameRect.pos.x - mShapeFrameRect.width / 2.0, mShapeFrameRect.pos.y - mShapeFrameRect.height / 2.0}
  };

  for (int i = 0; i < 4; ++i)
  {
    if (((newPoints[i].x >= matrixPoints[0].x) && (newPoints[i].x <= matrixPoints[2].x)
      && (newPoints[i].y >= matrixPoints[3].y) && (newPoints[i].y <= matrixPoints[1].y))
        || ((matrixPoints[i].x >= newPoints[0].x) && (matrixPoints[i].x <= newPoints[2].x)
          && (matrixPoints[i].y >= newPoints[3].y) && (matrixPoints[i].y <= newPoints[1].y)))
    {
      return true;
    }
  }
  return false;
}

int Matrix::getNumber()
{
  return layersNumber_;
}

int Matrix::getSize()
{
  return layerSize_;
}


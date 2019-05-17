#include "plusminus.h"

#include "plusminusexercise.h"

namespace mathex
{

PlusMinus::PlusMinus() :
  rand_(1, 10), count_(0)
{
}

PlusMinus::~PlusMinus()
{
}

void PlusMinus::generate_numbers()
{
  left_ = rand_.next_int();
  right_ = rand_.next_int();
  sum_ = left_ + right_;
}

std::unique_ptr<xgen::Exercise> PlusMinus::generate()
{
  int left;
  int right;
  switch ((++count_) % 3)
  {
    case 0:
      left = sum_;
      right = left_ * -1;
      break;
    case 1:
      generate_numbers();
      left = left_;
      right = right_;
      break;
    case 2:
      left = sum_;
      right = right_ * -1;
      break;
  }
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(right);
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


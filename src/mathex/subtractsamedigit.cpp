#include "subtractsamedigit.h"
#include "plusminusexercise.h"

namespace mathex
{

SubtractSameDigit::SubtractSameDigit(unsigned int right) :
  right_(right), rand_(right_, 19)
{
  right_ *= -1;
}

SubtractSameDigit::~SubtractSameDigit()
{
}

std::unique_ptr<xgen::Exercise> SubtractSameDigit::generate()
{
  int left(rand_.next_int());
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(right_);
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


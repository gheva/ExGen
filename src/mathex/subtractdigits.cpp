#include "subtractdigits.h"
#include "plusminusexercise.h"

namespace mathex
{

SubtractDigits::SubtractDigits() :
  rand_(1, 10)
{
}

SubtractDigits::~SubtractDigits()
{
}

std::unique_ptr<xgen::Exercise> SubtractDigits::generate()
{
  int left(rand_.next_int());
  RandNum r(0, left);
  int right(r.next_int());
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(-1 * right);
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


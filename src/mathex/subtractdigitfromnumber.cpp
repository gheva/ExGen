#include "subtractdigitfromnumber.h"
#include "plusminusexercise.h"

namespace mathex
{

SubtractDigitFromNumber::SubtractDigitFromNumber(int version) :
  rand_(1, 20), version_(version)
{
}

SubtractDigitFromNumber::~SubtractDigitFromNumber()
{
}

std::unique_ptr<xgen::Exercise> SubtractDigitFromNumber::generate()
{
  int left(rand_.next_int());
  RandNum r(1, left > 10 ? 10 : left);
  int right(r.next_int());
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise(version_));
  e->reset(left);
  e->add(-1 * right);
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


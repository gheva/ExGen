#include "carrying2digits.h"

namespace mathex
{

Carrying2Digits::Carrying2Digits(int level) :
  rand_(1, 9), should_not_carry_(0, 3)
{
  int top(3);
  switch (level)
  {
  case (1):
    top = 5;
    break;
  case (2):
    top = 4;
    break;
  case (3):
    top = 3;
    break;
  case (100):
    break;
  }
  should_not_carry_.reset_range(0, top);
}

Carrying2Digits::~Carrying2Digits()
{
}

void Carrying2Digits::level_100(PlusMinusExercise* ex)
{
  //rand_.reset_range(11, 99);
  ex->reset(rand_.next_int());
  ex->add(rand_.next_int());
}

void Carrying2Digits::next_digit(int& l, int& r)
{
  l = rand_.next_int();
  int top(should_not_carry_.next_int() && l < 8 ? 9 - l : 9);
  RandNum tmp(1, top);
  r = tmp.next_int();
}

void Carrying2Digits::level_1(PlusMinusExercise* ex)
{
  //rand_.reset_range(1, 9);
  int l(0), r(0), left(0), right(0);
  next_digit(left, right);
  next_digit(l, r);
  left += l * 10;
  right += r * 10;

  ex->reset(left);
  ex->add(right);
}

std::unique_ptr<xgen::Exercise> Carrying2Digits::generate()
{
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise(PlusMinusExercise::TWO_LEVEL_EXERCISE));
  level_1(e.get());
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


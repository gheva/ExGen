#include "longplusminus.h"
#include "plusminusexercise.h"

namespace mathex
{

LongPlusMinus::LongPlusMinus() :
  rand_(0, 9)
{
}

LongPlusMinus::~LongPlusMinus()
{
}

void LongPlusMinus::next_digit(int& l, int& r, bool first)
{
  l = rand_.next_int();
  if (first)
  {
    while (l == 0)
    {
      l = rand_.next_int();
    }
  }
  int top(plus_ ? 9 - l : l);
  RandNum tmp(0, top);
  r = tmp.next_int();
}

std::unique_ptr<xgen::Exercise> LongPlusMinus::generate()
{
  plus_ = !plus_;
  unsigned long long left(0), right(0);
  int l(0), r(0);
  next_digit(l, r, true);
  left = l;
  right = r;
  for (int i = 0; i < 9; ++i)
  {
    next_digit(l, r);
    left *= 10;
    right *= 10;
    left += l;
    right += r;
  }
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise(PlusMinusExercise::LONG_ADD_SUBTRACT));
  e->reset(left);
  if (plus_)
    e->add(right);
  else
    e->subtract(right);
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


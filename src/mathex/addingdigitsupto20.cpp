#include "addingdigitsupto20.h"
#include "plusminusexercise.h"

namespace mathex
{
int AddingDigitsUpTo20::above(1);
int AddingDigitsUpTo20::below(1);

AddingDigitsUpTo20::AddingDigitsUpTo20(bool force_carry) :
  rand_(0, 10), force_carry(force_carry)
{
}

AddingDigitsUpTo20::~AddingDigitsUpTo20()
{
}

std::unique_ptr<xgen::Exercise> AddingDigitsUpTo20::generate()
{
  int left(next_int());
  int right(next_int());
  if (left + right >= 10)
  {
    ++above;
  }
  else
  {
    if (below > above && force_carry)
    {
      return generate();
    }
    ++below;
  }

  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(right);
  return std::move(e);
}

int AddingDigitsUpTo20::next_int()
{
  return rand_.next_int();
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#include "addingdigitsupto10.h"
#include "plusminusexercise.h"

namespace mathex
{

AddingDigitsUpTo10::AddingDigitsUpTo10() :
  rand_(0, 9)
{
}

AddingDigitsUpTo10::~AddingDigitsUpTo10()
{
}

std::unique_ptr<xgen::Exercise> AddingDigitsUpTo10::generate()
{
  int left(next_int());
  int right(next_int());
  while (left + right >= 10)
  {
    right = next_int();
  }
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(right);
  return std::move(e);
}

int AddingDigitsUpTo10::next_int()
{
  return rand_.next_int();
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#include "addingabove10.h"
#include "plusminusexercise.h"

namespace mathex
{

AddingAbove10::AddingAbove10() :
  rand_(1, 10)
{
}

AddingAbove10::~AddingAbove10()
{
}

std::unique_ptr<xgen::Exercise> AddingAbove10::generate()
{
  int left(next_int());
  RandNum r(10 - left, 10);
  int right(r.next_int());

  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise());
  e->reset(left);
  e->add(right);
  return std::move(e);
}

int AddingAbove10::next_int()
{
  return rand_.next_int();
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


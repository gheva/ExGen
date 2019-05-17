#include "plustomul.h"
#include "plusminusexercise.h"
#include "randnum.h"

namespace mathex
{

PlusToMul::PlusToMul() : count_(0), digit_(7)
{
  RandNum rand(3, 9);
  digit_ = rand.next_int();
}

PlusToMul::~PlusToMul()
{
}

std::unique_ptr<xgen::Exercise> PlusToMul::generate()
{
  unsigned int top(digit_ * count_);
  ++count_;
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise(PlusMinusExercise::PLUS_TO_MUL));
  if (count_ == 1)
  {
    e->set_version(PlusMinusExercise::TWO_LEVEL_EXERCISE);
  }
  e->reset(top);
  e->add(digit_);
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


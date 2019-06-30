#include "multiplyby.h"
#include "mulexercise.h"

namespace mathex
{

MultiplyBy::MultiplyBy(unsigned int left, bool mixit, unsigned int limit) :
  left_(left), mixit_(mixit), rand_(1, limit), should_mix_(0, 1)
{
}

MultiplyBy::~MultiplyBy()
{
}

void MultiplyBy::set_left(unsigned int left)
{
  left_ = left;
}

std::unique_ptr<xgen::Exercise> MultiplyBy::generate()
{
  unsigned int right(rand_.next_int());
  unsigned int left(left_);
  std::unique_ptr<MulExercise> e(new MulExercise(MulExercise::MUL_LEVEL_ONE_DIGIT));
  if (mixit_ && should_mix_.next_int() == 1)
  {
    left = right;
    right = left_;
  }
  e->reset(left);
  e->mul(right);
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


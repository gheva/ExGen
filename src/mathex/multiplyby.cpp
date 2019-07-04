#include "multiplyby.h"
#include "mulexercise.h"

namespace mathex
{

static std::vector<unsigned int> unused;
MultiplyBy::MultiplyBy(unsigned int left, bool mixit, unsigned int limit) :
  left_(left), mixit_(mixit), rand_(1, limit), should_mix_(0, 1), lefts_(unused)
{
}

MultiplyBy::MultiplyBy(std::vector<unsigned int>& known) :
  left_(-1), mixit_(true), rand_(1, 9), should_mix_(0, 1), lefts_(known)
{
}

MultiplyBy::~MultiplyBy()
{
}

void MultiplyBy::set_left(unsigned int left)
{
  left_ = left;
}

unsigned int MultiplyBy::get_left()
{
  if (static_cast<int>(left_) != -1)
  {
    return left_;
  }
  int length = lefts_.size();
  if (length == 0)
  {
    return 2;
  }
  RandNum selector(0, length - 1);
  return lefts_[selector.next_int()];
}

std::unique_ptr<xgen::Exercise> MultiplyBy::generate()
{
  unsigned int right(rand_.next_int());
  unsigned int left(get_left());
  std::unique_ptr<MulExercise> e(new MulExercise(MulExercise::MUL_LEVEL_ONE_DIGIT));
  if (mixit_ && should_mix_.next_int() == 1)
  {
    std::swap(left, right);
  }
  e->reset(left);
  e->mul(right);
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


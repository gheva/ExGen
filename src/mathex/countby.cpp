#include "countby.h"

#include "mulexercise.h"

namespace mathex
{

int CountBy::by_[] = {0, 1, 10, 2, 5, 9, 4, 3, 6, 8, 7};

CountBy::CountBy(int digit) : count_(0), digit_(digit)
{
}

CountBy::~CountBy()
{
}

std::unique_ptr<xgen::Exercise> CountBy::generate()
{
  if (count_ > 10)
    return nullptr;
  std::unique_ptr<MulExercise> e(new MulExercise(MulExercise::MUL_LEVEL_COUNT_BY));
  if (digit_ >= 0)
  {
    e->reset(digit_);
  }
  else
  {
    e->reset(by_[count_++]);
  }
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


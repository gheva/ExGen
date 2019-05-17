#include "carryborrow.h"
#include "plusminusexercise.h"

namespace mathex
{

CarryBorrow::CarryBorrow(int carry, int borrow, int digits) :
  carry_(carry), borrow_(borrow), digits_(digits), carried_(0), borrowed_(0),
  rand_(1, 9), plus_minus_(true)
{
}

CarryBorrow::~CarryBorrow()
{
}

int CarryBorrow::flip_number(int number)
{
  int ret(0);
  while (number > 0)
  {
    ret *= 10;
    ret += number % 10;
    number /= 10;
  }
  return ret;
}

void CarryBorrow::evaluate(int prev, int num)
{
  if (!prev)
  {
    return;
  }
  if (plus_minus_)
  {
    int tmp = prev + num;
    int d(0);
    while (tmp)
    {
      ++d;
      tmp /= 10;
    }
    if (d > digits_)
    {
      ++carried_;
    }
  }
  else
  {
    for (int i = 0; i < digits_; ++i)
    {
      int l, r;
      l = prev % 10;
      r = num % 10;
      if (l < r)
      {
        ++borrowed_;
        return;
      }
      prev /= 10;
      num /= 10;
    }
  }
}

int CarryBorrow::next_number(int prev)
{
  int ret(0);
  if (!prev || (plus_minus_ && carried_ < carry_))
  {
    for (int i = 0; i < digits_; ++i)
    {
      ret *= 10;
      ret += rand_.next_int();
    }
    evaluate(prev, ret);
  }
  else if (plus_minus_)
  {
    while (prev)
    {
      ret *= 10;
      int dig = prev % 10;
      dig = 10 - dig;
      ret += rand_.next_smaller_than(dig);
      prev /= 10;
    }
  }
  else
  {
    int tmp = flip_number(prev);
    bool first(true);
    while (tmp)
    {
      int dig = tmp % 10;
      int n;
      ret *= 10;
      if (first || borrowed_ >= borrow_)
      {
        n = rand_.next_smaller_than(dig > 1 ? dig - 1 : dig);
        first = false;
      }
      else
      {
        n = rand_.next_int();
      }

      ret += n;
      
      tmp /= 10;
    }

    evaluate(prev, ret);
  }

  return ret;
}

std::unique_ptr<xgen::Exercise> CarryBorrow::generate()
{
  std::unique_ptr<PlusMinusExercise> e(new PlusMinusExercise(PlusMinusExercise::TWO_LEVEL_EXERCISE));

  int l = next_number(0);
  e->reset(l);
  e->add((plus_minus_ ? 1 : -1) * next_number(l));
  plus_minus_ = !plus_minus_;
  return std::move(e);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


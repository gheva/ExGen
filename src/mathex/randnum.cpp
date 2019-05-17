#include "randnum.h"

namespace mathex
{

RandNum::RandNum(int from, int to) :
  gen_(rd_()), dis_(from, to), from_(from), to_(to)
{
}

int RandNum::next_int()
{
  return dis_(gen_);
}

void RandNum::reset_range(int from, int to)
{
  dis_ = std::uniform_int_distribution<>(from, to);
}

int RandNum::next_bigger_than(int n)
{
  return std::uniform_int_distribution<>(n, to_)(gen_);
}

int RandNum::next_smaller_than(int n)
{
  if (n <= from_)
    return from_;
  return std::uniform_int_distribution<>(from_, n)(gen_);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#ifndef MATHEX_RANDNUM_H__
#define MATHEX_RANDNUM_H__

#include <random>

namespace mathex
{

class RandNum
{
public:
  RandNum(int from, int to);
  int next_int();
  void reset_range(int from, int to);
  int next_bigger_than(int n);
  int next_smaller_than(int n);
protected:
private:
  std::random_device rd_;
  std::mt19937 gen_;
  std::uniform_int_distribution<> dis_;
  int from_;
  int to_;
};

} // namespace

#endif // MATHEX_RANDNUM_H__

/* vim: set cindent sw=2 expandtab : */


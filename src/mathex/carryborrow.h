#ifndef MATHEX_CARRYBORROW_H__
#define MATHEX_CARRYBORROW_H__

#include "level.h"
#include "randnum.h"

namespace mathex
{

class CarryBorrow : public xgen::Level
{
public:
  CarryBorrow(int carry, int borrow, int digits);
  virtual ~CarryBorrow();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  int next_number(int prev);
  int flip_number(int num);
  void evaluate(int prev, int num);
  int digits_;
  int carry_;
  int borrow_;
  int carried_;
  int borrowed_;
  RandNum rand_;
  bool plus_minus_;
};

} // namespace

#endif // MATHEX_CARRYBORROW_H__

/* vim: set cindent sw=2 expandtab : */


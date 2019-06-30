#include "multiplication.h"
#include "countby.h"
#include "multable.h"
#include "multiplyby.h"
#include "digitbydigit.h"

namespace mathex
{

Multiplication::Multiplication() :
  Topic("Multiplication")
{
  add_level(new CountBy);
  add_level(new MulTable);
  add_level(new MultiplyBy(2, true));
  add_level(new MultiplyBy(5, true));
  add_level(new MultiplyBy(4, true));
  add_level(new MultiplyBy(3, true));
  add_level(new MultiplyBy(6, true, 5));
  add_level(new MultiplyBy(7, true, 5));
  add_level(new MultiplyBy(8, true, 5));
  add_level(new MultiplyBy(9, true, 5));
  add_level(new DigitByDigit());
}

Multiplication::~Multiplication()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


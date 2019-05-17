#include "arithmetic.h"
#include "carrying2digits.h"
#include "carryborrow.h"
#include "plustomul.h"
#include <iostream>

namespace mathex
{

Arithmetic::Arithmetic() :
  Topic("Arithmetic")
{
  add_level(new Carrying2Digits(1));
  add_level(new CarryBorrow(10, 1, 2));
  add_level(new CarryBorrow(10, 2, 2));
  add_level(new CarryBorrow(10, 4, 2));
  add_level(new PlusToMul());
}

Arithmetic::~Arithmetic()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


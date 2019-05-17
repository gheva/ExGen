#include "multiplication.h"
#include "countby.h"
#include "multable.h"

namespace mathex
{

Multiplication::Multiplication() :
  Topic("Multiplication")
{
  add_level(new CountBy);
  add_level(new MulTable);
}

Multiplication::~Multiplication()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#include "addition.h"
#include "addingdigitsupto10.h"
#include "addingdigitsupto20.h"
#include "addingabove10.h"
#include "carrying2digits.h"

namespace mathex
{

Addition::Addition() :
  Topic("Addition")
{
  add_level(new AddingDigitsUpTo10);
  add_level(new AddingDigitsUpTo20);
  add_level(new AddingDigitsUpTo20(true));
  add_level(new AddingAbove10);
  add_level(new Carrying2Digits(1));
}

Addition::~Addition()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


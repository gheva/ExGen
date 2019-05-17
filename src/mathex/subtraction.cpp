#include "subtraction.h"
#include "plusminus.h"
#include "plusminusexercise.h"
#include "subtractdigits.h"
#include "subtractdigitfromnumber.h"
#include "subtractsamedigit.h"
#include "longplusminus.h"

namespace mathex
{

Subtraction::Subtraction() :
  Topic("Subtraction")
{
  add_level(new PlusMinus);
  add_level(new SubtractDigits);
  add_level(new SubtractDigitFromNumber);
  add_level(new SubtractSameDigit(9));
  add_level(new SubtractSameDigit(8));
  add_level(new SubtractSameDigit(7));
  add_level(new SubtractSameDigit(6));
  add_level(new SubtractDigitFromNumber(PlusMinusExercise::TWO_LEVEL_EXERCISE));
  add_level(new LongPlusMinus());
}

Subtraction::~Subtraction()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


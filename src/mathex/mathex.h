#ifndef EXGEN_MATHEX_H__
#define EXGEN_MATHEX_H__

/**
  \defgroup mathex Math exercises
  \brief This module produces math exercises

  ## Topics
  The exercises are divided into several topics starting with simple addition exercises and building up from there.

  ## Indexing
  The exercises are 0 indexed (yup, a programmer wrote this....), so subtract 1 from the level number here, consider this some exercise for you ;-)

  ### Addition
  This topic produces fairly simple addition exercises, from simple addition of two digits, summing up to less than 10, to addition of any 2 numbers.
  #### Levels
  1. Adding 2 digits that sum up to less than 10
  2. Adding 2 digits that can go above 10
  3. Adding digits that can go above 10, ensuring that at least half the exercises do
  4. Adding digits that will always add up to more than 10
  5. Adding 2 digit numbers, with some of the exercises generating a carry. This is the first level that produces exercises marked for being displayed as 2 level.

  ### Subtraction
  This topic produces exercises for subtraction.
  #### Levels
  1. Demonstrates the correlation between an addition and subtraction
  2. Subtract one digit from another
  3. Subtract a digit from a number up to 20
  4. Levels 4 - 7 are exercises of subtracting the same digit from a number. level 4 - Subtract 9 from numbers up to 20
  5. Subtract 8 from numbers up to 20
  6. Subtract 7 from numbers up to 20
  7. Subtract 6 from numbers up to 20
  8. Subtract a digit fro a number, but this is marked to be displayed as a 2 level exercise
  9. A very long number addition and subtraction

  */

enum math_exercise_ids
{
  EXERCISE_ID_PLUS_MINUS = MATH_EXERCISE_IDS_FIRST,
  EXERCISE_ID_MULTIPLICATION,
};

#include "mathex/addition.h"
#include "mathex/subtraction.h"
#include "mathex/arithmetic.h"
#include "mathex/multiplication.h"

#endif // EXGEN_MATHEX_H__

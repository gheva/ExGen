#ifndef MATHEX_CARRYING2DIGITS_H__
#define MATHEX_CARRYING2DIGITS_H__

#include "level.h"
#include "randnum.h"
#include "plusminusexercise.h"

namespace mathex
{

/**
  \class Carrying2Digits carrying2digits.h "mathext/carrying2digits.h"
  \ingroup mathex
  \brief Generates exercises of adding 2 digit numbers allowing for carry operations
  */
class Carrying2Digits : public xgen::Level
{
public:
  /**
    \brief Constructs a level with the given level

    The difference between the levels is the probability of the exercise to have a carry:
    1. Chances of carry are 1:5
    2. Chances of carry are 1:4
    3. Chances of carry are 1:3

    By default, Chances of carry are 1:3
    */
  Carrying2Digits(int level);
  virtual ~Carrying2Digits();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  void next_digit(int& l, int& r);
  void level_1(PlusMinusExercise* ex);
  void level_100(PlusMinusExercise* ex);
  RandNum rand_;
  RandNum should_not_carry_;
};

} // namespace

#endif // MATHEX_CARRYING2DIGITS_H__

/* vim: set cindent sw=2 expandtab : */


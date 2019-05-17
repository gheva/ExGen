#ifndef MATHEX_PLUSMINUSEXERCISE_H__
#define MATHEX_PLUSMINUSEXERCISE_H__

#include <vector>
#include "mathexercise.h"

namespace mathex
{

/**
  \class PlusMinusExercise plusminusexercise.h "mathex/plusminusexercise.h"
  \ingroup mathex
  \brief Represents an addition or subtraction exercise

  The operands are stored in a vector of signed integers, and the operator is derived based on the sign of the right hand operand.
  */
class PlusMinusExercise : public MathExercise
{
public:
  enum versions
  {
    EX_VERSION_0 = 0,
    TWO_LEVEL_EXERCISE,
    LONG_ADD_SUBTRACT,
    PLUS_TO_MUL,
  };

  /**
    */
  PlusMinusExercise(unsigned int version = 0);
  virtual ~PlusMinusExercise();
  void reset(unsigned long long first);
  void add(unsigned long long operand);
  void subtract(unsigned long long operand);

  unsigned long long operator[](unsigned int index) const;
  // returns the operator between index - 1 and index, true = +, false = -
  bool op(unsigned int index) const;
  unsigned int size() const;
  unsigned int version() const;
  void set_version(versions v)
  {
    version_ = v;
  }

private:
  std::vector<long long> operands_;
  unsigned int version_;
};

} // namespace

#endif // MATHEX_PLUSMINUSEXERCISE_H__

/* vim: set cindent sw=2 expandtab : */


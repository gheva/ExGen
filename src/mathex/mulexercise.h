#ifndef MATHEX_MULEXERCISE_H__
#define MATHEX_MULEXERCISE_H__

#include "mathexercise.h"
#include <vector>

namespace mathex
{

class MulExercise : public MathExercise
{
public:
  enum MulLevels
  {
    MUL_LEVEL_COUNT_BY,
    MUL_LEVEL_MUL_TABLE,
    MUL_LEVEL_ONE_DIGIT,
  };
  MulExercise(MulLevels level);
  virtual ~MulExercise();
  void reset(unsigned long long first);
  void mul(unsigned long long operand);
  void div(unsigned long long operand);

  unsigned long long operator[](unsigned int index) const;
  // returns the operator between index - 1 and index, true = +, false = -
  bool op(unsigned int index) const;
  unsigned int size() const;
  unsigned int version() const;
protected:
private:
  std::vector<unsigned long long> operands_;
  std::vector<bool> operators_;
  MulLevels version_;
};

} // namespace

#endif // MATHEX_MULEXERCISE_H__

/* vim: set cindent sw=2 expandtab : */


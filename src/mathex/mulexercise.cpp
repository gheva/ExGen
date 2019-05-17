#include "mulexercise.h"
#include "mathex.h"

namespace mathex
{

MulExercise::MulExercise(MulLevels version) :
  MathExercise(EXERCISE_ID_MULTIPLICATION), version_(version)
{
}

MulExercise::~MulExercise()
{
}

void MulExercise::reset(unsigned long long first)
{
  operands_.clear();
  operators_.clear();
  operands_.push_back(first);
}

void MulExercise::mul(unsigned long long operand)
{
  operators_.push_back(true);
  operands_.push_back(operand);
}

void MulExercise::div(unsigned long long operand)
{
  operators_.push_back(false);
  operands_.push_back(operand);
}

unsigned long long MulExercise::operator[](unsigned int index) const
{
  return operands_[index];
}

bool MulExercise::op(unsigned int index) const
{
  return operators_[index];
}

unsigned int MulExercise::size() const
{
  return operators_.size();
}

unsigned int MulExercise::version() const
{
  return version_;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


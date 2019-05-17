#include "plusminusexercise.h"
#include <cmath>
#include "mathex.h"

namespace mathex
{

PlusMinusExercise::PlusMinusExercise(unsigned int version) :
  MathExercise(EXERCISE_ID_PLUS_MINUS), version_(version)
{
}

PlusMinusExercise::~PlusMinusExercise()
{
}

void PlusMinusExercise::reset(unsigned long long first)
{
  operands_.clear();
  operands_.push_back(first);
}

void PlusMinusExercise::add(unsigned long long operand)
{
  operands_.push_back(operand);
}

void PlusMinusExercise::subtract(unsigned long long operand)
{
  operands_.push_back(-1 * operand);
}

unsigned long long PlusMinusExercise::operator[](unsigned int index) const
{
  return abs(operands_[index]);
}

bool PlusMinusExercise::op(unsigned int index) const
{
  return operands_[index] >= 0;
}

unsigned int PlusMinusExercise::size() const
{
  return operands_.size();
}

unsigned int PlusMinusExercise::version() const
{
  return version_;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#ifndef MATHEX_MATHEXERCISE_H__
#define MATHEX_MATHEXERCISE_H__

#include "exercise.h"

namespace mathex
{

/**
  \class MathExercise mathexercise.h "mathex/mathexercise.h"
  \ingroup mathex
  \brief Represent a math exercise

  The math exercise consists of a list of operands and operators, accessible by their index.
  */
class MathExercise : public xgen::Exercise
{
public:
  /**
    \brief Constructs a math exercise
    \param id - The id for this exercise
    */
  MathExercise(int id);
  virtual ~MathExercise();

  /**
    \brief Returns the operand at the given index
    \param index - The index of the requested operand
    \return Returns the operand at the given index
    */
  virtual unsigned long long operator[](unsigned int index) const = 0;
  // returns the operator between index - 1 and index, true = +, false = -
  /**
    \brief Returns the operator before the operand at the given index
    \param index - The index to the left hand operator before operand at the given index
    \return Returns the operator before the operand at the given index
    */
  virtual bool op(unsigned int index) const = 0;
  /**
    \brief Returns the number of operands in this exercise
    */
  virtual unsigned int size() const = 0;

  /**
    \brief Returns the version of this exercise

    Different exercises versions will be displayed differently based on their version.
    */
  virtual unsigned int version() const = 0;
protected:
private:
};

} // namespace

#endif // MATHEX_MATHEXERCISE_H__

/* vim: set cindent sw=2 expandtab : */


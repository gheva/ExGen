#ifndef MATHEX_SUBTRACTDIGITFROMNUMBER_H__
#define MATHEX_SUBTRACTDIGITFROMNUMBER_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  \class SubtractDigitFromNumber subtractdigitfromnumber.h "mathex/subtractdigitfromnumber.h"
  \ingroup mathex
  \brief Generates exercises of subtraction of a digit from a number up to 20
  */
class SubtractDigitFromNumber : public xgen::Level
{
public:
  /**
    \param version - The display version (e.g TWO_LEVEL_EXERCISE)
    */
  SubtractDigitFromNumber(int version=0);
  virtual ~SubtractDigitFromNumber();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  RandNum rand_;
  int version_;
};

} // namespace

#endif // MATHEX_SUBTRACTDIGITFROMNUMBER_H__

/* vim: set cindent sw=2 expandtab : */


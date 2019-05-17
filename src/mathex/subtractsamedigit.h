#ifndef MATHEX_SUBTRACTSAMEDIGIT_H__
#define MATHEX_SUBTRACTSAMEDIGIT_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  \class SubtractSameDigit subtractsamedigit.h "mathex/subtractsamedigit.h"
  \ingroup mathex
  \brief Gerenrates exercises of subtracting the same digit from numbers up to 20
  */
class SubtractSameDigit : public xgen::Level
{
public:
  /**
    \param right - The digit to be subtracted
    */
  SubtractSameDigit(unsigned int right);
  virtual ~SubtractSameDigit();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  unsigned int right_;
  RandNum rand_;
};

} // namespace

#endif // MATHEX_SUBTRACTSAMEDIGIT_H__

/* vim: set cindent sw=2 expandtab : */


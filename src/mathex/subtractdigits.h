#ifndef MATHEX_SUBTRACTDIGITS_H__
#define MATHEX_SUBTRACTDIGITS_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  \class SubtractDigits subtractdigits.h "mathex/subtractdigits.h"
  \ingroup mathex
  \brief Generates exercises of subtracting one digit from another
  */
class SubtractDigits : public xgen::Level
{
public:
  SubtractDigits();
  virtual ~SubtractDigits();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  RandNum rand_;
};

} // namespace

#endif // MATHEX_SUBTRACTDIGITS_H__

/* vim: set cindent sw=2 expandtab : */


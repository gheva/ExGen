#ifndef MATHEX_DIGITBYDIGIT_H__
#define MATHEX_DIGITBYDIGIT_H__

#include "multiplyby.h"

namespace mathex
{

/**
  \class DigitByDigit digitbydigit.h "mathex/digitbydigit.h"
  \ingroup mathex
  \brief Generates exercises of multiplying a one random digit by another
  */
class DigitByDigit : public xgen::Level
{
public:
  DigitByDigit();
  virtual ~DigitByDigit();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate() override;
private:
  RandNum rand_;
  MultiplyBy generator_;
};

} // namespace

#endif // MATHEX_DIGITBYDIGIT_H__

/* vim: set cindent sw=2 expandtab : */


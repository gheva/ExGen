#ifndef MATHEX_PLUSMINUS_H__
#define MATHEX_PLUSMINUS_H__

#include "level.h"
#include "randnum.h"

namespace mathex
{

/**
  \class PlusMinus plusminus.h "mathex/plusminus.h"
  \ingroup mathex
  \brief Generates an exercise with an addition followed by the same digits in different configurationd to show the corresponding subtractions.

  For example:
  1 + 2 = _ | 3 - 1 = _ | 3 - 2 = _ 
  */
class PlusMinus : public xgen::Level
{
public:
  PlusMinus();
  virtual ~PlusMinus();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  void generate_numbers();
  RandNum rand_;
  int left_;
  int right_;
  int sum_;
  int count_;
};

} // namespace

#endif // MATHEX_PLUSMINUS_H__

/* vim: set cindent sw=2 expandtab : */


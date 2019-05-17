#ifndef MATHEX_ADDINGDIGITSUPTO20_H__
#define MATHEX_ADDINGDIGITSUPTO20_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  class AddingDigitsUpTo20 addingdigitsupto20.h "mathex/addingdigitsupto20.h"
  \ingroup mathex
  \brief Generates exercises for adding digits which can sum up to more than 10
  */
class AddingDigitsUpTo20 : public xgen::Level
{
public:
  /**
    \brief Constructs this level
    \param force_carry - If set to true, exercises will be generatd so that about half of them will have sum up to more than 10
    */
  AddingDigitsUpTo20(bool force_carry=false);
  virtual ~AddingDigitsUpTo20();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  RandNum rand_;
  int next_int();
  static int above;
  static int below;
  bool force_carry;
};

} // namespace

#endif // MATHEX_ADDINGDIGITSUPTO20_H__

/* vim: set cindent sw=2 expandtab : */


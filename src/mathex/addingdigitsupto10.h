#ifndef MATHEX_ADDINGDIGITSUPTO10_H__
#define MATHEX_ADDINGDIGITSUPTO10_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  \class AddingDigitsUpTo10 addingdigitsupto10.h "mathex/addingdigitsupto10.h"
  \ingroup mathex
  \brief Produces exercises of addition of 2 didgits, summing up to less than 10
  */
class AddingDigitsUpTo10 : public xgen::Level
{
public:
  AddingDigitsUpTo10();
  virtual ~AddingDigitsUpTo10();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  RandNum rand_;
  int next_int();
};

} // namespace

#endif // MATHEX_ADDINGDIGITSUPTO10_H__

/* vim: set cindent sw=2 expandtab : */


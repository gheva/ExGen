#ifndef MATHEX_ADDINGABOVE10_H__
#define MATHEX_ADDINGABOVE10_H__

#include "randnum.h"
#include "level.h"

namespace mathex
{

/**
  \class AddingAbove10 addingabove10.h "mathex/addingabove10.h"
  \ingroup mathex
  \brief Generates exercises with adding digits so that the sum is above 10
  */
class AddingAbove10 : public xgen::Level
{
public:
  AddingAbove10();
  virtual ~AddingAbove10();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  RandNum rand_;
  int next_int();
};

} // namespace

#endif // MATHEX_ADDINGABOVE10_H__

/* vim: set cindent sw=2 expandtab : */


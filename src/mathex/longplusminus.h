#ifndef MATHEX_LONGPLUSMINUS_H__
#define MATHEX_LONGPLUSMINUS_H__

#include "level.h"
#include "randnum.h"

namespace mathex
{

/**
  \class LongPlusMinus longplusminus.h "mathex/longplusminus.h"
  \ingroup mathex
  \brief Produces a very long exercise, alternate sbetwen producing an addition and subtraction
  */
class LongPlusMinus : public xgen::Level
{
public:
  LongPlusMinus();
  virtual ~LongPlusMinus();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
  void next_digit(int& l, int& r, bool first=false);
private:
  bool plus_;
  RandNum rand_;
};

} // namespace

#endif // MATHEX_LONGPLUSMINUS_H__

/* vim: set cindent sw=2 expandtab : */


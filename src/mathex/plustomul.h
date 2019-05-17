#ifndef MATHEX_PLUSTOMUL_H__
#define MATHEX_PLUSTOMUL_H__

#include "level.h"

namespace mathex
{

class PlusToMul : public xgen::Level
{
public:
  PlusToMul();
  virtual ~PlusToMul();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  unsigned int count_;
  unsigned int digit_;
};

} // namespace

#endif // MATHEX_PLUSTOMUL_H__

/* vim: set cindent sw=2 expandtab : */


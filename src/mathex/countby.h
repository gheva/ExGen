#ifndef MATHEX_COUNTBY_H__
#define MATHEX_COUNTBY_H__

#include "level.h"

namespace mathex
{

class CountBy : public xgen::Level
{
public:
  CountBy(int digit=-1);
  virtual ~CountBy();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
  int count_;
  static int by_[];
  int digit_;
};

} // namespace

#endif // MATHEX_COUNTBY_H__

/* vim: set cindent sw=2 expandtab : */


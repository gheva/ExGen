#ifndef MATHEX_MULTABLE_H__
#define MATHEX_MULTABLE_H__

#include "level.h"

namespace mathex
{

class MulTable : public xgen::Level
{
public:
  MulTable();
  virtual ~MulTable();
protected:
  virtual std::unique_ptr<xgen::Exercise> generate();
private:
};

} // namespace

#endif // MATHEX_MULTABLE_H__

/* vim: set cindent sw=2 expandtab : */


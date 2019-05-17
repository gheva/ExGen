#ifndef SVG_DEFS_H__
#define SVG_DEFS_H__

#include "svgelement.h"

namespace svg
{

/**
  \class Defs defs.h "svg/defs.h"
  \ingroup svg
  \brief Represents a def svg element
  */
class Defs : public SVGElement
{
public:
  Defs();
  virtual ~Defs();
protected:
private:
};

} // namespace

#endif // SVG_DEFS_H__

/* vim: set cindent sw=2 expandtab : */


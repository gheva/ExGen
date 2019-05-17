#include "use.h"

namespace svg
{

Use::Use(const std::string& id, unsigned int x, unsigned int y) :
  SVGElement("use")
{
  add_attribute("xlink:href", "#" + id);
  add_attribute("x", x);
  add_attribute("y", y);
}

Use::~Use()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


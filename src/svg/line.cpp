#include "line.h"

namespace svg
{

Line::Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) :
  SVGElement("line"), from_x_(x1), from_y_(y1), to_x_(x2), to_y_(y2)
{
  add_attribute("x1", from_x_);
  add_attribute("y1", from_y_);
  add_attribute("x2", to_x_);
  add_attribute("y2", to_y_);
}

Line::~Line()
{
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


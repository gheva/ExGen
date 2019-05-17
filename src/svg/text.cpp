#include "text.h"

namespace svg
{

Text::Text(const std::string& s) :
  SVGElement("text")
{
  add_child(s);
}

Text::~Text()
{
}

void Text::add_text(const std::string& text)
{
  add_child(text);
}

void Text::set_location(int x, int y)
{
  add_attribute("x", x);
  add_attribute("y", y);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


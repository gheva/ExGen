#include "font.h"

namespace svg
{

Font::Font(const std::string& family, int size) :
  size_(size), style_(""), weight_(""), decoration_(""), word_spacing_(0),
  letter_spacing_(0), unit_("")
{
  family_.push_back(family);
}

Font::~Font()
{
}

void Font::set_units(const std::string& unit)
{
  unit_ = unit;
}

void Font::set_family(const std::string& family)
{
  family_.clear();
  family_.push_back(family);
}

void Font::add_family(const std::string& family)
{
  family_.push_back(family);
}

void Font::apply(SVGElement& text) const
{
  text.add_style("font-family", family_);
  text.add_style("font-size", size_);
  if (!style_.empty())
  {
    text.add_style("font-style", style_);
  }
  if (!weight_.empty())
  {
    text.add_style("font-weight", weight_);
  }
}

void Font::set_style(const std::string& style)
{
  style_ = style;
}

void Font::set_weight(const std::string& weight)
{
  weight_ = weight;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


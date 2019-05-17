#include "svgelement.h"
#include <sstream>

namespace svg
{

SVGElement::SVGElement(const std::string& tag) :
  XMLNode(tag)
{
}

SVGElement::~SVGElement()
{
}

void SVGElement::add_style(const std::string& name, const std::string& value)
{
  // TODO escape string to avoid injection type issues
  style_[name].push_back(value);
}

void SVGElement::add_style(const std::string& name, int val)
{
  std::stringstream ss;
  ss << val;
  std::string v(ss.str());
  add_style(name, v);
}

void SVGElement::add_style(const std::string& name,
    const std::vector<std::string>& val)
{
  std::stringstream ss;

  bool first(true);
  for (auto ff : val)
  {
    if (!first)
    {
      ss << ',';
    }
    ss << ff;
    first = false;
  }

  std::string v(ss.str());
  add_style(name, v);
}

std::ostream& SVGElement::print_style(std::ostream& stream) const
{
  if (style_.empty())
  {
    return stream;
  }
  stream << " style=\"";
  bool semicolon(false);
  for (auto p : style_)
  {
    if (semicolon)
    {
      stream << "; ";
    }
    semicolon = true;
    stream << p.first << ": ";
    bool first(true);
    for (auto i : p.second)
    {
      if (!first)
      {
        stream << ',';
      }
      first = false;
      stream << i;
    }
  }
  return stream << '"';
}

std::ostream& SVGElement::attributes(std::ostream& stream) const
{
  xml::XMLNode::attributes(stream);
  return print_style(stream);
}

void SVGElement::stroke(const std::string& stroke)
{
  add_style("stroke", stroke);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


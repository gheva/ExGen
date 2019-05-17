#include "g.h"
#include "xml/xmlnode.h"

namespace svg
{

G::G(const std::string& id) :
  SVGElement("g")
{
  if (!id.empty())
  {
    add_attribute("id", id);
  }
}

G::~G()
{
}

void G::add_title(const std::string& title)
{
  xml::XMLNode* node = new xml::XMLNode("title");
  node->add_child(title);
  add_child(node);
}

void G::add_decription(const std::string& desc)
{
  xml::XMLNode* node = new xml::XMLNode("desc");
  node->add_child(desc);
  add_child(node);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


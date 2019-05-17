#ifndef SVG_TEXT_H__
#define SVG_TEXT_H__

#include <string>

#include "svgelement.h"

namespace svg
{

/**
  \class Text text.h "svg/text.h"
  \ingroup svg
  \brief Represents an svg text element
  */
class Text : public SVGElement
{
public:
  /**
    \brief Constructs a text element with the given text
    \param contents the contents to be set for this text node
    */
  Text(const std::string& contents="");
  virtual ~Text();

  /**
    \brief Adds a text data node to this element
    \param text - The contents of the node to be added

    This method calls xml::XMLNode::add_child with text as the single argument
    */
  void add_text(const std::string& text);

  /**
    \brief Sets the location attributes for this element
    \param x - The x coordinate for the location
    \param y - The y coordinate for the location
    */
  void set_location(int x, int y);
};

} // namespace

#endif // SVG_TEXT_H__

/* vim: set cindent sw=2 expandtab : */


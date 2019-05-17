#ifndef SVG_FONT_H__
#define SVG_FONT_H__

#include <string>
#include <vector>
#include <ostream>
#include "svgelement.h"

namespace svg
{

/**
  \class Font font.h "svg/font.h"
  \ingroup svg
  \brief Represents a font in an svg document.

  The font is applied on to an svg element (it ends up being a style on the svg, which ends up being an attribute on the xml node.
  */
class Font
{
public:
  /**
    \brief Constructs a Font object with the given family and size
    \param family - The font family represented by this font object
    \param size - The size of the font
    */
  Font(const std::string& family="serif", int size=12);
  virtual ~Font();

  /**
    \brief Sets the font units for this font
    \param unit - The unit name to be used
    */
  void set_units(const std::string& unit);

  /**
    \brief Sets the font family for this font
    \param family - The family name to be used
    */
  void set_family(const std::string& family);

  /**
    \brief Adds a family to the optional families
    \param family - The family name to be added

    In svg a text element can have several families, which are ordered and the first one to exist on the system will be used. This method adds a font to this list
    */
  void add_family(const std::string& family);

  /**
    \brief Sets this font's style
    \param style - The style to be used (e.g italics)
    */
  void set_style(const std::string& style);

  /**
    \brief Sets the font's weight
    \param weight - The font weight to be used (e.g bold)
    */
  void set_weight(const std::string& weight);

  /**
    \brief Apply this font to the given svg::SVGElement
    \param text - The svg element to which we want to apply this font
    */
  void apply(SVGElement& text) const;

private:
  std::vector<std::string> family_;
  int size_;
  std::string style_;
  std::string weight_;
  std::string decoration_;
  int word_spacing_;
  int letter_spacing_;
  std::string unit_;
};

} // namespace

#endif // SVG_FONT_H__

/* vim: set cindent sw=2 expandtab : */


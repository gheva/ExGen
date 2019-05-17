#ifndef SVG_LINEDTEXT_H__
#define SVG_LINEDTEXT_H__

#include "svg/font.h"
#include "svg/line.h"
#include "svg/text.h"
#include "xml/xmlnode.h"
#include <map>
#include <string>

using namespace xml;

namespace svg
{

/*
   Holds a text string, a length constraint, and can add the needed number of
   lines, as well as the text to a given node.
 */
/**
  \class LinedText linedtext.h "svg/linedtext.h"
  \ingroup svg
  \brief Holds a text and a length constraint, which will be used to split the text into lines with a limited length
  */
class LinedText
{
public:
  /**
    \brief Constructs a lined text object with the given length and initial content.
    \param text - The initial text
    \param char_count - The limit of characters per line
    */
  LinedText(const std::string& text, unsigned int char_count=default_limit);
  virtual ~LinedText();

  /**
    \brief Sets the font for the given text
    \param family - The font family to be used
    \param size -  The size for the font
    \return Returns the svg::Font object created

    If a font has already been set, it will be deleted and removed. Since the ownership of the memory of the returned pointer is of this object, callers need to be aware that it could be dropped at any moment.
    \todo come on, this needs to be a shared pointer....
    */
  Font* set_font(const std::string& family, int size);

  /**
    \brief Outputs the contents of this object to an xml::XMLNode using the optional fill for fill style of the printed text
    \param node - The node to which we are printing
    \param fill - The fill style for the text
    \return Returns the `Y` offset of the next line to be printed

    The expected usage of this method is:
    \code
    LinedText t1, t2 ....;
    XMLNode node
    unsigned int offset = t1.print(node);
    t2.set_y_offset(offset);
    t2.print(node);
    \endcode
    */
  unsigned int print(XMLNode& node, const std::string& fill="none");

  /**
    \brief Sets the y offset to be used when printing to a node
    \param off - The y offset to be used
    */
  void set_y_offset(unsigned int off);

  /**
    \brief Adds a style to the text
    \param name - The name of the style to be added
    \param val - The value of the style
    */
  void add_text_style(const std::string& name, const std::string& val);

  /**
    \brief tells this object to display background lines
    */
  void display_lines();

  /**
    \brief tells this object to not display background lines
    */
  void hide_bg_lines();
private:
  static Line* add_line(XMLNode& node, int x1, int y1, int x2, int y2);
  unsigned int letter_height();
  unsigned int line_space();
  unsigned int skip();
  static void trace_style(Text* text, const std::string& fill="none");
  unsigned int y_offset(unsigned int off);
  void add_bg_line(XMLNode& node, unsigned int off);
  void line_style(Line* line);
  void print_one_line(XMLNode& node, unsigned int off,
    const std::string& txt, const std::string& fill="none");

private:
  std::string text_;
  unsigned int limit_;
  unsigned int line_count_;
  static unsigned int default_limit;
  unsigned int font_size_;
  Font* font_;
  bool bg_lines_;
  unsigned int y_offset_;
  std::map<std::string, std::string> text_style_;
};

} // namespace

#endif // SVG_LINEDTEXT_H__

/* vim: set cindent sw=2 expandtab : */


#ifndef EXGEN_SVGDISPLAY_H__
#define EXGEN_SVGDISPLAY_H__

#include "exercisesvg.h"
#include "display.h"
#include <string>
#include <vector>

namespace xml
{
  class XMLNode;
}

namespace svg
{
  class Font;
  class Defs;
  class Use;
}

namespace exgen
{

/**
  \class SVGDisplay svgdisplay.h "displays/svgdisplay.h"
  \ingroup exgen
  \brief Prints out more than a single exercise to an svg document

  Each xgen::Exercise is transformed to svg in the exgen::ExerciseSVG during the call to pre_show
  */
class SVGDisplay : public xgen::Display
{
public:
  /**
    \brief Constructs a display which will output to to the given path, with each worksheet using the given dimensions.
    \param width - The width of each worksheet
    \param height - The height of each worksheet
    \param base_path - The directory into which the svg files will be output

    When outputting, we are assuming the directory exists, and each file will be named file_<index>.svg
    */
  SVGDisplay(unsigned int width, unsigned int height,
    const std::string& base_path);
  virtual ~SVGDisplay();

  /**
    \brief Prints out the pages to a file.
    */
  virtual void finalize();

  /**
    \brief Adds an exercise to the svg document
    \param exercise - The exercise to be added

    When calling show, the exercise is transfomred to svg during the call to pre_show, which will allow us to calculate the approprite location for this exercise.
    */
  virtual void show(const xgen::Exercise& exercise);
private:
  virtual void pre_show(const xgen::Exercise& exercise);
  virtual void post_show(const xgen::Exercise& exercise);
  xml::XMLNode* new_page();
  std::string id();

  std::ostream& stream(std::ostream& s);
private:
  const std::string& base_path_;
  unsigned int width_;
  unsigned int height_;
  unsigned int x_;
  unsigned int y_;
  unsigned int count_;
  svg::Font* font_;
  svg::Defs* current_defs_;
  std::vector<xml::XMLNode*> pages_;
  std::vector<svg::Use*> locations_;
  ExerciseSVG* exercise_;
  static const std::string& xml_header;
  static const std::string& xml_doctype;
  static const unsigned int x_offset;
  static const unsigned int y_offset;
  static const unsigned int x_skip;
  static const unsigned int y_skip;
  static const unsigned int math_font_size;
};

} // namespace

#endif // EXGEN_SVGDISPLAY_H__

/* vim: set cindent sw=2 expandtab : */


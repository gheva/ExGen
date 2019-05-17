#ifndef EXGEN_MATHSVG_H__
#define EXGEN_MATHSVG_H__

#include "exercise.h"
#include <string>

namespace svg
{
class Font;
class SVGElement;
}

namespace exgen
{

/**
  \class ExerciseSVG exercisesvg.h "displays/exercisesvg.h"
  \ingroup exgen
  \brief Transforms an xgen::Exercise to an svg

  This class allows fitting exercises into an svg by transforming them into an svg element with a given id. The element is then used in the svg document with the `use` tag to place the element in the proper place in the page.

  The class is using a factory to return the appropriate subtype for a given exercise version.
  */
class ExerciseSVG
{
public:
  virtual ~ExerciseSVG();

  /**
    \brief Returns the width that the passed in exercise will require
    */
  virtual unsigned int width() const = 0;

  /**
    \brief Returns the height that the passed in exercise will require
    */
  virtual unsigned int height() const = 0;

  /**
    \brief Returns an svg representation of the passed in exercise
    \param id - The id for the svg element
    \return Returns an svg representation of the passed in exercise
    */
  virtual svg::SVGElement* svg(const std::string& id="") = 0;

  /**
    \brief Use the provided font when producing the svg
    \param font - The font to be used
    */
  virtual void use_font(const svg::Font* font);

  /**
    \brief Factory method to return the appropriate implementation of a exgen::ExerciseSVG
    */
  static ExerciseSVG* new_ExerciseSVG(const xgen::Exercise& exercise);
protected:
  ExerciseSVG();
  const svg::Font* font_;
  void apply_font(svg::SVGElement& text);
private:
};

} // namespace

#endif // EXGEN_MATHSVG_H__

/* vim: set cindent sw=2 expandtab : */


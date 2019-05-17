#ifndef EXGEN_PLUS_MINUS_SVG__
#define EXGEN_PLUS_MINUS_SVG__

#include "exercisesvg.h"
#include "mathex/plusminusexercise.h"
#include <string>

namespace svg
{
class Font;
class SVGElement;
}

namespace exgen
{

class PlusMinusSVG : public ExerciseSVG
{
public:
  PlusMinusSVG(const mathex::PlusMinusExercise& ex);
  virtual ~PlusMinusSVG();
  unsigned int width() const;
  unsigned int height() const;
  const std::string& id();
  svg::SVGElement* svg(const std::string& id="");
protected:
  const mathex::PlusMinusExercise& exercise_;
private:
  svg::SVGElement* get_text_element();
  svg::SVGElement* get_two_level_exercise();
  int line_width();
  int ex_start();
};

} // namespace

#endif // EXGEN_PLUS_MINUS_SVG__

/* vim: set cindent sw=2 expandtab : */


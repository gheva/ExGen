#ifndef EXGEN_MULDIVSVG_H__
#define EXGEN_MULDIVSVG_H__

#include "exercisesvg.h"
#include "mathex/mulexercise.h"

namespace xgen
{
class Font;
class SVGElement;
}

namespace exgen
{

class MulDivSVG : public ExerciseSVG
{
public:
  MulDivSVG(const mathex::MulExercise& e);
  virtual ~MulDivSVG();
  virtual unsigned int width() const;
  virtual unsigned int height() const;
  virtual svg::SVGElement* svg(const std::string& id="");
protected:
private:
  svg::SVGElement* line(int x1, int y1, int x2, int y2);
  svg::SVGElement* square(int x, int y, int dim);
  svg::SVGElement* countby_svg();
  svg::SVGElement* multable_svg();
  svg::SVGElement* two_level_mul_svg();
  const mathex::MulExercise& exercise_;
  static const int SQUARE_DIM;
  static const int X_TEXT_OFFSET;
  static const int Y_TEXT_OFFSET;
  static const std::string LINE_STROKE_COLOR;
};

} // namespace

#endif // EXGEN_MULDIVSVG_H__

/* vim: set cindent sw=2 expandtab : */


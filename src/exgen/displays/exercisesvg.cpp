#include "exercisesvg.h"
#include "mathex.h"
#include "plusminussvg.h"
#include "muldivsvg.h"
#include "plusminusexercise.h"
#include "mulexercise.h"
#include "svg/font.h"
#include "svg/g.h"
#include "svg/line.h"
#include "svg/text.h"

using namespace mathex;

namespace exgen
{

ExerciseSVG::ExerciseSVG()
{
}

ExerciseSVG::~ExerciseSVG()
{
}

void ExerciseSVG::use_font(const svg::Font* font)
{
  font_ = font;
}

void ExerciseSVG::apply_font(svg::SVGElement& text)
{
  font_->apply(text);
}

ExerciseSVG* ExerciseSVG::new_ExerciseSVG(const xgen::Exercise& exercise)
{
  switch (exercise.id())
  {
  case math_exercise_ids::EXERCISE_ID_PLUS_MINUS:
    return new PlusMinusSVG(static_cast<const PlusMinusExercise&>(exercise));
    break;
  case math_exercise_ids::EXERCISE_ID_MULTIPLICATION:
    return new MulDivSVG(static_cast<const MulExercise&>(exercise));
    break;
  }
  return nullptr;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


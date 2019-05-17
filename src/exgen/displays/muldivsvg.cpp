#include "muldivsvg.h"
#include "svg/g.h"
#include "svg/text.h"
#include "svg/font.h"
#include "svg/line.h"
#include <sstream>

using namespace mathex;

namespace exgen
{

const int MulDivSVG::SQUARE_DIM(40);
const int MulDivSVG::X_TEXT_OFFSET(15);
const int MulDivSVG::Y_TEXT_OFFSET(25);
const std::string MulDivSVG::LINE_STROKE_COLOR("grey");;

MulDivSVG::MulDivSVG(const MulExercise& e) : exercise_(e)
{
}

MulDivSVG::~MulDivSVG()
{
}

unsigned int MulDivSVG::width() const
{
  switch (exercise_.version())
  {
  case MulExercise::MUL_LEVEL_COUNT_BY:
  case MulExercise::MUL_LEVEL_MUL_TABLE:
    return 540;
  }
  return 180;
}

unsigned int MulDivSVG::height() const
{
  switch (exercise_.version())
  {
  case MulExercise::MUL_LEVEL_COUNT_BY:
    return 10;
  }
  return 20;
}

svg::SVGElement* MulDivSVG::svg(const std::string& id)
{
  svg::G* ret = new svg::G(id);
  switch (exercise_.version())
  {
  case MulExercise::MUL_LEVEL_COUNT_BY:
    ret->add_child(countby_svg());
    break;
  case MulExercise::MUL_LEVEL_MUL_TABLE:
    ret->add_child(multable_svg());
    break;
  }
  return ret;
}

svg::SVGElement* MulDivSVG::multable_svg()
{
  svg::G* ret = new svg::G();
  int x(0), y(0);
  std::stringstream ss;
  svg::Text* text;
  for (int i = 0; i < 11; ++i)
  {
    for (int j = 0; j < 11; ++j)
    {
      svg::SVGElement* tmp(square(x, y, SQUARE_DIM));
      if (i == 0 && j == 0)
      {
        text = new svg::Text("X");
        font_->apply(*text);
        text->set_location(X_TEXT_OFFSET, Y_TEXT_OFFSET);
        tmp->add_child(text);
      }
      else if (i == 0)
      {
        ss.str("");
        ss << j;
        text = new svg::Text(ss.str());
        font_->apply(*text);
        text->set_location(x + X_TEXT_OFFSET, y + Y_TEXT_OFFSET);
        tmp->add_child(text);
      }
      else if (j == 0)
      {
        ss.str("");
        ss << i;
        text = new svg::Text(ss.str());
        font_->apply(*text);
        text->set_location(x + X_TEXT_OFFSET, y + Y_TEXT_OFFSET);
        tmp->add_child(text);
      }
      ret->add_child(tmp);

      x += SQUARE_DIM;
    }
    y += SQUARE_DIM;
    x = 0;
  }
  return ret;
}

svg::SVGElement* MulDivSVG::countby_svg()
{
  svg::G* ret = new svg::G();
  int x(SQUARE_DIM), y(0);
  svg::SVGElement* tmp(square(0, 0, SQUARE_DIM));
  std::stringstream ss;

  ss << exercise_[0];

  svg::Text* text = new svg::Text(ss.str());
  font_->apply(*text);
  text->set_location(X_TEXT_OFFSET, Y_TEXT_OFFSET);
  tmp->add_child(text);

  ret->add_child(tmp);
  for (int i = 1; i < 11; ++i)
  {
    ret->add_child(square(x, y, SQUARE_DIM));
    x += SQUARE_DIM;
  }
  return ret;
}

svg::SVGElement* MulDivSVG::square(int x, int y, int dim)
{
  svg::G* ret = new svg::G();
  ret->add_child(line(x, y, x, y + dim));
  ret->add_child(line(x, y, x + dim, y));
  ret->add_child(line(x + dim, y, x + dim, y + dim));
  ret->add_child(line(x, y + dim, x + dim, y + dim));
  return ret;
}

svg::SVGElement* MulDivSVG::line(int x1, int y1, int x2, int y2)
{
  svg::Line* l = new svg::Line(x1, y1, x2, y2);
  l->stroke(LINE_STROKE_COLOR);
  l->add_style("stroke-width", "0.5");
  return l;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


#include "plusminussvg.h"
#include "svg/font.h"
#include "svg/g.h"
#include "svg/line.h"
#include "svg/text.h"
#include <cstdlib>
#include <sstream>

using namespace mathex;

namespace exgen
{

PlusMinusSVG::PlusMinusSVG(const PlusMinusExercise& ex) :
  exercise_(ex)
{
}

PlusMinusSVG::~PlusMinusSVG()
{
}

unsigned int PlusMinusSVG::width() const
{
  switch (exercise_.version())
  {
    case PlusMinusExercise::LONG_ADD_SUBTRACT:
      return 540;
  }
  return 180;
}

unsigned int PlusMinusSVG::height() const
{
  unsigned int ret(0);
  switch (exercise_.version())
  {
  case PlusMinusExercise::TWO_LEVEL_EXERCISE:
  case PlusMinusExercise::PLUS_TO_MUL:
    ret = 80;
    break;
  case PlusMinusExercise::LONG_ADD_SUBTRACT:
    ret = 55;
    break;
  default:
    ret = 20;
    break;
  }
  return ret;
}

svg::SVGElement* PlusMinusSVG::get_text_element()
{

  std::stringstream ss;
  ss << exercise_[0];
  for (int i = 1; i < exercise_.size(); ++i)
  {
    ss << (exercise_.op(i) ? " + " : " - ") << exercise_[i];
  }
  ss << " = ____";
  svg::Text* txt = new svg::Text(ss.str());
  font_->apply(*txt);
  return txt;
}

int PlusMinusSVG::line_width()
{
  int ret(0);
  switch (exercise_.version())
  {
  case PlusMinusExercise::TWO_LEVEL_EXERCISE:
  case PlusMinusExercise::PLUS_TO_MUL:
    ret = 30;
    break;
  case PlusMinusExercise::LONG_ADD_SUBTRACT:
    ret = 330;
  }
  return ret;
}

int PlusMinusSVG::ex_start()
{
  int ret(0);
  switch (exercise_.version())
  {
  case PlusMinusExercise::TWO_LEVEL_EXERCISE:
  case PlusMinusExercise::PLUS_TO_MUL:
    ret = 28;
    break;
  case PlusMinusExercise::LONG_ADD_SUBTRACT:
    ret = 330;
  }
  return ret;
}

svg::SVGElement* PlusMinusSVG::get_two_level_exercise()
{
  svg::G* g = new svg::G();
  std::stringstream ss;
  if (exercise_.version() != PlusMinusExercise::PLUS_TO_MUL)
  {
    ss << exercise_[0];
  }
  else
  {
    ss << "  ";
  }
  svg::Text* t = new svg::Text(ss.str());
  t->add_style("text-anchor", "end");
  t->add_style("letter-spacing", "5pt");
  font_->apply(*t);
  t->set_location(ex_start(), 0);
  g->add_child(t);
  std::string op(exercise_.op(1) ? "+" : "-");
  t = new svg::Text(op);
  font_->apply(*t);
  t->set_location(0, 15);
  g->add_child(t);
  ss.str("");
  ss << exercise_[1];
  t = new svg::Text(ss.str());
  font_->apply(*t);
  t->set_location(ex_start(), 30);
  t->add_style("text-anchor", "end");
  t->add_style("letter-spacing", "5pt");
  g->add_child(t);

  svg::Line* line = new svg::Line(0, 35, line_width(), 35);
  line->stroke("black");
  g->add_child(line);

  line = new svg::Line(0, 60, line_width(), 60);
  line->stroke("black");
  g->add_child(line);

  return g;
}

svg::SVGElement* PlusMinusSVG::svg(const std::string& id)
{
  svg::G* ret = new svg::G(id);
  switch (exercise_.version())
  {
  case PlusMinusExercise::EX_VERSION_0:
    ret->add_child(get_text_element());
    break;
  case PlusMinusExercise::LONG_ADD_SUBTRACT:
  case PlusMinusExercise::TWO_LEVEL_EXERCISE:
  case PlusMinusExercise::PLUS_TO_MUL:
    ret->add_child(get_two_level_exercise());
    break;
  }

  return ret;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


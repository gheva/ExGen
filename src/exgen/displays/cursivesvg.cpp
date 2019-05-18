#include "cursivesvg.h"

namespace exgen
{

CursiveSVG::CursiveSVG(const cursex::CursiveExercise& ex)
{
}

CursiveSVG::~CursiveSVG()
{
}

unsigned int CursiveSVG::width() const
{
  return 0;
}

unsigned int CursiveSVG::height() const
{
  return 0;
}

svg::SVGElement* CursiveSVG::svg(const std::string& id)
{
  return nullptr;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


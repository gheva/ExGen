#ifndef EXGEN_CURSIVESVG_H__
#define EXGEN_CURSIVESVG_H__
#include "exercisesvg.h"
#include "cursex/cursiveexercise.h"

namespace exgen
{

class CursiveSVG : public ExerciseSVG
{
public:
  CursiveSVG(const cursex::CursiveExercise& ex);
  virtual ~CursiveSVG();
  virtual unsigned int width() const;
  virtual unsigned int height() const;
  virtual svg::SVGElement* svg(const std::string& id="");
  //virtual void use_font(const svg::Font* font);
protected:
private:
};

} // namespace

#endif // EXGEN_CURSIVESVG_H__

/* vim: set cindent sw=2 expandtab : */


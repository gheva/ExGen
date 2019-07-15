#include "svgdisplay.h"
#include "svg/defs.h"
#include "svg/font.h"
#include "svg/use.h"
#include "xml/xmlnode.h"
#include <iostream>
#include <fstream>
#include "mathex.h"

using namespace mathex;

namespace exgen
{

const std::string& SVGDisplay::xml_header("<?xml version=\"1.0\"?>");
const std::string& SVGDisplay::xml_doctype("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" \
    " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">");
const unsigned int SVGDisplay::x_offset(10);
const unsigned int SVGDisplay::y_offset(15);
const unsigned int SVGDisplay::x_skip(20);
const unsigned int SVGDisplay::y_skip(50);
const unsigned int SVGDisplay::math_font_size(16);


SVGDisplay::SVGDisplay(unsigned int width, unsigned int height,
  const std::string& base_path) :
  base_path_(base_path), width_(width), height_(height),
  x_(x_offset), y_(y_offset), font_(NULL), exercise_(NULL), count_(0)
{
  current_defs_ = new svg::Defs();
}

SVGDisplay::~SVGDisplay()
{
  for (int i = 0; i < pages_.size(); ++i)
  {
    delete pages_[i];
  }
  if (font_)
  {
    delete font_;
  }
}

xml::XMLNode* SVGDisplay::new_page()
{
  xml::XMLNode* ret = new xml::XMLNode("svg");
  ret->add_attribute("width", width_);
  ret->add_attribute("height", height_);
  ret->add_attribute("xmlns", "http://www.w3.org/2000/svg");
  ret->add_attribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
  ret->add_child(current_defs_);
  current_defs_ = new svg::Defs();
  count_ = 0;
  x_ = x_offset;
  y_ = y_offset;
  for (auto iter : locations_)
  {
    ret->add_child(iter);
  }
  locations_.clear();
  pages_.push_back(ret);
  return ret;
}

std::string SVGDisplay::id()
{
  char buffer[32];
  snprintf(buffer, 32, "exercise_%d", count_);
  return std::string(buffer);
}

void SVGDisplay::show(const xgen::Exercise& exercise)
{
  pre_show(exercise);

  if (!font_)
  {
    font_ = new svg::Font("sans-serif", math_font_size);
  }
  exercise_->use_font(font_);
  std::string i(id());
  current_defs_->add_child(exercise_->svg(i));
  locations_.push_back(new svg::Use(i, x_, y_));

  post_show(exercise);
}

void SVGDisplay::pre_show(const xgen::Exercise& exercise)
{
  if (!current_defs_)
  {
    current_defs_ = new svg::Defs();
  }
  if (exercise_)
  {
    delete exercise_;
  }

  exercise_ = ExerciseSVG::new_ExerciseSVG(exercise);

  if (x_ + exercise_->width() >= width_)
  {
    x_ = x_offset;
    y_ += exercise_->height() + y_skip;
    if (y_ >= height_)
    {
      new_page();
    }
  }
}

void SVGDisplay::post_show(const xgen::Exercise& exercise)
{
  ++count_;
  x_ += exercise_->width() + x_skip;
  if (x_ >= width_)
  {
    x_ = x_offset;
    y_ += exercise_->height() + y_skip;
    if (y_ >= height_)
    {
      new_page();
    }
  }
}

void SVGDisplay::finalize()
{
  char buffer[1024];
  new_page();
  for (int i = 0; i < pages_.size(); ++i)
  {
    snprintf(buffer, 1024, "%s_%d.svg", base_path_.c_str(), i);

    std::ofstream fs(buffer);
    if (fs.is_open())
    {
      fs << xml_header << std::endl;
      fs << xml_doctype << std::endl;
      fs << *pages_[i] << std::endl;
      fs.close();
    }
  }
}

std::ostream& SVGDisplay::stream(std::ostream& s)
{
  new_page();
  for (int i = 0; i < pages_.size(); ++i)
  {
    s << *pages_[i] << std::endl;
  }
  return s;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


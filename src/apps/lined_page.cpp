#include "svg/line.h"
#include "xml/xmlnode.h"
#include <iostream>

#define LARGE_SPACE 39
#define SHORT_SPACE 17
#define LINE_COLOR "grey"
#define STROKE_WIDTH "0.5"

/**
  \defgroup lined_page The lined page generator
  \brief Generate an svg page with lines suitable for cursive writing

  This is a very simple application, it is useful for printing pages for practicing free writing of cursive (at least this worked well for my kid)
  */
using namespace std;
using namespace xml;
using namespace svg;

void print_header(ostream& stream);
Line* single_line(int x1, int y1, int x2, int y2)
{
  Line* l = new Line(x1, y1, x2, y2);
  l->stroke(LINE_COLOR);
  l->add_style("stroke-width", STROKE_WIDTH);
  return l;
}

void add_page(int x1, int y1, int y2, XMLNode& root)
{
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += LARGE_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));
  x1 += SHORT_SPACE;
  root.add_child(single_line(x1, y1, x1, y2));

}

int main(int argc, char** argv)
{
  XMLNode root("svg");
  root.add_attribute("width", "600");
  root.add_attribute("height", "800");
  root.add_attribute("xmlns", "http://www.w3.org/2000/svg");

  add_page(5, 5, 400, root);
  add_page(5, 430, 800, root);

  print_header(cout);
  cout << root << endl;
}

#define XML_HEADER "<?xml version=\"1.0\"?>"
#define XML_DOCTYPE "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" \
    " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" 

void print_header(ostream& stream)
{
  stream << XML_HEADER << endl;
  stream << XML_DOCTYPE << endl;
}

/* vim: set cindent sw=2 expandtab : */


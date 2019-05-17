#ifndef SVG_LINE_H__
#define SVG_LINE_H__

#include "svgelement.h"

namespace svg
{

/**
  \class Line line.h "svg/line.h"
  \ingroup svg
  \brief Represents an svg line element
  */
class Line : public SVGElement
{
public:
  /**
    \brief Constructs a line element from the first point to the second
    \param from_x - The x coordinate of the starting point for this line
    \param from_y - The y coordinate of the starting point for this line
    \param to_x - The x coordinate of the end point for this line
    \param to_y - The y coordinate of the end point for this line
    */
  Line(unsigned int from_x, unsigned int from_y, unsigned int to_x, unsigned int to_y);
  virtual ~Line();
protected:
private:
  unsigned int from_x_;
  unsigned int from_y_;
  unsigned int to_x_;
  unsigned int to_y_;
};

} // namespace

#endif // SVG_LINE_H__

/* vim: set cindent sw=2 expandtab : */


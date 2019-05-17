#ifndef SVG_USE_H__
#define SVG_USE_H__

#include "svgelement.h"
#include <string>

namespace svg
{

/**
  \class Use use.h svg/use.h
  \ingroup svg
  \brief Represents an svg use element
  */
class Use : public SVGElement
{
public:
  /**
    \brief Constructs a use element to use the given id at the given location
    \param id - The id of the element to use
    \param x - The x coordinate to put the element at
    \param y - The y coordinate to put the element at
    */
  Use(const std::string& id, unsigned int x, unsigned int y);
  virtual ~Use();
};

} // namespace

#endif // SVG_USE_H__

/* vim: set cindent sw=2 expandtab : */


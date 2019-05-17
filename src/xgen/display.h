#ifndef XGEN_DISPLAY_H__
#define XGEN_DISPLAY_H__

#include "exercise.h"

namespace xgen
{

/**
  \class Display display.h "xgen/display.h"
  \ingroup xgen
  \brief A display is used to display a single exercise
 */
class Display
{
public:
  Display();
  virtual ~Display();

  /**
    \brief Show a single exercise
    \param exercise - The exercise to display
    */
  virtual void show(const Exercise& exercise) = 0;
};

} // namespace

#endif // XGEN_DISPLAY_H__

/* vim: set cindent sw=2 expandtab : */


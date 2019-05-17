#ifndef XGEN_EXERCISE_H__
#define XGEN_EXERCISE_H__

#include <ostream>

namespace xgen
{

/**
  \class Exercise exercise.h "xgen/exercise.h"
  \ingroup xgen
  \brief A representation of a single exercise

  When a Level object generates an exercise, we use the Exercise object is used to pass the information to the display. Subclasses are expected to target specific types of exercises and to be handled by proper displays.
  */
class Exercise
{
public:
  Exercise(int id);
  virtual ~Exercise();
  int id() const;
private:
  int id_;
};

} // namespace

#endif // XGEN_EXERCISE_H__

/* vim: set cindent sw=2 expandtab : */


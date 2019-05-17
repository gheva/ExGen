#ifndef XGEN_LEVEL_H__
#define XGEN_LEVEL_H__

#include <memory>
#include <ostream>
#include <vector>

#include "exercise.h"

namespace xgen
{

/**
  \class Level level.h "xgen/level.h"
  \ingroup xgen
  \brief Generates a list of exercises

  The level is responsible of generating exercises.
  */
class Level
{
public:
  /**
    \typedef exercise_list
    \brief A list of exercises. 

    The memory of the  Exercise objects is held by the vector
    */
  typedef std::vector<std::unique_ptr<Exercise>> exercise_list;

  Level();
  virtual ~Level();

  /**
    \brief Generate an exercise list
    \param count - The number of exercises to generate
    \return Returns a list of exercises
    */
  exercise_list generate(int count);

  /**
    \brief Generate a single exercise
    \return a memory managed pointer to an exercise

    Subclasses are expected to override this method and generate the appropriate exercises.
    */
  virtual std::unique_ptr<Exercise> generate() = 0;
private:
};

} // namespace

#endif // XGEN_LEVEL_H__

/* vim: set cindent sw=2 expandtab : */


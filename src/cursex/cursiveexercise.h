#ifndef CURSEX_CURSIVEEXERCISE_H__
#define CURSEX_CURSIVEEXERCISE_H__
#include "exercise.h"

namespace cursex
{

enum cursive_exercise_ids
{
  EXERCISE_ID_SINGLE_LETTER = CURSIVE_EXERCISE_IDS_FIRST,
  EXERCISE_ID_CAPITAL_LETTER,
  EXERCISE_ID_LETTER_COMBINATIONS,
  EXERCISE_ID_WORD,
  EXERCISE_ID_SENTENCE,
};

class CursiveExercise : public xgen::Exercise
{
public:
  CursiveExercise(int id);
  virtual ~CursiveExercise();
protected:
private:
};

} // namespace

#endif // CURSEX_CURSIVEEXERCISE_H__

/* vim: set cindent sw=2 expandtab : */


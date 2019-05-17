#include "multable.h"

#include "mulexercise.h"

namespace mathex
{

MulTable::MulTable()
{
}

MulTable::~MulTable()
{
}

std::unique_ptr<xgen::Exercise> MulTable::generate()
{
  std::unique_ptr<MulExercise> e(new MulExercise(MulExercise::MUL_LEVEL_MUL_TABLE));
  return e;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


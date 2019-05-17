#include "exercise.h"

namespace xgen
{

Exercise::Exercise(int id) :
  id_(id)
{
}

Exercise::~Exercise()
{
}

int Exercise::id() const
{
  return id_;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


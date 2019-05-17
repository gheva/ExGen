#include "level.h"

namespace xgen
{

Level::Level()
{
}

Level::~Level()
{
}

std::vector<std::unique_ptr<Exercise>> Level::generate(int count)
{
  std::vector<std::unique_ptr<Exercise>> ret;
  for (int i = 0; i < count; ++i)
  {
    ret.push_back(std::move(generate()));
  }
  return std::move(ret);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


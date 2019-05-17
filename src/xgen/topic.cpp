#include "topic.h"

using std::string;

namespace xgen
{

Topic::Topic(const string& name) :
  name_(name)
{
}

Topic::~Topic()
{
  for (int i = 0; i < levels_.size(); ++i)
  {
    delete levels_[i];
    levels_[i] = NULL;
  }
}

const string& Topic::name() const
{
  return name_;
}

Level* Topic::get_level(unsigned int index)
{
  if (index >= levels_.size())
  {
    return NULL;
  }
  return levels_[index];
}

void Topic::add_level(Level* l)
{
  levels_.push_back(l);
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


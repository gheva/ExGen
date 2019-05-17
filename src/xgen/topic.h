#ifndef XGEN_TOPIC_H__
#define XGEN_TOPIC_H__

#include <string>
#include <vector>
#include "level.h"

namespace xgen
{

/**
  \class Topic topic.h "xgen/topic.h"
  \ingroup xgen
  \brief Represents a learning topic.

  Each topic consists of a list of levels for generating exercises. The topics are added by pointer, the ownership of the memory of the levels is of the Topic object holding them.
  */
class Topic
{
public:
  /**
    \brief Constructs a topic with the given name
    \param name - The name of this topic
    */
  Topic(const std::string& name);
  virtual ~Topic();

  /**
    \brief Returns the name of this topic
    \return Returns the name of this topic
    */
  const std::string& name() const;

  /**
    \brief Gets the level at the given index
    \param index - The index into the vector of levels
    \return Returns a pointer to the level at the given index. Returns nullptr if the index is out of bounds
    */
  Level* get_level(unsigned int index);

  /**
    \brief Adds a level to this topic
    \param level - A pointer to a Level object to be added to this topic

    The pointer is held by the Topic class, and will be deleted during the destruction of the Topic object.
    */
  void add_level(Level* level);
protected:
private:
  std::string name_;
  std::vector<Level*> levels_;
};

} // namespace

#endif // XGEN_TOPIC_H__

/* vim: set cindent sw=2 expandtab : */


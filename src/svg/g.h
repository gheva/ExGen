#ifndef SVG_G_H__
#define SVG_G_H__

#include "svgelement.h"
#include <string>

namespace svg
{

/**
  \class G g.h "svg/g.h"
  \ingroup svg
  \brief Represents an svg g (group) element
  */
class G : public SVGElement
{
public:
  /**
    \brief Constructs a g element with an optional id
    \param id - The optional id for this g element

    An empty id will create a g element without an id
    */
  G(const std::string& id="");
  virtual ~G();

  /**
    \brief Adds a title to this element
    \param title - The title for this element

    The title is added as a data node inside an xml::XMLNode with the tag of `title`
    */
  void add_title(const std::string& title);

  /**
    \brief Adds a description to this element
    \param desc - The title for this element

    The description is added as a data node inside an xml::XMLNode with the tag of `description`
    */
  void add_decription(const std::string& desc);
};

} // namespace

#endif // SVG_G_H__

/* vim: set cindent sw=2 expandtab : */


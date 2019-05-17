#ifndef SVG_SVGELEMENT_H__
#define SVG_SVGELEMENT_H__

#include "xml/xmlnode.h"
#include <string>
#include <map>
#include <vector>

/**
  \defgroup svg svg
  \brief This is a simple library for generating svg documents.

  The svg is based on the implementation of xml::XMLNode
  */
namespace svg
{

/**
  \class SVGElement svgelement.h "inc/svgelement.h"
  \ingroup svg
  \brief Represent an svg element

  The SVGElement adds the functionality of adding a style to the xml::XMLNode
  */
class SVGElement : public xml::XMLNode
{
public:
  SVGElement(const std::string& tag);
  virtual ~SVGElement();

  /**
    \brief Adds a named style to this element
    \param name - The name of the style to add
    \param value - The value to be assigned to this style
    */
  void add_style(const std::string& name, const std::string& value);

  /**
    \brief Adds a named style to this element
    \param name - The name of the style to add
    \param value - The value to be assigned to this style
    */
  void add_style(const std::string& name, int val);

  /**
    \brief Adds a named style to this element
    \param name - The name of the style to add
    \param value - The value to be assigned to this style
    */
  void add_style(const std::string& name,
                      const std::vector<std::string>& val);

  /**
    \brief Adds a named stroke to this node
    \param stroke - The name of the stroke to be applied to this element
    */
  void stroke(const std::string& stroke);
protected:
  virtual std::ostream& attributes(std::ostream& stream) const;
private:
  std::ostream& print_style(std::ostream& stream) const; 
  std::map<std::string, std::vector<std::string> > style_;
};

} // namespace

#endif // SVG_SVGELEMENT_H__

/* vim: set cindent sw=2 expandtab : */


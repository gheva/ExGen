#ifndef XML_XMLNODE_H__
#define XML_XMLNODE_H__

/**
  \defgroup xml xml
  \brief This is a small module for abstracting xml, which will be used in the svg module.

  Some consideration has been made on whether or not to use the boost library for xml and svg. In boost svg is pure graphics, for us it made more sense to keep things simple and treat everything as text.
  */
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace xml
{

/**
  \class XMLNode xmlnode.h "xml/xmlnode.h"
  \ingroup xml
  \brief An abstraction of an XML node or document.

  Our abstraction consists of a tree of nodes, each with a map of attributes.
  An xml node can either be a node in the tree, or a data node, which is a wrapper around string data. A data node does not have a tag, and will be printed to a stream as the string itself.
  */
class XMLNode
{
public:
  /**
    \typedef node_list
    \brief A vector of nodes.

    Each node holds a list of child nodes.
    */
  typedef std::vector<std::unique_ptr<XMLNode>> node_list;

  /**
    \typedef attribute_map
    \brief Each attribute for a node is stored as a node in the attribute map
    */
  typedef std::map<std::string, std::string> attribute_map;

  /**
    \brief Construct an XMLNode with the given tag at the given indentation level.
    \param tag - The tag for this xml node
    \param ilevel - The indentation level

    When outputting the node to a stream, each node will start at a new line and end with a new line. At the beginning of the line, white space, for indentation, will be printed to the stream. The amount of white space is `ilevel * XMLNode::indentation`.
    */
  XMLNode(const std::string& tag="", unsigned int ilevel=0);
  virtual ~XMLNode();

  /**
    \brief Return the indentation level of this XMLNode
    \return Returns the indentation level
    */
  unsigned int indent() const;
  /**
    \brief Set the indentation level of this XMLNode
    \param ilevel - The indentation level to set for this XMLNode
    */
  void indent(unsigned int ilevel);

  /**
    \brief Adds a data node child
    \param data - The data to be stored in the child data node
    */
  void add_child(const std::string& data);

  /**
    \brief Adds a node as a child node to this node
    \param child - A pointer to the node object to be added
    */
  void add_child(XMLNode* child);

  /**
    \brief Adds a node as a child node to this node
    \param child - A unique pointer to the node object to be added

    The ownership of the child node will move to this node
    */
  void add_child(std::unique_ptr<XMLNode>& child);

  /**
    \brief Get the children held by this node
    \return Returns the list of children nodes

    The memory of the child nodes is held by the node to which they belong.
    */
  const node_list& childeren() const;

  /**
    \brief Returns the count of child nodes belonging to this node
    \return Returns the count of child nodes belonging to this node
    */
  unsigned int size() const;

  /**
    \brief Returns a reference to the child node at the provided index
    \param index - The index of the requested node
    \return Returns the node at the given index

    This method will behave as the STL behaves when accessing a vector out of it's bounds
    */
  const XMLNode& operator[](unsigned int index) const;

  /**
    \brief Adds a named attribute to this node
    \param name - The name of the attribute
    \param value - The value to assign to this attribute
    */
  void add_attribute(const std::string& name, unsigned int value); 

  /**
    \brief Adds a named attribute to this node
    \param name - The name of the attribute
    \param value - The value to assign to this attribute
    */
  void add_attribute(const std::string& name, const std::string& value); 

  /**
    \brief Stores data in this node
    \param data - The data to be stored
    */
  void data(const std::string& data);

  /**
    \brief getter for the data stored in the node
    \return Returns the data stored in this node
    */
  const std::string& data() const;

  /**
    \brief Returns whether this node needs it's tag printed
    */
  bool is_data_node() const;

  std::string tag() const { return tag_; }

  std::string attribute(const std::string& name) const;

  friend std::ostream& operator<<(std::ostream& stream, const XMLNode& xml);
protected:
  virtual std::ostream& attributes(std::ostream& stream) const;
private:
  std::ostream& indent(std::ostream& stream) const;
  std::ostream& open_tag(std::ostream& stream) const;
  std::ostream& close_tag(std::ostream& stream) const;
  unsigned int indent_level_;
  const std::string tag_;
  std::string data_;
  /**
    \brief This constant holds the indentation string.

    When outputting the xml to a stream, the indentation is added at the beginning of each printed node, based n the indentation level (e.g if the indentation level is 4, 4 indentation strings will be printed to the stream before the node
    */
  static const std::string& indentation;
  attribute_map attributes_;
  node_list children_;
};

/**
  \brief Prints out this node and it's children to the stream
  \param stream - A reference to the stream into which we are printing
  \param xml - The node to be printed
  \return Returns a reference to the stream

  This function prints the node recursively in an in order traversal, which would limit the functionality to not extremely large xml documents.
  */
std::ostream& operator<<(std::ostream& stream, const XMLNode& xml);

} // namespace

#endif // XML_XMLNODE_H__

/* vim: set cindent sw=2 expandtab : */


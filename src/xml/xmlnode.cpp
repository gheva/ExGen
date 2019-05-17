#include "xmlnode.h"
#include <sstream>
#include <algorithm>

namespace xml
{

const std::string& XMLNode::indentation("  ");

XMLNode::XMLNode(const std::string& tag, unsigned int ilevel) :
  tag_(tag), indent_level_(ilevel)
{
}

XMLNode::~XMLNode()
{
}

// {{{ indentation

unsigned int XMLNode::indent() const
{
  return indent_level_;
}

void XMLNode::indent(unsigned int ilevel)
{
  indent_level_ = ilevel;
}

std::ostream& XMLNode::indent(std::ostream& stream) const
{
  for (int i = 0; i < indent_level_; ++i)
  {
    stream << indentation;
  }
  return stream;
}

// }}}

// {{{ printout

std::ostream& XMLNode::attributes(std::ostream& stream) const
{
  for (auto k : attributes_)
  {
    stream << ' ' << k.first << "=\"" << k.second << '"';
  }
  return stream;
}

std::ostream& XMLNode::open_tag(std::ostream& stream) const
{
  indent(stream) << '<' << tag_;
  attributes(stream);
  if (children_.empty())
  {
    stream << '/';
  }
  stream << '>' << std::endl;
  return stream;
}

std::ostream& XMLNode::close_tag(std::ostream& stream) const
{
  if (children_.empty())
  {
    return stream;
  }
  indent(stream) << "</" << tag_ << '>' << std::endl;
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const XMLNode& xml)
{
  if (xml.is_data_node())
  {
    xml.indent(stream);
    return stream << xml.data() << std::endl;
  }
  xml.open_tag(stream);
  for (int i = 0; i < xml.size(); ++i)
  {
    stream << xml[i];
  }
  return xml.close_tag(stream) << std::endl;
}

// }}}

// {{{ Child handling

void XMLNode::add_child(const std::string& data)
{
  XMLNode* node = new XMLNode;
  node->indent(indent_level_ + 1);
  node->data(data);
  add_child(node);
}

void XMLNode::add_child(XMLNode* child)
{
  children_.push_back(std::move(std::unique_ptr<XMLNode>(child)));
}

void XMLNode::add_child(std::unique_ptr<XMLNode>& child)
{
  child->indent(indent_level_ + 1);
  children_.push_back(std::move(child));
}

const XMLNode::node_list& XMLNode::childeren() const
{
  return children_;
}

unsigned int XMLNode::size() const
{
  return children_.size();
}

const XMLNode& XMLNode::operator[](unsigned int index) const
{
  return *(children_[index]);
}

// }}}

// {{{ data handling

void XMLNode::data(const std::string& data)
{
  data_ = data;
}

const std::string& XMLNode::data() const
{
  return data_;
}

bool XMLNode::is_data_node() const
{
  return tag_.empty();
}

// }}}

// {{{ Attributes

void XMLNode::add_attribute(const std::string& name, const std::string& value)
{
  attributes_[name] = value;
}

void XMLNode::add_attribute(const std::string& name, unsigned int value)
{
  std::stringstream ss;
  ss << value;
  attributes_[name] = ss.str();
}

std::string XMLNode::attribute(const std::string& name) const 
{
  attribute_map::const_iterator iter;
  if ((iter = attributes_.find(name)) != attributes_.end())
  {
    return iter->second;
  }
  return "";
}

// }}}

} // namespace

/* vim: set cindent sw=2 expandtab foldmethod=marker : */


#include "xmlnodetests.h"
#include "../xmlnode.h"

using namespace xml;

namespace unittests
{

TEST_CASE(xmlnode_test_constructors)
void test_one_node(const XMLNode& node)
{
  ASSERT_EQ(static_cast<int>(node.indent()), 0);
  ASSERT_EQ(static_cast<int>(node.size()), 0);
  ASSERT_TRUE(node.data().empty());
}

virtual bool run()
{
  XMLNode node;
  ASSERT_TRUE(node.is_data_node());
  test_one_node(node);
  XMLNode node2("root");
  ASSERT_FALSE(node2.is_data_node());
  test_one_node(node2);
  return true;
}
END_CASE;

void XMLNodeTests::init()
{
}

void XMLNodeTests::destroy()
{
}

void XMLNodeTests::load_cases()
{
  ADD_TEST_CASE(xmlnode_test_constructors);
}

} // namespace

DEFINE_ADD_TO_RUNNER(XMLNodeTests);

/* vim: set cindent sw=2 expandtab : */


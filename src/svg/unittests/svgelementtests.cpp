#include "svgelementtests.h"
#include "../svgelement.h"
#include "../defs.h"
#include "../g.h"
#include "../line.h"
#include "../text.h"
#include "../use.h"
#include "xml/xmlnode.h"
#include <sstream>
/*
   The best way to test any of these would have been to create the xml and then parse it back as xml and look at the node contents. This however will require an xml parsing library, and it seemed like an overkill, this decision could always be reversed if needed.
 */
using namespace svg;
using namespace xml;
namespace unittests
{

TEST_CASE(svg_element_test_tag)

const std::string tag = "ATAG"; 

virtual bool run()
{
  SVGElement el(tag);
  // Not strickly needed here, as we could get the tag from the svg...
  XMLNode* nd = &el;
  ASSERT_EQ(nd->tag(), tag);
  return true;
}
END_CASE;

TEST_CASE(svg_element_test_add_style)
const std::string tag = "ATAG"; 
const std::string style_name = "myStyle";
const std::string style_value = "myStyleValue";
const std::string constructed = "<" + tag + " style=\"" + style_name + ": " + style_value + "\"/>";

virtual bool run()
{
  SVGElement el(tag);
  el.add_style(style_name, style_value);
  std::stringstream ss;
  ss << el;
  ASSERT_EQ(ss.str().substr(0, 30), constructed.substr(0, 30));

  return true;
}
END_CASE;

TEST_CASE(svg_element_test_stroke)
const std::string tag = "ATAG"; 
const std::string style_name = "stroke";
const std::string style_value = "grey";
const std::string constructed = "<" + tag + " style=\"" + style_name + ": " + style_value + "\"/>";

virtual bool run()
{
  SVGElement el(tag);
  // A stroke is stored internally as a style with the name stroke
  el.stroke(style_value);
  std::stringstream ss;
  ss << el;
  ASSERT_EQ(ss.str().substr(0, 25), constructed.substr(0, 25));

  return true;
}
END_CASE;

TEST_CASE(svg_defs_test_tag)
const std::string TAG = "defs";
virtual bool run()
{
  Defs defs;

  ASSERT_EQ(defs.tag(), TAG);

  return true;
}
END_CASE;

TEST_CASE(svg_g_test_tag)
const std::string TAG = "g";
const std::string contents = "<g/>";
const std::string id = "MyID";
virtual bool run()
{
  G g;

  ASSERT_EQ(g.tag(), TAG);
  std::stringstream ss;
  ss << g;
  ASSERT_EQ(ss.str().substr(0,3), contents.substr(0,3));

  G g2(id);
  ASSERT_EQ(g2.attribute("id"), id);
  return true;
}
END_CASE;

TEST_CASE(svg_g_test_title)
const std::string id = "MyID";
const std::string title = "My Title";
const std::string expected = "title";
virtual bool run()
{
  G g(id);
  g.add_title(title);
  ASSERT_EQ(g.size(), 1u);
  ASSERT_EQ(g[0].tag(), expected);
  ASSERT_TRUE(g[0][0].is_data_node());
  ASSERT_EQ(g[0][0].data(), title);
  return true;
}
END_CASE;

TEST_CASE(svg_g_test_descrption)
const std::string id = "MyID";
const std::string description = "Just cause we want a description";
const std::string expected = "desc";
virtual bool run()
{
  G g(id);
  g.add_decription(description);
  ASSERT_EQ(g.size(), 1u);
  ASSERT_EQ(g[0].tag(), expected);
  ASSERT_TRUE(g[0][0].is_data_node());
  ASSERT_EQ(g[0][0].data(), description);
  return true;
}
END_CASE;

TEST_CASE(svg_line_test)
const int from_x = 13;
const int from_y = 54;
const int to_x = 98;
const int to_y = 45;
const std::string TAG = "line";
virtual bool run()
{
  Line l(from_x, from_y, to_x, to_y);
  ASSERT_EQ(l.tag(), TAG);

  ASSERT_EQ(atoi(l.attribute("x1").c_str()), from_x);
  ASSERT_EQ(atoi(l.attribute("y1").c_str()), from_y);
  ASSERT_EQ(atoi(l.attribute("x2").c_str()), to_x);
  ASSERT_EQ(atoi(l.attribute("y2").c_str()), to_y);
  return true;
}
END_CASE;

TEST_CASE(svg_text_test_tag)
const std::string TAG = "text";
virtual bool run()
{
  Text t;
  ASSERT_EQ(t.tag(), TAG);
  return true;
}
END_CASE;

TEST_CASE(svg_text_test_location)
const int x = 20;
const int y = 45;
virtual bool run()
{
  Text t;
  t.set_location(x, y);
  ASSERT_EQ(atoi(t.attribute("x").c_str()), x);
  ASSERT_EQ(atoi(t.attribute("y").c_str()), y);
  return true;
}
END_CASE;

TEST_CASE(svg_text_test_contents)
const std::string initial_contents = "Initial contents";
const std::string more_contents = "More contents";
virtual bool run()
{
  Text t(initial_contents);
  ASSERT_EQ(t.size(), 1u);
  ASSERT_TRUE(t[0].is_data_node());
  ASSERT_EQ(t[0].data(), initial_contents);
  t.add_text(more_contents);
  ASSERT_EQ(t.size(), 2u);
  ASSERT_TRUE(t[1].is_data_node());
  ASSERT_EQ(t[1].data(), more_contents);

  return true;
}
END_CASE;

TEST_CASE(svg_use_test)
const std::string TAG = "use";
const int x = 20;
const int y = 45;
const std::string id = "MyID";
virtual bool run()
{
  Use u(id, x, y);
  ASSERT_EQ(u.tag(), TAG);
  ASSERT_EQ(atoi(u.attribute("x").c_str()), x);
  ASSERT_EQ(atoi(u.attribute("y").c_str()), y);
  ASSERT_EQ(u.attribute("xlink:href"), "#" + id);
  return true;
}
END_CASE;

void SVGElementTests::init()
{
}

void SVGElementTests::destroy()
{
}

void SVGElementTests::load_cases()
{
  ADD_TEST_CASE(svg_element_test_tag);
  ADD_TEST_CASE(svg_element_test_add_style);
  ADD_TEST_CASE(svg_element_test_stroke);
  ADD_TEST_CASE(svg_defs_test_tag);
  ADD_TEST_CASE(svg_g_test_tag);
  ADD_TEST_CASE(svg_g_test_title);
  ADD_TEST_CASE(svg_g_test_descrption);
  ADD_TEST_CASE(svg_line_test);
  ADD_TEST_CASE(svg_text_test_tag);
  ADD_TEST_CASE(svg_text_test_location);
  ADD_TEST_CASE(svg_text_test_contents);
  ADD_TEST_CASE(svg_use_test);
}

} // namespace

DEFINE_ADD_TO_RUNNER(SVGElementTests);

/* vim: set cindent sw=2 expandtab : */


#include "svgfonttests.h"
#include "../font.h"
#include "../svgelement.h"
#include <sstream>
/*
   The best way to test any of these would have been to create the xml and then parse it back as xml and look at the node contents. This however will require an xml parsing library, and it seemed like an overkill, this decision could always be reversed if needed.
 */

#include <iostream>
using namespace std;

using namespace svg;
namespace unittests
{

TEST_CASE(svg_font_test_family)
const std::string TAG = "MyTag";
const std::string expected = "<" + TAG + " style=\"font-family: serif; font-size: 12\"/>";
virtual bool run()
{
  SVGElement element(TAG);
  Font f;
  f.apply(element);
  std::stringstream ss;
  ss << element;
  ASSERT_EQ(ss.str().substr(0, 45), expected.substr(0, 45));

  return true;
}
END_CASE;

void SVGFontTests::init()
{
}

void SVGFontTests::destroy()
{
}

void SVGFontTests::load_cases()
{
  ADD_TEST_CASE(svg_font_test_family);
}

} // namespace

DEFINE_ADD_TO_RUNNER(SVGFontTests);

/* vim: set cindent sw=2 expandtab : */


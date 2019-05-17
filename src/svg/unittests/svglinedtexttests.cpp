#include "svglinedtexttests.h"
#include "../linedtext.h"
#include "../svgelement.h"
#include "xml/xmlnode.h"


#include <iostream>
using namespace std;

using namespace svg;
namespace unittests
{

TEST_CASE(svg_lined_text_test_length)
const std::string the_text = "To be, or not to be, that is the question: \
Whether 'tis nobler in the mind to suffer \
The slings and arrows of outrageous fortune, \
Or to take arms against a sea of troubles \
And by opposing end them. To die—to sleep, \
No more; and by a sleep to say we end \
The heart-ache and the thousand natural shocks \
That flesh is heir to: 'tis a consummation \
Devoutly to be wish'd. To die, to sleep; \
To sleep, perchance to dream—ay, there's the rub: \
For in that sleep of death what dreams may come, \
When we have shuffled off this mortal coil, \
Must give us pause—there's the respect \
That makes calamity of so long life.";
const int line_limit = 40;
const std::string font_family = "serif";
const int font_size = 16;
const std::string TAG = "tag";
const std::string text_tag = "text";
virtual bool run()
{
  LinedText txt(the_text, line_limit);

  txt.set_font(font_family, font_size);
  txt.hide_bg_lines();
  SVGElement node(TAG);
  txt.print(node);
  cout << node << endl;
  ASSERT_EQ(node.size(), 19u);
  for (int i = 0; i < node.size(); ++i)
  {
    ASSERT_EQ(node[i].tag(), text_tag);
  }
  return true;
}
END_CASE;

void SVGLinedTextTests::init()
{
}

void SVGLinedTextTests::destroy()
{
}

void SVGLinedTextTests::load_cases()
{
  ADD_TEST_CASE(svg_lined_text_test_length);
}

} // namespace

DEFINE_ADD_TO_RUNNER(SVGLinedTextTests);

/* vim: set cindent sw=2 expandtab : */


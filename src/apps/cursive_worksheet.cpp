#include "svg/font.h"
#include "svg/line.h"
#include "svg/text.h"
#include "xml/xmlnode.h"
#include "svg/linedtext.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <random>

/**
  \defgroup cursive_worksheet The cursive worksheet application
  \brief Generate cursive worksheets

  This application will generate a single page, with the following contents:
  \li A line with a randomly picked letter to be practiced in both tracing and free writing
  \li A sentence, written in cursive, which can be used for tracing and as an example for what it should look like in cursive
  \li The same sentence, not in cursive, to help in reading the sentence
  \li a line with random combination of letters to be traced. This is very good for practicing transitioning between letters
  \li two lines, each with a word, in cursive, which can be used for tracing, and the rest of the line can be used for free writing

  <h2>Running</h2>
  It's as simple as
  \code
  ./cursive_worksheet.exe
  \endcode

  <h2>The data used</h2>
  The data used for the sentences and words is located in the files `assets/proverbs.txt` and `assets/word_list.txt` respectively. These files are loaded, during compilation via `#include "word_list.txt"`, and so must be a syntactically valid header file.

  The contents of these files is taken from good old google, the word list is a list of commonly used words, and the proverbs file is a list of 1000 known proverbs (well, someone knows all of them, none of us do ;-) ).

  NB: The svg generated is designed to work with the font `5th grade cursive-italics`. 
  */
#define CURSIVE_FONT "5th grade cursive-italics"
#define CWS_VERSION_3

const char* proverbs_[] = {
#include "proverbs.txt"
};
#define PROVERB_COUNT (sizeof(proverbs_) / sizeof(proverbs_[0]))

const char* words_[] = 
{
#include "word_list.txt"
};
#define WORD_COUNT (sizeof(words_) / sizeof(words_[0]))

using namespace std;
using namespace xml;
using namespace svg;

void print_header(ostream& stream);
void generate_page(XMLNode& node, const string& phrase, char c);

int main(int argc, char** argv)
{
  XMLNode root("svg");
  root.add_attribute("width", 600);
  root.add_attribute("height", 800);
  root.add_attribute("xmlns", "http://www.w3.org/2000/svg");

  uniform_int_distribution<> proverbs_distribution(0, PROVERB_COUNT);
  random_device rd;
  mt19937 gen(rd());

  char c('l');
  if (argc > 1)
  {
    c = argv[1][0];
  }
  else
  {
    uniform_int_distribution<> char_distribution('a', 'z');
    c = char_distribution(gen);
  }

  string phrase(proverbs_[proverbs_distribution(gen)]);
  std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
  generate_page(root, phrase, c);
  
  print_header(cout);
  cout << root << endl;
}

// {{{ macros
#define X_START 10
#define X_END 800
#define TOP_LINE 10
#define TRACE_TOP_LINE 200
#define CURSIVE_FONT_SIZE 34
#define LETTER_HEIGHT (CURSIVE_FONT_SIZE >> 1)
#define LINE_SPACE CURSIVE_FONT_SIZE
#define SKIP (LINE_SPACE + LETTER_HEIGHT)
// }}}

// {{{ Forward declerations
void add_phrase_bg_lines(XMLNode& node);
void add_tracing_bg_lines(XMLNode& node);
void add_cursive_phrase(XMLNode& node, const std::string& phrase);
void add_normal_phrase(XMLNode& node, const std::string& phrase);
void add_trace(XMLNode& node, char c);
void generate_random_letters(std::string& ret);
void long_letter_trace_generator(std::string& str);
void generate_random_word(std::string& str);
void add_letter_trace(XMLNode& node);
void add_word_trace(XMLNode& node);
// }}}

// this is the first version, the page had a phrase and 3 lines of 
// letters to be traced
#if defined(CWS_VERSION_1)
void generate_page(XMLNode& node, const string& phrase, char c)
{
  add_phrase_bg_lines(node);
  add_tracing_bg_lines(node);
  add_cursive_phrase(node, phrase);
  add_normal_phrase(node, phrase);
  add_trace(node, c);
}
#elif defined(CWS_VERSION_2)
void generate_page(XMLNode& node, const string& phrase, char c)
{
  add_phrase_bg_lines(node);
  add_tracing_bg_lines(node);
  add_cursive_phrase(node, phrase);
  add_normal_phrase(node, phrase);
  add_letter_trace(node);
  add_word_trace(node);
}
#elif defined(CWS_VERSION_3)
void generate_page(XMLNode& node, const string& phrase, char c)
{
  unsigned int next_y(TOP_LINE);
  std::string str;
  long_letter_trace_generator(str);
  LinedText letters(str);
  letters.add_text_style("letter-spacing", "5pt");
  letters.set_font(CURSIVE_FONT, CURSIVE_FONT_SIZE)->set_style("italic");
  letters.set_y_offset(next_y);
  next_y = letters.print(node) + CURSIVE_FONT_SIZE;

  LinedText lt(phrase);
  lt.set_font(CURSIVE_FONT, CURSIVE_FONT_SIZE)->set_style("italic");
  lt.set_y_offset(next_y);
  next_y = lt.print(node, "rgb(200, 200, 200)") + 10;

  LinedText normal(phrase);
  normal.set_font("sans-serif", CURSIVE_FONT_SIZE)->set_weight("bold");
  normal.set_y_offset(next_y);
  normal.hide_bg_lines();
  next_y = normal.print(node, "black") + CURSIVE_FONT_SIZE;

  generate_random_letters(str);
  LinedText letter_trace(str);
  letter_trace.set_font(CURSIVE_FONT, CURSIVE_FONT_SIZE)->set_style("italic");
  letter_trace.set_y_offset(next_y);
  next_y = letter_trace.print(node) + CURSIVE_FONT_SIZE;

  generate_random_word(str);
  LinedText word1(str);
  word1.set_font(CURSIVE_FONT, CURSIVE_FONT_SIZE)->set_style("italic");
  word1.set_y_offset(next_y);
  next_y = word1.print(node);

  generate_random_word(str);
  LinedText word2(str);
  word2.set_font(CURSIVE_FONT, CURSIVE_FONT_SIZE)->set_style("italic");
  word2.set_y_offset(next_y);
  next_y = word2.print(node);
}
#endif

// {{{ Lines
Line* add_line(XMLNode& node, int x1, int y1, int x2, int y2)
{
  Line* line = new Line(x1, y1, x2, y2);
  node.add_child(line);
  return line;
}

void line_style(Line* line)
{
  line->stroke("gray");
  line->add_style("stroke-width", 1);
}

// {{{ Add lines in batch
void add_bg_lines(XMLNode& node, int top_line)
{

  Line* line;
  int y(top_line);
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += LINE_SPACE;
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += LETTER_HEIGHT;
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += LINE_SPACE;
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
}
// }}}

// {{{ phrase bg lines
void add_phrase_bg_lines(XMLNode& node)
{
  add_bg_lines(node, TOP_LINE);
}
// }}}

// {{{ tracing bg lines
void add_tracing_bg_lines(XMLNode& node)
{
  add_bg_lines(node, TRACE_TOP_LINE);
  add_bg_lines(node, TRACE_TOP_LINE + SKIP);
  add_bg_lines(node, TRACE_TOP_LINE + 2 * (SKIP));
}
// }}}

//}}}

// {{{ Text

int y_offset(int top_line)
{
  return top_line + LINE_SPACE + LETTER_HEIGHT;
}

void trace_style(Text* text, const string& fill="none")
{
  text->stroke("black");
  text->add_style("stroke-width", "0.1");
  text->add_style("fill", fill);
}

// {{{ cursive phrase
void add_cursive_phrase(XMLNode& node, const std::string& phrase)
{
  Font f(CURSIVE_FONT, CURSIVE_FONT_SIZE);
  f.set_style("italic");
  Text* text = new Text(phrase);
  f.apply(*text);
  trace_style(text, "rgb(200, 200, 200)");
  text->set_location(X_START + 5, y_offset(TOP_LINE));
  node.add_child(text);
}
// }}}

// {{{ Normal phrase
void add_normal_phrase(XMLNode& node, const std::string& phrase)
{
  Font f("sans-serif", CURSIVE_FONT_SIZE);
  f.set_weight("bold");
  Text* text = new Text(phrase);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TOP_LINE + 3 * LINE_SPACE));
  node.add_child(text);
}
// }}}

// {{{ Trace
string range(char c, char fro, char to)
{
  stringstream ss;
  for (int i = fro; i <= to; ++i)
  {
    ss << c << static_cast<char>(i) << ' ';
  }
  return ss.str();
}

void add_trace(XMLNode& node, char c)
{
  Font f(CURSIVE_FONT, CURSIVE_FONT_SIZE);
  f.set_style("italic");
  
  string str(range(c, 'a', 'j'));
  Text* text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE));
  trace_style(text);
  node.add_child(text);

  str = range(c, 'k', 't');
  text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE + SKIP));
  trace_style(text);
  node.add_child(text);

  str = range(c, 'u', 'z');
  text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE + 2 * (SKIP)));
  trace_style(text);
  node.add_child(text);
}
// }}}

// }}}

// {{{ version 2 functions

void generate_random_letters(std::string& ret)
{
  uniform_int_distribution<> char_dist(0, 25);
  random_device rd;
  mt19937 gen(rd());
  ret.clear();
  ret.reserve(40);
  char first, second;
  first = char_dist(gen);
  second = char_dist(gen);
  for (int i = 0; i < 10; ++i)
  {
    ret += static_cast<char>(char_dist(gen) + 'a');
    ret += static_cast<char>(char_dist(gen) + 'a');
    ret += ' ';
  }
}

// {{{ letters for warmup tracing
static const char letters[] = {'l', 'k', 'b', 'h', 'f', 't'};
const unsigned int letters_count(sizeof(letters) / sizeof(letters[0]));
const int llcount(3);
// }}}

void long_letter_trace_generator(std::string& str)
{
  uniform_int_distribution<> char_dist(0, letters_count - 1);
  random_device rd;
  mt19937 gen(rd());
  str.clear();
  str.reserve(llcount);
  char c(letters[char_dist(gen)]);

  for (int i = 0; i < llcount; ++i)
  {
    str += c;
  }
}

void generate_random_word(std::string& str)
{
  uniform_int_distribution<> words_distribution(0, WORD_COUNT);
  random_device rd;
  mt19937 gen(rd());
  str = words_[words_distribution(gen)];
}

void add_letter_trace(XMLNode& node)
{
  Font f(CURSIVE_FONT, CURSIVE_FONT_SIZE);
  f.set_style("italic");
  std::string str;
  generate_random_letters(str);
  Text* text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE));
  trace_style(text);
  node.add_child(text);
}

void add_word_trace(XMLNode& node)
{
  Font f(CURSIVE_FONT, CURSIVE_FONT_SIZE);
  f.set_style("italic");

  string str;
  generate_random_word(str);
  Text* text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE + SKIP));
  trace_style(text);
  node.add_child(text);

  generate_random_word(str);
  text = new Text(str);
  f.apply(*text);
  text->set_location(X_START + 5, y_offset(TRACE_TOP_LINE + 2 * (SKIP)));
  trace_style(text);
  node.add_child(text);
}

// }}}

#define XML_HEADER "<?xml version=\"1.0\"?>"
#define XML_DOCTYPE "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" \
    " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" 

void print_header(ostream& stream)
{
  stream << XML_HEADER << endl;
  stream << XML_DOCTYPE << endl;
}

/* vim: set cindent sw=2 expandtab foldmethod=marker : */


#include "linedtext.h"
#include <cctype>

namespace svg
{

#define DEFAULT_LIMIT 35
#define X_START 10
#define X_END 800

unsigned int LinedText::default_limit(DEFAULT_LIMIT);
LinedText::LinedText(const std::string& text, unsigned int char_count) :
  text_(text), limit_(char_count), line_count_(text_.size() / limit_),
  font_(NULL), bg_lines_(true)
{
}

LinedText::~LinedText()
{
  if (font_)
  {
    delete font_;
  }
}

Font* LinedText::set_font(const std::string& family, int size)
{
  if (font_)
  {
    delete font_;
  }
  font_ = new Font(family, size);
  font_size_ = size;
  return font_;
}

Line* LinedText::add_line(XMLNode& node, int x1, int y1, int x2, int y2)
{
  Line* line = new Line(x1, y1, x2, y2);
  node.add_child(line);
  return line;
}

unsigned int LinedText::letter_height()
{
  return font_size_ >> 1;
}

unsigned int LinedText::line_space()
{
  return font_size_;
}

unsigned int LinedText::skip()
{
  return font_size_ + letter_height();
}

void LinedText::trace_style(Text* text, const std::string& fill)
{
  text->stroke("black");
  text->add_style("stroke-width", "0.1");
  text->add_style("fill", fill);
}

void LinedText::line_style(Line* line)
{
  line->stroke("gray");
  line->add_style("stroke-width", 1);
}

unsigned int LinedText::y_offset(unsigned int off)
{
  return off + line_space() + letter_height();
}

void LinedText::set_y_offset(unsigned int off)
{
  y_offset_ = off;
}

void LinedText::display_lines()
{
  bg_lines_ = true;
}

void LinedText::hide_bg_lines()
{
  bg_lines_ = false;
}

void LinedText::add_bg_line(XMLNode& node, unsigned int off)
{
  if (!bg_lines_)
  {
    return;
  }
  Line* line;
  int y(off);
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += line_space();
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += letter_height();
  line = add_line(node, X_START, y, X_END, y);
  line_style(line);
  y += line_space();;
  line = add_line(node, X_START, y, X_END, y);
}

void LinedText::add_text_style(const std::string& name, const std::string& val)
{
  text_style_[name] = val;
}

void LinedText::print_one_line(XMLNode& node, unsigned int off,
    const std::string& txt, const std::string& fill)
{
  typedef std::map<std::string, std::string> string_map;
  add_bg_line(node, off);
  Text* text = new Text(txt);
  for (string_map::const_iterator ci = text_style_.cbegin();
      ci != text_style_.cend(); ++ci)
  {
    text->add_style(ci->first, ci->second);
  }
  font_->apply(*text);
  trace_style(text, fill);
  text->set_location(X_START + 5, y_offset(off));
  node.add_child(text);
}

unsigned int LinedText::print(XMLNode& node, const std::string& fill)
{
  size_t text_size(text_.size());
  if (text_size <= limit_)
  {
    print_one_line(node, y_offset_, text_, fill);
    y_offset_ += skip();
    return y_offset_;
  }
  int from(0);
  while (from < text_size)
  {
    int count(limit_);
    if (from + count > text_size)
    {
      count = text_size - from;
      std::string str(text_.substr(from, count));
      print_one_line(node, y_offset_, str, fill);
      y_offset_ += skip();
      return y_offset_;
    }
    while (count > 0 && text_[count] != ' ')
    {
      --count;
    }
    std::string str(text_.substr(from, count));
    print_one_line(node, y_offset_, str, fill);
    y_offset_ += skip();
    from += count;
  }
  return y_offset_;
}

} // namespace

/* vim: set cindent sw=2 expandtab : */


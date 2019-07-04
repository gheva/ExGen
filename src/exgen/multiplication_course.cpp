#include "xgen.h"
#include "mathex.h"
#include "displays/svgdisplay.h"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

using namespace xgen;
using namespace exgen;
using namespace std;
using namespace mathex;
std::vector<unsigned int> know_these;
stringstream known_digits;

void multiply_by_digit_l1(unsigned int digit, const string& base_path, int index, int& page_number, bool help=true, bool practice=false)
{
  stringstream path_builder;
  path_builder << base_path << "/" << ++page_number;
  if (!practice)
  {
    path_builder << "_multiply_by_" << digit << "_level_" << ((help) ? 0 : 1) << "_" << index << ".svg";
  }
  else
  {
    path_builder << "_practice_digits" << known_digits.str() << "_" << index << ".svg";
  }
  string path = path_builder.str();
  unique_ptr<SVGDisplay> display(new SVGDisplay(600, 800, path));
  unique_ptr<Level> l;
  Level::exercise_list list;

  if (help)
  {
    l.reset(new CountBy(digit));
    list = l->generate(1);
    display->show(*(list[0]));
  }
  if (practice)
  {
    l.reset(new MultiplyBy(know_these));
  }
  else
  {
    l.reset(new MultiplyBy(digit, true));
  }
  list = l->generate(12);
  for (int i = 0; i < 12; ++i)
  {
    display->show(*(list[i]));
  }
  display->finalize();
}

void learn_digit(unsigned int digit, const string& base_path, int& page_number)
{
  // Generate the addition to multiplication exercise for this digit
  unique_ptr<Level> l(new PlusToMul(digit));
  stringstream path_builder;
  path_builder << base_path << "/" << ++page_number << "_plus_to_mul_" << digit << ".svg";
  string path = path_builder.str();
  unique_ptr<SVGDisplay> display(new SVGDisplay(600, 800, path));
  Level::exercise_list list = l->generate(10);
  for (int i = 0; i < 10; ++i)
  {
    display->show(*(list[i]));
  }
  display->finalize();
  know_these.push_back(digit);
  known_digits << "_" << digit;

  // Generate multiplication by this digit
  path_builder.str(string());
  path_builder << base_path << "/multiply_by_0_" << digit << ".svg";
  for (int i = 0; i < 3; ++i)
  {
    multiply_by_digit_l1(digit, base_path, i, page_number);
  }
  path_builder.str(string());
  path_builder << base_path << "/multiply_by_1_" << digit << ".svg";
  for (int i = 0; i < 5; ++i)
  {
    multiply_by_digit_l1(digit, base_path, i, page_number, false);
  }
  path_builder.str(string());
  path_builder << base_path << "/practice_up_to_" << digit << ".svg";
  for (int i = 0; i < 5; ++i)
  {
    multiply_by_digit_l1(digit, base_path, i, page_number, false, true);
  }
}

void multiplication_table(const string& base_path)
{
  unique_ptr<Level> l;
  string path;
  unique_ptr<SVGDisplay> display;
  Level::exercise_list list;

  path = base_path + "/multiplication_table.svg";
  display.reset(new SVGDisplay(600, 800, path));
  l.reset(new MulTable);
  list = l->generate(1);
  display->show(*(list[0]));
  display->finalize();
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    cerr << "Usage: " << argv[0] << " path" << endl;
    cerr << "Where path is a path to an existing directoryinto which the exercises will be generated" << endl;
    exit(EXIT_FAILURE);
  }
  int page_number(0);
  string path(argv[1]);
  multiplication_table(path);
  learn_digit(2, path, page_number);
  learn_digit(5, path, page_number);
  learn_digit(9, path, page_number);
  learn_digit(3, path, page_number);
  learn_digit(4, path, page_number);
  learn_digit(6, path, page_number);
  learn_digit(8, path, page_number);
  learn_digit(7, path, page_number);
}

/* vim: set cindent sw=2 expandtab : */


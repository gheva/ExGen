#include "exgen2httpdsl_generator.h"
#include "xgen.h"
#include "mathex.h"
#include "displays/svgdisplay.h"
#include <map>
#include <vector>
#include <sstream>
#include <cstring>
#include "index.html.h"

using namespace std;
using namespace exgen;
using namespace xgen;
using namespace mathex;

static const string index_html{
HTML_HEADER_STRING FORM_HEADER SELECT_SUBJECT " <br> " ADDITION_SELECT_LEVEL SUBTRACTION_SELECT_LEVEL ARITHMETICS_SELECT_LEVEL MULTIPLICATION_SELECT_LEVEL  " <br> " HTML_FOOTER
};

map<string, Topic*> topics{
  {"addition", new mathex::Addition},
  {"subtraction", new mathex::Subtraction},
  {"arithmetic", new mathex::Arithmetic},
  {"multiplication", new mathex::Multiplication},
};

map<string, vector<int> > count_per_subject{
  {"addition", {12, 12, 12, 12, 12}},
  {"subtraction", {12, 12, 12, 12, 12, 12 ,12, 12, 4}},
  {"arithmetic", {12, 12, 12, 12, 10}},
  {"multiplication", {10, 1, 12, 12, 12, 12, 12, 12, 12, 12, 12}},
};

HTTPDSL_REQUEST_STATUS_CODE handle_get(httpdsl_arg* arg)
{
  char* buffer = static_cast<char*>(calloc(index_html.length() + 1, sizeof(char)));
  arg->request->add_resource(arg->request, arg->out_tag, buffer, free);
  strcpy(buffer, index_html.c_str());
  return STATUS_CODE_OK;
}

static const string SUBJECT_PARAM_NAME("subject");
HTTPDSL_REQUEST_STATUS_CODE handle_post(httpdsl_arg* arg)
{
  char* buffer;
  string subject = arg->request->get_param(arg->request, SUBJECT_PARAM_NAME.c_str());
  string level_key = subject + "_level";
  string level = arg->request->get_param(arg->request, level_key.c_str());
  int level_i = atoi(level.c_str());
  Topic* generator(topics[subject]);
  if (generator == nullptr)
  {
    return STATUS_CODE_ERROR;
  }
  Level* level_obj(generator->get_level(level_i));
  if (level_obj == nullptr)
  {
    return STATUS_CODE_ERROR;
  }
  int count(count_per_subject[subject][level_i]);
  Level::exercise_list exe_list = level_obj->generate(count);
  SVGDisplay display(600, 650, "/tmp/exercise.svg");
  for (int i = 0; i < count; ++i)
  {
    display.show(*(exe_list[i]));
  }

  stringstream ss;
  ss << HTML_HEADER_STRING;
  display.stream(ss);
  ss << FORM_HEADER SELECT_SUBJECT " <br> " ADDITION_SELECT_LEVEL SUBTRACTION_SELECT_LEVEL ARITHMETICS_SELECT_LEVEL MULTIPLICATION_SELECT_LEVEL  " <br> " HTML_FOOTER;
  string payload = ss.str();

  buffer = static_cast<char*>(calloc(payload.length() + 1, sizeof(char)));
  arg->request->add_resource(arg->request, arg->out_tag, buffer, free);
  strcpy(buffer, payload.c_str());
  return STATUS_CODE_OK;
}

/* vim: set cindent sw=2 expandtab : */


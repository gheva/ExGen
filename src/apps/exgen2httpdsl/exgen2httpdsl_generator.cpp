#include "exgen2httpdsl_generator.h"
#include "xgen.h"
#include "mathex.h"
#include "displays/svgdisplay.h"
#include <map>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;
using namespace exgen;
using namespace xgen;
using namespace mathex;

map<string, Topic*> topics{
  {"addition", new Addition},
  {"subtraction", new Subtraction},
  {"arithmetic", new Arithmetic},
  {"multiplication", new Multiplication},
};

map<string, vector<int> > count_per_subject{
  {"addition", {10, 10, 10}},
  {"subtraction", {10, 10, 10}},
  {"arithmetic", {10, 10, 10}},
  {"multiplication", {10, 10, 10}},
};

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
  int count(count_per_subject[subject][level_i - 1]);
  Level::exercise_list exe_list = level_obj->generate(count);
  SVGDisplay display(600, 800, "/tmp/exercise.svg");
  for (int i = 0; i < count; ++i)
  {
    display.show(*(exe_list[i]));
  }

  stringstream ss;
  display.stream(ss);
  string payload = ss.str();

  buffer = static_cast<char*>(calloc(payload.length() + 1, sizeof(char)));
  arg->request->add_resource(arg->request, arg->out_tag, buffer, free);
  strcpy(buffer, payload.c_str());
  return STATUS_CODE_OK;
}


/* vim: set cindent sw=2 expandtab : */


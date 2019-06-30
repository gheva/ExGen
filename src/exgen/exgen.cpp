#include <cstdlib>
#include <iostream>
#include <map>
#include "xgen.h"
#include "mathex.h"
#include "displays/svgdisplay.h"

/**
  \defgroup exgen ExGen - Exercise Generator
  \brief This application generates exercise worksheets as svg documents
  */
#include <iostream>

#define REQUIRED_ARG_COUNT 5
using namespace std;
using namespace exgen;
using namespace xgen;
using namespace mathex;

map<string, Topic*> topics{
  {"Addition", new Addition},
  {"Subtraction", new Subtraction},
  {"Arithmetic", new Arithmetic},
  {"Multiplication", new Multiplication},
};

void usage(const char* name)
{
  cout << "Generate exercises to the given file" << endl;
  cout << "Currnetly we have the following topics:\n"
    "Addition, Subtraction, Arithmetic, Multiplication\n";
  cout << "Example:\n" << name << " Multiplication 10 12 ~/mul1\n"
    "Will generate exercises into files named ~/mul1_<number>.svg if a single page is all that is neded, a single file named ~/mul1_0.svg is created" << endl;
  exit(EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
  if (argc < REQUIRED_ARG_COUNT && argv[1][0] == '-')
  {
    if (argv[1][1] == 'h')
    {
      usage(argv[0]);
    }
  }
  if (argc < REQUIRED_ARG_COUNT)
  {
    cerr << "Usage: " << argv[0] << " TOPIC LEVEL COUNT PATH" << endl;
    cerr << "For advanced info use " << argv[0] << " -h" << endl;
    exit(EXIT_FAILURE);
  }
  const char* topic(argv[1]);
  int level(atoi(argv[2]));
  int count(atoi(argv[3]));
  std::string path(argv[4]);
  if (argc >= 5)
  {
    path = argv[4];
  }
  Topic* t = topics[topic];
  if (!t)
  {
    cerr << "Unknown topic " << topic << endl;
    exit(EXIT_FAILURE);
  }
  Level* l = t->get_level(level);
  if (!l)
  {
    cerr << "Level " << level << " does not exist yet" << endl; 
    exit(EXIT_FAILURE);
  }

  SVGDisplay display(600, 800, path);
  Level::exercise_list list = l->generate(count);
  for (int i = 0; i < count; ++i)
  {
    display.show(*(list[i]));
  }
  display.finalize();

  exit(EXIT_SUCCESS);
}

/* vim: set cindent sw=2 expandtab : */


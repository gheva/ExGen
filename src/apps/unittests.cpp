#include <iostream>
#include "ut/unittests.h"
#include "ut/stdoutlogger.h"

#include "xml/unittests/xmlnodetests.h"

/**
  \defgroup unittests The unittests app
  \brief Run the unittests

  You can run either all the unittests, by running the unittests application with no arguments, or you can run a single suite by passing it's name as a command line arguments.

  \code
  Usage: unittests suite1_name suite2_name ...
  \endcode
  */
using namespace unittests;
int main(int argc, char** argv)
{
  StdoutLogger logger;
  TestRunner runner(&logger);
  CALL_ADD_TO_RUNNER(XMLNodeTests, &runner);

  if (argc > 1)
  {
    for (int i = 1; i < argc; ++i)
    {
      runner.run(argv[i]);
    }
  }
  else
  {
    runner.run();
  }

}

/* vim: set cindent sw=2 expandtab : */


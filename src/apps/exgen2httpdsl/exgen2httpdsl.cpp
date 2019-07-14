#include <aws/lambda-runtime/runtime.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include "httpdsl.h"
#include "exgen2httpdsl_config.h"

using namespace std;
using namespace aws::lambda_runtime;

void cleanup_server(serverless& server)
{
  httpdsl_server_release(&server);
}

static invocation_response handle_request(invocation_request const& req, serverless& server)
{
  void* ptr = httpdsl_server_handle_request(&server, const_cast<invocation_request*>(&req));
  if (ptr == nullptr)
  {
    return invocation_response::failure("Unknown error", "application/json");
  }
  return invocation_response::success(static_cast<char*>(ptr), "application/json");
}

int main(int argc, char** argv)
{
  serverless server_;
  init_server(server_);

  auto handler_fn = [&server_](aws::lambda_runtime::invocation_request const& req) {
    return handle_request(req, server_);
  };
  run_handler(handler_fn);
}

/* vim: set cindent sw=2 expandtab : */


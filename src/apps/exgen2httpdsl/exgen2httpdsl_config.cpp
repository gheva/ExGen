#include "exgen2httpdsl_config.h"
#include <aws/lambda-runtime/runtime.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <memory/umap_session.h>
#include <aws/lambda/lambdarequest.h>
#include <string>

using namespace std;
using namespace aws::lambda_runtime;

static const string statusCode("statusCode");
static const string Content_type("Content-type");
static const string text_html("text/html");
static const string headers("headers");
static const string body("body");
static const string response_text_resource("response_text");
static const string index_html{
#include "index.html.h"
};

#ifdef __cplusplus
extern "C" {
#endif

static void release_string(void* str)
{
  if (str == nullptr)
  {
    return;
  }
  std::string* s = static_cast<std::string*>(str);
  delete s;
}

void* static_server_respond(httpdsl_request* request)
{
  using namespace Aws::Utils::Json;

  JsonValue response;
  response.WithInteger(statusCode, 200);
  JsonValue headers_obj;
  headers_obj.WithString(Content_type, text_html);
  response.WithObject(headers, headers_obj);
  const char* pl = request->get_payload(request);
  if (pl == nullptr)
  {
    response.WithString(body, "Better luck next time");
  }
  else
  {
    string s(pl);
    response.WithString(body, s);
  }

  std::string* response_string = new std::string(response.View().WriteReadable(true));
  int stat = request->add_resource(request, response_text_resource.c_str(), response_string, release_string);
  if (stat == 0) // Could not add the resource the resource is freed for us
  {
    return nullptr;
  }

  return const_cast<char*>(response_string->c_str());
}

/*
 * This is very hacky. The intention is to have the server, after loading the data, we should iterate over modules. for the POC, we are going to use the data getter as the only method, which will take care of all data
 */
HTTPDSL_REQUEST_STATUS_CODE do_work(httpdsl_arg* arg, void* priv)
{
  char* buffer;
  int stat = 7;//arg->request->add_resource(arg->request, arg->out_tag, buffer, free);

  arg->request->set_status(arg->request, 200);
  arg->request->add_header(arg->request, Content_type.c_str(), text_html.c_str());

  // We were unable to add the resource
  if (stat == 0)
  {
    // TODO we must change this to a meaningful code
    return STATUS_CODE_ERROR;
  }

  unsigned long long method(arg->request->get_method(arg->request));

  switch (method)
  {
  case HTTP_GET:
    buffer = static_cast<char*>(calloc(index_html.length() + 1, sizeof(char)));
    arg->request->add_resource(arg->request, arg->out_tag, buffer, free);
    strcpy(buffer, index_html.c_str());
    break;
  case HTTP_POST:
    buffer = static_cast<char*>(calloc(1024, sizeof(char)));
    arg->request->add_resource(arg->request, arg->out_tag, buffer, free);
    strcpy(buffer, "It's a post");
    break;
  default:
    strcpy(buffer, "This is kinda cool");
    break;
  }

  return STATUS_CODE_OK;
}

HTTPDSL_REQUEST_STATUS_CODE exgen_storage_init(httpdsl_storage* module)
{
  return STATUS_CODE_OK;
}

#ifdef __cplusplus
} // extern "C"
#endif

void init_server(serverless& server)
{
  server.configuration.request_init = lambda_request_init;
  server.configuration.request_respond = lambda_request_respond;

  set_session_umap(server);
  server.configuration.storage_modules = nullptr;

  server.configuration.storage_modules = new httpdsl_storage*[2];
  server.configuration.storage_modules[0] = new httpdsl_storage;
  server.configuration.storage_modules[0]->regex = ".*" ;
  server.configuration.storage_modules[0]->init = exgen_storage_init;
  server.configuration.storage_modules[0]->get = do_work;
  // The list is null terminated
  server.configuration.storage_modules[1] = nullptr;

  httpdsl_server_init(&server);
}

/* vim: set cindent sw=2 expandtab : */


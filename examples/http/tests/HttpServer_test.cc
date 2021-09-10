#include "../HttpServer.h"
#include "../HttpRequest.h"
#include "../HttpResponse.h"
#include "libnet/net/EventLoop.h"
#include "libnet/base/Logging.h"

#include <iostream>
#include <map>

using namespace libnet;
using namespace libnet::net;

bool benchmark = false;

void onRequest(const HttpRequest& req, HttpResponse* resp)
{
  std::cout << "Headers " << req.methodString() << " " << req.path() << std::endl;
  if (!benchmark)
  {
    const std::map<string, string>& headers = req.headers();
    for (const auto& header : headers)
    {
      std::cout << header.first << ": " << header.second << std::endl;
    }
  }

  if (req.path() == "/")
  {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/html");
    resp->addHeader("Server", "Muduo");
    string now = Timestamp::now().toFormattedString();
    resp->setBody("<html><head><title>This is title</title></head>"
        "<body><h1>Hello</h1>Now is " + now +
        "</body></html>");
  }
  else if (req.path() == "/hello")
  {
    resp->setStatusCode(HttpResponse::k200Ok);
    resp->setStatusMessage("OK");
    resp->setContentType("text/plain");
    resp->addHeader("Server", "Muduo");
    resp->setBody("hello, world!\n");
  }
  else
  {
    resp->setStatusCode(HttpResponse::k404NotFound);
    resp->setStatusMessage("Not Found");
    resp->setCloseConnection(true);
  }
}
int main(int argc, char* argv[])
{
  int numThreads = 0;
  if (argc > 1)
  {
    benchmark = true;
    Logger::setLogLevel(Logger::WARN);
    numThreads = atoi(argv[1]);
  }
  EventLoop loop;
  HttpServer server(&loop, InetAddress(8000), "dummy");
  server.setHttpCallback(onRequest);
  server.setThreadNum(numThreads);
  server.start();
  loop.loop();
}

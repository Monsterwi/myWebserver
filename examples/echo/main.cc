#include "examples/echo/echo.h"

#include "libnet/base/Logging.h"
#include "libnet/net/EventLoop.h"

#include <unistd.h>

// using namespace libnet;
// using namespace libnet::net;

int main()
{
  LOG_INFO << "pid = " << getpid();
  libnet::net::EventLoop loop;
  libnet::net::InetAddress listenAddr(2007);
  EchoServer server(&loop, listenAddr);
  server.start();
  loop.loop();
}


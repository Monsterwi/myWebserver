#ifndef LIBNET_EXAMPLES_SIMPLE_ECHO_ECHO_H
#define LIBNET_EXAMPLES_SIMPLE_ECHO_ECHO_H

#include "libnet/net/TcpServer.h"

// RFC 862
class EchoServer
{
 public:
  EchoServer(libnet::net::EventLoop* loop,
             const libnet::net::InetAddress& listenAddr);

  void start();  // calls server_.start();

 private:
  void onConnection(const libnet::net::TcpConnectionPtr& conn);

  void onMessage(const libnet::net::TcpConnectionPtr& conn,
                 libnet::net::Buffer* buf,
                 libnet::Timestamp time);

  libnet::net::TcpServer server_;
};

#endif  // LIBNET_EXAMPLES_SIMPLE_ECHO_ECHO_H

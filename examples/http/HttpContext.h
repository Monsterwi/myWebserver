// This is an internal header file, you should not include this.

#ifndef LIBNET_NET_HTTP_HTTPCONTEXT_H
#define LIBNET_NET_HTTP_HTTPCONTEXT_H


// parse request
#include "libnet/base/copyable.h"

#include "HttpRequest.h"

namespace libnet
{
namespace net
{

class Buffer;

class HttpContext : public libnet::copyable
{
 public:
  enum HttpRequestParseState
  {
    kExpectRequestLine,
    kExpectHeaders,
    kExpectBody,
    kGotAll,
  };

  HttpContext()
    : state_(kExpectRequestLine)
  {
  }

  // default copy-ctor, dtor and assignment are fine

  // return false if any error
  bool parseRequest(Buffer* buf, Timestamp receiveTime);

  bool gotAll() const
  { return state_ == kGotAll; }

  void reset()
  {
    state_ = kExpectRequestLine;
    HttpRequest dummy;
    request_.swap(dummy);
  }

  const HttpRequest& request() const
  { return request_; }

  HttpRequest& request()
  { return request_; }

 private:
  bool processRequestLine(const char* begin, const char* end);

  HttpRequestParseState state_;
  HttpRequest request_;
};

}  // namespace net
}  // namespace libnet

#endif  // LIBNET_NET_HTTP_HTTPCONTEXT_H

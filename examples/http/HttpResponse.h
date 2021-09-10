// This is a public header file, it must only include public header files.

#ifndef LIBNET_NET_HTTP_HTTPRESPONSE_H
#define LIBNET_NET_HTTP_HTTPRESPONSE_H

#include "libnet/base/copyable.h"
#include "libnet/base/Types.h"

#include <map>

// add response information
namespace libnet
{
namespace net
{

class Buffer;
class HttpResponse : public libnet::copyable
{
 public:
  enum HttpStatusCode
  {
    kUnknown,
    k200Ok = 200,
    k301MovedPermanently = 301,
    k400BadRequest = 400,
    k404NotFound = 404,
  };

  explicit HttpResponse(bool close)
    : statusCode_(kUnknown),
      closeConnection_(close)
  {
  }

  void setStatusCode(HttpStatusCode code)
  { statusCode_ = code; }

  void setStatusMessage(const string& message)
  { statusMessage_ = message; }

  void setCloseConnection(bool on)
  { closeConnection_ = on; }

  bool closeConnection() const
  { return closeConnection_; }

  void setContentType(const string& contentType)
  { addHeader("Content-Type", contentType); }

  // FIXME: replace string with StringPiece
  void addHeader(const string& key, const string& value)
  { headers_[key] = value; }

  void setBody(const string& body)
  { body_ = body; }

  void appendToBuffer(Buffer* output) const;

 private:
  std::map<string, string> headers_;
  HttpStatusCode statusCode_;
  // FIXME: add http version
  string statusMessage_;
  bool closeConnection_;
  string body_;
};

}  // namespace net
}  // namespace libnet

#endif  // LIBNET_NET_HTTP_HTTPRESPONSE_H

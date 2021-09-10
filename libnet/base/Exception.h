#ifndef LIBNET_BASE_EXCEPTION_H
#define LIBNET_BASE_EXCEPTION_H

#include "libnet/base/Types.h"
#include <exception>

namespace libnet
{

class Exception : public std::exception
{
 public:
  Exception(string what);
  ~Exception() noexcept override = default;

  // default copy-ctor and operator= are okay.

  const char* what() const noexcept override
  {
    return message_.c_str();
  }

  const char* stackTrace() const noexcept
  {
    return stack_.c_str();
  }

 private:
  string message_;
  string stack_;
};

}  // namespace libnet

#endif  // LIBNET_BASE_EXCEPTION_H

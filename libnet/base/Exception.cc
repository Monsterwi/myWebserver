#include "libnet/base/Exception.h"
#include "libnet/base/CurrentThread.h"

namespace libnet
{

Exception::Exception(string msg)
  : message_(std::move(msg)),
    stack_(CurrentThread::stackTrace(/*demangle=*/false))
{
}

}  // namespace libnet

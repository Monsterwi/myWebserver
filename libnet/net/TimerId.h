// This is a public header file, it must only include public header files.

#ifndef LIBNET_NET_TIMERID_H
#define LIBNET_NET_TIMERID_H

#include "libnet/base/copyable.h"

namespace libnet
{
namespace net
{

class Timer;

///
/// An opaque identifier, for canceling Timer.
///
class TimerId : public libnet::copyable
{
 public:
  TimerId()
    : timer_(NULL),
      sequence_(0)
  {
  }

  TimerId(Timer* timer, int64_t seq)
    : timer_(timer),
      sequence_(seq)
  {
  }

  // default copy-ctor, dtor and assignment are okay

  friend class TimerQueue;

 private:
  Timer* timer_;
  int64_t sequence_;
};

}  // namespace net
}  // namespace libnet

#endif  // LIBNET_NET_TIMERID_H

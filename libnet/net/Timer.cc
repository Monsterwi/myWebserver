// Author: Shuo Chen (chenshuo at chenshuo dot com)

#include "libnet/net/Timer.h"

using namespace libnet;
using namespace libnet::net;

AtomicInt64 Timer::s_numCreated_;

void Timer::restart(Timestamp now)
{
  if (repeat_)
  {
    expiration_ = addTime(now, interval_);
  }
  else
  {
    expiration_ = Timestamp::invalid();
  }
}

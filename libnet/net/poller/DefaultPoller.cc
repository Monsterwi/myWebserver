// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/libnet/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)

#include "libnet/net/Poller.h"
#include "libnet/net/poller/PollPoller.h"
#include "libnet/net/poller/EPollPoller.h"

#include <stdlib.h>

using namespace libnet::net;

Poller* Poller::newDefaultPoller(EventLoop* loop)
{
  if (::getenv("LIBNET_USE_POLL"))
  {
    return new PollPoller(loop);
  }
  else
  {
    return new EPollPoller(loop);
  }
}

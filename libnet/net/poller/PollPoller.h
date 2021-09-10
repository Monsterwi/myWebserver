// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/libnet/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is an internal header file, you should not include this.

#ifndef LIBNET_NET_POLLER_POLLPOLLER_H
#define LIBNET_NET_POLLER_POLLPOLLER_H

#include "libnet/net/Poller.h"

#include <vector>

struct pollfd;

namespace libnet
{
namespace net
{

///
/// IO Multiplexing with poll(2).
///
class PollPoller : public Poller
{
 public:

  PollPoller(EventLoop* loop);
  ~PollPoller() override;

  Timestamp poll(int timeoutMs, ChannelList* activeChannels) override;
  void updateChannel(Channel* channel) override;
  void removeChannel(Channel* channel) override;

 private:
  void fillActiveChannels(int numEvents,
                          ChannelList* activeChannels) const;

  typedef std::vector<struct pollfd> PollFdList;
  PollFdList pollfds_;
};

}  // namespace net
}  // namespace libnet
#endif  // LIBNET_NET_POLLER_POLLPOLLER_H

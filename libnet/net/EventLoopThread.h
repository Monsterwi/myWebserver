// This is a public header file, it must only include public header files.

#ifndef LIBNET_NET_EVENTLOOPTHREAD_H
#define LIBNET_NET_EVENTLOOPTHREAD_H

#include "libnet/base/Condition.h"
#include "libnet/base/Mutex.h"
#include "libnet/base/Thread.h"

namespace libnet
{
namespace net
{

class EventLoop;

class EventLoopThread : noncopyable
{
 public:
  typedef std::function<void(EventLoop*)> ThreadInitCallback;

  EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback(),
                  const string& name = string());
  ~EventLoopThread();
  EventLoop* startLoop();

 private:
  void threadFunc();

  EventLoop* loop_ GUARDED_BY(mutex_);
  bool exiting_;
  Thread thread_;
  MutexLock mutex_;
  Condition cond_ GUARDED_BY(mutex_);
  ThreadInitCallback callback_;
};

}  // namespace net
}  // namespace libnet

#endif  // LIBNET_NET_EVENTLOOPTHREAD_H


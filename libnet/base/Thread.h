#ifndef LIBNET_BASE_THREAD_H
#define LIBNET_BASE_THREAD_H

#include "libnet/base/Atomic.h"
#include "libnet/base/CountDownLatch.h"
#include "libnet/base/Types.h"

#include <functional>
#include <memory>
#include <pthread.h>

namespace libnet
{

class Thread : noncopyable
{
 public:
  typedef std::function<void ()> ThreadFunc;

  explicit Thread(ThreadFunc, const string& name = string());
  // FIXME: make it movable in C++11
  ~Thread();

  void start();
  int join(); // return pthread_join()

  bool started() const { return started_; }
  // pthread_t pthreadId() const { return pthreadId_; }
  pid_t tid() const { return tid_; }
  const string& name() const { return name_; }

  static int numCreated() { return numCreated_.get(); }

 private:
  void setDefaultName();

  bool       started_;
  bool       joined_;
  pthread_t  pthreadId_;
  pid_t      tid_;
  ThreadFunc func_;
  string     name_;
  CountDownLatch latch_;

  static AtomicInt32 numCreated_;
};

}  // namespace libnet
#endif  // LIBNET_BASE_THREAD_H

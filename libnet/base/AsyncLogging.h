#ifndef LIBNET_BASE_ASYNCLOGGING_H
#define LIBNET_BASE_ASYNCLOGGING_H

#include "libnet/base/BlockingQueue.h"
#include "libnet/base/BoundedBlockingQueue.h"
#include "libnet/base/CountDownLatch.h"
#include "libnet/base/Mutex.h"
#include "libnet/base/Thread.h"
#include "libnet/base/LogStream.h"

#include <atomic>
#include <vector>

namespace libnet
{

class AsyncLogging : noncopyable
{
 public:

  AsyncLogging(const string& basename,
               off_t rollSize,
               int flushInterval = 3);

  ~AsyncLogging()
  {
    if (running_)
    {
      stop();
    }
  }

  void append(const char* logline, int len);

  void start()
  {
    running_ = true;
    thread_.start();
    latch_.wait();
  }

  void stop() NO_THREAD_SAFETY_ANALYSIS
  {
    running_ = false;
    cond_.notify();
    thread_.join();
  }

 private:

  void threadFunc();

  typedef libnet::detail::FixedBuffer<libnet::detail::kLargeBuffer> Buffer;
  typedef std::vector<std::unique_ptr<Buffer>> BufferVector;
  typedef BufferVector::value_type BufferPtr;

  const int flushInterval_;
  std::atomic<bool> running_;
  const string basename_;
  const off_t rollSize_;
  libnet::Thread thread_;
  libnet::CountDownLatch latch_;
  libnet::MutexLock mutex_;
  libnet::Condition cond_ GUARDED_BY(mutex_);
  BufferPtr currentBuffer_ GUARDED_BY(mutex_);
  BufferPtr nextBuffer_ GUARDED_BY(mutex_);
  BufferVector buffers_ GUARDED_BY(mutex_);
};

}  // namespace libnet

#endif  // LIBNET_BASE_ASYNCLOGGING_H

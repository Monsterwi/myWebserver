#ifndef LIBNET_BASE_COUNTDOWNLATCH_H
#define LIBNET_BASE_COUNTDOWNLATCH_H

#include "libnet/base/Condition.h"
#include "libnet/base/Mutex.h"

namespace libnet
{

class CountDownLatch : noncopyable
{
 public:

  explicit CountDownLatch(int count);

  void wait();

  void countDown();

  int getCount() const;

 private:
  mutable MutexLock mutex_;
  Condition condition_ GUARDED_BY(mutex_);
  int count_ GUARDED_BY(mutex_);
};

}  // namespace libnet
#endif  // LIBNET_BASE_COUNTDOWNLATCH_H

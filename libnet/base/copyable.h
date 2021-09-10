#ifndef LIBNET_BASE_COPYABLE_H
#define LIBNET_BASE_COPYABLE_H

namespace libnet
{

/// A tag class emphasises the objects are copyable.
/// The empty base class optimization applies.
/// Any derived class of copyable should be a value type.
class copyable
{
 protected:
  copyable() = default;
  ~copyable() = default;
};

}  // namespace libnet

#endif  // LIBNET_BASE_COPYABLE_H

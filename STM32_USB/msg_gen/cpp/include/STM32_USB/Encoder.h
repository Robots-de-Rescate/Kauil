/* Auto-generated by genmsg_cpp for file /home/parallels/fuerte_workspace/STM32_USB/msg/Encoder.msg */
#ifndef STM32_USB_MESSAGE_ENCODER_H
#define STM32_USB_MESSAGE_ENCODER_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace STM32_USB
{
template <class ContainerAllocator>
struct Encoder_ {
  typedef Encoder_<ContainerAllocator> Type;

  Encoder_()
  : encoder(0)
  {
  }

  Encoder_(const ContainerAllocator& _alloc)
  : encoder(0)
  {
  }

  typedef int32_t _encoder_type;
  int32_t encoder;


  typedef boost::shared_ptr< ::STM32_USB::Encoder_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::STM32_USB::Encoder_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Encoder
typedef  ::STM32_USB::Encoder_<std::allocator<void> > Encoder;

typedef boost::shared_ptr< ::STM32_USB::Encoder> EncoderPtr;
typedef boost::shared_ptr< ::STM32_USB::Encoder const> EncoderConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::STM32_USB::Encoder_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::STM32_USB::Encoder_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace STM32_USB

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::STM32_USB::Encoder_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::STM32_USB::Encoder_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::STM32_USB::Encoder_<ContainerAllocator> > {
  static const char* value() 
  {
    return "6c463ba19d05d5db3d5666538249e96f";
  }

  static const char* value(const  ::STM32_USB::Encoder_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x6c463ba19d05d5dbULL;
  static const uint64_t static_value2 = 0x3d5666538249e96fULL;
};

template<class ContainerAllocator>
struct DataType< ::STM32_USB::Encoder_<ContainerAllocator> > {
  static const char* value() 
  {
    return "STM32_USB/Encoder";
  }

  static const char* value(const  ::STM32_USB::Encoder_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::STM32_USB::Encoder_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32 encoder\n\
\n\
\n\
";
  }

  static const char* value(const  ::STM32_USB::Encoder_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::STM32_USB::Encoder_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::STM32_USB::Encoder_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.encoder);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Encoder_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::STM32_USB::Encoder_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::STM32_USB::Encoder_<ContainerAllocator> & v) 
  {
    s << indent << "encoder: ";
    Printer<int32_t>::stream(s, indent + "  ", v.encoder);
  }
};


} // namespace message_operations
} // namespace ros

#endif // STM32_USB_MESSAGE_ENCODER_H


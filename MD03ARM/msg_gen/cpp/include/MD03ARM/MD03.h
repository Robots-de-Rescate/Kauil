/* Auto-generated by genmsg_cpp for file /home/kauil/ros_workspace/MD03ARM/msg/MD03.msg */
#ifndef MD03ARM_MESSAGE_MD03_H
#define MD03ARM_MESSAGE_MD03_H
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


namespace MD03ARM
{
template <class ContainerAllocator>
struct MD03_ {
  typedef MD03_<ContainerAllocator> Type;

  MD03_()
  : MD03()
  {
  }

  MD03_(const ContainerAllocator& _alloc)
  : MD03(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _MD03_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  MD03;


  typedef boost::shared_ptr< ::MD03ARM::MD03_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::MD03ARM::MD03_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct MD03
typedef  ::MD03ARM::MD03_<std::allocator<void> > MD03;

typedef boost::shared_ptr< ::MD03ARM::MD03> MD03Ptr;
typedef boost::shared_ptr< ::MD03ARM::MD03 const> MD03ConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::MD03ARM::MD03_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::MD03ARM::MD03_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace MD03ARM

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::MD03ARM::MD03_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::MD03ARM::MD03_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::MD03ARM::MD03_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d37cd3b8b867e41b41f25c01332dacf2";
  }

  static const char* value(const  ::MD03ARM::MD03_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd37cd3b8b867e41bULL;
  static const uint64_t static_value2 = 0x41f25c01332dacf2ULL;
};

template<class ContainerAllocator>
struct DataType< ::MD03ARM::MD03_<ContainerAllocator> > {
  static const char* value() 
  {
    return "MD03ARM/MD03";
  }

  static const char* value(const  ::MD03ARM::MD03_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::MD03ARM::MD03_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string MD03\n\
\n\
";
  }

  static const char* value(const  ::MD03ARM::MD03_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::MD03ARM::MD03_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.MD03);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct MD03_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::MD03ARM::MD03_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::MD03ARM::MD03_<ContainerAllocator> & v) 
  {
    s << indent << "MD03: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.MD03);
  }
};


} // namespace message_operations
} // namespace ros

#endif // MD03ARM_MESSAGE_MD03_H

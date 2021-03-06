// Generated by gencpp from file quad_msgs/SonarData.msg
// DO NOT EDIT!


#ifndef QUAD_MSGS_MESSAGE_SONARDATA_H
#define QUAD_MSGS_MESSAGE_SONARDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace quad_msgs
{
template <class ContainerAllocator>
struct SonarData_
{
  typedef SonarData_<ContainerAllocator> Type;

  SonarData_()
    : header()
    , x_pos(0.0)
    , x_neg(0.0)
    , y_pos(0.0)
    , y_neg(0.0)
    , up(0.0)
    , down(0.0)  {
    }
  SonarData_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x_pos(0.0)
    , x_neg(0.0)
    , y_pos(0.0)
    , y_neg(0.0)
    , up(0.0)
    , down(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _x_pos_type;
  _x_pos_type x_pos;

   typedef double _x_neg_type;
  _x_neg_type x_neg;

   typedef double _y_pos_type;
  _y_pos_type y_pos;

   typedef double _y_neg_type;
  _y_neg_type y_neg;

   typedef double _up_type;
  _up_type up;

   typedef double _down_type;
  _down_type down;




  typedef boost::shared_ptr< ::quad_msgs::SonarData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::quad_msgs::SonarData_<ContainerAllocator> const> ConstPtr;

}; // struct SonarData_

typedef ::quad_msgs::SonarData_<std::allocator<void> > SonarData;

typedef boost::shared_ptr< ::quad_msgs::SonarData > SonarDataPtr;
typedef boost::shared_ptr< ::quad_msgs::SonarData const> SonarDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::quad_msgs::SonarData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::quad_msgs::SonarData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace quad_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'quad_msgs': ['/home/odroid/quad_ws/src/quad_msgs/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::quad_msgs::SonarData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::quad_msgs::SonarData_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::quad_msgs::SonarData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::quad_msgs::SonarData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::quad_msgs::SonarData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::quad_msgs::SonarData_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::quad_msgs::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3646bd231f5033c4af083bc617838d04";
  }

  static const char* value(const ::quad_msgs::SonarData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3646bd231f5033c4ULL;
  static const uint64_t static_value2 = 0xaf083bc617838d04ULL;
};

template<class ContainerAllocator>
struct DataType< ::quad_msgs::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "quad_msgs/SonarData";
  }

  static const char* value(const ::quad_msgs::SonarData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::quad_msgs::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 x_pos\n\
float64 x_neg\n\
float64 y_pos\n\
float64 y_neg\n\
float64 up\n\
float64 down\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::quad_msgs::SonarData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::quad_msgs::SonarData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x_pos);
      stream.next(m.x_neg);
      stream.next(m.y_pos);
      stream.next(m.y_neg);
      stream.next(m.up);
      stream.next(m.down);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SonarData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::quad_msgs::SonarData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::quad_msgs::SonarData_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x_pos: ";
    Printer<double>::stream(s, indent + "  ", v.x_pos);
    s << indent << "x_neg: ";
    Printer<double>::stream(s, indent + "  ", v.x_neg);
    s << indent << "y_pos: ";
    Printer<double>::stream(s, indent + "  ", v.y_pos);
    s << indent << "y_neg: ";
    Printer<double>::stream(s, indent + "  ", v.y_neg);
    s << indent << "up: ";
    Printer<double>::stream(s, indent + "  ", v.up);
    s << indent << "down: ";
    Printer<double>::stream(s, indent + "  ", v.down);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QUAD_MSGS_MESSAGE_SONARDATA_H

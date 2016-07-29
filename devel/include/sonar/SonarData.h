// Generated by gencpp from file sonar/SonarData.msg
// DO NOT EDIT!


#ifndef SONAR_MESSAGE_SONARDATA_H
#define SONAR_MESSAGE_SONARDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sonar
{
template <class ContainerAllocator>
struct SonarData_
{
  typedef SonarData_<ContainerAllocator> Type;

  SonarData_()
    : x_pos(0.0)
    , x_neg(0.0)
    , y_pos(0.0)
    , y_neg(0.0)
    , up(0.0)
    , down(0.0)  {
    }
  SonarData_(const ContainerAllocator& _alloc)
    : x_pos(0.0)
    , x_neg(0.0)
    , y_pos(0.0)
    , y_neg(0.0)
    , up(0.0)
    , down(0.0)  {
  (void)_alloc;
    }



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




  typedef boost::shared_ptr< ::sonar::SonarData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sonar::SonarData_<ContainerAllocator> const> ConstPtr;

}; // struct SonarData_

typedef ::sonar::SonarData_<std::allocator<void> > SonarData;

typedef boost::shared_ptr< ::sonar::SonarData > SonarDataPtr;
typedef boost::shared_ptr< ::sonar::SonarData const> SonarDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sonar::SonarData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sonar::SonarData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sonar

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sonar': ['/home/odroid/quad_ws/src/sonar/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sonar::SonarData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sonar::SonarData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sonar::SonarData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sonar::SonarData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sonar::SonarData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sonar::SonarData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sonar::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7934ff36ec557a739a2288dd6df3b8ce";
  }

  static const char* value(const ::sonar::SonarData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7934ff36ec557a73ULL;
  static const uint64_t static_value2 = 0x9a2288dd6df3b8ceULL;
};

template<class ContainerAllocator>
struct DataType< ::sonar::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sonar/SonarData";
  }

  static const char* value(const ::sonar::SonarData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sonar::SonarData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x_pos\n\
float64 x_neg\n\
float64 y_pos\n\
float64 y_neg\n\
float64 up\n\
float64 down\n\
";
  }

  static const char* value(const ::sonar::SonarData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sonar::SonarData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
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
struct Printer< ::sonar::SonarData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sonar::SonarData_<ContainerAllocator>& v)
  {
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

#endif // SONAR_MESSAGE_SONARDATA_H

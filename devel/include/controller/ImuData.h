// Generated by gencpp from file controller/ImuData.msg
// DO NOT EDIT!


#ifndef CONTROLLER_MESSAGE_IMUDATA_H
#define CONTROLLER_MESSAGE_IMUDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace controller
{
template <class ContainerAllocator>
struct ImuData_
{
  typedef ImuData_<ContainerAllocator> Type;

  ImuData_()
    : theta(0.0)
    , phi(0.0)
    , psi(0.0)
    , theta_dot(0.0)
    , phi_dot(0.0)
    , psi_dot(0.0)  {
    }
  ImuData_(const ContainerAllocator& _alloc)
    : theta(0.0)
    , phi(0.0)
    , psi(0.0)
    , theta_dot(0.0)
    , phi_dot(0.0)
    , psi_dot(0.0)  {
    }



   typedef double _theta_type;
  _theta_type theta;

   typedef double _phi_type;
  _phi_type phi;

   typedef double _psi_type;
  _psi_type psi;

   typedef double _theta_dot_type;
  _theta_dot_type theta_dot;

   typedef double _phi_dot_type;
  _phi_dot_type phi_dot;

   typedef double _psi_dot_type;
  _psi_dot_type psi_dot;




  typedef boost::shared_ptr< ::controller::ImuData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::controller::ImuData_<ContainerAllocator> const> ConstPtr;

}; // struct ImuData_

typedef ::controller::ImuData_<std::allocator<void> > ImuData;

typedef boost::shared_ptr< ::controller::ImuData > ImuDataPtr;
typedef boost::shared_ptr< ::controller::ImuData const> ImuDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::controller::ImuData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::controller::ImuData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace controller

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'controller': ['/home/odroid/quad_ws/src/controller/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::controller::ImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::controller::ImuData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::controller::ImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::controller::ImuData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::controller::ImuData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::controller::ImuData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::controller::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6d12c1b1418f0fcd269a1dafcbda678f";
  }

  static const char* value(const ::controller::ImuData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6d12c1b1418f0fcdULL;
  static const uint64_t static_value2 = 0x269a1dafcbda678fULL;
};

template<class ContainerAllocator>
struct DataType< ::controller::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "controller/ImuData";
  }

  static const char* value(const ::controller::ImuData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::controller::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 theta\n\
float64 phi\n\
float64 psi\n\
float64 theta_dot\n\
float64 phi_dot\n\
float64 psi_dot\n\
";
  }

  static const char* value(const ::controller::ImuData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::controller::ImuData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.theta);
      stream.next(m.phi);
      stream.next(m.psi);
      stream.next(m.theta_dot);
      stream.next(m.phi_dot);
      stream.next(m.psi_dot);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ImuData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::controller::ImuData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::controller::ImuData_<ContainerAllocator>& v)
  {
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
    s << indent << "phi: ";
    Printer<double>::stream(s, indent + "  ", v.phi);
    s << indent << "psi: ";
    Printer<double>::stream(s, indent + "  ", v.psi);
    s << indent << "theta_dot: ";
    Printer<double>::stream(s, indent + "  ", v.theta_dot);
    s << indent << "phi_dot: ";
    Printer<double>::stream(s, indent + "  ", v.phi_dot);
    s << indent << "psi_dot: ";
    Printer<double>::stream(s, indent + "  ", v.psi_dot);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CONTROLLER_MESSAGE_IMUDATA_H

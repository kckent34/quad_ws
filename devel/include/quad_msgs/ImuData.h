// Generated by gencpp from file quad_msgs/ImuData.msg
// DO NOT EDIT!


#ifndef QUAD_MSGS_MESSAGE_IMUDATA_H
#define QUAD_MSGS_MESSAGE_IMUDATA_H


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
struct ImuData_
{
  typedef ImuData_<ContainerAllocator> Type;

  ImuData_()
    : header()
    , theta(0.0)
    , phi(0.0)
    , psi(0.0)
    , quat()
    , theta_dot(0.0)
    , phi_dot(0.0)
    , psi_dot(0.0)
    , psi_gyro_integration(0.0)
    , altitude(0.0)
    , barometer(0.0)
    , acc_z(0.0)
    , dt(0.0)
    , succ_read(0)  {
      quat.assign(0.0);
  }
  ImuData_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , theta(0.0)
    , phi(0.0)
    , psi(0.0)
    , quat()
    , theta_dot(0.0)
    , phi_dot(0.0)
    , psi_dot(0.0)
    , psi_gyro_integration(0.0)
    , altitude(0.0)
    , barometer(0.0)
    , acc_z(0.0)
    , dt(0.0)
    , succ_read(0)  {
  (void)_alloc;
      quat.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _theta_type;
  _theta_type theta;

   typedef float _phi_type;
  _phi_type phi;

   typedef float _psi_type;
  _psi_type psi;

   typedef boost::array<float, 4>  _quat_type;
  _quat_type quat;

   typedef float _theta_dot_type;
  _theta_dot_type theta_dot;

   typedef float _phi_dot_type;
  _phi_dot_type phi_dot;

   typedef float _psi_dot_type;
  _psi_dot_type psi_dot;

   typedef float _psi_gyro_integration_type;
  _psi_gyro_integration_type psi_gyro_integration;

   typedef float _altitude_type;
  _altitude_type altitude;

   typedef float _barometer_type;
  _barometer_type barometer;

   typedef float _acc_z_type;
  _acc_z_type acc_z;

   typedef float _dt_type;
  _dt_type dt;

   typedef int32_t _succ_read_type;
  _succ_read_type succ_read;




  typedef boost::shared_ptr< ::quad_msgs::ImuData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::quad_msgs::ImuData_<ContainerAllocator> const> ConstPtr;

}; // struct ImuData_

typedef ::quad_msgs::ImuData_<std::allocator<void> > ImuData;

typedef boost::shared_ptr< ::quad_msgs::ImuData > ImuDataPtr;
typedef boost::shared_ptr< ::quad_msgs::ImuData const> ImuDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::quad_msgs::ImuData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::quad_msgs::ImuData_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::quad_msgs::ImuData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::quad_msgs::ImuData_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::quad_msgs::ImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::quad_msgs::ImuData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::quad_msgs::ImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::quad_msgs::ImuData_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::quad_msgs::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b4cb0757a32bc7fb5f4a695374eb506c";
  }

  static const char* value(const ::quad_msgs::ImuData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb4cb0757a32bc7fbULL;
  static const uint64_t static_value2 = 0x5f4a695374eb506cULL;
};

template<class ContainerAllocator>
struct DataType< ::quad_msgs::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "quad_msgs/ImuData";
  }

  static const char* value(const ::quad_msgs::ImuData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::quad_msgs::ImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float32 theta\n\
float32 phi\n\
float32 psi\n\
float32[4] quat\n\
float32 theta_dot\n\
float32 phi_dot\n\
float32 psi_dot\n\
float32 psi_gyro_integration\n\
float32 altitude\n\
float32 barometer\n\
float32 acc_z\n\
float32 dt\n\
int32 succ_read\n\
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

  static const char* value(const ::quad_msgs::ImuData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::quad_msgs::ImuData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.theta);
      stream.next(m.phi);
      stream.next(m.psi);
      stream.next(m.quat);
      stream.next(m.theta_dot);
      stream.next(m.phi_dot);
      stream.next(m.psi_dot);
      stream.next(m.psi_gyro_integration);
      stream.next(m.altitude);
      stream.next(m.barometer);
      stream.next(m.acc_z);
      stream.next(m.dt);
      stream.next(m.succ_read);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ImuData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::quad_msgs::ImuData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::quad_msgs::ImuData_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "theta: ";
    Printer<float>::stream(s, indent + "  ", v.theta);
    s << indent << "phi: ";
    Printer<float>::stream(s, indent + "  ", v.phi);
    s << indent << "psi: ";
    Printer<float>::stream(s, indent + "  ", v.psi);
    s << indent << "quat[]" << std::endl;
    for (size_t i = 0; i < v.quat.size(); ++i)
    {
      s << indent << "  quat[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.quat[i]);
    }
    s << indent << "theta_dot: ";
    Printer<float>::stream(s, indent + "  ", v.theta_dot);
    s << indent << "phi_dot: ";
    Printer<float>::stream(s, indent + "  ", v.phi_dot);
    s << indent << "psi_dot: ";
    Printer<float>::stream(s, indent + "  ", v.psi_dot);
    s << indent << "psi_gyro_integration: ";
    Printer<float>::stream(s, indent + "  ", v.psi_gyro_integration);
    s << indent << "altitude: ";
    Printer<float>::stream(s, indent + "  ", v.altitude);
    s << indent << "barometer: ";
    Printer<float>::stream(s, indent + "  ", v.barometer);
    s << indent << "acc_z: ";
    Printer<float>::stream(s, indent + "  ", v.acc_z);
    s << indent << "dt: ";
    Printer<float>::stream(s, indent + "  ", v.dt);
    s << indent << "succ_read: ";
    Printer<int32_t>::stream(s, indent + "  ", v.succ_read);
  }
};

} // namespace message_operations
} // namespace ros

#endif // QUAD_MSGS_MESSAGE_IMUDATA_H

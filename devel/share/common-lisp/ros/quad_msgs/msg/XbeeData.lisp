; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude XbeeData.msg.html

(cl:defclass <XbeeData> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (joy_des_angles
    :reader joy_des_angles
    :initarg :joy_des_angles
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (joy_thrust
    :reader joy_thrust
    :initarg :joy_thrust
    :type cl:fixnum
    :initform 0)
   (flight_mode
    :reader flight_mode
    :initarg :flight_mode
    :type cl:fixnum
    :initform 0))
)

(cl:defclass XbeeData (<XbeeData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <XbeeData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'XbeeData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<XbeeData> is deprecated: use quad_msgs-msg:XbeeData instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <XbeeData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'joy_des_angles-val :lambda-list '(m))
(cl:defmethod joy_des_angles-val ((m <XbeeData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:joy_des_angles-val is deprecated.  Use quad_msgs-msg:joy_des_angles instead.")
  (joy_des_angles m))

(cl:ensure-generic-function 'joy_thrust-val :lambda-list '(m))
(cl:defmethod joy_thrust-val ((m <XbeeData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:joy_thrust-val is deprecated.  Use quad_msgs-msg:joy_thrust instead.")
  (joy_thrust m))

(cl:ensure-generic-function 'flight_mode-val :lambda-list '(m))
(cl:defmethod flight_mode-val ((m <XbeeData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:flight_mode-val is deprecated.  Use quad_msgs-msg:flight_mode instead.")
  (flight_mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <XbeeData>) ostream)
  "Serializes a message object of type '<XbeeData>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'joy_des_angles))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'joy_thrust)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flight_mode)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <XbeeData>) istream)
  "Deserializes a message object of type '<XbeeData>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'joy_des_angles) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'joy_des_angles)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'joy_thrust)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flight_mode)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<XbeeData>)))
  "Returns string type for a message object of type '<XbeeData>"
  "quad_msgs/XbeeData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'XbeeData)))
  "Returns string type for a message object of type 'XbeeData"
  "quad_msgs/XbeeData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<XbeeData>)))
  "Returns md5sum for a message object of type '<XbeeData>"
  "9e8751e764ae2fdba0ee593ad1928d7c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'XbeeData)))
  "Returns md5sum for a message object of type 'XbeeData"
  "9e8751e764ae2fdba0ee593ad1928d7c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<XbeeData>)))
  "Returns full string definition for message of type '<XbeeData>"
  (cl:format cl:nil "Header header~%float32[3] joy_des_angles~%uint8 joy_thrust~%uint8 flight_mode~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'XbeeData)))
  "Returns full string definition for message of type 'XbeeData"
  (cl:format cl:nil "Header header~%float32[3] joy_des_angles~%uint8 joy_thrust~%uint8 flight_mode~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <XbeeData>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joy_des_angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <XbeeData>))
  "Converts a ROS message object to a list"
  (cl:list 'XbeeData
    (cl:cons ':header (header msg))
    (cl:cons ':joy_des_angles (joy_des_angles msg))
    (cl:cons ':joy_thrust (joy_thrust msg))
    (cl:cons ':flight_mode (flight_mode msg))
))

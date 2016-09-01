; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude ImuData.msg.html

(cl:defclass <ImuData> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0)
   (phi
    :reader phi
    :initarg :phi
    :type cl:float
    :initform 0.0)
   (psi
    :reader psi
    :initarg :psi
    :type cl:float
    :initform 0.0)
   (quat
    :reader quat
    :initarg :quat
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0))
   (theta_dot
    :reader theta_dot
    :initarg :theta_dot
    :type cl:float
    :initform 0.0)
   (phi_dot
    :reader phi_dot
    :initarg :phi_dot
    :type cl:float
    :initform 0.0)
   (psi_dot
    :reader psi_dot
    :initarg :psi_dot
    :type cl:float
    :initform 0.0)
   (psi_gyro_integration
    :reader psi_gyro_integration
    :initarg :psi_gyro_integration
    :type cl:float
    :initform 0.0)
   (altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0)
   (barometer
    :reader barometer
    :initarg :barometer
    :type cl:float
    :initform 0.0)
   (acc_z
    :reader acc_z
    :initarg :acc_z
    :type cl:float
    :initform 0.0)
   (dt
    :reader dt
    :initarg :dt
    :type cl:float
    :initform 0.0)
   (succ_read
    :reader succ_read
    :initarg :succ_read
    :type cl:integer
    :initform 0))
)

(cl:defclass ImuData (<ImuData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImuData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImuData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<ImuData> is deprecated: use quad_msgs-msg:ImuData instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:theta-val is deprecated.  Use quad_msgs-msg:theta instead.")
  (theta m))

(cl:ensure-generic-function 'phi-val :lambda-list '(m))
(cl:defmethod phi-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:phi-val is deprecated.  Use quad_msgs-msg:phi instead.")
  (phi m))

(cl:ensure-generic-function 'psi-val :lambda-list '(m))
(cl:defmethod psi-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:psi-val is deprecated.  Use quad_msgs-msg:psi instead.")
  (psi m))

(cl:ensure-generic-function 'quat-val :lambda-list '(m))
(cl:defmethod quat-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:quat-val is deprecated.  Use quad_msgs-msg:quat instead.")
  (quat m))

(cl:ensure-generic-function 'theta_dot-val :lambda-list '(m))
(cl:defmethod theta_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:theta_dot-val is deprecated.  Use quad_msgs-msg:theta_dot instead.")
  (theta_dot m))

(cl:ensure-generic-function 'phi_dot-val :lambda-list '(m))
(cl:defmethod phi_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:phi_dot-val is deprecated.  Use quad_msgs-msg:phi_dot instead.")
  (phi_dot m))

(cl:ensure-generic-function 'psi_dot-val :lambda-list '(m))
(cl:defmethod psi_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:psi_dot-val is deprecated.  Use quad_msgs-msg:psi_dot instead.")
  (psi_dot m))

(cl:ensure-generic-function 'psi_gyro_integration-val :lambda-list '(m))
(cl:defmethod psi_gyro_integration-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:psi_gyro_integration-val is deprecated.  Use quad_msgs-msg:psi_gyro_integration instead.")
  (psi_gyro_integration m))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:altitude-val is deprecated.  Use quad_msgs-msg:altitude instead.")
  (altitude m))

(cl:ensure-generic-function 'barometer-val :lambda-list '(m))
(cl:defmethod barometer-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:barometer-val is deprecated.  Use quad_msgs-msg:barometer instead.")
  (barometer m))

(cl:ensure-generic-function 'acc_z-val :lambda-list '(m))
(cl:defmethod acc_z-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:acc_z-val is deprecated.  Use quad_msgs-msg:acc_z instead.")
  (acc_z m))

(cl:ensure-generic-function 'dt-val :lambda-list '(m))
(cl:defmethod dt-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:dt-val is deprecated.  Use quad_msgs-msg:dt instead.")
  (dt m))

(cl:ensure-generic-function 'succ_read-val :lambda-list '(m))
(cl:defmethod succ_read-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:succ_read-val is deprecated.  Use quad_msgs-msg:succ_read instead.")
  (succ_read m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImuData>) ostream)
  "Serializes a message object of type '<ImuData>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'phi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'psi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'quat))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'theta_dot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'phi_dot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'psi_dot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'psi_gyro_integration))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'barometer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dt))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'succ_read)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImuData>) istream)
  "Deserializes a message object of type '<ImuData>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'phi) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi) (roslisp-utils:decode-single-float-bits bits)))
  (cl:setf (cl:slot-value msg 'quat) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'quat)))
    (cl:dotimes (i 4)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta_dot) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'phi_dot) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi_dot) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi_gyro_integration) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'altitude) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'barometer) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dt) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'succ_read) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImuData>)))
  "Returns string type for a message object of type '<ImuData>"
  "quad_msgs/ImuData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImuData)))
  "Returns string type for a message object of type 'ImuData"
  "quad_msgs/ImuData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImuData>)))
  "Returns md5sum for a message object of type '<ImuData>"
  "b4cb0757a32bc7fb5f4a695374eb506c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImuData)))
  "Returns md5sum for a message object of type 'ImuData"
  "b4cb0757a32bc7fb5f4a695374eb506c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImuData>)))
  "Returns full string definition for message of type '<ImuData>"
  (cl:format cl:nil "Header header~%float32 theta~%float32 phi~%float32 psi~%float32[4] quat~%float32 theta_dot~%float32 phi_dot~%float32 psi_dot~%float32 psi_gyro_integration~%float32 altitude~%float32 barometer~%float32 acc_z~%float32 dt~%int32 succ_read~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImuData)))
  "Returns full string definition for message of type 'ImuData"
  (cl:format cl:nil "Header header~%float32 theta~%float32 phi~%float32 psi~%float32[4] quat~%float32 theta_dot~%float32 phi_dot~%float32 psi_dot~%float32 psi_gyro_integration~%float32 altitude~%float32 barometer~%float32 acc_z~%float32 dt~%int32 succ_read~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImuData>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'quat) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImuData>))
  "Converts a ROS message object to a list"
  (cl:list 'ImuData
    (cl:cons ':header (header msg))
    (cl:cons ':theta (theta msg))
    (cl:cons ':phi (phi msg))
    (cl:cons ':psi (psi msg))
    (cl:cons ':quat (quat msg))
    (cl:cons ':theta_dot (theta_dot msg))
    (cl:cons ':phi_dot (phi_dot msg))
    (cl:cons ':psi_dot (psi_dot msg))
    (cl:cons ':psi_gyro_integration (psi_gyro_integration msg))
    (cl:cons ':altitude (altitude msg))
    (cl:cons ':barometer (barometer msg))
    (cl:cons ':acc_z (acc_z msg))
    (cl:cons ':dt (dt msg))
    (cl:cons ':succ_read (succ_read msg))
))

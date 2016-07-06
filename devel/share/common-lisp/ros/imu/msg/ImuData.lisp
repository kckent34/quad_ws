; Auto-generated. Do not edit!


(cl:in-package imu-msg)


;//! \htmlinclude ImuData.msg.html

(cl:defclass <ImuData> (roslisp-msg-protocol:ros-message)
  ((theta
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
    :initform 0.0))
)

(cl:defclass ImuData (<ImuData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImuData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImuData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name imu-msg:<ImuData> is deprecated: use imu-msg:ImuData instead.")))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:theta-val is deprecated.  Use imu-msg:theta instead.")
  (theta m))

(cl:ensure-generic-function 'phi-val :lambda-list '(m))
(cl:defmethod phi-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:phi-val is deprecated.  Use imu-msg:phi instead.")
  (phi m))

(cl:ensure-generic-function 'psi-val :lambda-list '(m))
(cl:defmethod psi-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:psi-val is deprecated.  Use imu-msg:psi instead.")
  (psi m))

(cl:ensure-generic-function 'theta_dot-val :lambda-list '(m))
(cl:defmethod theta_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:theta_dot-val is deprecated.  Use imu-msg:theta_dot instead.")
  (theta_dot m))

(cl:ensure-generic-function 'phi_dot-val :lambda-list '(m))
(cl:defmethod phi_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:phi_dot-val is deprecated.  Use imu-msg:phi_dot instead.")
  (phi_dot m))

(cl:ensure-generic-function 'psi_dot-val :lambda-list '(m))
(cl:defmethod psi_dot-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:psi_dot-val is deprecated.  Use imu-msg:psi_dot instead.")
  (psi_dot m))

(cl:ensure-generic-function 'psi_gyro_integration-val :lambda-list '(m))
(cl:defmethod psi_gyro_integration-val ((m <ImuData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader imu-msg:psi_gyro_integration-val is deprecated.  Use imu-msg:psi_gyro_integration instead.")
  (psi_gyro_integration m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImuData>) ostream)
  "Serializes a message object of type '<ImuData>"
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImuData>) istream)
  "Deserializes a message object of type '<ImuData>"
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImuData>)))
  "Returns string type for a message object of type '<ImuData>"
  "imu/ImuData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImuData)))
  "Returns string type for a message object of type 'ImuData"
  "imu/ImuData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImuData>)))
  "Returns md5sum for a message object of type '<ImuData>"
  "1e67f9547d3aff4c172378fd0c9696f9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImuData)))
  "Returns md5sum for a message object of type 'ImuData"
  "1e67f9547d3aff4c172378fd0c9696f9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImuData>)))
  "Returns full string definition for message of type '<ImuData>"
  (cl:format cl:nil "float32 theta~%float32 phi~%float32 psi~%float32 theta_dot~%float32 phi_dot~%float32 psi_dot~%float32 psi_gyro_integration~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImuData)))
  "Returns full string definition for message of type 'ImuData"
  (cl:format cl:nil "float32 theta~%float32 phi~%float32 psi~%float32 theta_dot~%float32 phi_dot~%float32 psi_dot~%float32 psi_gyro_integration~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImuData>))
  (cl:+ 0
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
    (cl:cons ':theta (theta msg))
    (cl:cons ':phi (phi msg))
    (cl:cons ':psi (psi msg))
    (cl:cons ':theta_dot (theta_dot msg))
    (cl:cons ':phi_dot (phi_dot msg))
    (cl:cons ':psi_dot (psi_dot msg))
    (cl:cons ':psi_gyro_integration (psi_gyro_integration msg))
))

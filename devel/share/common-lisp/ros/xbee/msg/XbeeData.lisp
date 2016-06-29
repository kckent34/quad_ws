; Auto-generated. Do not edit!


(cl:in-package xbee-msg)


;//! \htmlinclude XbeeData.msg.html

(cl:defclass <XbeeData> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type cl:float
    :initform 0.0))
)

(cl:defclass XbeeData (<XbeeData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <XbeeData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'XbeeData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name xbee-msg:<XbeeData> is deprecated: use xbee-msg:XbeeData instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <XbeeData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader xbee-msg:data-val is deprecated.  Use xbee-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <XbeeData>) ostream)
  "Serializes a message object of type '<XbeeData>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <XbeeData>) istream)
  "Deserializes a message object of type '<XbeeData>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'data) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<XbeeData>)))
  "Returns string type for a message object of type '<XbeeData>"
  "xbee/XbeeData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'XbeeData)))
  "Returns string type for a message object of type 'XbeeData"
  "xbee/XbeeData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<XbeeData>)))
  "Returns md5sum for a message object of type '<XbeeData>"
  "fdb28210bfa9d7c91146260178d9a584")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'XbeeData)))
  "Returns md5sum for a message object of type 'XbeeData"
  "fdb28210bfa9d7c91146260178d9a584")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<XbeeData>)))
  "Returns full string definition for message of type '<XbeeData>"
  (cl:format cl:nil "float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'XbeeData)))
  "Returns full string definition for message of type 'XbeeData"
  (cl:format cl:nil "float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <XbeeData>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <XbeeData>))
  "Converts a ROS message object to a list"
  (cl:list 'XbeeData
    (cl:cons ':data (data msg))
))

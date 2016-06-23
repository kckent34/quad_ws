; Auto-generated. Do not edit!


(cl:in-package motors-msg)


;//! \htmlinclude MotorVals.msg.html

(cl:defclass <MotorVals> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:fixnum
    :initform 0))
)

(cl:defclass MotorVals (<MotorVals>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorVals>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorVals)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motors-msg:<MotorVals> is deprecated: use motors-msg:MotorVals instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <MotorVals>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motors-msg:num-val is deprecated.  Use motors-msg:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorVals>) ostream)
  "Serializes a message object of type '<MotorVals>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorVals>) istream)
  "Deserializes a message object of type '<MotorVals>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'num)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorVals>)))
  "Returns string type for a message object of type '<MotorVals>"
  "motors/MotorVals")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorVals)))
  "Returns string type for a message object of type 'MotorVals"
  "motors/MotorVals")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorVals>)))
  "Returns md5sum for a message object of type '<MotorVals>"
  "0285aea93c08847f409c58db5e8d9137")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorVals)))
  "Returns md5sum for a message object of type 'MotorVals"
  "0285aea93c08847f409c58db5e8d9137")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorVals>)))
  "Returns full string definition for message of type '<MotorVals>"
  (cl:format cl:nil "uint16 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorVals)))
  "Returns full string definition for message of type 'MotorVals"
  (cl:format cl:nil "uint16 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorVals>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorVals>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorVals
    (cl:cons ':num (num msg))
))

; Auto-generated. Do not edit!


(cl:in-package STM32_USB-msg)


;//! \htmlinclude Compass.msg.html

(cl:defclass <Compass> (roslisp-msg-protocol:ros-message)
  ((compass
    :reader compass
    :initarg :compass
    :type cl:float
    :initform 0.0))
)

(cl:defclass Compass (<Compass>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Compass>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Compass)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name STM32_USB-msg:<Compass> is deprecated: use STM32_USB-msg:Compass instead.")))

(cl:ensure-generic-function 'compass-val :lambda-list '(m))
(cl:defmethod compass-val ((m <Compass>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader STM32_USB-msg:compass-val is deprecated.  Use STM32_USB-msg:compass instead.")
  (compass m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Compass>) ostream)
  "Serializes a message object of type '<Compass>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'compass))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Compass>) istream)
  "Deserializes a message object of type '<Compass>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'compass) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Compass>)))
  "Returns string type for a message object of type '<Compass>"
  "STM32_USB/Compass")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Compass)))
  "Returns string type for a message object of type 'Compass"
  "STM32_USB/Compass")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Compass>)))
  "Returns md5sum for a message object of type '<Compass>"
  "071a7bf0338a5c920686d632df45950e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Compass)))
  "Returns md5sum for a message object of type 'Compass"
  "071a7bf0338a5c920686d632df45950e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Compass>)))
  "Returns full string definition for message of type '<Compass>"
  (cl:format cl:nil "float32 compass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Compass)))
  "Returns full string definition for message of type 'Compass"
  (cl:format cl:nil "float32 compass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Compass>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Compass>))
  "Converts a ROS message object to a list"
  (cl:list 'Compass
    (cl:cons ':compass (compass msg))
))

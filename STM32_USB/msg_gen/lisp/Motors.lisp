; Auto-generated. Do not edit!


(cl:in-package STM32_USB-msg)


;//! \htmlinclude Motors.msg.html

(cl:defclass <Motors> (roslisp-msg-protocol:ros-message)
  ((MotorLeft
    :reader MotorLeft
    :initarg :MotorLeft
    :type cl:fixnum
    :initform 0)
   (MotorRight
    :reader MotorRight
    :initarg :MotorRight
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Motors (<Motors>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Motors>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Motors)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name STM32_USB-msg:<Motors> is deprecated: use STM32_USB-msg:Motors instead.")))

(cl:ensure-generic-function 'MotorLeft-val :lambda-list '(m))
(cl:defmethod MotorLeft-val ((m <Motors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader STM32_USB-msg:MotorLeft-val is deprecated.  Use STM32_USB-msg:MotorLeft instead.")
  (MotorLeft m))

(cl:ensure-generic-function 'MotorRight-val :lambda-list '(m))
(cl:defmethod MotorRight-val ((m <Motors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader STM32_USB-msg:MotorRight-val is deprecated.  Use STM32_USB-msg:MotorRight instead.")
  (MotorRight m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Motors>) ostream)
  "Serializes a message object of type '<Motors>"
  (cl:let* ((signed (cl:slot-value msg 'MotorLeft)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'MotorRight)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Motors>) istream)
  "Deserializes a message object of type '<Motors>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'MotorLeft) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'MotorRight) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Motors>)))
  "Returns string type for a message object of type '<Motors>"
  "STM32_USB/Motors")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Motors)))
  "Returns string type for a message object of type 'Motors"
  "STM32_USB/Motors")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Motors>)))
  "Returns md5sum for a message object of type '<Motors>"
  "8190e347f82924a3dacda1485c60de6a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Motors)))
  "Returns md5sum for a message object of type 'Motors"
  "8190e347f82924a3dacda1485c60de6a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Motors>)))
  "Returns full string definition for message of type '<Motors>"
  (cl:format cl:nil "int16 MotorLeft~%int16 MotorRight~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Motors)))
  "Returns full string definition for message of type 'Motors"
  (cl:format cl:nil "int16 MotorLeft~%int16 MotorRight~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Motors>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Motors>))
  "Converts a ROS message object to a list"
  (cl:list 'Motors
    (cl:cons ':MotorLeft (MotorLeft msg))
    (cl:cons ':MotorRight (MotorRight msg))
))

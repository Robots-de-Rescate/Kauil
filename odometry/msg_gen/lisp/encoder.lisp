; Auto-generated. Do not edit!


(cl:in-package odometry-msg)


;//! \htmlinclude encoder.msg.html

(cl:defclass <encoder> (roslisp-msg-protocol:ros-message)
  ((rpulses
    :reader rpulses
    :initarg :rpulses
    :type cl:float
    :initform 0.0)
   (lpulses
    :reader lpulses
    :initarg :lpulses
    :type cl:float
    :initform 0.0))
)

(cl:defclass encoder (<encoder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <encoder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'encoder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name odometry-msg:<encoder> is deprecated: use odometry-msg:encoder instead.")))

(cl:ensure-generic-function 'rpulses-val :lambda-list '(m))
(cl:defmethod rpulses-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader odometry-msg:rpulses-val is deprecated.  Use odometry-msg:rpulses instead.")
  (rpulses m))

(cl:ensure-generic-function 'lpulses-val :lambda-list '(m))
(cl:defmethod lpulses-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader odometry-msg:lpulses-val is deprecated.  Use odometry-msg:lpulses instead.")
  (lpulses m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <encoder>) ostream)
  "Serializes a message object of type '<encoder>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'rpulses))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lpulses))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <encoder>) istream)
  "Deserializes a message object of type '<encoder>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rpulses) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lpulses) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<encoder>)))
  "Returns string type for a message object of type '<encoder>"
  "odometry/encoder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'encoder)))
  "Returns string type for a message object of type 'encoder"
  "odometry/encoder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<encoder>)))
  "Returns md5sum for a message object of type '<encoder>"
  "a066eb83358996063bdf035669876fc4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'encoder)))
  "Returns md5sum for a message object of type 'encoder"
  "a066eb83358996063bdf035669876fc4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<encoder>)))
  "Returns full string definition for message of type '<encoder>"
  (cl:format cl:nil "float64 rpulses~%float64 lpulses~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'encoder)))
  "Returns full string definition for message of type 'encoder"
  (cl:format cl:nil "float64 rpulses~%float64 lpulses~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <encoder>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <encoder>))
  "Converts a ROS message object to a list"
  (cl:list 'encoder
    (cl:cons ':rpulses (rpulses msg))
    (cl:cons ':lpulses (lpulses msg))
))

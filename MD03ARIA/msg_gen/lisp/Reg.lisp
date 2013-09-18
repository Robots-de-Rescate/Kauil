; Auto-generated. Do not edit!


(cl:in-package MD03ARIA-msg)


;//! \htmlinclude Reg.msg.html

(cl:defclass <Reg> (roslisp-msg-protocol:ros-message)
  ((B0_direction
    :reader B0_direction
    :initarg :B0_direction
    :type cl:integer
    :initform 0)
   (B0_speed
    :reader B0_speed
    :initarg :B0_speed
    :type cl:integer
    :initform 0)
   (B2_direction
    :reader B2_direction
    :initarg :B2_direction
    :type cl:integer
    :initform 0)
   (B2_speed
    :reader B2_speed
    :initarg :B2_speed
    :type cl:integer
    :initform 0))
)

(cl:defclass Reg (<Reg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Reg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Reg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name MD03ARIA-msg:<Reg> is deprecated: use MD03ARIA-msg:Reg instead.")))

(cl:ensure-generic-function 'B0_direction-val :lambda-list '(m))
(cl:defmethod B0_direction-val ((m <Reg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:B0_direction-val is deprecated.  Use MD03ARIA-msg:B0_direction instead.")
  (B0_direction m))

(cl:ensure-generic-function 'B0_speed-val :lambda-list '(m))
(cl:defmethod B0_speed-val ((m <Reg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:B0_speed-val is deprecated.  Use MD03ARIA-msg:B0_speed instead.")
  (B0_speed m))

(cl:ensure-generic-function 'B2_direction-val :lambda-list '(m))
(cl:defmethod B2_direction-val ((m <Reg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:B2_direction-val is deprecated.  Use MD03ARIA-msg:B2_direction instead.")
  (B2_direction m))

(cl:ensure-generic-function 'B2_speed-val :lambda-list '(m))
(cl:defmethod B2_speed-val ((m <Reg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:B2_speed-val is deprecated.  Use MD03ARIA-msg:B2_speed instead.")
  (B2_speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Reg>) ostream)
  "Serializes a message object of type '<Reg>"
  (cl:let* ((signed (cl:slot-value msg 'B0_direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'B0_speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'B2_direction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'B2_speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Reg>) istream)
  "Deserializes a message object of type '<Reg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B0_direction) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B0_speed) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B2_direction) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B2_speed) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Reg>)))
  "Returns string type for a message object of type '<Reg>"
  "MD03ARIA/Reg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Reg)))
  "Returns string type for a message object of type 'Reg"
  "MD03ARIA/Reg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Reg>)))
  "Returns md5sum for a message object of type '<Reg>"
  "8aa5d362ecee3cd4ca4534b5a5c89625")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Reg)))
  "Returns md5sum for a message object of type 'Reg"
  "8aa5d362ecee3cd4ca4534b5a5c89625")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Reg>)))
  "Returns full string definition for message of type '<Reg>"
  (cl:format cl:nil "int64 B0_direction~%int64 B0_speed~%int64 B2_direction~%int64 B2_speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Reg)))
  "Returns full string definition for message of type 'Reg"
  (cl:format cl:nil "int64 B0_direction~%int64 B0_speed~%int64 B2_direction~%int64 B2_speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Reg>))
  (cl:+ 0
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Reg>))
  "Converts a ROS message object to a list"
  (cl:list 'Reg
    (cl:cons ':B0_direction (B0_direction msg))
    (cl:cons ':B0_speed (B0_speed msg))
    (cl:cons ':B2_direction (B2_direction msg))
    (cl:cons ':B2_speed (B2_speed msg))
))

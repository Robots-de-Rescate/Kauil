; Auto-generated. Do not edit!


(cl:in-package MD03ARIA-msg)


;//! \htmlinclude encoder.msg.html

(cl:defclass <encoder> (roslisp-msg-protocol:ros-message)
  ((rpulses
    :reader rpulses
    :initarg :rpulses
    :type cl:fixnum
    :initform 0)
   (rdirection
    :reader rdirection
    :initarg :rdirection
    :type cl:fixnum
    :initform 0)
   (lpulses
    :reader lpulses
    :initarg :lpulses
    :type cl:fixnum
    :initform 0)
   (ldirection
    :reader ldirection
    :initarg :ldirection
    :type cl:fixnum
    :initform 0))
)

(cl:defclass encoder (<encoder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <encoder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'encoder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name MD03ARIA-msg:<encoder> is deprecated: use MD03ARIA-msg:encoder instead.")))

(cl:ensure-generic-function 'rpulses-val :lambda-list '(m))
(cl:defmethod rpulses-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:rpulses-val is deprecated.  Use MD03ARIA-msg:rpulses instead.")
  (rpulses m))

(cl:ensure-generic-function 'rdirection-val :lambda-list '(m))
(cl:defmethod rdirection-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:rdirection-val is deprecated.  Use MD03ARIA-msg:rdirection instead.")
  (rdirection m))

(cl:ensure-generic-function 'lpulses-val :lambda-list '(m))
(cl:defmethod lpulses-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:lpulses-val is deprecated.  Use MD03ARIA-msg:lpulses instead.")
  (lpulses m))

(cl:ensure-generic-function 'ldirection-val :lambda-list '(m))
(cl:defmethod ldirection-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:ldirection-val is deprecated.  Use MD03ARIA-msg:ldirection instead.")
  (ldirection m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <encoder>) ostream)
  "Serializes a message object of type '<encoder>"
  (cl:let* ((signed (cl:slot-value msg 'rpulses)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'rdirection)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'lpulses)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ldirection)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <encoder>) istream)
  "Deserializes a message object of type '<encoder>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rpulses) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rdirection) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'lpulses) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ldirection) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<encoder>)))
  "Returns string type for a message object of type '<encoder>"
  "MD03ARIA/encoder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'encoder)))
  "Returns string type for a message object of type 'encoder"
  "MD03ARIA/encoder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<encoder>)))
  "Returns md5sum for a message object of type '<encoder>"
  "e4b10ca275ee312169b4dee797690312")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'encoder)))
  "Returns md5sum for a message object of type 'encoder"
  "e4b10ca275ee312169b4dee797690312")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<encoder>)))
  "Returns full string definition for message of type '<encoder>"
  (cl:format cl:nil "int8 rpulses~%int8 rdirection~%int8 lpulses~%int8 ldirection~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'encoder)))
  "Returns full string definition for message of type 'encoder"
  (cl:format cl:nil "int8 rpulses~%int8 rdirection~%int8 lpulses~%int8 ldirection~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <encoder>))
  (cl:+ 0
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <encoder>))
  "Converts a ROS message object to a list"
  (cl:list 'encoder
    (cl:cons ':rpulses (rpulses msg))
    (cl:cons ':rdirection (rdirection msg))
    (cl:cons ':lpulses (lpulses msg))
    (cl:cons ':ldirection (ldirection msg))
))

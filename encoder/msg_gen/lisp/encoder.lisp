; Auto-generated. Do not edit!


(cl:in-package encoder-msg)


;//! \htmlinclude encoder.msg.html

(cl:defclass <encoder> (roslisp-msg-protocol:ros-message)
  ((izq
    :reader izq
    :initarg :izq
    :type cl:integer
    :initform 0)
   (der
    :reader der
    :initarg :der
    :type cl:integer
    :initform 0))
)

(cl:defclass encoder (<encoder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <encoder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'encoder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name encoder-msg:<encoder> is deprecated: use encoder-msg:encoder instead.")))

(cl:ensure-generic-function 'izq-val :lambda-list '(m))
(cl:defmethod izq-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader encoder-msg:izq-val is deprecated.  Use encoder-msg:izq instead.")
  (izq m))

(cl:ensure-generic-function 'der-val :lambda-list '(m))
(cl:defmethod der-val ((m <encoder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader encoder-msg:der-val is deprecated.  Use encoder-msg:der instead.")
  (der m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <encoder>) ostream)
  "Serializes a message object of type '<encoder>"
  (cl:let* ((signed (cl:slot-value msg 'izq)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'der)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <encoder>) istream)
  "Deserializes a message object of type '<encoder>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'izq) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'der) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<encoder>)))
  "Returns string type for a message object of type '<encoder>"
  "encoder/encoder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'encoder)))
  "Returns string type for a message object of type 'encoder"
  "encoder/encoder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<encoder>)))
  "Returns md5sum for a message object of type '<encoder>"
  "44cd1e2362e72574bc175ff0d1538977")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'encoder)))
  "Returns md5sum for a message object of type 'encoder"
  "44cd1e2362e72574bc175ff0d1538977")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<encoder>)))
  "Returns full string definition for message of type '<encoder>"
  (cl:format cl:nil "int32 izq~%int32 der~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'encoder)))
  "Returns full string definition for message of type 'encoder"
  (cl:format cl:nil "int32 izq~%int32 der~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <encoder>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <encoder>))
  "Converts a ROS message object to a list"
  (cl:list 'encoder
    (cl:cons ':izq (izq msg))
    (cl:cons ':der (der msg))
))

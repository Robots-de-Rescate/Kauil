; Auto-generated. Do not edit!


(cl:in-package MD03ARIA-msg)


;//! \htmlinclude MD03.msg.html

(cl:defclass <MD03> (roslisp-msg-protocol:ros-message)
  ((MD03
    :reader MD03
    :initarg :MD03
    :type cl:string
    :initform ""))
)

(cl:defclass MD03 (<MD03>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MD03>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MD03)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name MD03ARIA-msg:<MD03> is deprecated: use MD03ARIA-msg:MD03 instead.")))

(cl:ensure-generic-function 'MD03-val :lambda-list '(m))
(cl:defmethod MD03-val ((m <MD03>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader MD03ARIA-msg:MD03-val is deprecated.  Use MD03ARIA-msg:MD03 instead.")
  (MD03 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MD03>) ostream)
  "Serializes a message object of type '<MD03>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'MD03))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'MD03))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MD03>) istream)
  "Deserializes a message object of type '<MD03>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'MD03) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'MD03) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MD03>)))
  "Returns string type for a message object of type '<MD03>"
  "MD03ARIA/MD03")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MD03)))
  "Returns string type for a message object of type 'MD03"
  "MD03ARIA/MD03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MD03>)))
  "Returns md5sum for a message object of type '<MD03>"
  "d37cd3b8b867e41b41f25c01332dacf2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MD03)))
  "Returns md5sum for a message object of type 'MD03"
  "d37cd3b8b867e41b41f25c01332dacf2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MD03>)))
  "Returns full string definition for message of type '<MD03>"
  (cl:format cl:nil "string MD03~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MD03)))
  "Returns full string definition for message of type 'MD03"
  (cl:format cl:nil "string MD03~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MD03>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'MD03))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MD03>))
  "Converts a ROS message object to a list"
  (cl:list 'MD03
    (cl:cons ':MD03 (MD03 msg))
))

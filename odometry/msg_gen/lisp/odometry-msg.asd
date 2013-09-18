
(cl:in-package :asdf)

(defsystem "odometry-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "encoder" :depends-on ("_package_encoder"))
    (:file "_package_encoder" :depends-on ("_package"))
  ))
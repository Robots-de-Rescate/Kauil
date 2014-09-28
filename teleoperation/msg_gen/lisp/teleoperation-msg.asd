
(cl:in-package :asdf)

(defsystem "teleoperation-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Motors" :depends-on ("_package_Motors"))
    (:file "_package_Motors" :depends-on ("_package"))
  ))
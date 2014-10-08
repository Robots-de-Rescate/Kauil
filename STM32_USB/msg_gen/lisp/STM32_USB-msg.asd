
(cl:in-package :asdf)

(defsystem "STM32_USB-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Battery" :depends-on ("_package_Battery"))
    (:file "_package_Battery" :depends-on ("_package"))
    (:file "Encoder" :depends-on ("_package_Encoder"))
    (:file "_package_Encoder" :depends-on ("_package"))
    (:file "Motors" :depends-on ("_package_Motors"))
    (:file "_package_Motors" :depends-on ("_package"))
    (:file "Compass" :depends-on ("_package_Compass"))
    (:file "_package_Compass" :depends-on ("_package"))
  ))
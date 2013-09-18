
(cl:in-package :asdf)

(defsystem "MD03ARIA-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MD03" :depends-on ("_package_MD03"))
    (:file "_package_MD03" :depends-on ("_package"))
    (:file "encoder" :depends-on ("_package_encoder"))
    (:file "_package_encoder" :depends-on ("_package"))
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "Reg" :depends-on ("_package_Reg"))
    (:file "_package_Reg" :depends-on ("_package"))
  ))
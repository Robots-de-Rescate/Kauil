
(cl:in-package :asdf)

(defsystem "MD03ARM-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Reg" :depends-on ("_package_Reg"))
    (:file "_package_Reg" :depends-on ("_package"))
    (:file "MD03" :depends-on ("_package_MD03"))
    (:file "_package_MD03" :depends-on ("_package"))
  ))
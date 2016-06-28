
(cl:in-package :asdf)

(defsystem "imu-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ImuData" :depends-on ("_package_ImuData"))
    (:file "_package_ImuData" :depends-on ("_package"))
  ))
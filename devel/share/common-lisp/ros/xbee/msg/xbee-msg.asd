
(cl:in-package :asdf)

(defsystem "xbee-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "XbeeData" :depends-on ("_package_XbeeData"))
    (:file "_package_XbeeData" :depends-on ("_package"))
  ))
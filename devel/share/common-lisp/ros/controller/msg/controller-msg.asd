
(cl:in-package :asdf)

(defsystem "controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ImuData" :depends-on ("_package_ImuData"))
    (:file "_package_ImuData" :depends-on ("_package"))
    (:file "SonarData" :depends-on ("_package_SonarData"))
    (:file "_package_SonarData" :depends-on ("_package"))
    (:file "MotorCommands" :depends-on ("_package_MotorCommands"))
    (:file "_package_MotorCommands" :depends-on ("_package"))
    (:file "XbeeData" :depends-on ("_package_XbeeData"))
    (:file "_package_XbeeData" :depends-on ("_package"))
  ))
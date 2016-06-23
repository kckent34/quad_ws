
(cl:in-package :asdf)

(defsystem "sonar-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SonarData" :depends-on ("_package_SonarData"))
    (:file "_package_SonarData" :depends-on ("_package"))
  ))
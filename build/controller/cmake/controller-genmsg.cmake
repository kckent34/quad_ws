# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "controller: 4 messages, 0 services")

set(MSG_I_FLAGS "-Icontroller:/home/odroid/quad_ws/src/controller/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(controller_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg" NAME_WE)
add_custom_target(_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "controller" "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg" ""
)

get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/SonarData.msg" NAME_WE)
add_custom_target(_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "controller" "/home/odroid/quad_ws/src/controller/msg/SonarData.msg" ""
)

get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/ImuData.msg" NAME_WE)
add_custom_target(_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "controller" "/home/odroid/quad_ws/src/controller/msg/ImuData.msg" ""
)

get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg" NAME_WE)
add_custom_target(_controller_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "controller" "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(controller
  "/home/odroid/quad_ws/src/controller/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
)
_generate_msg_cpp(controller
  "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
)
_generate_msg_cpp(controller
  "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
)
_generate_msg_cpp(controller
  "/home/odroid/quad_ws/src/controller/msg/ImuData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
)

### Generating Services

### Generating Module File
_generate_module_cpp(controller
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(controller_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(controller_generate_messages controller_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg" NAME_WE)
add_dependencies(controller_generate_messages_cpp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/SonarData.msg" NAME_WE)
add_dependencies(controller_generate_messages_cpp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/ImuData.msg" NAME_WE)
add_dependencies(controller_generate_messages_cpp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg" NAME_WE)
add_dependencies(controller_generate_messages_cpp _controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(controller_gencpp)
add_dependencies(controller_gencpp controller_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS controller_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(controller
  "/home/odroid/quad_ws/src/controller/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
)
_generate_msg_lisp(controller
  "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
)
_generate_msg_lisp(controller
  "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
)
_generate_msg_lisp(controller
  "/home/odroid/quad_ws/src/controller/msg/ImuData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
)

### Generating Services

### Generating Module File
_generate_module_lisp(controller
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(controller_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(controller_generate_messages controller_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg" NAME_WE)
add_dependencies(controller_generate_messages_lisp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/SonarData.msg" NAME_WE)
add_dependencies(controller_generate_messages_lisp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/ImuData.msg" NAME_WE)
add_dependencies(controller_generate_messages_lisp _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg" NAME_WE)
add_dependencies(controller_generate_messages_lisp _controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(controller_genlisp)
add_dependencies(controller_genlisp controller_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS controller_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(controller
  "/home/odroid/quad_ws/src/controller/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
)
_generate_msg_py(controller
  "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
)
_generate_msg_py(controller
  "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
)
_generate_msg_py(controller
  "/home/odroid/quad_ws/src/controller/msg/ImuData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
)

### Generating Services

### Generating Module File
_generate_module_py(controller
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(controller_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(controller_generate_messages controller_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/MotorCommands.msg" NAME_WE)
add_dependencies(controller_generate_messages_py _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/SonarData.msg" NAME_WE)
add_dependencies(controller_generate_messages_py _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/ImuData.msg" NAME_WE)
add_dependencies(controller_generate_messages_py _controller_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/odroid/quad_ws/src/controller/msg/XbeeData.msg" NAME_WE)
add_dependencies(controller_generate_messages_py _controller_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(controller_genpy)
add_dependencies(controller_genpy controller_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS controller_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/controller
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(controller_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/controller
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(controller_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/controller
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(controller_generate_messages_py std_msgs_generate_messages_py)

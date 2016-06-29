# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "xbee: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ixbee:/home/odroid/quad_ws/src/xbee/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(xbee_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg" NAME_WE)
add_custom_target(_xbee_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "xbee" "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(xbee
  "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xbee
)

### Generating Services

### Generating Module File
_generate_module_cpp(xbee
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xbee
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(xbee_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(xbee_generate_messages xbee_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg" NAME_WE)
add_dependencies(xbee_generate_messages_cpp _xbee_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xbee_gencpp)
add_dependencies(xbee_gencpp xbee_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xbee_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(xbee
  "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xbee
)

### Generating Services

### Generating Module File
_generate_module_lisp(xbee
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xbee
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(xbee_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(xbee_generate_messages xbee_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg" NAME_WE)
add_dependencies(xbee_generate_messages_lisp _xbee_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xbee_genlisp)
add_dependencies(xbee_genlisp xbee_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xbee_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(xbee
  "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xbee
)

### Generating Services

### Generating Module File
_generate_module_py(xbee
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xbee
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(xbee_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(xbee_generate_messages xbee_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/xbee/msg/XbeeData.msg" NAME_WE)
add_dependencies(xbee_generate_messages_py _xbee_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(xbee_genpy)
add_dependencies(xbee_genpy xbee_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS xbee_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xbee)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/xbee
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(xbee_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xbee)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/xbee
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(xbee_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xbee)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xbee\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/xbee
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(xbee_generate_messages_py std_msgs_generate_messages_py)

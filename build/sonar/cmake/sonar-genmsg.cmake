# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "sonar: 1 messages, 0 services")

set(MSG_I_FLAGS "-Isonar:/home/odroid/quad_ws/src/sonar/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(sonar_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg" NAME_WE)
add_custom_target(_sonar_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sonar" "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(sonar
  "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sonar
)

### Generating Services

### Generating Module File
_generate_module_cpp(sonar
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sonar
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(sonar_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(sonar_generate_messages sonar_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg" NAME_WE)
add_dependencies(sonar_generate_messages_cpp _sonar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sonar_gencpp)
add_dependencies(sonar_gencpp sonar_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sonar_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(sonar
  "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sonar
)

### Generating Services

### Generating Module File
_generate_module_lisp(sonar
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sonar
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(sonar_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(sonar_generate_messages sonar_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg" NAME_WE)
add_dependencies(sonar_generate_messages_lisp _sonar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sonar_genlisp)
add_dependencies(sonar_genlisp sonar_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sonar_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(sonar
  "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sonar
)

### Generating Services

### Generating Module File
_generate_module_py(sonar
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sonar
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(sonar_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(sonar_generate_messages sonar_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/quad_ws/src/sonar/msg/SonarData.msg" NAME_WE)
add_dependencies(sonar_generate_messages_py _sonar_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sonar_genpy)
add_dependencies(sonar_genpy sonar_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sonar_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sonar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sonar
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(sonar_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sonar)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sonar
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(sonar_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sonar)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sonar\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sonar
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(sonar_generate_messages_py std_msgs_generate_messages_py)

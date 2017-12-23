cmake_minimum_required(VERSION 3.1)

# enforce C++11 features
set(CMAKE_CXX_STANDARD 11)

project(assignment-sinusoids
  LANGUAGES CXX
  VERSION 1.0.0.0)

find_package(YARP REQUIRED)

add_subdirectory(consumer_module)
add_subdirectory(producer_module)

# copy the config file into ${YARP_CONTEXTS_INSTALL_DIR}/${EXE_TARGET_NAME} folder
file(GLOB scripts ${CMAKE_CURRENT_SOURCE_DIR}/app/*.xml)
yarp_install(FILES ${scripts} DESTINATION ${YARP_APPLICATIONS_INSTALL_DIR})


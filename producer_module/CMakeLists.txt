set(EXE_TARGET_NAME producer_module)

find_package(YARP   REQUIRED)

set(${EXE_TARGET_NAME}_SRC
  producer.cpp
  )

set(${EXE_TARGET_NAME}_HDR
  )

add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC} ${${EXE_TARGET_NAME}_HDR})

target_link_libraries(${EXE_TARGET_NAME} ${YARP_LIBRARIES})

install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)

# copy the config file into ${YARP_CONTEXTS_INSTALL_DIR}/${EXE_TARGET_NAME} folder
file(GLOB ${EXE_TARGET_NAME}_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/config/*.ini)
yarp_install(FILES ${${EXE_TARGET_NAME}_CONFIG} DESTINATION ${YARP_CONTEXTS_INSTALL_DIR}/${EXE_TARGET_NAME})

set(EXE_TARGET_NAME consumer_module)

set(${EXE_TARGET_NAME}_SRC
  consumer.cpp
  )

set(${EXE_TARGET_NAME}_HDR
  )

add_executable(${EXE_TARGET_NAME} ${${EXE_TARGET_NAME}_SRC} ${${EXE_TARGET_NAME}_HDR})

target_link_libraries(${EXE_TARGET_NAME} ${YARP_LIBRARIES})

install(TARGETS ${EXE_TARGET_NAME} DESTINATION bin)

SET(FILES 

  sensor-mock-basic.cpp
)

IF (UNIX)
  SET(FILES ${FILES} sensor-w1-suite.cpp)
ENDIF()

ADD_EXECUTABLE(
  test-suite

  ${FILES}
)

TARGET_LINK_LIBRARIES(
  test-suite

  toolcase
  gtest_main 
)

SET(FILES 

  sensor-mock-basic.cpp
  switch-mock-basic.cpp

  hysteresis-nop_when_within_range.cpp
  hysteresis-falls_below_range.cpp
  hysteresis-rises_above_range.cpp
  hysteresis-rises_above_range_when_on.cpp
  hysteresis-set-range.cpp

  kochtopf-suite.cpp
  cloud-kochtopf-suite.cpp
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

ADD_EXECUTABLE(
  test-suite

  sensor-mock-basic.cpp
  sensor-w1-suite.cpp
)

TARGET_LINK_LIBRARIES(
  test-suite

  toolcase
  gtest_main 
)

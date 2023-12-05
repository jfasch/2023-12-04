set(FILES

  sensor-mock.h
  sensor-mock.cpp
)

IF (UNIX)
  set(FILES ${FILES} sensor-w1.h sensor-w1.cpp)
ENDIF()

ADD_LIBRARY(
  toolcase

  ${FILES}
)

TARGET_INCLUDE_DIRECTORIES(toolcase PUBLIC .)

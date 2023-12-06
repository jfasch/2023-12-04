set(FILES

  sensor-mock.h
  sensor-mock.cpp

  switch-mock.h
  switch-mock.cpp

  hysteresis.h
  hysteresis.cpp

  kochtopf.h
  kochtopf.cpp

  cloud-kochtopf.h
  cloud-kochtopf.cpp
)

IF (UNIX)
  set(FILES ${FILES} sensor-w1.h sensor-w1.cpp)
ENDIF()

ADD_LIBRARY(
  toolcase

  ${FILES}
)

TARGET_INCLUDE_DIRECTORIES(toolcase PUBLIC .)

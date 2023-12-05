ADD_EXECUTABLE(w1-loop w1-loop.cpp)
TARGET_LINK_LIBRARIES(w1-loop toolcase)

ADD_EXECUTABLE(reg reg.cpp)
TARGET_LINK_LIBRARIES(reg toolcase)

ADD_EXECUTABLE(w1-loop w1-loop.cpp)
TARGET_LINK_LIBRARIES(w1-loop toolcase)

ADD_EXECUTABLE(shared-weak shared-weak.cpp)

ADD_EXECUTABLE(unique-ptr unique-ptr.cpp)
TARGET_LINK_LIBRARIES(unique-ptr toolcase)

ADD_EXECUTABLE(kochen kochen.cpp)
TARGET_LINK_LIBRARIES(kochen toolcase)


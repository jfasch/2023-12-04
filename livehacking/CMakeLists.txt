ADD_EXECUTABLE(containers containers.cpp)
ADD_EXECUTABLE(map map.cpp)
ADD_EXECUTABLE(vector-sort vector-sort.cpp)
ADD_EXECUTABLE(vector-bad-initialization vector-bad-initialization.cpp)
ADD_EXECUTABLE(lambda lambda.cpp)

ADD_EXECUTABLE(thread thread.cpp)
TARGET_LINK_LIBRARIES(thread Threads::Threads)

ADD_EXECUTABLE(auto auto.cpp)
ADD_EXECUTABLE(class-layout class-layout.cpp)
#ADD_EXECUTABLE(variant variant.cpp)

ADD_EXECUTABLE(intro intro.cpp)
TARGET_LINK_LIBRARIES(intro Threads::Threads)

ADD_EXECUTABLE(storage storage.cpp)

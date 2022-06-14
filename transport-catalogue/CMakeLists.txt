cmake_minimum_required(VERSION 3.10)

project(PathFinder CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)
find_package(Threads REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS graph.proto
                                            map_renderer.proto
                                            svg.proto
                                            transport_catalogue.proto
                                            transport_router.proto)
message(STATIC "Proto srcs: " ${PROTO_SRCS})
message(STATIC "Proto hdrs: " ${PROTO_HDRS})
set(PATHFINDER_FILES domain.h domain.cpp
                     geo.h geo.cpp
                     graph.h graph.proto
                     json.h json.cpp
                     json_builder.h json_builder.cpp
                     json_reader.h json_reader.cpp
                     map_renderer.h map_renderer.cpp map_renderer.proto
                     ranges.h
                     request_handler.h request_handler.cpp
                     router.h
                     serialization.h serialization.cpp
                     svg.h svg.cpp svg.proto
                     transport_catalogue.h transport_catalogue.cpp transport_catalogue.proto
                     transport_router.h transport_router.cpp transport_router.proto
                     main.cpp)

add_executable(transport_catalogue ${PROTO_SRCS} ${PROTO_HDRS} ${PATHFINDER_FILES})
target_include_directories(transport_catalogue PUBLIC ${Protobuf_INCLUDE_DIRS})
target_include_directories(transport_catalogue PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

string(REPLACE "protobuf.lib" "protobufd.lib" "Protobuf_LIBRARY_DEBUG" "${Protobuf_LIBRARY_DEBUG}")
string(REPLACE "protobuf.a" "protobufd.a" "Protobuf_LIBRARY_DEBUG" "${Protobuf_LIBRARY_DEBUG}")
string(REPLACE "protobufd.lib" "protobuf.lib" "Protobuf_LIBRARY_RELEASE" "${Protobuf_LIBRARY_RELEASE}")
string(REPLACE "protobufd.a" "protobuf.a" "Protobuf_LIBRARY" "${Protobuf_LIBRARY_RELEASE}")

target_link_libraries(transport_catalogue "$<IF:$<CONFIG:Debug>,${Protobuf_LIBRARY_DEBUG},${Protobuf_LIBRARY_RELEASE}>" Threads::Threads)

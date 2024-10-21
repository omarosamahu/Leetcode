cmake_minimum_required(VERSION 3.2)
project(GRPCServer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/protos)

add_executable(${PROJECT_NAME} src/server.cpp) 

target_include_directories (${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)


# Link gRPC and Protobuf libraries
target_link_libraries(${PROJECT_NAME}
    protolib
)

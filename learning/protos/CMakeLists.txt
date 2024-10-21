cmake_minimum_required(VERSION 3.2)
project(protolib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Protobuf CONFIG REQUIRED)

find_package(gRPC CONFIG REQUIRED)

set(PRTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/update.proto)
get_target_property (_GRPC_CPP_PLUGIN_EXECUTABLE gRPC::grpc_cpp_plugin LOCATION)

################################################################################
add_library(${PROJECT_NAME} STATIC ${PRTO_FILES})
# Link gRPC and Protobuf libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    gRPC::grpc
    gRPC::grpc++
    gRPC::grpc++_reflection
    protobuf::libprotobuf  # Protobuf library
)


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# PROTO Functions
protobuf_generate(TARGET ${PROJECT_NAME} LANGUAGE cpp)
protobuf_generate(TARGET ${PROJECT_NAME} LANGUAGE grpc
GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
PLUGIN "protoc-gen-grpc=${_GRPC_CPP_PLUGIN_EXECUTABLE}"
)
#################################################################################


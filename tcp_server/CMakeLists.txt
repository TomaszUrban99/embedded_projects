cmake_minimum_required(VERSION 3.16)

project(tcp_server LANGUAGES CXX)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(inc)

# Compiling and linking main executable file
add_executable(tcp_server src/main.cpp)
target_include_directories(tcp_server PUBLIC ../inc)
target_link_libraries(tcp_server tcpServer)
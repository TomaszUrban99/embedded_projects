cmake_minimum_required(VERSION 3.16)

project(tcp_client LANGUAGES CXX)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(inc)

add_executable(tcp_client src/main.cpp)
target_include_directories(tcp_client PUBLIC ../inc)
target_link_libraries(tcp_client tcp_client_class)
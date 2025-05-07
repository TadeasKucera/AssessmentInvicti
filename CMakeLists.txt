cmake_minimum_required(VERSION 3.15)
project(AssignmentInvicti)

set(CMAKE_CXX_STANDARD 17)

find_package(cpr REQUIRED)

add_executable(assignment main.cpp)

target_link_libraries(assignment PRIVATE cpr::cpr)

cmake_minimum_required(VERSION 3.10)

project(MyGraphicsProject)

include_directories(include)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(main src/main.cpp)

target_link_libraries(main OpenGL::GL glfw)


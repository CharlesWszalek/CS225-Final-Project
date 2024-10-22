cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project)

set(CMAKE_CXX_STANDARD 11)

# Find OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Add the executable (replace main.cpp with your actual source file)
add_executable(OpenGL_Project main.cpp)

# Link the libraries
target_link_libraries(OpenGL_Project OpenGL::GL glfw)

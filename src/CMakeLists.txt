cmake_minimum_required(VERSION 3.10)

project(OpenGL_Library C CXX)

add_definitions(-std=c++11)

#----------------------------------------------------------------------
# Add subdirectories
#----------------------------------------------------------------------
add_subdirectory(opengl)
add_subdirectory(gl_func)

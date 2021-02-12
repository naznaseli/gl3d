cmake_minimum_required(VERSION 3.10)

project(OpenGL_Library C CXX)

add_definitions(-std=c++11)

if (MSVC)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/build/install")
else()
endif()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Output directory for applications")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# option
option(OPTION_BUILD_EXAMPLES "Build example programs" ON)
option(OPTION_BUILD_TESTS "Build test programs" OFF)
option(OPTION_BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)
set(CMAKE_DEBUG_POSTFIX "d")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
    #find_package(OpenCV REQUIRED PATHS "C:/lib/opencv-4.3.0/build/install")
else()
    #find_package(OpenCV REQUIRED)
endif()

#add_subdirectory(third_party/googletest)
add_subdirectory(src)
# Examples
if(OPTION_BUILD_EXAMPLES)
    set(IDE_FOLDER "Examples")
    add_subdirectory(examples)
endif()

# Tests
if(OPTION_BUILD_TESTS)
    enable_testing()
    set(IDE_FOLDER "Tests")
    add_subdirectory(tests)
endif()

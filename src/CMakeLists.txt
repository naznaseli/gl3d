set(target opengl)

set(SRCS
    opengl.cpp
    #opengl.hpp
    draw.cpp
    #draw.hpp
)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Fetch contents
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
include(FetchContent)
#:**********************************************************************
FetchContent_Declare(GLFW3
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG master
)

#FetchContent_MakeAvailable(GLFW3)
FetchContent_GetProperties(glfw3)
if(NOT glfw3_POPULATED)
    FetchContent_Populate(glfw3)
    add_subdirectory(${glfw3_SOURCE_DIR} ${glfw3_BINARY_DIR})
endif()

#:**********************************************************************
FetchContent_Declare(GLEW
    #GIT_REPOSITORY https://github.com/nigels-com/glew.git
    #GIT_TAG master
    URL https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip
)

#FetchContent_MakeAvailable(GLEW)
FetchContent_GetProperties(glew)
if(NOT glew_POPULATED)
    FetchContent_Populate(glew)
    add_subdirectory(${glew_SOURCE_DIR}/build/cmake ${glew_BINARY_DIR})
endif()


set(INCLUDE_DIRECTORIES
    ${OpenCV_INCLUDE_DIRS}
    #${GLFW_INCLUDE_DIRS}
    #${GLEW_INCLUDE_DIRS}
    ${glfw3_SOURCE_DIR}/include/
    ${glew_SOURCE_DIR}/include/
)

set(LIBRARIES
    ${OPENGL_LIBRARIES}
    #${GLFW_LIBRARIES}
    #${GLEW_LIBRARIES}
    glfw
    glew
)

add_library(${target} STATIC ${SRCS})

target_compile_options(${target}
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
)

target_include_directories(${target} PUBLIC ${INCLUDE_DIRECTORIES})
target_link_libraries(${target} PUBLIC ${LIBRARIES})
#cmake_minimum_required(VERSION 3.10)

#set(CMAKE_CXX_STANDARD 11)

#if(MSVC)
#    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#    # include directories
#    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#    if(NOT OpenCV_FOUND)
#        #set(OpenCV_DIR "C:/lib/opencv-4.3.0/build/install")
#        #find_package(OpenCV REQUIRED PATHS "C:/lib/opencv-4.3.0/build/install")
#    endif()
#    if(NOT OPENGL_LIBRARIES)
#        set(OPENGL_LIBRARIES "opengl32;glu32")
#    endif()
#    if(NOT GLFW_INCLUDE_DIRS)
#        set(GLFW_INCLUDE_DIRS "C:/lib/glfw/include")
#        set(GLEW_INCLUDE_DIRS "C:/lib/glew/include")
#    endif()
#
#    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#    # Libraries
#    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#    if(CMAKE_VS_PLATFORM_NAME MATCHES "x64")
#        if(NOT GLFW_LIBRARIES)
#            set(GLFW_LIBRARIES "C:/lib/glfw/x64/lib/glfw3.lib")
#            set(GLEW_LIBRARIES "C:/lib/glew/x64/lib/glew32.lib")
#        endif()
#    else()
#        if(NOT GLFW_FOUND)
#            set(GLFW_LIBRARIES "C:/lib/glfw/x86/lib/glfw3.lib")
#            set(GLFW_FOUND TRUE)
#        endif()
#        if(NOT GLEW_FOUND)
#            set(GLEW_LIBRARIES "C:/lib/glew/x86/lib/glew32.lib")
#            set(GLEW_FOUND TRUE)
#        endif()
#    endif()
#else()
#    #find_package(OpenCV REQUIRED)
#    find_package(glfw3 REQUIRED)
#    set(GLFW_LIBRARIES glfw)
#    find_package(GLEW REQUIRED)
#endif()
#
#if(NOT OpenGL_FOUND)
#    find_package(OpenGL REQUIRED)
#endif()

#target_compile_options(${target}
#    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
#    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
#)

#include(FetchContent)
#FetchContent_Declare(GLFW3
#    GIT_REPOSITORY https://github.com/glfw/glfw.git
#    GIT_TAG master
#)
#
##FetchContent_MakeAvailable(GLFW3)
#FetchContent_GetProperties(glfw3)
#if(NOT glfw3_POPULATED)
#    FetchContent_Populate(glfw3)
#    add_subdirectory(${glfw3_SOURCE_DIR} ${glfw3_BINARY_DIR})
#endif()
#
##:**********************************************************************
#FetchContent_Declare(GLEW
#    #GIT_REPOSITORY https://github.com/nigels-com/glew.git
#    #GIT_TAG master
#    URL https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip
#)
#
##FetchContent_MakeAvailable(GLEW)
#FetchContent_GetProperties(glew)
#if(NOT glew_POPULATED)
#    FetchContent_Populate(glew)
#    add_subdirectory(${glew_SOURCE_DIR}/build/cmake ${glew_BINARY_DIR})
#endif()

#----------------------------------------------------------------------
# Add subdirectories
#----------------------------------------------------------------------
#add_subdirectory(opengl)
#add_subdirectory(draw)

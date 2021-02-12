cmake_minimum_required(VERSION 3.0)

set(target example-robot)

set(include_path "./")
set(source_path "./")

if(MSVC)
    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    #+ include directories
    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if(NOT OpenCV_FOUND)
        #set(OpenCV_DIR "C:/lib/opencv-4.3.0/build/install")
        #find_package(OpenCV REQUIRED PATHS "C:/lib/opencv-4.3.0/build/install")
    endif()
    if(NOT OPENGL_LIBRARIES)
        set(OPENGL_LIBRARIES "opengl32;glu32")
    endif()
    if(NOT GLFW_INCLUDE_DIRS)
        set(GLFW_INCLUDE_DIRS "C:/lib/glfw/include")
        set(GLEW_INCLUDE_DIRS "C:/lib/glew/include")
    endif()

    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    #+ libraries
    #++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if(CMAKE_VS_PLATFORM_NAME MATCHES "x64")
        if(NOT GLFW_LIBRARIES)
            set(GLFW_LIBRARIES "C:/lib/glfw/x64/lib/glfw3.lib")
            set(GLEW_LIBRARIES "C:/lib/glew/x64/lib/glew32.lib")
        endif()
    else()
        if(NOT GLFW_FOUND)
            set(GLFW_LIBRARIES "C:/lib/glfw/x86/lib/glfw3.lib")
            set(GLFW_FOUND TRUE)
        endif()
        if(NOT GLEW_FOUND)
            set(GLEW_LIBRARIES "C:/lib/glew/x86/lib/glew32.lib")
            set(GLEW_FOUND TRUE)
        endif()
    endif()
else()
    #find_package(OpenCV REQUIRED)
    find_package(glfw3 REQUIRED)
    set(GLFW_LIBRARIES glfw)
    find_package(GLEW REQUIRED)
endif()

if(NOT OpenGL_FOUND)
    find_package(OpenGL REQUIRED)
endif()

set(headers
    ${include_path}/example-robot.hpp
)

set(sources
    ${source_path}/example-robot.cpp
    ${source_path}/main.cpp
)

add_executable(${target}
    ${sources}
    ${headers}
)

target_compile_options(${target}
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
)
#add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
#add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

target_include_directories(${target}
    PUBLIC
    #${OpenCV_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src/opengl
)

target_link_libraries(${target}
    PUBLIC
    opengl
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
)
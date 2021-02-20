set(target opengl)

set(SRCS
    opengl.cpp
    #opengl.hpp
)

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

#target_include_directories(${target} PUBLIC ${INCLUDE_DIRECTORIES})
#target_link_libraries(${target} PUBLIC ${LIBRARIES})
#target_include_directories(${target}
#    PUBLIC
#    #${GLFW_INCLUDE_DIRS}
#    #${GLEW_INCLUDE_DIRS}
#    ${glfw3_SOURCE_DIR}/include/
#    ${glew_SOURCE_DIR}/include/
#)
#
#target_link_libraries(${target}
#    PUBLIC
#    ${OPENGL_LIBRARIES}
#    #${GLFW_LIBRARIES}
#    ${GLEW_LIBRARIES}
#)



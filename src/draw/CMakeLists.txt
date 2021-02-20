set(target draw)

set(SRCS
    draw.cpp
    draw.hpp
)

add_library(${target} STATIC ${SRCS})

target_compile_options(${target}
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
)

target_include_directories(${target}
    PUBLIC
    #${GLFW_INCLUDE_DIRS}
    #${GLEW_INCLUDE_DIRS}
    ${glfw3_SOURCE_DIR}/include/
    ${glew_SOURCE_DIR}/include/
)

target_link_libraries(${target}
    PUBLIC
    ${OPENGL_LIBRARIES}
    #${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
)

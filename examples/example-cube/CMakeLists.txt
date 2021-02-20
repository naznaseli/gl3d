set(target example-cube)

add_executable(${target} main.cpp)

target_compile_options(${target}
    PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
)

set_target_properties(${target} PROPERTIES FOLDER "${IDE_FOLDER}")

target_include_directories(${target}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${target}
    PRIVATE
    opengl
)

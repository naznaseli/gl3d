set(TARGET example-3d)

add_executable(${TARGET} example-3d.cpp)

if(MSVC)
    target_compile_options(${TARGET}
        PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
        PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
    )
endif()

set_target_properties(${TARGET} PROPERTIES FOLDER "${IDE_FOLDER}")

target_include_directories(${TARGET}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${TARGET}
    PRIVATE
    #libopengl
    gl3d
)

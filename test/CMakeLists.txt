set(target test-example)

include(FetchContent)
#if(NOT GLEW_FOUND)
    FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    #FetchContent_MakeAvailable(GLEW)
    #FetchContent_GetProperties(googletest)
    #if(NOT googletest_POPULATED)
    #    FetchContent_Populate(googletest)
    #    #add_subdirectory(${glew_SOURCE_DIR}/build/cmake ${glew_BINARY_DIR})
    #    add_subdirectory(
    #        ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    #        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    #        EXCLUDE_FROM_ALL
    #    )
    #endif()
    #set(GLEW_INCLUDE_DIRS ${glew_SOURCE_DIR}/include)
    #set(GLEW_LIBRARIES glew)
#endif()

add_executable(${target} test-example.cpp)

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
    gtest
    gtest_main
)


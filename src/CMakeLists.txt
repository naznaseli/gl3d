set(TARGET libopengl)

set(SOURCES
    opengl.cpp
    draw.cpp
)

#++++++++++++++++++++++++++++++++++++++++++++++++++
# ローカルで検索
#++++++++++++++++++++++++++++++++++++++++++++++++++
if(UNIX)
    find_package(glfw3)
    find_package(glew)
    find_package(OpenGL)
else()
    ##パス指定
    #set(GLFW_INCLUDE_DIRS "C:/lib/glfw/include")
    #set(GLEW_INCLUDE_DIRS "C:/lib/glew/include")
    #set(OPENGL_LIBRARIES "opengl32;glu32")
    #if(CMAKE_VS_PLATFORM_NAME MATCHES "x64")
    #    set(GLFW_LIBRARIES "C:/lib/glfw/x64/lib/glfw3.lib")
    #    set(GLFW_FOUND TRUE)
    #    set(GLEW_LIBRARIES "C:/lib/glew/x64/lib/glew32.lib")
    #    set(GLEW_FOUND TRUE)
    #else()
    #    set(GLFW_LIBRARIES "C:/lib/glfw/x86/lib/glfw3.lib")
    #    set(GLFW_FOUND TRUE)
    #    set(GLEW_LIBRARIES "C:/lib/glew/x86/lib/glew32.lib")
    #    set(GLEW_FOUND TRUE)
    #endif()
endif()

#++++++++++++++++++++++++++++++++++++++++++++++++++
# リモートから取得
#++++++++++++++++++++++++++++++++++++++++++++++++++
if(${CMAKE_VERSION} VERSION_LESS "3.11.0")
    message("Please consider to switch to CMake 3.11.0")
else()
    include(FetchContent)
    if(NOT GLFW_FOUND)
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
        set(GLFW_INCLUDE_DIRS ${glfw3_SOURCE_DIR}/include)
        set(GLFW_LIBRARIES glfw)
    endif()

    if(NOT GLEW_FOUND)
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
        set(GLEW_INCLUDE_DIRS ${glew_SOURCE_DIR}/include)
        set(GLEW_LIBRARIES glew)
    endif()
endif()

set(INCLUDE_DIRECTORIES
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

set(LIBRARIES
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
)

#++++++++++++++++++++++++++++++++++++++++++++++++++
# Add libraries
#++++++++++++++++++++++++++++++++++++++++++++++++++
add_library(${TARGET} STATIC ${SOURCES})

if(MSVC)
    target_compile_options(${TARGET}
        PRIVATE $<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>
        PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>
    )
endif()

#++++++++++++++++++++++++++++++++++++++++++++++++++
# Include Directories
#++++++++++++++++++++++++++++++++++++++++++++++++++
target_include_directories(${TARGET} PUBLIC ${INCLUDE_DIRECTORIES})

#++++++++++++++++++++++++++++++++++++++++++++++++++
# Link libraries
#++++++++++++++++++++++++++++++++++++++++++++++++++
target_link_libraries(${TARGET} PUBLIC ${LIBRARIES})

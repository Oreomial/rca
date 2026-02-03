cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_path(GET PROJECT_SOURCE_DIR PARENT_PATH workspace)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${workspace}/output")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}")

include(CPM.cmake)

CPMAddPackage(
    NAME sol2
    GITHUB_REPOSITORY ThePhD/sol2
    GIT_TAG develop
)

CPMAddPackage(
    NAME raylib
    GITHUB_REPOSITORY raysan5/raylib
    GIT_TAG master
)

CPMAddPackage(
    NAME raygui
    GITHUB_REPOSITORY raysan5/raygui
    GIT_TAG master
)

file(GLOB bindings "${workspace}/cpp/bindings/*.cpp")
file(GLOB uis "${workspace}/engine/UIs/*.cpp")

add_executable(game
    ${workspace}/main.cpp
    ${workspace}/engine/mainEngine.cpp

    ${bindings}
    ${uis}
)

target_include_directories(game PRIVATE
    ${workspace}/.
    ${workspace}/cpp/bindings
    ${workspace}/cpp/classes
    C:/lua/include
)

target_link_directories(game PRIVATE
    C:/lua
)

target_include_directories(game PRIVATE
    ${raygui_SOURCE_DIR}/src
)

target_link_libraries(game
    lua54
    sol2::sol2
    raylib
)

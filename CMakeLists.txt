cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game
    main.cpp

    cpp/classes/Instance.cpp

    cpp/bindings/Instance.cpp
    cpp/bindings/Vector3.cpp
)

target_include_directories(game PRIVATE
    .
    cpp/bindings
    cpp/classes
    C:/lua/include
)

target_link_directories(game PRIVATE
    C:/lua
)

target_link_libraries(game
    lua54
)

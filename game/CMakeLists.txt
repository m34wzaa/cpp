cmake_minimum_required(VERSION 3.20)
project(GameSim)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(game
    src/main.cpp
    src/Player.cpp
)

target_include_directories(game PRIVATE include)
target_link_libraries(game sfml-graphics sfml-window sfml-system)
cmake_minimum_required(VERSION 3.16)
project(CellularMap)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS ON)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

add_subdirectory(engine)
add_subdirectory(game)
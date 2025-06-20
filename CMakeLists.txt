# CMakeList.txt : CMake project for CmakeTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.30)

project(CmakeTest)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)

FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(CmakeTest
    CmakeTest.cpp
    Engine.cpp
    EngineInputSystem.cpp
    FontManager.cpp
    GameObject.cpp
    image.cpp
    Object.cpp
    RenderObject.cpp
    SceneCamera.cpp
    SpriteElement.cpp
    TestScript.cpp
    TextBox.cpp
    Behaviour.cpp
    BoxRenderer.cpp
    AABBCollider.cpp
)

target_link_libraries(CmakeTest sfml-graphics)
target_link_libraries(CmakeTest sfml-window)
target_link_libraries(CmakeTest sfml-audio) 
target_link_libraries(CmakeTest sfml-system) 


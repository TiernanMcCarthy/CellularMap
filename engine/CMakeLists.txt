file(GLOB_RECURSE ENGINE_SOURCES src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS include/*.h)

add_library(Engine SHARED
        ${ENGINE_SOURCES}
        ${ENGINE_HEADERS}
)



target_include_directories(Engine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Engine
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-system
)

target_compile_definitions(Engine PRIVATE ENGINE_EXPORTS)

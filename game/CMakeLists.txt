add_executable(CellularMap
        main.cpp
        src/ObjectSpawnList.cpp
        src/SceneCamera.cpp
        src/TestScript.cpp
        src/WorldMap.cpp
        include/TerrainTile.h
)

target_link_libraries(CellularMap PRIVATE Engine)

target_include_directories(CellularMap PRIVATE
        ${PROJECT_SOURCE_DIR}/engine/include
        ${PROJECT_SOURCE_DIR}/game/include
)
if(WIN32)
add_custom_command(TARGET CellularMap POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/engine/libEngine.dll
        $<TARGET_FILE_DIR:CellularMap>
)
endif(WIN32)
message("ENGINE INCLUDE PATH: ${PROJECT_SOURCE_DIR}/engine/include")

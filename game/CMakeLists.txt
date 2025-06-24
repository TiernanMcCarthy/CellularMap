add_executable(CellularMap
        main.cpp
)

target_link_libraries(CellularMap PRIVATE Engine)

target_include_directories(CellularMap PRIVATE
        ${PROJECT_SOURCE_DIR}/engine/include
)

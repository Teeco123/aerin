add_executable(Editor
    app.cpp
)

target_link_libraries(Editor PRIVATE Aerin ECS)
target_include_directories(Editor PRIVATE ${CMAKE_SOURCE_DIR}/aerin)

add_executable(Sandbox
    app.cpp
)

target_link_libraries(Sandbox PRIVATE Aerin)
target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/aerin)

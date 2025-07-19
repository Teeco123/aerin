add_executable(Sandbox
    app.cpp
)

target_link_libraries(Sandbox PRIVATE Test)
target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/engine)

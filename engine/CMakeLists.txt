add_library(Test SHARED
    test.cpp
    test.h
)

target_include_directories(Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

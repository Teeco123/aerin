# Library definition
add_library(MetalCPP ${CMAKE_CURRENT_SOURCE_DIR}/def.cpp)

# Metal cpp headers
target_include_directories(MetalCPP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Metal cpp library (linker)
target_link_libraries(MetalCPP
        "-framework Metal"
        "-framework Foundation"
        "-framework QuartzCore"
        )

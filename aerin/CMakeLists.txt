file(GLOB_RECURSE AERIN_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(Aerin SHARED
	${AERIN_SOURCES}
	aerin.h
)

target_include_directories(Aerin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

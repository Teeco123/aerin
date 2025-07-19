add_library(Aerin SHARED
	app.cpp
  app.h
)

target_include_directories(Aerin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

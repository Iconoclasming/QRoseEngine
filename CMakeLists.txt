cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)
include_directories(QRoseEngine.Core)
set(SOURCE_EXE Demo/MainWin32.cpp)
set(SOURCE_LIB 
	QRoseEngine.Core/Color.cpp
	QRoseEngine.Core/GraphicsDesc.cpp
	QRoseEngine.Core/Size.cpp)
add_library(QRoseEngine.Core STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
target_link_libraries(main QRoseEngine.Core)
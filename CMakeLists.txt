cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)
include_directories(
	QRoseEngine.Core/include)
add_subdirectory(QRoseEngine.Core)

set(DEMO_EXE Demo/MainWin32.cpp)
add_executable(Demo ${DEMO_EXE})
target_link_libraries(Demo ${HEADERS} ${LIBS})
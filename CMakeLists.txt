cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)

include_directories(
	include/QRoseEngine.Core
	include/QRoseEngine.Components)
add_subdirectory(QRoseEngine.Core)
add_subdirectory(QRoseEngine.Components)
add_subdirectory(QRoseEngine)

set(DEMO_EXE QRoseEngine.Demo/MainWin32.cpp)
add_executable(QRoseEngine.Demo ${DEMO_EXE})
target_link_libraries(QRoseEngine.Demo opengl32)
target_link_libraries(QRoseEngine.Demo ${HEADERS} QRoseEngine)
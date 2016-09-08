cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)

include_directories(
	QRoseEngine.Core/include
	QRoseEngine.Components/include)
add_subdirectory(QRoseEngine.Core)
add_subdirectory(QRoseEngine.Components)

set(DEMO_EXE Demo/MainWin32.cpp)
add_executable(Demo ${DEMO_EXE})
target_link_libraries(Demo opengl32)
target_link_libraries(Demo ${HEADERS} QRoseEngine.Core QRoseEngine.Components)
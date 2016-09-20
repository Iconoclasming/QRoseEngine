cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)

add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
include_directories(thirdparty/glm/include)

include_directories(
	include/QRoseEngine.Core
	include/QRoseEngine.Components
	include/QRoseEngine.Platforms)
add_subdirectory(QRoseEngine.Core)
add_subdirectory(QRoseEngine.Components)
add_subdirectory(QRoseEngine.Platforms)

set(DEMO_EXE QRoseEngine.Demo/MainWin32.cpp)
add_executable(QRoseEngine.Demo ${DEMO_EXE})
target_link_libraries(QRoseEngine.Demo opengl32)
target_link_libraries(QRoseEngine.Demo Rpcrt4.lib)
target_link_libraries(QRoseEngine.Demo 
	${HEADERS} 
	QRoseEngine.Core 
	QRoseEngine.Components
	QRoseEngine.Platforms.Win32)
cmake_minimum_required(VERSION 3.6)

project(QRoseEngine)

add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
include_directories(thirdparty/glm/include)

include_directories(
	include/QRoseEngine.Core
	include/QRoseEngine.Graphics.OpenGL
	include/QRoseEngine.Platforms.Win32)
add_subdirectory(src/QRoseEngine.Core)
add_subdirectory(src/QRoseEngine.Graphics.OpenGL)
add_subdirectory(src/QRoseEngine.Platforms.Win32)

set(DEMO_EXE src/QRoseEngine.Demo/MainWin32.cpp)
add_executable(QRoseEngine.Demo ${DEMO_EXE})
target_link_libraries(QRoseEngine.Demo opengl32)
target_link_libraries(QRoseEngine.Demo Rpcrt4.lib)
target_link_libraries(QRoseEngine.Demo 
	${HEADERS} 
	QRoseEngine.Core
	QRoseEngine.Graphics.OpenGL
	QRoseEngine.Platforms.Win32)
cmake_minimum_required(VERSION 3.5)

project(QRoseEngine)

add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
include_directories(thirdparty/glm/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)
include_directories(thirdparty/glfw/include)

add_definitions(-DGLEW_STATIC)
include_directories(thirdparty/glew/include/)
file(COPY thirdparty/glew/lib/Release/Win32/glew32s.lib DESTINATION thirdparty/glew/lib/Release/Win32)

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
	glfw
	thirdparty/glew/lib/Release/Win32/glew32s
	QRoseEngine.Core
	QRoseEngine.Graphics.OpenGL
	QRoseEngine.Platforms.Win32)
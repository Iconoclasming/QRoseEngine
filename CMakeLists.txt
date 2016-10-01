cmake_minimum_required(VERSION 3.5)

project(QRoseEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(NOT MSVC)
 	# g++ doesn't have "abstract" keyword - it's MSVC only feature
	add_definitions(-Dabstract==0)
endif(NOT MSVC)

add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
include_directories(thirdparty/glm/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)
include_directories(thirdparty/glfw/include)

add_definitions(-DGLEW_STATIC)
include_directories(thirdparty/glew/include/)

include_directories(
	include/QRoseEngine.Core
	include/QRoseEngine.Graphics.OpenGL
	include/QRoseEngine.Platforms.Win32)
add_subdirectory(src/QRoseEngine.Core)
add_subdirectory(src/QRoseEngine.Graphics.OpenGL)
add_subdirectory(src/QRoseEngine.Platforms.Win32)

set(DEMO_EXE src/QRoseEngine.Demo/MainWin32.cpp)
add_executable(QRoseEngine.Demo ${DEMO_EXE})

target_link_libraries(QRoseEngine.Demo 
	${HEADERS}
	QRoseEngine.Platforms.Win32
	QRoseEngine.Graphics.OpenGL
	QRoseEngine.Core
	glfw)

if(WIN32)
	file(COPY thirdparty/glew/lib/Release/Win32/glew32s.lib DESTINATION thirdparty/glew/lib/Release/Win32)
	target_link_libraries(QRoseEngine.Demo 
		opengl32
		Rpcrt4.lib
		thirdparty/glew/lib/Release/Win32/glew32s)
endif(WIN32)
if(UNIX)
	find_package(OpenGL REQUIRED)
	file(COPY thirdparty/glew/lib/Release/Linux64/libGLEW.a DESTINATION thirdparty/glew/lib/Release/Linux64)
	target_link_libraries(QRoseEngine.Demo
		/usr/lib/x86_64-linux-gnu/libuuid.a
		${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glew/lib/Release/Linux64/libGLEW.a
		${OPENGL_LIBRARIES})
endif(UNIX)

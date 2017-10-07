cmake_minimum_required(VERSION 3.5)

project(QRoseEngine)

# Copy all assets
file(GLOB QROSEENGINE_DEMO_ASSETS_SHADERS "assets/shaders/*.glsl")
file(COPY ${QROSEENGINE_DEMO_ASSETS_SHADERS} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/assets/shaders")
file(GLOB QROSEENGINE_DEMO_ASSETS_MODELS "assets/models/*.fbx")
file(COPY ${QROSEENGINE_DEMO_ASSETS_MODELS} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/assets/models")
# Add the config file as content in VS project
file(COPY src/QRoseEngine.Demo/config.json DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# We're gonna use C++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# g++ doesn't have "abstract" keyword - it's MSVC only feature, thus we substitute "abstract" by "=0"
if(NOT MSVC)
	add_definitions(-Dabstract==0)
endif(NOT MSVC)

# Prepare GLFW library
include_directories(thirdparty/glfw/include)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)
# Prepare GLEW library
add_definitions(-DGLEW_STATIC)
include_directories(thirdparty/glew/include/)
# Prepare GLM (OpenGL Maths) library
include_directories(thirdparty/glm/include)
# Prepare JSON library
include_directories(thirdparty/json/include)
# Prepare StructureOfArrays library
include_directories(thirdparty/StructureOfArrays)
# Prepare assimp library
include_directories(thirdparty/assimp/include)
file(COPY thirdparty/assimp/bin/assimp-vc140-mt.dll DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY thirdparty/assimp/bin/assimp-vc140-mt.lib DESTINATION thirdparty/assimp/bin)
set(THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/assimp/bin/assimp-vc140-mt.lib)

# We are using GLM as our main mathematics library, so we set the flag
add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
# Add QRose includes
include_directories(include)

# Prepare QRose modules
add_subdirectory(src/QRoseEngine.Core)
add_subdirectory(src/QRoseEngine.Graphics)
add_subdirectory(src/QRoseEngine.Graphics.OpenGL)

# Prepare UUID library
if(WIN32)
	set(THIRDPARTY_LIBS ${THIRDPARTY_LIBS} Rpcrt4.lib)
endif(WIN32)
if(UNIX)
	set(THIRDPARTY_LIBS ${THIRDPARTY_LIBS} /usr/lib/x86_64-linux-gnu/libuuid.a)
endif(UNIX)

# Prepare OpenGL and utilities
if(WIN32)
	file(COPY thirdparty/glew/lib/Release/Win32/glew32s.lib DESTINATION thirdparty/glew/lib/Release/Win32)
	set(THIRDPARTY_LIBS ${THIRDPARTY_LIBS} opengl32 ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glew/lib/Release/Win32/glew32s.lib)
endif(WIN32)
if(UNIX)
	find_package(OpenGL REQUIRED)
	file(COPY thirdparty/glew/lib/Release/Linux64/libGLEW.a DESTINATION thirdparty/glew/lib/Release/Linux64)
	set(THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${OPENGL_LIBRARIES} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glew/lib/Release/Linux64/libGLEW.a)
endif(UNIX)

# Create executables
add_executable(QRoseEngine.Demo
	include/QRoseEngine.Demo/Input.hpp
	include/QRoseEngine.Demo/GLFWInput.hpp
	include/QRoseEngine.Demo/MovableComponent.hpp
	include/QRoseEngine.Demo/MovementData.hpp
	include/QRoseEngine.Demo/MovementSystem.hpp
	src/QRoseEngine.Demo/GLFWInput.cpp
	src/QRoseEngine.Demo/MainWin32.cpp
	src/QRoseEngine.Demo/MovementSystem.cpp
	src/QRoseEngine.Demo/World.cpp)

# Link all libraries against all executables
target_link_libraries(QRoseEngine.Demo
	QRoseEngine.Graphics.OpenGL
	QRoseEngine.Graphics
	QRoseEngine.Core
	glfw
	${THIRDPARTY_LIBS})
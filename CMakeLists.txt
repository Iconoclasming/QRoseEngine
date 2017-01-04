cmake_minimum_required(VERSION 3.5)

project(QRoseEngine)

# We're gonna use C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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

# Prepare Eigen and LBFGS++ libs
include_directories(thirdparty/Eigen/)
include_directories(thirdparty/LBFGSpp/include/)

# Prepare GLM (OpenGL Maths) library
include_directories(thirdparty/glm/include)

# Prepare JSON library
include_directories(thirdparty/json/include)

# We are using GLM as our main mathematics library, so we set the flag
add_definitions(-DQROSEENGINE_USE_OPENGL_MATHEMATICS=1)
# Add QRose includes
include_directories(include)

# Prepare QRose modules
add_subdirectory(src/QRoseEngine.Core)
add_subdirectory(src/QRoseEngine.Graphics)
add_subdirectory(src/QRoseEngine.Graphics.OpenGL)
add_subdirectory(src/QRoseEngine.Demo.Game)
add_subdirectory(src/QRoseEngine.NN)

# Prepare UUID library
if(WIN32)
	set(UUID_LIBRARY Rpcrt4.lib)
endif(WIN32)
if(UNIX)
	set(UUID_LIBRARY /usr/lib/x86_64-linux-gnu/libuuid.a)
endif(UNIX)

# Prepare OpenGL and utilities
if(WIN32)
	file(COPY thirdparty/glew/lib/Release/Win32/glew32s.lib DESTINATION thirdparty/glew/lib/Release/Win32)
	set(OPENGL_AND_UTILS_LIBRARIES opengl32 thirdparty/glew/lib/Release/Win32/glew32s)
endif(WIN32)
if(UNIX)
	find_package(OpenGL REQUIRED)
	file(COPY thirdparty/glew/lib/Release/Linux64/libGLEW.a DESTINATION thirdparty/glew/lib/Release/Linux64)
	set(OPENGL_AND_UTILS_LIBRARIES ${OPENGL_LIBRARIES} ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glew/lib/Release/Linux64/libGLEW.a)
endif(UNIX)

# Create executables
add_executable(QRoseEngine.Demo src/QRoseEngine.Demo/MainWin32.cpp)
add_executable(QRoseEngine.NNDemo src/QRoseEngine.Demo/NeuralNetworkDemo.cpp)

# Link all libraries against all executables
target_link_libraries(QRoseEngine.Demo
	QRoseEngine.Demo.Game
	QRoseEngine.Graphics.OpenGL
	QRoseEngine.Graphics
	QRoseEngine.Core
	glfw
	${UUID_LIBRARY}
	${OPENGL_AND_UTILS_LIBRARIES})
target_link_libraries(QRoseEngine.NNDemo
	QRoseEngine.Core
	QRoseEngine.NN
	${UUID_LIBRARY})
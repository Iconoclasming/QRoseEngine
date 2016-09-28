cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_GRAPHICS_OPENGL_HEADERS
	../../include/QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp
	../../include/QRoseEngine.Graphics.OpenGL/OpenGLRender.hpp
	../../include/QRoseEngine.Graphics.OpenGL/OpenGLResourcesManager.hpp)
set(QROSEENGINE_GRAPHICS_OPENGL_SOURCES
	OpenGLGraphics.cpp
	OpenGLRender.cpp
	OpenGLResourcesManager.cpp)
add_library(QRoseEngine.Graphics.OpenGL STATIC
	${QROSEENGINE_GRAPHICS_OPENGL_HEADERS}
	${QROSEENGINE_GRAPHICS_OPENGL_SOURCES})
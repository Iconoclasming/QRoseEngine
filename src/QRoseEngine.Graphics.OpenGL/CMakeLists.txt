cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_GRAPHICS_OPENGL_HEADERS
	../../include/QRoseEngine.Graphics.OpenGL/OpenGlGraphics.hpp
	../../include/QRoseEngine.Graphics.OpenGL/OpenGlRender.hpp
	../../include/QRoseEngine.Graphics.OpenGL/OpenGlResourcesManager.hpp
	../../include/QRoseEngine.Graphics.OpenGL/OpenGlMesh.hpp)
set(QROSEENGINE_GRAPHICS_OPENGL_SOURCES
	OpenGlGraphics.cpp
	OpenGlRender.cpp
	OpenGlResourcesManager.cpp)
add_library(QRoseEngine.Graphics.OpenGL STATIC
	${QROSEENGINE_GRAPHICS_OPENGL_HEADERS}
	${QROSEENGINE_GRAPHICS_OPENGL_SOURCES})
cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_CORE_HEADERS
	include/Color.h
	include/Engine.h
	include/GraphicsDesc.h
	include/QRoseEngineCore.h
	include/Scene.h
	include/Size.h
	include/WindowDesc.h)
set(HEADERS ${HEADERS} ${QROSEENGINE_CORE_HEADERS})
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	GraphicsDesc.cpp
	Size.cpp)
add_library(QRoseEngine.Core STATIC ${QROSEENGINE_CORE_HEADERS} ${QROSEENGINE_CORE_SOURCES})
set(LIBS ${LIBS} QRoseEngine.Core)
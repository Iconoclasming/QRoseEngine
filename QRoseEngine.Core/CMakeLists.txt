cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_CORE_HEADERS
	include/Color.h
	include/Engine.h
	include/GraphicsDesc.h
	include/QRoseEngineCore.h
	include/Scene.h
	include/Size.h
	include/WindowDesc.h
	include/QCE.h
	include/Streaming.hpp
	include/Uuid.hpp
	include/Entity.hpp)
set(HEADERS ${HEADERS} ${QROSEENGINE_CORE_HEADERS})
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	GraphicsDesc.cpp
	Size.cpp
	Win32EngineFactory.cpp
	WindowDesc.cpp
	Uuid.cpp)
add_library(QRoseEngine.Core STATIC ${QROSEENGINE_CORE_HEADERS} ${QROSEENGINE_CORE_SOURCES})
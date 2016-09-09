cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_CORE_HEADERS
	include/Color.hpp
	include/Engine.hpp
	include/EngineFactory.hpp
	include/GraphicsDesc.hpp
	include/QRoseEngineCore.hpp
	include/Scene.hpp
	include/Size.hpp
	include/WindowDesc.hpp
	include/QCE.hpp
	include/Streaming.hpp
	include/Uuid.hpp
	include/Entity.hpp
	include/SerializationException.hpp)
set(HEADERS ${HEADERS} ${QROSEENGINE_CORE_HEADERS})
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	GraphicsDesc.cpp
	Size.cpp
	Win32EngineFactory.cpp
	WindowDesc.cpp
	Uuid.cpp)
add_library(QRoseEngine.Core STATIC ${QROSEENGINE_CORE_HEADERS} ${QROSEENGINE_CORE_SOURCES})
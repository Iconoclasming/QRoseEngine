cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_PLATFORM_HEADERS
	../../include/QRoseEngine.Platform/Engine.hpp
	../../include/QRoseEngine.Platform/EngineFactory.hpp
	../../include/QRoseEngine.Platform/Scene.hpp)
set(QROSEENGINE_PLATFORM_SOURCES
	Engine.cpp)
add_library(QRoseEngine.Platform STATIC 
	${QROSEENGINE_PLATFORM_HEADERS} 
	${QROSEENGINE_PLATFORM_SOURCES})
cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_PLATFORMS_WIN32_HEADERS
	../../include/QRoseEngine.Platforms.Win32/Win32Engine.hpp)
set(QROSEENGINE_PLATFORMS_WIN32_SOURCES
	Win32EngineFactory.cpp
	Win32Engine.cpp)
add_library(QRoseEngine.Platforms.Win32 STATIC
	${QROSEENGINE_PLATFORMS_WIN32_HEADERS}
	${QROSEENGINE_PLATFORMS_WIN32_SOURCES})
cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_PLATFORMS_WIN32_SOURCES
	QRoseEngine.Platforms.Win32/Win32EngineFactory.cpp)
add_library(QRoseEngine.Platforms.Win32 STATIC
	${QROSEENGINE_PLATFORMS_WIN32_SOURCES})
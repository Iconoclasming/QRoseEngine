cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_PLATFORM_AGNOSTIC_HEADERS
	../../include/QRoseEngine.Platform.Agnostic/AgnosticEngine.hpp)
set(QROSEENGINE_PLATFORM_AGNOSTIC_SOURCES
	AgnosticEngineFactory.cpp
	AgnosticEngine.cpp)
add_library(QRoseEngine.Platform.Agnostic STATIC
	${QROSEENGINE_PLATFORM_AGNOSTIC_HEADERS}
	${QROSEENGINE_PLATFORM_AGNOSTIC_SOURCES})
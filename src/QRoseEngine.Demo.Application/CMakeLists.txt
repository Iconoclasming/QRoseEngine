cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_DEMO_APPLICATION_HEADERS
	../../include/QRoseEngine.Demo.Application/EntitiesComponentsService.hpp)
set(QROSEENGINE_DEMO_APPLICATION_SOURCES
	EntitiesComponentsService.cpp)
add_library(QRoseEngine.Demo.Application STATIC 
	${QROSEENGINE_DEMO_APPLICATION_HEADERS} 
	${QROSEENGINE_DEMO_APPLICATION_SOURCES})
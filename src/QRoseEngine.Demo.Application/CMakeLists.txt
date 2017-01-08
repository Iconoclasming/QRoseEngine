cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_DEMO_APPLICATION_HEADERS
	../../include/QRoseEngine.Demo.Application/EntitiesComponentsService.hpp
	../../include/QRoseEngine.Demo.Application/GLFWInput.hpp)
set(QROSEENGINE_DEMO_APPLICATION_SOURCES
	EntitiesComponentsService.cpp
	GLFWInput.cpp)
add_library(QRoseEngine.Demo.Application STATIC 
	${QROSEENGINE_DEMO_APPLICATION_HEADERS} 
	${QROSEENGINE_DEMO_APPLICATION_SOURCES})
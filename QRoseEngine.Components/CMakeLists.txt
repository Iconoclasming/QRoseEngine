cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_COMPONENTS_HEADERS
	../include/QRoseEngine.Components/TransformationComponent.hpp
	../include/QRoseEngine.Components/MeshComponent.hpp)
set(HEADERS ${HEADERS} ${QROSEENGINE_COMPONENTS_HEADERS})
set(QROSEENGINE_COMPONENTS_SOURCES
	TransformationComponent.cpp
	MeshComponent.cpp)
add_library(QRoseEngine.Components STATIC ${QROSEENGINE_COMPONENTS_HEADERS} ${QROSEENGINE_COMPONENTS_SOURCES})
cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_GRAPHICS_HEADERS
	../../include/QRoseEngine.Graphics/GraphicsDesc.hpp
	../../include/QRoseEngine.Graphics/Render.hpp
	../../include/QRoseEngine.Graphics/RenderSystem.hpp
	../../include/QRoseEngine.Graphics/WindowDesc.hpp
	../../include/QRoseEngine.Graphics/Graphics.hpp
	../../include/QRoseEngine.Graphics/MeshHandle.hpp)
set(QROSEENGINE_GRAPHICS_COMPONENTS_HEADERS
	../../include/QRoseEngine.Graphics/Components/MeshComponent.hpp
	../../include/QRoseEngine.Graphics/Components/CameraComponent.hpp)
set(QROSEENGINE_GRAPHICS_SOURCES
	GraphicsDesc.cpp
	RenderSystem.cpp
	WindowDesc.cpp)
set(QROSEENGINE_GRAPHICS_COMPONENTS_SOURCES
	Components/MeshComponent.cpp
	Components/CameraComponent.cpp)
source_group("Components" FILES ${QROSEENGINE_GRAPHICS_COMPONENTS_HEADERS} ${QROSEENGINE_GRAPHICS_COMPONENTS_SOURCES})
add_library(QRoseEngine.Graphics STATIC 
	${QROSEENGINE_GRAPHICS_HEADERS} 
	${QROSEENGINE_GRAPHICS_COMPONENTS_HEADERS}
	${QROSEENGINE_GRAPHICS_SOURCES}
	${QROSEENGINE_GRAPHICS_COMPONENTS_SOURCES})
cmake_minimum_required(VERSION 3.6)

set(QROSEENGINE_CORE_HEADERS
	../../include/QRoseEngine.Core/Color.hpp
	../../include/QRoseEngine.Core/Engine.hpp
	../../include/QRoseEngine.Core/EngineFactory.hpp
	../../include/QRoseEngine.Core/GraphicsDesc.hpp
	../../include/QRoseEngine.Core/QRoseEngineCore.hpp
	../../include/QRoseEngine.Core/Scene.hpp
	../../include/QRoseEngine.Core/Size.hpp
	../../include/QRoseEngine.Core/WindowDesc.hpp
	../../include/QRoseEngine.Core/QCE.hpp
	../../include/QRoseEngine.Core/Streaming.hpp
	../../include/QRoseEngine.Core/Uuid.hpp
	../../include/QRoseEngine.Core/Entity.hpp
	../../include/QRoseEngine.Core/SerializationException.hpp
	../../include/QRoseEngine.Core/Vector.hpp
	../../include/QRoseEngine.Core/ComponentsRepository.hpp
	../../include/QRoseEngine.Core/EntitiesRepository.hpp
	../../include/QRoseEngine.Core/EntitiesComponentsRepository.hpp
	../../include/QRoseEngine.Core/EntitiesComponentsService.hpp
	../../include/QRoseEngine.Core/System.hpp
	../../include/QRoseEngine.Core/ManagedPtr.hpp
	../../include/QRoseEngine.Core/RenderSystem.hpp
	../../include/QRoseEngine.Core/Render.hpp
	../../include/QRoseEngine.Core/Delegate.hpp
	../../include/QRoseEngine.Core/Event.hpp
	../../include/QRoseEngine.Core/EventInvoker.hpp)
set(QROSEENGINE_CORE_COMPONENTS_HEADERS
	../../include/QRoseEngine.Core/Components/TransformationComponent.hpp
	../../include/QRoseEngine.Core/Components/MeshComponent.hpp)
set(HEADERS ${HEADERS} ${QROSEENGINE_CORE_HEADERS} ${QROSEENGINE_CORE_COMPONENTS_HEADERS})
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	GraphicsDesc.cpp
	Size.cpp
	WindowDesc.cpp
	Uuid.cpp
	Entity.cpp
	Scene.cpp
	Streaming.cpp
	Vector3.cpp
	EntitiesComponentsService.cpp
	EntitiesRepository.cpp
	EntitiesComponentsRepository.cpp
	RenderSystem.cpp)
set(QROSEENGINE_CORE_COMPONENTS_SOURCES
	Components/TransformationComponent.cpp
	Components/MeshComponent.cpp)
source_group("Components" FILES ${QROSEENGINE_CORE_COMPONENTS_HEADERS} ${QROSEENGINE_CORE_COMPONENTS_SOURCES})
add_library(QRoseEngine.Core STATIC 
	${QROSEENGINE_CORE_HEADERS} 
	${QROSEENGINE_CORE_COMPONENTS_HEADERS}
	${QROSEENGINE_CORE_SOURCES}
	${QROSEENGINE_CORE_COMPONENTS_SOURCES})
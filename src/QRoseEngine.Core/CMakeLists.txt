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
	../../include/QRoseEngine.Core/ComponentsEntitiesRepository.hpp)
set(HEADERS ${HEADERS} ${QROSEENGINE_CORE_HEADERS})
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	GraphicsDesc.cpp
	Size.cpp
	WindowDesc.cpp
	Uuid.cpp
	Entity.cpp
	Scene.cpp
	Streaming.cpp
	Vector3.cpp)
add_library(QRoseEngine.Core STATIC ${QROSEENGINE_CORE_HEADERS} ${QROSEENGINE_CORE_SOURCES})
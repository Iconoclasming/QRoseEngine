cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_CORE_HEADERS
	../../include/QRoseCore.hpp
	../../include/QRoseEngine.Core/Color.hpp
	../../include/QRoseEngine.Core/Size.hpp
	../../include/QRoseEngine.Core/QCE.hpp
	../../include/QRoseEngine.Core/Streaming.hpp
	../../include/QRoseEngine.Core/Uuid.hpp
	../../include/QRoseEngine.Core/EntityHandle.hpp
	../../include/QRoseEngine.Core/SerializationException.hpp
	../../include/QRoseEngine.Core/Vector.hpp
	../../include/QRoseEngine.Core/Vector3.hpp
	../../include/QRoseEngine.Core/Vector4.hpp
	../../include/QRoseEngine.Core/System.hpp
	../../include/QRoseEngine.Core/ManagedPtr.hpp
	../../include/QRoseEngine.Core/Delegate.hpp
	../../include/QRoseEngine.Core/Event.hpp
	../../include/QRoseEngine.Core/EventInvoker.hpp
	../../include/QRoseEngine.Core/Matrix4x4.hpp
	../../include/QRoseEngine.Core/World.hpp
	../../include/QRoseEngine.Core/Storage.hpp
	../../include/QRoseEngine.Core/Assert.hpp)
set(QROSEENGINE_CORE_COMPONENTS_HEADERS
	../../include/QRoseEngine.Core/Components/TransformComponent.hpp)
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	Size.cpp
	Uuid.cpp
	Streaming.cpp
	Vector3.cpp
	Vector4.cpp
	Matrix4x4.cpp)
set(QROSEENGINE_CORE_COMPONENTS_SOURCES
	Components/TransformComponent.cpp)
source_group("Components" FILES ${QROSEENGINE_CORE_COMPONENTS_HEADERS} ${QROSEENGINE_CORE_COMPONENTS_SOURCES})
add_library(QRoseEngine.Core STATIC 
	${QROSEENGINE_CORE_HEADERS} 
	${QROSEENGINE_CORE_COMPONENTS_HEADERS}
	${QROSEENGINE_CORE_SOURCES}
	${QROSEENGINE_CORE_COMPONENTS_SOURCES})
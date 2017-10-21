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
	../../include/QRoseEngine.Core/Vector2.hpp
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
	../../include/QRoseEngine.Core/DebugRender.hpp
	../../include/QRoseEngine.Core/IDebugRender.hpp
	../../include/QRoseEngine.Core/NullDebugRender.hpp
	../../include/QRoseEngine.Core/Angle.hpp)
set(QROSEENGINE_CORE_COMPONENTS_HEADERS
	../../include/QRoseEngine.Core/Components/TransformComponent.hpp)
set(QROSEENGINE_CORE_SOURCES
	Color.cpp
	Size.cpp
	Uuid.cpp
	Streaming.cpp
	Vector2.cpp
	Vector3.cpp
	Vector4.cpp
	Matrix4x4.cpp
	DebugRender.cpp
	Angle.cpp)
set(QROSEENGINE_CORE_COMPONENTS_SOURCES
	Components/TransformComponent.cpp)
source_group("Components" FILES ${QROSEENGINE_CORE_COMPONENTS_HEADERS} ${QROSEENGINE_CORE_COMPONENTS_SOURCES})
add_library(QRoseEngine.Core STATIC 
	${QROSEENGINE_CORE_HEADERS} 
	${QROSEENGINE_CORE_COMPONENTS_HEADERS}
	${QROSEENGINE_CORE_SOURCES}
	${QROSEENGINE_CORE_COMPONENTS_SOURCES})
cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_DEMO_GAME_HEADERS
	../../include/QRoseEngine.Demo.Game/DemoGame.hpp
	../../include/QRoseEngine.Demo.Game/MovableComponent.hpp
	../../include/QRoseEngine.Demo.Game/MovementSystem.hpp)
set(QROSEENGINE_DEMO_GAME_SOURCES
	DemoGame.cpp
	MovableComponent.cpp
	MovementSystem.cpp)
add_library(QRoseEngine.Demo.Game STATIC 
	${QROSEENGINE_DEMO_GAME_HEADERS} 
	${QROSEENGINE_DEMO_GAME_SOURCES})
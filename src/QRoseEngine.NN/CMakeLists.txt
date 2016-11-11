cmake_minimum_required(VERSION 3.5)

set(QROSEENGINE_NN_HEADERS
	../../include/QRoseNN.hpp
	../../include/QRoseEngine.NN/NeuralNetwork.hpp
	../../include/QRoseEngine.NN/Functions.hpp
	../../include/QRoseEngine.NN/NeuralNetworkTrainer.hpp)
#set(QROSEENGINE_NN_HEADERS_EXPORT
#	../../include/QRoseEngine.NN/QRoseNN.hpp)
#set(HEADERS ${HEADERS} ${QROSEENGINE_NN_HEADERS})
set(QROSEENGINE_NN_SOURCES
	Functions.cpp
	NeuralNetwork.cpp
	NeuralNetworkTrainer.cpp)
add_library(QRoseEngine.NN STATIC 
	${QROSEENGINE_NN_HEADERS} 
	${QROSEENGINE_NN_SOURCES})
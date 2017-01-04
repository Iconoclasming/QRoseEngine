#pragma once

#include "../QRoseEngine.Core/Matrix.hpp"
#include "../QRoseEngine.NN/NeuralNetwork.hpp"
#include "../QRoseEngine.Core/ManagedPtr.hpp"

namespace QRose
{
	class NeuralNetworkTrainer
	{
	public:

		void Train(NeuralNetwork& neuralNetwork, const Matrix<float>& data, const Matrix<float>& desiredOutput);

	private:
	};
}
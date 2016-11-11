#pragma once

#include "../QRoseEngine.Core/Matrix.hpp"

namespace QRose
{
	class NeuralNetwork
	{
	public:
		NeuralNetwork(int inputNeuronsCount, int hiddenNeuronsCount);
		~NeuralNetwork();

		Matrix<float> Forward(const Matrix<float>& data) const;

	private:
		Matrix<float> inputWeights;
		Matrix<float> outputWeights;
	};
}
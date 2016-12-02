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
		float Cost(const Matrix<float>& data, const Matrix<float>& desiredOutput);
		
		Matrix<float> GetInputWeights() const;
		Matrix<float> GetOutputWeights() const;
		int GetInputWeightsCount() const;
		int GetOutputWeightsCount() const;

	private:
		Matrix<float> inputWeights;
		Matrix<float> outputWeights;
		Matrix<float> output;
	};
}
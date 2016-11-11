#pragma once

#include "../QRoseEngine.Core/Matrix.hpp"

namespace QRose
{
	class NeuralNetworkTrainer
	{
	public:
		NeuralNetworkTrainer(const Matrix<float>& desiredOutput);

		float Cost(const Matrix<float>& actualOutput);

	private:
		Matrix<float> desiredOutput;
	};
}
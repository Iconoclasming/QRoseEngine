#pragma once

#include "../QRoseEngine.Core/Matrix.hpp"

namespace QRose
{
	class Functions
	{
	public:
		static float Sigmoid(float x);
		static Matrix<float> SigmoidMatrix(Matrix<float> matrix);
		static float SigmoidPrime(float x);
		static Matrix<float> SigmoidPrimeMatrix(Matrix<float> matrix);
	};
}
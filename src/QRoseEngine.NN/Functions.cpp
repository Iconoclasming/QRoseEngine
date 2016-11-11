#include "QRoseEngine.NN/Functions.hpp"

using namespace QRose;

float Functions::Sigmoid(float x)
{
	return 1.0f / (1.0f + std::exp(-x));
}

Matrix<float> Functions::SigmoidMatrix(Matrix<float> matrix)
{
	return matrix.Feed(Sigmoid);
}

float Functions::SigmoidPrime(float x)
{
	return std::exp(-x) / std::pow(1.0f + std::exp(-x), 2.0f);
}

Matrix<float> Functions::SigmoidPrimeMatrix(Matrix<float> matrix)
{
	return matrix.Feed(SigmoidPrime);
}
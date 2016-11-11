#include "QRoseEngine.NN/NeuralNetwork.hpp"
#include "QRoseEngine.NN/Functions.hpp"

using namespace QRose;

NeuralNetwork::NeuralNetwork(int inputNeuronsCount, int hiddenNeuronsCount)
{
	if(inputNeuronsCount <= 0)
	{
		throw std::invalid_argument("input neurons count must be greater then zero");
	}
	if(hiddenNeuronsCount <= 0)
	{
		throw std::invalid_argument("hidden neurons count must be greater then zero");
	}
	inputWeights = Matrix<float>::Random(inputNeuronsCount, hiddenNeuronsCount, 0.0f, 1.0f);
	outputWeights = Matrix<float>::Random(hiddenNeuronsCount, 1, 0.0f, 1.0f);
}

NeuralNetwork::~NeuralNetwork()
{
}

Matrix<float> NeuralNetwork::Forward(const Matrix<float>& data) const
{
	// TODO: data dimensions check
	Matrix<float> hiddenLayerInput = data * inputWeights;
	Matrix<float> hiddenLayerOutput = Functions::SigmoidMatrix(hiddenLayerInput);
	Matrix<float> outputLayerInput = hiddenLayerOutput * outputWeights;
	Matrix<float> outputLayerOutput = Functions::SigmoidMatrix(outputLayerInput);
	return outputLayerOutput;
}
#include "QRoseEngine.NN/NeuralNetworkTrainer.hpp"

using namespace QRose;

NeuralNetworkTrainer::NeuralNetworkTrainer(const Matrix<float>& desiredOutput) : desiredOutput(desiredOutput)
{
}

float NeuralNetworkTrainer::Cost(const Matrix<float>& actualOutput)
{
	if(actualOutput.GetRowsCount() != desiredOutput.GetRowsCount() 
		|| actualOutput.GetColumnsCount() != desiredOutput.GetColumnsCount())
	{
		throw std::invalid_argument("data dimensions must match");
	}
	float cost = 0.0;
	for(int i = 0; i < actualOutput.GetRowsCount(); i++)
	{
		for(int j = 0; j < actualOutput.GetColumnsCount(); j++)
		{
			double error = 0.5f * std::pow(desiredOutput[i][j] - actualOutput[i][j], 2.0f);
			cost += error;
		}
	}
	return cost;
}
#include "QRoseEngine.NN/NeuralNetworkTrainer.hpp"

#include <LBFGS.h>

using namespace QRose;

Matrix<float> ToMatrix(const Eigen::VectorXf& vector, int rows, int cols);
Eigen::VectorXf RavelMatrix(const Matrix<float>& matrix);
Eigen::VectorXf Concat(const Eigen::VectorXf& first, const Eigen::VectorXf& second);
Eigen::VectorXf Subvector(const Eigen::VectorXf& vector, int start, int end);

void NeuralNetworkTrainer::Train(NeuralNetwork& neuralNetwork, const Matrix<float>& data, const Matrix<float>& desiredOutput)
{
	const int n = 10;
	// Set up parameters
	LBFGSpp::LBFGSParam<float> param;
	param.epsilon = 1e-6;
	param.max_iterations = 1;
	// Create solver and function object
	LBFGSpp::LBFGSSolver<float> solver(param);
	auto costFunction = 
		[&neuralNetwork, &data, &desiredOutput](const Eigen::VectorXf& weightsVector, Eigen::VectorXf& gradient)
	{
		//Eigen::VectorXf inputWeights = Subvector(weightsVector, 0, )
		//Matrix<float> weights = UnrollVector(weightsVector, rows, cols);
		// neuralNetwork.SetWeights(weights);
		// float cost = neuralNetwork.Cost(data, desiredOutput);
		// Matrix<float> gradientMatrix = ComputeGradients(neuralNetwork, data, desiredOutput);
		// gradient = RollMatrix(gradientMatrix);
		// return cost;
		return 1.0f;
	};
	Eigen::VectorXf weightsVector = Concat(RavelMatrix(neuralNetwork.GetInputWeights()),
		RavelMatrix(neuralNetwork.GetOutputWeights()));
	std::vector<float> values;
	for (int i = 0; i < weightsVector.size(); i++)
	{
		values.push_back(weightsVector[i]);
	}
	float cost;
	solver.minimize(costFunction, weightsVector, cost);
}

Eigen::VectorXf RavelMatrix(const Matrix<float>& matrix)
{
	Eigen::VectorXf vector;
	vector.resize(matrix.GetRowsCount() * matrix.GetColumnsCount());
	for (int m = 0; m < matrix.GetRowsCount(); m++)
	{
		for (int n = 0; n < matrix.GetColumnsCount(); n++)
		{
			vector(matrix.GetColumnsCount() * m + n) = matrix[m][n];
		}
	}
	return vector;
}

Eigen::VectorXf Concat(const Eigen::VectorXf & first, const Eigen::VectorXf & second)
{
	Eigen::VectorXf vector;
	vector.resize(first.size() + second.size());
	for (int i = 0; i < first.size(); i++)
	{
		vector(i) = first[i];
	}
	for (int i = 0; i < second.size(); i++)
	{
		vector(first.size() + i) = second[i];
	}
	return vector;
}

Eigen::VectorXf Subvector(const Eigen::VectorXf & vector, int start, int end)
{

	return Eigen::VectorXf();
}

Matrix<float> ToMatrix(const Eigen::VectorXf & vector, int rows, int cols)
{
	if (vector.size() != rows * cols)
	{
		throw std::runtime_error("vector size must be equal to rows*cols");
	}



	return Matrix<float>();
}

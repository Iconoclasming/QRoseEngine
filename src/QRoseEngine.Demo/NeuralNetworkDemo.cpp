#include <QRoseNN.hpp>

#include <Eigen/Core>

void main()
{
	QRose::Matrix<float> data(
		{
			{ 3.0, 5.0 },
			{ 5.0, 1.0 },
			{ 10.0, 2.0 }
		}
	);
	QRose::Matrix<float> desiredOutput(
		{
			{ 0.75f },
			{ 0.82f },
			{ 0.93f }
		}
	);
	QRose::NeuralNetwork neuralNetwork(2, 3);
	QRose::NeuralNetworkTrainer trainer;
	trainer.Train(neuralNetwork, data, desiredOutput);
}
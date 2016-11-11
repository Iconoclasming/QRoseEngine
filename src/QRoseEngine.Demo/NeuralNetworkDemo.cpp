#include <QRoseNN.hpp>

void main()
{
	QRose::Matrix<float> data(
		{
			{ 3.0, 5.0 },
			{ 5.0, 1.0 },
			{ 10.0, 2.0 }
		}
	);
	QRose::Matrix<float> desiredResult(
		{
			{ 0.75f },
			{ 0.82f },
			{ 0.93f }
		}
	);
	QRose::RNDGen<int> rnd(5, 6);
	QRose::NeuralNetwork neuralNetwork(2, 3);
	QRose::NeuralNetworkTrainer trainer(desiredResult);	// TODO: pass a network to the trainer for him to train it
	QRose::Matrix<float> actualOutput = neuralNetwork.Forward(data);
	float cost = trainer.Cost(actualOutput);
}
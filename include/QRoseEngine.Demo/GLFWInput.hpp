#pragma once

#include <GLFW/glfw3.h>
#include <QRoseEngine.Demo/Input.hpp>

namespace QRose
{
	class GLFWInput : public Input
	{
	public:
		GLFWInput(GLFWwindow* pWindow);
		~GLFWInput();

		MovementData GetMovementData() const override;

		void SetForeAftMovementSpeed(float speed);
		void SetRightLeftMovementSpeed(float speed);

	private:
		float foreAftMovementSpeed;
		float rightLeftMovementSpeed;
	};
}
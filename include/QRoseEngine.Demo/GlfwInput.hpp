#pragma once

#include <GLFW/glfw3.h>
#include <QRoseEngine.Demo/Input.hpp>

namespace QRose
{
	class GlfwInput : public Input
	{
	public:
		explicit GlfwInput(GLFWwindow* pWindow);
		~GlfwInput();

		MovementData GetMovementData() const override;

		void SetForeAftMovementSpeed(float speed);
		void SetRightLeftMovementSpeed(float speed);

	private:
		float foreAftMovementSpeed;
		float rightLeftMovementSpeed;
	};
}
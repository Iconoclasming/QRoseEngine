#include <QRoseEngine.Demo/GlfwInput.hpp>

using namespace QRose;

int g_WKeyPressed = 0;
int g_AKeyPressed = 0;
int g_SKeyPressed = 0;
int g_DKeyPressed = 0;

void KeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods);
void CursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos);

GlfwInput::GlfwInput(GLFWwindow* pWindow)
{
	glfwSetKeyCallback(pWindow, KeyCallback);
	glfwSetCursorPosCallback(pWindow, CursorPositionCallback);
	SetForeAftMovementSpeed(0.05f);
	SetRightLeftMovementSpeed(0.05f);
}

GlfwInput::~GlfwInput()
{
}

MovementData GlfwInput::GetMovementData() const
{
	MovementData movementData;
	movementData.forward = g_WKeyPressed * foreAftMovementSpeed;
	movementData.backward = g_SKeyPressed * foreAftMovementSpeed;
	movementData.right = g_DKeyPressed * rightLeftMovementSpeed;
	movementData.left = g_AKeyPressed * rightLeftMovementSpeed;
	return movementData;
}

void GlfwInput::SetForeAftMovementSpeed(float speed)
{
	foreAftMovementSpeed = speed;
}

void GlfwInput::SetRightLeftMovementSpeed(float speed)
{
	rightLeftMovementSpeed = speed;
}

void KeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_W:
		g_WKeyPressed = action > 0;
		break;

	case GLFW_KEY_A:
		g_AKeyPressed = action > 0;
		break;

	case GLFW_KEY_S:
		g_SKeyPressed = action > 0;
		break;

	case GLFW_KEY_D:
		g_DKeyPressed = action > 0;
		break;
	default: ;
	}
}

void CursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos)
{
}
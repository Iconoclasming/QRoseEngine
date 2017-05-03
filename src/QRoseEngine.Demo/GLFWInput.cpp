#include <QRoseEngine.Demo/GLFWInput.hpp>

using namespace QRose;

int g_WKeyPressed = 0;
int g_AKeyPressed = 0;
int g_SKeyPressed = 0;
int g_DKeyPressed = 0;

void KeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods);
void CursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos);

GLFWInput::GLFWInput(GLFWwindow* pWindow)
{
	glfwSetKeyCallback(pWindow, KeyCallback);
	glfwSetCursorPosCallback(pWindow, CursorPositionCallback);
	SetForeAftMovementSpeed(0.05f);
	SetRightLeftMovementSpeed(0.05f);
}

GLFWInput::~GLFWInput()
{
}

MovementData GLFWInput::GetMovementData() const
{
	MovementData movementData;
	movementData.forward = g_WKeyPressed * foreAftMovementSpeed;
	movementData.backward = g_SKeyPressed * foreAftMovementSpeed;
	movementData.right = g_DKeyPressed * rightLeftMovementSpeed;
	movementData.left = g_AKeyPressed * rightLeftMovementSpeed;
	return movementData;
}

void GLFWInput::SetForeAftMovementSpeed(float speed)
{
	foreAftMovementSpeed = speed;
}

void GLFWInput::SetRightLeftMovementSpeed(float speed)
{
	rightLeftMovementSpeed = speed;
}

void KeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case GLFW_KEY_W:
		g_WKeyPressed = action;
		break;

	case GLFW_KEY_A:
		g_AKeyPressed = action;
		break;

	case GLFW_KEY_S:
		g_SKeyPressed = action;
		break;

	case GLFW_KEY_D:
		g_DKeyPressed = action;
		break;
	}
}

void CursorPositionCallback(GLFWwindow* pWindow, double xpos, double ypos)
{
}
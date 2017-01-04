#include "QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp"

using namespace QRose;

OpenGLGraphics::OpenGLGraphics() : pWindow(nullptr)
{
}

OpenGLGraphics::~OpenGLGraphics()
{
}

void OpenGLGraphics::Initialize(const GraphicsDesc& graphicsDesc)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	pWindow = glfwCreateWindow(graphicsDesc.windowDesc.GetWindowSize().GetWidth(),
		graphicsDesc.windowDesc.GetWindowSize().GetHeight(), graphicsDesc.windowDesc.GetWindowName().c_str(),
		nullptr, nullptr);
	if (pWindow == nullptr)
	{
		throw std::runtime_error("failed to create GLFW window");
	}
	glfwMakeContextCurrent(pWindow);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("failed to initialize GLEW");
	}
	int width, height;
	glfwGetFramebufferSize(pWindow, &width, &height);
	glViewport(0, 0, width, height);

	pResourcesManager = NewManaged<OpenGLResourcesManager>();
	pResourcesManager->LoadDefaultShaderProgram();
	pRender = NewManaged<OpenGLRender>(pResourcesManager, pWindow);
	pRender->SetClearColor(graphicsDesc.backgroundColor);
}

Handle OpenGLGraphics::LoadMesh(const std::string& path)
{
	return pResourcesManager->LoadMesh(path);
}

Handle OpenGLGraphics::CreateBoxMesh(const Vector3& size)
{
	return pResourcesManager->LoadBoxMesh(size);
}

Ptr<OpenGLRender> OpenGLGraphics::GetRender() const
{
	return pRender;
}

GLFWwindow* OpenGLGraphics::GetWindow() const
{
	return pWindow;
}
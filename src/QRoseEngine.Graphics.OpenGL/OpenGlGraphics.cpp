#include "QRoseEngine.Graphics.OpenGL/OpenGlGraphics.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "QRoseEngine.Core/DebugRender.hpp"

using namespace QRose;

OpenGlGraphics::OpenGlGraphics() : pWindow(nullptr)
{
}

OpenGlGraphics::~OpenGlGraphics()
{
}

void OpenGlGraphics::Initialize(const GraphicsDesc& graphicsDesc, const std::string& assetsDirectory)
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

	pResourcesManager = NewManaged<OpenGlResourcesManager>();
	pResourcesManager->LoadDefaultShaderProgram(assetsDirectory + "\\shaders\\demo_vertex_shader.glsl",
		assetsDirectory + "\\shaders\\demo_fragment_shader.glsl");
	pRender = NewManaged<OpenGlRender>(pResourcesManager, pWindow);
	pRender->SetClearColor(graphicsDesc.backgroundColor);
	pRender->InitializeDebugDrawing();
	DebugRender::SetDebugRender(pRender);
}

MeshHandle OpenGlGraphics::LoadMesh(const std::string& path)
{
	return pResourcesManager->LoadMesh(path);
}

MeshHandle OpenGlGraphics::CreateBoxMesh(const Vector3& size)
{
	return pResourcesManager->LoadBoxMesh(size);
}

Ptr<OpenGlRender> OpenGlGraphics::GetRender() const
{
	return pRender;
}

GLFWwindow* OpenGlGraphics::GetWindow() const
{
	return pWindow;
}
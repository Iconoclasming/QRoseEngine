#pragma once

#include "QRoseEngine.Core/ManagedPtr.hpp"
#include "QRoseEngine.Graphics/Render.hpp"
#include "QRoseEngine.Graphics.OpenGL/OpenGlResourcesManager.hpp"
#include "QRoseEngine.Core/IDebugRender.hpp"

struct GLFWwindow;

namespace QRose
{
	class OpenGlRender : public Render, public IDebugRender
	{
	public:
		OpenGlRender(Ptr<OpenGlResourcesManager> pResourcesManager, GLFWwindow* pWindow);
		virtual ~OpenGlRender();

		void ClearView() override;
		void SetViewMatrix(const Matrix4x4 & viewMatrix) override;
		void DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix) override;
		void Present() override;
		Color GetClearColor() override;
		void SetClearColor(const Color& color) override;
		void AddPointLight(const Vector3& position, const Color& intensity) override;

		void DrawLine(Vector2 from, Vector2 to, float thickness, Color colorStart, Color colorEnd) override;
		void DrawLine(Vector3 from, Vector3 to, Vector4 rotation, float thickness, Color colorStart, Color colorEnd) override;

		void InitializeDebugDrawing();

	private:
		struct PointLight;
		struct Line2D;
		struct Line3D;

		Ptr<OpenGlResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;

		Color clearColor;
		Matrix4x4 projectionMatrix;
		Matrix4x4 viewMatrix;

		std::vector<PointLight> _pointLights;

		bool isDebugDrawingInitialized;
		GLuint lineScreenSpaceShaderProgram;
		GLuint lineWorldSpaceShaderProgram;
		std::vector<Line2D> linesScreenSpace;
		std::vector<Line3D> linesWorldSpace;
	};
}

#pragma once

#include <QRoseEngine.Core/Color.hpp>
#include <QRoseEngine.Core/Matrix4x4.hpp>
#include <QRoseEngine.Graphics/MeshHandle.hpp>

namespace QRose
{
	class Render
	{
	public:
		Render() {}
		virtual ~Render() {}

		virtual void ClearView() abstract;
		virtual void SetViewMatrix(const Matrix4x4& viewMatrix) abstract;
		virtual void DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix) abstract;
		virtual void Present() abstract;
		virtual void AddPointLight(const Vector3& position, const Color& intensity) abstract;

		virtual Color GetClearColor() abstract;
		virtual void SetClearColor(const Color& color) abstract;
	};
}
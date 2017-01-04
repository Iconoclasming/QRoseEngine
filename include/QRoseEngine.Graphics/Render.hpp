#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/Vector.hpp>
#include <QRoseEngine.Core/Color.hpp>
#include <QRoseEngine.Core/Matrix4x4.hpp>

namespace QRose
{
	class Render
	{
	public:
		Render() {}
		virtual ~Render() {}

		virtual void ClearView() abstract;
		virtual void BeginDrawing() abstract;
		virtual void DrawMesh(Handle meshId, const Matrix4x4& transformation) abstract;
		virtual void Present() abstract;

		virtual Color GetClearColor() abstract;
		virtual void SetClearColor(const Color& color) abstract;
	};
}
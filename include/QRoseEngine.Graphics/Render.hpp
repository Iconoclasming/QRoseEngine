#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/Vector.hpp>
#include <QRoseEngine.Core/Color.hpp>

namespace QRose
{
	class Render
	{
	public:
		Render() {}
		virtual ~Render() {}

		virtual void ClearView() abstract;
		virtual void BeginDrawing() abstract;
		virtual void DrawMesh(Handle meshId, const Vector3& position) abstract;
		virtual void Present() abstract;

		virtual Color GetClearColor() abstract;
		virtual void SetClearColor(const Color& color) abstract;
	};
}
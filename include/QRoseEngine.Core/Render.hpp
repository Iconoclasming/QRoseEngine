#pragma once

#include "Uuid.hpp"
#include "Vector.hpp"
#include "Color.hpp"

namespace QRose
{
	class Render
	{
	public:
		Render() {}
		virtual ~Render() {}

		virtual void ClearView() abstract;
		virtual void BeginDrawing() abstract;
		virtual void DrawMesh(const Uuid& meshId, const Vector3& position) abstract;
		virtual void Present() abstract;

		virtual Color GetClearColor() abstract;
		virtual void SetClearColor(const Color& color) abstract;
	};
}
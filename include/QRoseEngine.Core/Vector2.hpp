#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
#else
#error GLM required to compile mathematic classes
#endif

namespace QRose
{
	class Vector2
	{
	public:
		Vector2(float x, float y);
		~Vector2();

		float GetX() const;
		float GetY() const;

		const float* Flatten() const; 
	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		explicit Vector2(glm::vec2 vec2);
		glm::vec2 vec2;
#endif
	};
}
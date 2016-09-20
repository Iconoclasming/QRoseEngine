#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
#endif

namespace QRose
{
	class Vector3
	{
	public:
		Vector3(float x, float y, float z);
		~Vector3();

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		glm::vec3 vecInternal;
#endif
	};
}
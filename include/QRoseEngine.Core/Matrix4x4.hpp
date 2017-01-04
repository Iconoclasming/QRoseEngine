#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
#else
#error GLM required to compile mathematic classes
#endif
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace QRose
{
	class Matrix4x4
	{
	public:
		Matrix4x4();
		~Matrix4x4();

		Matrix4x4 Translate(const Vector3& vector);
		Matrix4x4 Rotate(float angle, const Vector3& vector);
		Matrix4x4 Rotate(const Vector4& quaternion);
		Matrix4x4 Scale(const Vector3& vector);

		Matrix4x4 operator*(const Matrix4x4& rhs);

		const float* GetArray() const;

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		Matrix4x4(glm::mat4& mat4);
		glm::mat4 mat4;
#endif
	};
}
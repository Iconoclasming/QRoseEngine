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
		Matrix4x4() = default;
		~Matrix4x4() = default;

		Matrix4x4 Translate(const Vector3& vector) const;
		Matrix4x4 Rotate(float angle, const Vector3& vector) const;
		Matrix4x4 Rotate(const Vector4& quaternion) const;
		Matrix4x4 Scale(const Vector3& vector) const;

		Matrix4x4 operator*(const Matrix4x4& rhs) const;
		float* operator[](int row);

		const float* Flatten() const;

		static Matrix4x4 Projection(float fov, float aspect, float nearPlane, float farPlane);

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		explicit Matrix4x4(glm::mat4&& mat4);
		explicit Matrix4x4(glm::mat4& mat4);
		glm::mat4 mat4;
#endif
	};
}
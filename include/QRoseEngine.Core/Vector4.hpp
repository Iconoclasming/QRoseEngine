#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#endif
#include <istream>
#include "Vector3.hpp"

namespace QRose
{
	class Vector4
	{
	public:
		Vector4(float x, float y, float z, float w);
		~Vector4();

		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetW() const;

		static Vector4 FromAxisAngle(const Vector3& axis, float angle);

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		friend class Matrix4x4;
		Vector4(glm::quat& quat);
		glm::quat quat;
#endif
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static Vector4 Deserialize(std::istream& deserializationStream);
	};

	std::ostream& operator<<(std::ostream& s, const Vector4& vector);
	Vector4 operator >> (std::istream& s, Vector4& vector);
}
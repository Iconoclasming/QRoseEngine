#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
#else
#error GLM required to compile mathematic classes
#endif
#include <istream>

namespace QRose
{
	class Vector3
	{
	public:
		Vector3(float x, float y, float z);
		~Vector3();

		float GetX() const;
		float GetY() const;
		float GetZ() const;

		Vector3& operator+=(const Vector3& rhs);

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		friend class Matrix4x4;
		friend class Vector4;
		Vector3(glm::vec3 vec3);
		glm::vec3 vec3;
#endif
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static Vector3 Deserialize(std::istream& deserializationStream);
	};

	std::ostream& operator<<(std::ostream& s, const Vector3& vector);
	Vector3 operator >> (std::istream& s, Vector3& vector);
}
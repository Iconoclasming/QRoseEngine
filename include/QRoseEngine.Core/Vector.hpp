#pragma once

#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
#include <glm.hpp>
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

	private:
#ifdef QROSEENGINE_USE_OPENGL_MATHEMATICS
		glm::vec3 vecInternal;
#endif
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static Vector3 Deserialize(std::istream& deserializationStream);
	};

	std::ostream& operator<<(std::ostream& s, const Vector3& vector);
	Vector3 operator >> (std::istream& s, Vector3& vector);
}
#include "QRoseEngine.Core/Vector3.hpp"

#include <string>
#include <regex>
#include "gtc/type_ptr.inl"

using namespace QRose;

Vector3::Vector3(float x, float y, float z) : vec3(x, y, z)
{
}

Vector3::Vector3(glm::vec3 vec3) : vec3(vec3)
{
}

Vector3::~Vector3()
{
}

float Vector3::GetX() const
{
	return vec3.x;
}

float Vector3::GetY() const
{
	return vec3.y;
}

float Vector3::GetZ() const
{
	return vec3.z;
}

Vector3 Vector3::operator+=(const Vector3 & rhs)
{
	vec3.x += rhs.GetX();
	vec3.y += rhs.GetY();
	vec3.z += rhs.GetZ();
	return *this;
}

Vector3 Vector3::operator-=(const Vector3 & rhs)
{
	vec3.x -= rhs.GetX();
	vec3.y -= rhs.GetY();
	vec3.z -= rhs.GetZ();
	return *this;
}

Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(scalar * vec3.x, scalar * vec3.y, scalar * vec3.z);
}

Vector3 Vector3::operator-(const Vector3& rhs) const
{
	return Vector3(GetX() - rhs.GetX(), GetY() - rhs.GetY(), GetZ() - rhs.GetZ());
}

Vector3 Vector3::Normalize() const
{
	return glm::normalize(vec3);
}

Vector3 Vector3::Cross(const Vector3 & rhs) const
{
	return glm::cross(vec3, rhs.vec3);
}

const float* Vector3::Flatten() const
{
	return glm::value_ptr(vec3);
}

void Vector3::Serialize(std::ostream& serializationStream) const
{
	serializationStream << *this << std::endl;
}

Vector3 Vector3::Deserialize(std::istream& deserializationStream)
{
	Vector3 vector(0, 0, 0);
	deserializationStream >> vector;
	return vector;
}

std::ostream& QRose::operator<<(std::ostream& s, const Vector3& vector)
{
	return s << "(" << vector.GetX() << ";" << vector.GetY() << ";" << vector.GetZ() << ")";
}

Vector3 QRose::operator>>(std::istream& s, Vector3& vector)
{
	std::string vectorString;
	s >> vectorString;
	std::regex vectorRegex(".([-+]?[0-9]*\\.?[0-9]+);([-+]?[0-9]*\\.?[0-9]*);([-+]?[0-9]*\\.?[0-9]*).");
	std::smatch results;
	if (!std::regex_match(vectorString, results, vectorRegex))
	{
		throw std::invalid_argument("invalid vector string format");
	}
	std::string x = results[1];
	std::string y = results[2];
	std::string z = results[3];
	return Vector3(std::stod(x), std::stod(y), std::stod(z));
}

Vector3 QRose::operator*(float scalar, Vector3 & rhs)
{
	return rhs * scalar;
}

#include "Vector.hpp"

#include <string>
#include <regex>

using namespace QRose;

Vector3::Vector3(float x, float y, float z) : vecInternal(x, y, z)
{
}

Vector3::~Vector3()
{
}

float Vector3::GetX() const
{
	return vecInternal.x;
}

float Vector3::GetY() const
{
	return vecInternal.y;
}

float Vector3::GetZ() const
{
	return vecInternal.z;
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
	return s << "(" << vector.GetX() << "; " << vector.GetY() << "; " << vector.GetZ() << ")";
}

Vector3 QRose::operator>>(std::istream& s, Vector3& vector)
{
	std::string vectorString;
	s >> vectorString;
	std::regex vectorRegex(".([-+]?[0-9]*\\.?[0-9]+); ([-+]?[0-9]*\\.?[0-9]*); ([-+]?[0-9]*\\.?[0-9]*).");
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
#include "QRoseEngine.Core/Vector4.hpp"

#include <string>
#include <regex>

using namespace QRose;

Vector4::Vector4(float x, float y, float z, float w) : vecInternal(x, y, z, w)
{
}

Vector4::~Vector4()
{
}

float Vector4::GetX() const
{
	return vecInternal.x;
}

float Vector4::GetY() const
{
	return vecInternal.y;
}

float Vector4::GetZ() const
{
	return vecInternal.z;
}

float Vector4::GetW() const
{
	return vecInternal.w;
}

void Vector4::Serialize(std::ostream& serializationStream) const
{
	serializationStream << *this << std::endl;
}

Vector4 Vector4::Deserialize(std::istream& deserializationStream)
{
	Vector4 vector(0, 0, 0, 0);
	deserializationStream >> vector;
	return vector;
}

std::ostream& QRose::operator<<(std::ostream& s, const Vector4& vector)
{
	return s << "(" << vector.GetX() << ";" << vector.GetY() << ";" << vector.GetZ() << "; " << vector.GetW() << ")";
}

Vector4 QRose::operator >> (std::istream& s, Vector4& vector)
{
	std::string vectorString;
	s >> vectorString;
	std::regex vectorRegex(".([-+]?[0-9]*\\.?[0-9]+);([-+]?[0-9]*\\.?[0-9]*);([-+]?[0-9]*\\.?[0-9]*);([-+]?[0-9]*\\.?[0-9]*).");
	std::smatch results;
	if (!std::regex_match(vectorString, results, vectorRegex))
	{
		throw std::invalid_argument("invalid vector string format");
	}
	std::string x = results[1];
	std::string y = results[2];
	std::string z = results[3];
	std::string w = results[4];
	return Vector4(std::stod(x), std::stod(y), std::stod(z), std::stod(w));
}
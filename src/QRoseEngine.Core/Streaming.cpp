#include "Streaming.hpp"

using namespace QRose;

bool Streaming::Write(int integer, std::ostream& serializationStream)
{
	return false;
}

bool Streaming::Write(float real, std::ostream& serializationStream)
{
	return false;
}

bool Streaming::Write(double doubleReal, std::ostream& serializationStream)
{
	return false;
}

bool Streaming::Write(bool boolean, std::ostream& serializationStream)
{
	return false;
}

bool Streaming::Write(const std::string& str, std::ostream& serializationStream)
{
	return false;
}

bool Streaming::Read(int& integerOut, std::istream& deserializationStream)
{
	return false;
}

bool Streaming::Read(float& realOut, std::istream& deserializationStream)
{
	return false;
}

bool Streaming::Read(double& doubleRealOut, std::istream& deserializationStream)
{
	return false;
}

bool Streaming::Read(bool& booleanOut, std::istream& deserializationStream)
{
	return false;
}

bool Streaming::Read(std::string& strOut, std::istream& deserializationStream)
{
	return false;
}
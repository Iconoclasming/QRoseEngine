#include "Streaming.hpp"

using namespace QRose;

bool Streaming::Write(int integer, const std::ostream& serializationStream)
{
}

bool Streaming::Write(float real, const std::ostream& serializationStream)
{
}

bool Streaming::Write(double doubleReal, const std::ostream& serializationStream)
{
}

bool Streaming::Write(bool boolean, const std::ostream& serializationStream)
{
}

bool Streaming::Write(const std::string& str, const std::ostream& serializationStream)
{
}

bool Streaming::Read(int& integerOut, const std::istream& deserializationStream)
{
}

bool Streaming::Read(float& realOut, const std::istream& deserializationStream)
{
}

bool Streaming::Read(double& doubleRealOut, const std::istream& deserializationStream)
{
}

bool Streaming::Read(bool& booleanOut, const std::istream& deserializationStream)
{
}

bool Streaming::Read(std::string& strOut, const std::istream& deserializationStream)
{
}
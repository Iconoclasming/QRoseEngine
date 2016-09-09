#pragma once

#include <iostream>

namespace QRose
{
	class Streaming
	{
	public:
		template<typename T>
		static bool Serialize(const T* object, const std::ostream& serializationStream)
		{
			
		}

		template<typename T>
		static T* Deserialize(const std::istream& deserializationStream);

		static bool Write(int integer, const std::ostream& serializationStream);
		static bool Write(float real, const std::ostream& serializationStream);
		static bool Write(double doubleReal, const std::ostream& serializationStream);
		static bool Write(bool boolean, const std::ostream& serializationStream);
		static bool Write(const std::string& str, const std::ostream& serializationStream);

		static bool Read(int& integerOut, const std::istream& deserializationStream);
		static bool Read(float& realOut, const std::istream& deserializationStream);
		static bool Read(double& doubleRealOut, const std::istream& deserializationStream);
		static bool Read(bool& booleanOut, const std::istream& deserializationStream);
		static bool Read(std::string& strOut, const std::istream& deserializationStream);
	};
}
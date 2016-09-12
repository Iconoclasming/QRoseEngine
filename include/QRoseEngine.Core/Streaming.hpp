#pragma once

#include <iostream>
#include "SerializationException.hpp"

namespace QRose
{
	class Streaming
	{
	public:
		template<typename T>
		static bool Serialize(const T* object, const std::ostream& serializationStream)
		{
			try
			{
				object->Serialize(serializationStream);
			}
			catch (const SerializationException& ex)
			{
				// TODO: exception's logging
				return false;
			}
			return true;
		}

		template<typename T>
		static T* Deserialize(const std::istream& deserializationStream)
		{
			try
			{
				return T::Deserialize(deserializationStream);
			}
			catch (const SerializationException& ex)
			{
				// TODO: exception's logging
				return nullptr;
			}
		}

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
	
	/* from: http://www.boost.org/doc/libs/1_61_0/libs/serialization/doc/index.html
	// When the class Archive corresponds to an output archive, the
    	// & operator is defined similar to <<.  Likewise, when the class Archive
	 // is a type of input archive the & operator is defined similar to >>.
    	template<class Archive>
	 void serialize(Archive & ar, const unsigned int version)
    	{
        	ar & degrees;
        	ar & minutes;
        	ar & seconds;
    	}
    	*/
}

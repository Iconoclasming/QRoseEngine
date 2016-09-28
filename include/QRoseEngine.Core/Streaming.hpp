#pragma once

#include <iostream>
#include "SerializationException.hpp"

namespace QRose
{
	class Streaming
	{
	public:
		template<typename T>
		static bool Serialize(const T* object, std::ostream& serializationStream)
		{
			try
			{
				object->Serialize(serializationStream);
			}
			catch (const SerializationException&)
			{
				// TODO: exception's logging
				return false;
			}
			return true;
		}

		template<typename T>
		static T Deserialize(std::istream& deserializationStream)
		{
			return T::Deserialize(deserializationStream);
		}

		static bool Write(int integer, std::ostream& serializationStream);
		static bool Write(float real, std::ostream& serializationStream);
		static bool Write(double doubleReal, std::ostream& serializationStream);
		static bool Write(bool boolean, std::ostream& serializationStream);
		static bool Write(const std::string& str, std::ostream& serializationStream);

		static bool Read(int& integerOut, std::istream& deserializationStream);
		static bool Read(float& realOut, std::istream& deserializationStream);
		static bool Read(double& doubleRealOut, std::istream& deserializationStream);
		static bool Read(bool& booleanOut, std::istream& deserializationStream);
		static bool Read(std::string& strOut, std::istream& deserializationStream);
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

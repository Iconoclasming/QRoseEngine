#pragma once

#include <exception>
#include <string>

namespace QRose
{
	class SerializationException : public std::exception
	{
	public:
		SerializationException(const std::string& message) : std::exception(message.c_str()) {}
		~SerializationException() {}
	};
}
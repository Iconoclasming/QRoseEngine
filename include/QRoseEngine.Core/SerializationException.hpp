#pragma once

#include <exception>
#include <string>

namespace QRose
{
	class SerializationException : public std::exception
	{
	public:
		SerializationException(const std::string& message) : message(message) {}
		~SerializationException() {}

		virtual const char* what() const throw ()
		{
			return message.c_str();
		}

	private:
		std::string message;
	};
}
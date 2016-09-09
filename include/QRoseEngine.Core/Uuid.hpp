#pragma once

#include <string>

namespace QRose
{
	class Uuid
	{
	public:
		Uuid();
		~Uuid() {}

		static Uuid GenerateUuid();
		static Uuid FromString(std::string uuidString);

		static const Uuid Zero;

		bool operator==(const Uuid& rhs) const;
		bool operator<(const Uuid& rhs) const;

		std::string ToString() const;

	protected:
		Uuid(std::string uuid);

	private:
		std::string uuid;
	};
}
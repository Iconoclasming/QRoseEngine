#pragma once

#include <string>
#include <iostream>

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

	std::ostream& operator<<(std::ostream& s, const Uuid& id);
	Uuid operator>>(std::istream& s, Uuid& id);
}
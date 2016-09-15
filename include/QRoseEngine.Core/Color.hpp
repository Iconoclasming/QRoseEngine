#pragma once

#include <iostream>

namespace QRose
{
	class Color
	{
	public:
		Color();
		Color(double r, double g, double b);
		~Color();

		double GetRed() const;
		double GetGreen() const;
		double GetBlue() const;

	private:
		double red;
		double green;
		double blue;

		friend class Streaming;
		void Serialize(const std::ostream& serializationStream) const;
		static Color* Deserialize(const std::istream& deserializationStream);
	};
}
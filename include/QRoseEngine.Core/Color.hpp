#pragma once

#include <iostream>

namespace QRose
{
	class Color
	{
	public:
		Color();
		Color(float r, float g, float b, float a);
		~Color();

		float GetRed() const;
		float GetGreen() const;
		float GetBlue() const;
		float GetAlpha() const;

		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Magneta;
		static const Color Cyan;
		static const Color White;
		static const Color Black;
		static const Color Aqua;

	private:
		float red;
		float green;
		float blue;
		float alpha;

		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static Color Deserialize(std::istream& deserializationStream);
	};
}
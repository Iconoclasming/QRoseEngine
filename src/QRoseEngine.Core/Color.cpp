#include "QRoseEngine.Core/Color.hpp"

using namespace QRose;

Color const Color::Red = Color(1.0f, 0.0f, 0.0f, 1.0f);
Color const Color::Green = Color(0.0f, 1.0f, 0.0f, 1.0f);
Color const Color::Blue = Color(0.0f, 0.0f, 1.0f, 1.0f);
Color const Color::Yellow = Color(1.0f, 1.0f, 0.0f, 1.0f);
Color const Color::Magneta = Color(1.0f, 0.0f, 1.0f, 1.0f);
Color const Color::Cyan = Color(0.0f, 1.0f, 1.0f, 1.0f);
Color const Color::White = Color(1.0f, 1.0f, 1.0f, 1.0f);
Color const Color::Black = Color(0.0f, 0.0f, 0.0f, 1.0f);
Color const Color::Aqua = Color(0.2f, 0.4f, 0.6f, 1.0f);

Color::Color() : Color(0.0, 0.0, 0.0, 0.0)
{
}

Color::Color(float r, float g, float b, float a)
{
	if(r < 0.0)
	{
		r = 0.0;
	}
	else if(r > 1.0)
	{
		r = 1.0;
	}
	if(g < 0.0)
	{
		g = 0.0;
	}
	else if(g > 1.0)
	{
		g = 1.0;
	}
	if(b < 0.0)
	{
		b = 0.0;
	}
	else if(b > 1.0)
	{
		b = 1.0;
	}
	if (a < 0.0)
	{
		a = 0.0;
	}
	else if (a > 1.0)
	{
		a = 1.0;
	}
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

Color::~Color()
{
}

float Color::GetRed() const
{
	return red;
}

float Color::GetGreen() const
{
	return green;
}

float Color::GetBlue() const
{
	return blue;
}

float Color::GetAlpha() const
{
	return alpha;
}

void Color::Serialize(std::ostream& serializationStream) const
{
}

Color Color::Deserialize(std::istream& deserializationStream)
{
	return Color(0, 0, 0, 0);
}
#pragma once

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
	};
}
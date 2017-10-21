#pragma once

namespace QRose
{
	class Angle
	{
	public:
		static const float Pi;
		static float Rad(float degrees) { return degrees * Pi / 180.0f; }
		static float Deg(float radians) { return radians * 180.0f / Pi; }
	};
}
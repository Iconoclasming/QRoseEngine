#include <QRoseEngine.Core/Vector2.hpp>

#include <gtc/type_ptr.hpp>

QRose::Vector2::Vector2(float x, float y) : Vector2(glm::vec2(x, y))
{
}

QRose::Vector2::Vector2(glm::vec2 vec2) : vec2(vec2)
{
}

QRose::Vector2::~Vector2()
{
}

float QRose::Vector2::GetX() const
{
	return vec2.x;
}

float QRose::Vector2::GetY() const
{
	return vec2.y;
}

const float* QRose::Vector2::Flatten() const
{
	return glm::value_ptr(vec2);
}

#pragma once

namespace QRose
{
	template <typename T>
	class Size
	{
	public:
		Size();
		Size(const T& width, const T& height);
		~Size();

		T GetWidth() const;
		T GetHeight() const;

	private:
		T width;
		T height;
	};
}
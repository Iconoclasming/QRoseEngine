#include "Size.h"

using namespace QRose;

template <typename T>
Size<T>::Size() : Size(0, 0)
{
}

template <typename T>
Size<T>::Size(const T& width, const T& height) : width(width >= 0 ? width : 0), height(height >= 0 ? height : 0)
{
}

template <typename T>
Size<T>::~Size()
{
}

template <typename T>
T Size<T>::GetWidth() const
{
	return width;
}

template <typename T>
T Size<T>::GetHeight() const
{
	return height;
}

template class Size<int>;
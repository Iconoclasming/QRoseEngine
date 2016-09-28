#pragma once
#include <memory>

namespace QRose
{
	template<typename T>
	using MPtr = std::shared_ptr<T>;

	template<typename T, typename ... CtorArgs>
	MPtr<T> Managed(CtorArgs ... ctorArgs)
	{
		return std::make_shared<T>(ctorArgs...);
	}
}
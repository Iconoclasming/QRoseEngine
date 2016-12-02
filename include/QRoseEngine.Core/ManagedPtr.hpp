#pragma once
#include <memory>

namespace QRose
{
	template<typename T>
	using Ptr = std::shared_ptr<T>;

	template<typename T, typename ... CtorArgs>
	Ptr<T> Managed(CtorArgs ... ctorArgs)
	{
		return std::make_shared<T>(ctorArgs...);
	}
}
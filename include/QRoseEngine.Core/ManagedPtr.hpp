#pragma once
#include <memory>

namespace QRose
{
	template<typename T>
	using ManagedPtr = std::shared_ptr<T>;

	template<typename T, typename ... CtorArgs>
	ManagedPtr<T> Managed(CtorArgs ... ctorArgs)
	{
		return std::make_shared<T>(ctorArgs...);
	}
}
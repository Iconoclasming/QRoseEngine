#pragma once

#include <functional>

/*
An attempt to make C#-like method delegates/functions in C++.
Source: http://blog.molecular-matters.com/2011/09/19/generic-type-safe-delegates-and-events-in-c/
*/

namespace QRose
{
	template<typename TReturn, typename ... Types>
	class Delegate
	{
	public:
		Delegate(std::function<TReturn(Types ...)> func) : func(func) {}
		virtual ~Delegate() {}

		// Binds a class method
		template<class C, TReturn(C::*TFunction)(Types ...)>
		static Delegate<TReturn, Types ...> inline Bind(C* instance)
		{
			return Delegate([instance](Types ... args)
			{
				return (static_cast<C*>(instance)->*TFunction)(std::forward<Types>(args)...);
			});
		}

		template<class C, TReturn(C::*TFunction)(Types ...)>
		static std::function<TReturn(Types ...)> inline ClassMethodAsFunction(C* instance)
		{
			return std::function<TReturn(Types ...)>([instance](Types ... args)
			{
				return (static_cast<C*>(instance)->*TFunction)(std::forward<Types>(args)...);
			});
		}

		TReturn inline Invoke(Types ... args)
		{
			return func(std::forward<Types>(args)...);
		}

		TReturn inline operator()(Types ... args)
		{
			return Invoke(std::forward<Types>(args)...);
		}

		std::function<TReturn(Types ...)> AsFunction() const
		{
			return func;
		}

	private:
		std::function<TReturn(Types ...)> func;
	};
}
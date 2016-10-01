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

	// Delegate implementation with variadic template parameters
	// Signature: void Sample(TArg1 arg1, TArg2 arg2, ...)
	template<typename ... Types>
	class ReturnsNothingDelegate : public Delegate<void, Types ...>
	{
	public:
		ReturnsNothingDelegate(std::function<void(Types ...)> func) : Delegate<void, Types ...>(func) {}
		virtual ~ReturnsNothingDelegate() {}

		// Binds a class method
		template<class C, void(C::*TFunction)(Types ...)>
		static ReturnsNothingDelegate inline Bind(C* instance)
		{
			return ReturnsNothingDelegate(std::function<void(Types ...)>([instance](Types ... args)
			{
				(static_cast<C*>(instance)->*TFunction)(std::forward<Types>(args)...);
			}));
		}
	};

	// Non-variadic Delegate implementation.
	// Signature: void Command()
	class CommandDelegate : public Delegate<void>
	{
	public:
		CommandDelegate(std::function<void(void)> func) : Delegate(func) {}
		virtual ~CommandDelegate() {}

		// Binds a class method
		template<class C, void(C::*TFunction)(void)>
		static CommandDelegate inline Bind(C* instance)
		{
			return CommandDelegate(std::function<void(void)>([instance]()
			{
				(static_cast<C*>(instance)->*TFunction)();
			}));
		}
	};
}
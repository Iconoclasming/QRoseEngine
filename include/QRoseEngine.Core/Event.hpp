#pragma once

#include <list>
#include "Delegate.hpp"
#include "EventInvoker.hpp"
#include "QCE.hpp"

using std::list;

namespace QRose
{
	template<typename TEventArgs>
	class Event
	{
	public:
		Event(EventInvoker<TEventArgs>* pInvoker);
		virtual ~Event();

		void Subscribe(ReturnsNothingDelegate<const TEventArgs&>* pDelegate);
		void Unsubscribe(ReturnsNothingDelegate<const TEventArgs&>* pDelegate);

		void Subscribe(Delegate<void, const TEventArgs&>* pDelegate);
		void Unsubscribe(Delegate<void, const TEventArgs&>* pDelegate);

		inline bool IsSubscribed(ReturnsNothingDelegate<const TEventArgs&>* pDelegate);
		inline bool IsSubscribed(Delegate<void, const TEventArgs&>* pDelegate);

		bool IsAnyoneSubscribed() { return subscribedDelegates.size() > 0; }

		Event& operator+=(ReturnsNothingDelegate<const TEventArgs&>* pDelegate) { Subscribe(pDelegate); return *this; }
		Event& operator+=(Delegate<void, const TEventArgs&>* pDelegate) { Subscribe(pDelegate); return *this; }
		Event& operator+=(Delegate<void, const TEventArgs&>& rDelegate) { Subscribe(&rDelegate); return *this; }
		Event& operator-=(ReturnsNothingDelegate<const TEventArgs&>* pDelegate) { Unsubscribe(pDelegate); return *this; }
		Event& operator-=(Delegate<void, const TEventArgs&>* pDelegate) { Unsubscribe(pDelegate); return *this; }
		Event& operator-=(Delegate<void, const TEventArgs&>& rDelegate) { Unsubscribe(&rDelegate); return *this; }

	private:
		list<Delegate<void, const TEventArgs&>*> subscribedDelegates;
		Delegate<void, const TEventArgs&> invokeDelegate;
		EventInvoker<TEventArgs>* pInvoker;

		void Invoke(const TEventArgs& eventArgs);
	};

#define INVOKE_EVENT(event, invoker, sender, eventArgs) { if(event.IsAnyoneSubscribed()) { invoker.Invoke(sender, eventArgs); } }

	template<typename TEventArgs>
	Event<TEventArgs>::Event(EventInvoker<TEventArgs>* pInvoker)
		: invokeDelegate(Delegate<void, const TEventArgs&>::Bind<Event, &Event::Invoke>(this))
	{
		if (pInvoker == nullptr)
		{
			throw std::invalid_argument("pInvoker == nullptr");
		}
		this->pInvoker = pInvoker;
		this->pInvoker->Subscribe(&invokeDelegate);
	}

	template<typename TEventArgs>
	Event<TEventArgs>::~Event()
	{
		subscribedDelegates.clear();
	}

	template<typename TEventArgs>
	void Event<TEventArgs>::Subscribe(ReturnsNothingDelegate<const TEventArgs&>* pDelegate)
	{
		Subscribe(dynamic_cast<Delegate<void, const TEventArgs&>*>(pDelegate));
	}

	template<typename TEventArgs>
	void Event<TEventArgs>::Unsubscribe(ReturnsNothingDelegate<const TEventArgs&>* pDelegate)
	{
		Unsubscribe(dynamic_cast<Delegate<void, const TEventArgs&>*>(pDelegate));
	}

	template<typename TEventArgs>
	inline void Event<TEventArgs>::Subscribe(Delegate<void, const TEventArgs&>* pDelegate)
	{
		if (pDelegate != nullptr && !IsSubscribed(pDelegate))
		{
			subscribedDelegates.push_back(pDelegate);
		}
	}

	template<typename TEventArgs>
	inline void Event<TEventArgs>::Unsubscribe(Delegate<void, const TEventArgs&>* pDelegate)
	{
		if (IsSubscribed(pDelegate))
		{
			subscribedDelegates.remove(pDelegate);
		}
	}

	template<typename TEventArgs>
	bool Event<TEventArgs>::IsSubscribed(ReturnsNothingDelegate<const TEventArgs&>* pDelegate)
	{
		return IsSubscribed(dynamic_cast<Delegate<void, const TEventArgs&>*>(pDelegate));
	}

	template<typename TEventArgs>
	inline bool Event<TEventArgs>::IsSubscribed(Delegate<void, const TEventArgs&>* pDelegate)
	{
		return QCE::Contains(subscribedDelegates, pDelegate);
	}

	template<typename TEventArgs>
	void Event<TEventArgs>::Invoke(const TEventArgs& eventArgs)
	{
		for (auto delegate : subscribedDelegates)
		{
			delegate->Invoke(eventArgs);
		}
	}
}
#pragma once

namespace QRose
{
	template<typename TEventArgs> class Event;

	template<typename TEventArgs>
	class EventInvoker
	{
	public:
		EventInvoker() {}
		~EventInvoker()
		{
			Unsubscribe();
		}

		void Invoke(const TEventArgs& eventArgs)
		{
			if (pInvokeDelegate != nullptr)
			{
				pInvokeDelegate->Invoke(eventArgs);
			}
		}

	private:
		Delegate<void, const TEventArgs&>* pInvokeDelegate;

		void Subscribe(Delegate<void, const TEventArgs&>* pDelegate)
		{
			pInvokeDelegate = pDelegate;
		}
		void Unsubscribe()
		{
			pInvokeDelegate = nullptr;
		}

		friend class Event<TEventArgs>;
	};
}
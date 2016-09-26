#pragma once

#include "ManagedPtr.h"

namespace QRose
{
	template<typename T>
	class Managed
	{
	public:
		Managed();
		virtual ~Managed();

	private:
		int referencesCount;

		void IncrementReferencesCount();
		void DecrementReferencesCount();
		int GetReferencesCount() const;

		friend class ManagedPtr<T>;
	};

	template <typename T>
	Managed<T>::Managed() : referencesCount(0)
	{
	}

	template <typename T>
	Managed<T>::~Managed()
	{
	}

	template <typename T>
	void Managed<T>::IncrementReferencesCount()
	{
		referencesCount++;
	}

	template <typename T>
	void Managed<T>::DecrementReferencesCount()
	{
		if(referencesCount > 0)
		{
			referencesCount--;
		}
	}

	template <typename T>
	int Managed<T>::GetReferencesCount() const
	{
		return referencesCount;
	}
}
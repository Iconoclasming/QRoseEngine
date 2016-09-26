#pragma once

namespace QRose
{
	template<typename T>
	class ManagedPtr
	{
	public:
		ManagedPtr() : ManagedPtr(nullptr) {}
		ManagedPtr(T* pObject);
		ManagedPtr(const ManagedPtr& rhs);
		~ManagedPtr();

		operator T*() const;
		T& operator*() const;
		T* operator->() const;

		ManagedPtr& operator=(T* rhs);
		ManagedPtr& operator=(const ManagedPtr& rhs);

		bool operator==(T* rhs) const;
		bool operator!=(T* rhs) const;
		bool operator==(const ManagedPtr& rhs) const;
		bool operator!= (const ManagedPtr& rhs) const;

	private:
		T* pObject;
	};


	template<typename T>
	inline ManagedPtr<T>::ManagedPtr(T* pObject)
	{
		this->pObject = pObject;
		if (pObject != nullptr)
		{
			pObject->IncrementReferencesCount();
		}
	}

	template<typename T>
	inline ManagedPtr<T>::ManagedPtr(const ManagedPtr& rhs)
	{
		pObject = rhs.pObject;
		if (pObject != nullptr)
		{
			pObject->IncrementReferencesCount();
		}
	}

	template<typename T>
	inline ManagedPtr<T>::~ManagedPtr()
	{
		if (pObject)
		{
			pObject->DecrementReferencesCount();
			if (pObject->GetReferencesCount() == 0)
			{
				delete pObject;
			}
		}
	}

	template<typename T>
	inline ManagedPtr<T>::operator T*() const
	{
		return pObject;
	}

	template<typename T>
	inline T& ManagedPtr<T>::operator*() const
	{
		return &pObject;
	}

	template<typename T>
	inline T* ManagedPtr<T>::operator->() const
	{
		return pObject;
	}

	template<typename T>
	inline ManagedPtr<T>& ManagedPtr<T>::operator=(T* rhs)
	{
		if (pObject != rhs)
		{
			if (rhs != nullptr)
			{
				rhs->IncrementReferencesCount();
			}
			if (pObject != nullptr)
			{
				pObject->DecrementReferencesCount();
			}
			pObject = rhs;
		}
		return *this;
	}

	template<typename T>
	inline ManagedPtr<T>& ManagedPtr<T>::operator=(const ManagedPtr& rhs)
	{
		operator=(rhs.pObject);
		return *this;
	}

	template<typename T>
	inline bool ManagedPtr<T>::operator==(T* rhs) const
	{
		return pObject == rhs;
	}

	template<typename T>
	inline bool ManagedPtr<T>::operator!=(T* rhs) const
	{
		return pObject != rhs;
	}

	template<typename T>
	inline bool ManagedPtr<T>::operator==(const ManagedPtr& rhs) const
	{
		return pObject == rhs.pObject;
	}

	template<typename T>
	inline bool ManagedPtr<T>::operator!=(const ManagedPtr& rhs) const
	{
		return pObject != rhs.pObject;
	}
}
#pragma once

#include <mapped_soa.h>
#include "EntityHandle.hpp"

namespace QRose
{
	class StorageBase
	{
	public:
		virtual ~StorageBase() {}

		virtual void Clear() abstract;
		virtual bool Has(EntityHandle id) abstract;
	};

	template<typename TComponent>
	class Storage : public StorageBase
	{
	public:
		virtual ~Storage();

		void Clear() override;
		bool Has(EntityHandle id) override;

		static const unsigned int Type = TComponent::Type;

		bool Add(TComponent& component);
		TComponent& Get(EntityHandle id);
		TComponent* GetAll();
		TComponent& At(int index);
		bool Remove(int id);
		int Size() const;

	private:
		MappedSoA<EntityHandle, TComponent> storage;
	};

	template <typename TComponent>
	Storage<TComponent>::~Storage()
	{
	}

	template <typename TComponent>
	void Storage<TComponent>::Clear()
	{
		// TODO
	}

	template <typename TComponent>
	bool Storage<TComponent>::Has(EntityHandle id)
	{
		return storage.has(id);
	}

	template <typename TComponent>
	bool Storage<TComponent>::Add(TComponent& component)
	{
		if(Has(component.id))
		{
			return false;	
		}
		storage.add(component.id, component);
		return true;
	}

	template <typename TComponent>
	TComponent& Storage<TComponent>::Get(EntityHandle id)
	{
		return storage.get<0>(id);
	}

	template <typename TComponent>
	TComponent* Storage<TComponent>::GetAll()
	{
		return storage.template array<0>();
	}

	template <typename TComponent>
	TComponent& Storage<TComponent>::At(int index)
	{
		return storage.at<0>(index);
	}

	template <typename TComponent>
	bool Storage<TComponent>::Remove(int id)
	{
		storage.remove(id);
		return true;
	}

	template <typename TComponent>
	int Storage<TComponent>::Size() const
	{
		return storage.size();
	}
}

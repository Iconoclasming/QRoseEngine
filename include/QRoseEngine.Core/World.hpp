#pragma once

#include <map>
#include <QRoseEngine.Core/Storage.hpp>

namespace QRose
{
	class World
	{
	public:
		World();
		~World();
		
		template<typename TStorage>
		void Add(TStorage* pStorage);

		template<typename TStorage>
		TStorage* Get();
		
	private:
		std::map<unsigned int, StorageBase*> storages;
	};

	template <typename TStorage>
	void World::Add(TStorage* pStorage)
	{
		storages[TStorage::Type] = pStorage;
	}

	template <typename TStorage>
	TStorage* World::Get()
	{
		return static_cast<TStorage*>(storages[TStorage::Type]);
	}
}

#include <QRoseEngine.Core/World.hpp>

using namespace QRose;

World::World()
{
}

World::~World() 
{
	for (auto& componentStoragePair : storages)
	{
		delete componentStoragePair.second;
		componentStoragePair.second = nullptr;
	}
}
#include <QRoseEngine.Platform/Scene.hpp>

using namespace QRose;

Scene::Scene(Ptr<Engine> engine) : engine(engine)
{
	if (engine == nullptr)
	{
		throw std::invalid_argument("engine == nullptr");
	}
}

Scene::~Scene()
{
}
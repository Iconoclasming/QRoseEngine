#include <QRoseEngine.Graphics/Scene.hpp>

using namespace QRose;

Scene::Scene(const std::list<Uuid>& entities) : entities(entities)
{
}

Scene::~Scene()
{
}
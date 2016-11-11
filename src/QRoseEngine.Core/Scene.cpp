#include "QRoseEngine.Core/Scene.hpp"

using namespace QRose;

Scene::Scene(const std::list<Entity>& entities) : entities(entities)
{
}

Scene::~Scene()
{
}
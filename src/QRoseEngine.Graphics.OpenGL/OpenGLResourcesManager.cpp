#include "OpenGLResourcesManager.hpp"

using namespace QRose;

Uuid OpenGLResourcesManager::LoadMesh(const std::string& path)
{
	return Uuid::GenerateUuid();
}

Uuid OpenGLResourcesManager::LoadBoxMesh(const Vector3& size)
{
	return Uuid::GenerateUuid();
}
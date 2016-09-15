#include "MeshComponent.hpp"

using namespace QRose;

MeshComponent::MeshComponent(const Uuid& meshId) : meshId(meshId)
{
}

MeshComponent::~MeshComponent()
{
}

Uuid MeshComponent::GetMeshId() const
{
	return meshId;
}
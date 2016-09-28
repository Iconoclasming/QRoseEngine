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

Uuid MeshComponent::GetID() const
{
	return id;
}

void MeshComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << id << std::endl;
	serializationStream << meshId << std::endl;
}

MeshComponent MeshComponent::Deserialize(std::istream& deserializationStream)
{
	Uuid id;
	Uuid meshId;
	deserializationStream >> id;
	deserializationStream >> meshId;
	MeshComponent meshComponent(meshId);
	meshComponent.id = id;
	return meshComponent;
}
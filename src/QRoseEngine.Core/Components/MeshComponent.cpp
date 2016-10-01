#include "Components/MeshComponent.hpp"

#include <typeinfo>

using namespace QRose;

const Uuid MeshComponent::ComponentTypeId = Uuid::FromString("2F6C50ED-C7A8-4990-AB1E-5F1D4EF5C128");
const std::string MeshComponent::ComponentName = typeid(MeshComponent).name();

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
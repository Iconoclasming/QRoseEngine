#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

const Uuid MeshComponent::Type = Uuid::FromString("2F6C50ED-C7A8-4990-AB1E-5F1D4EF5C128");

void MeshComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << meshId << std::endl;
}

MeshComponent MeshComponent::Deserialize(std::istream& deserializationStream)
{
	Uuid meshId;
	deserializationStream >> meshId;
	MeshComponent meshComponent;
	meshComponent.meshId = meshId;
	return meshComponent;
}
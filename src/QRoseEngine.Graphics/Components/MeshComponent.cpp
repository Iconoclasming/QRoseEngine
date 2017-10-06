#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

#include <QRoseEngine.Core/Uuid.hpp>

using namespace QRose;

void MeshComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << id << std::endl;
	serializationStream << meshId << std::endl;
}

MeshComponent MeshComponent::Deserialize(std::istream& deserializationStream)
{
	EntityHandle id;
	MeshHandle meshId;
	deserializationStream >> id;
	deserializationStream >> meshId;
	MeshComponent meshComponent(id, meshId);
	return meshComponent;
}
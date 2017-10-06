#include <QRoseEngine.Core/Components/TransformComponent.hpp>

using namespace QRose;

void TransformComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << id << std::endl;
	serializationStream << position << std::endl;
	serializationStream << rotation << std::endl;
	serializationStream << scale << std::endl;
}

TransformComponent TransformComponent::Deserialize(std::istream& deserializationStream)
{
	EntityHandle id;
	Vector3 position(0, 0, 0);
	Vector4 rotation(0, 0, 0, 0);
	Vector3 scale(0, 0, 0);
	deserializationStream >> id;
	deserializationStream >> position;
	deserializationStream >> rotation;
	deserializationStream >> scale;
	TransformComponent transformationComponent(id);
	transformationComponent.position = position;
	transformationComponent.rotation = rotation;
	transformationComponent.scale = scale;
	return transformationComponent;
}
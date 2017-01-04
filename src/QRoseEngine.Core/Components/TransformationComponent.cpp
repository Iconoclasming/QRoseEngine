#include "QRoseEngine.Core/Components/TransformationComponent.hpp"

using namespace QRose;

const Uuid TransformationComponent::Type = Uuid::FromString("843CE3F3-AE74-4A85-8801-515A37F4B3E8");

void TransformationComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << position << std::endl;
	serializationStream << rotation << std::endl;
	serializationStream << scale << std::endl;
}

TransformationComponent TransformationComponent::Deserialize(std::istream& deserializationStream)
{
	Vector3 position(0, 0, 0);
	Vector4 rotation(0, 0, 0, 0);
	Vector3 scale(0, 0, 0);
	deserializationStream >> position;
	deserializationStream >> rotation;
	deserializationStream >> scale;
	TransformationComponent transformationComponent;
	transformationComponent.position = position;
	transformationComponent.rotation = rotation;
	transformationComponent.scale = scale;
	return transformationComponent;
}
#include "TransformationComponent.hpp"

using namespace QRose;

TransformationComponent::TransformationComponent() : position(0.0, 0.0, 0.0), id(Uuid::GenerateUuid())
{
}

TransformationComponent::TransformationComponent(Vector3 position) : position(position)
{
}

TransformationComponent::~TransformationComponent()
{
}

Uuid TransformationComponent::GetID() const
{
	return id;
}

void TransformationComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << id << std::endl;
	serializationStream << position << std::endl;
}

TransformationComponent TransformationComponent::Deserialize(std::istream& deserializationStream)
{
	return TransformationComponent();
}
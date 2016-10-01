#include "Components/TransformationComponent.hpp"

#include <typeinfo>

using namespace QRose;

const Uuid TransformationComponent::ComponentTypeId = Uuid::FromString("843CE3F3-AE74-4A85-8801-515A37F4B3E8");
const std::string TransformationComponent::ComponentName = typeid(TransformationComponent).name();

TransformationComponent::TransformationComponent() : id(Uuid::GenerateUuid()), position(0.0, 0.0, 0.0)
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

Vector3 TransformationComponent::GetPosition() const
{
	return position;
}

void TransformationComponent::Serialize(std::ostream& serializationStream) const
{
	serializationStream << id << std::endl;
	serializationStream << position << std::endl;
}

TransformationComponent TransformationComponent::Deserialize(std::istream& deserializationStream)
{
	Uuid id;
	Vector3 position(0, 0, 0);
	deserializationStream >> id;
	deserializationStream >> position;
	TransformationComponent transformationComponent(position);
	transformationComponent.id = id;
	return transformationComponent;
}
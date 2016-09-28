#include "Components/TransformationComponent.hpp"

using namespace QRose;

const Uuid TransformationComponent::ComponentTypeId = Uuid::FromString("843CE3F3-AE74-4A85-8801-515A37F4B3E8");
const std::string TransformationComponent::ComponentName = typeid(TransformationComponent).name();

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
#include "TransformationComponent.hpp"

using namespace QRose;

TransformationComponent::TransformationComponent() : position(0.0, 0.0, 0.0)
{
}

TransformationComponent::TransformationComponent(Vector3 position) : position(position)
{
}

TransformationComponent::~TransformationComponent()
{
}
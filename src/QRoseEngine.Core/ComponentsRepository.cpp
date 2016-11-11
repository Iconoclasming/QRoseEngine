#include "QRoseEngine.Core/ComponentsRepository.hpp"

using namespace QRose;

bool ComponentsRepository::Contains(const Uuid& componentId)
{
	return components.count(componentId) > 0;
}
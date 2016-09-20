#pragma once

#include <string>
#include "Vector.hpp"
#include "Uuid.hpp"

namespace QRose
{
	class TransformationComponent
	{
	public:
		TransformationComponent();
		TransformationComponent(Vector3 position);
		~TransformationComponent();

		static const Uuid ComponentTypeId;
		static const std::string ComponentName;

	private:
		Vector3 position;
	};
}
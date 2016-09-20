#pragma once

#include "Uuid.hpp"

namespace QRose
{
	class MeshComponent
	{
	public:
		MeshComponent(const Uuid& meshId);
		~MeshComponent();

		Uuid GetMeshId() const;

		static const Uuid ComponentTypeId;
		static const std::string ComponentName;

	private:
		Uuid meshId;
	};
}
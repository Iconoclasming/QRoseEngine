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

	private:
		Uuid meshId;
	};
}
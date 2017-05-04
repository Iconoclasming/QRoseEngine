#pragma once

#include "QRoseEngine.Core/EntityHandle.hpp"

namespace QRose
{
	class MeshComponent
	{
	public:
		MeshComponent() : MeshComponent(EntityHandle()) {}
		MeshComponent(const EntityHandle& meshId) : meshId(meshId) {}

		EntityHandle meshId;

		static const EntityHandle Type;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static MeshComponent Deserialize(std::istream& deserializationStream);
	};
}
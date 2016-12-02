#pragma once

#include "QRoseEngine.Core/Uuid.hpp"

namespace QRose
{
	class MeshComponent
	{
	public:
		MeshComponent() : MeshComponent(Uuid::Zero) {}
		MeshComponent(const Uuid& meshId) : meshId(meshId) {}

		Uuid meshId;

		static const Uuid Type;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static MeshComponent Deserialize(std::istream& deserializationStream);
	};
}
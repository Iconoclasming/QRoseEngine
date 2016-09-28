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

		Uuid GetID() const;
		static const Uuid ComponentTypeId;
		static const std::string ComponentName;

	private:
		Uuid id;
		Uuid meshId;

		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static MeshComponent Deserialize(std::istream& deserializationStream);
	};
}
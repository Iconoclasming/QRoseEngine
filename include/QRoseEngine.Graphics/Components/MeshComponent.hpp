#pragma once

#include <iostream>
#include <QRoseEngine.Core/EntityHandle.hpp>
#include <QRoseEngine.Graphics/MeshHandle.hpp>

namespace QRose
{
	class MeshComponent
	{
	public:
		MeshComponent(EntityHandle id) : MeshComponent(id, MeshHandle()) {}
		MeshComponent(EntityHandle id, const MeshHandle& meshId) : id(id), meshId(meshId) {}

		const EntityHandle id;
		MeshHandle meshId;

		static const unsigned int Type = 4;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static MeshComponent Deserialize(std::istream& deserializationStream);
	};
}

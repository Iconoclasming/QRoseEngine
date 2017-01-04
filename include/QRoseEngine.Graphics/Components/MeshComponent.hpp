#pragma once

#include "QRoseEngine.Core/Handle.hpp"

namespace QRose
{
	class MeshComponent
	{
	public:
		MeshComponent() : MeshComponent(Handle()) {}
		MeshComponent(const Handle& meshId) : meshId(meshId) {}

		Handle meshId;

		static const Handle Type;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static MeshComponent Deserialize(std::istream& deserializationStream);
	};
}
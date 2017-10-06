#pragma once

#include <QRoseEngine.Core/EntityHandle.hpp>
#include <QRoseEngine.Core/Vector.hpp>

namespace QRose
{
	struct TransformComponent
	{
		explicit TransformComponent(EntityHandle id) : id(id), position(Vector3(0, 0, 0)),
		                                               rotation(Vector4(0, 0, 0, 1)), scale(Vector3(1, 1, 1)),
		                                               padding(0)
		{
		}

		static const unsigned int Type = 1;

		const EntityHandle id;
		Vector3 position;
		Vector4 rotation;
		Vector3 scale;		
		int padding;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static TransformComponent Deserialize(std::istream& deserializationStream);
	};
}

#pragma once

#include <string>
#include "QRoseEngine.Core/Vector.hpp"
#include "QRoseEngine.Core/Uuid.hpp"

namespace QRose
{
	struct TransformationComponent
	{
		TransformationComponent() : position(Vector3(0, 0, 0)), rotation(Vector4(0, 0, 0, 0)), scale(Vector3(0, 0, 0))
		{
		}

		Vector3 position;
		Vector4 rotation;
		Vector3 scale;

		static const Uuid Type;

	private:
		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static TransformationComponent Deserialize(std::istream& deserializationStream);
	};
}
#pragma once

#include <string>
#include "QRoseEngine.Core/Vector.hpp"
#include "QRoseEngine.Core/Uuid.hpp"

namespace QRose
{
	class TransformationComponent
	{
	public:
		TransformationComponent();
		TransformationComponent(Vector3 position);
		~TransformationComponent();

		Uuid GetID() const;
		Vector3 GetPosition() const;

		static const Uuid ComponentTypeId;
		static const std::string ComponentName;

	private:
		Uuid id;
		Vector3 position;

		friend class Streaming;
		void Serialize(std::ostream& serializationStream) const;
		static TransformationComponent Deserialize(std::istream& deserializationStream);
	};
}
#pragma once

#include <string>
#include "Vector.hpp"
#include "Uuid.hpp"

namespace QRose
{
	class TransformationComponent
	{
	public:
		TransformationComponent();
		TransformationComponent(Vector3 position);
		~TransformationComponent();

		Uuid GetID() const;
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
#pragma once

namespace QRose
{
	class ComponentsRepository
	{
	public:
		
		template<typename TComponent>
		void Add(const TComponent& component);
	};
}
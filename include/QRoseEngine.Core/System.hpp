#pragma once

namespace QRose
{
	class System
	{
	public:
		System() {}
		virtual ~System() {}

		virtual void Update(double dt) abstract;
	};
}
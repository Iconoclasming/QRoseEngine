#pragma once

#include "Managed.hpp"

namespace QRose
{
	class Render : public Managed<Render>
	{
	public:
		Render() {}
		virtual ~Render() {}
	};
}
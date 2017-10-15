#pragma once

#include <memory>
#include "NullDebugRender.hpp"

namespace QRose
{
	class DebugRender
	{
	public:
		static std::shared_ptr<IDebugRender> Get() { return pDebugRender; }
		static void SetDebugRender(std::shared_ptr<IDebugRender> pDebugRender)
		{
			if(pDebugRender == nullptr)
			{
				pDebugRender = std::make_shared<NullDebugRender>();
			}
			DebugRender::pDebugRender = pDebugRender;
		}

	protected:
		~DebugRender() = default;

	private:
		static std::shared_ptr<IDebugRender> pDebugRender;
	};
}

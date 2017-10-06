#pragma once

namespace QRose
{
	class Clock
	{
	public:
		unsigned int GetTicks() const;
		unsigned long TicksToMilliseconds(unsigned int ticks) const;
	};

	class WallClock
	{
	public:
		static const Clock& Get();
		static Clock Create();
	};
}
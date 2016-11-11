#pragma once

#include <random>
#include <ctime>

namespace QRose
{
	template<typename T>
	class RNDGen
	{
	public:
		RNDGen() : RNDGen(0, std::numeric_limits<T>::max()) {}

		RNDGen(T min, T max)
		{
			gen.seed(std::time(nullptr));
			distribution = std::uniform_real_distribution<T>(min, max);
		}

		~RNDGen() {}

		inline T Next() { return distribution(gen); }

	private:
		std::mt19937 gen;
		std::uniform_real_distribution<T> distribution;
	};

	template class RNDGen<float>;
	template class RNDGen<double>;

	template<>
	class RNDGen<int>
	{
	public:
		RNDGen() : RNDGen<int>(0, std::numeric_limits<int>::max()) {}

		RNDGen(int min, int max)
		{
			gen.seed(std::time(nullptr));
			distribution = std::uniform_int_distribution<int>(min, max);
		}

		~RNDGen() {}

		inline int Next() { return distribution(gen); }

	private:
		std::mt19937 gen;
		std::uniform_int_distribution<int> distribution;
	};
}
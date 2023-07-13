#ifndef UTIL_RANDOM_HPP
#define UTIL_RANDOM_HPP

#include <random>
#include <chrono>

namespace util {
	std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
}

template <typename Type>
Type random(Type min, Type max) {
	return util::rng() % (max - min + 1) + min;
}

template <typename Type>
Type random(Type max) {
	return util::rng() % max;
}

#endif
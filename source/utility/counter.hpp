#ifndef UTIL_COUNTER_HPP
#define UTIL_COUNTER_HPP

#include <cstdint>

template<typename Type>
struct Counter {
	uintmax_t count = 0;

	bool operator()(const Type &a, const Type &b) {
		++count;
		return a < b;
	}
};

#endif
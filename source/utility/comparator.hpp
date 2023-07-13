#ifndef UTIL_COMPARATOR_HPP
#define UTIL_COMPARATOR_HPP

#include <cstdint>

template<typename T>
struct Comparator {
	uintmax_t count = 0;

	bool operator ()(const T &a, const T &b) {
		++count;
		return a < b;
	}
};

#endif
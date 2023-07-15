#ifndef UTIL_COMPARATOR_HPP
#define UTIL_COMPARATOR_HPP

#include <cstdint>

template<typename Type>
struct Comparator {
	uintmax_t count = 0;

	bool operator ()(const Type &a, const Type &b) {
		++count;
		return a < b;
	}
};

#endif
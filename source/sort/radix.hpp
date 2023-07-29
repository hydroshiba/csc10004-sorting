#ifndef SORT_RADIX_HPP
#define SORT_RADIX_HPP

/* ---------------------- RADIX SORT ---------------------- */

// This radix sort implementation uses base 256, which is the value of a byte (8 bits),
// so that the calculation of indices and digits can be done using bitwise operations.
// Since the base is 256, the number of digits (K) is equal to the number of bytes in
// the type. The histogram is iterated from the end so this implementation is also stable.

/*
- Average Complexity: O(N * K)
- Best Complexity: O(N * K)
- Worst Complexity: O(N * K)
- Space Complexity: O(N + K)
- Stability: Yes
- Does not work with custom comparators (of course since there's no comparison)
*/

#include <climits>
#include <cstring>
#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void radixSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	
	size_t size = end - begin;
	if(loop(size, 2)) return;
	
	size_t bytes = sizeof(Type);
	size_t bits = CHAR_BIT;
	size_t mask = (1 << bits) - 1;

	size_t* count = new size_t[mask + 1]();
	Type* temp = new Type[size];

	for(size_t i = 0; loop(i, bytes); ++i) {
		size_t shift = bits * i;
		memset(count, 0, sizeof(size_t) * (mask + 1));
		
		for(size_t j = 0; loop(j, size); ++j) ++count[(begin[j] >> shift) & mask];
		for(size_t j = 1; loop(j, mask + 1); ++j) count[j] += count[j - 1];
		
		for(size_t j = size - 1; loop(j, size); --j) {
			--count[(begin[j] >> shift) & mask];
			temp[count[(begin[j] >> shift) & mask]] = begin[j];
		}

		for(size_t j = 0; loop(j, size); ++j) begin[j] = temp[j];
	}

	delete[] count;
	delete[] temp;
}

template <typename iter, class Compare>
void radixSort(iter begin, iter end, Compare &func) {
	auto loop = std::less<size_t>();
	radixSort(begin, end, func, loop);
}

template <typename iter>
void radixSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	radixSort(begin, end, func);
}

#endif
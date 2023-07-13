#ifndef SORT_MERGE_HPP
#define SORT_MERGE_HPP

#include <cstdint>

template <typename iter, class Compare>
void merge(iter lbegin, iter lend, iter rbegin, iter rend, iter begin, Compare &func) {
	size_t size = lend - lbegin + rend - rbegin;
	
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	Type* temp = new Type[size];
	Type* pos = temp;

	while(lbegin < lend && rbegin < rend) {
		iter &cur = (func(*lbegin, *rbegin) ? lbegin : rbegin);
		*pos = *cur;

		++pos;
		++cur;
	}

	while(lbegin < lend) {
		*pos = *lbegin;
		++lbegin;
		++pos;
	}

	while(rbegin < rend) {
		*pos = *rbegin;
		++rbegin;
		++pos;
	}

	for(size_t i = 0; i < size; i++) {
		*begin = temp[i];
		++begin;
	}

	delete[] temp;
}

template <typename iter, class Compare>
void mergeSort(iter begin, iter end, Compare &func) {
	size_t size = end - begin;
	if (size < 2) return;

	for(size_t i = 1; i + i < size; i <<= 1) {
		for(size_t j = 0; j + i < size; j += (i << 1)) {
			iter left = begin + j;
			iter mid = begin + j + i;
			iter right = begin + std::min(j + (i << 1), size);

			merge(left, mid, mid, right, left, func);
		}
	}
}

template <typename iter>
void mergeSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

	auto func = std::less<Type>();
	mergeSort(begin, end, func);
}

#endif
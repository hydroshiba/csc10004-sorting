#ifndef SORT_HEAP_HPP
#define SORT_HEAP_HPP

/* ---------------------- HEAP SORT ---------------------- */

/*
- Average Complexity: O(N log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N log N)
- Space Complexity: O(1)
- Stability: No
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare>
void heapify(iter begin, iter end, iter pos, Compare &func) {
	iter cur = pos;
	
	while(true) {
		size_t dist = cur - begin + 1;

		iter left = cur + dist;
		iter right = cur + dist + 1;

		iter next;

		if(left >= end || (right < end && func(*left, *right))) {
			next = right;
			func.count+=2;
		}
		else next = left;

		if(next < end && func(*cur, *next)) {
			func.count++;
			std::swap(*cur, *next);
			cur = next;
			continue;
		}

		return;
	}
}

template <typename iter, class Compare>
void heapBuild(iter begin, iter end, Compare &func) {
	intmax_t size = end - begin;

	for(intmax_t i = size / 2; i > -1; --i) {
		func.count++;
		heapify(begin, end, begin + i, func);
	}
}

template <typename iter, class Compare>
void heapSort(iter begin, iter end, Compare &func) {
	heapBuild(begin, end, func);

	for(iter i = end - 1; i > begin; --i) {
		func.count++;
		std::swap(*begin, *i);
		heapify(begin, i, begin, func);
	}
}

template<class Compare>
void heapSort(int* arr, int n, Compare &func) {
	heapSort(arr, arr+n, func);
}

template <typename iter>
void heapSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

	auto func = std::less<Type>();
	heapSort(begin, end, func);
}

#endif
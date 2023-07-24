#ifndef SORT_HEAP_HPP
#define SORT_HEAP_HPP

/* ---------------------- HEAP SORT ---------------------- */

/*
- Average Complexity: O(N log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N log N)
- Space Complexity: O(1)
- Stability: No
- Works with custom compare functions
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void heapify(iter begin, iter end, iter pos, Compare &func, CompareLoop &loop) {
	size_t size = end - begin;
	size_t cur = pos - begin;

	while(true) {
		size_t left = (cur << 1) + 1;
		size_t right = left + 1;

		size_t next = left;
		if(!loop(left, size) || (loop(right, size) && func(begin[left], begin[right])))
			next = right;

		if(loop(next, size) && func(begin[cur], begin[next])) {
			std::swap(begin[cur], begin[next]);
			cur = next;
			continue;
		}

		return;
	}
}

template <typename iter, class Compare, class CompareLoop>
void heapBuild(iter begin, iter end, Compare &func, CompareLoop &loop) {
	size_t size = end - begin;
	for(size_t i = size / 2; loop(i, size); --i)
		heapify(begin, end, begin + i, func, loop);
}

template <typename iter, class Compare, class CompareLoop>
void heapSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
	size_t size = end - begin;
	if(loop(size, 2)) return;

	heapBuild(begin, end, func, loop);

	for(size_t i = size - 1; loop(0, i); --i) {
		std::swap(begin[0], begin[i]);
		heapify(begin, begin + i, begin, func, loop);
	}
}

template <typename iter, class Compare>
void heapSort(iter begin, iter end, Compare &func) {
	auto loop = std::less<size_t>();
	heapSort(begin, end, func, loop);
}

template <typename iter>
void heapSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	heapSort(begin, end, func);
}

#endif
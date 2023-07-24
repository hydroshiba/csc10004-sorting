#ifndef SORT_QUICK_HPP
#define SORT_QUICK_HPP

/* ---------------------- QUICK SORT ---------------------- */

// Instead of the taught method of partitioning (also known as Lomuto's partition scheme), this
// implementation uses Hoare's partition instead. This is because Lomuto's method degrades to
// O(N^2) when the array elements are equal (the partition point is deviated to one side) while
// Hoare's method does not. Hoare's method is also more efficient in general.

/*
- Average Complexity: O(N log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N^2)
- Space Complexity: O(log N)
- Stability: No
- Works with custom compare functions
*/

#include <iterator>
#include <utility>
#include "../utility/random.hpp"

template <typename iter, class Compare, class CompareLoop>
iter partition(iter begin, iter end, Compare &func, CompareLoop &loop) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	
	size_t size = end - begin;
	Type pivot = begin[random(size)];
	
	iter left = begin;
	iter right = end - 1;

	while(loop(left - begin, right - begin)) {
		while(func(*left, pivot)) ++left;
		while(func(pivot, *right)) --right;

		if(!loop(left - begin, right - begin)) return right + func(*right, pivot);
		std::swap(*left, *right);

		++left;
		--right;
	}

	return right + func(*right, pivot);
}

template <typename iter, class Compare, class CompareLoop>
void quickSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
	size_t size = end - begin;

	if(loop(size, 2)) return;
	if(loop(size, 3)) {
		if(func(begin[1], begin[0])) std::swap(begin[0], begin[1]);
		return;
	}

	iter mid = partition(begin, end, func, loop);
	quickSort(begin, mid, func, loop);
	quickSort(mid, end, func, loop);
}

template <typename iter, class Compare>
void quickSort(iter begin, iter end, Compare &func) {
	auto loop = std::less<size_t>();
	quickSort(begin, end, func, loop);
}

template <typename iter>
void quickSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	quickSort(begin, end, func);
}

#endif
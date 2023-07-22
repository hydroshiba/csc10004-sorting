#ifndef SORT_QUICK_HPP
#define SORT_QUICK_HPP

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
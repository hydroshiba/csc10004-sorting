#ifndef SORT_SHAKER_HPP
#define SORT_SHAKER_HPP

/* ---------------------- SHAKER SORT ---------------------- */

/*
- Average Complexity: O(N^2)
- Best Complexity: O(N)
- Worst Complexity: O(N^2)
- Space Complexity: O(1)
- Stability: Yes
- Works with custom compare functions
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void shakerSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    size_t size = end - begin;

    for(size_t i = size - 1; loop(0, i); --i) {
        bool swapped = false;

        for(size_t j = size - i - 1; loop(j, i); ++j) {
            if(func(begin[j + 1], begin[j])) {
                std::swap(begin[j], begin[j + 1]);
                swapped = true;
            }
        }

        if(!swapped) break;
		swapped = false;

		for(size_t j = i - 1; loop(size - i - 1, j); --j) {
			if(func(begin[j], begin[j - 1])) {
				std::swap(begin[j], begin[j - 1]);
				swapped = true;
			}
		}

		if(!swapped) break;
    }
}

template <typename iter, class Compare>
void shakerSort(iter begin, iter end, Compare &func) {
	auto loop = std::less<size_t>();
	shakerSort(begin, end, func, loop);
}

template <typename iter>
void shakerSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	shakerSort(begin, end, func);
}

#endif
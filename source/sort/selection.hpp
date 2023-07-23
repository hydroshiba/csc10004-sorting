#ifndef SORT_SELECTION_HPP
#define SORT_SELECTION_HPP

/* ---------------------- SELECTION SORT ---------------------- */

/*
- Average Complexity: O(N^2)
- Best Complexity: O(N^2)
- Worst Complexity: O(N^2)
- Space Complexity: O(1)
- Stability: No
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void selectionSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    size_t size = end - begin;

    for(size_t i = 0; loop(i, size); ++i) {
        iter min = begin + i;

        for(size_t j = i + 1; loop(j, size); ++j) {
            if (func(begin[j], *min)) {
                min = begin + j;
            }
        }

        std::swap(begin[i], *min);
    }
}

template <typename iter, class Compare>
void selectionSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    selectionSort(begin, end, func, loop);
}

template <typename iter>
void selectionSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
	auto func = std::less<Type>();
	selectionSort(begin, end, func);
}

#endif
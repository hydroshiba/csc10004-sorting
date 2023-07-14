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

#include <utility>

template <typename iter, class Compare>
void selectionSort(iter begin, iter end, Compare &func) {
    for(iter i = begin; i != end; i++) {
        iter min = i;

        for(iter j = i + 1; j != end; j++) {
            if (func(*j, *min)) {
                min = j;
            }
        }

        std::swap(*i, *min);
    }
}

template <typename iter>
void selectionSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

	auto func = std::less<Type>();
	selectionSort(begin, end, func);
}

#endif
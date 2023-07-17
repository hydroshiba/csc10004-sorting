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

// template <typename iter, class Compare>
// void selectionSort(iter begin, iter end, Compare &func) {
//     for(iter i = begin; i != end; ++i) {
//         iter min = i;

//         for(iter j = i + 1; j != end; ++j) {
//             if (func(*j, *min)) {
//                 min = j;
//             }
//         }

//         std::swap(*i, *min);
//     }
// }

template <class Compare>
void selectionSort(int *arr, int n, Compare &func) {
    for(int i = 0; func(i, n); ++i) {
        int minIdx = i;

        for(int j = i + 1; func(j, n); ++j) {
            if (func(arr[j], arr[minIdx])) {
                minIdx = j;
            }
        }

        std::swap(arr[i], arr[minIdx]);
    }
}

template <typename iter>
void selectionSort(iter begin, iter end) {
	using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

	auto func = std::less<Type>();
	selectionSort(begin, end, func);
}

#endif
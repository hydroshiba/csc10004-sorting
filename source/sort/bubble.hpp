#ifndef SORT_BUBBLE_HPP
#define SORT_BUBBLE_HPP

/* ---------------------- BUBBLE SORT ---------------------- */

// The original bubble sort runs in O(N^2) time for all cases. However, this implementation
// uses a flag to exit early if the remaining array is already sorted. This improves the best
// case to O(N) complexity.

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
void bubbleSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    size_t size = end - begin;

    for(size_t i = size - 1; loop(0, i); --i) {
        bool swapped = false;

        for(size_t j = 0; loop(j, i); ++j) {
            if(func(begin[j + 1], begin[j])) {
                std::swap(begin[j], begin[j + 1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

template <typename iter, class Compare>
void bubbleSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    bubbleSort(begin, end, func, loop);
}

template <typename iter>
void bubbleSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
    auto func = std::less<Type>();
    bubbleSort(begin, end, func);
}

#endif
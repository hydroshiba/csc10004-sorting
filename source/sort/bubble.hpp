#ifndef SORT_BUBBLE_HPP
#define SORT_BUBBLE_HPP

/* ---------------------- BUBBLE SORT ---------------------- */

/*
- Average Complexity: O(N^2)
- Best Complexity: O(N)
- Worst Complexity: O(N^2)
- Space Complexity: O(1)
- Stability: Yes
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare>
void bubbleSort(iter begin, iter end, Compare &func) {
    for(iter i = end - 1; ++func.count && i != begin; --i) {
        bool swapped = false;
        for(iter j = begin; ++func.count && j != i; ++j) {
            if(func(*(j + 1), *j)) {
                std::swap(*j, *(j + 1));
                swapped = true;
            }
        }

        if(++func.count && !swapped) break;
    }
}

template<class Compare>
void bubbleSort(int* arr, int n, Compare &func) {
    bubbleSort(arr, arr+n, func);
}

template <typename iter>
void bubbleSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

    auto func = std::less<Type>();
    bubbleSort(begin, end, func);
}

#endif
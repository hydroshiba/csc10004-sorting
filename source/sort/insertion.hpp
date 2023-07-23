#ifndef SORT_INSERTION_HPP
#define SORT_INSERTION_HPP

/* ---------------------- INSERTION SORT ---------------------- */

// This implementation of insertion sort uses binary search to find the position of the
// current element in the sorted array. This makes the best case O(N). The worst case is
// still O(N^2) because the array must be shifted over to make room for the new element.

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
void insertionSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    using Type = typename std::iterator_traits<iter>::value_type;
    size_t size = end - begin;

    for(size_t i = 1; loop(i, size); ++i) {
        // Binary search for the position of the current element

        size_t pos = 0;
        size_t log = [&] (size_t x) -> size_t {
            size_t res = 0;
            while(loop(0, x)) {
                ++res;
                x >>= 1;
            }
            return res;
        } (i);

        for(size_t step = log; loop(step, size); --step) {
            size_t cur = pos + (size_t(1) << step);
            if(!loop(cur, i)) continue;
            if(func(begin[cur], begin[i])) pos = cur;
        }

        // Shifting the array to make room for the new element

        if(func(begin[pos], begin[i])) ++pos;
        Type temp = std::move(begin[i]);

        for(size_t j = i; loop(pos, j); --j)
            begin[j] = std::move(begin[j - 1]);

        begin[pos] = std::move(temp);
    }
}

template <typename iter, class Compare>
void insertionSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    insertionSort(begin, end, func, loop);
}

template <class Compare>
void insertionSort(int* arr, int n, Compare &func) {
    insertionSort(arr, arr+n, func);
}

template <typename iter>
void insertionSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<iter>::value_type;
    auto func = std::less<Type>();
    insertionSort(begin, end, func);
}

#endif
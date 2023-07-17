#ifndef SORT_MERGE_HPP
#define SORT_MERGE_HPP

/* ---------------------- MERGE SORT ---------------------- */

/*
- Average Complexity: O(N log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N log N)
- Space Complexity: O(N)
- Stability: Yes
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare>
void merge(iter lbegin, iter lend, iter rbegin, iter rend, iter begin, Compare &func) {
    size_t size = lend - lbegin + rend - rbegin;
    
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
    Type* temp = new Type[size];
    Type* pos = temp;

    while(++func.count && lbegin < lend && ++func.count && rbegin < rend) {
        iter &cur = (!func(*rbegin, *lbegin) ? lbegin : rbegin);
        *pos = *cur;

        ++pos;
        ++cur;
    }

    while(++func.count && lbegin < lend) {
        *pos = *lbegin;
        ++lbegin;
        ++pos;
    }

    while(++func.count && rbegin < rend) {
        *pos = *rbegin;
        ++rbegin;
        ++pos;
    }

    for(size_t i = 0; ++func.count && i < size; i++) {
        *begin = temp[i];
        ++begin;
    }

    delete[] temp;
}

template <typename iter, class Compare>
void mergeSort(iter begin, iter end, Compare &func) {
    size_t size = end - begin;
    if (func(size, 2)) return;

    for(size_t i = 1; i < size; i <<= 1) {
        func.count++;
        for(size_t j = 0; j < size; j += (i << 1)) {
            func.count++;
            iter left = begin + j;
            iter mid = begin + std::min(j + i, size);
            func.count++;
            iter right = begin + std::min(j + (i << 1), size);
            func.count++;
            merge(left, mid, mid, right, left, func);
        }
    }
}

template<class Compare>
void mergeSort(int* arr, int n, Compare &func) {
    mergeSort(arr, arr+n, func);
}

template <typename iter>
void mergeSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

    auto func = std::less<Type>();
    mergeSort(begin, end, func);
}

#endif
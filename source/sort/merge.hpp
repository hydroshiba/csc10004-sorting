#ifndef SORT_MERGE_HPP
#define SORT_MERGE_HPP

/* ---------------------- MERGE SORT ---------------------- */

// Merging in this implementation is done bottom up instead of top down, so
// there's no recursion overhead. This is done by merging subarrays of size of
// powers of 2 starting from size 1.

/*
- Average Complexity: O(N log N)
- Best Complexity: O(N log N)
- Worst Complexity: O(N log N)
- Space Complexity: O(N)
- Stability: Yes
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void merge(iter lbegin, iter lend, iter rbegin, iter rend, iter begin, Compare &func, CompareLoop &loop) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
    size_t size = lend - lbegin + rend - rbegin;

    size_t lsize = lend - lbegin;
    size_t rsize = rend - rbegin;

    size_t lpos = 0;
    size_t rpos = 0;
    
    Type* temp = new Type[size];
    Type* pos = temp;

    while(loop(lpos, lsize) && loop(rpos, rsize)) {
        if(func(rbegin[rpos], lbegin[lpos])) *pos = rbegin[rpos++];
        else *pos = lbegin[lpos++];
        ++pos;
    }

    while(loop(lpos, lsize)) {
        *pos = lbegin[lpos++];
        ++pos;
    }

    while(loop(rpos, rsize)) {
        *pos = rbegin[rpos++];
        ++pos;
    }

    for(size_t i = 0; loop(i, size); ++i) {
        *begin = temp[i];
        ++begin;
    }

    delete[] temp;
}

template <typename iter, class Compare, class CompareLoop>
void mergeSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    size_t size = end - begin;
    if (func(size, 2)) return;

    for(size_t i = 1; loop(i, size); i <<= 1) {
        for(size_t j = 0; loop(j, size); j += (i << 1)) {
            iter left = begin + j;
            iter mid = begin + std::min(j + i, size, loop);
            iter right = begin + std::min(j + (i << 1), size, loop);

            merge(left, mid, mid, right, left, func, loop);
        }
    }
}

template <typename iter, class Compare>
void mergeSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    mergeSort(begin, end, func, loop);
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
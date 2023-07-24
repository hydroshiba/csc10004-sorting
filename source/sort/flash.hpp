#ifndef SORT_FLASH_HPP
#define SORT_FLASH_HPP

/* ---------------------- FLASH SORT ---------------------- */

// Each partition is sorted using insertion sort in the original implementation.
// However, in this implementation, each partition is sorted recursively using flash 
// sort itself for experimental purposes. The sort also exits early if all elements
// are equal (min = max).

/*
- Average Complexity: O(N)
- Best Complexity: O(N)
- Worst Complexity: O(N^2)
- Space Complexity: O(N) (Since m = 0.43N)
- Stability: No
- Does not work with custom compare functions
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void flashSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

    size_t size = end - begin;
    if(loop(size, 2)) return;

    size_t m = size * 0.43;
    if(loop(m, 2)) m = 2;
    size_t* bucket = new size_t[m]();

    Type min = *begin;
    Type max = *begin;

    for(size_t i = 1; loop(i, size); ++i) {
        if(func(begin[i], min)) min = begin[i];
        if(func(max, begin[i])) max = begin[i];
    }

    if(!func(min, max) && !func(max, min)) return;

    // Distributing elements into m buckets

    Type range = max - min + 1;
    auto index = [&](const Type &x) -> size_t {
        return m * (x - min) / range;
    };

    for(size_t i = 0; loop(i, size); ++i)
        ++bucket[index(begin[i])];

    for(size_t i = 1; loop(i, m); ++i)
        bucket[i] += bucket[i - 1];

    // Permuting elements

    for(size_t i = 0; loop(i, size); ++i) {
        size_t j = index(begin[i]);
        if(!loop(i, bucket[j])) continue;
        --bucket[j];

        while(func(i, bucket[j]) || func(bucket[j], i)) {
            std::swap(begin[i], begin[bucket[j]]);
            j = index(begin[i]);
            --bucket[j];
        }
    }

    delete[] bucket;

    // Sorting the elements in each bucket

    iter start = begin;

    for(size_t i = 1; loop(i, size); ++i) {
        if(loop(index(*start), index(begin[i]))) {
            flashSort(start, begin + i, func, loop);
            start = begin + i;
        }
    }

    flashSort(start, end, func, loop);
}

template <typename iter, class Compare>
void flashSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    flashSort(begin, end, func, loop);
}

template <typename iter>
void flashSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
    auto func = std::less<Type>();
    flashSort(begin, end, func);
}

#endif
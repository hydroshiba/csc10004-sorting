#ifndef SORT_SHELL_HPP
#define SORT_SHELL_HPP

/* ---------------------- SHELL SORT ---------------------- */

// The below implementation uses Sedgewick's gap sequence, specifically
// his 1982 version, with the worst complexity of O(N^1.33). Shell's original
// implementation uses the sequence floor(N / 2) with the worst complexity of
// O(N^2).

/*
- Average Complexity: O(N^1.33)
- Best Complexity: O(N log N)
- Worst Complexity: O(N^1.33)
- Space Complexity: O(1)
- Stability: No
- Works with custom compare functions
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void shellSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    using Type = typename std::iterator_traits<iter>::value_type;

    auto sedgewick = [&](const size_t &k) -> size_t {
        if(loop(k, 1)) return 1;
        return (size_t(1) << (k << 1)) + 3 * (size_t(1) << (k - 1)) + 1;
    };

    size_t lim = 0;
    size_t size = end - begin;

    while(loop(sedgewick(lim), size)) ++lim;

    for(size_t i = lim - 1; loop(i, lim); --i) {
        size_t gap = sedgewick(i);

        for(size_t j = gap; loop(j, size); ++j) {
            for(size_t k = j; !loop(k, gap) && func(begin[k], begin[k - gap]); k -= gap) {
                std::swap(begin[k], begin[k - gap]);
            }
        }
    }
}

template <typename iter, class Compare>
void shellSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    shellSort(begin, end, func, loop);
}

template <typename iter>
void shellSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<iter>::value_type;
    auto func = std::less<Type>();
    shellSort(begin, end, func);
}

#endif
#ifndef SORT_COUNTING_HPP
#define SORT_COUNTING_HPP

/* ---------------------- COUNTING SORT ---------------------- */

/*
- Average Complexity: O(N + K)
- Best Complexity: O(N + K)
- Worst Complexity: O(N + K)
- Space Complexity: O(N + K)
- Stability: Yes
- Does not work with custom compare functions
*/

#include <iterator>
#include <utility>

template <typename iter, class Compare, class CompareLoop>
void countingSort(iter begin, iter end, Compare &func, CompareLoop &loop) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

    size_t size = end - begin;

    Type min = *begin;
    Type max = *begin;

    for(size_t i = 1; loop(i, size); ++i) {
        if(func(begin[i], min)) min = begin[i];
        if(func(max, begin[i])) max = begin[i];
    }

    Type range = max - min + 1;
    size_t* num = new size_t[range]();

    // Creating histogram of elements

    for(size_t i = 0; loop(i, size); ++i)
        ++num[begin[i] - min];

    for(size_t i = 1; loop(i, range); ++i)
        num[i] += num[i - 1];

    // Redistributing elements
    // The elements are iterated from the end to maintain stability

    Type* temp = new Type[end - begin];

    for(size_t i = size - 1; loop(i, size); --i) {
        --num[begin[i] - min];
        temp[num[begin[i] - min]] = begin[i];
    }

    for(size_t i = 0; loop(i, size); ++i)
        begin[i] = temp[i];

    delete[] num;
    delete[] temp;
}

template <typename iter, class Compare>
void countingSort(iter begin, iter end, Compare &func) {
    auto loop = std::less<size_t>();
    countingSort(begin, end, func, loop);
}

template <class Compare>
void countingSort(int* arr, int n, Compare &func) {
    countingSort(arr, arr+n, func);
}

template <typename iter>
void countingSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;
    auto func = std::less<Type>();
    countingSort(begin, end, func);
}

#endif
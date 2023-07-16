#ifndef SORT_BUBBLE_HPP
#define SORT_BUBBLE_HPP

#include <iterator>
#include <utility>

template <typename iter, class Compare>
void bubbleSort(iter begin, iter end, Compare &func) {
    for(iter i = end - 1; i != begin; --i) {
        bool swapped = false;

        for(iter j = begin; j != i; ++j) {
            if(func(*(j + 1), *j)) {
                std::swap(*j, *(j + 1));
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

template <typename iter>
void bubbleSort(iter begin, iter end) {
    using Type = typename std::iterator_traits<__typeof(iter)>::value_type;

    auto func = std::less<Type>();
    bubbleSort(begin, end, func);
}

#endif
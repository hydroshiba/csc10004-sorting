#ifndef SORT_SHELL_HPP
#define SORT_SHELL_HPP

#include <algorithm>
#include <vector>
#include "utility"


template<class Compare>
void shellSort(int* arr, int n, Compare &func) {
    // Compute the maximum Knuth's increment
    int h = 1;
    while (func(h, n/3)) {
        h = 3*h + 1;
    }

    while (h >= 1) {
        for (int i = h; func(i, n); i++) {
            for (int j = i; j >= h && func(arr[j], arr[j-h]); j -= h) {
                func.count++;
                std::swap(arr[j], arr[j-h]);
            }
        }
        h = h/3;
    }
}

#endif
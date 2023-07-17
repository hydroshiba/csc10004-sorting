#ifndef SORT_COUNTING_HPP
#define SORT_COUNTING_HPP

#include <algorithm>
#include <vector>

// template <typename iter>
// void countingSort(iter begin, iter end) {
//     size_t size = end - begin;
//     int max_val = *std::max_element(begin, end);
//     int *count = new int[size+1]{0};
//     for (iter i = begin; i < end; i++) {
//         count[*i]++;
//     }
//     for (int i = 1; i <= size; i++) {
//         count[i] += count[i-1];
//     }
//     int output[size];
//     for (int i = 0; i < size; i++) {
//         output[count[*(begin+i)] -1] = *(begin+i);
//         count[*(begin+i)--];
//     }
//     for (iter i = begin; i < end; i++) {
//         *i = output[i-begin];
//     }
// }

template<class Compare>
void countingSort(int* arr, int n, Compare &func)
{
    int max_val = *std::max_element(arr, arr+n);
    func.count += n - 1; //max_element uses max((last-begin)-1, 0) comparisons
    int count[max_val + 1]{0};
    for (int i = 0; func(i, n); i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; ++func.count && i <= max_val; i++)
    {
        count[i] += count[i - 1];
    }
    int output[n];
    for (int i = n - 1; ++func.count && i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; func(i, n); i++)
    {
        arr[i] = output[i];
    }
}

#endif
#ifndef SORT_INSERTION_HPP
#define SORT_INSERTION_HPP

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

template <class value, class comparator>
void insertion_sort_countCompare(value *arr, int n, comparator &compare_func)
{
    value i, key, j;
    for (i = 1;(++compare_func.count) && (i < n); i++)
    {
        key = arr[i];
        j = i - 1;
        while ((++compare_func.count) && (j >= 0 && arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            ++compare_func.count;
        }
        arr[j + 1] = key;
    }
}

template <class value>
void insertion_sort(value *arr, int n)
{
    value i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


#endif
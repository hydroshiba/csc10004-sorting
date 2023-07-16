#ifndef SORT_INSERTION_HPP
#define SORT_INSERTION_HPP

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

template <class Comparator>
void insertionSort_countCmp(int *arr, int size, Comparator &count)
{
    int i, key, j;
    for (i = 1; ++count && i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (++count && (j >= 0 && arr[j] > key))
        {
            ++count;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSort(int *arr, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
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
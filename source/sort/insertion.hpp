#ifndef SORT_INSERTION_HPP
#define SORT_INSERTION_HPP

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

template <class Compare>
void insertionSort(int *arr, int size, Compare &func)
{
    int i, key, j;
    for (i = 1; func(i, size); i++)
    {
        key = arr[i];
        j = i - 1;
        while ( func.count++ && (j >= 0 && arr[j] > key) && func.count++)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// void insertionSort(int *arr, int size)
// {
//     int i, key, j;
//     for (i = 1; i < size; i++)
//     {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

#endif
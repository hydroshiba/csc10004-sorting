#ifndef SORT_BUBBLE_HPP
#define SORT_BUBBLE_HPP


template<class val>
void swapNum(val &a, val &b)
{
    val temp = a;
    a = b;
    b = temp;
}

template<class Comparator>
void bubbleSort_countCmp(int *arr, int n,Comparator &count)
{
    int i, j;
    bool swapped;
    for (i = 0; ++count && i < n - 1; i++) {
        swapped = false;
        for (j = 0; ++count && j < n - i - 1; j++) {
            if (++count && (arr[j] > arr[j + 1])) {
                swapNum(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (++count && (swapped == false))
            break;
    }
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapNum(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}


#endif
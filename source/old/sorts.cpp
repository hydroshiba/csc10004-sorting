#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

int *generateArray(int &n)
{
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    return arr;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minn = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[minn] > arr[j])
            {
                minn = j;
            }
        }
        swap(arr[i], arr[minn]);
    }
}

void heapify(int *arr, int left, int right)
{
    int child = left * 2 + 1;
    if (child > right)
        return;
    if (child + 1 < right && arr[child] < arr[child + 1])
    {
        child = child + 1;
    }
    if (arr[left] < arr[child])
    {
        swap(arr[left], arr[child]);
        heapify(arr, child, right);
    }
}

void heapSort(int *arr, int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(arr, i, size - 1);
    }
    for (int i = size - 1; i >= 1; i--)
    {
        if (arr[i] < arr[0])
            swap(arr[i], arr[0]);
        heapify(arr, 0, i - 1);
    }
}

void quickSort(int *arr, int size, int left, int right)
{
    int pivotVal = arr[(right + left) / 2];
    int i = left, j = right;
    while (i <= j)
    {
        while (arr[i] < pivotVal)
            i++;
        while (arr[j] > pivotVal)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > left)
        quickSort(arr, j - left + 1, left, j);
    if (i < right)
        quickSort(arr, right - i + 1, i, right);
}

void merge(int *arr, int left, int mid, int right)
{
    int *tmp = new int[right - left + 1];
    int subLeft = left;
    int subRight = mid + 1;
    int tmpSize = 0;
    while (tmpSize < right - left + 1)
    {
        if ((subLeft <= mid && arr[subLeft] < arr[subRight]) || subRight > right)
        {
            tmp[tmpSize++] = arr[subLeft++];
        }
        else
        {
            tmp[tmpSize++] = arr[subRight++];
        }
    }
    for (int i = 0; i < tmpSize; i++)
    {
        arr[left + i] = tmp[i];
    }
    delete[] tmp;
}

void mergeSort(int *arr, int left, int right)
{
    if (right - left < 1)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
struct Node
{
    int data;
    Node *next = nullptr;
};

void displayNode(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void addNode(Node *head, int data)
{
    while (head->next)
    {
        head = head->next;
    }
    head->next = new Node;
    head->next->data = data;
}

int getData(Node *&head)
{
    Node *curr = head;
    head = head->next;
    int rt = curr->data;
    delete curr;
    return rt;
}

void radixSort(int *arr, int size)
{
    int currDigit = 0;
    bool isEnd = false;
    while (!isEnd)
    {
        isEnd = true;
        Node **bucket = new Node *[10];
        for (int i = 0; i < 10; i++)
        {
            bucket[i] = new Node;
        }
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < (int)pow(10, currDigit))
            {
                addNode(bucket[0], arr[i]);
                continue;
            }
            addNode(bucket[(arr[i] / (int)pow(10, currDigit)) % 10], arr[i]);
            isEnd = false;
        }
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            bucket[i] = bucket[i]->next;
            while (bucket[i])
            {
                arr[cnt++] = getData(bucket[i]);
            }
            delete bucket[i];
        }
        currDigit++;
        delete[] bucket;
    }
}

void insertionSort(int *arr, int n)
{
    int i, key, j;
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

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// int main()
// {
//     srand(time(NULL));
//     int size = 6;
//     int *arr = generateArray(size);
//     printArray(arr, size);
//     insertionSort(arr, size);
//     printArray(arr, size);
//     delete[] arr;
//     return 0;
// }

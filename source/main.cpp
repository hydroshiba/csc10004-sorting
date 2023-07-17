// Command: .\main.exe -a [sort-algo] [input size] [input-type] [output-parameter]
// See sortingAlgo map for [sort-algo]
// [input size] receive an integer > 0
// see inputType map for [input-type] 
// see outParam map for [output-parameter]

#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <cstring>

// Utilities
#include "utility/comparator.hpp"
#include "utility/random.hpp"
#include "utility/timer.hpp"
#include "utility/DataGenerator.cpp"

// Sorting algorithms
#include "source/sort/heap.hpp"
#include "source/sort/bubble.hpp"
#include "source/sort/shaker.hpp"
#include "source/sort/insertion.hpp"
#include "source/sort/lis.hpp"
#include "source/sort/merge.hpp"
#include "source/sort/quick.hpp"
#include "source/sort/selection.hpp"
#include "source/sort/shell.hpp"
#include "source/sort/counting.hpp"
#include "source/sort/flash.hpp"
#include "source/sort/radix.hpp"

typedef void (*sort_ptr)(int*, int, Comparator<int>&);
sort_ptr sortFunc[] = {selectionSort, insertionSort, bubbleSort, heapSort, mergeSort, quickSort, radixSort, shakerSort, shellSort, countingSort, flashSort};

const char* algoName[11] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Shaker Sort", "Shell Sort", "Counting Sort", "Flash Sort"};

unordered_map<string, int> sortingAlgo = {
    {"selection-sort", 0}, 
    {"insertion-sort", 1}, 
    {"bubble-sort", 2}, 
    {"heap-sort", 3}, 
    {"merge-sort", 4}, 
    {"quick-sort", 5}, 
    {"radix-sort", 6}, 
    {"shaker-sort", 7}, 
    {"shell-sort", 8}, 
    {"counting-sort", 9}, 
    {"flash-sort", 10}
};

unordered_map<string, int> inputType = {
    {"-rand", 0}, 
    {"-sorted", 1}, 
    {"-rev", 2}, 
    {"-nsorted", 3}
};

const char* typeName[] = {"Randomized data", "Sorted data", "Reverse sorted data", "Nearly sorted data"};

unordered_map<string, int> outParams = {
    {"-time", 0}, 
    {"-comp", 1}, 
    {"-both", 2}
};

int getAlgo(const char* algo) {
    auto it = sortingAlgo.find(algo);
    return (it != sortingAlgo.end()) ? it->second : -1;
}

int getType(const char* type) {
    auto it = inputType.find(type);
    return (it != inputType.end()) ? it->second : -1;
}

int getParam(const char* param) {
    auto it = outParams.find(param);
    return (it != outParams.end()) ? it->second : -1;
}
int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "-a") == 0) {
        if (argc == 6) {
            int algo = getAlgo(argv[2]);
            int type = getType(argv[4]);
            int param = getParam(argv[5]);
            int size = stoi(argv[3]);
            if (algo == -1 || type == -1 || param == -1 || size <= 0) {
				cout << "Error: invalid parameter(s)" << endl;
				return 0;
			}
			cout << "Algorithm: " << algoName[algo] << endl;
			cout << "Input size: " << size << endl;
			cout << "Input order: " << typeName[type] << endl;
			cout << "-----------------------------" << endl;
			int* arr = new int[size];
			Timer timer;
			GenerateData(arr, size, type);
			Comparator<int> func;
			timer.start();
			sortFunc[algo](arr, size, func);
			int64_t totalTime = timer.get();
			cout << "Running time (if required): " << ((param==0 || param==2) ? to_string(totalTime):"") << endl;
			cout << "Comparisons (if required): " << ((param==1 || param==2) ? to_string(func.count):"") << endl;
			return 0;
        }
    }
}

// void sortTest()
// {
// 	int n = 10;
// 	std::vector<int> arr(n);
// 	for (int i = 0; i < n; ++i)
// 		arr[i] = random(1, n);
// 	arr.push_back(1);

// 	for (int i : arr)
// 		std::cout << i << " ";
// 	std::cout << std::endl;

// 	mergeSort(arr.begin(), arr.end());
// 	for (int i : arr)
// 		std::cout << i << " ";
// }

// void demo()
// {
// 	int n = 10;
// 	int *org = new int[n];

// 	// To generate random numbers, use random(min, max)

// 	std::cout << "Original array: ";

// 	for (int *i = org; i < org + n; ++i)
// 	{
// 		*i = random(1, n);
// 		std::cout << *i << " ";
// 	}

// 	std::cout << std::endl;

// 	// To sort, pass the begin and end pointers of the array as arguments to the sorting algorithm
// 	// The end pointer is the address AFTER the last element
// 	// Simply put, the sorting range is [begin, end)

// 	int *arr = new int[n];
// 	std::copy(org, org + n, arr);

// 	selectionSort(arr, arr + n);

// 	std::cout << "Sorted array: ";
// 	for (int *i = arr; i < arr + n; ++i)
// 		std::cout << *i << " ";
// 	std::cout << std::endl;

// 	delete[] arr;

// 	// This can also be done with vectors, simply use vec.begin() and vec.end() as begin and end pointers instead

// 	std::vector<int> vec(org, org + n);

// 	selectionSort(vec.begin(), vec.end());

// 	std::cout << "Sorted vector: ";
// 	for (int i : vec)
// 		std::cout << i << " ";
// 	std::cout << std::endl;

// 	// To time a sorting algorithm, create a timer object and call start() before the sorting algorithm and get() after it

// 	n = 10000;
// 	vec = std::vector<int>(n);
// 	for (int i = 0; i < n; ++i)
// 		vec[i] = random(1, n);

// 	Timer timer;
// 	timer.start();

// 	mergeSort(vec.begin(), vec.end());
// 	std::cout << "Time: " << timer.get() << std::endl;

// 	// To count the number of comparisons, create a comparator object and pass it to the sorting algorithm
// 	// The result is stored in the comparator variable `count`
// 	// Creating a separate comparator for counting ensures that counting does not affect the raw runtime of the sorting algorithm

// 	for (int i = 0; i < n; ++i)
// 		vec[i] = random(1, n);
// 	Comparator<int> comp;

// 	selectionSort(vec.begin(), vec.end(), comp);
// 	std::cout << "Comparisons: " << comp.count << std::endl;

// 	delete[] org;
// }

// void insertionSort_test()
// {
// 	int n = 100000;
// 	int *TempArr = new int[n];
// 	int *TempArr1 = new int[n];

// 	for (int i = 0; i <= 3; ++i)
// 	{
// 		GenerateData(TempArr, n, 0);
// 		for (int i = 0; i < n; ++i)
// 			TempArr1[i] = TempArr[i];
// 		Timer timer;
// 		timer.start();
		
// 		insertionSort(TempArr, n);
// 		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

// 		Comparator<int> cmp;
// 		insertionSort_countCmp(TempArr1, n, cmp.count);
// 		cout << "Comparisions: " << cmp.count << endl;
// 	}

// 	delete[] TempArr1;
// 	TempArr1 = nullptr;
// 	delete[] TempArr;
// 	TempArr = nullptr;
// }

// void bubbleSort_test()
// {

// 	int n = 70000;
// 	int *TempArr = new int[n];
// 	int *TempArr1 = new int[n];

// 	for (int i = 0; i <= 3; ++i)
// 	{
// 		GenerateData(TempArr, n, 0);
// 		for (int i = 0; i < n; ++i)
// 			TempArr1[i] = TempArr[i];

// 		Timer timer;
// 		timer.start();

// 		bubbleSort(TempArr, TempArr + n);
// 		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

// 		Comparator<int> cmp;
// 		bubbleSort(TempArr1, TempArr1 + n, cmp);
// 		cout << "Comparisions: " << cmp.count << endl;
// 	}

// 	delete[] TempArr1;
// 	TempArr1 = nullptr;
// 	delete[] TempArr;
// 	TempArr = nullptr;
// }

// void shakerSort_test()
// {
// 	int n = 100000;
// 	int *TempArr = new int[n];
// 	int *TempArr1 = new int[n];

// 	for (int i = 0; i <= 3; ++i)
// 	{
// 		GenerateData(TempArr, n, 0);
// 		for (int i = 0; i < n; ++i)
// 			TempArr1[i] = TempArr[i];

// 		Timer timer;
// 		timer.start();

// 		shakerSort(TempArr, n);
// 		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

// 		Comparator<int> cmp;
// 		shakerSort_countCMP(TempArr1, n, cmp.count);
// 		cout << "Comparisions: " << cmp.count << endl;
// 	}

// 	delete[] TempArr1;
// 	TempArr1 = nullptr;
// 	delete[] TempArr;
// 	TempArr = nullptr;
// }
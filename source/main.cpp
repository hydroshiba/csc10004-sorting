#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

// Utilities
#include "utility/comparator.hpp"
#include "utility/random.hpp"
#include "utility/timer.hpp"
#include "utility/DataGenerator.cpp"

// Sorting algorithms
#include "sort/heap.hpp"
#include "sort/bubble.hpp"
#include "sort/shaker.hpp"
#include "sort/insertion.hpp"
#include "sort/lis.hpp"
#include "sort/merge.hpp"
// #include "sort/quick.hpp"
#include "sort/selection.hpp"

void sortTest()
{
	int n = 10;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		arr[i] = random(1, n);
	arr.push_back(1);

	for (int i : arr)
		std::cout << i << " ";
	std::cout << std::endl;

	mergeSort(arr.begin(), arr.end());
	for (int i : arr)
		std::cout << i << " ";
}

void demo()
{
	int n = 10;
	int *org = new int[n];

	// To generate random numbers, use random(min, max)

	std::cout << "Original array: ";

	for (int *i = org; i < org + n; ++i)
	{
		*i = random(1, n);
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	// To sort, pass the begin and end pointers of the array as arguments to the sorting algorithm
	// The end pointer is the address AFTER the last element
	// Simply put, the sorting range is [begin, end)

	int *arr = new int[n];
	std::copy(org, org + n, arr);

	selectionSort(arr, arr + n);

	std::cout << "Sorted array: ";
	for (int *i = arr; i < arr + n; ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	delete[] arr;

	// This can also be done with vectors, simply use vec.begin() and vec.end() as begin and end pointers instead

	std::vector<int> vec(org, org + n);

	selectionSort(vec.begin(), vec.end());

	std::cout << "Sorted vector: ";
	for (int i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	// To time a sorting algorithm, create a timer object and call start() before the sorting algorithm and get() after it

	n = 10000;
	vec = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		vec[i] = random(1, n);

	Timer timer;
	timer.start();

	mergeSort(vec.begin(), vec.end());
	std::cout << "Time: " << timer.get() << std::endl;

	// To count the number of comparisons, create a comparator object and pass it to the sorting algorithm
	// The result is stored in the comparator variable `count`
	// Creating a separate comparator for counting ensures that counting does not affect the raw runtime of the sorting algorithm

	for (int i = 0; i < n; ++i)
		vec[i] = random(1, n);
	Comparator<int> comp;

	selectionSort(vec.begin(), vec.end(), comp);
	std::cout << "Comparisons: " << comp.count << std::endl;

	delete[] org;
}

void insertionSort_test()
{
	int n = 100000;
	int *TempArr = new int[n];
	int *TempArr1 = new int[n];

	for (int i = 0; i <= 3; ++i)
	{
		GenerateData(TempArr, n, 0);
		for (int i = 0; i < n; ++i)
			TempArr1[i] = TempArr[i];
		Timer timer;
		timer.start();
		
		insertionSort(TempArr, n);
		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

		Comparator<int> cmp;
		insertionSort_countCmp(TempArr1, n, cmp.count);
		cout << "Comparisions: " << cmp.count << endl;
	}

	delete[] TempArr1;
	TempArr1 = nullptr;
	delete[] TempArr;
	TempArr = nullptr;
}

void bubbleSort_test()
{

	int n = 70000;
	int *TempArr = new int[n];
	int *TempArr1 = new int[n];

	for (int i = 0; i <= 3; ++i)
	{
		GenerateData(TempArr, n, 0);
		for (int i = 0; i < n; ++i)
			TempArr1[i] = TempArr[i];

		Timer timer;
		timer.start();

		bubbleSort(TempArr, TempArr + n);
		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

		Comparator<int> cmp;
		bubbleSort(TempArr1, TempArr1 + n, cmp);
		cout << "Comparisions: " << cmp.count << endl;
	}

	delete[] TempArr1;
	TempArr1 = nullptr;
	delete[] TempArr;
	TempArr = nullptr;
}

void shakerSort_test()
{
	int n = 100000;
	int *TempArr = new int[n];
	int *TempArr1 = new int[n];

	for (int i = 0; i <= 3; ++i)
	{
		GenerateData(TempArr, n, 0);
		for (int i = 0; i < n; ++i)
			TempArr1[i] = TempArr[i];

		Timer timer;
		timer.start();

		shakerSort(TempArr, n);
		cout << "Duration of " << i << " is: " << timer.get() << " milliseconds" << endl;

		Comparator<int> cmp;
		shakerSort_countCMP(TempArr1, n, cmp.count);
		cout << "Comparisions: " << cmp.count << endl;
	}

	delete[] TempArr1;
	TempArr1 = nullptr;
	delete[] TempArr;
	TempArr = nullptr;
}

int main()
{
	// sortTest();
	bubbleSort_test();
	return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>

// Utilities
#include "source/utility/comparator.hpp"
#include "source/utility/random.hpp"
#include "source/utility/timer.hpp"

// Sorting algorithms
#include "source/sort/heap.hpp"
#include "source/sort/lis.hpp"
#include "source/sort/merge.hpp"
#include "source/sort/quick.hpp"
#include "source/sort/selection.hpp"

void sortTest() {
	int n = 10;
	std::vector<int> arr(n);
	for(int i = 0; i < n; ++i) arr[i] = random(1, n);
	arr.push_back(1);

	for(int i : arr) std::cout << i << " ";
	std::cout << std::endl;

	mergeSort(arr.begin(), arr.end());
	for(int i : arr) std::cout << i << " ";
}

void demo() {
	int n = 10;
	int* org = new int[n];

	// To generate random numbers, use random(min, max)

	std::cout << "Original array: ";

	for(int* i = org; i < org + n; ++i) {
		*i = random(1, n);
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	// To sort, pass the begin and end pointers of the array as arguments to the sorting algorithm
	// The end pointer is the address AFTER the last element
	// Simply put, the sorting range is [begin, end)

	int* arr = new int[n];
	std::copy(org, org + n, arr);

	selectionSort(arr, arr + n);

	std::cout << "Sorted array: ";
	for(int* i = arr; i < arr + n; ++i) std::cout << *i << " ";
	std::cout << std::endl;

	delete[] arr;

	// This can also be done with vectors, simply use vec.begin() and vec.end() as begin and end pointers instead

	std::vector<int> vec(org, org + n);
	
	selectionSort(vec.begin(), vec.end());

	std::cout << "Sorted vector: ";
	for(int i : vec) std::cout << i << " ";
	std::cout << std::endl;
	
	// To time a sorting algorithm, create a timer object and call start() before the sorting algorithm and get() after it

	n = 10000;
	vec = std::vector<int>(n);
	for(int i = 0; i < n; ++i) vec[i] = random(1, n);

	Timer timer;
	timer.start();
	
	selectionSort(vec.begin(), vec.end());
	std::cout << std::fixed << std::setprecision(6) << "Time: " << timer.get() << std::endl;

	// To count the number of comparisons, create a comparator object and pass it to the sorting algorithm
	// The result is stored in the comparator variable `count`
	// Creating a separate comparator for counting ensures that counting does not affect the raw runtime of the sorting algorithm

	for(int i = 0; i < n; ++i) vec[i] = random(1, n);
	Comparator<int> comp;

	selectionSort(vec.begin(), vec.end(), comp);
	std::cout << "Comparisons: " << comp.count << std::endl;

	delete[] org;
}

int main() {
	demo();
	//sortTest();

	return 0;
}
#include <iostream>
#include <vector>

// Utilities
#include "source/utility/comparator.hpp"
#include "source/utility/random.hpp"
#include "source/utility/timer.hpp"

// Sorting algorithms
#include "source/sort/heap.hpp"
#include "source/sort/lis.hpp"
#include "source/sort/merge.hpp"
#include "source/sort/selection.hpp"

void sortTest() {
	int n = 100000;
	std::vector<int> arr(n);

	// To generate random numbers, use random(min, max)

	for(int &i : arr) i = random(1, n);
	
	// To time a sorting algorithm, create a timer object and call start() before the sorting algorithm and get() after it

	Timer timer;
	timer.start();
	
	mergeSort(arr.begin(), arr.end());
	std::cout << "Time: " << timer.get() << std::endl;

	// To count the number of comparisons, create a comparator object and pass it to the sorting algorithm
	// The result is stored in the comparator variable `count`
	// Creating a separate comparator for counting ensures that counting does not affect the raw runtime of the sorting algorithm

	Comparator<int> comp;
	mergeSort(arr.begin(), arr.end(), comp);
	std::cout << "Comparisons: " << comp.count << std::endl;
}

int main() {
	sortTest();
	return 0;
}
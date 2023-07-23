#ifndef SORT_HPP
#define SORT_HPP

#include <string>
#include <unordered_map>

#include "sort/bubble.hpp"
#include "sort/counting.hpp"
#include "sort/flash.hpp"
#include "sort/heap.hpp"
#include "sort/insertion.hpp"
#include "sort/lis.hpp"
#include "sort/merge.hpp"
#include "sort/quick.hpp"
#include "sort/radix.hpp"
#include "sort/selection.hpp"
#include "sort/shaker.hpp"
#include "sort/shell.hpp"

template <typename iter>
void error(iter begin, iter end) {
	return;
}

template <typename iter, class Compare, class CompareLoop>
void error(iter begin, iter end, Compare &func, CompareLoop &loop) {
	return;
}

namespace sort {
	std::unordered_map<std::string, int> id = {
		{"bubble-sort", 1}, 
		{"counting-sort", 2}, 
		{"flash-sort", 3}, 
		{"heap-sort", 4}, 
		{"insertion-sort", 5}, 
		{"merge-sort", 6}, 
		{"quick-sort", 7}, 
		{"radix-sort", 8}, 
		{"selection-sort", 9}, 
		{"shaker-sort", 10},
		{"shell-sort", 11},
		{"lis-sort", 12}
	};

	const std::string name[] = {
		"Invalid",
		"Bubble sort",
		"Counting sort",
		"Flash sort",
		"Heap sort",
		"Insertion sort",
		"Merge sort",
		"Quick sort",
		"Radix sort",
		"Selection sort",
		"Shaker sort",
		"Shell sort",
		"LIS sort"
	};

	template <typename iter>
	void (*func[])(iter, iter) = {
		error,
		bubbleSort,
		countingSort,
		flashSort,
		heapSort,
		insertionSort,
		mergeSort,
		quickSort,
		radixSort,
		selectionSort,
		shakerSort,
		shellSort,
		lisSort
	};

	template <typename iter, class Compare, class CompareLoop>
	void (*count[])(iter, iter, Compare, CompareLoop) = {
		error,
		bubbleSort,
		countingSort,
		flashSort,
		heapSort,
		insertionSort,
		mergeSort,
		quickSort,
		radixSort,
		selectionSort,
		shakerSort,
		shellSort,
		lisSort
	};
}

#endif
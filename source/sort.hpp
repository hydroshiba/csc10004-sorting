#ifndef SORT_HPP
#define SORT_HPP

#include <string>

#include "sort/bubble.hpp"
// #include "sort/counting.hpp"
// #include "sort/flash.hpp"
#include "sort/heap.hpp"
#include "sort/insertion.hpp"
#include "sort/lis.hpp"
#include "sort/merge.hpp"
// #include "sort/quick.hpp"
// #include "sort/radix.hpp"
#include "sort/selection.hpp"
#include "sort/shaker.hpp"
// #include "sort/shell.hpp"

namespace sort {
	const string name[] = {
		"bubble-sort",
		// "counting-sort",
		// "flash-sort",
		"heap-sort",
		"insertion-sort",
		"lis-sort",
		"merge-sort",
		// "quick-sort",
		// "radix-sort",
		"selection-sort",
		"shaker-sort",
		// "shell-sort"
	};

	template <typename iter>
	void (*function[])(iter, iter) = {
		bubbleSort,
		// countingSort,
		// flashSort,
		heapSort,
		insertionSort,
		lisSort,
		mergeSort,
		// quickSort,
		// radixSort,
		selectionSort,
		shakerSort,
		// shellSort
	};
}

#endif
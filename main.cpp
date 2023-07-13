#include <iostream>
#include <vector>

// Utilities
#include "comparator.hpp"
#include "random.hpp"
#include "timer.hpp"

// Sorting algorithms
#include "heap.hpp"
#include "lis.hpp"
#include "merge.hpp"
#include "selection.hpp"

bool less_than(int a, int b) {
	return a < b;
}

void sortTest() {
	int n = 100000;
	std::vector<int> arr(n);

	for(int &i : arr) i = random(1, n);

	Comparator<int> comp;
	Timer timer;

	timer.start();
	lisSort(arr.begin(), arr.end());
	
	std::cout << timer.get() << std::endl;
	std::cout << comp.count << std::endl;
}

int main() {
	sortTest();
	return 0;
}
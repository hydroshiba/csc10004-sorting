#ifndef UTIL_HPP
#define UTIL_HPP

#include "utility/counter.hpp"
#include "utility/random.hpp"
#include "utility/timer.hpp"
#include "utility/DataGenerator.cpp"

namespace order {
	std::unordered_map<std::string, int> id = {
		{"-rand", 1}, 
		{"-sorted", 2},
		{"-rev", 3},
		{"-nsorted", 4}
	};

	const std::string name[] = {
		"Invalid",
		"Random",
		"Sorted",
		"Reversed",
		"Nearly sorted"
	};
}

namespace param {
	std::unordered_map<std::string, int> id = {
		{"-time", 1}, 
		{"-comp", 2}, 
		{"-both", 3}
	};
}

size_t to_size(const std::string &s) {
	size_t res = 0;

	for(char c : s) {
		if(c < '0' || c > '9') return 0;
		res *= 10;
		res += c - '0';
	}

	return res;
}

int* importFile(const std::string &file, size_t &size) {
    ifstream ifile {file};
    if (!ifile) {
        cout << "Error: cannot open input file" << endl;
        return nullptr;
    }
    ifile >> size;
    if (size == 0) return nullptr;
    int* arr = new int[size];
    int cnt = 0;
    while (ifile >> arr[cnt++]) {}
    ifile.close();
    return arr;
}

int* duplicateArray(int* arr, int n) {
    int* newArr = new int[n];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }
    return newArr;
}

void exportFile(int* arr, int n, const std::string &name) {
    ofstream ofile {name};
    if (!ofile) {
        cout << "Error: cannot create export file" << endl;
        return;
    }
    ofile << n << endl;
    for (int i = 0; i < n; i++) {
        ofile << arr[i] << " ";
    }
    ofile.close();
}

uintmax_t timeSort(int* arr, int size, int sort) {
    Timer timer;
    
    timer.start();
    sort::func<int*>[sort](arr, arr + size);
    uintmax_t runtime = (timer.get());

    return runtime;
}

uintmax_t countSort(int* arr, int size, int sort) {
    Counter<int> func;
    Counter<size_t> loop;
    
    sort::count<int*, Counter<int>, Counter<size_t>>[sort](arr, arr + size, func, loop);
    uintmax_t comparison = func.count + loop.count;

    return comparison;
}

void measureSort(int* arr, int size, int sort, int param) {
    uintmax_t runtime, comparison;

    if(param != 2) {
        int* dup = duplicateArray(arr, size);
        runtime = timeSort(dup, size, sort);
        delete[] dup;
    }
    
    std::cout << "Running time: " << ((param != 2) ? std::to_string(runtime) : "") << std::endl;

    if(param > 1) comparison = countSort(arr, size, sort);
    std::cout << "Comparisons: " << (comparison ? std::to_string(comparison) : "") << std::endl;

    std::cout << std::endl;
}

void compareSort(int* arr, int size, int sortA, int sortB) {
    uintmax_t runtimeA, runtimeB;
    uintmax_t comparisonA, comparisonB;

    int* dupA = duplicateArray(arr, size);
    int* dupB = duplicateArray(arr, size);

    runtimeA = timeSort(dupA, size, sortA);
    std::cout << "Running time: " << runtimeA << " | ";
    
    runtimeB = timeSort(dupB, size, sortB);
    std::cout << runtimeB << std::endl;

    dupA = duplicateArray(arr, size);

    comparisonA = countSort(dupA, size, sortA);
    std::cout << "Comparisons: " << comparisonA << " | ";

    comparisonB = countSort(arr, size, sortB);
    std::cout << comparisonB << std::endl;
        
    delete[] dupA;
    delete[] dupB;
}

void saveResult(const string &fileName, const uintmax_t &comparison, const uint64_t &time, const int &algo, const int &type, const int &size) {
    
}

#endif
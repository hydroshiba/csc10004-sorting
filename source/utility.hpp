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

int* getDataFromFile(const char* file, int &size) {
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

void exportFile(int* arr, int n, std::string name) {
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

void saveResult(const string &fileName, const uintmax_t &comparison, const uint64_t &time, const int &algo, const int &type, const int &size) {
    
}

#endif
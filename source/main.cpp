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
#include "sort/heap.hpp"
#include "sort/bubble.hpp"
#include "sort/shaker.hpp"
#include "sort/insertion.hpp"
#include "sort/lis.hpp"
#include "sort/merge.hpp"
#include "sort/quick.hpp"
#include "sort/selection.hpp"
#include "sort/shell.hpp"
#include "sort/counting.hpp"
#include "sort/flash.hpp"
#include "sort/radix.hpp"

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
    {"-sorted", 2}, 
    {"-rev", 3}, 
    {"-nsorted", 1}
};

const char* typeName[] = {"Randomized data", "Nearly sorted data", "Sorted data", "Reverse sorted data"};

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

void exportFile(int* arr, int n, string name) {
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
            exportFile(arr, size, "input.txt");
			Comparator<int> func;   
			timer.start();
			sortFunc[algo](arr, size, func);
			int64_t totalTime = timer.get();
            cout << "-----------------------------" << endl;
			cout << "Running time (if required): " << ((param==0 || param==2) ? to_string(totalTime):"") << endl;
			cout << "Comparisons (if required): " << ((param==1 || param==2) ? to_string(func.count):"") << endl;
            exportFile(arr, size, "output.txt");
            delete [] arr;
			return 2;
        }
        else if (argc == 5) {
            istringstream iss (argv[3]);
            bool isNum = false;
            int test;
            if (iss >> test) {
                isNum = true;
            }
            iss.clear();
            if (isNum) {
                int algo = getAlgo(argv[2]);
                int param = getParam(argv[4]);
                int size = stoi(argv[3]);
                if (algo == -1 || param == -1 || size <= 0) {
                    cout << "Error: invalid parameter(s)" << endl;
                    return 0;
                }
                cout << "Algorithm: " << algoName[algo] << endl;
			    cout << "Input size: " << size << endl;
			    for (int i = 0; i < 4; i++) {
                    cout << "\nInput order: " << typeName[i] << endl;
                    cout << "-----------------------------" << endl;
                    int* arr = new int[size];
                    Timer timer;
                    GenerateData(arr, size, i);
                    Comparator<int> func;
                    timer.start();
                    sortFunc[algo](arr, size, func);
                    int64_t totalTime = timer.get();
                    cout << "Running time (if required): " << ((param==0 || param==2) ? to_string(totalTime):"") << endl;
                    cout << "Comparisons (if required): " << ((param==1 || param==2) ? to_string(func.count):"") << endl;
                    exportFile(arr, size, "input_"+to_string(i+1)+".txt");
                    delete [] arr;
                }
                return 3;
            }
            int size{};
            int* arr = getDataFromFile(argv[3], size);
            if (size == 0) {
                cout << "Error: input file has no data" << endl;
                return -1;
            }
            int algo = getAlgo(argv[2]);
            int param = getParam(argv[4]);
            if (algo == -1 || param == -1) {
                cout << "Error: invalid parameter(s)" << endl;
                return -1;
            }
            cout << "Algorithm: " << algoName[algo] << endl;
            cout << "Input file: " << argv[3] << endl;
            cout << "Input size: " << size << endl;
            Timer timer;
            Comparator<int> func;
            timer.start();
            sortFunc[algo](arr, size, func);
            int64_t totalTime = timer.get();
            cout << "-----------------------------" << endl;
            cout << "Running time (if required): " << ((param==0 || param==2) ? to_string(totalTime):"") << endl;
            cout << "Comparisons (if required): " << ((param==1 || param==2) ? to_string(func.count):"") << endl;
            exportFile(arr, size, "output.txt");
            delete [] arr;
            return 1;
        }
        else {
            cout << "Error: invalid parameter(s)" << endl;
        }
    }
    else if (strcmp(argv[1], "-c") == 0) {
        if (argc == 5) {
            int algo1 = getAlgo(argv[2]);
            int algo2 = getAlgo(argv[3]);
            int size{};
            int* arr1 = getDataFromFile(argv[4], size);
            int* arr2 = duplicateArray(arr1, size);
            if (size == 0) {
                cout << "Error: input file has no data" << endl;
                return -1;
            }
            if (algo1 == -1 || algo2 == -1) {
                cout << "Error: invalid parameter(s)" << endl;
                return -1;
            }
            cout << "Algorithm: " << algoName[algo1] << " | " << algoName[2] << endl;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input size: " << size << endl; 
            cout << "-----------------------------" << endl;
            Timer timer1, timer2;
            Comparator<int> func1, func2;
            timer1.start();
            sortFunc[algo1](arr1, size, func1);
            uint64_t time1 = timer1.get();
            timer2.start();
            sortFunc[algo2](arr2, size, func2);
            uint64_t time2 = timer2.get();
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisons: " << func1.count << " | " << func2.count << endl;
            return 4;
        }
        else if (argc == 6) {
            int algo1 = getAlgo(argv[2]);
            int algo2 = getAlgo(argv[3]);
            int size = stoi(argv[4]);
            int type = getType(argv[5]);
            if (algo1 == -1 || algo2 == -1 || size <= 0 || type == -1) {
                cout << "Error: invalid parameter(s)" << endl;
                return -1;
            }
            int* arr1 = new int[size];
            GenerateData(arr1, size, type);
            exportFile(arr1, size, "input.txt");
            int* arr2 = duplicateArray(arr1, size);
            cout << "Algorithm: " << algoName[algo1] << " | " << algoName[2] << endl;
            cout << "Input file: " << argv[4] << endl;
            cout << "Input order: " << typeName[type] << endl;
            cout << "-----------------------------" << endl;
            Timer timer1, timer2;
            Comparator<int> func1, func2;
            timer1.start();
            sortFunc[algo1](arr1, size, func1);
            uint64_t time1 = timer1.get();
            timer2.start();
            sortFunc[algo2](arr2, size, func2);
            uint64_t time2 = timer2.get();
            cout << "Running time: " << time1 << " | " << time2 << endl;
            cout << "Comparisons: " << func1.count << " | " << func2.count << endl;
            return 5;
        }
        else {
            cout << "Error: invalid parameter(s)" << endl;
        }
    }
    else {
        cout << "Error: invalid parameter(s)" << endl;
        return -1;
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
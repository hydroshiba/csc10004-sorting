#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "sort.hpp"
#include "utility.hpp"
#include "function.hpp"

void command1(int argc, char* argv[]) {
	// Command 1
	// main.exe -a [Algorithm] [Input file] [Output parameter]

	size_t size = toSize(argv[3]);

	if(sort::id[argv[2]] * param::id[argv[4]] == 0) {
		std::cout << "Invalid parameters" << std::endl;
		return;
	}

	int* arr = importFile(argv[3], size);
	if(arr == nullptr) {
		std::cout << "Invalid file" << std::endl;
		return;
	}

	std::cout << "Command 1" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl << std::endl;
	std::cout << "Input file: " << argv[3] << std::endl;
	std::cout << "Input size: " << size << std::endl;
	std::cout << "-----------------------------" << std::endl;

	measureSort(arr, size, sort::id[argv[2]], param::id[argv[4]]);
	exportFile("output.txt", arr, size);
	
	delete[] arr;
	return;
}

void command2(int argc, char* argv[]) {
	// Command 2
    // main.exe -a [Algorithm] [Input size] [Input order] [Output parameter]

	size_t size = toSize(argv[3]);
            
	if(sort::id[argv[2]] * size * order::id[argv[4]] * param::id[argv[5]] == 0) {
		std::cout << "Invalid parameters" << std::endl;
		return;
	}

	std::cout << "Command 2" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl << std::endl;
	std::cout << "Input size: " << size << std::endl;
	std::cout << "Input order: " << order::name[order::id[argv[4]]] << std::endl;
	std::cout << "-----------------------------" << std::endl;

	int* arr = new int[size]();
	GenerateData(arr, size, order::id[argv[4]] - 1);
	exportFile("input.txt", arr, size);

	measureSort(arr, size, sort::id[argv[2]], param::id[argv[5]]);
	exportFile("output.txt", arr, size);
	
	delete[] arr;
	return;
}

void command3(int argc, char* argv[]) {
	// Command 3
	// main.exe -a [Algorithm] [Input size] [Output parameter]

	size_t size = toSize(argv[3]);

	if(sort::id[argv[2]] * size * param::id[argv[4]] == 0) {
		std::cout << "Invalid parameters" << std::endl;
		return;
	}

	std::cout << "Command 3" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl << std::endl;
	std::cout << "Input size: " << size << std::endl;

	int* arr = new int[size]();

	for(int i = 1; i <= 4; ++i) {
		std::cout << "Input order: " << order::name[i] << std::endl;
		std::cout << "-----------------------------" << std::endl;

		GenerateData(arr, size, i - 1);
		exportFile("input_" +  std::to_string(i) + ".txt", arr, size);
		measureSort(arr, size, sort::id[argv[2]], param::id[argv[4]]);
	}

	delete[] arr;
	return;
}

void command4(int argc, char* argv[]) {
	// Command 4
	// main.exe -c [Algorithm 1] [Algorithm 2] [Input file]

	size_t size = 0;

	if(sort::id[argv[2]] * sort::id[argv[3]] == 0) {
		std::cout << "Invalid parameters" << std::endl;
		return;
	}

	int* arr = importFile(argv[4], size);
	if(arr == nullptr) {
		std::cout << "Invalid file" << std::endl;
		return;
	}

	std::cout << "Command 4" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << " | " << sort::name[sort::id[argv[3]]] << std::endl << std::endl;
	std::cout << "Input file: " << argv[4] << std::endl;
	std::cout << "Input size: " << size << std::endl;
	std::cout << "-----------------------------" << std::endl;

	compareSort(arr, size, sort::id[argv[2]], sort::id[argv[3]]);

	delete[] arr;
	return;
}

void command5(int argc, char* argv[]) {
	// Command 5
	// main.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

	size_t size = toSize(argv[4]);

	if(sort::id[argv[2]] * sort::id[argv[3]] * size * order::id[argv[5]] == 0) {
		std::cout << "Invalid parameters" << std::endl;
		return;
	}

	std::cout << "Command 5" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << " | " << sort::name[sort::id[argv[3]]] << std::endl << std::endl;
	std::cout << "Input size: " << size << std::endl;
	std::cout << "Input order: " << order::name[order::id[argv[5]]] << std::endl;
	std::cout << "-----------------------------" << std::endl;

	int* arr = new int[size];
	GenerateData(arr, size, order::id[argv[5]] - 1);
	exportFile("input.txt", arr, size);

	compareSort(arr, size, sort::id[argv[2]], sort::id[argv[3]]);

	delete[] arr;
	return;
}

void runAll() {
	size_t sizes[] = {10000, 30000, 50000, 100000, 300000, 500000};

	for(int sort = 12; sort > 0; --sort) {
		std::cout << "Running " << sort::name[sort] << std::endl << std::endl;

		for(int order = 1; order <= 4; ++order) {
			std::cout << "Input order: " << order::name[order] << std::endl;
			std::cout << "-----------------------------" << std::endl;

			std::string results;

			for(int i = 0; i < 6; ++i) {
				size_t size = sizes[i];
				std::cout << size << std::endl;

				int* arr = new int[size];
				GenerateData(arr, size, order - 1);
				results += measureSort(arr, size, sort, 3);
				
				delete[] arr;
			}

			saveResult(sort, order, results);
		}
	}
}

#endif
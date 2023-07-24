#include <iostream>
#include <iomanip>
#include <cstring>

#include "source/sort.hpp"
#include "source/utility.hpp"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Missing parameters" << std::endl;
        return 0;
    }

    if(strcmp(argv[1], "-a") == 0) {
        std::cout << "ALGORITHM MODE" << std::endl << std::endl;

        if(argc == 6) {
            // Command 2
            // main.exe -a [Algorithm] [Input size] [Input order] [Output parameter]
            
            size_t size = to_size(argv[3]);
            
            if(sort::id[argv[2]] * size * order::id[argv[4]] * param::id[argv[5]] == 0) {
                std::cout << "Invalid parameters" << std::endl;
                return 0;
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
            return 0;
        }
        
        if(argc == 5) {
            size_t size = to_size(argv[3]);

            if(size) {
                // Command 3
                // main.exe -a [Algorithm] [Input size] [Output parameter]

                if(sort::id[argv[2]] * size * param::id[argv[4]] == 0) {
                    std::cout << "Invalid parameters" << std::endl;
                    return 0;
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
                return 0;
            }

            else {
                // Command 1
                // main.exe -a [Algorithm] [Input file] [Output parameter]

                if(sort::id[argv[2]] * param::id[argv[4]] == 0) {
                    std::cout << "Invalid parameters" << std::endl;
                    return 0;
                }

                int* arr = importFile(argv[3], size);
                if(arr == nullptr) {
                    std::cout << "Invalid file" << std::endl;
                    return 0;
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
                return 0;
            }
        }

        std::cout << "Missing parameters" << std::endl;
        return 0;
    }
    else if (strcmp(argv[1], "-c") == 0) {
        std::cout << "COMPARISON MODE" << std::endl << std::endl;

        if(argc == 5) {
            // Command 4
            // main.exe -c [Algorithm 1] [Algorithm 2] [Input file]

            size_t size = 0;

            if(sort::id[argv[2]] * sort::id[argv[3]] == 0) {
                std::cout << "Invalid parameters" << std::endl;
                return 0;
            }

            int* arr = importFile(argv[4], size);
            if(arr == nullptr) {
                std::cout << "Invalid file" << std::endl;
                return 0;
            }

            std::cout << "Command 4" << std::endl;
            std::cout << "-----------------------------" << std::endl << std::endl;
            std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << " | " << sort::name[sort::id[argv[3]]] << std::endl << std::endl;
            std::cout << "Input file: " << argv[4] << std::endl;
            std::cout << "Input size: " << size << std::endl;
            std::cout << "-----------------------------" << std::endl;

            compareSort(arr, size, sort::id[argv[2]], sort::id[argv[3]]);

            delete[] arr;
            return 0;
        }
        
        if(argc == 6) {
            // Command 5
            // main.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

            size_t size = to_size(argv[4]);

            if(sort::id[argv[2]] * sort::id[argv[3]] * size * order::id[argv[5]] == 0) {
                std::cout << "Invalid parameters" << std::endl;
                return 0;
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
            return 0;
        }
        
        std::cout << "Missing parameters" << std::endl;
        return 0;
    }
    
    std::cout << "Invalid parameters" << std::endl;
    return 0;
}
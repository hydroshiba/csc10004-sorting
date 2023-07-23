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
        std::cout << "ALGORITHM MODE" << std::endl;

        if(argc == 6) {
            // Command 2
            // main.exe -a [Algorithm] [Input size] [Input order] [Output parameter]
            
            size_t size = to_size(argv[3]);
            
            if(sort::id[argv[2]] * size * order::id[argv[4]] * param::id[argv[5]] == 0) {
                std::cout << "Invalid parameters" << endl;
                return 0;
            }

            std::cout << "Command 2" << std::endl;
			std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl;
			std::cout << "Input size: " << size << std::endl;
			std::cout << "Input order: " << order::name[order::id[argv[4]]] << std::endl;
			std::cout << "-----------------------------" << std::endl;

			int* arr = new int[size]();
			GenerateData(arr, size, order::id[argv[4]] - 1);
            exportFile(arr, size, "input.txt");

            int param = param::id[argv[5]];
            uintmax_t runtime, comparison = 0;

            if(param > 1) {
                Counter<int> func;
                Counter<size_t> loop;
                
                int* dup = duplicateArray(arr, size);
                sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[2]]](dup, dup + size, func, loop);

                comparison = func.count + loop.count;
                delete[] dup;
            }

            if(param != 2) {
                Timer timer;
                timer.start();
                sort::func<int*>[sort::id[argv[2]]](arr, arr + size);
                runtime = std::max(uintmax_t(1), timer.get());
            }

			std::cout << "Running time: " << (runtime ? std::to_string(runtime) : "") << std::endl;
			std::cout << "Comparisons: " << (comparison ? std::to_string(comparison) : "") << std::endl;

            exportFile(arr, size, "output.txt");
            delete[] arr;

            return 0;
        }
        
        if(argc == 5) {
            size_t size = to_size(argv[3]);

            if(size) {
                // Command 3
                // main.exe -a [Algorithm] [Input size] [Output parameter]

                if(sort::id[argv[2]] * size * param::id[argv[4]] == 0) {
                    std::cout << "Invalid parameters" << endl;
                    return 0;
                }

                std::cout << "Command 3" << std::endl;
                std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl << std::endl;
			    std::cout << "Input size: " << size << std::endl;

                int* arr = new int[size]();

                for(int i = 1; i <= 4; ++i) {
                    std::cout << "Input order: " << order::name[i] << std::endl;
                    std::cout << "-----------------------------" << std::endl;

                    GenerateData(arr, size, i - 1);
                    exportFile(arr, size, "input_" +  std::to_string(i) + ".txt");

                    int param = param::id[argv[4]];
                    uintmax_t runtime, comparison = 0;

                    if(param > 1) {
                        Counter<int> func;
                        Counter<size_t> loop;
                        
                        int* dup = duplicateArray(arr, size);
                        sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[2]]](dup, dup + size, func, loop);

                        comparison = func.count + loop.count;
                        delete[] dup;
                    }

                    if(param != 2) {
                        Timer timer;
                        timer.start();
                        sort::func<int*>[sort::id[argv[2]]](arr, arr + size);
                        runtime = std::max(uintmax_t(1), timer.get());
                    }

                    std::cout << "Running time: " << (runtime ? std::to_string(runtime) : "") << std::endl;
                    std::cout << "Comparisons: " << (comparison ? std::to_string(comparison) : "") << std::endl;
                    std::cout << std::endl;
                }

                delete[] arr;
                return 0;
            }

            else {
                // Command 1
                // main.exe -a [Algorithm] [Input file] [Output parameter]

                if(sort::id[argv[2]] * param::id[argv[4]] == 0) {
                    std::cout << "Invalid parameters" << endl;
                    return 0;
                }

                int* arr = importFile(argv[3], size);
                if(arr == nullptr) {
                    std::cout << "Invalid file" << std::endl;
                    return 0;
                }

                std::cout << "Command 1" << std::endl;
                std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << std::endl;
                std::cout << "Input file: " << argv[3] << std::endl;
                std::cout << "Input size: " << size << std::endl;
                std::cout << "-----------------------------" << std::endl;

                int param = param::id[argv[4]];
                uintmax_t runtime, comparison = 0;

                if(param > 1) {
                    Counter<int> func;
                    Counter<size_t> loop;
                    
                    int* dup = duplicateArray(arr, size);
                    sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[2]]](dup, dup + size, func, loop);

                    comparison = func.count + loop.count;
                    delete[] dup;
                }

                if(param != 2) {
                    Timer timer;
                    timer.start();
                    sort::func<int*>[sort::id[argv[2]]](arr, arr + size);
                    runtime = std::max(uintmax_t(1), timer.get());
                }

                std::cout << "Running time: " << (runtime ? std::to_string(runtime) : "") << std::endl;
                std::cout << "Comparisons: " << (comparison ? std::to_string(comparison) : "") << std::endl;

                exportFile(arr, size, "output.txt");
                delete[] arr;

                return 0;
            }
        }

        std::cout << "Missing parameters" << std::endl;
        return 0;
    }
    else if (strcmp(argv[1], "-c") == 0) {
        std::cout << "COMPARISON MODE" << std::endl;

        if(argc == 5) {
            // Command 4
            // main.exe -c [Algorithm 1] [Algorithm 2] [Input file]

            size_t size = 0;

            if(sort::id[argv[2]] * sort::id[argv[3]] == 0) {
                std::cout << "Invalid parameters" << endl;
                return 0;
            }

            int* arr1 = importFile(argv[4], size);
            if(arr1 == nullptr) {
                std::cout << "Invalid file" << std::endl;
                return 0;
            }
            int* arr2 = duplicateArray(arr1, size);

            std::cout << "Command 4" << std::endl;
            std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << " | " << sort::name[sort::id[argv[3]]] << std::endl;
            std::cout << "Input file: " << argv[4] << std::endl;
            std::cout << "Input size: " << size << std::endl;
            std::cout << "-----------------------------" << std::endl;

            Counter<int> func1, func2;
            Counter<size_t> loop1, loop2;

            int* dup1 = duplicateArray(arr1, size);
            int* dup2 = duplicateArray(arr1, size);

            sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[2]]](dup1, dup1 + size, func1, loop1);
            sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[3]]](dup2, dup2 + size, func2, loop2);

            uintmax_t comparison1 = func1.count + loop1.count;
            uintmax_t comparison2 = func2.count + loop2.count;

            Timer timer1, timer2;
            uintmax_t runtime1, runtime2;

            timer1.start();
            sort::func<int*>[sort::id[argv[2]]](arr1, arr1 + size);
            runtime1 = std::max(uintmax_t(1), timer1.get());

            timer2.start();
            sort::func<int*>[sort::id[argv[3]]](arr2, arr2 + size);
            runtime2 = std::max(uintmax_t(1), timer2.get());

            std::cout << "Running time: " << runtime1 << " | " << runtime2 << std::endl;
            std::cout << "Comparisons: " << comparison1 << " | " << comparison2 << std::endl;

            delete[] arr1;
            delete[] arr2;

            delete[] dup1;
            delete[] dup2;

            return 0;
        }
        
        if(argc == 6) {
            // Command 5
            // main.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

            size_t size = to_size(argv[4]);

            if(sort::id[argv[2]] * sort::id[argv[3]] * size * order::id[argv[5]] == 0) {
                std::cout << "Invalid parameters" << endl;
                return 0;
            }

            std::cout << "Command 5" << std::endl;
            std::cout << "Algorithm: " << sort::name[sort::id[argv[2]]] << " | " << sort::name[sort::id[argv[3]]] << std::endl;
            std::cout << "Input size: " << size << std::endl;
            std::cout << "Input order: " << order::name[order::id[argv[5]]] << std::endl;
            std::cout << "-----------------------------" << std::endl;

            int* arr1 = new int[size];
            GenerateData(arr1, size, order::id[argv[5]] - 1);
            int* arr2 = duplicateArray(arr1, size);

            exportFile(arr1, size, "input.txt");

            Counter<int> func1, func2;
            Counter<size_t> loop1, loop2;

            int* dup1 = duplicateArray(arr1, size);
            int* dup2 = duplicateArray(arr1, size);

            sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[2]]](dup1, dup1 + size, func1, loop1);
            sort::count<int*, Counter<int>, Counter<size_t>>[sort::id[argv[3]]](dup2, dup2 + size, func2, loop2);

            uintmax_t comparison1 = func1.count + loop1.count;
            uintmax_t comparison2 = func2.count + loop2.count;

            Timer timer1, timer2;
            uintmax_t runtime1, runtime2;

            timer1.start();
            sort::func<int*>[sort::id[argv[2]]](arr1, arr1 + size);
            runtime1 = std::max(uintmax_t(1), timer1.get());

            timer2.start();
            sort::func<int*>[sort::id[argv[3]]](arr2, arr2 + size);
            runtime2 = std::max(uintmax_t(1), timer2.get());

            std::cout << "Running time: " << runtime1 << " | " << runtime2 << std::endl;
            std::cout << "Comparisons: " << comparison1 << " | " << comparison2 << std::endl;

            delete[] arr1;
            delete[] arr2;

            delete[] dup1;
            delete[] dup2;

            return 0;
        }
        
        std::cout << "Missing parameters" << std::endl;
        return 0;
    }
    
    std::cout << "Invalid" << std::endl;
    return 0;
}
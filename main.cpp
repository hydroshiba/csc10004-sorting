#include "source/command.hpp"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Missing parameters" << std::endl;
        return 0;
    }

    if(!strcmp(argv[1], "-a")) {
        std::cout << "ALGORITHM MODE" << std::endl << std::endl;

        if(argc == 6) command2(argc, argv);
        else if(argc == 5) {
            size_t size = toSize(argv[3]);

            if(size) command3(argc, argv);
            else command1(argc, argv);
        }
        else std::cout << "Missing parameters" << std::endl;

        return 0;
        
    }

    if(!strcmp(argv[1], "-c")) {
        std::cout << "COMPARISON MODE" << std::endl << std::endl;

        if(argc == 5) command4(argc, argv);
        else if(argc == 6) command5(argc, argv);
        else std::cout << "Missing parameters" << std::endl;
        
        return 0;
    }

    if(!strcmp(argv[1], "-all")) {
        std::cout << "EXPORT MODE" << std::endl << std::endl;
        runAll();
        return 0;
    }
    
    std::cout << "Invalid parameters" << std::endl;
}
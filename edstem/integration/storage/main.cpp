#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {

    std::ifstream file("edstem/integration/edstem-data/data.txt");

    // Later we will implement the rest of the code hre

    std::string line;

    while (std::getline(file, line)) {

        std::istringstream iss(line);

        std::string word;

        // implement check system so we are sorting depending on the first word
        // This line is for testing
        // std::cout << line << std::endl;

        // check line to see if the first characters are st or bhavl
        if (line.substr(0, 2) == "st") {
            // implement code to sort the data for student
            std::cout << "Splay Tree" << std::endl;
        } else if (line.substr(0, 5) == "bhavl") {
            // implement code to sort the data for bhavl
            std::cout << "Binary Heap / AVL tree" << std::endl;
        }
        
    }
    

    return 0;
}


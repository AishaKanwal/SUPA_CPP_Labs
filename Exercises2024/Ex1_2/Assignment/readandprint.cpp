// readandprint.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "readandprint.h"

void readAndPrintData(const std::string& filePath, int N) {
    std::ifstream inputFile(filePath);

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;

    // Read and print lines until we reach N or end of file
    while (lineCount < N && std::getline(inputFile, line)) {
        std::cout << line << std::endl;
        lineCount++;
    }

    inputFile.close();

    // If fewer than N lines were read, notify the user
    if (lineCount < N) {
        std::cout << "The file contains fewer than " << N << " lines." << std::endl;
    }
}

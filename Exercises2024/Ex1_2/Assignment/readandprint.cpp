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
    int totalLines = 0;

    // Count total lines in the file
    while (std::getline(inputFile, line)) {
        totalLines++;
    }

    // Reset the file pointer to the beginning
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    // If N is larger than total lines, give a warning and set N to 5
    if (N > totalLines) {
        std::cout << "Warning: The file contains fewer than " << N << " lines." << std::endl;
        std::cout << "Displaying the first 5 lines instead:" << std::endl;
        N = std::min(5, totalLines);
    }

    // Read and print lines up to N
    while (lineCount < N && std::getline(inputFile, line)) {
        std::cout << line << std::endl;
        lineCount++;
    }

    inputFile.close();
}

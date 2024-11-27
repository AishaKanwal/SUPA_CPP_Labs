// readMystery

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "readmystery.h"

std::vector<double> readMystery(const std::string& filePath, int N) {
    std::vector<double> data;
    std::ifstream inputFile(filePath);

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return data; // Return an empty vector if the file can't be opened
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

    // Read and store the lines into the data vector
    double value;
    while (lineCount < N && std::getline(inputFile, line)) {
        try {
            value = std::stod(line);  // Convert the line to a double
            data.push_back(value);    // Store the value in the vector
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid data in line: " << line << std::endl;
        }
        lineCount++;
    }

    inputFile.close();
    return data; // Return the filled vector
}

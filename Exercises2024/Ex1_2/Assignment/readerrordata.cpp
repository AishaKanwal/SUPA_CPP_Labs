#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "readerrordata.h"

std::vector<double> ReadErrorData(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    std::vector<double> errors;
    std::string line;

    if (!inputFile) {
        std::cerr << "Error: Could not open the error file!" << std::endl;
        return errors;
    }

    // Skip the header
    std::getline(inputFile, line);

    // Read the error data
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        double error;
        if (ss >> error) {
            errors.push_back(error);
        } else {
            std::cerr << "Error: Invalid data format in line: " << line << std::endl;
        }
    }

    inputFile.close();
    return errors;
}

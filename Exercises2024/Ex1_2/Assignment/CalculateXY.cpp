// CalculateXY.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include "CalculateXY.h"


void CalculateXY(const std::string& filePath) {
    // Open file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    // Store data (x, y pairs)
    std::vector<std::pair<double, double>> data;
    std::string line;
    
    // Skip header
    std::getline(inputFile, line);
    
    // Read the data points
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        double x, y;
        char comma;
        if (ss >> x >> comma >> y) {
            data.push_back({x, y});
        } else {
            std::cerr << "Error: Invalid data format in line: " << line << std::endl;
        }
    }

    // If no data points are available
    if (data.empty()) {
        std::cerr << "Error: No data points to process!" << std::endl;
        return;
    }

    // Vector to store x^y values
    std::vector<double> xy_values(data.size());

    // Use std::transform to calculate x^y for each data point
    std::transform(data.begin(), data.end(), xy_values.begin(), [](const std::pair<double, double>& p) {
        return std::pow(p.first, p.second); // Calculate x^y for each pair
    });

    //open output file
    std::ofstream outputFile("CalculateXY_output.txt");

    //check if the output file is opened successfully
    if (!outputFile) {
        std::cerr <<"Error: Could not open output file!" <<std::endl;
        return;
    }

    // Output the x^y values // we can use L"x\u0B8" for x power y with wcout cmd
    std::cout << "Calculated x^y for each data point:" << std::endl;
    for (const auto& value : xy_values) {
        std::cout << value << std::endl;
    }

    outputFile.close();
}

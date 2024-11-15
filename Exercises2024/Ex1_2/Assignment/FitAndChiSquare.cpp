#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "FitAndChiSquare.h"

void FitLineAndChiSquare(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    std::vector<std::pair<double, double>> data; // To store (x, y) pairs
    std::string line;
    // Skip the header
    std::getline(inputFile, line);

    // Read the data
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

    // If no data points are found, exit
    if (data.empty()) {
        std::cerr << "Error: No data points to process!" << std::endl;
        return;
    }

    // Perform the least squares fitting
    double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;
    int N = data.size();
    
    for (const auto& pair : data) {
        sum_x += pair.first;
        sum_y += pair.second;
        sum_xx += pair.first * pair.first;
        sum_xy += pair.first * pair.second;
    }

    double p = (N * sum_xy - sum_x * sum_y) / (N * sum_xx - sum_x * sum_x);
    double q = (sum_y * sum_xx - sum_x * sum_xy) / (N * sum_xx - sum_x * sum_x);

    // Open the output file
    std::ofstream outputFile("FitAndChiSquare_output.txt");

    // Check if the file was opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not open output file!" << std::endl;
        return;
    }

    // Write the line of best fit and chi-squared to the file
    outputFile << "Line of best fit: y = " << p << "x + " << q << std::endl;

    // Perform the chi-squared test (simplified version)
    double chi_squared = 0;
    for (const auto& pair : data) {
        double expected_y = p * pair.first + q;
        chi_squared += std::pow(pair.second - expected_y, 2) / expected_y;
    }

    // Output the chi-squared value
    outputFile << "Chi-squared: " << chi_squared << std::endl;

    outputFile.close();  // Close the output file
}

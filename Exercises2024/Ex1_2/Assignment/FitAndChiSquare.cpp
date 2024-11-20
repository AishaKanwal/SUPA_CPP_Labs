#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "FitAndChiSquare.h"

void FitLineAndChiSquare(const std::string& filePath, const std::vector<double>& errors) {
    // Read the data file
    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error: Could not open the data file!" << std::endl;
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

    // Ensure the error vector size matches the data size
    if (errors.size() != data.size()) {
        std::cerr << "Error: The number of error values does not match the number of data points!" << std::endl;
        return;
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

    // calculating slope
    double p = (N * sum_xy - sum_x * sum_y) / (N * sum_xx - sum_x * sum_x);
    double q = (sum_y * sum_xx - sum_x * sum_xy) / (N * sum_xx - sum_x * sum_x);

    // Open the output file
    std::ofstream outputFile("FitAndChiSquare_output.txt");

    // Check if the file was opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not open output file!" << std::endl;
        return;
    }

    // Write the line of best fit to the file
    outputFile << "Line of best fit: y = " << p << "x + " << q << std::endl;

    // Perform the chi-squared test (using the error data)
    double chi_squared = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        double expected_y = p * data[i].first + q;
        double error = errors[i];
        chi_squared += std::pow((data[i].second - expected_y) / error, 2);
    }

    // Compute NDF (Number of Degrees of Freedom)
    int NDF = N - 2; // Two parameters (slope and intercept) for a linear fit

    // Calculate Chi-Squared / NDF
    double chi_squared_per_ndf = chi_squared/NDF;

    // Display the results on the terminal
    std::cout << "Line of best fit: y = " << p << "x + " << q << std::endl;
    std::cout << "Chi-squared: " << chi_squared << std::endl;
    std::cout << "Degrees of Freedom (NDF): " << NDF << std::endl;
    std::cout << "Chi-squared/NDF: " << chi_squared_per_ndf << std::endl;

    // Output the chi-squared value and NDF and Chi-squared/NDF
    outputFile << "Chi-squared: " << chi_squared << std::endl;
    outputFile << "Degrees of Freedom (NDF): " << NDF << std::endl;
    outputFile << "Chi-Squared per NDF: " << chi_squared_per_ndf <<std::endl;

    outputFile.close();  // Close the output file
}

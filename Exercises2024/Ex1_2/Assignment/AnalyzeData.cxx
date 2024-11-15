// AnalyzeData.cxx

#include <iostream>
#include <string>
#include "readandprint.h"
#include "CalculateMagnitude.h"
#include "FitAndChiSquare.h"
#include "CalculateXY.h"

int main() {
    // Path to the file
    std::string filePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex1_2/input2D_float.txt";
    
    // Number of lines to print
    int N = 5; // Change this to the number of lines you want to print

    // Calling readAndPrintData function to print first N lines
    readAndPrintData(filePath, N);

    // Calling CalculateMagnitude function to calculate magnitudes for each row in the file
    CalculateMagnitude(filePath);

    // Debug: Print data before fitting the line
    std::cout << "\nAttempting to fit a line to the data...\n";

    // Calling FitLineAndChiSquare function to fit a line and calculate Chi-squared
    try {
        FitLineAndChiSquare(filePath);  // Calling the function
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Output error message to standard error stream
    }

    // calling calculatexy function to calculate x power y 
    CalculateXY(filePath);

    return 0;
}


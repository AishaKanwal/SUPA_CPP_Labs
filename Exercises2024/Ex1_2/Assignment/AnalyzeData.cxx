// AnalyzeData.cxx

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "readandprint.h"
#include "readerrordata.h"
#include "CalculateMagnitude.h"
#include "FitAndChiSquare.h"
#include "CalculateXY.h"

int main() {
    // File paths
    std::string inputFilePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex1_2/input2D_float.txt";
    std::string errorFilePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex1_2/error2D_float.txt";

    bool continueProgram = true;

    while (continueProgram) {
        // Display the menu
        std::cout << "\nChoose an operation to perform:\n";
        std::cout << "1. Read and print data from the file.\n";
        std::cout << "2. Calculate magnitudes of the data.\n";
        std::cout << "3. Fit a line to the data and calculate Chi-squared.\n";
        std::cout << "4. Calculate x^y (x raised to y) for each data point.\n";
        std::cout << "5. Exit the program.\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int N;
            std::cout << "Enter the number of lines to print: ";
            std::cin >> N;
            readAndPrintData(inputFilePath, N);
            break;
        }
        case 2:
            CalculateMagnitude(inputFilePath);
            break;
        case 3: {
            // Read error data
            std::vector<double> errors = ReadErrorData(errorFilePath);
            if (errors.empty()) {
                std::cerr << "Error: Failed to read the error data from " << errorFilePath << "!\n";
                break;
            }
            try {
                FitLineAndChiSquare(inputFilePath, errors);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << '\n';
            }
            break;
        }
        case 4:
            CalculateXY(inputFilePath);
            break;
        case 5:
            std::cout << "Exiting the program. Goodbye!\n";
            continueProgram = false;
            break;
        default:
            std::cerr << "Invalid choice. Please try again.\n";
        }

        if (continueProgram) {
            // Ask if the user wants to perform another operation
            char repeat;
            std::cout << "\nDo you want to perform another operation? (y/n): ";
            std::cin >> repeat;
            if (repeat == 'n' || repeat == 'N') {
                continueProgram = false;
                std::cout << "Exiting the program. Goodbye!\n";
            }
        }
    }

    return 0;
}

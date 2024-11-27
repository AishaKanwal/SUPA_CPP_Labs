#include <iostream>
#include <vector>
#include "FiniteFunctions.h"
#include "readmystery.h"  // Include the header for the readData function

int main() {
    // Test 1: Default Constructor
    std::cout << "Test 1: Default Constructor" << std::endl;
    FiniteFunction defaultFunc;
    defaultFunc.printInfo();

    // Test 2: Reading data from MysteryData13112.txt
    std::cout << "Test 2: Read Data from MysteryData13112.txt" << std::endl;
    std::string filePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex3_4/Outputs/data/MysteryData13112.txt";
    int N = 5;  // Read the first 10 data points
    std::vector<double> data = readMystery(filePath, N);  // Read the data into a vector

    std::cout << "Read data: ";
    for (double x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Test 3: Using the data with FiniteFunction
    std::cout << "Test 3: Function Evaluation on MysteryData" << std::endl;
    FiniteFunction evalFunc(-10.0, 10.0, "MysteryFunction");

    // Iterate through the data and evaluate the function
    for (double x : data) {
        double fx = evalFunc.callFunction(x);
        std::cout << "Function value at x = " << x << " is " << fx << std::endl;
    }

    // Test 4: Plot the function with the read data
    std::cout << "Test 4: Plotting Function with Read Data" << std::endl;
    evalFunc.plotFunction();  // This will plot the function if the class supports it

    // Test 5: Calculate the integral of the function
    std::cout << "Test 5: Calculate Integral" << std::endl;
    int Ndiv = 1000; // Set number of divisions for integration
    double integralValue = evalFunc.integral(Ndiv);  // Assuming integral() is implemented in FiniteFunction
    std::cout << "Integral of the function: " << integralValue << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include "FiniteFunctions.h"
#include "readmystery.h"  // Include the header for the readData function
#include "CustomFunctions.h" //Include the header for Normal, Cauchy-Lorentz, and Negative Crystal Ball Distribution 

int main() {
    try {

    // Test 1: Default Constructor
    std::cout << "Test 1: Default Constructor" << std::endl;
    FiniteFunction defaultFunc;
    defaultFunc.printInfo();

    // Test 2: Reading data from MysteryData13112.txt
    std::cout << "Test 2: Read Data from MysteryData13112.txt" << std::endl;
    std::string filePath = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex3_4/Outputs/data/MysteryData13112.txt";
    int N = 5;  // Read the first 5 data points
    std::vector<double> data = readMystery(filePath, N);  // Read the data into a vector

    std::cout << "Read data: ";
    for (double x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Test 3: Using the data with FiniteFunction
    std::cout << "Test 3: Function Evaluation on MysteryData" << std::endl;
    FiniteFunction evalFunc(-4.0, 4.0, "MysteryFunction");

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

    // ============================= Testing Normal Distribution =============================
    
    // ============================= Sample Data =============================
    std::cout << "\nTesting Normal Distribution on sample data:" << std::endl;
    NormalDistribution normal(-4.0, 4.0, 0.0, 1.0, "NormalDistribution");
    normal.printInfo(); // Print details about the distribution
    double integralNormal = normal.integral(1000); // Calculate integral using 1000 divisions
    std::cout << "\nIntegral of Normal Distribution: " << integralNormal << std::endl;
    normal.plotFunction(); // Generate plot

    // ============================= Mystery Data =============================
    std::cout<< "\nEvaluating Normal Distribution on Mystery data:" <<std::endl;
    for (double x : data) {
            double fx = normal.callFunction(x);
            std::cout << "f(" << x << ") = " << fx << std::endl;
            normal.plotData(data, 20);
        }

    // ========================== Testing Cauchy-Lorentz Distribution ==========================

    // ============================= Sample Data =============================
    std::cout << "\nTesting Cauchy-Lorentz Distribution on sample data" << std::endl;
    CauchyLorentzDistribution cauchy(-4.0, 4.0, 0.0, 1.0, "CauchyLorentzDistribution");
    cauchy.printInfo(); // Print details
    double integralCauchy = cauchy.integral(1000);
    std::cout << "\nIntegral of Cauchy-Lorentz Distribution: " << integralCauchy << std::endl;
    cauchy.plotFunction();

    // ============================= Mystery Data =============================
    std::cout<< "\nEvaluating Cauchy-Lorentz Distribution on Mystery data:" <<std::endl;
    for (double x : data) {
            double fx = cauchy.callFunction(x);
            std::cout << "f(" << x << ") = " << fx << std::endl;
            cauchy.plotData(data, 20);
        }
    
    // ======================= Testing Negative Crystal Ball Distribution =======================

    // ============================= Sample Data =============================
    std::cout << "\nTesting Negative Crystal Ball Distribution on sample data" << std::endl;
    NegativeCrystalBallDistribution crystal(-4.0, 4.0, 1.0, 0.0, 1.5, 2.0, "NegativeCrystalBall");
    crystal.printInfo();
    double integralCrystal = crystal.integral(1000);
    std::cout << "\nIntegral of Negative Crystal Ball Distribution: " << integralCrystal << std::endl;
    crystal.plotFunction();

    // ============================= Mystery Data =============================
    std::cout<< "\nEvaluating Negative Crystal Ball Distribution on Mystery data:" <<std::endl;
    for (double x : data) {
            double fx = crystal.callFunction(x);
            std::cout << "f(" << x << ") = " << fx << std::endl;
            crystal.plotData(data, 20);
        }

} catch (const std::exception& e) {
    std::cerr << "An error occurred: " << e.what() << std::endl;
}

    return 0;
}

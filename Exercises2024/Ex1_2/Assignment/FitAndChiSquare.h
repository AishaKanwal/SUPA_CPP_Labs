// FitAndChiSquare.h

#ifndef FITANDCHISQUARE_H
#define FITANDCHISQUARE_H

#include <vector>
#include <string>

// Function to perform Least Squares Fit and calculate Chi-squared
void FitLineAndChiSquare(const std::string& filePath, const std::vector<double>& errors);

#endif
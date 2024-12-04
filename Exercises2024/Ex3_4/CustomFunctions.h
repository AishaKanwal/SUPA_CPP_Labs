#ifndef CUSTOM_FUNCTIONS_H
#define CUSTOM_FUNCTIONS_H

#include "FiniteFunctions.h"
#include <cmath> // For math functions like exp, sqrt, etc.

class NormalDistribution : public FiniteFunction {
public:
    NormalDistribution(double range_min, double range_max, double mu, double sigma, std::string outfile);
    double callFunction(double x) override;

private:
    double m_mu; //Mean
    double m_sigma; //Std dev
};

class CauchyLorentzDistribution : public FiniteFunction {
public:
    CauchyLorentzDistribution(double range_min, double range_max, double x0, double gamma, std::string outfile);
    double callFunction(double x) override;

private:
    double m_x0; //Location parameter
    double m_gamma; //scale parameter
};

class NegativeCrystalBallDistribution : public FiniteFunction {
public:
    NegativeCrystalBallDistribution(double range_min, double range_max, double sigma, double x_bar, double alpha, double n, std::string outfile);
    double callFunction(double x) override;

private:
    double m_sigma; //std dev
    double m_x_bar; //mean (center of distribution)
    double m_alpha; //slope parameter
    double m_n; //Exponent
    double m_A; //const A
    double m_B; //const B
    double m_N; //normalization const

    void calculateConstants();
};

#endif // CUSTOM_FUNCTIONS_H

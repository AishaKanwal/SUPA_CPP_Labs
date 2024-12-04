#include "CustomFunctions.h"

// ============================= Normal Distribution =============================
NormalDistribution::NormalDistribution(double range_min, double range_max, double mu, double sigma, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_mu(mu), m_sigma(sigma) {}

double NormalDistribution::callFunction(double x) {
    return (1.0 / (m_sigma * std::sqrt(2 * M_PI))) * std::exp(-0.5 * std::pow((x - m_mu) / m_sigma, 2));
}

// ========================== Cauchy-Lorentz Distribution =========================
CauchyLorentzDistribution::CauchyLorentzDistribution(double range_min, double range_max, double x0, double gamma, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_x0(x0), m_gamma(gamma) {}

double CauchyLorentzDistribution::callFunction(double x) {
    return (1.0 / (M_PI * m_gamma)) * (1.0 / (1.0 + std::pow((x - m_x0) / m_gamma, 2)));
}

// ===================== Negative Crystal Ball Distribution =======================
NegativeCrystalBallDistribution::NegativeCrystalBallDistribution(double range_min, double range_max, double sigma, double x_bar, double alpha, double n, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_sigma(sigma), m_x_bar(x_bar), m_alpha(alpha), m_n(n) {
    calculateConstants();
}

void NegativeCrystalBallDistribution::calculateConstants() {
    if(m_alpha <=0 || m_n <=1 || m_sigma <=0) {
        throw std::invalid_argument("Invalid parameters: alpha>0, n>1, and sigma>0 required.");
    }

    //calculate the constants for distribution
    m_A = std::pow(m_n / std::abs(m_alpha), m_n) * std::exp(-0.5 * std::pow(std::abs(m_alpha), 2));
    m_B = m_n / std::abs(m_alpha) - std::abs(m_alpha);

    // intermediate constants
    double C = (m_n / std::abs(m_alpha)) * (1.0 / (m_n - 1)) * std::exp(-0.5 * std::pow(std::abs(m_alpha), 2));
    double D = std::sqrt(M_PI / 2.0) * (1 + std::erf(std::abs(m_alpha) / std::sqrt(2.0)));

    //normalization constact
    m_N = 1.0 / (m_sigma *(C + D));

}

double NegativeCrystalBallDistribution::callFunction(double x) {
    double t = (x - m_x_bar) / m_sigma; // normalized variable
    if (t > -m_alpha) {
        // Branch 1
        return m_N * std::exp(-0.5 * t * t);
    } else {
        // Branch 2
        return m_N * m_A * std::pow(m_B - t, -m_n);
    }
}

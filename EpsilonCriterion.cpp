#include <cmath>
#include "EpsilonCriterion.h"

EpsilonCriterion::EpsilonCriterion(int _n, double _eps): n(_n), eps(_eps) {
}

bool EpsilonCriterion::is_converged(std::vector<double> function) {
    double fsum = 0;
    for (int i = 0; i <= n; ++i) {
        fsum += function[i];
    }
    double favg = fsum / (n + 1);
    double s = 0.0;
    for (int i = 0; i <= n; ++i) {
        s += std::pow((function[i] - favg), 2.0) / (n);
    }
    s = std::sqrt(s);
    return s < eps;
}

bool EpsilonCriterion::is_converged(int dim, double eps, std::vector<double> previous_approximation, std::vector<double> new_approximation) {
    return false;
}

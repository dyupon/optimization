#include <cmath>
#include "EpsilonCriterion.h"

EpsilonCriterion::EpsilonCriterion(int _n, double _eps): n(_n), eps(_eps) {
}

bool EpsilonCriterion::is_converged(const std::vector<double> &function) const {
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

bool EpsilonCriterion::is_converged(size_t dim,
                                    double eps,
                                    const std::vector<double> &previous_approximation,
                                    const std::vector<double> &new_approximation) const {
    return false;
}

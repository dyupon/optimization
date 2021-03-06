#include <cmath>
#include "SpecialNMCriterion.h"

SpecialNMCriterion::SpecialNMCriterion(double _eps) : AbstractCriterion(_eps) {

}

bool SpecialNMCriterion::isConverged(const std::vector<double> &function, double dim) const {
    double fsum = 0;
    for (int i = 0; i <= dim; ++i) {
        fsum += function[i];
    }
    double favg = fsum / (dim + 1);
    double s = 0.0;
    for (int i = 0; i <= dim; ++i) {
        s += std::pow((function[i] - favg), 2.0) / dim;
    }
    s = std::sqrt(s);
    return s < eps;
}

bool SpecialNMCriterion::isConverged(size_t dim,
                                     const std::vector<double> &previousApproximation,
                                     const std::vector<double> &newApproximation) const {
    return false;
}

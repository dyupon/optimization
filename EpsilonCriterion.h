#ifndef NELDERMID_EPSILONCRITERION_H
#define NELDERMID_EPSILONCRITERION_H


#include "AbstractCriterion.h"

class EpsilonCriterion : public AbstractCriterion {
    const int n;
    const double eps;
public:
    EpsilonCriterion(int _n, double _eps);

    bool isConverged(const std::vector<double> &function) const override;

    bool isConverged(size_t dim,
                     double eps,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation) const override;
};


#endif //NELDERMID_EPSILONCRITERION_H

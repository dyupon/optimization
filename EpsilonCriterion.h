#ifndef NELDERMID_EPSILONCRITERION_H
#define NELDERMID_EPSILONCRITERION_H


#include "AbstractCriterion.h"

class EpsilonCriterion : public AbstractCriterion {
    const int n;
    const double eps;
public:
    EpsilonCriterion(int _n, double _eps);

    bool is_converged(const std::vector<double> &function) const override;

    bool is_converged(size_t dim,
                      double eps,
                      const std::vector<double> &previous_approximation,
                      const std::vector<double> &new_approximation) const override;
};


#endif //NELDERMID_EPSILONCRITERION_H

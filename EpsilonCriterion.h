#ifndef NELDERMID_EPSILONCRITERION_H
#define NELDERMID_EPSILONCRITERION_H


#include "AbstractCriterion.h"

class EpsilonCriterion : public AbstractCriterion {
    const int n;
    const double eps;
public:
    EpsilonCriterion(int _n, double _eps);
    bool is_converged(std::vector<double> function) override;
    bool is_converged(int dim, double eps, std::vector<double> previous_approximation, std::vector<double> new_approximation) override;
};


#endif //NELDERMID_EPSILONCRITERION_H

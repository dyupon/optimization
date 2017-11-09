/** \brief Inherits from AbstractCriterion class to implement eps-based stopping criterion for Nelder-Mead optimization  **/

#ifndef NELDERMID_EPSILONCRITERION_H
#define NELDERMID_EPSILONCRITERION_H


#include "AbstractCriterion.h"

class SpecialNMCriterion : public AbstractCriterion {
public:
    explicit SpecialNMCriterion(double _eps);

    bool isConverged(const std::vector<double> &function, double dim) const override;

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation) const override;

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation,
                     FunctionImplementation *function) const override {
        return false;
    }
};


#endif //NELDERMID_EPSILONCRITERION_H

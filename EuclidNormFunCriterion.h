//
// Created by User on 11/9/2017.
//

#ifndef NELDERMID_EUCLIDNORMARGCRITERION_H
#define NELDERMID_EUCLIDNORMARGCRITERION_H


#include "AbstractCriterion.h"

class EuclidNormFunCriterion : public AbstractCriterion {
public:
    explicit EuclidNormFunCriterion(double _eps);

    bool isConverged(const std::vector<double> &function, double dim) const override;

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation,
                     FunctionImplementation *function) const override;

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation) const override {
        return false;
    }
};


#endif //NELDERMID_EUCLIDNORMARGCRITERION_H

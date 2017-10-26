//
// Created by User on 10/12/2017.
//

#ifndef NELDERMID_EUCLIDNORMCRITERIA_H
#define NELDERMID_EUCLIDNORMCRITERIA_H


#include "AbstractCriterion.h"

class EuclidNormCriterion: public AbstractCriterion {
public:
    EuclidNormCriterion();

    bool isConverged(const std::vector<double> &function) const override;

    bool isConverged(size_t dim,
                     double eps,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation) const override;
private:
    const int MAX_ITER_COUNT = 50000;
    mutable int iterCount;
};


#endif //NELDERMID_EUCLIDNORMCRITERIA_H

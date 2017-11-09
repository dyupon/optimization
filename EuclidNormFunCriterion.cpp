//
// Created by User on 11/9/2017.
//

#include <cmath>
#include "EuclidNormFunCriterion.h"

EuclidNormFunCriterion::EuclidNormFunCriterion(double _eps) : AbstractCriterion(_eps) {

}

bool EuclidNormFunCriterion::isConverged(const std::vector<double> &function, double dim) const {
    return false;
}

bool EuclidNormFunCriterion::isConverged(size_t dim, const std::vector<double> &previousApproximation,
                                         const std::vector<double> &newApproximation,
                                         FunctionImplementation *function) const {
    ++iterCount;
    double sum = 0;
    for (int i = 0; i < dim; ++i) {
        double difference =
                function->getFunctionValue(newApproximation) - function->getFunctionValue(previousApproximation);
        sum += difference * difference;
    }
    return (std::sqrt(sum) < eps) || (iterCount > MAX_ITER_COUNT);
}

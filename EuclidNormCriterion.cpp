
#include "EuclidNormCriterion.h"
#include <cmath>

bool EuclidNormCriterion::isConverged(size_t dim,
                                      const std::vector<double> &previousApproximation,
                                      const std::vector<double> &newApproximation) const {
    ++iterCount;
    double sum = 0;
    for (int i = 0; i < dim; ++i) {
        double difference = newApproximation[i] - previousApproximation[i];
        sum += difference * difference;
    }
    return (std::sqrt(sum) < eps) || (iterCount > MAX_ITER_COUNT);
}

EuclidNormCriterion::EuclidNormCriterion(double _eps) : AbstractCriterion(_eps) {

}

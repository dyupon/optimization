
#include "EuclidNormCriterion.h"
#include <cmath>

bool EuclidNormCriterion::is_converged(std::vector<double> function) const {
    return false;
}

bool EuclidNormCriterion::is_converged(int dim,
                                       double eps,
                                       std::vector<double> previous_approximation,
                                       std::vector<double> new_approximation) const {
    ++iter_count;
    double sum = 0;
    for (int i = 0; i < dim; ++i) {
        double difference = new_approximation[i] - previous_approximation[i];
        sum += difference * difference;
    }
    return (std::sqrt(sum) < eps) || (iter_count > MAX_ITER_COUNT);
}

EuclidNormCriterion::EuclidNormCriterion() {
    iter_count = 0;
}

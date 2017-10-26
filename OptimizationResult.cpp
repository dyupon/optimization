#include "OptimizationResult.h"

OptimizationResult::OptimizationResult(int _iterCount,
                                       int _functionEvaluationsCount,
                                       const std::vector<double> &_minimumPoint) :
        iterCount(_iterCount),
        functionEvaluationsCount(_functionEvaluationsCount),
        minimumPoint(_minimumPoint) {
}

const std::vector<double> &OptimizationResult::getExtrPoint() const {
    return minimumPoint;
}

int OptimizationResult::getFuncEvaluationCount() const {
    return functionEvaluationsCount;
}

int OptimizationResult::getIterCount() const {
    return iterCount;
}

//
// Created by User on 10/23/2017.
//

#ifndef NELDERMID_OPTIMIZATIONRESULT_H
#define NELDERMID_OPTIMIZATIONRESULT_H


#include <vector>

class OptimizationResult {
public:
    OptimizationResult(int _iterCount, int _functionEvaluationsCount, const std::vector<double> &_minimumPoint);

    int getIterCount() const;

    int getFuncEvaluationCount() const;

    const std::vector<double> &getExtrPoint() const;
private:
    const int iterCount;
    const int functionEvaluationsCount;
    const std::vector<double> minimumPoint;
};


#endif //NELDERMID_OPTIMIZATIONRESULT_H

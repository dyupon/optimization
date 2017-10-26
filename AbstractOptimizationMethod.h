#ifndef NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H
#define NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

#include <vector>
#include "AbstractCriterion.h"
#include "AbstractArea.h"
#include "Function.h"
#include "OptimizationResult.h"

class AbstractOptimizationMethod {
public:
    virtual OptimizationResult optimize(
            const std::vector<double> &initialApproximation,
            const AbstractCriterion &criteria,
            const Function &function
    ) = 0;
};

#endif //NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

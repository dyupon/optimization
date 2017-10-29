/** \brief Abstract base class for optimization method **/

#ifndef NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H
#define NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

#include <vector>
#include "AbstractCriterion.h"
#include "AbstractArea.h"
#include "Function.h"
#include "OptimizationResult.h"
#include "FunctionImplementation.h"


class AbstractOptimizationMethod {
public:
    virtual OptimizationResult optimize(
            const std::vector<double> &initialApproximation,
            const AbstractCriterion &criterion,
            FunctionImplementation *function
    ) = 0; /** Main method for running optimization for function starting from initialApproximation and finishing when convergence criterion is reached **/
};

#endif //NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

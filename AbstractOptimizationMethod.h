#ifndef NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H
#define NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

#include <vector>
#include "AbstractCriterion.h"
#include "AbstractArea.h"
#include "Function.h"

class AbstractOptimizationMethod {
public:
    virtual void optimize(std::vector<double> &initial_approximation, AbstractCriterion &criteria, Function &function) = 0;
protected:
    std::vector<double> function_values;
    int function_evaluations_count = 0;
};


#endif //NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

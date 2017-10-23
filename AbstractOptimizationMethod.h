#ifndef NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H
#define NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

#include <vector>
#include "AbstractCriterion.h"
#include "AbstractArea.h"
#include "Function.h"

class AbstractOptimizationMethod {
public:
    virtual std::vector<double> optimize(std::vector<double> const& initial_approximation, AbstractCriterion const& criteria, Function const& function) = 0;
protected:
    std::vector<double> function_values;
    int function_evaluations_count = 0;
};


#endif //NELDERMID_ABSTRACTOPTIMIZATIONMETHOD_H

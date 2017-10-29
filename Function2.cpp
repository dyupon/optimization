#include "Function2.h"

double Function2::getFunctionValue(const std::vector<double> &x) const {
    return (1.5 - x[0] + x[0] * x[1]) * (1.5 - x[0] + x[0] * x[1]) +
           (2.25 - x[0] + x[0] * x[1] * x[1]) * (2.25 - x[0] + x[0] * x[1] * x[1]) +
           (2.625 - x[0] + x[0] * x[1] * x[1] * x[1]) * (2.625 - x[0] + x[0] * x[1] * x[1] * x[1]);
}

Function2::Function2(int _dim, const std::vector<double> &upper, const std::vector<double> &lower)
        : FunctionImplementation(_dim, upper, lower) {
}


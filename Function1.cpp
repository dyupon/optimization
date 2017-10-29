#include "Function1.h"

double Function1::getFunctionValue(const std::vector<double> &x) const {
    return 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]) + (1.0 - x[0]) * (1.0 - x[0]) + (1 - x[2]) * (1 - x[2]);
}

Function1::Function1(int _dim, const std::vector<double> &upper, const std::vector<double> &lower)
        : FunctionImplementation(_dim, upper, lower) {
}



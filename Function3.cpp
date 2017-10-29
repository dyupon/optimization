#include "Function3.h"

double Function3::getFunctionValue(const std::vector<double> &x) const {
    return (0.26 * (x[0] * x[0] + x[1] * x[1]) - 0.48 * x[0] * x[1]);
}

Function3::Function3(int _dim, const std::vector<double> &upper, const std::vector<double> &lower)
        : FunctionImplementation(_dim, upper, lower) {

}

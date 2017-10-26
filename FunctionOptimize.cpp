#include "FunctionOptimize.h"

double FunctionOptimize::getFunctionValue(const std::vector<double> &x) const {
    return 100*(x[1]-x[0]*x[0])*(x[1]-x[0]*x[0])+(1.0-x[0])*(1.0-x[0])+(1-x[2])*(1-x[2]);
}

FunctionOptimize::FunctionOptimize(int _dim, const std::vector<double> &upper, const std::vector<double> &lower) {
    dim = _dim;
    area = SquareArea(dim);
    area.setBorder(upper, lower);
}

SquareArea FunctionOptimize::getDomain() const {
    return area;
}

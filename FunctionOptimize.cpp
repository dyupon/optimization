#include "FunctionOptimize.h"

double FunctionOptimize::get_function_value(std::vector<double> x) {
    return 100*(x[1]-x[0]*x[0])*(x[1]-x[0]*x[0])+(1.0-x[0])*(1.0-x[0])+(1-x[2])*(1-x[2]);
}

FunctionOptimize::FunctionOptimize(int _dim) {
    dim = _dim;
    area = SquareArea(dim);
}

SquareArea FunctionOptimize::get_domain() {
    return area;
}

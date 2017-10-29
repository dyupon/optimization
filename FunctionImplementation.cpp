#include "FunctionImplementation.h"

FunctionImplementation::FunctionImplementation(int _dim, const std::vector<double> &upper,
                                               const std::vector<double> &lower) {
    dim = _dim;
    area = SquareArea(dim);
    area.setBorder(upper, lower);
}

SquareArea FunctionImplementation::getDomain() const {
    return area;
}

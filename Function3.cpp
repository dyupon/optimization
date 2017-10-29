//
// Created by User on 10/29/2017.
//

#include "Function3.h"

double Function3::getFunctionValue(const std::vector<double> &x) const {
    return 0;
}

Function3::Function3(int _dim, const std::vector<double> &upper, const std::vector<double> &lower) {
    dim = _dim;
    area = SquareArea(dim);
    area.setBorder(upper, lower);
}

SquareArea Function3::getDomain() const {
    return SquareArea();
}

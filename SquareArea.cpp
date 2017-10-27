#include "SquareArea.h"
#include <iostream>

SquareArea::SquareArea(size_t _dim) : dim(_dim) {
}

void SquareArea::setBorder(const std::vector<double> &_upper, const std::vector<double> &_lower) {
    upper = _upper;
    lower = _lower;
}

std::vector<double> SquareArea::getApproximationInsideBorder() {
    return std::vector<double>();
}

bool SquareArea::isOutOfBorder(const std::vector<double> &x) {
    bool result = 0;
    for (int i = 0; i < dim; ++i) {
        result = (lower[i] < x[i] && x[i] < upper[i]);
    }
    return !result;
}

size_t SquareArea::getDim() {
    return dim;
}


std::vector<double> SquareArea::getUpper() {
    return upper;
}

std::vector<double> SquareArea::getLower() {
    return lower;
}

SquareArea::SquareArea() = default;

std::vector<double> SquareArea::getRandomPointOnBorder(const std::vector<double> &point_1,
                                                       const std::vector<double> &point_2) {
    return std::vector<double>();
}

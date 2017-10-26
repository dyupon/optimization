#include "SquareArea.h"
#include <iostream>

SquareArea::SquareArea(size_t _dim) : dim(_dim) {
}

void SquareArea::set_border(const std::vector<double> &_upper, const std::vector<double> &_lower) {
    upper = _upper;
    lower = _lower;
}

std::vector<double> SquareArea::get_approximation_inside_border() {
    return std::vector<double>();
}

bool SquareArea::is_out_of_border(const std::vector<double> &x) {

    return false;
}

size_t SquareArea::get_dim() {
    return dim;
}


std::vector<double> SquareArea::get_upper() {
    return upper;
}

std::vector<double> SquareArea::get_lower() {
    return lower;
}

SquareArea::SquareArea() {}

std::vector<double> SquareArea::get_random_point_on_border(const std::vector<double> &point_1,
                                                           const std::vector<double> &point_2) {
    return std::vector<double>();
}

#include "SquareArea.h"
#include <iostream>

SquareArea::SquareArea(int _dim) :dim (_dim) {
    upper.resize(dim);
    lower.resize(dim);
}

void SquareArea::set_border(std::vector<double> _upper, std::vector<double> _lower) {
    for (int i = 0; i< dim; ++i) {
        upper[i] = _upper[i];
        lower[i] = _lower[i];
    }
}

std::vector<double> SquareArea::get_approximation_inside_border() {
    return std::vector<double>();
}

std::vector<double> SquareArea::get_random_point_inside() {

}

bool SquareArea::is_out_of_border(std::vector<double> x) {
    return false;
}

int SquareArea::get_dim() {
    return dim;
}


std::vector<double> SquareArea::get_upper() {
    return upper;
}

std::vector<double> SquareArea::get_lower() {
    return lower;
}

SquareArea::SquareArea() {}


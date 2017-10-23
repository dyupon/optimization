#include <iostream>
#include "RandomSearch.h"

OptimizationResult RandomSearch::optimize(std::vector<double> const& first_approximation, AbstractCriterion const& criteria, Function const& function) {
    std::vector<double> initial_approximation = first_approximation;
    SquareArea area = function.get_domain();
    area.set_border({-10, -10, -10}, {10, 10, 10});
    int dim = area.get_dim();
    std::vector<double> upper = area.get_upper();
    std::vector<double> lower = area.get_lower();
    std::vector<double> function_values, old_approximation, x;
    x = get_random_point(dim, upper, lower);
    function_values.resize(dim);
    old_approximation = get_random_point(dim, upper, lower);
    double eps = 1.0e-15;
    double neighbor_radius = 0.1;
    std::vector<double> radius = std::vector<double>(dim, neighbor_radius);
    while (!criteria.is_converged(dim, eps, old_approximation, initial_approximation)) {
        std::cout << function.get_function_value(initial_approximation) << std::endl;
        double p_b = runif(gen);
        if (p_b < p) {
            x = get_random_point(dim, upper, lower);
            if (function.get_function_value(x) < function.get_function_value(initial_approximation)) {
                old_approximation = initial_approximation;
                initial_approximation = x;
            }
        } else {
            SquareArea neighbor = SquareArea(dim);
            std::vector<double> upper_neighbor = sum(x, radius);
            std::vector<double> lower_neighbor = diff(x, radius);
            neighbor.set_border(upper_neighbor, lower_neighbor);
            x = get_random_point(dim, upper_neighbor, lower_neighbor);
            if (function.get_function_value(x) < function.get_function_value(initial_approximation)) {
                old_approximation = initial_approximation;
                initial_approximation = x;
                for (int i = 0; i < dim; i++) {
                    radius[i] *= 0.9;
                }
            }
        }
    }
    std::cout << "Minimum found at: ";
    for (int i = 0; i < dim; ++i) {
        std::cout << initial_approximation[i] << " ";
    }
    std::cout << std::endl;
    OptimizationResult optimizationResult = OptimizationResult(0, 0, initial_approximation);
    return optimizationResult;
}

RandomSearch::RandomSearch(double _p) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 mt(rd());
    gen = mt;
    std::uniform_real_distribution<> dist(0, 1);
    runif = dist;
    p = _p;
}

std::vector<double> RandomSearch::get_random_point(int dim, std::vector<double> &upper, std::vector<double> &lower) {
    std::vector<double> random_point;
    random_point.resize(dim);
    for (int i = 0; i < dim; ++i) {
        double rnd = runif(gen);
        random_point[i] = lower[i] + rnd * (upper[i] - lower[i]);
    }
    return random_point;
}

std::vector<double> RandomSearch::sum(std::vector<double> a, std::vector<double> b) {
    std::vector<double> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] + b[i]);
    }
    return result;
}

std::vector<double> RandomSearch::diff(std::vector<double> a, std::vector<double> b) {
    std::vector<double> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] - b[i]);
    }
    return result;
}




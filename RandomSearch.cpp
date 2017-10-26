#include <iostream>
#include "RandomSearch.h"

OptimizationResult RandomSearch::optimize(const std::vector<double> &first_approximation,
                                          const AbstractCriterion &criteria,
                                          const Function &function) {
    std::vector<double> initial_approximation = first_approximation;
    SquareArea area = function.get_domain();
    area.set_border({-10, -10, -10}, {10, 10, 10});
    size_t dim = area.get_dim();
    std::vector<double> upper = area.get_upper();
    std::vector<double> lower = area.get_lower();
    std::vector<double> old_approximation, x;
    x = get_random_point(dim, upper, lower);
    old_approximation = get_random_point(dim, upper, lower);
    double eps = 1.0e-15;
    double neighbor_radius = 0.1;
    int iterCount = 0;
    int funcEvalCount = 0;
    std::vector<double> radius = std::vector<double>(dim, neighbor_radius);
    while (!criteria.is_converged(dim, eps, old_approximation, initial_approximation)) {
        ++iterCount;
        // std::cout << function.get_function_value(initial_approximation) << std::endl;
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
        funcEvalCount += 2;
    }
    OptimizationResult optimizationResult = OptimizationResult(iterCount, funcEvalCount, initial_approximation);
    return optimizationResult;
}

RandomSearch::RandomSearch(double _p) {
    if (_p < 0.0 || _p > 1.0) {
        throw std::invalid_argument("Probability should be between 0 and 1");
    }
    std::random_device rd;   // non-deterministic generator
    std::mt19937 mt(rd());
    gen = mt;
    std::uniform_real_distribution<> dist(0, 1);
    runif = dist;
    p = _p;
}

std::vector<double> RandomSearch::get_random_point(size_t dim,
                                                   const std::vector<double> &upper,
                                                   const std::vector<double> &lower) {
    std::vector<double> random_point;
    random_point.reserve(dim);
    for (int i = 0; i < dim; ++i) {
        double rnd = runif(gen);
        random_point.push_back(lower[i] + rnd * (upper[i] - lower[i]));
    }
    return random_point;
}

std::vector<double> RandomSearch::sum(const std::vector<double> &a, const std::vector<double> &b) const {
    std::vector<double> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] + b[i]);
    }
    return result;
}

std::vector<double> RandomSearch::diff(const std::vector<double> &a, const std::vector<double> &b) const {
    std::vector<double> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] - b[i]);
    }
    return result;
}




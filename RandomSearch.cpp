#include <iostream>
#include "RandomSearch.h"

OptimizationResult RandomSearch::optimize(const std::vector<double> &_initialApproximation,
                                          const AbstractCriterion &criteria,
                                          const Function &function) {
    std::vector<double> initialApproximation = _initialApproximation;
    SquareArea area = function.getDomain();
    size_t dim = area.getDim();
    std::vector<double> upper = area.getUpper();
    std::vector<double> lower = area.getLower();
    std::vector<double> oldApproximation, x;
    x = getRandomPoint(dim, upper, lower);
    oldApproximation = getRandomPoint(dim, upper, lower);
    double eps = 1.0e-15;
    double neighborRadius = 0.1;
    int iterCount = 0;
    int funcEvalCount = 0;
    std::vector<double> radius = std::vector<double>(dim, neighborRadius);
    while (!criteria.isConverged(dim, eps, oldApproximation, initialApproximation)) {
        ++iterCount;
        // std::cout << function.getFunctionValue(initialApproximation) << std::endl;
        double p_b = runif(gen);
        if (p_b < p) {
            x = getRandomPoint(dim, upper, lower);
            if (function.getFunctionValue(x) < function.getFunctionValue(initialApproximation)) {
                oldApproximation = initialApproximation;
                initialApproximation = x;
            }
        } else {
            SquareArea neighbor = SquareArea(dim);
            std::vector<double> upperNeighbor = sum(x, radius);
            std::vector<double> lowerNeighbor = diff(x, radius);
            neighbor.setBorder(upperNeighbor, lowerNeighbor);
            x = getRandomPoint(dim, upperNeighbor, lowerNeighbor);
            if (function.getFunctionValue(x) < function.getFunctionValue(initialApproximation)) {
                oldApproximation = initialApproximation;
                initialApproximation = x;
                for (int i = 0; i < dim; i++) {
                    radius[i] *= 0.9;
                }
            }
        }
        funcEvalCount += 2;
    }
    OptimizationResult optimizationResult = OptimizationResult(iterCount, funcEvalCount, initialApproximation);
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

std::vector<double> RandomSearch::getRandomPoint(size_t dim,
                                                 const std::vector<double> &upper,
                                                 const std::vector<double> &lower) {
    std::vector<double> randomPoint;
    randomPoint.reserve(dim);
    for (int i = 0; i < dim; ++i) {
        double rnd = runif(gen);
        randomPoint.push_back(lower[i] + rnd * (upper[i] - lower[i]));
    }
    return randomPoint;
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




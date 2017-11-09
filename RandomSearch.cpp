#include <iostream>
#include "RandomSearch.h"
#include "FunctionImplementation.h"
#include "Utils.h"

OptimizationResult RandomSearch::optimize(const std::vector<double> &_initialApproximation,
                                          std::shared_ptr<AbstractCriterion> &criterion,
                                          FunctionImplementation *function) {
    std::vector<double> initialApproximation = _initialApproximation;
    SquareArea area = function->getDomain();
    size_t dim = area.getDim();
    std::vector<double> upper = area.getUpper();
    std::vector<double> lower = area.getLower();
    std::vector<double> oldApproximation, x;
    x = getRandomPoint(dim, upper, lower);
    oldApproximation = getRandomPoint(dim, upper, lower);
    double neighborRadius = 0.1;
    int iterCount = 0;
    int funcEvalCount = 0;
    Utils<double> utils = Utils<double>();
    std::vector<double> radius = std::vector<double>(dim, neighborRadius);
    while (!criterion->isConverged(dim, oldApproximation, initialApproximation)) {
        ++iterCount;
        double p_b = runif(gen);
        if (p_b < p) {
            x = getRandomPoint(dim, upper, lower);
            if (function->getFunctionValue(x) < function->getFunctionValue(initialApproximation)) {
                oldApproximation = initialApproximation;
                initialApproximation = x;
            }
        } else {
            SquareArea neighbor = SquareArea(dim);
            std::vector<double> upperNeighbor = utils.sum(x, radius);
            std::vector<double> lowerNeighbor = utils.diff(x, radius);
            neighbor.setBorder(upperNeighbor, lowerNeighbor);
            x = getRandomPoint(dim, upperNeighbor, lowerNeighbor);
            if (function->getFunctionValue(x) < function->getFunctionValue(initialApproximation)) {
                oldApproximation = initialApproximation;
                initialApproximation = x;
                for (int i = 0; i < dim; i++) {
                    radius[i] *= resizeCoef;
                }
            }
        }
        funcEvalCount += 2;
    }
    OptimizationResult optimizationResult = OptimizationResult(iterCount, funcEvalCount, initialApproximation);
    return optimizationResult;
}

RandomSearch::RandomSearch(double _p, double _resizeCoef) : resizeCoef(_resizeCoef) {
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




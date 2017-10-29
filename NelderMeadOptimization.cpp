#include <cmath>
#include <iostream>
#include "NelderMeadOptimization.h"
#include "FunctionImplementation.h"

const double NelderMeadOptimization::ALPHA = 1.0;
const double NelderMeadOptimization::BETA = 0.5;
const double NelderMeadOptimization::GAMMA = 2.0;

NelderMeadOptimization::NelderMeadOptimization(size_t _dim, double _scale) : dim(_dim), scale(_scale) {
}

OptimizationResult NelderMeadOptimization::optimize(const std::vector<double> &_initialApproximation,
                                                    const AbstractCriterion &criteria,
                                                    FunctionImplementation *function) {
    std::vector<double> functionValues;
    functionValues.reserve(dim + 1);
    std::vector<double> vm;
    vm.reserve(dim);

    std::vector<double> initialApproximation = _initialApproximation;
    double reflectionPoint, expansionPoint, contractionPoint, simplexVertex1, simplexVertex2, center;

    simplexVertex1 = scale * (std::sqrt(dim + 1) - 1 + dim) / (dim * std::sqrt(2));
    simplexVertex2 = scale * (std::sqrt(dim + 1) - 1) / (dim * std::sqrt(2));
    /* SquareArea domain = function.getDomain();
     std::vector<double> upper = domain.getUpper();
     std::vector<double> lower = domain.getLower();*/

    std::vector<std::vector<double>> simplex;
    simplex.reserve(dim + 1);
    simplex.push_back(initialApproximation);

    for (int i = 1; i <= dim; ++i) {
        std::vector<double> simplexRow;
        simplexRow.reserve(dim);
        for (int j = 0; j < dim; ++j) {
            if (i - 1 == j) {
                simplexRow.push_back(simplexVertex1 + initialApproximation[j]);
            } else {
                simplexRow.push_back(simplexVertex2 + initialApproximation[j]);
            }
        }
        simplex.push_back(simplexRow);
    }
    // TODO 1. Найти центр тяжести начального симплекcа 2. Найти центр тяжести прямоугольной области 3. Совместить его с центром тяжести начального симплекса
    for (int i = 0; i <= dim; ++i) {
        functionValues.push_back(function->getFunctionValue(simplex[i]));
    }

    int functionEvaluationsCount = static_cast<int>(dim + 1);

    int largestValueVertex = 0;
    int smallestValueVertex = 0;
    int iterCount;

    for (iterCount = 1; iterCount <= MAX_IT; ++iterCount) {

        for (int i = 0; i <= dim; ++i) {
            if (functionValues[i] > functionValues[largestValueVertex]) {
                largestValueVertex = i;
            }
            if (functionValues[i] < functionValues[smallestValueVertex]) {
                smallestValueVertex = i;
            }
        }

        int nextSmallestValueVertex = smallestValueVertex;
        for (int i = 0; i <= dim; ++i) {
            if (functionValues[i] > functionValues[nextSmallestValueVertex] &&
                functionValues[i] < functionValues[largestValueVertex]) {
                nextSmallestValueVertex = i;
            }
        }

        for (int i = 0; i <= dim - 1; ++i) {
            center = 0.0;
            for (int j = 0; j <= dim; ++j) {
                if (j != largestValueVertex) {
                    center += simplex[j][i];
                }
            }
            vm[i] = center / dim;
        }

        std::vector<double> vertexReflection;
        vertexReflection.reserve(dim);
        for (int i = 0; i <= dim - 1; ++i) {
            vertexReflection.push_back(vm[i] + ALPHA * (vm[i] - simplex[largestValueVertex][i]));
        }


        reflectionPoint = function->getFunctionValue(vertexReflection);
        ++functionEvaluationsCount;

        if (reflectionPoint < functionValues[nextSmallestValueVertex] &&
            reflectionPoint >= functionValues[smallestValueVertex]) {
            for (int i = 0; i <= dim - 1; ++i) {
                simplex[largestValueVertex][i] = vertexReflection[i];
            }
            functionValues[largestValueVertex] = reflectionPoint;
        }

        if (reflectionPoint < functionValues[smallestValueVertex]) {
            std::vector<double> vertex_expansion;
            vertex_expansion.reserve(dim);
            for (int i = 0; i <= dim - 1; ++i) {
                vertex_expansion.push_back(vm[i] + GAMMA * (vertexReflection[i] - vm[i]));
            }

            expansionPoint = function->getFunctionValue(vertex_expansion);
            functionEvaluationsCount++;

            if (expansionPoint < reflectionPoint) {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largestValueVertex][i] = vertex_expansion[i];
                }
                functionValues[largestValueVertex] = expansionPoint;
            } else {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largestValueVertex][i] = vertexReflection[i];
                }
                functionValues[largestValueVertex] = reflectionPoint;
            }
        }

        if (reflectionPoint >= functionValues[nextSmallestValueVertex]) {
            std::vector<double> vertexContraction;
            vertexContraction.reserve(dim);
            if (reflectionPoint < functionValues[largestValueVertex] &&
                reflectionPoint >= functionValues[nextSmallestValueVertex]) {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertexContraction.push_back(vm[i] + BETA * (vertexReflection[i] - vm[i]));
                }
                contractionPoint = function->getFunctionValue(vertexContraction);
                ++functionEvaluationsCount;
            } else {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertexContraction.push_back(vm[i] - BETA * (vm[i] - simplex[largestValueVertex][i]));
                }
                contractionPoint = function->getFunctionValue(vertexContraction);
                ++functionEvaluationsCount;
            }

            if (contractionPoint < functionValues[largestValueVertex]) {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largestValueVertex][i] = vertexContraction[i];
                }
                functionValues[largestValueVertex] = contractionPoint;
            } else {
                for (int row = 0; row <= dim; ++row) {
                    if (row != smallestValueVertex) {
                        for (int i = 0; i <= dim - 1; ++i) {
                            simplex[row][i] = simplex[smallestValueVertex][i] +
                                              (simplex[row][i] - simplex[smallestValueVertex][i]) / 2.0;
                        }
                    }
                }

                functionValues[largestValueVertex] = function->getFunctionValue(simplex[largestValueVertex]);
                ++functionEvaluationsCount;

                functionValues[nextSmallestValueVertex] = function->getFunctionValue(
                        simplex[nextSmallestValueVertex]);
                ++functionEvaluationsCount;
            }
        }
        if (criteria.isConverged(functionValues)) break;
    }

    for (int i = 0; i < dim; ++i) {
        initialApproximation[i] = simplex[smallestValueVertex][i];
    }
    OptimizationResult optimizationResult = OptimizationResult(iterCount, functionEvaluationsCount,
                                                               initialApproximation);
    return optimizationResult;
}

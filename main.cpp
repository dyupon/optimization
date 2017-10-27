#include <iostream>
#include "EpsilonCriterion.h"
#include "Function.h"
#include "FunctionOptimize.h"
#include "NelderMeadOptimization.h"
#include "RandomSearch.h"
#include "EuclidNormCriterion.h"

void printOptimizationResult(const FunctionOptimize &function, const OptimizationResult &optimizationResult) {
    std::cout << "Minimum was found at: " << std::endl;
    std::vector<double> extr = optimizationResult.getExtrPoint();
    for (double i : extr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Minimum was found as: " << std::endl;
    std::cout << function.getFunctionValue(extr) << std::endl;
    std::cout << optimizationResult.getFuncEvaluationCount() << " Function Evaluations" << std::endl;
    std::cout << optimizationResult.getIterCount() << " Iterations through program" << std::endl;
}

int main() {
    size_t dim;
    std::cout << "Enter dimension of the area: " << std::endl;
    std::cin >> dim;
    double currentCoordinate;
    std::cout << "Enter initial approximation: " << std::endl;
    std::vector<double> initial_approximation;// = {-1.2, 1.0, 1.0}
    initial_approximation.reserve(dim);
    for (int i = 0; i < dim; ++i) {
        std::cin >> currentCoordinate;
        initial_approximation.push_back(currentCoordinate);
    }
    std::cout << "Enter the optimization method: 1 for Nelder-Mead, 2 for random search." << std::endl;
    int flag = 0;
    std::cin >> flag;
    std::vector<double> upper, lower;
    upper.reserve(dim);
    lower.reserve(dim);
    std::cout << "Enter upper bounds of area: " << std::endl;
    for (int i = 0; i < dim; ++i) {
        std::cin >> currentCoordinate;
        upper.push_back(currentCoordinate);
    }
    std::cout << "Enter lower bounds of area: " << std::endl;
    for (int i = 0; i < dim; ++i) {
        std::cin >> currentCoordinate;
        lower.push_back(currentCoordinate);
    }
    FunctionOptimize function = FunctionOptimize(dim, upper, lower);
    if (flag == 1) {
        double eps = 1.0e-15;
        double scale = 1.0;
        EpsilonCriterion criteria = EpsilonCriterion(dim, eps);
        NelderMeadOptimization nelderMeadOptimization = NelderMeadOptimization(dim, scale);
        OptimizationResult optimizationResult = nelderMeadOptimization.optimize(initial_approximation, criteria,
                                                                                function);
        printOptimizationResult(function, optimizationResult);
    }
    if (flag == 2) {
        double p;
        std::cout << "Enter the probability of searching the whole area: " << std::endl;
        std::cin >> p;
        EuclidNormCriterion euclidNormCriterion = EuclidNormCriterion();
        try {
            RandomSearch randomSearch = RandomSearch(p);
            OptimizationResult optimizationResult = randomSearch.optimize(initial_approximation, euclidNormCriterion,
                                                                          function);
            printOptimizationResult(function, optimizationResult);
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}

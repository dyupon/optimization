#include <iostream>
#include "EpsilonCriterion.h"
#include "Function.h"
#include "Function1.h"
#include "NelderMeadOptimization.h"
#include "RandomSearch.h"
#include "EuclidNormCriterion.h"
#include "Function2.h"

const int DIM_1D = 1;
const int DIM_2D = 2;
const int DIM_3D = 3;
const int DIM_4D = 4;

void printOptimizationResult(FunctionImplementation *function, const OptimizationResult &optimizationResult) {
    std::cout << "Minimum was found at: " << std::endl;
    std::vector<double> extr = optimizationResult.getExtrPoint();
    for (double i : extr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Minimum was found as: " << std::endl;
    std::cout << function->getFunctionValue(extr) << std::endl;
    std::cout << optimizationResult.getFuncEvaluationCount() << " Function Evaluations" << std::endl;
    std::cout << optimizationResult.getIterCount() << " Iterations through program" << std::endl;
}

int main() {
    int functionFlag = 0;
    std::cout << "Choose function: 1 for 100(x-y)^2 + (1-y)^2 + (1-z)^2" << std::endl;
    std::cout << "2 for (1.23 - x + xy)^2 + (2.25 - x + xy^2)^2 + (2.625 - x + xy^3)^2" << std::endl;
    std::cout << "3 for 0.26(x^2 + y^2) - 0.48xy " << std::endl;
    std::cin >> functionFlag;
    size_t dim = 0;
    switch (functionFlag) {
        case 1:
            dim = DIM_3D;
            break;
        case 2:
            dim = DIM_2D;
            break;
        case 3:
            dim = DIM_2D;
            break;
        default:
            break;
    }
    double currentCoordinate;
    std::cout << "Enter initial approximation: " << std::endl;
    std::vector<double> initial_approximation;// = {-1.2, 1.0, 1.0}
    initial_approximation.reserve(dim);
    for (int i = 0; i < dim; ++i) {
        std::cin >> currentCoordinate;
        initial_approximation.push_back(currentCoordinate);
    }
    std::cout << "Enter the optimization method: 1 for Nelder-Mead, 2 for random search." << std::endl;
    int methodFlag = 0;
    std::cin >> methodFlag;
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
    std::cout << "Enter the value of epsilon as a parameter for testing convergence: " << std::endl;
    double eps;// 1.0e-15;
    std::cin >> eps;
    FunctionImplementation *function = 0;
    switch (functionFlag) {
        case 1:
            function = new Function1(dim, upper, lower);
            break;
        case 2:
            function = new Function2(dim, upper, lower);
            break;
        case 3:
            function = new Function2(dim, upper, lower);
            break;
        default:
            break;
    }
    if (methodFlag == 1) {
        double scale = 1.0;
        EpsilonCriterion criteria = EpsilonCriterion(dim, eps);
        NelderMeadOptimization nelderMeadOptimization = NelderMeadOptimization(dim, scale);
        OptimizationResult optimizationResult = nelderMeadOptimization.optimize(initial_approximation, criteria,
                                                                                function);
        printOptimizationResult(function, optimizationResult);
    }
    if (methodFlag == 2) {
        double p;
        std::cout << "Enter the probability of searching the whole area: " << std::endl;
        std::cin >> p;
        EuclidNormCriterion euclidNormCriterion = EuclidNormCriterion(eps);
        try {
            RandomSearch randomSearch = RandomSearch(p);
            OptimizationResult optimizationResult = randomSearch.optimize(initial_approximation, euclidNormCriterion,
                                                                          function);
            printOptimizationResult(function, optimizationResult);
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }
    delete function;
    return 0;
}

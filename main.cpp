#include <iostream>
#include "EpsilonCriterion.h"
#include "Function.h"
#include "FunctionOptimize.h"
#include "NelderMeadOptimization.h"
#include "RandomSearch.h"
#include "EuclidNormCriterion.h"

void printOptimizationResult(const FunctionOptimize &function, const OptimizationResult &optimizationResult) {
    std::cout << "Minimum was found at: " << std::endl;
    std::vector<double> extr = optimizationResult.get_extr_point();
    for (double i : extr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Minimum was found as: " << std::endl;
    std::cout << function.get_function_value(extr) << "\t";
}

int main() {
    std::vector<double> initial_approximation = {-1.2, 1.0, 1.0};
    int dim = 3;
    int flag = 0;
    std::cout << "Enter the optimization method: 1 for Nelder-Mead, 2 for random search." << std::endl;
    std::cin >> flag;
    FunctionOptimize function = FunctionOptimize(dim);
    if (flag == 1) {
        double eps = 1.0e-15;
        double scale = 1.0;
        EpsilonCriterion criteria = EpsilonCriterion(dim, eps);
        NelderMeadOptimization nelderMeadOptimization = NelderMeadOptimization(dim, scale);
        OptimizationResult optimizationResult = nelderMeadOptimization.optimize(initial_approximation, criteria, function);
        printOptimizationResult(function, optimizationResult);
    }
    if (flag == 2) {
        double p;
        std::cout << "Enter the probability of searching the the whole area: " << std::endl;
        std::cin >> p;
        EuclidNormCriterion euclidNormCriterion = EuclidNormCriterion();
        RandomSearch randomSearch = RandomSearch(p);
        OptimizationResult optimizationResult = randomSearch.optimize(initial_approximation, euclidNormCriterion, function);
        printOptimizationResult(function, optimizationResult);
    }
    return 0;
}

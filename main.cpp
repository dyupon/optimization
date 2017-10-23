#include <iostream>
#include "EpsilonCriterion.h"
#include "Function.h"
#include "FunctionOptimize.h"
#include "NelderMeadOptimization.h"
#include "SquareArea.h"
#include "RandomSearch.h"
#include "EuclidNormCriterion.h"

int main() {
    std::vector<double> initial_approximation = {-1.2, 1.0, 1.0};
    int dim = 3;
    int flag = 0;
    std::cout << "Enter the optimization method: 1 for Nelder-Mead, 2 for random search." << std::endl;
    std::cin >> flag;
    std::vector<double> extr;
    FunctionOptimize function = FunctionOptimize(dim);
    if (flag == 1) {
        double eps = 1.0e-15;
        double scale = 1.0;
        EpsilonCriterion criteria = EpsilonCriterion(dim, eps);
        NelderMeadOptimization nelderMeadOptimization = NelderMeadOptimization(dim, scale);
        extr = nelderMeadOptimization.optimize(initial_approximation, criteria, function);
    }
    if (flag == 2) {
        double p;
        std::cout << "Enter the probability of searching the the whole area: " << std::endl;
        std::cin >> p;
        EuclidNormCriterion euclidNormCriterion = EuclidNormCriterion();
        RandomSearch randomSearch = RandomSearch(p);
        extr = randomSearch.optimize(initial_approximation, euclidNormCriterion, function);
    }
    std::cout << "Minimum was found at: " << std::endl;
    for (double i : extr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "Minimum was found as: " << std::endl;
    std::cout << function.get_function_value(extr) << "\t";
    return 0;
}